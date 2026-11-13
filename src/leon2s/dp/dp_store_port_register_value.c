/* dp_store_port_register_value  (FUN_a00b04a8)
 *
 * Read the 16-bit registers 0x94, 0x96, 0x98 and 0x9A of a port and store them in its record.
 * Name basis: descriptive - value from a register routine
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b04a8 @ 0xa00b04a8 (-mcpu=v8 -Os -g)
 * Source form: the table is an array of halfwords, so the port's record starts at halfword port * 150 and the
 * four stores use the halfword indexes 0x80, 0x84, 0x83 and 0x87.
 */
extern int dp_reg_read16(int, int);
extern unsigned short dp_input_records[];

#define DP_INPUT_RECORD_HALFWORDS 150   /* 300 bytes per port record, counted in halfwords */

/*
 * Read the 16-bit registers 0x94, 0x96, 0x98 and 0x9A of the port and store them in its DP input record:
 *   register 0x94 -> halfword at +0x100
 *   register 0x96 -> halfword at +0x108
 *   register 0x98 -> halfword at +0x106 (low 15 bits only)
 *   register 0x9A -> halfword at +0x10E (low 15 bits only)
 *   port: DP receiver (0 or 1)
 * Called from dp_run_link_state.
 */
void dp_store_port_register_value(unsigned int port)
{
    unsigned int masked_port;
    unsigned int value;
    unsigned short *record;

    masked_port = port & 0xff;
    record = &dp_input_records[masked_port * DP_INPUT_RECORD_HALFWORDS];
    value = dp_reg_read16(masked_port, 0x94);
    record[0x80] = (unsigned short)value;                /* +0x100 */
    value = dp_reg_read16(masked_port, 0x96);
    record[0x84] = (unsigned short)value;                /* +0x108 */
    value = dp_reg_read16(masked_port, 0x98);
    record[0x83] = (unsigned short)(value & 0x7fff);     /* +0x106 */
    value = dp_reg_read16(masked_port, 0x9a);
    record[0x87] = (unsigned short)(value & 0x7fff);     /* +0x10e */
}
