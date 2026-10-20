/* leon2m FUN_a010ac68 @ 0xa010ac68-0xa010ace4 (31 words).
 * Two bounded waits on bit 0 of hardware register 0xcf011ff4, timed with the 16-bit tick counter: reads the start
 * count with func_0x4008d588 (= FUN_a002d588), then loops while fewer than 0x32 ticks have passed
 * (func_0x4008d594 = FUN_a002d594, count minus start) and bit 0 is set, then while fewer than 0x64 ticks have passed
 * and bit 0 is clear. Each loop is written as a tick test with a break on the bit test; a combined `&&` condition
 * gives other registers. No direct callers were found.
 */
#define REG_cf011ff4 (*(volatile unsigned int *)0xcf011ff4)

extern unsigned short func_0x4008d588(void);
extern unsigned short func_0x4008d594(unsigned short start);

void FUN_a010ac68(void)
{
    unsigned short t = func_0x4008d588();

    while (func_0x4008d594(t) < 0x32) {
        if (!(REG_cf011ff4 & 1))
            break;
    }
    while (func_0x4008d594(t) < 0x64) {
        if (REG_cf011ff4 & 1)
            break;
    }
}
