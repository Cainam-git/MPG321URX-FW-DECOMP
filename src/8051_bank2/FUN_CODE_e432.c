/* 8051_bank2 FUN_CODE_e432 @ 0xe432
 * s = FUN_CODE_4ffa() (XDATA 0x075B) stored in this function's own LARGE local (XDATA 0x08EB, never read again: the
 * firmware has the store), then tail LJMP FUN_CODE_9734(XDATA 0x0401 as unsigned long). Only caller 0x71e8.
 * Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 */
extern unsigned long xdata DAT_EXTMEM_0401;
unsigned char FUN_CODE_4ffa(void);
void FUN_CODE_9734(unsigned long a);
void FUN_CODE_e432(void)
{
    unsigned char s;
    s = FUN_CODE_4ffa();
    FUN_CODE_9734(DAT_EXTMEM_0401);
}
