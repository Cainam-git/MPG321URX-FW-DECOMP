/* 8051_bank1 FUN_CODE_9bde @ 0x9bde .. 0x9ca9
 * Mode n = 0..12 -> register block 0x9A00 writes (FUN_CODE_d9d1(reg, val) = 0x9A00[reg] = val, FUN_CODE_d645(reg, mask,
 * on) = 0x9A00[reg] |= / &= mask): reg 4 = mode byte, reg 3, reg 0x54; n 7..10 also set/clear bit 0 of 0x9A03 and of
 * XDATA 0xDCF0; n = 0 also clears XDATA 0x6043. Other n: nothing.
 * Keil switch: CJNE A,#0DH / JC, 3-byte LJMP table at 0x9bee; the identical case tails are cross-jumped.
 * REGFILE(R.ORC) is needed (Keil then knows d9d1 keeps R5/R7: 'DEC R7' for reg 3 after reg 4; without it 235 B).
 * functions.json size 17 is the code before the table; the judged span is 0x9bde..0x9caa (204 B).
 * Only caller 0xb87d (FUN_CODE_b802).
 * Options: OPTIMIZE(8,SPEED) REGFILE(R.ORC).
 */
extern unsigned char xdata DAT_EXTMEM_6043;
extern unsigned char xdata DAT_EXTMEM_dcf0;
void FUN_CODE_d9d1(unsigned char reg, unsigned char val);
void FUN_CODE_d645(unsigned char reg, unsigned char mask, unsigned char on);
void FUN_CODE_9bde(unsigned char n)
{
    switch (n) {
    case 0:
        FUN_CODE_d9d1(4, 0x80);
        FUN_CODE_d9d1(3, 0x80);
        FUN_CODE_d9d1(0x54, 0x20);
        DAT_EXTMEM_6043 = 0;
        break;
    case 1: FUN_CODE_d9d1(4, 0x82); FUN_CODE_d9d1(3, 0x08); FUN_CODE_d9d1(0x54, 0x90); break;
    case 2: FUN_CODE_d9d1(4, 0x86); FUN_CODE_d9d1(3, 0x08); FUN_CODE_d9d1(0x54, 0x90); break;
    case 3: FUN_CODE_d9d1(4, 0x86); FUN_CODE_d9d1(3, 0x08); FUN_CODE_d9d1(0x54, 0x90); break;
    case 4: FUN_CODE_d9d1(4, 0x86); FUN_CODE_d9d1(3, 0x08); FUN_CODE_d9d1(0x54, 0x90); break;
    case 5: FUN_CODE_d9d1(4, 0x8a); FUN_CODE_d9d1(3, 0x08); FUN_CODE_d9d1(0x54, 0x90); break;
    case 6: FUN_CODE_d9d1(4, 0x8e); FUN_CODE_d9d1(3, 0x08); FUN_CODE_d9d1(0x54, 0x90); break;
    case 7:
        FUN_CODE_d9d1(4, 0x83); FUN_CODE_d645(3, 1, 0); DAT_EXTMEM_dcf0 &= 0xfe;
        FUN_CODE_d9d1(3, 0x08); FUN_CODE_d9d1(0x54, 0x90); break;
    case 8:
        FUN_CODE_d9d1(4, 0x83); FUN_CODE_d645(3, 1, 1); DAT_EXTMEM_dcf0 |= 0x01;
        FUN_CODE_d9d1(3, 0x08); FUN_CODE_d9d1(0x54, 0x90); break;
    case 9:
        FUN_CODE_d9d1(4, 0x83); FUN_CODE_d645(3, 1, 0); DAT_EXTMEM_dcf0 |= 0x01;
        FUN_CODE_d9d1(3, 0x08); FUN_CODE_d9d1(0x54, 0x90); break;
    case 10:
        FUN_CODE_d9d1(4, 0x83); FUN_CODE_d645(3, 1, 1); DAT_EXTMEM_dcf0 &= 0xfe;
        FUN_CODE_d9d1(3, 0x08); FUN_CODE_d9d1(0x54, 0x90); break;
    case 11: FUN_CODE_d9d1(4, 0x82); FUN_CODE_d9d1(3, 0x28); FUN_CODE_d9d1(0x54, 0x90); break;
    case 12: FUN_CODE_d9d1(4, 0x82); FUN_CODE_d9d1(3, 0x28); FUN_CODE_d9d1(0x54, 0x90); break;
    }
}
