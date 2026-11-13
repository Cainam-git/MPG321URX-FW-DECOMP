/* edid_init_port_regs  (FUN_CODE_8947)
 *
 * Write a fixed set-up into one port's EDID slave registers.
 *   port
 *   unused
 *   value
 * Note: No caller in the bank-1 image; parameter b is unused.
 * Name basis: descriptive - register pointers from CODE tables 0xB114.. (port 0: 0xF01C, 0xF01D, 0xF15B ..);
 *   writes 0xA0, 0xE8, 0, v
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_8947 @ 0x8947..0x8A51 (266 bytes), OPTIMIZE(8,SPEED) LARGE.
 * Source form: 'unused = unused;' (the usual way to silence Keil's unreferenced-parameter warning) emits no code
 * and keeps Keil from storing the parameter to its XDATA slot; without it the routine starts with
 * 'MOV DPTR,#slot / MOV A,R5 / MOVX'. The CODE tables are declared with their size (7), which gives the 8-bit
 * MUL AB index. The targets are hardware registers (volatile).
 */
extern unsigned char volatile * code edid_slave_ctrl_reg_ptrs[7];
extern unsigned char volatile * code edid_slave_addr_reg_ptrs[7];
extern unsigned char volatile * code edid_init_zero_reg_ptrs[7];
extern unsigned char volatile * code edid_init_value_reg_ptrs[7];
extern unsigned char volatile * code edid_init_extra_reg_ptrs[7];
extern unsigned char volatile * xdata DAT_EXTMEM_a6df;
extern unsigned char volatile * xdata DAT_EXTMEM_a6e2;
extern unsigned char volatile * xdata DAT_EXTMEM_a6e5;
extern unsigned char volatile * xdata DAT_EXTMEM_a6e8;
extern unsigned char volatile * xdata DAT_EXTMEM_a6eb;
extern unsigned char xdata DAT_EXTMEM_a6de;

/*
 * edid_init_port_regs - write a fixed set-up into the EDID slave registers of one port.
 *   port    0..6, index into the five CODE tables of register pointers
 *   unused  not used
 *   value   written to the port's fourth register when not 0
 * The five register pointers of the port are kept in XDATA 0xA6DF, 0xA6E2, 0xA6E5, 0xA6E8 and 0xA6EB (port 0:
 * reg_edid0_ctrl 0xF01C, reg_edid0_address 0xF01D, 0xF15B, 0xF15D, 0xF15E; for ports 1..6 the last three are
 * 0xF382, 0xF384 and 0xF385 plus 5 per port after port 1). Writes 0xA0 to the control register, 0xE8 to the address register, 0 to the third register, value to the
 * fourth and the byte at XDATA 0xA6DE to the fifth when that byte is not 0.
 * Nothing in the bank 1 program calls this routine.
 */
void edid_init_port_regs(unsigned char port, unsigned char unused, unsigned char value)
{
    unused = unused;
    DAT_EXTMEM_a6df = edid_slave_ctrl_reg_ptrs[port];
    DAT_EXTMEM_a6e2 = edid_slave_addr_reg_ptrs[port];
    DAT_EXTMEM_a6e5 = edid_init_zero_reg_ptrs[port];
    DAT_EXTMEM_a6e8 = edid_init_value_reg_ptrs[port];
    DAT_EXTMEM_a6eb = edid_init_extra_reg_ptrs[port];
    *DAT_EXTMEM_a6df = 0xa0;
    *DAT_EXTMEM_a6e2 = 0xe8;
    *DAT_EXTMEM_a6e5 = 0;
    if (value) *DAT_EXTMEM_a6e8 = value;
    if (DAT_EXTMEM_a6de) *DAT_EXTMEM_a6eb = DAT_EXTMEM_a6de;
}
