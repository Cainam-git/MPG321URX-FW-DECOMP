/* leon2s FUN_a00add8c @ 0xa00add8c-0xa00adf64, -mcpu=v8 -Os -g.
 * (u8 port, u8 mode), void. ch = FUN_a00add48(port, func_0x9f1c6624(port)) and k = port * 4 +
 * func_0x9f1c6624(port) (u8; ROM call outside the image). As FUN_a00adf84 but with the registers 0xcf014758
 * (ch <= 3) / 0xcf01475c (ch > 3, field index ch - 4): the 2-bit field at bit 2*ch becomes 3 for mode 1,
 * mode (2) for mode 2, 1 for mode 4 and 0 otherwise; bit k of the byte mask DAT_a807de70 is set to 1 (as
 * mode << k) for mode 1 and cleared for every other mode.
 */
extern unsigned int func_0x9f1c6624(unsigned char);
extern unsigned char FUN_a00add48(unsigned char, unsigned char);
extern unsigned char DAT_a807de70;

#define REG_CF014758 (*(volatile unsigned int *)0xcf014758)
#define REG_CF01475C (*(volatile unsigned int *)0xcf01475c)

void FUN_a00add8c(unsigned char port, unsigned char mode)
{
    unsigned char ch, k;

    ch = FUN_a00add48(port, func_0x9f1c6624(port));
    k = port * 4 + func_0x9f1c6624(port);
    if (ch <= 3) {
        if (mode == 1) {
            REG_CF014758 |= 3 << (ch * 2);
            DAT_a807de70 |= mode << k;
        }
        else if (mode == 2) {
            REG_CF014758 = (REG_CF014758 & ~(3 << (ch * 2))) | (mode << (ch * 2));
            DAT_a807de70 &= ~(1 << k);
        }
        else if (mode == 4) {
            REG_CF014758 = (REG_CF014758 & ~(3 << (ch * 2))) | (1 << (ch * 2));
            DAT_a807de70 &= ~(1 << k);
        }
        else {
            REG_CF014758 &= ~(3 << (ch * 2));
            DAT_a807de70 &= ~(1 << k);
        }
    } else {
        ch -= 4;
        if (mode == 1) {
            REG_CF01475C |= 3 << (ch * 2);
            DAT_a807de70 |= mode << k;
        }
        else if (mode == 2) {
            REG_CF01475C = (REG_CF01475C & ~(3 << (ch * 2))) | (mode << (ch * 2));
            DAT_a807de70 &= ~(1 << k);
        }
        else if (mode == 4) {
            REG_CF01475C = (REG_CF01475C & ~(3 << (ch * 2))) | (1 << (ch * 2));
            DAT_a807de70 &= ~(1 << k);
        }
        else {
            REG_CF01475C &= ~(3 << (ch * 2));
            DAT_a807de70 &= ~(1 << k);
        }
    }
}
