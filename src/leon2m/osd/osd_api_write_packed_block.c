/* osd_api_write_packed_block  (FUN_a01461dc)
 *
 * Send a plain or run-length packed block to a menu layer's memory.
 * Name basis: derived - forwards to osd_ram_write_packed_block; command 0xA0, 0xB0, 0xC0 or 0xC1 chosen from
 *   the request
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01461dc, flags -mcpu=v8 -O3 -g.
 * The run-length flag is a _Bool local computed first (the firmware keeps it and masks it with 1 at the call). The
 * zero-initialised record m is built on the stack; the command stays 0 for a kind above 3.
 */
/* The block as the caller gives it. */
struct packed_block_request {
    unsigned short count;               /* number of data bytes (packed bytes when run-length coded) */
    unsigned char kind;                 /* 0..3 selects the command 0xA0, 0xB0, 0xC0 or 0xC1 */
    unsigned int address;
    unsigned int data;                  /* address of the data bytes */
};
/* The block as osd_ram_write_packed_block takes it (struct packed_block there). */
struct packed_block {
    unsigned short count;
    unsigned int command;
    unsigned int address;
    unsigned int data;
};
extern void osd_ram_write_packed_block(unsigned int run_length, struct packed_block *m, unsigned char layer);

/* Send a plain or run-length packed block to a menu layer's memory: builds the request with the command chosen by
 * kind (the same four codes osd_api_write_reg24_group uses) and calls osd_ram_write_packed_block.
 *   run_length: 1 = the data is run-length coded, any other value = plain
 *   p:          the block
 *   layer:      menu layer number
 * Called by ShowLogo (ShowLogo).
 */
void osd_api_write_packed_block(unsigned char run_length, struct packed_block_request *p, unsigned char layer)
{
    _Bool f = run_length == 1;
    struct packed_block m = {0};
    m.count = p->count;
    switch (p->kind) {
    case 0: m.command = 0xa0; break;
    case 1: m.command = 0xb0; break;
    case 2: m.command = 0xc0; break;
    case 3: m.command = 0xc1; break;
    }
    m.address = p->address;
    m.data = p->data;
    osd_ram_write_packed_block(f, &m, layer);
}
