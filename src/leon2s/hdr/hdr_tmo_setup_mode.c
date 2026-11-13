/* hdr_tmo_setup_mode  (FUN_a00d2678)
 *
 * Set the tone-mapping block up for a mode.
 * Name basis: descriptive - field writes to 0xD0013FE0 and others; table source by selector
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source form the exact build depends on: the 'b <= 0xef' and 'i != 0x400' arms come first (the firmware's
 * fall-through order); the high-nibble term '(b & 0xf) << 8' is not truncated to an unsigned char;
 * hdr_tmo_setup_steps_mode1 is declared as a symbol array.
 */
extern unsigned char hdr_tmo_setup_steps_mode1[];
extern void reg_write_bit_range(unsigned int *, unsigned int, unsigned int, unsigned int);
extern void reg_write_bit_field(unsigned int *, unsigned int, unsigned int, unsigned int);
extern unsigned int reg_read32(unsigned int);
extern void reg_write32(unsigned int, unsigned int);

#define TMO_REG_CONTROL      0xd0013fe0     /* bits 2..0 = 7 first; bits 18..8 = entry index */
#define TMO_REG_ENTRY        0xd0013fe8     /* value of entry index (indices 0..0x3ff) */
#define TMO_REG_LAST_ENTRY   0xd0013fec     /* bits 11..0 = value of entry 0x400; bits 31..30 end the load */
#define TMO_ENTRIES          0x400          /* entries 0..0x400 are written */
#define TMO_SUM_LIMIT        0xfff          /* the table stops adding once the sum reaches this */
#define TMO_BYTE_ESCAPE      0xef           /* a table byte above this starts a two-byte step */

/*
 * Load the first tone-mapping table into the register block at 0xD0013FE0..0xD0013FEC.
 *
 *   mode  1 = use the byte table hdr_tmo_setup_steps_mode1; any other value loads no table, so every entry
 *         is written as 0
 *   param_2  not used
 *
 * Returns 1. Called by hdr_init with mode 1.
 *
 * The table holds steps, not values: entry i is the running sum of the steps up to i. A step is one
 * byte; a byte above 0xEF is the high nibble of a 12-bit step (low nibble << 8) and the next byte its
 * low part. Steps are added only while the sum is below 0xFFF.
 * Order: set bits 2..0 of 0xD0013FE0 to 7. Then for the indices 0..0x400: write the index into bits 18..8
 * of 0xD0013FE0, add the next step, and write the sum to 0xD0013FE8 (index 0x400: into bits 11..0 of
 * 0xD0013FEC instead, as 0xFFF). Last, set bits 31..30 of 0xD0013FEC to 0 and then to 3.
 */
int hdr_tmo_setup_mode(int mode, unsigned char param_2)
{
    unsigned int v;
    unsigned char *steps;
    unsigned int sum;    /* running sum */
    unsigned int pos;    /* read position in the table */
    unsigned int i;
    unsigned int b;      /* first byte of the step */

    v = 0;
    steps = 0;
    if (mode != 0) {
        if (mode == 1)
            steps = hdr_tmo_setup_steps_mode1;
    }
    v = reg_read32(TMO_REG_CONTROL);
    reg_write_bit_field(&v, 2, 0, 7);
    reg_write32(TMO_REG_CONTROL, v);
    sum = 0;
    pos = 0;
    i = 0;
    do {
        reg_write_bit_field(&v, 0x12, 8, i);
        reg_write32(TMO_REG_CONTROL, v);
        if (steps != 0 && sum < TMO_SUM_LIMIT) {
            b = steps[pos];
            if (b <= TMO_BYTE_ESCAPE) {
                sum += b;
            } else {
                pos++;
                sum += ((b & 0xf) << 8) + steps[pos];
            }
            pos++;
        }
        if (i != TMO_ENTRIES) {
            reg_write32(TMO_REG_ENTRY, sum);
        } else {
            v = reg_read32(TMO_REG_LAST_ENTRY);
            reg_write_bit_range(&v, 0xb, 0, 0xfff);
            reg_write32(TMO_REG_LAST_ENTRY, v);
        }
        i++;
    } while (i <= TMO_ENTRIES);
    v = reg_read32(TMO_REG_LAST_ENTRY);
    reg_write_bit_field(&v, 0x1f, 0x1e, 0);
    reg_write32(TMO_REG_LAST_ENTRY, v);
    reg_write_bit_field(&v, 0x1f, 0x1e, 3);
    reg_write32(TMO_REG_LAST_ENTRY, v);
    return 1;
}
