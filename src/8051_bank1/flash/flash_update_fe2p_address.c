/* flash_update_fe2p_address  (FUN_CODE_d31d)
 *
 * Store and log a new LEON flash window address and pass it to the main chip.
 *   addr: new window base
 * Name basis: proven - prints 'Update FE2P Addr %08lx'; posts the value to mailbox portal word 0xB4
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d31d @ 0xd31d  OPTIMIZE(8,SPEED)
 * Source form: the pointer to the stored value is a separate local, set after the print.
 */
#define FE2P_PORTAL_WORD 0xb4  /* mailbox portal word that receives the new window base */

extern unsigned long xdata DAT_EXTMEM_a4b3;
extern unsigned char xdata DAT_EXTMEM_a4bf;
extern void lib_printf517(void *fmt, ...) large;
extern void ipc_portal_write(unsigned char n, void *p);

/*
 * Keep a new flash window base (the address through which the LEON cores see the flash), print it as
 * "Update FE2P Addr %08lx", set the flag byte at XDATA 0xA4BF and post the 4-byte value to the main chip
 * through portal word 0xB4.
 */
void flash_update_fe2p_address(unsigned long addr)
{
    void *value_ptr;

    DAT_EXTMEM_a4b3 = addr;
    lib_printf517((void code *)0x54cb, DAT_EXTMEM_a4b3);
    value_ptr = (void *)&DAT_EXTMEM_a4b3;
    DAT_EXTMEM_a4bf = 1;
    ipc_portal_write(FE2P_PORTAL_WORD, value_ptr);
}
