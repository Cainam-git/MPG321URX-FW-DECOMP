/* sys_map_port_signal_code  (FUN_a013143c)
 *
 * Translate a port's signal code through the source code table into two port bytes.
 * Name basis: descriptive - port bytes 0x0C and 0x0D; 0xFF for selector 0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013143c @ 0xa013143c-0xa0131510 (53 words), flags -mcpu=v8 -O3 -g.
 * Exact form: the table byte is read through a small static helper (inlined; it sets the compare operand order);
 * the 0xb1 replacement goes through an int local (-1 for 0xff).
 */
/* Port record (0x2a bytes): the port code at +0xA, the block at +0xB, and the two result bytes +0xC and +0xD. */
struct port_record { unsigned char pad[0xa]; unsigned char port_code, block, source_index, result_index; unsigned char rest[0x1c]; };
/* Channel record, word 0 only (0x78 bytes in all). */
struct channel_record { unsigned int bits_16_31 : 16, port : 4, bits_0_11 : 12; unsigned char rest[0x74]; };
extern struct port_record port_records[];
extern struct channel_record channel_records[];
extern unsigned char sys_source_b1_block;       /* index of the channel behind the routed port code 0xB1; 0xFF = none */
extern const unsigned char input_source_code_table[];   /* ROM table of four codes {0x61, 0x51, 0x81, 0x71} */
extern unsigned char input_block_get_signal_code(unsigned char block);

#define PORT_CODE_ROUTED 0xb1                   /* signal code that stands for the port of another channel */
#define PORT_NONE 0xff

static unsigned char source_code_at(unsigned char index)
{
    return input_source_code_table[index];
}

/*
 * Fill bytes +0xC and +0xD of port record `port`.
 *
 *   enable  0: byte +0xD becomes 0xFF and nothing else is done
 *   port    index of the port record
 *
 * Otherwise the signal code of the input block in byte +0xB is read. If it is 0xB1 it is replaced by the port
 * code of the channel sys_source_b1_block (0xFF when that is 0xFF). When the code is one of the four codes of
 * input_source_code_table, its index goes to byte +0xC. Byte +0xC is then copied to byte +0xD.
 * Caller: sys_mode_notify_channel0_port.
 */
void sys_map_port_signal_code(unsigned char enable, unsigned char port)
{
    struct port_record *record = &port_records[port];
    unsigned char code, i;
    int routed;

    if (enable == 0) {
        record->result_index = PORT_NONE;
        return;
    }
    code = input_block_get_signal_code(record->block);
    if (code == PORT_CODE_ROUTED) {
        if (sys_source_b1_block == 0xff)
            routed = -1;
        else
            routed = port_records[channel_records[sys_source_b1_block].port].port_code;
        code = routed;
    }
    for (i = 0; i <= 3; i++)
        if (code == source_code_at(i)) {
            record->source_index = i;
            break;
        }
    record->result_index = record->source_index;
}
