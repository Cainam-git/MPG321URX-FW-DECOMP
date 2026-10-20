/* leon2m FUN_a00f9a00 @ 0xa00f9a00-0xa00f9bbc (111 words).
 * Copies the 17 halfwords at 0xa8027a52 into 12-bit fields of the hardware registers 0xd0040110..0xd0040130: register
 * k (k = 0..7) gets t[2k] in bits 0..11 and t[2k + 1] in bits 16..27, register 8 gets t[16] in bits 0..11. Other bits
 * keep their values; each register is read and written once. Source form: the first field is set through a small
 * static helper, set_field(v, bits, clear) = (v | bits) & ~clear, which GCC inlines; written as one expression per
 * register, the registers are assigned differently.
 */
extern unsigned short DAT_a8027a52[17];
#define REG(a) (*(volatile unsigned int *)(a))

static unsigned int set_field(unsigned int v, unsigned int bits, unsigned int clear)
{
    return (v | bits) & ~clear;
}

void FUN_a00f9a00(void)
{
    REG(0xd0040110) = set_field(REG(0xd0040110) & ~0xfff, DAT_a8027a52[0] & 0xfff, 0xfff0000) | ((DAT_a8027a52[1] << 16) & 0xfff0000);
    REG(0xd0040114) = set_field(REG(0xd0040114) & ~0xfff, DAT_a8027a52[2] & 0xfff, 0xfff0000) | ((DAT_a8027a52[3] << 16) & 0xfff0000);
    REG(0xd0040118) = set_field(REG(0xd0040118) & ~0xfff, DAT_a8027a52[4] & 0xfff, 0xfff0000) | ((DAT_a8027a52[5] << 16) & 0xfff0000);
    REG(0xd004011c) = set_field(REG(0xd004011c) & ~0xfff, DAT_a8027a52[6] & 0xfff, 0xfff0000) | ((DAT_a8027a52[7] << 16) & 0xfff0000);
    REG(0xd0040120) = set_field(REG(0xd0040120) & ~0xfff, DAT_a8027a52[8] & 0xfff, 0xfff0000) | ((DAT_a8027a52[9] << 16) & 0xfff0000);
    REG(0xd0040124) = set_field(REG(0xd0040124) & ~0xfff, DAT_a8027a52[10] & 0xfff, 0xfff0000) | ((DAT_a8027a52[11] << 16) & 0xfff0000);
    REG(0xd0040128) = set_field(REG(0xd0040128) & ~0xfff, DAT_a8027a52[12] & 0xfff, 0xfff0000) | ((DAT_a8027a52[13] << 16) & 0xfff0000);
    REG(0xd004012c) = set_field(REG(0xd004012c) & ~0xfff, DAT_a8027a52[14] & 0xfff, 0xfff0000) | ((DAT_a8027a52[15] << 16) & 0xfff0000);
    REG(0xd0040130) = (REG(0xd0040130) & ~0xfff) | (DAT_a8027a52[16] & 0xfff);
}
