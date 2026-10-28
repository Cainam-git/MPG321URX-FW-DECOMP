/* leon2m FUN_a00f72cc @ 0xa00f72cc-0xa00f7434.
 * Saves the low byte of register 0xcf00e984, calls func_0x4008e2a4(), then sets (p != 0) or clears bit 6 of
 * 0xcf00e984. For the field values 0, 2 and 4 in bits 1..3 of 0xcf00e984 (written as (reg & 0xf1) | value) it reads
 * four halfwords into out: 0xcf00e98c | 0xcf00e990 << 8, 0xcf00e994 | 0xcf00e998 << 8, 0xcf00e99c | 0xcf00e9a0 << 8
 * and 0xcf00e9a4, giving out halfwords 0..3, 4..7 and 8..11. Finally the saved byte is written back to 0xcf00e984.
 * Source form: out points to a union of 12 halfwords and 6 words, so the halfword stores share an alias set with the
 * word register reads and stay between them in the firmware's order (with a plain unsigned short pointer GCC moves
 * all reads of a group before its stores). The saved value is an unsigned char local.
 */
#define R(a) (*(volatile unsigned int *)(a))

union P { unsigned short h[12]; unsigned int w[6]; };
extern void func_0x4008e2a4(void);

void FUN_a00f72cc(unsigned char p, union P *out)
{
    unsigned char save;

    save = R(0xcf00e984);
    func_0x4008e2a4();
    if (p != 0)
        R(0xcf00e984) |= 0x40;
    else
        R(0xcf00e984) &= ~0x40;
    R(0xcf00e984) = (R(0xcf00e984) & 0xf1) | 0;
    out->h[0] = R(0xcf00e98c) | (R(0xcf00e990) << 8);
    out->h[1] = R(0xcf00e994) | (R(0xcf00e998) << 8);
    out->h[2] = R(0xcf00e99c) | (R(0xcf00e9a0) << 8);
    out->h[3] = R(0xcf00e9a4);
    R(0xcf00e984) = (R(0xcf00e984) & 0xf1) | 2;
    out->h[4] = R(0xcf00e98c) | (R(0xcf00e990) << 8);
    out->h[5] = R(0xcf00e994) | (R(0xcf00e998) << 8);
    out->h[6] = R(0xcf00e99c) | (R(0xcf00e9a0) << 8);
    out->h[7] = R(0xcf00e9a4);
    R(0xcf00e984) = (R(0xcf00e984) & 0xf1) | 4;
    out->h[8] = R(0xcf00e98c) | (R(0xcf00e990) << 8);
    out->h[9] = R(0xcf00e994) | (R(0xcf00e998) << 8);
    out->h[10] = R(0xcf00e99c) | (R(0xcf00e9a0) << 8);
    out->h[11] = R(0xcf00e9a4);
    R(0xcf00e984) = save;
}
