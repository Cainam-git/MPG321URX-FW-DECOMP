/* input_load_port_flag_bits  (FUN_a006d4e0)
 *
 * Copy one per-port flag bit from the command byte into each port record.
 * Name basis: descriptive - bit i of the byte set by the command dispatcher -> bit 7 of record halfword +0x12,
 *   copied to the link table
 *
 * Matching notes
 * --------------
 * leon2s FUN_a006d4e0 @ 0xa006d4e0, flags -mcpu=v8 -Os -g.
 * Source form: the record address is integer arithmetic, (struct *)(port * sizeof + table) with
 * table = (unsigned int)input_port_records (the firmware adds the offset to the base; &input_port_records[port]
 * swaps the add operands). The record is 20 bytes; the bits are shifted as a signed int.
 */

/* Port record: only the halfword at +0x12 is used here; bit 7 of it is the flag copied from the command byte. */
struct port_record { unsigned char before_flags[0x12]; unsigned short flags; };
extern struct port_record input_port_records[];
extern unsigned char input_port_flag_bits;

#define PORT_FLAG_COMMAND_BIT 0x80      /* bit 7 of the record's halfword +0x12 */

/*
 * Bit n of input_port_flag_bits (set by the command dispatcher) is copied into bit 7 of the halfword at +0x12
 * of port record n, for the records 0..8.
 */
void input_load_port_flag_bits(void)
{
    unsigned int table = (unsigned int)input_port_records;
    int bits = input_port_flag_bits;
    unsigned char port;

    for (port = 0; port <= 8; port++)
    {
        struct port_record *rec = (struct port_record *)(port * sizeof(struct port_record) + table);
        rec->flags = (rec->flags & ~PORT_FLAG_COMMAND_BIT) | (((bits >> port) & 1) << 7);
    }
}
