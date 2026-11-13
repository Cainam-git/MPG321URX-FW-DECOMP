/* pq_ace_write_reg_d8  (FUN_a00f6cdc)
 *
 * Write register 0xCF00EED8 of the ACE block.
 * Name basis: descriptive - mechanics only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f6cdc @ 0xa00f6cdc-0xa00f6cf4 (24 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Source form: a volatile register store of an unsigned char parameter (and 0xff; the store stays before retl).
 */
/* Write a byte to register 0xCF00EED8 of the ACE block.
   Called by pq_fga_handle_command to carry out a calibration command received over DDC/CI. */
#define ACE_REG_D8 (*(volatile unsigned int *)0xcf00eed8)

void pq_ace_write_reg_d8(unsigned char value)
{
    ACE_REG_D8 = value;
}
