# ioctl_list

This directory contains a C++ program called `ioctl_list`, which will output Rust definitions for
any ioctls found on the current system.

## Adding a New Platform

To add support for a new platform, one should generate ioctl definitions for the platform by running
the `ioctl_list` program. The `ioctl_list` program must be run on the target platform. Start by
building `ioctl_list`:

```sh
./autogen.sh && ./configure && make
```

After `ioctl_list` is built, run it:

```sh
./ioctl_list
```

Running `ioctl_list` will print to stdout something resembling a Rust source file:

```rust
// socket

pub const FIOSETOWN: c_int = 0x00008901;
pub const SIOCSPGRP: c_int = 0x00008902;
pub const FIOGETOWN: c_int = 0x00008903;
pub const SIOCGPGRP: c_int = 0x00008904;
pub const SIOCGSTAMP: c_int = 0x00008906;

/* ... more ... */
```

`ioctl_list` tries to guess the correct type for each constant, but they're not always correct.
Check the results to make sure the constants have the correct data type. For example, the constants
that represent ioctl commands should match the data type of the `request` parameter of `ioctl()`
(consult the target platform's ioctl(2) man page).

Save the output to a file named after the target platform in `src/os` and correct any types that are
incorrect. Import any types needed from `libc` at the top of the new file. Next, add `mod` and `use`
declarations in `src/os/mod.rs` and `src/lib.rs` with an appropriate `#[cfg(...)]` guard. Consult
the existing implementations as reference.

## Adding a New IOCTL

Adding a new ioctl requires editing `ioctl_list` to generate the appropriate definition. If the
ioctl requires including a header that isn't currently included, add an appropriate
`AC_CHECK_HEADERS()` call to `configure.ac` and include the header with a matching `#ifdef` guard.
Add any new ioctls to `src/main.cc` with appropriate `#ifdef` guards.

With the new ioctls added, compile and run `ioctl_list` for each supported platform. For each
platform, copy the new constants to the appropriate source file.
