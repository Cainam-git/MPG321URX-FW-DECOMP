/* ipc_portal_write  (FUN_CODE_b228)
 *
 * Write words to the mailbox portal shared with the main processor.
 *   off: byte offset
 *   src: words
 *   n: word count
 * Name basis: proven - AHB 0x9F0A0100 + offset through reg_ahb_write32 (header of ipc_service_mailbox)
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_b228, OPTIMIZE(8,SPEED) LARGE. The third parameter is passed in memory (XDATA 0xA4BF) because the
 * generic pointer occupies R1..R3. The AHB address is built in a local and copied into the callee's parameter slots.
 */
typedef union { unsigned long l; unsigned char b[4]; } DW;
extern DW xdata reg_ahb_write_addr;
extern DW xdata reg_ahb_write_value;
extern void reg_ahb_write32(void);   /* parameters in its overlay: addr = 0xA4EC, val = 0xA4F0 */
/*
 * ipc_portal_write - write n 32-bit words to the mailbox portal shared with the main processor: word i goes to
 * AHB address 0x9F0A0100 + off + 4*i through reg_ahb_write32. Only the low address byte is changed (8-bit sum).
 *   off: byte offset in the portal
 *   src: the words
 *   n: word count
 * Caller seen: flash_update_fe2p_address ("Update FE2P Addr") posts the new address with ipc_portal_write(0xB4, &addr, 1).
 */
void ipc_portal_write(unsigned char off, unsigned long *src, unsigned char n)
{
    unsigned char i;
    DW addr;
    DW val;
    addr.l = 0x9F0A0100;
    for (i = 0; i < n; i++) {
        addr.b[3] = off + i * 4;
        val.l = src[i];
        reg_ahb_write_addr = addr;
        reg_ahb_write_value = val;
        reg_ahb_write32();
    }
}
