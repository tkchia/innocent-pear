#include <cinttypes>
#include <cstdlib>
#include <unistd.h>
#include <sys/mman.h>
#include <biting-pear/orly.h>

extern unsigned char startup_text_start[]
    __asm("_.biting_pear.text.startup.start")
    __attribute__((section(".text.startup")));
extern unsigned char startup_text_end[]
    __asm("_.biting_pear.text.startup.end")
    __attribute__((section(".text.startup.zzzzzzzzzzzzzzzzzzzzzzzz")));

#ifdef biting_pear_HAVE_CTOR_PRIORITY
__attribute__((constructor(101)))
#else
__attribute__((constructor))
#endif
static void unscramble()
{
	uintptr_t pg_sz = (uintptr_t)getpagesize();
	uintptr_t prot_start = (uintptr_t)startup_text_start & -pg_sz;
	uintptr_t prot_end = ((uintptr_t)startup_text_end + pg_sz - 1)
	    & -pg_sz;
	mprotect((void *)prot_start, (std::size_t)(prot_end - prot_start),
	    PROT_READ | PROT_WRITE | PROT_EXEC);
	biting_pear::orly<biting_pear_DOGE_STATE, unsigned char, false,
	    true>().wut(startup_text_start, startup_text_end);
	__builtin___clear_cache(startup_text_start, startup_text_end);
}
