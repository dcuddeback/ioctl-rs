extern crate libc;

use std::io;
use std::mem;
use std::os::unix::io::RawFd;

use libc::c_int;

#[cfg(any(target_os = "linux", target_os = "android"))]
pub use os::linux::*;

#[cfg(target_os = "macos")]
pub use os::macos::*;

#[cfg(target_os = "freebsd")]
pub use os::freebsd::*;

#[cfg(target_os = "dragonfly")]
pub use os::dragonfly::*;

#[cfg(target_os = "openbsd")]
pub use os::openbsd::*;

mod os;


/// Put the terminal in exclusive mode.
pub fn tiocexcl(fd: RawFd) -> io::Result<()> {
    match unsafe { ioctl(fd, TIOCEXCL) } {
        0 => Ok(()),
        _ => Err(io::Error::last_os_error())
    }
}

/// Disable exclusive mode.
pub fn tiocnxcl(fd: RawFd) -> io::Result<()> {
    match unsafe { ioctl(fd, TIOCNXCL) } {
        0 => Ok(()),
        _ => Err(io::Error::last_os_error())
    }
}

/// Get the status of modem bits.
pub fn tiocmget(fd: RawFd) -> io::Result<BitsInt> {
    let mut bits: BitsInt = unsafe { mem::uninitialized() };

    match unsafe { ioctl(fd, TIOCMGET, &mut bits) } {
        0 => Ok(bits),
        _ => Err(io::Error::last_os_error())
    }
}

/// Set the status of modem bits.
pub fn tiocmset(fd: RawFd, bits: BitsInt) -> io::Result<()> {
    match unsafe { ioctl(fd, TIOCMSET, &bits) } {
        0 => Ok(()),
        _ => Err(io::Error::last_os_error())
    }
}

/// Set the indicated modem bits.
pub fn tiocmbis(fd: RawFd, bits: BitsInt) -> io::Result<()> {
    match unsafe { ioctl(fd, TIOCMBIS, &bits) } {
        0 => Ok(()),
        _ => Err(io::Error::last_os_error())
    }
}

/// Clear the indicated modem bits.
pub fn tiocmbic(fd: RawFd, bits: BitsInt) -> io::Result<()> {
    match unsafe { ioctl(fd, TIOCMBIC, &bits) } {
        0 => Ok(()),
        _ => Err(io::Error::last_os_error())
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    /// Will fail to compile if types don't match.
    #[allow(dead_code)]
    fn compile_bits() {
        tiocmbic(0, TIOCM_RTS).unwrap();
    }

    #[allow(dead_code)]
    fn compile_get_bits() {
        let bits = tiocmget(0).unwrap();
        tiocmset(0, bits).unwrap();
    }
}
