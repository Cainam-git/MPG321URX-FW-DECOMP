/* sys_path_block_set_record  (FUN_a011f364)
 *
 * Write a mode record to registers 4..8 of a signal path block, or of both.
 * Name basis: descriptive - fields of the ROM mode table at 0x1A6CB4
 *
 * Matching notes
 * --------------
 * FUN_a011f364, flags -mcpu=v8 -O3 -g.
 * Source form: the byte and 16-bit write helpers are the static helpers of sys_path_block_set_reg48_bit5 and
 * sys_path_block_set_reg36, inlined at -O3.
 */
#define R(a) (*(volatile unsigned int *)(a))
/* Register `a` of the register area: address 0xCF000000 + 4 * a. */
#define RB(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern const unsigned short sys_path_block_bases[2];     /* register base of each of the two path blocks */

#define PATH_BLOCK_BOTH    2            /* block argument that stands for both path blocks; above 2 nothing is written */
#define PATH_ACCESS_REG    0xcf011428   /* bits 0..1 are set before every path block register access */

/* Write one byte to register `reg` of path block `block` (or of both). */
static void write_byte(unsigned int block, unsigned char reg, unsigned char value)
{
    unsigned char i;

    R(PATH_ACCESS_REG) |= 3;
    if (block == PATH_BLOCK_BOTH) {
        for (i = 0; i < 2; i++)
            RB(sys_path_block_bases[i] + reg) = value;
    } else if (block < 2) {
        RB(sys_path_block_bases[block] + reg) = value;
    }
}

/* Write a 16-bit value to registers `reg` (low byte) and `reg` + 1 (high byte) of path block `block` (or of both). */
static void write_halfword(unsigned int block, unsigned char reg, unsigned short value)
{
    unsigned char i;

    R(PATH_ACCESS_REG) |= 3;
    if (block == PATH_BLOCK_BOTH) {
        for (i = 0; i < 2; i++) {
            RB(sys_path_block_bases[i] + reg) = (unsigned char)value;
            RB(sys_path_block_bases[i] + reg + 1) = (unsigned char)(value >> 8);
        }
    } else if (block < 2) {
        RB(sys_path_block_bases[block] + reg) = (unsigned char)value;
        RB(sys_path_block_bases[block] + reg + 1) = (unsigned char)(value >> 8);
    }
}

/* A six-byte record of the ROM tables (offsets in bytes). */
struct path_block_record {
    unsigned char byte_0x0;
    unsigned char byte_0x1;
    unsigned short half_0x2;        /* only the low 12 bits are used */
    unsigned char byte_0x4;         /* only the low 4 bits are used */
    unsigned char byte_0x5;         /* only the low 4 bits are used */
};

/*
 * Write a record to registers 4..8 of path block `block` (0 or 1, or PATH_BLOCK_BOTH for both).
 *
 * Register 4 gets byte 0, register 5 gets byte 1, register 6 gets the low nibble of byte 4 in its high half
 * and the low nibble of byte 5 in its low half, registers 7 and 8 get the low and high byte of the low 12 bits
 * of halfword 2.
 * Called by sys_set_channel_path_mode (with the mode record of the selected row).
 */
void sys_path_block_set_record(unsigned int block, struct path_block_record *record)
{
    write_byte(block, 4, record->byte_0x0);
    write_byte(block, 5, record->byte_0x1);
    write_byte(block, 6, ((record->byte_0x4 & 0xf) << 4) | (record->byte_0x5 & 0xf));
    write_halfword(block, 7, record->half_0x2 & 0xfff);
}
