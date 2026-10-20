/* leon2m FUN_a00f9bbc @ 0xa00f9bbc-0xa00f9d78 (111 words).
 * Copies the 17 halfwords at 0xa8027a30 into 12-bit fields of the hardware registers 0xd0040140..0xd0040160: register
 * k (k = 0..7) gets t[2k] in bits 0..11 and t[2k + 1] in bits 16..27, register 8 gets t[16] in bits 0..11. Other bits
 * keep their values; each register is read and written once. Same code as FUN_a00f9a00 with another table and
 * register block. Source form: the first field is set through a small static helper, set_field(v, bits, clear) = (v |
 * bits) & ~clear, which GCC inlines; written as one expression per register, the registers are assigned differently.
 */
extern unsigned short DAT_a8027a30[17];
#define REG(a) (*(volatile unsigned int *)(a))

static unsigned int set_field(unsigned int v, unsigned int bits, unsigned int clear)
{
    return (v | bits) & ~clear;
}

void FUN_a00f9bbc(void)
{
    REG(0xd0040140) = set_field(REG(0xd0040140) & ~0xfff, DAT_a8027a30[0] & 0xfff, 0xfff0000) | ((DAT_a8027a30[1] << 16) & 0xfff0000);
    REG(0xd0040144) = set_field(REG(0xd0040144) & ~0xfff, DAT_a8027a30[2] & 0xfff, 0xfff0000) | ((DAT_a8027a30[3] << 16) & 0xfff0000);
    REG(0xd0040148) = set_field(REG(0xd0040148) & ~0xfff, DAT_a8027a30[4] & 0xfff, 0xfff0000) | ((DAT_a8027a30[5] << 16) & 0xfff0000);
    REG(0xd004014c) = set_field(REG(0xd004014c) & ~0xfff, DAT_a8027a30[6] & 0xfff, 0xfff0000) | ((DAT_a8027a30[7] << 16) & 0xfff0000);
    REG(0xd0040150) = set_field(REG(0xd0040150) & ~0xfff, DAT_a8027a30[8] & 0xfff, 0xfff0000) | ((DAT_a8027a30[9] << 16) & 0xfff0000);
    REG(0xd0040154) = set_field(REG(0xd0040154) & ~0xfff, DAT_a8027a30[10] & 0xfff, 0xfff0000) | ((DAT_a8027a30[11] << 16) & 0xfff0000);
    REG(0xd0040158) = set_field(REG(0xd0040158) & ~0xfff, DAT_a8027a30[12] & 0xfff, 0xfff0000) | ((DAT_a8027a30[13] << 16) & 0xfff0000);
    REG(0xd004015c) = set_field(REG(0xd004015c) & ~0xfff, DAT_a8027a30[14] & 0xfff, 0xfff0000) | ((DAT_a8027a30[15] << 16) & 0xfff0000);
    REG(0xd0040160) = (REG(0xd0040160) & ~0xfff) | (DAT_a8027a30[16] & 0xfff);
}
