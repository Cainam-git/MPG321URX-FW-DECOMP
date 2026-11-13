/* sys_set_c940_bit1_and_notify  (FUN_a014e7e0)
 *
 * Set or clear bit 1 of register 0xCF03C940, then write the follow-up register.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014e7e0 @ 0xa014e7e0-0xa014e82c (19 words), flags -mcpu=v8 -O3 -g.
 * Source form: the register as a volatile fixed-address macro, written in each arm; the call once after the if/else
 * (GCC duplicates it into both arms as two tail calls). Only -O3 gives the firmware's register copy (mov %o4,%o5)
 * for the store address.
 */
#define R(a) (*(volatile unsigned int *)(a))

#define REG_C940 0xcf03c940

extern void irq_raise_software_irq_bit2(void);

/*
 * Set bit 1 of register 0xCF03C940 when 'on' is 1, clear it otherwise, then raise software interrupt bit 2
 * (irq_raise_software_irq_bit2, which writes 4 to register 0x9F120024).
 *
 *   on  1 sets the bit, any other value clears it
 *
 * Nothing in the firmware calls it. The routine after it does the same with bit 2 and software interrupt bit 3.
 */
void sys_set_c940_bit1_and_notify(unsigned char on)
{
    if (on == 1)
        R(REG_C940) |= 2;
    else
        R(REG_C940) &= ~2;
    irq_raise_software_irq_bit2();
}
