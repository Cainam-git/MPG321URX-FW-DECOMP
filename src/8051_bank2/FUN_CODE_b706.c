/* 8051_bank2 FUN_CODE_b706 @ 0xb706 (325 B), OPTIMIZE(8,SPEED) LARGE; local i at XDATA 0x08FA, k register-only.
 * Callers: FUN_CODE_6e16, FUN_CODE_9734, FUN_CODE_b5b4, FUN_CODE_ba96.
 * Walks the CODE table 0xC9D2 (16 records of 7 bytes: unsigned int reg, unsigned long val, unsigned char wait; the
 * last record has reg 0xFFFF) for at most 255 records, stopping at reg 0xFFFF. By the top nibble of reg:
 * 0x0 -> FUN_CODE_b317(reg, val), 0x1 -> FUN_CODE_dfbe(reg, val), 0x2 -> FUN_CODE_ddbb(reg, val), other values no
 * call; then FUN_CODE_e44b(wait) for every record. Afterwards XDATA 0x08CD..0x08CF = 0, 4, 6, byte 0x08BC and
 * 0x0829 = 0x22, FUN_CODE_da02(), XDATA 0x07D1 / 0x07D2 = 3.
 * Source forms the bytes depend on: the table declared with its size [16] (8-bit record offset: MUL AB, CLR A /
 * ADDC); every test reads the record again (an if / else-if chain, no switch); 0x22 through the char local k
 * (MOV R7,#22H / MOV A,R7; it also keeps the first record test free of a MOV R7,A copy). No aids.
 */
struct regwr { unsigned int reg; unsigned long val; unsigned char wait; };
struct addrs { unsigned char k; unsigned long a; unsigned long b; unsigned long c; };
extern struct regwr code DAT_CODE_c9d2[16];
extern unsigned char xdata DAT_EXTMEM_08cd[3];
extern struct addrs xdata DAT_EXTMEM_08bc;
extern unsigned char xdata DAT_EXTMEM_0829;
extern unsigned char xdata DAT_EXTMEM_07d1[2];
void FUN_CODE_b317(unsigned int reg, unsigned long v);
void FUN_CODE_dfbe(unsigned int reg, unsigned long mask);
void FUN_CODE_ddbb(unsigned int reg, unsigned long mask);
void FUN_CODE_e44b(unsigned char n);
void FUN_CODE_da02(void);
void FUN_CODE_b706(void)
{
    unsigned char i;
    unsigned char k;
    for (i = 0; i < 0xff; i++) {
        if (DAT_CODE_c9d2[i].reg == 0xffff) break;
        if ((DAT_CODE_c9d2[i].reg & 0xf000) == 0) {
            FUN_CODE_b317(DAT_CODE_c9d2[i].reg, DAT_CODE_c9d2[i].val);
        } else if ((DAT_CODE_c9d2[i].reg & 0xf000) == 0x1000) {
            FUN_CODE_dfbe(DAT_CODE_c9d2[i].reg, DAT_CODE_c9d2[i].val);
        } else if ((DAT_CODE_c9d2[i].reg & 0xf000) == 0x2000) {
            FUN_CODE_ddbb(DAT_CODE_c9d2[i].reg, DAT_CODE_c9d2[i].val);
        }
        FUN_CODE_e44b(DAT_CODE_c9d2[i].wait);
    }
    DAT_EXTMEM_08cd[0] = 0;
    DAT_EXTMEM_08cd[1] = 4;
    DAT_EXTMEM_08cd[2] = 6;
    k = 0x22;
    DAT_EXTMEM_08bc.k = k;
    DAT_EXTMEM_0829 = k;
    FUN_CODE_da02();
    DAT_EXTMEM_07d1[0] = 3;
    DAT_EXTMEM_07d1[1] = 3;
}
