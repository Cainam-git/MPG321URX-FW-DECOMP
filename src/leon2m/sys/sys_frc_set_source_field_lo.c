/* sys_frc_set_source_field_lo  (FUN_a0108eec)
 *
 * Write the 3-bit field at bits 0-2 of a converter source register.
 * Name basis: descriptive - register 0xCF011AA0 + 4 * n, n = 1..3; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0108eec @ 0xa0108eec, flags -mcpu=v8 -O3 -g.
 * Source form: a switch with the two register statements written out in every case; value is an unsigned char.
 */
#define REG_CF011AA4 (*(volatile unsigned int *)0xcf011aa4)
#define REG_CF011AA8 (*(volatile unsigned int *)0xcf011aa8)
#define REG_CF011AAC (*(volatile unsigned int *)0xcf011aac)

/*
 * Write `value` (low 3 bits) into bits 0 to 2 of the register 0xCF011AA0 + 4 * index, for index 1 to 3. Other
 * indexes do nothing. Nothing in the image calls it.
 */
void sys_frc_set_source_field_lo(unsigned char index, unsigned char value)
{
    switch (index) {
    case 1:
        REG_CF011AA4 &= ~7u;
        REG_CF011AA4 |= value & 7;
        break;
    case 2:
        REG_CF011AA8 &= ~7u;
        REG_CF011AA8 |= value & 7;
        break;
    case 3:
        REG_CF011AAC &= ~7u;
        REG_CF011AAC |= value & 7;
        break;
    }
}
