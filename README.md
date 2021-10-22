# Turok 3
A in-progress decompilation of Turok 3 for the N64. This project currently supports the US release.

## Building (Linux)
The build process has the following package requirements:
- git
- build-essential
- binutils-mips-linux-gnu
- python3

Under a Debian based distribution, you can install these with the following commands:
```
sudo apt-get update
sudo apt-get install git build-essential binutils-mips-linux-gnu python3
```

### Clone the repository
Clone `https://github.com/Drahsid/turok3.git` in whatever directory you wish. Make sure to initialize the submodules!
```
git clone https://github.com/Drahsid/turok3.git --recursive
cd turok3
git submodule init
```

### Install Python3 requirements
Navigate to `tools/splat/` and run `pip3 install requirements.txt`

### Prepare the base rom
Copy over your US version of the Turok 3 rom into the root folder of this repository. Rename the rom to baserom.z64.

Next, run `make setup` to extract the assets of the rom.

### Build the rom
Just run `make` to build the rom.

## Contributing
Contributions are welcome. If you would like to reserve a function, open a PR with the function or file name(s).

