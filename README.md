## License

Copyright © 2026 @treespire

This project is licensed under the GNU General Public License v3.0 or later.
See [LICENSE](LICENSE) for the full text. Third-party components and their
licences are listed in [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md).

## Description

This project is a free hobby operating system, built through contributions
and by its community. Contributors and supporters are very welcome,
and any help is gratefully appreciated.

* **Primary Target:** `riscv64`
* **Languages:** Written mostly in C++ and C (Rust is welcome too).
* **Executable Format:** Static ELF.

### Why this project exists

The project is developing to use the Plan 9 directory structure and the 9P protocol as the main protocol to focus on, something mostly not used by most operating systems today,
in favor of the standard directory structure.
It is riscv64 first, though I'll keep makefile options for other architectures (in case someone wants to port this desperately).


## Warning

This project is not meant for production use. **It is made for educational purposes and as a hobby.**
It won't be anything big like Linux/GNU or other hobby operating systems.

## COMPILE


### Dependencies

Any `make` command depends on GNU make (`gmake`) and is expected to be run using it. This usually means using `make` on most GNU/Linux distros, or `gmake` on other non-GNU systems.

It is recommended to build this project using a standard UNIX-like system, using a Clang/LLVM toolchain capable of cross compilation.

Building also requires `git`, used to fetch the kernel's dependencies (see `kernel/get-deps`), `curl`, used to download the Limine release and the EDK2 OVMF firmware images, and a C compiler for the host (`cc` by default, see the `HOST_CC` `make` variable), used to build the `limine` host utility.

Additionally, building an ISO with `make all` requires `xorriso`, and building a HDD/USB image with `make all-hdd` requires `sgdisk` (usually from `gdisk` or `gptfdisk` packages) and `mtools`.

Assembly files with the `*.S` extension are built using the same toolchain as the C and C++ sources.
The `run` targets require `qemu`.

### How to Build

Using  `make run` is recommended.

In case permission errors occur, you might want to use  `chmod +x ./kernel/get-deps`,
and then repeat `make run`.

There is only one command after all(whether it's  `make run` or  `make all`).

### Toolchain selection

The `TOOLCHAIN` and `TOOLCHAIN_PREFIX` `make` variables can be used to set the toolchain. `TOOLCHAIN` can be set to `llvm` to use Clang/LLVM.

For example:
```
make TOOLCHAIN=llvm
```
`

The kernel is linked through the C++ compiler driver, using its default linker for GCC and LLD for Clang. A different linker can be picked by adding a `-fuse-ld=` option to `LDFLAGS`.

Link-time optimisation can be enabled by adding `-flto` to `CFLAGS` and `CXXFLAGS`, for example:
```
make CFLAGS='-g -O2 -pipe -flto' CXXFLAGS='-g -O2 -pipe -flto'
```

### Architectural targets

The `ARCH` make variable determines the target architecture to build the kernel and image for.
The primary target is 'riscv64'.

### Makefile targets

Running `make all` will compile the kernel (from the `kernel/` directory) and then generate a bootable ISO image.

Running `make all-hdd` will compile the kernel and then generate a raw image suitable to be flashed onto a USB stick or hard drive/SSD.

Running `make run` will build the kernel and a bootable ISO (equivalent to make all) and then run it using `qemu` (if installed).

Running `make run-hdd` will build the kernel and a raw HDD image (equivalent to make all-hdd) and then run it using `qemu` (if installed).
