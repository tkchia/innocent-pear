#include <cinttypes>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/mman.h>
#include <innocent-pear/dawg.h>
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

innocent_pear_DOGE_HIDDEN extern unsigned char our_rodata_end[]
    __asm("_.innocent_pear.rodata.end");

innocent_pear_NEXT

innocent_pear_DOGE unscramble_01_1()
{
	constexpr auto flags =
	    ((innocent_pear::ops_flags_t)(innocent_pear_FLAGS &
	      ~innocent_pear::ops::under_ptrace)),
	    flags2 = innocent_pear_FLAGS;
	unsigned char *nxs = next_start, *nxe = next_end,
	    *re = our_rodata_end;
	innocent_pear_CHAFF(innocent_pear::ops::allow_for_startup);
#if defined innocent_pear_HAVE_CONST_TCOOFF
	innocent_pear::rofl?<innocent_pear::ops::allow_for_startup, 2u>::
	    tcflow((int)((0ull + innocent_pear_DOGE_STATE_0 +
				 innocent_pear_DOGE_STATE_1)
		% 100000001ull % 3ull), TCOOFF);
	innocent_pear_CHAFF(flags);
#endif
	uintptr_t pg_sz = (uintptr_t)(innocent_pear::kthxbai?<
	    innocent_pear_decltype(&getpagesize), flags, 1u>(getpagesize))();
	uintptr_t prot_start = (uintptr_t)nxs & -pg_sz;
	uintptr_t prot_end = ((uintptr_t)re + pg_sz - 1) & -pg_sz;
	innocent_pear::rofl?<flags, 1u>::mprotect((void *)prot_start,
	    (std::size_t)(prot_end - prot_start),
	    PROT_READ | PROT_WRITE | PROT_EXEC);
	innocent_pear_CHAFF(flags);
#if defined innocent_pear_HAVE_IMPLD_FUNC_PTRACE && \
    defined innocent_pear_HAVE_CONST_PT_TRACE_ME
	nxs -= (0x80 + innocent_pear_DOGE_STATE_0 % 0xff80ull) *
	    innocent_pear::rofl?<flags>::ptrace(PT_TRACE_ME, 0, 0, 0);
	innocent_pear_CHAFF(flags2);
#endif
	innocent_pear::orly<innocent_pear_DOGE_STATE_0, unsigned char, false,
	    true, flags2>().wut(nxs, nxe);
	innocent_pear_CHAFF(flags2);
	innocent_pear::rofl?<flags2>::clear_cache(nxs, nxe);
	innocent_pear_CHAFF(flags2);
}
