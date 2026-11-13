/* sys_frc_set_source_field_hi  (FUN_a0108e70)
 *
 * Write the 2-bit field at bits 4-5 of a converter source register.
 * Name basis: descriptive - register 0xCF011AA0 + 4 * n; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0108e70 @ 0xa0108e70, flags -mcpu=v8 -O3 -g.
 * Source form: a switch with the two register statements written out in every case.
 */
#define REG_CF011AA0 (*(volatile unsigned int *)0xcf011aa0)
#define REG_CF011AA4 (*(volatile unsigned int *)0xcf011aa4)
#define REG_CF011AA8 (*(volatile unsigned int *)0xcf011aa8)
#define REG_CF011AAC (*(volatile unsigned int *)0xcf011aac)

/*
 * Write `value` (low 2 bits) into bits 4 and 5 of the register 0xCF011AA0 + 4 * index. Indexes above 3 do nothing.
 * Nothing in the image calls it.
 */
void sys_frc_set_source_field_hi(unsigned char index, unsigned int value)
{
    switch (index) {
    case 0:
        REG_CF011AA0 &= ~0x30u;
        REG_CF011AA0 |= (value & 3) << 4;
        break;
    case 1:
        REG_CF011AA4 &= ~0x30u;
        REG_CF011AA4 |= (value & 3) << 4;
        break;
    case 2:
        REG_CF011AA8 &= ~0x30u;
        REG_CF011AA8 |= (value & 3) << 4;
        break;
    case 3:
        REG_CF011AAC &= ~0x30u;
        REG_CF011AAC |= (value & 3) << 4;
        break;
    }
}
