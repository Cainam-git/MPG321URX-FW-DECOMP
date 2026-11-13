/* sys_enable_channel_port  (FUN_a01312d4)
 *
 * Switch the port of a channel on or off and set its clock when switching on.
 * Name basis: derived - port enable, then the port's clock record and divider
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01312d4 @ 0xa01312d4-0xa013143c, flags -mcpu=v8 -O3 -g.
 * Source form: sys_get_channel_signal_code (sys_get_channel_signal_code) and sys_get_active_port_code (sys_get_active_port_code) are copied
 * here as static functions and inlined. The result of the first call, sys_get_channel_signal_code(ch), is
 * not used: the firmware keeps only its input_block_get_signal_code call (0xa01312fc), and the 0xb1 branch of the
 * inlined copy leaves no instructions. With a bare input_block_get_signal_code call instead, the compiler keeps
 * the record's base and index in two more registers across the call; with the inlined function the later reads
 * go through the pointer (%l4) as in the firmware, and the first load is base first ('ld [%o5 + %g1]' at
 * 0xa01312f0).
 */
#define PORT_CODE_ROUTED 0xb1           /* signal code of a block whose source is chosen through sys_source_b1_block */
#define NO_CHANNEL       0xff           /* sys_source_b1_block: none */

/* 0x3c bytes of the channel record at +6 (the input timing). */
struct Rec { unsigned char p0[8]; unsigned short h8; unsigned char p0a[0x3c - 0x0a]; };
/* The five doublewords of the channel record at +0x48 (the output timing). */
struct Clk { unsigned long long d0, d8, d10, d18, d20; };
struct Chan {
    union { unsigned int w; struct { unsigned int f16 : 16, port : 4, f0 : 12; } b; } u;   /* port = bits 12..15 */
    unsigned short h04;
    struct Rec rec;
    struct Clk clk;
    unsigned char p70[8];
};
struct Port { unsigned char p00[0x0a]; unsigned char port_code; unsigned char rest[0x2a - 0x0b]; };
/* Port entry (0x12 bytes): h0e is passed on as the second argument of pq_block_set_clock_ratio. */
struct Rec12 { unsigned char p0[0x0e]; unsigned short h0e; unsigned char b10, b11; };
extern struct Chan channel_records[];
extern struct Port port_records[];
extern struct Rec12 port_entries[];
extern unsigned char sys_source_b1_block;
extern void *memcpy(void *dst, const void *src, unsigned int n) __asm__("FUN_a013c910");
extern unsigned char input_block_get_signal_code(unsigned char);
extern void input_block_enable(unsigned char, unsigned char);
extern unsigned char input_port_id_to_entry_index(unsigned char);
extern void pq_block_set_clock_ratio(unsigned char ch, unsigned short div, struct Rec *r, struct Clk c);

/* Signal code of the block a channel uses; the code 0xb1 is replaced by the port code of the channel that
   sys_source_b1_block names (0xff when there is none). */
static unsigned char sys_get_channel_signal_code(unsigned char c)
{
    unsigned char v = input_block_get_signal_code(channel_records[c].u.b.port);

    if (v == PORT_CODE_ROUTED) {
        int r = -1;

        if (sys_source_b1_block != NO_CHANNEL)
            r = port_records[channel_records[sys_source_b1_block].u.b.port].port_code;
        v = r;
    }
    return v;
}

/* Port code of the port of channel sys_source_b1_block, or 0xff when there is none. */
static unsigned char sys_get_active_port_code(void)
{
    unsigned char r;

    if (sys_source_b1_block == NO_CHANNEL)
        r = 0xff;
    else
        r = port_records[channel_records[sys_source_b1_block].u.b.port].port_code;
    return r;
}

/*
 * Switch the input block of channel ch's port on (on != 0) or off, and when switching on load its clock
 * ratio.
 *
 * Switching on: look up the signal code of the port's block (0xb1 stands for the port code of the channel that
 * sys_source_b1_block names), find that code's index in the port entries, and take the halfword at +0xe of
 * that entry as the ratio argument; an index above 6 gives 1. Then pq_block_set_clock_ratio gets the port, that
 * value, a copy of the channel record's 0x3c bytes at +6 and the five doublewords of its output timing (+0x48).
 * Switching off only switches the block off.
 * Called by sys_api_enable_channel_port and GlobalModeHandler (the only two callers).
 */
void sys_enable_channel_port(unsigned char ch, unsigned char on)
{
    struct Chan *c = &channel_records[ch];
    struct Rec rec;
    unsigned char t, j;
    unsigned short h = 1;

    t = sys_get_channel_signal_code(ch);   /* result unused, see the matching notes */
    if (on) {
        input_block_enable(c->u.b.port, 1);
        t = input_block_get_signal_code(c->u.b.port);
        if (t == PORT_CODE_ROUTED)
            t = sys_get_active_port_code();
        j = input_port_id_to_entry_index(t);
        if (j <= 6)             /* the port entries are 7 */
            h = port_entries[j].h0e;
        rec = c->rec;
        pq_block_set_clock_ratio(c->u.b.port, h, &rec, c->clk);
    } else
        input_block_enable(c->u.b.port, 0);
}
