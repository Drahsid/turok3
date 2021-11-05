BASENAME  = turok3

BUILD_DIR = build
ASM_DIRS  = asm src/asm asm/data
BIN_DIRS  = assets
SRC_DIR   = src
SRC_DIRS  = $(SRC_DIR)
TOOLS_DIR := tools

S_FILES   = $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.s))
C_FILES   = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
BIN_FILES = $(foreach dir,$(BIN_DIRS),$(wildcard $(dir)/*.bin))
O_FILES := $(foreach file,$(S_FILES),$(BUILD_DIR)/$(file).o) \
           $(foreach file,$(C_FILES),$(BUILD_DIR)/$(file).o) \
           $(foreach file,$(BIN_FILES),$(BUILD_DIR)/$(file).o)


TARGET = $(BUILD_DIR)/$(BASENAME)
LD_SCRIPT = $(BASENAME).ld

CROSS = mips-linux-gnu-
AS = $(CROSS)as
CPP = cpp
LD = $(CROSS)ld
OBJDUMP = $(CROSS)objdump
OBJCOPY = $(CROSS)objcopy
PYTHON = python3
N64CRC = tools/n64crc

OBJCOPYFLAGS = -O binary

CC := $(TOOLS_DIR)/mips-gcc/cc1

OPT_FLAGS := -O2
INCLUDE_CFLAGS := -I. -Iinclude -Ilibreultra/include/2.0I
ASFLAGS = -EB -mtune=vr4300 -march=vr4300 -mabi=32 -I include

# Files requiring pre/post-processing
GREP := grep -rl
GLOBAL_ASM_C_FILES := $(shell $(GREP) GLOBAL_ASM $(SRC_DIR) </dev/null 2>/dev/null)
GLOBAL_ASM_O_FILES := $(foreach file,$(GLOBAL_ASM_C_FILES),$(BUILD_DIR)/$(file).o)

DFLAGS := -D_LANGUAGE_C -D_FINALROM -DF3DEX_GBI_2 -D__GNUC__=2
# original compiler had these default options: -fpeephole -ffunction-cse -fkeep-static-consts -fpcc-struct-return -fcommon -fverbose-asm -fgnu-linker -mgas -meb -mcpu=R4300
CFLAGS := -G 0 -mips3 -mgp32 -mfp32 -mcpu=R4300 $(OPT_FLAGS) -fno-common -fgnu-linker -mgas
CPPFLAGS := -P -undef -Wall -lang-c $(DFLAGS) $(INCLUDE_CFLAGS) -nostdinc
LDFLAGS := -T $(LD_SCRIPT) -Map $(TARGET).map -T undefined_syms_auto.txt -T undefined_funcs_auto.txt -T undefined_funcs.txt -T undefined_syms.txt --no-check-sections

ifdef PERMUTER
CPP_FLAGS += -DPERMUTER
endif

### Optimisation Overrides

### Targets

default: all

all: dirs $(TARGET).z64 check

check: $(TARGET).z64 $(N64CRC)
	$(N64CRC) $<
	@md5sum $<
	@md5sum -c checksum.md5

dirs:
	$(foreach dir,$(SRC_DIRS) $(ASM_DIRS) $(BIN_DIRS),$(shell mkdir -p $(BUILD_DIR)/$(dir)))

nuke:
	rm -rf asm
	rm -rf assets
	rm -rf build
	rm -f *auto.txt

clean:
	rm -rf build

setup:
	$(PYTHON) tools/splat/split.py $(BASENAME).yaml

context:
	rm -f ctx.c ctx_includes.c
	find include/ src/ -type f -name "*.h" | sed -e 's/.*/#include "\0"/' > ctx_includes.c
	$(PYTHON) tools/m2ctx.py ctx_includes.c

compare:
	$(PYTHON) first_diff.py

### Recipes

$(TARGET).elf: $(O_FILES)
	@$(LD) $(LDFLAGS) -o $@

$(BUILD_DIR)/%.i: %.c
	$(CPP) -MMD -MP -MT $@ -MF $@.d $(CPPFLAGS) $(INCLUDE_CFLAGS) -o $@ $<

$(BUILD_DIR)/%.c.s: $(BUILD_DIR)/%.i
	$(CC) $(CFLAGS) -o $@ $<

$(BUILD_DIR)/%.c.o: $(BUILD_DIR)/%.c.s
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/%.s.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/%.bin.o: %.bin
	$(LD) -r -b binary -o $@ $<

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) $(OBJCOPYFLAGS) $< $@

$(TARGET).z64: $(TARGET).bin
	@cp $< $@

$(N64CRC): tools/n64crc.c
	make -C tools

### Settings
.SECONDARY:
.PHONY: all clean default
SHELL = /bin/bash -e -o pipefail
