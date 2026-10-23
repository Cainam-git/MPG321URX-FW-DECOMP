/* 8051_bank0 FUN_CODE_17e2 @ 0x17e2  STBC boot loader: index of a marker byte in IDATA (byte-exact
 * with OPTIMIZE(8,SPEED) REGFILE(R.ORC)).
 * XDATA 0xD511 == 0x20 (FUN_CODE_18bb): first i in 0..5 with IDATA[0x0E + i] == 0x30; otherwise first i with
 * IDATA[0x08 + i] == 0x60; not found -> 0. Its only caller, main FUN_CODE_151c, stores the result + 1 in XDATA
 * 0xD929. The Keil start-up FUN_CODE_13f7 clears IDATA 0x01..0x7F, so this reads zeros unless that clear is
 * skipped.
 */
unsigned char idata DAT_08[6] _at_ 0x08;
unsigned char idata DAT_0e[6] _at_ 0x0e;
bit FUN_CODE_18bb(void);
unsigned char FUN_CODE_17e2(void)
{
    unsigned char i;
    i = 0;
    if (FUN_CODE_18bb()) {
        do { if (DAT_0e[i] == 0x30) break; i++; } while (i != 6);
    } else {
        for (i = 0; i != 6; i++) if (DAT_08[i] == 0x60) break;
    }
    if (i == 6) i = 0;
    return i;
}
