/* 8051_bank2 FUN_CODE_dd1a @ 0xdd1a  update agent: range setup by XDATA 0x0644, called from FUN_CODE_c1a6 at 0xc1c6 (from a mechanical
 * draft; byte-exact with OPTIMIZE(8,SPEED) LARGE; level 7 gives 93 B).
 * XDATA 0x0644 (the byte FUN_CODE_ceee compares with 0x80):
 * 0x10 -> FUN_CODE_e331(8 if param else 0); then FUN_CODE_df7f(lo, hi) = (0x20,0x3f) / (0x40,0x7f) / (0x80,0xff) /
 * (0x00,0xff) for 0x02 / 0x04 / 0x08 / 0x10; ends with the reply read FUN_CODE_e4bf(buf) on the shared buffer
 * XDATA 0x0436 (tail LJMP, generic pointer 01:0436 like FUN_CODE_e24d / e3ab / e2da).
 */
extern unsigned char xdata DAT_EXTMEM_0436[];
extern unsigned char xdata DAT_EXTMEM_0644;
void FUN_CODE_e331(unsigned char a);
void FUN_CODE_df7f(unsigned char lo, unsigned char hi);
void FUN_CODE_e4bf(unsigned char *buf);

void FUN_CODE_dd1a(unsigned char param_1)
{
    if (DAT_EXTMEM_0644 == 0x10) {
        if (param_1 == 0) {
            FUN_CODE_e331(0);
        } else {
            FUN_CODE_e331(8);
        }
    }
    if (DAT_EXTMEM_0644 == 0x02) {
        FUN_CODE_df7f(0x20, 0x3f);
    } else if (DAT_EXTMEM_0644 == 0x04) {
        FUN_CODE_df7f(0x40, 0x7f);
    } else if (DAT_EXTMEM_0644 == 0x08) {
        FUN_CODE_df7f(0x80, 0xff);
    } else if (DAT_EXTMEM_0644 == 0x10) {
        FUN_CODE_df7f(0, 0xff);
    }
    FUN_CODE_e4bf(DAT_EXTMEM_0436);
}
