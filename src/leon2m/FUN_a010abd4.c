/* leon2m FUN_a010abd4 @ 0xa010abd4-0xa010ac68 (37 words).
 * Two loops on bit n + 4 of hardware register 0xcf011ff4, bounded by the 16-bit counter: reads the start value
 * with func_0x4008d588 (= FUN_a002d588, halfword 0xa802b0ca), then loops while func_0x4008d594(start)
 * (= FUN_a002d594, counter minus start) is below 0x32 and the bit is set, then while it is below 0x64 and the bit
 * is clear. Same form as FUN_a010ac68 (bit 0). No direct callers were found.
 */
#define REG_cf011ff4 (*(volatile unsigned int *)0xcf011ff4)

extern unsigned short func_0x4008d588(void);
extern unsigned short func_0x4008d594(unsigned short start);

void FUN_a010abd4(unsigned char n)
{
    unsigned short t = func_0x4008d588();

    while (func_0x4008d594(t) < 0x32) {
        if (!((REG_cf011ff4 >> (n + 4)) & 1))
            break;
    }
    while (func_0x4008d594(t) < 0x64) {
        if ((REG_cf011ff4 >> (n + 4)) & 1)
            break;
    }
}
