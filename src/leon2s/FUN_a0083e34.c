/* FUN_a0083e34 (leon2s 0xa0083e34-0xa0083ec4, 144 bytes), flags -mcpu=v8 -Os -g.
 * on non-zero: sets bit 0 of hardware registers 0xcf0133c0 and 0xcf034400, sets the byte DAT_a80789ec to 1 and,
 * when FUN_a008d800() returns more than 0x81, writes 0x65 to 0xcf014778. on zero: clears those two bits, the
 * byte and register 0xcf014778.
 */
#define REG_33C0 (*(volatile unsigned int *)0xcf0133c0)
#define REG_4400 (*(volatile unsigned int *)0xcf034400)
#define REG_4778 (*(volatile unsigned int *)0xcf014778)
extern unsigned char DAT_a80789ec;
extern unsigned char FUN_a008d800(void);

void FUN_a0083e34(unsigned char on)
{
    if (on != 0) {
        REG_33C0 |= 1;
        REG_4400 |= 1;
        DAT_a80789ec = 1;
        if (FUN_a008d800() > 0x81)
            REG_4778 = 0x65;
    } else {
        REG_33C0 &= ~1;
        REG_4400 &= ~1;
        DAT_a80789ec = 0;
        REG_4778 = 0;
    }
}
