#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

#include <sys/ioctl.h>

#ifdef HAVE_SYS_SOCKET_H
# include <sys/socket.h>
#endif

#ifdef HAVE_NET_IF_H
# include <net/if.h>
#endif

#ifdef HAVE_TERMIOS_H
# include <termios.h>
#endif

#ifdef HAVE_UNISTD_H
# include <unistd.h>
#endif

#ifdef HAVE_IOKIT_SERIAL_IOSS_H
# include <IOKit/serial/ioss.h>
#endif


template <typename T>
std::string type_name(T);

template <> std::string type_name(int)           { return "c_int";   }
template <> std::string type_name(unsigned int)  { return "c_uint";  }
template <> std::string type_name(long)          { return "c_long";  }
template <> std::string type_name(unsigned long) { return "c_ulong"; }


#define constant(CONST) { \
    std::cout << "pub const " #CONST ": " << type_name(CONST) << " = 0x" << \
      std::hex << std::setfill('0') << std::setw(8) << (CONST) << ";" << std::endl; \
}

void header(std::string hdr)
{
    std::cout << std::endl;
    std::cout << "// " << hdr << std::endl;
    std::cout << std::endl;
}


int main()
{
#ifdef HAVE_SYS_SOCKET_H
    header("socket");

#ifdef FIOSETOWN
    constant(FIOSETOWN);
#endif
#ifdef SIOCSPGRP
    constant(SIOCSPGRP);
#endif
#ifdef FIOGETOWN
    constant(FIOGETOWN);
#endif
#ifdef SIOCGPGRP
    constant(SIOCGPGRP);
#endif
#ifdef SIOCATMAR
    constant(SIOCATMAR);
#endif
#ifdef SIOCGSTAMP
    constant(SIOCGSTAMP);
#endif
#endif // HAVE_SYS_SOCKET_H


#ifdef HAVE_TERMIOS_H
    header("termios");

#ifdef TCGETS
    constant(TCGETS);
#endif
#ifdef TCSETS
    constant(TCSETS);
#endif
#ifdef TCSETSW
    constant(TCSETSW);
#endif
#ifdef TCSETSF
    constant(TCSETSF);
#endif
#ifdef TCGETA
    constant(TCGETA);
#endif
#ifdef TCSETA
    constant(TCSETA);
#endif
#ifdef TCSETAW
    constant(TCSETAW);
#endif
#ifdef TCSETAF
    constant(TCSETAF);
#endif
#ifdef TCSBRK
    constant(TCSBRK);
#endif
#ifdef TCXONC
    constant(TCXONC);
#endif
#ifdef TCFLSH
    constant(TCFLSH);
#endif
#ifdef TIOCEXCL
    constant(TIOCEXCL);
#endif
#ifdef TIOCNXCL
    constant(TIOCNXCL);
#endif
#ifdef TIOCSCTTY
    constant(TIOCSCTTY);
#endif
#ifdef TIOCGPGRP
    constant(TIOCGPGRP);
#endif
#ifdef TIOCSPGRP
    constant(TIOCSPGRP);
#endif
#ifdef TIOCOUTQ
    constant(TIOCOUTQ);
#endif
#ifdef TIOCSTI
    constant(TIOCSTI);
#endif
#ifdef TIOCGWINSZ
    constant(TIOCGWINSZ);
#endif
#ifdef TIOCSWINSZ
    constant(TIOCSWINSZ);
#endif
#ifdef TIOCMGET
    constant(TIOCMGET);
#endif
#ifdef TIOCMBIS
    constant(TIOCMBIS);
#endif
#ifdef TIOCMBIC
    constant(TIOCMBIC);
#endif
#ifdef TIOCMSET
    constant(TIOCMSET);
#endif
#ifdef TIOCGSOFTCAR
    constant(TIOCGSOFTCAR);
#endif
#ifdef TIOCSSOFTCAR
    constant(TIOCSSOFTCAR);
#endif
#ifdef FIONREAD
    constant(FIONREAD);
#endif
#ifdef TIOCINQ
    constant(TIOCINQ);
#endif
#ifdef TIOCLINUX
    constant(TIOCLINUX);
#endif
#ifdef TIOCCONS
    constant(TIOCCONS);
#endif
#ifdef TIOCGSERIAL
    constant(TIOCGSERIAL);
#endif
#ifdef TIOCSSERIAL
    constant(TIOCSSERIAL);
#endif
#ifdef TIOCPKT
    constant(TIOCPKT);
#endif
#ifdef FIONBIO
    constant(FIONBIO);
#endif
#ifdef TIOCNOTTY
    constant(TIOCNOTTY);
#endif
#ifdef TIOCSETD
    constant(TIOCSETD);
#endif
#ifdef TIOCGETD
    constant(TIOCGETD);
#endif
#ifdef TCSBRKP
    constant(TCSBRKP);
#endif
#ifdef TIOCTTYGSTRUCT
    constant(TIOCTTYGSTRUCT);
#endif
#ifdef FIONCLEX
    constant(FIONCLEX);
#endif
#ifdef FIOCLEX
    constant(FIOCLEX);
#endif
#ifdef FIOASYNC
    constant(FIOASYNC);
#endif
#ifdef TIOCSERCONFIG
    constant(TIOCSERCONFIG);
#endif
#ifdef TIOCSERGWILD
    constant(TIOCSERGWILD);
#endif
#ifdef TIOCSERSWILD
    constant(TIOCSERSWILD);
#endif
#ifdef TIOCGLCKTRMIOS
    constant(TIOCGLCKTRMIOS);
#endif
#ifdef TIOCSLCKTRMIOS
    constant(TIOCSLCKTRMIOS);
#endif
#ifdef TIOCSERGSTRUCT
    constant(TIOCSERGSTRUCT);
#endif
#ifdef TIOCSERGETLSR
    constant(TIOCSERGETLSR);
#endif
#ifdef TIOCSERGETMULTI
    constant(TIOCSERGETMULTI);
#endif
#ifdef TIOCSERSETMULTI
    constant(TIOCSERSETMULTI);
#endif
#endif // HAVE_TERMIOS_H


#ifdef HAVE_IOKIT_SERIAL_IOSS_H
    header("IOKit");

#ifdef IOSSDATALAT
    constant(IOSSDATALAT);
#endif
#ifdef IOSSDATALAT_32
    constant(IOSSDATALAT_32);
#endif
#ifdef IOSSDATALAT_64
    constant(IOSSDATALAT_64);
#endif
#ifdef IOSSIOSPEED
    constant(IOSSIOSPEED);
#endif
#ifdef IOSSIOSPEED_32
    constant(IOSSIOSPEED_32);
#endif
#ifdef IOSSIOSPEED_64
    constant(IOSSIOSPEED_64);
#endif
#endif // HAVE_IOKIT_SERIAL_IOSS_H


#ifdef HAVE_NET_IF_H
    header("sockios");

#ifdef SIOCADDRT
    constant(SIOCADDRT);
#endif
#ifdef SIOCDELRT
    constant(SIOCDELRT);
#endif
#ifdef SIOCGIFNAME
    constant(SIOCGIFNAME);
#endif
#ifdef SIOCSIFLINK
    constant(SIOCSIFLINK);
#endif
#ifdef SIOCGIFCONF
    constant(SIOCGIFCONF);
#endif
#ifdef SIOCGIFFLAGS
    constant(SIOCGIFFLAGS);
#endif
#ifdef SIOCSIFFLAGS
    constant(SIOCSIFFLAGS);
#endif
#ifdef SIOCGIFADDR
    constant(SIOCGIFADDR);
#endif
#ifdef SIOCSIFADDR
    constant(SIOCSIFADDR);
#endif
#ifdef SIOCGIFDSTADDR
    constant(SIOCGIFDSTADDR);
#endif
#ifdef SIOCSIFDSTADDR
    constant(SIOCSIFDSTADDR);
#endif
#ifdef SIOCGIFBRDADDR
    constant(SIOCGIFBRDADDR);
#endif
#ifdef SIOCSIFBRDADDR
    constant(SIOCSIFBRDADDR);
#endif
#ifdef SIOCGIFNETMASK
    constant(SIOCGIFNETMASK);
#endif
#ifdef SIOCSIFNETMASK
    constant(SIOCSIFNETMASK);
#endif
#ifdef SIOCGIFMETRIC
    constant(SIOCGIFMETRIC);
#endif
#ifdef SIOCSIFMETRIC
    constant(SIOCSIFMETRIC);
#endif
#ifdef SIOCGIFMEM
    constant(SIOCGIFMEM);
#endif
#ifdef SIOCSIFMEM
    constant(SIOCSIFMEM);
#endif
#ifdef SIOCGIFMTU
    constant(SIOCGIFMTU);
#endif
#ifdef SIOCSIFMTU
    constant(SIOCSIFMTU);
#endif
#ifdef OLD_SIOCGIFHWADDR
    constant(OLD_SIOCGIFHWADDR);
#endif
#ifdef SIOCSIFHWADDR
    constant(SIOCSIFHWADDR);
#endif
#ifdef SIOCGIFENCAP
    constant(SIOCGIFENCAP);
#endif
#ifdef SIOCSIFENCAP
    constant(SIOCSIFENCAP);
#endif
#ifdef SIOCGIFHWADDR
    constant(SIOCGIFHWADDR);
#endif
#ifdef SIOCGIFSLAVE
    constant(SIOCGIFSLAVE);
#endif
#ifdef SIOCSIFSLAVE
    constant(SIOCSIFSLAVE);
#endif
#ifdef SIOCADDMULTI
    constant(SIOCADDMULTI);
#endif
#ifdef SIOCDELMULTI
    constant(SIOCDELMULTI);
#endif
#ifdef SIOCADDRTOLD
    constant(SIOCADDRTOLD);
#endif
#ifdef SIOCDELRTOLD
    constant(SIOCDELRTOLD);
#endif
#ifdef SIOCDARP
    constant(SIOCDARP);
#endif
#ifdef SIOCGARP
    constant(SIOCGARP);
#endif
#ifdef SIOCSARP
    constant(SIOCSARP);
#endif
#ifdef SIOCDRARP
    constant(SIOCDRARP);
#endif
#ifdef SIOCGRARP
    constant(SIOCGRARP);
#endif
#ifdef SIOCSRARP
    constant(SIOCSRARP);
#endif
#ifdef SIOCGIFMAP
    constant(SIOCGIFMAP);
#endif
#ifdef SIOCSIFMAP
    constant(SIOCSIFMAP);
#endif
#endif // HAVE_NET_IF_H


#ifdef HAVE_TERMIOS_H
    header("modem control lines");

#ifdef TIOCM_LE
    constant(TIOCM_LE);
#endif
#ifdef TIOCM_DTR
    constant(TIOCM_DTR);
#endif
#ifdef TIOCM_RTS
    constant(TIOCM_RTS);
#endif
#ifdef TIOCM_ST
    constant(TIOCM_ST);
#endif
#ifdef TIOCM_SR
    constant(TIOCM_SR);
#endif
#ifdef TIOCM_CTS
    constant(TIOCM_CTS);
#endif
#ifdef TIOCM_CAR
    constant(TIOCM_CAR);
#endif
#ifdef TIOCM_CD
    constant(TIOCM_CD);
#endif
#ifdef TIOCM_RNG
    constant(TIOCM_RNG);
#endif
#ifdef TIOCM_RI
    constant(TIOCM_RI);
#endif
#ifdef TIOCM_DSR
    constant(TIOCM_DSR);
#endif
#endif // HAVE_TERMIOS_H

    return EXIT_SUCCESS;
}
