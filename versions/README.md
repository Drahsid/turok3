# versions

This document details the contents of this folder.

## setup files
This decompilation project uses a tool called [splat](https://github.com/ethteck/splat/). Splat uses various files in the process of disecting and disassembling game roms. Additionally, splat is responsible for generating the linker script which is used to rebuild the rom.

### checksum
The checksumfiles provide the final checksum for the rom.

### yamls
The most important file that splat uses is the configuration file. The configuration file tells splat how and where to split and disassemble parts of the rom. It primarily uses a list of segments and offsets. For information on how to modify the configuration file, and more refer to the [splat wiki](https://github.com/ethteck/splat/wiki).

### diff_settings
The diff_settings files provide configuration for the [asm differ](../tools/asm-differ).

### symbol_addrs
The symbol_addrs files inform the linker where defined symbols for data and functions are. They have the same syntax any linker script (such as ones you would pass into ld using `-T`), with additional context that you can provide through comments. These comments can describe how large a symbol is, and its' type.

### undefined_funcs/syms
These are linker scripts that are used to explicitly provide mnemonics for (technically) undefined symbols.
