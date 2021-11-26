BASENAME  = turok3

ROOT_DIR  = $(PWD)
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
ASN64 = wine tools/mips-gcc/asn64.exe
CPP = cpp
LD = $(CROSS)ld
OBJDUMP = $(CROSS)objdump
OBJCOPY = $(CROSS)objcopy
PYTHON = python3
N64CRC = tools/n64crc
LNKCONV = tools/lnkconv/lnkconv
LNKASM	= tools/lnkconv/link.s
CC := $(TOOLS_DIR)/mips-gcc/cc1

# Flags
OPT_FLAGS := -O2
INCLUDE_CC_FLAGS := -I. -Iinclude -Ilibreultra/include/2.0I
AS_FLAGS := -EB -mtune=vr4300 -march=vr4300 -mabi=32 -mips3 -O1 -I include
ASM_FLAGS := -I include -mips3
D_FLAGS := -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2
ifeq ($(ORIGINAL_AS_TESTS),1)
D_FLAGS += -DORIGINAL_AS_TESTS
endif

CC_FLAGS := -quiet -G 0 -mips3 -mcpu=R4300 $(OPT_FLAGS) -mrnames # T2's original compiler had these default options: -mgas -meb -mcpu=R4300
CPP_FLAGS := -P -undef -Wall -lang-c $(D_FLAGS) $(INCLUDE_CC_FLAGS) -nostdinc
LD_FLAGS := -T $(LD_SCRIPT) -Map $(TARGET).map -T undefined_syms_auto.txt -T undefined_funcs_auto.txt -T undefined_funcs.txt -T undefined_syms.txt --no-check-sections
OBJCOPY_FLAGS = -O binary

ifeq ($(ORIGINAL_AS_TESTS),1)
CC_FLAGS += -fno-delayed-branch
endif

### Optimisation Overrides

### Targets

default: all

all: tools dirs $(TARGET).z64 check

check: $(TARGET).z64 $(N64CRC)
	$(N64CRC) $<
	@md5sum $<
	@md5sum -c checksum.md5

tools:
	make -C tools

dirs:
	$(foreach dir,$(SRC_DIRS) $(ASM_DIRS) $(BIN_DIRS),$(shell mkdir -p $(BUILD_DIR)/$(dir)))

nuke:
	rm -rf asm
	rm -rf assets
	rm -rf build
	rm -f *auto.txt

clean:
	rm -rf build

ifeq ($(ORIGINAL_AS_TESTS),1)
setup:
	$(PYTHON) tools/splat/split.py $(BASENAME).yaml
	dos2unix asm/nonmatchings/**/**
else
setup:
	$(PYTHON) tools/splat/split.py $(BASENAME).yaml
endif

context:
	rm -f ctx.c ctx_includes.c
	find include/ src/ -type f -name "*.h" | sed -e 's/.*/#include "\0"/' > ctx_includes.c
	$(PYTHON) tools/m2ctx.py ctx_includes.c
	sed -i 's/sizeof(long)/4/g' ctx.c

compare:
	$(PYTHON) first_diff.py

### Recipes

$(TARGET).elf: $(O_FILES)
	@$(LD) $(LD_FLAGS) -o $@

$(BUILD_DIR)/%.i: %.c
	$(CPP) -MMD -MP -MT $@ -MF $@.d $(CPP_FLAGS) -o $@ $<

$(BUILD_DIR)/%.c.s: $(BUILD_DIR)/%.i
	$(CC) $(CC_FLAGS) -o $@ $<

ifeq ($(ORIGINAL_AS_TESTS),1)
$(BUILD_DIR)/%.c.o.sn: $(BUILD_DIR)/%.c.s
	mkdir -p $@_pre
	unix2dos $<
	$(ASN64) $(ASM_FLAGS) -o $@ $<

$(BUILD_DIR)/%.c.o: $(BUILD_DIR)/%.c.o.sn
	$(LNKCONV) $<
	@mv out_text.bin         $<_pre/out_text.bin
	@mv functions.s          $<_pre/functions.s
	@mv out_data.bin         $<_pre/out_data.bin
	@mv out_rodata.bin       $<_pre/out_rodata.bin
	@mv bss_length.s         $<_pre/bss_length.s
	@mv out_bss_syms.txt     $<_pre/out_bss_syms.txt
	@mv out_data_syms.txt    $<_pre/out_data_syms.txt
	@mv out_rodata_syms.txt  $<_pre/out_rodata_syms.txt
	@mv out_text_syms.txt    $<_pre/out_text_syms.txt
	@cp $(LNKASM) $<_pre/link.s
	$(AS) $(AS_FLAGS) -I$<_pre/ -o $@ $<_pre/link.s
else
$(BUILD_DIR)/%.c.o: $(BUILD_DIR)/%.c.s
	$(AS) $(AS_FLAGS) -o $@ $<
endif

$(BUILD_DIR)/%.s.o: %.s
	$(AS) $(AS_FLAGS) -o $@ $<

$(BUILD_DIR)/%.bin.o: %.bin
	$(LD) -r -b binary -o $@ $<

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) $(OBJCOPY_FLAGS) $< $@

$(TARGET).z64: $(TARGET).bin
	@cp $< $@

$(N64CRC): tools/n64crc.c
	make -C tools

### Settings
.SECONDARY:
.PHONY: all clean default
SHELL = /bin/bash -e -o pipefail
