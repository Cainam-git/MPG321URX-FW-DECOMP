/* leon2s FUN_a0079a20 @ 0xa0079a20-0xa0079aac (140 bytes, 35 words)
 * Flags: -mcpu=v8 -Os -g.
 * Code facts: void (u32 port, u8 mask). For u16 i = 0..3 with bit i of mask set (signed sra of the
 * zero-extended mask), and a redundant i < 4 bound test in its own if (the fw keeps 'cmp 3; bgu'), it runs
 * FUN_a00a7424(0, 7, port, DAT_a00b3b18[i]) and FUN_a00a7488(port & 0xff, DAT_a00b3b10[i], 0xffffff,
 * 0x38000000). Both u16 tables are in the image. The fw masks the port separately for each call: the
 * u8 parameter conversion (zero_extend) and the explicit '& 0xff' are different RTL, so CSE does not merge them.
 * A u8 port param gives one shared and (63.89). A '&&' of the two tests gives a branch-free addx form
 * (57.14). The draft's behaviour was right; it was not void. No aids.
 */
extern unsigned short DAT_a00b3b10[];
extern unsigned short DAT_a00b3b18[];
extern void FUN_a00a7424(int, unsigned int, unsigned char, unsigned short);
extern void FUN_a00a7488(unsigned int, unsigned short, unsigned int, unsigned int);

void FUN_a0079a20(unsigned int port, unsigned char mask)
{
    unsigned short i;

    for (i = 0; i < 4; i++) {
        if ((mask >> i) & 1) {
            if (i < 4) {
                FUN_a00a7424(0, 7, port, DAT_a00b3b18[i]);
                FUN_a00a7488(port & 0xff, DAT_a00b3b10[i], 0xffffff, 0x38000000);
            }
        }
    }
}
