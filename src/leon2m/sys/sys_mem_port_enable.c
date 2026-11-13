/* sys_mem_port_enable  (FUN_a0115644)
 *
 * Switch the memory port on or off.
 * Name basis: derived - bit 7 and bit 0 of register 0xCF011F80
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0115644 @ 0xa0115644-0xa0115684 (16 words), flags -mcpu=v8 -O3 -g.
 * Source form: two separate read-modify-writes of the volatile register. The zero case is written first; with
 * the arms swapped GCC inverts the branch and the block order.
 */
#define REG_cf011f80 (*(volatile unsigned int *)0xcf011f80)  /* memory port control register */
#define MEM_PORT_BIT7 0x80
#define MEM_PORT_ON   1         /* bit 0 */

/*
 * Switch the memory port on (on non-zero) or off (on 0).
 * Sets bit 7 of the control register 0xCF011F80 in both cases, then sets or clears bit 0.
 * Called by fwupd_verify_file_checksum (twice) and pq_read_zone_color_averages.
 */
void sys_mem_port_enable(unsigned char on)
{
    REG_cf011f80 |= MEM_PORT_BIT7;
    if (on == 0)
        REG_cf011f80 &= ~MEM_PORT_ON;
    else
        REG_cf011f80 |= MEM_PORT_ON;
}
