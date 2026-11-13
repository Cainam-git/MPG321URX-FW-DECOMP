/* sys_write_status_register  (FUN_a01004cc)
 *
 * Write the status byte to the status register.
 * Name basis: descriptive - register 0xCF03C880; written by sys_publish_chip_status_code
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01004cc @ 0xa01004cc, flags -mcpu=v8 -O2 -g (the section default).
 */
#define reg_ipc_8051_shared_f220 (*(volatile unsigned int *)0xcf03c880)

/*
 * Write the low byte of `status` to the word register at 0xCF03C880.
 *
 * Called by sys_publish_chip_status_code, with the stored link status code (0 or 3).
 */
void sys_write_status_register(unsigned int status)
{
  reg_ipc_8051_shared_f220 = status & 0xff;
}
