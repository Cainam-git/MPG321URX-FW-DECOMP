/* sys_channel_fill_size_fields  (FUN_a013bfa8)
 *
 * Fill halfwords +0x12..+0x2C of a port's channel record from its port record and input block.
 * Note: Port record +0x16 / +0x18 (the second doubled on status bit 2) and input block registers 0x12 and
 *   0x0C.
 * Name basis: descriptive - stores into the channel record found by sys_find_channel_by_port; called by
 *   sys_channel_apply_output_timing
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013bfa8 @ 0xa013bfa8-0xa013c040, flags -mcpu=v8 -O3 -g.
 * Source order of the stores reproduces the firmware's scheduling; no unusual constructs. The firmware's only
 * caller passes a second argument that this routine does not read.
 */
/* The channel record (0x78 bytes) found by port; only the halfwords written here are shown. */
struct Out {
    unsigned char pad0[0x12];
    unsigned short h12, h14, h16, h18, h1a, h1c, h1e, h20;
    unsigned char pad22[8];
    unsigned short h2a, h2c;
};
/* Port record (0x2A bytes): the halfwords at +0x16 and +0x18 are the two sizes copied below. */
struct Port {
    unsigned char pad0[0x16];
    unsigned short h16, h18;
    unsigned char pad1a[0x10];
};
extern struct Port port_records[];
extern struct Out *sys_find_channel_by_port(unsigned char port);
extern unsigned char input_block_get_status_bit2(unsigned char port);
extern unsigned short input_block_get_capture_reg12(unsigned char port);
extern unsigned short input_block_get_reg0c_11bit(unsigned char port);

/*
 * Fill the halfwords +0x12..+0x2C of the channel record of `port` from the port record and from two registers of
 * the port's input block.
 *
 *   port  port number (also the number of the input block that is read)
 *
 * The port record's halfword +0x16 goes to +0x12 and +0x16 of the channel record, its halfword +0x18 to +0x14
 * and +0x18, doubled when the input block reports status bit 2. The block's register 0x12 (16 bits) gives
 * +0x1A and +0x1E (+0x2A repeats +0x1E); its register 0x0C (11 bits) gives +0x1C, +0x20 and +0x2C.
 * Called by sys_channel_apply_output_timing.
 */
void sys_channel_fill_size_fields(unsigned char port)
{
    struct Out *o;
    struct Port *p;
    unsigned short lines;
    unsigned short w;
    unsigned short t;

    o = sys_find_channel_by_port(port);
    p = &port_records[port];
    lines = p->h18;
    if (input_block_get_status_bit2(port))      /* status bit 2: the second size is doubled */
        lines = lines * 2;
    w = p->h16;
    o->h14 = lines;
    o->h18 = lines;
    o->h16 = w;
    o->h12 = w;
    o->h1a = input_block_get_capture_reg12(port);
    o->h1c = input_block_get_reg0c_11bit(port);
    o->h1e = input_block_get_capture_reg12(port);
    t = input_block_get_reg0c_11bit(port);
    o->h2a = o->h1e;
    o->h20 = t;
    o->h2c = t;
}
