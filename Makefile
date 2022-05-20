BASENAME = turok3
GAME_VERSION ?= us

ifeq ($(GAME_VERSION),3-5-2000)
VERSION = 3-5-2000
else ifeq ($(GAME_VERSION),09)
VERSION = 09
else ifeq ($(GAME_VERSION),10)
VERSION = 10
else ifeq ($(GAME_VERSION),11)
VERSION = 11
else ifeq ($(GAME_VERSION),15)
VERSION = 15
else ifeq ($(GAME_VERSION),18)
VERSION = 18
else ifeq ($(GAME_VERSION),16-7-2000)
VERSION = 16-7-2000
else ifeq ($(GAME_VERSION),us)
VERSION = us
else ifeq ($(GAME_VERSION),eu)
VERSION = eu
else
$(error Invalid game version $(GAME_VERSION))
endif

VERSIONS_DIR = versions
VERSION_DIR = $(VERSIONS_DIR)/$(VERSION)
ASM_DIR	  = asm
BIN_DIR   = assets
BUILD_DIR = $(VERSION_DIR)/build
SRC_DIR   = src

ASM_DIRS  = $(VERSION_DIR)/$(ASM_DIR) $(VERSION_DIR)/$(ASM_DIR)/data $(VERSION_DIR)/$(ASM_DIR)/data/virtual $(SRC_DIR)/$(VERSION)/asm $(SRC_DIR)/common/asm
BIN_DIRS  = $(VERSION_DIR)/$(BIN_DIR)
SRC_DIRS  = $(SRC_DIR)/$(VERSION) $(SRC_DIR)/$(VERSION)/virtual $(SRC_DIR)/common $(SRC_DIR)/common/virtual
TOOLS_DIR = tools

S_FILES   = $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.s))
C_FILES   = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
BIN_FILES = $(foreach dir,$(BIN_DIRS),$(wildcard $(dir)/*.bin))
O_FILES	 = $(foreach file,$(S_FILES),$(BUILD_DIR)/$(file).o) \
           $(foreach file,$(C_FILES),$(BUILD_DIR)/$(file).o) \
           $(foreach file,$(BIN_FILES),$(BUILD_DIR)/$(file).o)


TARGET    = $(BUILD_DIR)/$(BASENAME).$(VERSION)
LD_SCRIPT = $(VERSION_DIR)/$(BASENAME).ld

CROSS   = mips-linux-gnu-
AS      = $(CROSS)as
ASN64   = wine $(TOOLS_DIR)/mips-gcc/asn64.exe
CPP     = cpp
LD      = $(CROSS)ld
OBJDUMP = $(CROSS)objdump
OBJCOPY = $(CROSS)objcopy
PYTHON  = python3
N64CRC  = $(TOOLS_DIR)/n64crc
LNKCONV = $(TOOLS_DIR)/psyq-obj-parser
CC      = $(TOOLS_DIR)/mips-gcc/cc1

# Flags
OPT_FLAGS        = -O2
INCLUDE_CC_FLAGS = -I. -Iinclude -Iultralib/include
AS_FLAGS         = -EB -mtune=vr4300 -march=vr4300 -mabi=32 -mips3 -O1 -I include
ASM_FLAGS        = -I include -mips3
D_FLAGS          = -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2 -DGAME_VERSION=\"$(VERSION)\"

# Additional defines
ifeq ($(NON_MATCHING),1)
D_FLAGS += -DNON_MATCHING
endif

# T2's original compiler had these default options: -mgas -meb -mcpu=R4300
CC_FLAGS      = -quiet -G0 -mips3 $(OPT_FLAGS) -mgas -meb -mcpu=VR4300 -mhard-float -mfp64
CPP_FLAGS     = -P -undef -Wall -lang-c $(D_FLAGS) $(INCLUDE_CC_FLAGS) -nostdinc
LD_FLAGS      = -T $(LD_SCRIPT) -Map $(TARGET).map -T $(VERSION_DIR)/undefined_syms_auto.txt -T $(VERSION_DIR)/undefined_funcs_auto.txt -T $(VERSIONS_DIR)/undefined_funcs.$(VERSION).txt -T $(VERSIONS_DIR)/undefined_syms.$(VERSION).txt --no-check-sections
OBJCOPY_FLAGS = -O binary

### Optimisation Overrides

### Targets

default: all

all: tools dirs $(TARGET).z64 check

check: $(TARGET).z64 $(N64CRC)
	$(N64CRC) $<
	@sha1sum $<
	@sha1sum -c $(VERSIONS_DIR)/checksum.$(VERSION).sha1

tools:
	make -C $(TOOLS_DIR)

dirs:
	$(foreach dir,$(SRC_DIRS) $(ASM_DIRS:$(VERSION_DIR)/%=%) $(BIN_DIRS:$(VERSION_DIR)/%=%),$(shell mkdir -p $(BUILD_DIR)/$(dir)))

nuke:
	rm -rf $(VERSION_DIR)

nukeall:
	rm -rf $(VERSIONS_DIR)/3-5-2000
	rm -rf $(VERSIONS_DIR)/09
	rm -rf $(VERSIONS_DIR)/10
	rm -rf $(VERSIONS_DIR)/11
	rm -rf $(VERSIONS_DIR)/15
	rm -rf $(VERSIONS_DIR)/16-7-2000
	rm -rf $(VERSIONS_DIR)/18
	rm -rf $(VERSIONS_DIR)/eu
	rm -rf $(VERSIONS_DIR)/us

clean:
	rm -rf $(BUILD_DIR)
	rm -f gccdump*
	rm -f nul.s

setup: dirs
	$(PYTHON) $(TOOLS_DIR)/splat/split.py $(VERSIONS_DIR)/$(BASENAME).$(VERSION).yaml

context:
	rm -f ctx.c ctx_includes.c
	find include/ src/ -type f -name "*.h" | sed -e 's/.*/#include "\0"/' > ctx_includes.c
	$(PYTHON) $(TOOLS_DIR)/m2ctx.py ctx_includes.c
	sed -i 's/sizeof(long)/4/g' ctx.c

compare:
	$(PYTHON) first_diff.py

### Recipes

$(TARGET).elf: $(O_FILES)
	$(LD) $(LD_FLAGS) -o $@

$(BUILD_DIR)/%.i: %.c
	$(CPP) -MMD -MP -MT $@ -MF $@.d $(CPP_FLAGS) -o $@ $<

$(BUILD_DIR)/%.c.s: $(BUILD_DIR)/%.i
	unix2dos $<
	$(CC) $(CC_FLAGS) -o $@ $<

$(BUILD_DIR)/%.c.obj: $(BUILD_DIR)/%.c.s
	unix2dos $<
	$(ASN64) $(ASM_FLAGS) -o $@ $<

$(BUILD_DIR)/%.c.o: $(BUILD_DIR)/%.c.obj
	$(LNKCONV) $< -o $@ -b -n

$(BUILD_DIR)/%.s.o: %.s
	$(AS) $(AS_FLAGS) -o $(@:$(BUILD_DIR)/$(VERSION_DIR)/%=$(BUILD_DIR)/%) $<

$(BUILD_DIR)/%.bin.o: %.bin
	$(LD) -r -b binary -o $(@:$(BUILD_DIR)/$(VERSION_DIR)/%=$(BUILD_DIR)/%) $<

$(TARGET).z64: $(TARGET).elf
	$(OBJCOPY) $(OBJCOPY_FLAGS) $< $@

$(N64CRC): $(TOOLS_DIR)/n64crc.c
	make -C tools

### Settings
.SECONDARY:
.PHONY: all clean default
SHELL = /bin/bash -e -o pipefail
