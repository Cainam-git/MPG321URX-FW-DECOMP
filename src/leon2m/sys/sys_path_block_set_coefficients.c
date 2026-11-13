/* sys_path_block_set_coefficients  (FUN_a011f6a4)
 *
 * Write two coefficient records to a signal path block, or to both.
 * Name basis: descriptive - registers 0x10/0x30..0x32 and 0x11/0x33..0x35
 *
 * Matching notes
 * --------------
 * FUN_a011f6a4, flags -mcpu=v8 -O3 -g.
 * Source form: the byte and 16-bit write helpers are the static helpers of sys_path_block_set_reg48_bit5 and
 * sys_path_block_set_reg36.
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

/* A six-byte record of the ROM tables (offsets in bytes); see sys_path_block_set_record. */
struct path_block_record {
    unsigned char byte_0x0;
    unsigned char byte_0x1;
    unsigned short half_0x2;        /* only the low 12 bits are used */
    unsigned char byte_0x4;         /* only the low 4 bits are used */
    unsigned char byte_0x5;         /* only the low 4 bits are used */
};

#define COEF_A_FLAG 0x5000          /* ORed into the 16-bit value written for record a */
#define COEF_B_FLAG 0x4000          /* ORed into the 16-bit value written for record b */

/*
 * Write two records to a path block (0 or 1, or PATH_BLOCK_BOTH for both).
 *
 * Record a: register 0x10 gets byte 0; register 0x30 gets the low nibbles of bytes 4 (high half) and 5 (low
 * half); registers 0x31 and 0x32 get the low and high byte of (low 12 bits of halfword 2) | 0x5000.
 * Record b: register 0x11 gets the low 6 bits of byte 0; register 0x33 gets the nibbles of bytes 4 and 5 as
 * for a; registers 0x34 and 0x35 get the low and high byte of (low 12 bits of halfword 2) | 0x4000.
 * Called by sys_set_channel_path_mode (with the two coefficient records of the selected row).
 */
void sys_path_block_set_coefficients(unsigned int block, struct path_block_record *a, struct path_block_record *b)
{
    write_byte(block, 0x10, a->byte_0x0);
    write_byte(block, 0x30, ((a->byte_0x4 & 0xf) << 4) | (a->byte_0x5 & 0xf));
    write_halfword(block, 0x31, (a->half_0x2 & 0xfff) | COEF_A_FLAG);
    write_byte(block, 0x11, b->byte_0x0 & 0x3f);
    write_byte(block, 0x33, ((b->byte_0x4 & 0xf) << 4) | (b->byte_0x5 & 0xf));
    write_halfword(block, 0x34, (b->half_0x2 & 0xfff) | COEF_B_FLAG);
}
