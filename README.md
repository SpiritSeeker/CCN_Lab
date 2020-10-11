# CCN_Lab
Repository containing the software experiments of Computer Communication Lab (EC69504).

## Cloning the repo
This repository contains submodules, so clone the repo using
```shell
git clone --recurse-submodules https://github.com/SpiritSeeker/CCN_Lab.git
```
for HTTPS, or
```shell
git clone --recurse-submodules git@github.com:SpiritSeeker/CCN_Lab.git
```
for SSH.

## Repository Structure

    .
    ├── Assignment#             # Files related to the Assignments (Codes, Report, and individual READMEs)
    ├── src                     # Additional helper files
    ├── vendor                  # 3rd party softwares
    ├── premake5.lua            # Premake directives file
    ├── LICENSE
    └── README.md

## Building with Premake
Premake is used for ease of compiling all Assignments with very few commands.

### Prerequisites
An installation of `make` or any of its variants.

### Generating the Makefiles
From the root folder, run
```shell
vendor/bin/premake/premake5 gmake2
```
This will generate all the necessary Makefiles.

### Compiling with make
After generating the Makefiles with Premake, run `make` from the root folder
```shell
make
```
This should generate all the executable binaries in a directory `bin` under all Assignments.

### Run the binaries
Run the required binary with `./`. For example, for running the code for generating Poisson distribution in Assignment1,
```shell
./Assignment1/bin/poisson
```

## Building without Premake
Incase you do not have a `make` environment or you just want to compile a file manually, read the README.md files in the corresponding Assignment directories. They contain the steps for manually compiling the codes for the respective Assignment.
