/* dp_is_port_ready_for_service  (FUN_a00ad3e0)
 *
 * Return 1 when the port's bit in 0xCF0132C0 is set or its record byte 0x11F and the pulse flag are 1.
 * Returns: 0 or 1
 * Name basis: descriptive - bit 6 (block 1) or bit 7 (block 0) of 0xCF0132C0, or byte 0x11F of the port record
 *   with dp_hpd_pulse_flag
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ad3e0 @ 0xa00ad3e0, flags -mcpu=v8 -Os -g.
 * Source form: the record byte is read through a byte pointer, port * 300 + 0xA807DC18.
 */
extern int dp_map_port(int);
#define REG_CF0132C0 (*(volatile unsigned int *)0xcf0132c0)
extern unsigned char dp_hpd_pulse_flag;         /* cleared by dp_pulse_hpd_block */

/*
 * Return 1 in either of these cases, else 0:
 *   - dp_map_port(port) is 1 and bit 6 of register 0xCF0132C0 is set;
 *   - dp_map_port(port) is 0 and bit 7 of register 0xCF0132C0 is set;
 *   - byte 0x11F of the port's 300-byte record is 1 and dp_hpd_pulse_flag is 1.
 * Callers: dp_update_pending_bits, dp_setup_service_block, ipc_dispatch_command.
 *   port: DP port
 */
int dp_is_port_ready_for_service(int port)
{
    unsigned int block;
    unsigned char *record;

    port &= 0xff;
    block = dp_map_port(port) & 0xff;

    if (block == 1) {
        if (REG_CF0132C0 & 0x40)
            return 1;
    } else if (block == 0) {
        if (REG_CF0132C0 & 0x80)
            return 1;
    }

    record = (unsigned char *)(port * 300 + 0xa807dc18);
    if (record[0x11f] == 1 && dp_hpd_pulse_flag == 1)
        return 1;

    return 0;
}
