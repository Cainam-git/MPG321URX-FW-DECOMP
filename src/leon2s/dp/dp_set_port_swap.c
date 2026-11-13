/* dp_set_port_swap  (FUN_a0083e34)
 *
 * Set or clear the DP receiver port swap.
 *   on: 1 = swapped
 * Name basis: descriptive - bit 0 of 0xCF0133C0 and 0xCF034400 plus the flag dp_map_port reads
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0083e34 (0xa0083e34-0xa0083ec4, 144 bytes), flags -mcpu=v8 -Os -g.
 */
#define REG_CF0133C0 (*(volatile unsigned int *)0xcf0133c0)
#define REG_CF034400 (*(volatile unsigned int *)0xcf034400)
#define REG_CF014778 (*(volatile unsigned int *)0xcf014778)
extern unsigned char dp_port_swap_flag;
extern unsigned char sys_get_chip_revision(void);

/*
 * Turn the DP receiver port swap on or off.
 * On: sets bit 0 of registers 0xcf0133c0 and 0xcf034400, sets dp_port_swap_flag to 1 (dp_map_port reads it),
 * and writes 0x65 to register 0xcf014778 when the chip revision code is above 0x81.
 * Off: clears the two bits and the flag and writes 0 to register 0xcf014778.
 *   on: 1 = swapped
 */
void dp_set_port_swap(unsigned char on)
{
    if (on != 0) {
        REG_CF0133C0 |= 1;
        REG_CF034400 |= 1;
        dp_port_swap_flag = 1;
        if (sys_get_chip_revision() > 0x81)
            REG_CF014778 = 0x65;
    } else {
        REG_CF0133C0 &= ~1;
        REG_CF034400 &= ~1;
        dp_port_swap_flag = 0;
        REG_CF014778 = 0;
    }
}
