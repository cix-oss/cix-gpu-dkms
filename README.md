# cix-gpu-dkms

CIX GPU kernel driver source packaged for DKMS.

This repository provides the source used by the `cix-gpu-dkms` Debian package.
The package installs DKMS source as `cix-gpu-kmd` and builds the following kernel
modules for the target system kernel when matching kernel headers are available:

- `mali_kbase`
- `protected_memory_allocator`
- `memory_group_manager`

## Build

Install the Debian packaging dependencies for the target system, then build from
the repository root:

```bash
dpkg-buildpackage -us -uc
```

The resulting `cix-gpu-dkms_*_all.deb` package can be installed with:

```bash
sudo apt install ./cix-gpu-dkms_*_all.deb
```

After installation, DKMS status should show `cix-gpu-kmd` built for the target
kernel:

```bash
dkms status | grep cix-gpu-kmd
```

## Packaging

Debian packaging metadata lives under `debian/`. The package installs the DKMS
source under `/usr/src/cix-gpu-kmd-1.0.0/`.

## License

Most source files are licensed under GPL-2.0 terms, with many kernel-facing
files using `GPL-2.0 WITH Linux-syscall-note`. `gpu.mk` is licensed under the
Apache License 2.0. See `LICENSE`, `license.txt`, and `debian/copyright` for
the complete license and copyright details.
