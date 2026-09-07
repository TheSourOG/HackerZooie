# HackerZooie

This project, based on [n64decomp/banjo-kazooie](https://github.com/n64decomp/banjo-kazooie), aims to provide a flexible, and convenient base for creating Banjo-Kazooie ROM hacks. **It is not producing a PC Port.**

## Discord Servers:

### [HackerN64](https://discord.gg/brETAakcXr)

### [Hackpack](https://discord.gg/HzqWfGTM3n)

## Getting Started

The recommended base ROM is **Banjo-Kazooie US v1.0**.

Place the ROM in the **root** of the repository as:

```text
baserom.us.v10.z64
```
SHA-1:

```text
1fe1632098865f639e22c11b9a81ee8f29c75d7a
```
You can verify it with:

```bash
sha1sum baserom.us.v10.z64
```
Make sure to go to **include/config/** to toggle features and see what is there.

## Building

The following instructions should work on the following platforms:
- Ubuntu 18.04 or higher (x86_64)
- Docker only
    - Linux (x86_64, ARM)
    - macOS (x86_64, ARM)

Building Instructions Table Of Contents:
- [Local (Linux)](#local-linux)
- [Local (Docker - Linux/macOS)](#local-docker---linuxmacos)

## Local (Linux)

Works with Ubuntu 18.04 or higher.

### 1. Install Dependencies

From the repository **root**, run:

```sh
sudo apt-get update && sudo apt-get install -y $(cat packages.txt)
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
git submodule update --init --recursive
python3 -m venv .venv
.venv/bin/python3 -m pip install -r requirements.txt
```
Restart your shell after Rust installs.

### 2. Make

The first time you compile a **fresh clone**, use:

```bash
make fresh
```
`make fresh` performs a fresh build while extracting the Vanilla assets. This is the command to use when setting up the repository for the first time or when you intentionally want to **reset** assets back to their Vanilla state. `make`, `make emu`, `make n64`, etc. all retain your asset changes.

## Local (Docker - Linux/macOS)

Docker can be used to build the repository without installing the build
dependencies directly on your system.

### 1. Build the Docker Image

From the repository **root**, run:

```sh
docker build -t hackerzooie .
```
**NOTE for ARM users**: Use this command instead:

```sh
docker build --platform linux/amd64 -t hackerzooie .
```

### 2. Run the Docker Container

```sh
docker run -it --rm -v "$(pwd):/banjo" hackerzooie
```
**NOTE for ARM users**: Use this command instead:

```sh
docker run --platform linux/amd64 -it --rm -v "$(pwd):/banjo" hackerzooie
```
### 3. Make

Follow the same instructions as above in "Local (Linux)".

To exit Docker, simply type `exit`.

## UNFLoader Support

The repository supports UNFLoader for use with your flashcart + USB when you run `make n64` or `make n64-dbg`.

Further instructions can be found at the [official repository](https://github.com/buu342/N64-UNFLoader).

**NOTE**: Support for debugging over USB in UNFLoader with `make n64-dbg` is still a WIP, compiling with `make n64` should still load the rom to the flashcart however.

## Contributing

Contributions are very welcomed. When contributing a feature, please make it configurable where appropriate like the other **include/config/** features, and avoid unnecessarily breaking compatibility with upstream. Also, please avoid contributing features that **bloat** the repository.

## Contributors

TheSourOG

**Special Thanks**

The other HackerN64 devs for laying the foundation down.

GiantJigglypuff3 for his feature-packed [custom branch](https://gitlab.com/CyrusKashef/banjo-kazooie/-/tree/features/custom_file?ref_type=heads) of the Banjo-Kazooie decompilation.
