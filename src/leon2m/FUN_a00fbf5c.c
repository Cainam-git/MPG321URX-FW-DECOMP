/* leon2m FUN_a00fbf5c @ 0xa00fbf5c  MATCH (-mcpu=v8 -O3 -g)
 * on == 1: sets bit 31 of the word at 0xD0040000, then calls func_0x4008a880(0xC, 0x100, 0x9A814) and
 * func_0x40089820(0xC, 0x100) (ROM routines; same calls as FUN_a00fbfd4). Otherwise clears bit 31 and calls
 * func_0x40089968(0xC, 0x100). Callers: FUN_a014e878 (twice).
 * The firmware leaves the (byte-extended) parameter in %i0, so the function is written as returning on; each arm
 * has its own return (one return after the if/else schedules the 0x100 argument differently).
 */
extern void func_0x4008a880(int, int, int);
extern void func_0x40089820(int, int);
extern void func_0x40089968(int, int);

unsigned char FUN_a00fbf5c(unsigned char on)
{
    if (on == 1) {
        *(volatile unsigned int *)0xd0040000 |= 0x80000000;
        func_0x4008a880(0xc, 0x100, 0x9a814);
        func_0x40089820(0xc, 0x100);
        return on;
    } else {
        *(volatile unsigned int *)0xd0040000 &= ~0x80000000;
        func_0x40089968(0xc, 0x100);
        return on;
    }
}
