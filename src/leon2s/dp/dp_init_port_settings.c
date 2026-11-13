/* dp_init_port_settings  (FUN_a00ab8b8)
 *
 * Load the default settings into a DP port record.
 *   port: DP port
 * Name basis: derived - bytes +0x110..+0x129 (e.g. +0x110 = 3, +0x118 = 0x1B, +0x120 = 600); caller
 *   input_init_receivers
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ab8b8 @ 0xa00ab8b8, flags -mcpu=v8 -Os -g. Leaf.
 * Source form: the stores follow the order below, with byte 0x117 after the halfword at 0x120 and byte 0x128 last
 * (the order the compiler emitted them in; five neighbouring positions of the 0x117 store give the same code).
 */
/* The settings part of a DP port record (bytes 0x110..0x129); the other bytes are not touched here. */
struct dp_input_record {
    unsigned char before_0x110[0x110];
    unsigned char byte_0x110;                   /* default 3: selects the value of register 0x3B1 and 0x3B3 */
    unsigned char byte_0x111;                   /* default 2: selects the value of register 0x3B2 */
    unsigned char byte_0x112;                   /* default 0: see dp_get_port_setting_112 */
    unsigned char byte_0x113;
    unsigned char byte_0x114;
    unsigned char byte_0x115;                   /* default 1 */
    unsigned char byte_0x116;                   /* default 1 */
    unsigned char byte_0x117;                   /* default 2 */
    unsigned char byte_0x118;                   /* default 0x1B */
    unsigned char byte_0x119;
    unsigned char byte_0x11a;
    unsigned char byte_0x11b;
    unsigned char byte_0x11c;
    unsigned char byte_0x11d;
    unsigned char byte_0x11e;
    unsigned char byte_0x11f;
    unsigned short rate_divider;                /* +0x120: default 600 (the divider of dp_write_rate_divider_regs) */
    unsigned char pad_0x122[0x123 - 0x122];
    unsigned char byte_0x123;
    unsigned char byte_0x124;
    unsigned char byte_0x125;
    unsigned char pad_0x126[0x128 - 0x126];
    unsigned char byte_0x128;
    unsigned char byte_0x129;
    unsigned char after_0x129[300 - 0x12a];
};
extern struct dp_input_record dp_input_records[];   /* one 300-byte record per port */

/*
 * Load the default settings into bytes 0x110..0x129 of the record of a DP port: the non-zero defaults are
 * listed at the fields above, every other byte of the range (except 0x122 and 0x126, 0x127) is cleared.
 * Called for ports 0 and 1 by input_init_receivers.
 *   port: DP port, index of the record
 */
void dp_init_port_settings(unsigned char port)
{
    struct dp_input_record *r = dp_input_records + port;

    r->byte_0x110 = 3;
    r->byte_0x111 = 2;
    r->byte_0x112 = 0;
    r->byte_0x113 = 0;
    r->byte_0x114 = 0;
    r->byte_0x115 = 1;
    r->byte_0x116 = 1;
    r->byte_0x118 = 0x1b;
    r->byte_0x119 = 0;
    r->byte_0x11a = 0;
    r->byte_0x11b = 0;
    r->byte_0x11c = 0;
    r->byte_0x11d = 0;
    r->byte_0x11e = 0;
    r->byte_0x11f = 0;
    r->rate_divider = 600;
    r->byte_0x117 = 2;
    r->byte_0x123 = 0;
    r->byte_0x124 = 0;
    r->byte_0x125 = 0;
    r->byte_0x129 = 0;
    r->byte_0x128 = 0;
}
