/* FUN_a0062f3c (leon2s 0xa0062f3c-0xa0062fc8, 140 bytes), flags -mcpu=v8 -Os -g.
 * For mode 1 calls FUN_a00b192c(), otherwise writes 0x55 to hardware register 0xcf03c800. Then polls register
 * 0xcf03c804 for the value 0xdd up to 0x9c401 times (eight nops between polls) and returns 1 when it appears;
 * on timeout writes 0x88 to 0xcf03c800 and returns 0.
 * Source forms: the poll counter is initialised at its declaration; the poll loop and the final store go through
 * two register pointers set before the loop (the firmware keeps both addresses in registers). The eight nops are
 * the documented delay body.
 */
#define REG_C800 (*(volatile unsigned int *)0xcf03c800)
#define REG_C804 (*(volatile unsigned int *)0xcf03c804)
extern void FUN_a00b192c(void);

int FUN_a0062f3c(unsigned char mode)
{
    unsigned int i = 0;
    volatile unsigned int *r, *st;

    if (mode == 1)
        FUN_a00b192c();
    else
        REG_C800 = 0x55;
    r = &REG_C800;
    st = &REG_C804;
    for (; i <= 0x9c400; i++) {
        if (*st == 0xdd)
            return 1;
        __asm__("nop");
        __asm__("nop");
        __asm__("nop");
        __asm__("nop");
        __asm__("nop");
        __asm__("nop");
        __asm__("nop");
        __asm__("nop");
    }
    *r = 0x88;
    return 0;
}
