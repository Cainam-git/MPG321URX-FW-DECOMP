/* FUN_a008a868 (leon2s 0xa008a868-0xa008a924, 188 bytes), flags -mcpu=v8 -Os -g.
 * Tests byte 2 of DAT_a8076688: bit 0 set calls FUN_a008a824(on); bit 1 set sets (on non-zero) or clears
 * (on zero) bit 7 of hardware registers 0xcf01120c and 0xcf011218. The flag byte is read again for each
 * test. Source form: DAT_a8076688 is a byte array indexed directly; each arm of the on test has its own
 * pair of flag tests, and the zero arm passes the constant 0.
 */
#define REG_120C (*(volatile unsigned int *)0xcf01120c)
#define REG_1218 (*(volatile unsigned int *)0xcf011218)

extern unsigned char DAT_a8076688[];
extern void FUN_a008a824(unsigned char param_1);

void FUN_a008a868(unsigned char on)
{
    
    if (on) {
        if (DAT_a8076688[2] & 1)
            FUN_a008a824(on);
        if (DAT_a8076688[2] & 2) {
            REG_120C |= 0x80;
            REG_1218 |= 0x80;
        }
    } else {
        if (DAT_a8076688[2] & 1)
            FUN_a008a824(0);
        if (DAT_a8076688[2] & 2) {
            REG_120C &= ~0x80;
            REG_1218 &= ~0x80;
        }
    }
}
