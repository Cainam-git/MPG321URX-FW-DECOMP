/* sys_frc_set_six_bit_field  (FUN_a010ad28)
 *
 * Write a 6-bit field of one of the registers 0xCF011DCC..0xCF011DD8.
 * Name basis: descriptive - bit 7 kept; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010ad28 @ 0xa010ad28-0xa010adb8 (36 words), flags -mcpu=v8 -O3 -g.
 * Source form: a switch with the default arm written first; GCC shares the store block of case 2 and the default
 * through a register holding the address.
 */
#define FRC_REG_DCC (*(volatile unsigned int *)0xcf011dcc)
#define FRC_REG_DD0 (*(volatile unsigned int *)0xcf011dd0)
#define FRC_REG_DD4 (*(volatile unsigned int *)0xcf011dd4)
#define FRC_REG_DD8 (*(volatile unsigned int *)0xcf011dd8)

/*
 * Write the low 6 bits of `value` to one of four registers, keeping bit 7 of the register and clearing the
 * rest. `which` 1, 2 and 3 select 0xCF011DD0, 0xCF011DD4 and 0xCF011DD8; any other value selects 0xCF011DCC.
 */
void sys_frc_set_six_bit_field(unsigned char which, unsigned int value)
{
    unsigned char field = value & 0x3f;

    switch (which) {
    default:
        FRC_REG_DCC = (FRC_REG_DCC & 0x80) | field;
        break;
    case 1:
        FRC_REG_DD0 = (FRC_REG_DD0 & 0x80) | field;
        break;
    case 2:
        FRC_REG_DD4 = (FRC_REG_DD4 & 0x80) | field;
        break;
    case 3:
        FRC_REG_DD8 = (FRC_REG_DD8 & 0x80) | field;
        break;
    }
}
