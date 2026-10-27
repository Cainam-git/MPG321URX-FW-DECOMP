/* leon2s FUN_a007a648 @ 0xa007a648-0xa007a6f0 (168 bytes), flags -mcpu=v8 -Os -g.
 * void (u32 port, u8 mask). For u16 i = 0..3 with bit i of mask set (signed sra of the zero-extended mask),
 * and i < 4, it runs FUN_a00a7488(port & 0xff, DAT_a00b3b10[i], 0xffffff, 0x38000000),
 * FUN_a00a7488(port & 0xff, DAT_a00b3b20[i], 0xffffff00, 0x16) and FUN_a00a7424(1, 7, port, DAT_a00b3b18[i]).
 * The u16 tables are in the image. The firmware masks the port separately for each call. Same layout as
 * FUN_a0079a20.
 * Source form: each call has its own 'if (i < 4)' guard (the firmware keeps one 'cmp 3; bgu' for all three;
 * the separate guards stop CSE from sharing one masked port between the calls).
 */
extern unsigned short DAT_a00b3b10[];
extern unsigned short DAT_a00b3b18[];
extern unsigned short DAT_a00b3b20[];
extern void FUN_a00a7424(int, unsigned int, unsigned char, unsigned short);
extern void FUN_a00a7488(unsigned int, unsigned short, unsigned int, unsigned int);

void FUN_a007a648(unsigned int port, unsigned char mask)
{
    unsigned short i;

    for (i = 0; i < 4; i++) {
        if ((mask >> i) & 1) {
            if (i < 4)
                FUN_a00a7488(port & 0xff, DAT_a00b3b10[i], 0xffffff, 0x38000000);
            if (i < 4)
                FUN_a00a7488(port & 0xff, DAT_a00b3b20[i], 0xffffff00, 0x16);
            if (i < 4)
                FUN_a00a7424(1, 7, port, DAT_a00b3b18[i]);
        }
    }
}
