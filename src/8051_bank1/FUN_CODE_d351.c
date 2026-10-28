/* 8051_bank1 FUN_CODE_d351 @ 0xd351..0xd385 (52 B)  OPTIMIZE(8,SPEED), small function.
 * When XDATA 0xD511 is 0x20: for i = 0..3 writes (1 << i) | (0x10 << i) to XDATA 0xF40E, each followed by a read
 * and write-back of XDATA 0x7E7A. Caller: FUN_CODE_224f (0x2531).
 */
extern unsigned char volatile xdata DAT_EXTMEM_d511, DAT_EXTMEM_f40e, DAT_EXTMEM_7e7a;

void FUN_CODE_d351(void) small
{
    unsigned char i;

    if (DAT_EXTMEM_d511 == 0x20) {
        i = 0;
        do {
            DAT_EXTMEM_f40e = (1 << i) | (0x10 << i);
            DAT_EXTMEM_7e7a = DAT_EXTMEM_7e7a;
        } while (++i != 4);
    }
}
