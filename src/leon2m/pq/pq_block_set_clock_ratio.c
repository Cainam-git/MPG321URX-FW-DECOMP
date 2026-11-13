/* pq_block_set_clock_ratio  (FUN_a0105790)
 *
 * Compute a 16-bit ratio for a channel's block and write it.
 * Name basis: descriptive - registers 0x62 and 0x6F; used when a channel's port is switched on
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0105790 @ 0xa0105790-0xa0105910 (384 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: pq_block_read16 declared with an int result (htotal is extended where it is used); reg77 is an
 * unsigned int (the lduh value is shifted without a new extension); reg62_value is an unsigned short. Both
 * divisions of the 64-bit product go through __udivdi3 (__udivdi3); the low 32 bits are kept.
 */

/* Registers of a picture block (names as in panel_output_setup_channel_timing). */
#define BLK_HTOTAL         0x5e
#define BLK_ROW_0X30_SUM   0x62
#define BLK_ROW_0X30_SUM_2 0x6f
#define BLK_REG_88         0x88         /* bit 0 must be set, else nothing is written */
#define BLK_REG_BE         0xbe

#define PQ_PORT_BLOCKS     4            /* picture blocks 0..3 have an entry in panel_output_config_record */
#define HZ_PER_MHZ         1000000

/* The two per-block arrays of the output configuration record read here. */
struct panel_output_config {
    unsigned char pad00[0x15];
    unsigned char block_reg7c_high[4];  /* +0x15: bits 4..7 of register 0x7C of picture blocks 0..3 */
    unsigned char byte_0x19;
    unsigned short block_reg77[4];      /* +0x1A: register 0x77 (bits 0..14) of picture blocks 0..3 */
};
/* The channel's input timing (channel record +6); only the halfword at +8 is read here. */
struct input_timing { unsigned char pad0[8]; unsigned short half_0x8; };
/* The channel's output timing (channel record +0x48), passed by value as five doublewords. */
struct output_timing { unsigned long long dword_0x0, dword_0x8, dword_0x10, pixel_clock, dword_0x20; };
extern struct panel_output_config panel_output_config_record;
extern unsigned char pq_block_read8(unsigned char block, unsigned char reg);
extern int pq_block_read16(unsigned char block, unsigned char reg);
extern void pq_block_write16(unsigned char block, unsigned char reg, unsigned short value);

/*
 * Compute a 16-bit value for a picture block from the channel's timing and write it to the block's registers
 * 0x62 and 0x6F, then write 1 to register 0xBE.
 *
 *   block    the channel's port, used as the picture block number
 *   divisor  halfword +0xE of the port entry that matches the port's signal code (1 when there is none)
 *   in       the channel's input timing (a copy); its halfword +8 is used
 *   out      the channel's output timing; its pixel clock (Hz) is used
 *
 * Nothing happens unless bit 0 of block register 0x88 is set. For blocks 0..3 the two values saved in
 * panel_output_config_record (register 0x7C bits 4..7 and register 0x77) take part, for other blocks 0:
 *
 *   value = (reg7c_high * in.half_0x8 + reg77 * 8) * (pixel clock in MHz) / divisor / block htotal
 *
 * plus 1 for every block except block 1, and at least 3 for block 0 and at least 2 for the others.
 *
 * Only caller: sys_enable_channel_port, when it switches a channel's port on.
 */
void pq_block_set_clock_ratio(unsigned char block, unsigned short divisor, struct input_timing *in, struct output_timing out)
{
    unsigned short in_half_0x8, htotal, reg62_value;
    unsigned char reg7c_high;
    unsigned int reg77;
    unsigned int product, scaled;

    if (!(pq_block_read8(block, BLK_REG_88) & 1))
        return;
    in_half_0x8 = in->half_0x8;
    htotal = pq_block_read16(block, BLK_HTOTAL);
    reg7c_high = 0;
    reg77 = 0;
    if (block < PQ_PORT_BLOCKS) {
        reg7c_high = panel_output_config_record.block_reg7c_high[block];
        reg77 = panel_output_config_record.block_reg77[block];
    }
    product = reg7c_high * in_half_0x8 + reg77 * 8;
    scaled = (unsigned long long)product * (out.pixel_clock / HZ_PER_MHZ) / divisor;
    /* Block 1 takes the quotient as it is; every other block rounds up by one. */
    if (block == 1)
        reg62_value = scaled / htotal;
    else
        reg62_value = scaled / htotal + 1;
    if (block == 0) {
        if (reg62_value < 3)
            reg62_value = 3;
    } else {
        if (reg62_value < 2)
            reg62_value = 2;
    }
    pq_block_write16(block, BLK_ROW_0X30_SUM, reg62_value);
    pq_block_write16(block, BLK_ROW_0X30_SUM_2, reg62_value);
    pq_block_write16(block, BLK_REG_BE, 1);
}
