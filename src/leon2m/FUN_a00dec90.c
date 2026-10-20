/* leon2m FUN_a00dec90 @ 0xa00dec90-0xa00decf4 (25 words).
 * Reads t = func_0x4008c250(0xc00a0000). Returns 0 when byte 0xa802b0c4 is 0; otherwise d = word 0xa802b0c8 - p
 * (one less when word 0xa802b0c8 <= p) and returns d * 10000 + t - word 0xa802b0cc.
 * Compiler aid: __builtin_expect(word 0xa802b0c8 > p, 1) emits no instructions; it places the "one less" arm
 * out of line as in the firmware.
 */
struct B0c4 {
    unsigned char on;
    unsigned char pad[3];
    unsigned int w4;
    unsigned int w8;
};
extern struct B0c4 DAT_a802b0c4;
extern unsigned int func_0x4008c250(unsigned int);

int FUN_a00dec90(unsigned int p)
{
    unsigned int t = func_0x4008c250(0xc00a0000);
    int r = 0;

    if (DAT_a802b0c4.on) {
        unsigned int d;
        if (__builtin_expect(DAT_a802b0c4.w4 > p, 1))
            d = DAT_a802b0c4.w4 - p;
        else
            d = DAT_a802b0c4.w4 - p - 1;
        r = d * 10000 + (t - DAT_a802b0c4.w8);
    }
    return r;
}
