/* osd_api_write_block  (FUN_a01461a8)
 *
 * Send a block of bytes to a menu layer's memory.
 * Name basis: derived - forwards to osd_ram_write_block; copies the request record first
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01461a8, flags -mcpu=v8 -O2 -g.
 * The request is copied field by field in ascending order (count, address, data); GCC then loads the data word
 * first, as the firmware does. The callee takes (struct *, layer).
 */
/* A block of bytes for a menu layer's memory; the same layout as osd_ram_write_block's struct block_request. */
struct block_request {
    unsigned short count;               /* number of bytes */
    unsigned short address;             /* address in the layer's memory */
    unsigned int data;                  /* address of the bytes */
};
extern void osd_ram_write_block(struct block_request *, unsigned char);

/* Send a block of bytes to a menu layer's memory: copies the request to the stack and calls osd_ram_write_block.
 *   src:   the block request
 *   layer: menu layer number
 * Called by ShowLogo (ShowLogo).
 */
void osd_api_write_block(struct block_request *src, unsigned char layer)
{
    struct block_request m;
    m.count = src->count;
    m.address = src->address;
    m.data = src->data;
    osd_ram_write_block(&m, layer);
}
