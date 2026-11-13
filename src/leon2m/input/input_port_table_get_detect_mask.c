/* input_port_table_get_detect_mask  (FUN_a01252fc)
 *
 * Return the pin mask of the detect pin of an input's entry in the port table.
 * Returns: byte
 * Name basis: descriptive - byte +0x0C of the 22-byte ROM entries at 0x1A42A8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01252fc @ 0xa01252fc, flags -mcpu=v8 -O2 -g.
 * One byte load from the entry; the index is masked with 0xff.
 */
/* One entry of the port table in ROM (0x16 bytes); see docs/DATA.md. */
struct port_table_entry {
    unsigned char code;                 /* +0x00 */
    unsigned char type;                 /* +0x01 */
    unsigned char bus_id;               /* +0x02 */
    unsigned char byte_0x03;
    unsigned short edid_size;           /* +0x04 */
    unsigned short edid_base;           /* +0x06 */
    unsigned char byte_0x08, byte_0x09, byte_0x0a;
    unsigned char detect_port, detect_mask, detect_level;       /* +0x0B..+0x0D */
    unsigned char control_port, control_mask, control_level;    /* +0x0E..+0x10 */
    unsigned char byte_0x11;
    unsigned char byte_0x12, byte_0x13, byte_0x14, byte_0x15;
};
extern const struct port_table_entry port_table[];

/*
 * Return the pin mask of the detect pin (+0x0C) of an input's entry in the port table.
 *
 *   index  entry of the port table (low byte used)
 */
unsigned char input_port_table_get_detect_mask(unsigned int index)
{
    return port_table[index & 0xff].detect_mask;
}
