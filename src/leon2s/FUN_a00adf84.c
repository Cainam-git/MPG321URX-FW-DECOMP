/* leon2s FUN_a00adf84 @ 0xa00adf84-0xa00ae0dc, -mcpu=v8 -Os -g.
 * (u8 port, u8 mode), void. ch = FUN_a00add48(port, func_0x9f1c6624(port)) (ROM call outside the image).
 * The 2-bit field at bit 2*ch of 0xcf014798 (ch <= 3) or bit 2*(ch - 4) of 0xcf01479c (ch > 3) is set to
 * 3 for mode 1, 2 for mode 2 (written as mode << shift), 1 for mode 4, and 0 for any other mode.
 * Source form: the four-arm if chain is written out for each register; GCC shares the tails.
 */
extern unsigned int func_0x9f1c6624(unsigned char);
extern unsigned char FUN_a00add48(unsigned char, unsigned char);

#define REG_CF014798 (*(volatile unsigned int *)0xcf014798)
#define REG_CF01479C (*(volatile unsigned int *)0xcf01479c)

void FUN_a00adf84(unsigned char port, unsigned char mode)
{
    unsigned char ch;

    ch = FUN_a00add48(port, func_0x9f1c6624(port));
    if (ch <= 3) {
        if (mode == 1)
            REG_CF014798 |= 3 << (ch * 2);
        else if (mode == 2)
            REG_CF014798 = (REG_CF014798 & ~(3 << (ch * 2))) | (mode << (ch * 2));
        else if (mode == 4)
            REG_CF014798 = (REG_CF014798 & ~(3 << (ch * 2))) | (1 << (ch * 2));
        else
            REG_CF014798 &= ~(3 << (ch * 2));
    } else {
        ch -= 4;
        if (mode == 1)
            REG_CF01479C |= 3 << (ch * 2);
        else if (mode == 2)
            REG_CF01479C = (REG_CF01479C & ~(3 << (ch * 2))) | (mode << (ch * 2));
        else if (mode == 4)
            REG_CF01479C = (REG_CF01479C & ~(3 << (ch * 2))) | (1 << (ch * 2));
        else
            REG_CF01479C &= ~(3 << (ch * 2));
    }
}
