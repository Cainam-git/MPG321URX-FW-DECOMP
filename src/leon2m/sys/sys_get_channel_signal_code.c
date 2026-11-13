/* sys_get_channel_signal_code  (FUN_a012fc70)
 *
 * Return the signal code of a channel's input block; code 0xB1 gives another channel's port code.
 * Returns: code
 * Name basis: descriptive - input_block_get_signal_code of the channel's port field; code 0xB1 is replaced by
 *   port record byte +0xA of the port of channel sys_source_b1_block (0xFF when that is 0xFF)
 *
 * Matching notes
 * --------------
 * FUN_a012fc70 (leon2m 0xa012fc70-0xa012fcf4, 132 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: one unsigned char result variable; the 0xb1 branch uses an int set to -1.
 */
/* Channel record, word 0 only (0x78 bytes in all). */
struct channel_record { unsigned int word0; unsigned char p04[0x74]; };
/* Port record (0x2a bytes): only the port code at +0xA is named here. */
struct port_record { unsigned char p0[0xa]; unsigned char port_code; unsigned char pb[0x1f]; };
extern struct channel_record channel_records[4];
extern struct port_record port_records[];
extern unsigned char sys_source_b1_block;       /* index of the channel behind the routed port code 0xB1; 0xFF = none */
extern unsigned char input_block_get_signal_code(unsigned char block);

#define PORT_CODE_ROUTED 0xb1                   /* signal code that stands for the port of another channel */

/*
 * Return the signal code of the input block named by the port field (bits 12..15 of word 0) of channel ch.
 * When that code is PORT_CODE_ROUTED (0xB1), return instead the port code of the port of channel
 * sys_source_b1_block, or 0xFF when sys_source_b1_block is 0xFF.
 * Called by ipc_8051_build_wake_table and input_port_list_build.
 */
unsigned char sys_get_channel_signal_code(unsigned char ch)
{
    unsigned char code = input_block_get_signal_code((channel_records[ch].word0 >> 12) & 0xf);

    if (code == PORT_CODE_ROUTED) {
        int routed = -1;

        if (sys_source_b1_block != 0xff)
            routed = port_records[(channel_records[sys_source_b1_block].word0 >> 12) & 0xf].port_code;
        code = routed;
    }
    return code;
}
