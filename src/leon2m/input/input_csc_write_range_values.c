/* input_csc_write_range_values  (FUN_a01006e4)
 *
 * Write the value record for the current colour format to a block.
 * Name basis: descriptive - one of six records, chosen by the format code at 0xA8027A75
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01006e4 @ 0xa01006e4-0xa0100990 (684 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: the six records are initialised locals declared in stack order (cur first) and cur is assigned by
 * structure copy in each case; the switch compiles to a jump table of 40 entries; one complete
 * pq_block_update_bits call per arm of the flag test.
 */
/* One set of values for the picture block: five 16-bit registers and one flag bit. */
struct csc_value_record {
    unsigned short reg3, reg5, reg7, reg9, reg1;    /* written to picture block registers 3, 5, 7, 9 and 1, each << 2 */
    unsigned char reg2_bit6;                        /* 1: bit 6 of picture block register 2 is set, else cleared */
};
extern unsigned char input_csc_format_code;
extern unsigned int input_csc_selector;
extern void pq_block_write16(unsigned char blk, unsigned char reg, unsigned short val);
extern void pq_block_update_bits(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);
extern void pq_block_write8(unsigned char blk, unsigned char reg, unsigned char val);

/*
 * Write the value set that belongs to the current colour format code into a picture block.
 *
 *   port  picture block to write (input_csc_setup calls this for ports 0..3 only, the one caller)
 *
 * The format code (input_csc_format_code) picks one of six fixed value sets:
 *   0, 1, 26, 27              set 2 (the only one with reg2_bit6 = 1)
 *   8..13                     set 0
 *   14..19                    set 4
 *   20..25                    set 3
 *   28..39                    set 2 for port 0, set 5 for the other ports
 *   any other code            set 1
 * The five values go to block registers 3, 5, 7, 9 and 1 (each shifted left by 2) and the flag to bit 6 of
 * register 2. Register 0xb is then cleared in bit 0 when the selector (input_csc_selector) is 2 or the format
 * code is 0x2a, and otherwise set to 0xd. What the values mean for the picture is not shown by the code.
 */
void input_csc_write_range_values(unsigned char port)
{
    struct csc_value_record cur;
    struct csc_value_record set0 = {0x629, 0x1d6, 0xbb, 0x744, 0x400, 0};
    struct csc_value_record set1 = {0x57c, 0x2cb, 0x158, 0x6ee, 0x400, 0};
    struct csc_value_record set2 = {0x662, 0x341, 0x190, 0x812, 0x4a8, 1};
    struct csc_value_record set3 = {0x64d, 0x1df, 0xc0, 0x76c, 0x400, 0};
    struct csc_value_record set4 = {0x59c, 0x2db, 0x160, 0x717, 0x400, 0};
    struct csc_value_record set5 = {0x5e6, 0x249, 0xa9, 0x787, 0x400, 0};

    switch (input_csc_format_code) {
    case 0: case 1: case 26: case 27:
        cur = set2;
        break;
    case 8: case 9: case 10: case 11: case 12: case 13:
        cur = set0;
        break;
    case 14: case 15: case 16: case 17: case 18: case 19:
        cur = set4;
        break;
    case 20: case 21: case 22: case 23: case 24: case 25:
        cur = set3;
        break;
    case 28: case 29: case 30: case 31: case 32: case 33:
    case 34: case 35: case 36: case 37: case 38: case 39:
        if (port == 0)
            cur = set2;
        else
            cur = set5;
        break;
    default:
        cur = set1;
        break;
    }
    pq_block_write16(port, 3, cur.reg3 << 2);
    pq_block_write16(port, 5, cur.reg5 << 2);
    pq_block_write16(port, 7, cur.reg7 << 2);
    pq_block_write16(port, 9, cur.reg9 << 2);
    pq_block_write16(port, 1, cur.reg1 << 2);
    if (cur.reg2_bit6 == 1)
        pq_block_update_bits(port, 2, 0x40, 1);
    else
        pq_block_update_bits(port, 2, 0x40, 0);
    if (input_csc_selector == 2 || input_csc_format_code == 0x2a)
        pq_block_update_bits(port, 0xb, 1, 0);
    else
        pq_block_write8(port, 0xb, 0xd);
}
