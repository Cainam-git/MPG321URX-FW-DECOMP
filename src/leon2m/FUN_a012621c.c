/* leon2m FUN_a012621c @ 0xa012621c-0xa012629c (32 words).
 * Takes the tick count t = func_0x4008d588(), then repeats: reads the byte v = FUN_a0125e60(); when v differs from
 * the byte at 0xa802c9fc it stores v there, takes a new t and sets the wait w to 0x32. The loop ends when w is 0
 * (v equal to the stored byte on the first pass) or when func_0x4008d594(t) has reached w without a change of v.
 * Returns the byte at 0xa802c9fc. Callers: FUN_a008e650 and FUN_a008e7b0 (twice).
 */
extern unsigned short func_0x4008d588(void);
extern unsigned short func_0x4008d594(unsigned short start);
extern unsigned char FUN_a0125e60(void);
extern unsigned char DAT_a802c9fc;

unsigned char FUN_a012621c(void)
{
    unsigned short t = func_0x4008d588();
    unsigned char w = 0;
    unsigned char v;

    do {
        v = FUN_a0125e60();
        if (v != DAT_a802c9fc) {
            DAT_a802c9fc = v;
            t = func_0x4008d588();
            w = 0x32;
        }
    } while (w && func_0x4008d594(t) < w);
    return DAT_a802c9fc;
}
