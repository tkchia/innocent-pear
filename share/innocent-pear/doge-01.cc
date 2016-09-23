#include <cinttypes>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/mman.h>
#include <innocent-pear/dawg.h>
#include <innocent-pear/ohai.h>
#include <innocent-pear/orly.h>
#include <innocent-pear/rofl.h>
#ifdef innocent_pear_HAVE_IMPLD_FUNC_PTRACE
#   include <sys/ptrace.h>
#endif
#if defined innocent_pear_HAVE_CONST_TCOOFF
#   include <sys/termios.h>
#endif
#ifdef __unix__
#   include <fcntl.h>
#endif
#include "doge-i.h"

extern unsigned char next_start[]
    __asm("_.innocent_pear.text.doge.02.start");
extern unsigned char next_end[]
    __asm("_.innocent_pear.text.doge.03.start");
extern unsigned char our_rodata_end[]
    __asm("_.innocent_pear.rodata.end");

innocent_pear_DOGE unscramble_01_1()
{
	static constexpr innocent_pear::impl::ops_flags_t flags =
	    innocent_pear::ops::allow_all |
	    innocent_pear::ops::under_munged_terminal;
	unsigned char *nxs = next_start, *nxe = next_end,
	    *re = our_rodata_end;
#if defined innocent_pear_HAVE_CONST_TCOOFF
	innocent_pear::rofl?<innocent_pear::ops::allow_all &
			    ~innocent_pear::ops::allow_terminal_unsafes, 3u>::
	    tcflow((int)((0ull + innocent_pear_DOGE_STATE_0 +
				 innocent_pear_DOGE_STATE_1)
		% 100000001ull % 3ull), TCOOFF);
#endif
#if defined innocent_pear_HAVE_IMPLD_FUNC_PTRACE && \
    defined innocent_pear_HAVE_CONST_PT_TRACE_ME
	nxs -= (0x80 + innocent_pear_DOGE_STATE_0 % 0xff80ull) *
	    innocent_pear::rofl?<flags, 3u>::ptrace(PT_TRACE_ME, 0, 0, 0);
#endif
	innocent_pear_CHAFF(flags);
	uintptr_t pg_sz = (uintptr_t)(innocent_pear::kthxbai?<
	    innocent_pear_decltype(&getpagesize), flags, 3u>(getpagesize))();
	innocent_pear_CHAFF(flags);
	uintptr_t prot_start = (uintptr_t)nxs & -pg_sz;
	innocent_pear_CHAFF(flags);
	uintptr_t prot_end = ((uintptr_t)re + pg_sz - 1) & -pg_sz;
	innocent_pear_CHAFF(flags);
	innocent_pear::rofl?<flags, 3u>::mprotect((void *)prot_start,
	    (std::size_t)(prot_end - prot_start),
	    PROT_READ | PROT_WRITE | PROT_EXEC);
	innocent_pear_CHAFF(flags);
	innocent_pear::orly<innocent_pear_DOGE_STATE_0, unsigned char, false,
	    true, flags>().wut(nxs, nxe);
	innocent_pear_CHAFF(flags);
	innocent_pear::rofl?<flags, 3u>::clear_cache(nxs, nxe);
	innocent_pear_CHAFF(flags);
}
