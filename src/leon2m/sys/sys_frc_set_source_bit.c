/* sys_frc_set_source_bit  (FUN_a01093a8)
 *
 * Set or clear one source bit of the frame-rate converter and update its idle bit.
 * Name basis: descriptive - register 0xCF011AA0; bit 6 is set exactly when bits 0-3 are all clear
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01093a8 @ 0xa01093a8, flags -mcpu=v8 -O3 -g.
 * Source form: the register is re-read for each of the four bit tests; the count is an unsigned char.
 */
#define REG_cf011aa0 (*(volatile unsigned int *)0xcf011aa0)

/*
 * Set (on != 0) or clear bit `source_class` of the register 0xCF011AA0. Setting first clears bit 6.
 * Then bit 6 is recomputed: it is cleared when any of bits 0 to 3 is set and set when all four are clear.
 *
 * Called by GMDHEnableFRC with sys_get_channel_source_class(channel) as the bit number.
 */
void sys_frc_set_source_bit(unsigned char source_class, unsigned char on)
{
    unsigned char count = 0;

    if (on) {
        REG_cf011aa0 &= ~0x40;
        REG_cf011aa0 |= 1 << source_class;
    } else {
        REG_cf011aa0 &= ~(1 << source_class);
    }
    if (REG_cf011aa0 & 1)
        count = 1;
    if (REG_cf011aa0 & 2)
        count++;
    if (REG_cf011aa0 & 4)
        count++;
    if (REG_cf011aa0 & 8)
        count++;
    if (count)
        REG_cf011aa0 &= ~0x40;
    else
        REG_cf011aa0 |= 0x40;
}
