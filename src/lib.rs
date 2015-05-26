extern crate libc;

#[cfg(target_os = "linux")]
pub use os::linux::*;

#[cfg(target_os = "macos")]
pub use os::macos::*;

mod os;
