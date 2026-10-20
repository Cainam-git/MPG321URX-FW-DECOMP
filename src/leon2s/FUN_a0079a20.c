/* leon2s FUN_a0079a20 @ 0xa0079a20-0xa0079aac (140 bytes, 35 words)
 * Flags: -mcpu=v8 -Os -g.
 * void (u32 port, u8 mask). For u16 i = 0..3 with bit i of mask set (signed sra of the zero-extended mask),
 * and a redundant i < 4 bound test in its own if (the firmware keeps 'cmp 3; bgu'), it runs
 * FUN_a00a7424(0, 7, port, DAT_a00b3b18[i]) and FUN_a00a7488(port & 0xff, DAT_a00b3b10[i], 0xffffff,
 * 0x38000000). Both u16 tables are in the image. The firmware masks the port separately for each call:
 * the u8 parameter conversion (zero_extend) and the explicit '& 0xff' are different RTL, so CSE does not
 * merge them.
 * Source form: a u32 port parameter (a u8 one gives one shared 'and'); the two tests as separate ifs (a '&&'
 * gives a branch-free addx form).
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
