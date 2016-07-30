#include <cinttypes>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/mman.h>
#include <innocent-pear/kthxbai.h>
#include <innocent-pear/rofl.h>

extern unsigned char unlikely_text_start[]
    __asm("_.innocent_pear.text.unlikely.start");
extern unsigned char startup_text_start[]
    __asm("_.innocent_pear.text.startup.start");
extern unsigned char our_text_end[]
    __asm("_.innocent_pear.text.startup.end");

__attribute__((
#ifdef innocent_pear_HAVE_CTOR_PRIORITY
    constructor(65535),
#else
    constructor,
#endif
    section(".text.startup.zzzzzzzzzzzzzzzzzzzzzzzz"),
    optimize("no-reorder-blocks")))
static void scramble()
{
	using innocent_pear::ops::allow_debugger_unsafes;
	uintptr_t pg_sz = (uintptr_t)getpagesize();
	uintptr_t prot_start = (uintptr_t)unlikely_text_start & -pg_sz;
	uintptr_t prot_end = ((uintptr_t)our_text_end + pg_sz - 1) & -pg_sz;
	innocent_pear::kthxbai?<unsigned, allow_debugger_unsafes>
	    prot(PROT_READ | PROT_EXEC);
	innocent_pear::rofl?<allow_debugger_unsafes>::memset
	    (startup_text_start);
	innocent_pear::rofl?<allow_debugger_unsafes>::mprotect
	    ((void *)prot_start, (std::size_t)(prot_end - prot_start),
	    (int)(unsigned)prot);
}