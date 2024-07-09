use libc::c_int;

// socket

pub const FIOSETOWN: c_int = -0x7ffb9984;
pub const FIOGETOWN: c_int = 0x4004667b;
pub const SIOCSPGRP: c_int = -0x7ffb8cf8;
pub const SIOCGPGRP: c_int = 0x40047309;

// termios

pub const TCGETS: c_int = 0x5401;
pub const TCSETS: c_int = 0x5402;
pub const TCSETSW: c_int = 0x5403;
pub const TCSETSF: c_int = 0x5404;
pub const TCGETA: c_int = 0x5405;
pub const TCSETA: c_int = 0x5406;
pub const TCSETAW: c_int = 0x5407;
pub const TCSETAF: c_int = 0x5408;
pub const TCSBRK: c_int = 0x5409;
pub const TCXONC: c_int = 0x540b;
pub const TCFLSH: c_int = 0x540c;
pub const TIOCEXCL: c_int = 0x2000740d;
pub const TIOCNXCL: c_int = 0x2000740e;
pub const TIOCGPGRP: c_int = 0x40047477;
pub const TIOCSPGRP: c_int = -0x7ffb8b8a;
pub const TIOCOUTQ: c_int = 0x40047473;
pub const TIOCSTI: c_int = -0x7ffe8b8e;
pub const TIOCGWINSZ: c_int = 0x40087468;
pub const TIOCSWINSZ: c_int = -0x7ff78b99;
pub const TIOCMGET: c_int = 0x4004746a;
pub const TIOCMBIS: c_int = -0x7ffb8b94;
pub const TIOCMBIC: c_int = -0x7ffb8b95;
pub const TIOCMSET: c_int = -0x7ffb8b93;
pub const FIONREAD: c_int = 0x4004667f;
pub const TIOCCONS: c_int = -0x7ffb8b9e;
pub const TIOCPKT: c_int = -0x7ffb8b90;
pub const FIONBIO: c_int = -0x7ffb9982;
pub const TIOCNOTTY: c_int = 0x20007471;
pub const TIOCSETD: c_int = -0x7ffb8bff;
pub const TIOCGETD: c_int = 0x40047400;
pub const FIONCLEX: c_int = 0x20006602;
pub const FIOCLEX: c_int = 0x20006601;
pub const FIOASYNC: c_int = -0x7ffb9983;

// sockios

pub const SIOCADDRT: c_int = -0x7fc78df6;
pub const SIOCDELRT: c_int = -0x7fc78df5;
pub const SIOCGIFCONF: c_int = -0x3fef96bb;
pub const SIOCGIFFLAGS: c_int = -0x3fd796ef;
pub const SIOCSIFFLAGS: c_int = -0x7fd796f0;
pub const SIOCGIFADDR: c_int = -0x3fd796df;
pub const SIOCSIFADDR: c_int = -0x7fd796f4;
pub const SIOCGIFDSTADDR: c_int = -0x3fd796de;
pub const SIOCSIFDSTADDR: c_int = -0x7fd796f2;
pub const SIOCGIFBRDADDR: c_int = -0x3fd796dd;
pub const SIOCSIFBRDADDR: c_int = -0x7fd796ed;
pub const SIOCGIFNETMASK: c_int = -0x3fd796db;
pub const SIOCSIFNETMASK: c_int = -0x7fd796ea;
pub const SIOCGIFMETRIC: c_int = -0x3fd796e9;
pub const SIOCSIFMETRIC: c_int = -0x7fd796e8;
pub const SIOCGIFMTU: c_int = -0x3fd796aa;
pub const SIOCSIFMTU: c_int = -0x7fd796a8;
pub const SIOCGIFHWADDR: c_int = -0x3fab966b;
pub const SIOCADDMULTI: c_int = -0x7fdf96cf;
pub const SIOCDELMULTI: c_int = -0x7fdf96ce;
pub const SIOCDARP: c_int = -0x7fb396e0;
pub const SIOCGARP: c_int = -0x3fb396da;
pub const SIOCSARP: c_int = -0x7fb396e2;

// modem control lines

pub const TIOCM_LE: c_int = 0x1;
pub const TIOCM_DTR: c_int = 0x2;
pub const TIOCM_RTS: c_int = 0x4;
pub const TIOCM_ST: c_int = 0x8;
pub const TIOCM_SR: c_int = 0x10;
pub const TIOCM_CTS: c_int = 0x20;
pub const TIOCM_CAR: c_int = 0x40;
pub const TIOCM_CD: c_int = 0x40;
pub const TIOCM_RNG: c_int = 0x80;
pub const TIOCM_RI: c_int = 0x80;
pub const TIOCM_DSR: c_int = 0x100;

extern "C" {
    pub fn ioctl(fd: c_int, request: c_int, ...) -> c_int;
}
