/* sys_set_c940_bit2_and_notify  (FUN_a014e82c)
 *
 * Set or clear bit 2 of register 0xCF03C940, then write the follow-up register.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014e82c @ 0xa014e82c-0xa014e878 (19 words), flags -mcpu=v8 -O3 -g.
 * Source form: the register as a volatile fixed-address macro, written in each arm; the call once after the if/else
 * (GCC duplicates it into both arms as two tail calls). Only -O3 gives the firmware's register copy (mov %o4,%o5)
 * for the store address.
 */
#define R(a) (*(volatile unsigned int *)(a))

#define REG_C940 0xcf03c940

extern void irq_raise_software_irq_bit3(void);

/*
 * Set bit 2 of register 0xCF03C940 when 'on' is 1, clear it otherwise, then raise software interrupt bit 3
 * (irq_raise_software_irq_bit3, which writes 8 to register 0x9F120024).
 *
 *   on  1 sets the bit, any other value clears it
 *
 * Nothing in the firmware calls it. The routine before it does the same with bit 1 and software interrupt bit 2.
 */
void sys_set_c940_bit2_and_notify(unsigned char on)
{
    if (on == 1)
        R(REG_C940) |= 4;
    else
        R(REG_C940) &= ~4;
    irq_raise_software_irq_bit3();
}
