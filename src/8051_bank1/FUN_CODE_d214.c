/* 8051_bank1 FUN_CODE_d214 @ 0xd214 (54 B)  Byte-exact with OPTIMIZE(8,SPEED).
 * Runs in register bank 3 ('using 3': PUSH PSW, PSW = 0x18) like its callees. Steps the state byte at XDATA 0xA6EE:
 * 1 -> FUN_CODE_cc7d(), then 2; 0 and 2 -> incremented; 3 -> set to 4, then FUN_CODE_d24a() and FUN_CODE_d8a6();
 * 4 and above -> no change. Only caller FUN_CODE_c1c1 (0xC217, on its path where XDATA 0xD511 is not 0x20).
 * The second read of 0xA6EE is kept in R7 for the '== 3' test; 'state == 1' and 'state++' share the increment tail.
 */
extern unsigned char xdata DAT_EXTMEM_a6ee;
void FUN_CODE_cc7d(void);
void FUN_CODE_d24a(void);
void FUN_CODE_d8a6(void);

void FUN_CODE_d214(void) using 3
{
    if (DAT_EXTMEM_a6ee == 1) {
        FUN_CODE_cc7d();
        DAT_EXTMEM_a6ee++;
    } else if (DAT_EXTMEM_a6ee < 3) {
        DAT_EXTMEM_a6ee++;
    } else if (DAT_EXTMEM_a6ee == 3) {
        DAT_EXTMEM_a6ee = 4;
        FUN_CODE_d24a();
        FUN_CODE_d8a6();
    }
}
