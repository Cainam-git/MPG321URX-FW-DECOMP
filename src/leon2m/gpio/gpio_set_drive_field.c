/* gpio_set_drive_field  (FUN_a010031c)
 *
 * Write a 3-bit field of one of two pin drive registers.
 * Name basis: descriptive - 0xCF03C158 or 0xCF03C144; called from System_Initialize
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010031c, flags -mcpu=v8 -O3 -g.
 * Source form: an if/else chain on sel (not a switch).
 */

/* Each register holds two 3-bit fields: bits 0..2 and bits 3..5. */
#define REG_cf03c158 (*(volatile unsigned int *)0xcf03c158)
#define REG_cf03c144 (*(volatile unsigned int *)0xcf03c144)

/*
 * Write value (0..7; larger values are ignored) into one 3-bit field. Field 0 is bits 0..2 and field 1 bits 3..5
 * of 0xCF03C158; field 2 is bits 0..2 and field 3 bits 3..5 of 0xCF03C144. Other field numbers do nothing.
 * System_Initialize calls it for the fields 0 to 3.
 */
void gpio_set_drive_field(unsigned char field, unsigned char value)
{
    if (value > 7)
        return;
    if (field == 0)
        REG_cf03c158 = (REG_cf03c158 & ~7) | value;
    else if (field == 1)
        REG_cf03c158 = (REG_cf03c158 & ~0x38) | (value << 3);
    else if (field == 2)
        REG_cf03c144 = (REG_cf03c144 & ~7) | value;
    else if (field == 3)
        REG_cf03c144 = (REG_cf03c144 & ~0x38) | (value << 3);
}
