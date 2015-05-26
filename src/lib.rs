extern crate libc;

#[cfg(target_os = "linux")]
pub use os::linux::*;

mod os;
