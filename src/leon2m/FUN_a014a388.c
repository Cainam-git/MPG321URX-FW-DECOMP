/* leon2m FUN_a014a388 @ 0xa014a388-0xa014a428 (40 words), flags -mcpu=v8 -O2 -g.
 * Parameter k. For blk 0 and then blk 1: FUN_a011acac(k, blk), FUN_a011adc8(0xff, blk), then for b = 0..7
 * ROM func_0x4008e6e4(b, blk) followed by FUN_a011a848(k, blk). Callers: FUN_a00d4780, FUN_a00dc3dc.
 * Source form: two copies of the same block with blk 0 and 1; the counter is an unsigned char (do-while).
 */
extern void FUN_a011acac(unsigned char n, unsigned char blk);
extern void FUN_a011adc8(unsigned char n, unsigned char blk);
extern void FUN_a011a848(unsigned char n, unsigned char blk);
extern void func_0x4008e6e4(unsigned int v, unsigned char blk);

void FUN_a014a388(unsigned char k)
{
    unsigned char b;

    FUN_a011acac(k, 0);
    FUN_a011adc8(0xff, 0);
    b = 0;
    do {
        func_0x4008e6e4(b, 0);
        FUN_a011a848(k, 0);
        b++;
    } while (b < 8);
    FUN_a011acac(k, 1);
    FUN_a011adc8(0xff, 1);
    b = 0;
    do {
        func_0x4008e6e4(b, 1);
        FUN_a011a848(k, 1);
        b++;
    } while (b < 8);
}
