/* FUN_CODE_9b91, 8051_bank2 (update agent), range 0x9B91..0x9D97 (518 B).
 * Options: OPTIMIZE(8,SPEED) LARGE.
 * Code facts: the 32-bit controller register read, partner of FUN_CODE_b317 (write). LARGE parameter reg (0x0990),
 * locals n (0x0992) and v (ulong, 0x0993..0x0996). reg is cut to 9 bits; XDATA 0x075B selects the register window
 * (1 -> 0xCD20.., else 0xCD00..). Window +1 = reg low byte, +0 = 0x40 + (bit 8 of reg at bit 4), the read command;
 * then up to 10 polls (n--, e44b(1)) until bit 0 of window +0 is set. Returns window +9..+6 as a big-endian build
 * v = (v << 8) + byte, i.e. +6 is the low byte. The last step and the return are shared by both arms (Keil
 * cross-jumps the then-arm into the else-arm tail at 0x9D4D).
 * Shape lever: '(unsigned long)' on the byte: Keil then loads the byte first and PUSHes it across the ?C?LSHL call,
 * as the firmware does; without the cast it shifts first (v/9b91_1.c and v/9b91_2.c, 38.8 %).
 * 0x9B8D (MOV R7,#14H / MOV R6,#0, 4 B) in front of this function is a Keil common-entry block = 9b91(0x0014), used
 * by d2fb (0xD375), 69da (x4) and 0x4CE2; it needs those callers in this function's module, so it is not part of this file.
 * Callers (byte scan): 5c20 x13, 60b9 x9, 7a46 x6, 8f95 x2, 69da, b97a, ddbb, dfbe, e004, e3f9, and 9 sites outside
 * the functions.json ranges. No aids.
 */
extern unsigned char xdata DAT_EXTMEM_075b;
extern unsigned char xdata DAT_EXTMEM_cd00;
extern unsigned char xdata DAT_EXTMEM_cd01;
extern unsigned char xdata DAT_EXTMEM_cd06;
extern unsigned char xdata DAT_EXTMEM_cd07;
extern unsigned char xdata DAT_EXTMEM_cd08;
extern unsigned char xdata DAT_EXTMEM_cd09;
extern unsigned char xdata DAT_EXTMEM_cd20;
extern unsigned char xdata DAT_EXTMEM_cd21;
extern unsigned char xdata DAT_EXTMEM_cd26;
extern unsigned char xdata DAT_EXTMEM_cd27;
extern unsigned char xdata DAT_EXTMEM_cd28;
extern unsigned char xdata DAT_EXTMEM_cd29;
void FUN_CODE_e44b(unsigned char n);
unsigned long FUN_CODE_9b91(unsigned int reg)
{
    unsigned char n;
    unsigned long v;
    reg &= 0x01ff;
    if (DAT_EXTMEM_075b == 1) {
        DAT_EXTMEM_cd21 = reg;
        DAT_EXTMEM_cd20 = ((reg >> 4) & 0x10) + 0x40;
        n = 10;
        do {
            n--;
            FUN_CODE_e44b(1);
        } while (n > 0 && !(DAT_EXTMEM_cd20 & 1));
        v = DAT_EXTMEM_cd29;
        v = (v << 8) + (unsigned long)DAT_EXTMEM_cd28;
        v = (v << 8) + (unsigned long)DAT_EXTMEM_cd27;
        v = (v << 8) + (unsigned long)DAT_EXTMEM_cd26;
    } else {
        DAT_EXTMEM_cd01 = reg;
        DAT_EXTMEM_cd00 = ((reg >> 4) & 0x10) + 0x40;
        n = 10;
        do {
            n--;
            FUN_CODE_e44b(1);
        } while (n > 0 && !(DAT_EXTMEM_cd00 & 1));
        v = DAT_EXTMEM_cd09;
        v = (v << 8) + (unsigned long)DAT_EXTMEM_cd08;
        v = (v << 8) + (unsigned long)DAT_EXTMEM_cd07;
        v = (v << 8) + (unsigned long)DAT_EXTMEM_cd06;
    }
    return v;
}
