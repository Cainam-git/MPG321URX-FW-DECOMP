/* leon2m FUN_a00dec90 @ 0xa00dec90-0xa00decf4 (25 words).
 * Reads t = func_0x4008c250(0xc00a0000). Returns 0 when byte 0xa802b0c4 is 0; otherwise d = word 0xa802b0c8 - p
 * (one less when word 0xa802b0c8 <= p) and returns d * 10000 + t - word 0xa802b0cc.
 * Source form: the byte 0xa802b0c4 == 0 test jumps with 'goto none' over the computation to a 'return 0' at the
 * end of the function (firmware block order: the "one less" arm out of line after the return).
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
    unsigned int d;

    if (DAT_a802b0c4.on == 0)
        goto none;
    if (DAT_a802b0c4.w4 > p)
        d = DAT_a802b0c4.w4 - p;
    else
        d = DAT_a802b0c4.w4 - p - 1;
    return d * 10000 + (t - DAT_a802b0c4.w8);
none:
    return 0;
}
