/* hdr_tmo_write_gain_table  (FUN_a00d2f20)
 *
 * Write the running sums of a byte table to the tone-mapping block.
 * Name basis: descriptive - table chosen by mode; entries 0..0x400 are written (0x401 entries)
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source form: case 3 is written out with the same body as the default (the firmware's jump table sends 2 to
 * the default block and 3 to its own copy); the switch is a jump table at 0xa00d2f00 (0x9f1c2f00 in the
 * code, which is linked 0xF10000 higher than it is loaded).
 */
extern unsigned int reg_read32(unsigned int);
extern void reg_write32(unsigned int, unsigned int);
extern void reg_write_bit_field(unsigned int *, unsigned int, unsigned int, unsigned int);
extern unsigned short hdr_tmo_gain_copy_start;
extern unsigned int hdr_tmo_gain_sums[];
extern const unsigned char hdr_tmo_gain_steps_mode1[];
extern const unsigned char hdr_tmo_gain_steps_mode6[];
extern const unsigned char hdr_tmo_gain_steps_mode5[];
extern const unsigned char hdr_tmo_gain_steps_mode4[];
extern const unsigned char hdr_tmo_gain_steps_default[];

#define TMO_REG_CONTROL      0xd0013fd0     /* bits 2..0 = 7, bits 5..4 = 0 first; bits 19..8 = entry index */
#define TMO_REG_ENTRY        0xd0013fd8     /* value of entry index (indices 0..0x3ff) */
#define TMO_REG_LAST_ENTRY   0xd0013fdc     /* bits 17..0 = value of entry 0x400 */
#define TMO_ENTRIES          0x400          /* entries 0..0x400 are written */
#define TMO_SUM_LIMIT        0x3fffe        /* steps are added only while the sum is not above this */
#define TMO_BYTE_ESCAPE      0xef           /* a table byte above this starts a two-byte step */
#define TMO_COPY_ENTRIES     500            /* window of entries kept in hdr_tmo_gain_sums */

/*
 * Write the gain table of a mode into the tone-mapping register block at 0xD0013FD0..0xD0013FDC and keep a
 * copy of a window of it in RAM.
 *
 *   mode  the curve mode (hdr_eotf_mode): 1, 3, 4, 5 and 6 choose a byte table and the start of the
 *         window; 7 and 8 write nothing; every other value uses the table of mode 3
 *
 * Returns 1. The HDR curve update calls it between ipc_request_8051_access and ipc_release_8051_access.
 *
 * Mode   table                       window start (hdr_tmo_gain_copy_start)
 *   1    hdr_tmo_gain_steps_mode1    0x10E
 *   3    hdr_tmo_gain_steps_default  0x10E (also the table of every unlisted mode)
 *   4    hdr_tmo_gain_steps_mode4    0x13B
 *   5    hdr_tmo_gain_steps_mode5    0x15B
 *   6    hdr_tmo_gain_steps_mode6    0x1A9
 *   7, 8 none                        0x10E
 * The tables hold steps, not values: entry i is the running sum of the steps up to i (a step is one byte;
 * a byte above 0xEF is the high nibble of a 12-bit step, low nibble << 8, and the next byte its low part;
 * steps are added only while the sum is not above 0x3FFFE).
 * Order: set bits 2..0 of 0xD0013FD0 to 7 and bits 5..4 to 0. Then for the indices 0..0x400: write the
 * index into bits 19..8 of 0xD0013FD0, add the next step, write the sum to 0xD0013FD8 (index 0x400: into
 * bits 17..0 of 0xD0013FDC), and for indices above the window start and below start + 500 also store the
 * sum in hdr_tmo_gain_sums[index - start] (so element 0 is not written).
 */
int hdr_tmo_write_gain_table(unsigned int mode)
{
    unsigned int v = 0;
    unsigned int w = 0;
    const unsigned char *tab;      /* step table of the mode */
    unsigned int sum, k, i;        /* running sum, read position in the table, entry index */
    unsigned char c;               /* first byte of the step */

    switch (mode) {
    case 1:
        hdr_tmo_gain_copy_start = 0x10e;
        tab = hdr_tmo_gain_steps_mode1;
        break;
    case 3:
        hdr_tmo_gain_copy_start = 0x10e;
        tab = hdr_tmo_gain_steps_default;
        break;
    case 4:
        hdr_tmo_gain_copy_start = 0x13b;
        tab = hdr_tmo_gain_steps_mode4;
        break;
    case 5:
        hdr_tmo_gain_copy_start = 0x15b;
        tab = hdr_tmo_gain_steps_mode5;
        break;
    case 6:
        hdr_tmo_gain_copy_start = 0x1a9;
        tab = hdr_tmo_gain_steps_mode6;
        break;
    case 7:
    case 8:
        hdr_tmo_gain_copy_start = 0x10e;
        return 1;
    default:
        hdr_tmo_gain_copy_start = 0x10e;
        tab = hdr_tmo_gain_steps_default;
        break;
    }
    /* modes 7 and 8 return above and write no table */
    v = reg_read32(TMO_REG_CONTROL);
    reg_write_bit_field(&v, 2, 0, 7);
    reg_write_bit_field(&v, 5, 4, 0);
    reg_write32(TMO_REG_CONTROL, v);
    sum = 0;
    k = 0;
    for (i = 0; i <= TMO_ENTRIES; i++) {
        reg_write_bit_field(&v, 0x13, 8, i);
        reg_write32(TMO_REG_CONTROL, v);
        if (sum <= TMO_SUM_LIMIT) {
            c = tab[k];
            if (c > TMO_BYTE_ESCAPE)
                sum += ((c & 0xf) << 8) + tab[++k];
            else
                sum += c;
            k++;
        }
        if (i != TMO_ENTRIES)
            reg_write32(TMO_REG_ENTRY, sum);
        else {
            w = reg_read32(TMO_REG_LAST_ENTRY);
            reg_write_bit_field(&w, 0x11, 0, sum);
            reg_write32(TMO_REG_LAST_ENTRY, w);
        }
        if (hdr_tmo_gain_copy_start < i && i < hdr_tmo_gain_copy_start + TMO_COPY_ENTRIES)
            hdr_tmo_gain_sums[i - hdr_tmo_gain_copy_start] = sum;
    }
    return 1;
}
