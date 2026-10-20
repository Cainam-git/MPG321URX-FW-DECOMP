/* leon2s DRV_HDMI21_PHY_Freq_Detection @ 0xa009a580-0xa009a698 (70 words), flags -mcpu=v8 -Os -g.
 * Code facts: u8 port; PHY page ch = 2 for port 0, 3 for port 1, else return. If bit 0x800 of
 * _DAT_a8078634: print s_a006a298 with s_a00b4390 (function-name string). FUN_a00a7488(ch, 0x2f54,
 * 0xffffff00, 0x5f); for lane i = 0..3: a7488(ch, 0x2f50, 0xff00ffff, i << 16); FUN_a00a7424(1, 0x18,
 * ch, 0x2f50); FUN_a00b160c(0x14) (delay); u16 ARR_a807905a[port * 4 + i] = (FUN_a00a7314(ch, 0x2f54) &
 * 0x1fff00) >> 8; then a SECOND a7314 read for the print s_a006a2b0 'Lane%d, freq=%ld' (i, same field).
 * Returns nothing.
 * The delay b160c runs before the read; the print re-reads a7314; the table index is port * 4 + i; the
 * first print takes the name string. Source form: strings are symbols. Aids: none.
 */
extern unsigned int _DAT_a8078634;
extern unsigned short ARR_a807905a[];
extern char s_a006a298[], s_a00b4390[], s_a006a2b0[];
extern void FUN_a00a7488(unsigned char, unsigned short, unsigned int, unsigned int);
extern void FUN_a00b160c(unsigned int);
extern unsigned int FUN_a00a7314(unsigned char, unsigned short);
extern void FUN_a00a7424(unsigned int, unsigned int, unsigned char, unsigned short);
extern int FUN_a0073044(const char *, ...);

void DRV_HDMI21_PHY_Freq_Detection(unsigned char port)
{
    unsigned char ch;
    unsigned char i;

    if (port == 0)
        ch = 2;
    else if (port == 1)
        ch = 3;
    else
        return;
    if (_DAT_a8078634 & 0x800)
        FUN_a0073044(s_a006a298, s_a00b4390);
    FUN_a00a7488(ch, 0x2f54, 0xffffff00, 0x5f);
    for (i = 0; i < 4; i++) {
        FUN_a00a7488(ch, 0x2f50, 0xff00ffff, i << 16);
        FUN_a00a7424(1, 0x18, ch, 0x2f50);
        FUN_a00b160c(0x14);
        ARR_a807905a[port * 4 + i] = (FUN_a00a7314(ch, 0x2f54) & 0x1fff00) >> 8;
        FUN_a0073044(s_a006a2b0, i, (FUN_a00a7314(ch, 0x2f54) & 0x1fff00) >> 8);
    }
}
