/* FUN_CODE_b317, 8051_bank2 (helper chip updater), range 0xB317..0xB45F (328 B).
 * Options: OPTIMIZE(8,SPEED) LARGE. Judge: tools/diff8051.judge (scratch copy) MATCH, exact None, 328/328.
 * Code facts: the 32-bit controller register write, partner of the read FUN_CODE_9b91 (prototype as used by the
 * accepted callers in src/8051_bank2: void b317(unsigned int reg, unsigned long v)). LARGE parameters reg (0x0990)
 * and v (memory parameter 0x0992..0x0995, = ?_FUN_CODE_b317?BYTE+2), local n at 0x0996. reg is cut to 9 bits.
 * XDATA 0x075B selects the register window: 1 -> 0xCD20..0xCD25, else 0xCD00..0xCD05. Window +1 = reg low byte,
 * +2..+5 = v little-endian (?C?ULSHR for >> 8 / 16 / 24), then +0 = 0x80 + (bit 8 of reg at bit 4), the start
 * command. Then up to 10 polls: n--, e44b(1) delay, stop when n reaches 0 or bit 0 of window +0 is set (done).
 * Same bytes with or without volatile on 0xCD00 / 0xCD20 (Keil re-reads XDATA in the loop anyway), so none is used.
 * Callers (byte scan): 5c20 x11, 60b9 x32, 7a46 x10, b97a x3, 69da, b706, ddbb, dfbe, e004, and 0x4CDA, 0x5757,
 * 0x5782, 0x5826 (outside the functions.json ranges). No aids.
 */
extern unsigned char xdata DAT_EXTMEM_075b;
extern unsigned char xdata DAT_EXTMEM_cd00;
extern unsigned char xdata DAT_EXTMEM_cd01;
extern unsigned char xdata DAT_EXTMEM_cd02;
extern unsigned char xdata DAT_EXTMEM_cd03;
extern unsigned char xdata DAT_EXTMEM_cd04;
extern unsigned char xdata DAT_EXTMEM_cd05;
extern unsigned char xdata DAT_EXTMEM_cd20;
extern unsigned char xdata DAT_EXTMEM_cd21;
extern unsigned char xdata DAT_EXTMEM_cd22;
extern unsigned char xdata DAT_EXTMEM_cd23;
extern unsigned char xdata DAT_EXTMEM_cd24;
extern unsigned char xdata DAT_EXTMEM_cd25;
void FUN_CODE_e44b(unsigned char n);
void FUN_CODE_b317(unsigned int reg, unsigned long v)
{
    unsigned char n;
    reg &= 0x01ff;
    if (DAT_EXTMEM_075b == 1) {
        DAT_EXTMEM_cd21 = reg;
        DAT_EXTMEM_cd22 = v;
        DAT_EXTMEM_cd23 = v >> 8;
        DAT_EXTMEM_cd24 = v >> 16;
        DAT_EXTMEM_cd25 = v >> 24;
        DAT_EXTMEM_cd20 = ((reg >> 4) & 0x10) + 0x80;
        n = 10;
        do {
            n--;
            FUN_CODE_e44b(1);
        } while (n > 0 && !(DAT_EXTMEM_cd20 & 1));
    } else {
        DAT_EXTMEM_cd01 = reg;
        DAT_EXTMEM_cd02 = v;
        DAT_EXTMEM_cd03 = v >> 8;
        DAT_EXTMEM_cd04 = v >> 16;
        DAT_EXTMEM_cd05 = v >> 24;
        DAT_EXTMEM_cd00 = ((reg >> 4) & 0x10) + 0x80;
        n = 10;
        do {
            n--;
            FUN_CODE_e44b(1);
        } while (n > 0 && !(DAT_EXTMEM_cd00 & 1));
    }
}
