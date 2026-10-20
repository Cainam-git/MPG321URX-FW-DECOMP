/* 8051_bank0 FUN_CODE_1777 @ 0x1777  STBC boot loader: read the flash JEDEC ID (byte-exact with
 * OPTIMIZE(7,SPEED)).
 * Sends SPI command 0x9F (Read JEDEC ID) through the generic transfer FUN_CODE_124f(n_out 1, out, n_in 4, in) and
 * copies the first three answer bytes (manufacturer, memory type, capacity) to XDATA 0xF064..0xF066, where the flash
 * identification FUN_CODE_111f matches them against the 57-record table at CODE 0x4000. The command byte and the
 * answer buffer are this function's overlaid DATA locals at 0x22 and 0x23 (named by address so the link is checked).
 */
extern unsigned char data DAT_0022;
extern unsigned char data DAT_0023[4];
unsigned char volatile xdata DAT_f064[3] _at_ 0xf064;
void FUN_CODE_124f(int n_out, unsigned char *out, int n_in, unsigned char *in);
void FUN_CODE_1777(void)
{
    unsigned char i;
    DAT_0022 = 0x9f;
    FUN_CODE_124f(1, &DAT_0022, 4, DAT_0023);
    for (i = 0; i < 3; i++) {
        DAT_f064[i] = DAT_0023[i];
    }
}
