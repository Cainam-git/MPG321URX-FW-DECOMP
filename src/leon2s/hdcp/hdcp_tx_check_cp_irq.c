/* hdcp_tx_check_cp_irq  (FUN_a00cf9e8)
 *
 * Acknowledge a copy-protection interrupt flag of the output and test two status bytes.
 * Returns: 1 when the status bit is set
 * Name basis: derived - DPCD 0x201 bit 2 (CP_IRQ) cleared, then DPCD 0x68029 (HDCP status) read
 *
 * Matching notes
 * --------------
 * FUN_a00cf9e8 (leon2s, 0xa00cf9e8-0xa00cfab8, 208 bytes, 52 words).
 * Flags: -mcpu=v8 -Os -g.
 * Source form: u8 return type and a u8 result variable returned as is (an int variable returned as 'result & 1'
 * gives a different exit block).
 */
extern int dp_tx_aux_write_byte(int, int, int, int);
extern int dp_tx_aux_read_byte(int, int, int, void *);

#define AUX_CMD_READ            0x90
#define AUX_CMD_WRITE           0x80
#define AUX_ADDR_0x201          0x201
#define AUX_ADDR_0x68029        0x68029
#define AUX_ADDR_0x69493        0x69493
#define BYTE_0x201_BIT2         4       /* bit 2 of the byte at 0x201; written back as 4 */

/*
 * Test the interrupt flag of the DisplayPort receiver and, when it is set, look at two status bytes.
 *
 * The byte at AUX address 0x201 is read. If its bit 2 is set, 4 is written back to that address and then
 * 0x68029 is read: when the read succeeds (return 0) and bit 2 or bit 3 of the byte is set the result is 1.
 * Then 0x69493 is read in the same way: bit 3 or bit 4 of the byte sets the result to 1. Returns 1 if any of
 * these bits was set, else 0 (also 0 when the first byte had bit 2 clear). Called by hdcp_tx_service_port with
 * 0.
 */
unsigned char hdcp_tx_check_cp_irq(unsigned char port_arg)
{
    unsigned char status;
    unsigned char irq_flags;
    unsigned char found = 0;
    unsigned char port;

    port = port_arg & 0xff;
    irq_flags = 0;
    dp_tx_aux_read_byte(port, AUX_CMD_READ, AUX_ADDR_0x201, &irq_flags);

    if ((irq_flags & BYTE_0x201_BIT2) != 0) {
        dp_tx_aux_write_byte(port, AUX_CMD_WRITE, AUX_ADDR_0x201, BYTE_0x201_BIT2);

        if ((dp_tx_aux_read_byte(port, AUX_CMD_READ, AUX_ADDR_0x68029, &status) & 0xff) == 0) {
            if ((status & 4) != 0)
                found = 1;
            if ((status & 8) != 0)
                found = 1;
        }

        if ((dp_tx_aux_read_byte(port, AUX_CMD_READ, AUX_ADDR_0x69493, &status) & 0xff) == 0) {
            if ((status & 8) != 0)
                found = 1;
            if ((status & 0x10) != 0)
                found = 1;
        }
    }

    return found;
}
