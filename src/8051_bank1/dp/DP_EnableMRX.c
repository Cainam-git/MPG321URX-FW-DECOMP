/* DP_EnableMRX  (FUN_CODE_8a51)
 *
 * Switch the DisplayPort receivers to 8051-handled AUX mode and set them up.
 *   port: 0 or 1
 * Name basis: proven - prints 'DP_EnableMRX (%bx)' (original name); AUX registers 0xDCxx,
 *   dp_mrx_init_regs_80_fc / _c6
 *
 * Matching notes
 * --------------
 * Compiler flags: OPTIMIZE(8,SPEED) LARGE.
 * volatile on reg_chip_id (read again for every compare of the chain) and on the two-byte groups 0xDCDE and 0xDCCE
 *   (the firmware reads 0xDCDF / 0xDCCF back after each store; INC DPTR from the first byte = one object each).
 * Source form: the last test is '!(reg_chip_id == CHIP_ID_20)' (SETB C / CLR C / JC).
 */

#define DP_PORT0                  0
#define DP_PORT1                  1

/* reg_dp_aux_mode_portN is used as two bytes: [0] mode, [1] control (0xDCDF / 0xDCCF). */
#define AUX_MODE_VALUE            0x95
#define AUX_CTRL_BIT1             0x02
#define AUX_CTRL_BIT2             0x04
#define AUX_CTRL_BIT3             0x08

/* dp_aux_port_state_flags: four bits per receiver (receiver 1 << 4). */
#define PORT_POWERED_ON           0x02  /* bit 1: powered on by DPCD 0x600 */
#define BOTH_PORTS_POWERED_ON     (PORT_POWERED_ON | PORT_POWERED_ON << 4)

#define CHIP_ID_16                0x16
#define CHIP_ID_17                0x17
#define CHIP_ID_1A                0x1a
#define CHIP_ID_1E                0x1e
#define CHIP_ID_1F                0x1f
#define CHIP_ID_20                0x20  /* reg_chip_id value with its own set-up path */
#define MRX_SETUP_BYTES           7     /* bytes copied to XDATA 0xE140.. */
#define AUX_IRQ_ENABLE_BITS_3_4   0x18  /* reg_dp_mrx_aux_irq_enable value bits on chip 0x1A */
#define AUX_IRQ_ENABLE_BIT3       0x08  /* on every other chip */

extern unsigned char volatile xdata reg_dp_aux_mode_port0[2];
extern unsigned char volatile xdata reg_dp_aux_mode_port1[2];
extern unsigned char xdata DAT_EXTMEM_f161;
extern unsigned char xdata reg_dp_mrx_aux_irq_enable;
extern unsigned char volatile xdata reg_chip_id;
extern unsigned char xdata DAT_EXTMEM_e140[7];
extern unsigned char xdata dp_aux_link_config_port0_0x03;
extern unsigned char xdata dp_aux_link_config_port1_0x03;
extern unsigned char xdata dp_aux_port_state_flags;
extern unsigned char code dp_mrx_setup_bytes_default[7];
extern unsigned char code dp_mrx_setup_bytes_chip1a[7];
extern unsigned char code dp_mrx_setup_bytes_chip20[7];
extern bit sys_shared_bit_param;
extern bit dp_aux_answer_mode_flag;
extern void lib_printf517(void *fmt, ...) large;
extern void dp_aux_init_regs(void);
extern void dp_mrx_init_regs_80_fc(unsigned char ch);
extern void dp_mrx_init_regs_c6(unsigned char ch);

/* Hand the AUX channel of DP receiver 'port' (0 or 1) to the 8051 and set up the receivers for it.
 * Callers: Enable_DPMRX (mailbox command 0x2A, both receivers) and power_init_wake_detection (each receiver the
 * wake-up table names, unless bit 0 of its AUX control byte is already set).
 * Prints "DP_EnableMRX (%bx)" with port. In order:
 *   1. The AUX mode byte of the chosen receiver is set to 0x95, its control byte written 5 (receiver 0) or 9
 *      (receiver 1), bit 3 or 2 cleared, then written 1; byte 3 of its kept link configuration is cleared.
 *   2. Both receivers, whichever was chosen: control bit 1 cleared; receiver 0 gets bit 2 set and bit 3 cleared,
 *      receiver 1 bit 3 set and bit 2 cleared. Bits 1..0 of 0xF161 are cleared, and both receivers count as
 *      powered on in dp_aux_port_state_flags (all other bits of it cleared).
 *   3. Seven set-up bytes go to XDATA 0xE140.. from the table of the chip ID (none for chip IDs not listed).
 *   4. The AUX interrupt enables: bits 3..4 on chip 0x1A, bit 3 on the others.
 *   5. Chip 0x20: dp_aux_init_regs loads both receivers' AUX registers (with its bit choice taken from
 *      dp_aux_answer_mode_flag through sys_shared_bit_param), then both fixed receiver sequences run for receiver 0
 *      and receiver 1. Every other chip: dp_aux_answer_mode_flag is set, so the 8051 answers AUX requests itself.
 * Steps 2..5 do not depend on 'port'.
 */
void DP_EnableMRX(unsigned char port)
{
    unsigned char i;

    lib_printf517((void code *)0x6ac3, port);    /* "DP_EnableMRX (%bx)\r\n" */
    /* 1. The chosen receiver. */
    if (port == DP_PORT0) {
        reg_dp_aux_mode_port0[0] = AUX_MODE_VALUE;
        reg_dp_aux_mode_port0[1] = 0x05;
        reg_dp_aux_mode_port0[1] &= ~AUX_CTRL_BIT3;
        reg_dp_aux_mode_port0[1] = 0x01;
        dp_aux_link_config_port0_0x03 = 0;
    } else {
        reg_dp_aux_mode_port1[0] = AUX_MODE_VALUE;
        reg_dp_aux_mode_port1[1] = 0x09;
        reg_dp_aux_mode_port1[1] &= ~AUX_CTRL_BIT2;
        reg_dp_aux_mode_port1[1] = 0x01;
        dp_aux_link_config_port1_0x03 = 0;
    }
    /* 2. Both receivers. */
    reg_dp_aux_mode_port0[1] &= ~AUX_CTRL_BIT1;
    reg_dp_aux_mode_port1[1] &= ~AUX_CTRL_BIT1;
    reg_dp_aux_mode_port0[1] |= AUX_CTRL_BIT2;
    reg_dp_aux_mode_port0[1] &= ~AUX_CTRL_BIT3;
    reg_dp_aux_mode_port1[1] |= AUX_CTRL_BIT3;
    reg_dp_aux_mode_port1[1] &= ~AUX_CTRL_BIT2;
    DAT_EXTMEM_f161 &= 0xfc;
    dp_aux_port_state_flags = BOTH_PORTS_POWERED_ON;
    /* 3. Set-up bytes by chip ID. */
    for (i = 0; i < MRX_SETUP_BYTES; i++) {
        if (reg_chip_id == CHIP_ID_1A)
            DAT_EXTMEM_e140[i] = dp_mrx_setup_bytes_chip1a[i];
        else if (reg_chip_id == CHIP_ID_20)
            DAT_EXTMEM_e140[i] = dp_mrx_setup_bytes_chip20[i];
        else if (reg_chip_id == CHIP_ID_16 || reg_chip_id == CHIP_ID_1E || reg_chip_id == CHIP_ID_1F || reg_chip_id == CHIP_ID_17)
            DAT_EXTMEM_e140[i] = dp_mrx_setup_bytes_default[i];
    }
    /* 4. AUX interrupt enables. */
    if (reg_chip_id == CHIP_ID_1A)
        reg_dp_mrx_aux_irq_enable |= AUX_IRQ_ENABLE_BITS_3_4;
    else
        reg_dp_mrx_aux_irq_enable |= AUX_IRQ_ENABLE_BIT3;
    /* 5. Chip 0x20 sets up the receiver registers; the others answer AUX requests in the 8051. */
    if (reg_chip_id == CHIP_ID_20) {
        sys_shared_bit_param = dp_aux_answer_mode_flag;
        dp_aux_init_regs();
        dp_mrx_init_regs_80_fc(DP_PORT0);
        dp_mrx_init_regs_c6(DP_PORT0);
        dp_mrx_init_regs_80_fc(DP_PORT1);
        dp_mrx_init_regs_c6(DP_PORT1);
    }
    if (!(reg_chip_id == CHIP_ID_20))
        dp_aux_answer_mode_flag = 1;
}
