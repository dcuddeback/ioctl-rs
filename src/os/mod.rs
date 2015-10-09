#[cfg(any(target_os = "linux", target_os = "android"))]
pub mod linux;

#[cfg(target_os = "macos")]
pub mod macos;
