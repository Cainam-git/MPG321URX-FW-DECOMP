/* FUN_a00d430c (leon2m 0xa00d430c-0xa00d43b4, 168 bytes), flags -mcpu=v8 -O3 -g.
 * With id = FUN_a0144414() and level clamped to 100, writes v * (hi - lo) / 100 + FUN_a0145660(id, 0xe) to
 * parameter 0xb of id through FUN_a0145808(id, 0xb, value, 1) (tail call), where v = 100 - level, hi =
 * FUN_a0145660(id, 0xd) and lo = FUN_a0145660(id, 0xe) (halfwords, signed division). Called by FUN_a0088724. Source
 * form: the form of FUN_a00d41b4 with v = 100 - level in an unsigned char local. Compiler aid: the empty statement
 * "if (v) {}" emits no instructions; it changes where 100 - level is computed and masked (the firmware computes it
 * in the first call delay slot and masks it after the second call).
 */
extern unsigned char FUN_a0144414(void);
extern int FUN_a0145660(unsigned char, unsigned int);
extern void FUN_a0145808(unsigned char, unsigned int, unsigned short, int);
void FUN_a00d430c(unsigned char level)
{
    unsigned char id = FUN_a0144414();
    int hi, lo;
    unsigned char v;

    if (level > 100)
        level = 100;
    v = 100 - level;
    if (v) {
    }
    hi = (unsigned short)FUN_a0145660(id, 0xd);
    lo = (unsigned short)FUN_a0145660(id, 0xe);
    FUN_a0145808(id, 0xb, v * (hi - lo) / 100 + FUN_a0145660(id, 0xe), 1);
}
