/* edid_setup_port_slaves  (FUN_CODE_abc4)
 *
 * Set the EDID slave address and mode of the ports chosen by a bit mask.
 *   port_mask: port bits 0..6
 *   address: slave address
 *   size_mode: mode bit
 * Name basis: derived - command 0x01 (main side ipc_8051_enable_internal_edid): address 0xA0 | segment bits,
 *   mode 0x33 / 0x13; registers 0xF01C..
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_abc4 @ 0xabc4 (151 bytes), OPTIMIZE(8,SPEED) LARGE.
 * Source form: 'size_mode &= 1; ... (size_mode == 1)' gives the firmware's 'ANL A,#1 / CJNE A,#1'
 *   ('(size_mode & 1) == 1' compiles to JNB ACC.0); the '?:' result is built in R7 and copied to R6.
 */
extern unsigned char xdata reg_edid0_ctrl, reg_edid0_address, reg_edid1_ctrl, reg_edid1_address, reg_edid2_ctrl, reg_edid2_address, reg_edid3_ctrl, reg_edid3_address, reg_edid4_ctrl, reg_edid4_address, reg_edid5_ctrl, reg_edid5_address, reg_edid6_ctrl, reg_edid6_address;

#define EDID_SLAVE_ADDRESS    0xa0  /* EDID slave address; bits 3..1 may be set by the main processor */
#define EDID_ADDRESS_CHECK    0xf1  /* bits that must read 0xA0, else the address falls back to 0xA0 */
#define EDID_ADDRESS_BITS     0x0e
#define EDID_CTRL_KEEP        0xc0  /* control bits 7..6 are kept */
#define EDID_CTRL_256_BYTES   0x33  /* size mode 1: EDID longer than 128 bytes (docs/MAILBOX.md, command 0x01) */
#define EDID_CTRL_128_BYTES   0x13

/*
 * edid_setup_port_slaves - set the slave address and the size mode of the EDID slave of every port in port_mask.
 *   port_mask  bit N = port N (0..6)
 *   address    wanted slave address: 0xA0 with bits 3..1 free; any other value gives 0xA0
 *   size_mode  bit 0: 1 = 256-byte mode (0x33 into the control register), 0 = 0x13
 * Bits 7..6 of each control register are kept.
 * Only caller: mailbox command IPC_8051_CMD_ENABLE_EDID (0x01) in ipc_run_command, followed by
 * edid_enable_port_slaves for the same ports.
 */
void edid_setup_port_slaves(unsigned char port_mask, unsigned char address, unsigned char size_mode)
{
    unsigned char ctrl_bits;

    if ((address & EDID_ADDRESS_CHECK) != EDID_SLAVE_ADDRESS) address = EDID_SLAVE_ADDRESS;
    address = (address & EDID_ADDRESS_BITS) | EDID_SLAVE_ADDRESS;
    size_mode &= 1;
    ctrl_bits = (size_mode == 1) ? EDID_CTRL_256_BYTES : EDID_CTRL_128_BYTES;
    if (port_mask & 0x01) { reg_edid0_ctrl = (reg_edid0_ctrl & EDID_CTRL_KEEP) | ctrl_bits; reg_edid0_address = address; }
    if (port_mask & 0x02) { reg_edid1_ctrl = (reg_edid1_ctrl & EDID_CTRL_KEEP) | ctrl_bits; reg_edid1_address = address; }
    if (port_mask & 0x04) { reg_edid2_ctrl = (reg_edid2_ctrl & EDID_CTRL_KEEP) | ctrl_bits; reg_edid2_address = address; }
    if (port_mask & 0x08) { reg_edid3_ctrl = (reg_edid3_ctrl & EDID_CTRL_KEEP) | ctrl_bits; reg_edid3_address = address; }
    if (port_mask & 0x10) { reg_edid4_ctrl = (reg_edid4_ctrl & EDID_CTRL_KEEP) | ctrl_bits; reg_edid4_address = address; }
    if (port_mask & 0x20) { reg_edid5_ctrl = (reg_edid5_ctrl & EDID_CTRL_KEEP) | ctrl_bits; reg_edid5_address = address; }
    if (port_mask & 0x40) { reg_edid6_ctrl = (reg_edid6_ctrl & EDID_CTRL_KEEP) | ctrl_bits; reg_edid6_address = address; }
}
