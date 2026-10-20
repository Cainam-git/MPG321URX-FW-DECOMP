/* leon2m FUN_a00f381c @ 0xa00f381c  MATCH (-mcpu=v8 -O3 -g)
 * Waits on a 24-bit hardware value: takes the start tick t0 = func_0x4008d588(), then repeatedly reads
 * v = FUN_a00f30a8(0xCF012848) (three byte registers), scales it by 4 when the register 0xCF012844 reads 0xA or by
 * 2 when it reads 0xB, and computes d = v - DAT_a802b794. It returns when d lies within -8191..8191 and more than
 * 30 ticks have passed (func_0x4008d594(t0)), or when more than 299 ticks have passed.
 * No direct callers found. Source form: the range test as nested ifs (a combined && folds into one range compare).
 */
#define R(a) (*(volatile unsigned int *)(a))

extern unsigned short func_0x4008d588(void);
extern unsigned short func_0x4008d594(unsigned short start);
extern unsigned int FUN_a00f30a8(volatile unsigned int *r);
extern int DAT_a802b794;

void FUN_a00f381c(void)
{
    unsigned short t0 = func_0x4008d588();
    int v, d;

    for (;;) {
        v = FUN_a00f30a8((volatile unsigned int *)0xcf012848);
        if (R(0xcf012844) == 0xa)
            v <<= 2;
        else if (R(0xcf012844) == 0xb)
            v <<= 1;
        d = v - DAT_a802b794;
        if (d >= -8191)
            if (d <= 8191)
                if (func_0x4008d594(t0) > 30)
                    break;
        if (func_0x4008d594(t0) > 299)
            break;
    }
}
