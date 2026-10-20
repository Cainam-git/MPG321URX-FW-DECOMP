/* 8051_bank0 FUN_CODE_111f @ 0x111f  STBC boot loader: identify the SPI flash chip (byte-exact
 * with OPTIMIZE(8,SPEED)).
 * Walks the FUN_CODE_18e8() = 57 six-byte records at CODE 0x4000 ([0] chip index, [1] manufacturer, [2] memory
 * type, [3] capacity, [4] size code, [5] flags) against the JEDEC ID in XDATA 0xF064..0xF066 (FUN_CODE_1777).
 * Full match: DATA 0x30 = index, DATA 0x32 (16-bit) = size code (values below 15 are shifted into the high byte),
 * DATA 0x14 = flags, DATA 0x2F = flags & 1 (Quad capable), stop. Manufacturer-only match: DATA 0x30 =
 * (index & 0xF0) | 0x0F. Then DATA 0x31 = 0xD7 for manufacturer 0x7F, else 0x20 (sector-erase opcode).
 * Size code 5 (32 MiB chip, e.g. GD25Q256): if the Extended Address Register (FUN_CODE_18e2, opcode 0xC8) is not
 * 0, write it to 0 (FUN_CODE_180d), set 0xF00A = 0x55 and stop here forever: the boot loader refuses to continue
 * from the upper 16 MiB and waits for a power cycle / reset. Finally copies the 4 bytes DATA 0x30..0x33 into the
 * share structure (FUN_CODE_1346 kind 5 -> XDATA 0x3066) and tail-calls the bus-mode set-up FUN_CODE_0c83(quad,
 * index), returning its read opcode. Callers: main FUN_CODE_151c and the partition loader FUN_CODE_0003 (DUALFW).
 */
extern unsigned char code DAT_CODE_4000[][6];
extern unsigned char volatile xdata DAT_EXTMEM_f064, DAT_EXTMEM_f065, DAT_EXTMEM_f066, DAT_EXTMEM_f00a;
extern unsigned char data DAT_002f, DAT_0030, DAT_0031, DAT_0014;
extern unsigned int data DAT_0032;
unsigned char FUN_CODE_18e8(void);
unsigned char FUN_CODE_18e2(void);
void FUN_CODE_180d(unsigned char ear);
void FUN_CODE_1346(unsigned char kind, unsigned char len, unsigned char *src);
unsigned char FUN_CODE_0c83(unsigned char quad, unsigned char idx);
unsigned char FUN_CODE_111f(void)
{
    unsigned char i, n, m;
    n = FUN_CODE_18e8();
    DAT_002f = 0;
    for (i = 0; i < n; i++) {
        m = DAT_CODE_4000[i][1];
        if (m == DAT_EXTMEM_f064 && DAT_CODE_4000[i][2] == DAT_EXTMEM_f065 && DAT_CODE_4000[i][3] == DAT_EXTMEM_f066) {
            DAT_0030 = DAT_CODE_4000[i][0];
            DAT_0032 = DAT_CODE_4000[i][4];
            if (DAT_0032 < 0x0f) DAT_0032 <<= 8;
            DAT_0014 = DAT_CODE_4000[i][5];
            DAT_002f = DAT_0014 & 1;
            break;
        }
        if (DAT_EXTMEM_f064 == m) DAT_0030 = (DAT_CODE_4000[i][0] & 0xf0) | 0x0f;
    }
    if (DAT_EXTMEM_f064 == 0x7f) DAT_0031 = 0xd7; else DAT_0031 = 0x20;
    if (DAT_0032 == 0x0500) {
        if (FUN_CODE_18e2() > 0) {
            FUN_CODE_180d(0);
            DAT_EXTMEM_f00a = 0x55;
            for (;;);
        }
    }
    FUN_CODE_1346(5, 4, &DAT_0030);
    return FUN_CODE_0c83(DAT_002f, DAT_0030);
}
