/* sys_get_active_port_code  (FUN_a012fc20)
 *
 * Return the port code (port record byte +0xA) of the active channel's port, or 0xFF.
 * Returns: port code or 0xFF
 * Name basis: derived - byte 0x0A of the port record of channel sys_source_b1_block
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012fc20 @ 0xa012fc20 (-mcpu=v8 -O3 -g)
 */
/* Channel record, word 0 only (0x78 bytes in all). */
struct channel_record { unsigned int bits_16_31 : 16, port : 4, bits_0_11 : 12; unsigned char p04[0x74]; };
/* Port record (0x2a bytes): only the port code at +0xA is named here. */
struct port_record { unsigned char p00[0x0a]; unsigned char port_code; unsigned char rest[0x2a - 0x0b]; };
extern struct channel_record channel_records[];
extern struct port_record port_records[];
extern unsigned char sys_source_b1_block;       /* index of the channel behind the routed port code 0xB1; 0xFF = none */

/*
 * Return the port code (port record byte +0xA) of the port of channel sys_source_b1_block, or 0xFF when
 * sys_source_b1_block is 0xFF.
 */
unsigned char sys_get_active_port_code(void)
{
    unsigned char code;

    if (sys_source_b1_block == 0xff)
        code = 0xff;
    else
        code = port_records[channel_records[sys_source_b1_block].port].port_code;
    return code;
}
