# Turok 3

A in-progress decompilation of Turok 3 for the N64. This project currently focused on the US release, however supports the other versions.

## Building (Linux)
The build process has the following package requirements:
- git
- build-essential
- binutils-mips-linux-gnu
- python3

Under a Debian based distribution, you can install these with the following commands:
```
sudo apt update
sudo apt install git build-essential binutils-mips-linux-gnu python3
```

### Clone the repository
Clone `https://github.com/Drahsid/turok3.git` in whatever directory you wish. Make sure to initialize the submodules!
```
git clone https://github.com/Drahsid/turok3.git --recursive
cd turok3
git submodule init
```

### Install Python3 requirements
Navigate to `tools/splat/` and run `pip3 install -r requirements.txt`

### Prepare the base rom
Depending on the versions you wish to work with, you must rename the rom or roms and move them into the [version](version) folder. Here is a list for the names that you should give to each rom. Note that you only need one of these for the project.

|Version|Build Date|Name|GAME_VERSION|
|:--|:--|:--|:--|
|8/5/2000|May  3 2000.17:33:41|baserom.3-5-2000.z64|3-5-2000|
|N4TKER09|May 31 2000.17:25:23|baserom.09.z64|09|
|N4TKER10|Jun  6 2000.16:39:55|baserom.10.z64|10|
|N4TKER11|Jun 12 2000.16:23:15|baserom.11.z64|11|
|N4TKER15|Jun 26 2000.16:43:34|baserom.15.z64|15|
|N4TKER18|Jul 10 2000.11:01:57|baserom.18.z64|18|
|16/7/2000|Jul 16 2000.21:14:12|baserom.16-7-2000.z64|16-7-2000|
|US (and Nightdive dump)|Jul 18 2000.09:22:24|baserom.us.z64|us|
|EU|Jul 18 2000.10:01:59|baserom.eu.z64|eu|

Next, to extract the assets and code from the rom, run `make setup GAME_VERSION=[version]`. In this context, `[version]` is the value (as seen in the able above) that represents the version of the game that you want to setup. Note that each game is set up individually, so you can work on all of them at once. If you have every rom correctly set-up in the [version](version) folder, you can alternatively run `./setupall.sh` to run this step for every version.

If `GAME_VERSION` is not provided, it will default to `us`.

### Build the rom
Run `make GAME_VERSION=[version]` to build the rom. If `GAME_VERSION` is not provided, it will default to `us`. You can appent `-j` to speed up the build process.

#### Make Flags
to enable any of these, append `FLAG=1` to the end of the `make` command.

|Flag|Description|
|:--|:--|
|GAME_VERSION|This value can be `3-5-2000`, `09`, `10`, `11`, `15`, `18`, `16-7-2000`, `us`, or `eu`, and should correspond with the version of the game that you are working with. The default is `us`|
|NON_MATCHING|When this flag is enabled, `NON_MATCHING` functions will be built instead of their assembly|
|NON_MATCHING_DATA|When this flag is enabled, data that is not matched will be used over symbols|

#### Helpful Things

##### **Make Commands**
**check**: checks the results of the build for provided `GAME_VERSION`.

**nuke**: fully clean the build and assets for provided `GAME_VERSION`. Will require the setup step to be run again.

**nukeall**: fully clean the build and assets for every game version.

**context**: generate a `ctx.c` file that can beused with [mips to c](tools/mips_to_c)

##### **Shell Scripts**

**[checkall.sh](checkall.sh)**:
This script will run the `check` step for every version.

**[makeall.sh](makeall.sh)**:
This script will nuclearly setup and build every version.

**[setupall.sh](setupall.sh)**
This script will run the `setup` step for every version.

**[regnames.sh](regnames.sh)**
A limitation of the original assembler is that it does not have support for register names (no `-mrnames`.) Because of this, the assembly files that go through the original assembler use the register indexes. To make these more readable, you can pass the file as the first argument of this script to convert it, so that it uses register names.

### Hierarchy
At first-glance, the hierarchy of this project might seem like black-magic. Unfortunately, this is difficult to avoid with so many versions of the game to support.

In the [src](src) folder there are various other subdirectorys which correlate to a particular version of the game, and additionally there is the [common](src/common) directory. The [common](src/common) is for files that are matching on various versions of the game, where any differences are gated by ifdefs. The rest of the directories are for files that are unique to, or not matching other versions of the game. The ultimate goal is to inevitably have every piece of similar code being in the [common](src/common) directory when it is OK.

In the [versions](versions) folder are the files used to setup, configure, and check each version of the game. Additionally, for each setup version of the game, there will be a folder that corresponds to the `GAME_VERSION`, and when building, the results of the build will be produced in a folder titled `build`, which is inside of the aforementioned folder. For example, after building the us version of the game, the built rom will be produced in the directory `./versions/us/build/`.

For a more in-depth explanation of the contents of the versions folder, navigate [here](versions/README.md)

## Contributing
Contributions are welcome. If you would like to reserve a function, open a PR with the function or file name(s).

