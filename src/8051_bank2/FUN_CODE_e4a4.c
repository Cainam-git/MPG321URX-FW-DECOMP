/* 8051_bank2 FUN_CODE_e4a4 @ 0xe4a4  OPTIMIZE(7,SPEED)
 * Calls FUN_CODE_e331(0) and FUN_CODE_df7f(0x0E, 0x0E), then tail-jumps (LJMP) to LAB_CODE_e4bf with a generic
 * pointer to XDATA 0x0436.
 */
extern void FUN_CODE_e331(unsigned char);
extern void FUN_CODE_df7f(unsigned char, unsigned char);
extern void LAB_CODE_e4bf(char *);

void FUN_CODE_e4a4(void) {
    FUN_CODE_e331(0);
    FUN_CODE_df7f(0x0e, 0x0e);
    LAB_CODE_e4bf((char *)((char xdata *)0x0436));
}
