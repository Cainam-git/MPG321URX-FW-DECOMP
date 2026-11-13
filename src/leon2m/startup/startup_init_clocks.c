/* startup_init_clocks  (FUN_a0102680)
 *
 * Set two fixed clock values and their enable bits.
 * Name basis: derived - called from start-up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0102680, flags -mcpu=v8 -O3 -g.
 */
#define R(a) (*(volatile unsigned int *)(a))
extern void reg_write24_bytes_settle(unsigned int, unsigned int);

/*
 * First call of start-up step 2 (startup_bring_up_system), before startup_init_core. Sets bit 6 of 0xCF014780,
 * writes the 24-bit value 0x320000 to the three byte registers from 0xCF014184, sets bit 7 of 0xCF014194 and bit 4
 * of 0xCF012440, then writes the 24-bit value 0x29AAAA to the three byte registers from 0xCF012A44. Writes only:
 * it does not read anything back or wait for a lock.
 */
void startup_init_clocks(void)
{
    R(0xcf014780) |= 0x40;
    reg_write24_bytes_settle(0xcf014184, 0x320000);
    R(0xcf014194) |= 0x80;
    R(0xcf012440) |= 0x10;
    reg_write24_bytes_settle(0xcf012a44, 0x29aaaa);
}
