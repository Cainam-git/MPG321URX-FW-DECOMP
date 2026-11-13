/* ldc_hw_access_register  (FUN_a00fb434)
 *
 * Read, write or set up a register of the grid block selected by an id.
 * Name basis: derived - one entry point for offset select, read, write, bit-range writes and fixed set-ups
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fb434 @ 0xa00fb434-0xa00fb9ec (366 words), flags -mcpu=v8 -O3 -g.
 * Source form: ids LDC_ID_READ, LDC_ID_WRITE, LDC_ID_INIT and LDC_ID_SET_SIZE set the local action inside the
 * switch and act after it (if-chain on the action). Bit ranges are written by the inlined helpers fset / rset,
 * which take the highest and lowest bit number and build the mask as (1 << hi) | ((1 << hi) - (1 << lo)); the
 * mask is formed at RTL level, which keeps it in a register for both the and and the andn, keeps the
 * 'and 0x80000000' after 'sll 31' and builds 0x1f00 as sethi 0x1000 + or 0xf00. The limits are written as ?:
 * expressions on the globals. LDC_ID_INIT stores width before height, LDC_ID_SET_SIZE height before width.
 */

/* Picture size kept by this routine: width (DAT_a802d67a_hsize) and height (DAT_a802d678_vsize). */
extern unsigned short DAT_a802d67a_hsize;
extern unsigned short DAT_a802d678_vsize;

#define R(a) (*(volatile unsigned int *)(a))

/* Registers of the grid block. */
#define LDC_REG_BASE  0xd0040000
#define LDC_REG_CTRL  0xd0040000            /* bits 0..12 height, 16..28 width, bit 31 enable */
#define LDC_REG_04    0xd0040004            /* bits 10..18 cell height, 20..28 cell width */
#define LDC_REG_C4    0xd00400c4            /* bits 4..7 / 8..11: shift counts used by ldc_hw_run_mode3_pass */

/* Ids of ldc_hw_access_register. Ids 7 and 9..17 write one bit range of one register (named by the register
 * offset and the bits); the callers named are the ones that pass the id. */
enum ldc_access_id {
    LDC_ID_SELECT_OFFSET = 0,   /* remember *value as the register offset of ids 1 and 2 */
    LDC_ID_READ          = 1,   /* *value = register at that offset */
    LDC_ID_WRITE         = 2,   /* register at that offset = *value */
    LDC_ID_INIT          = 3,   /* fixed values, then keep width / height (ldc_hw_setup_for_panel_size) */
    LDC_ID_SET_WIDTH     = 4,   /* keep *value as width */
    LDC_ID_SET_HEIGHT    = 5,   /* keep *value as height */
    LDC_ID_SET_SIZE      = 6,   /* keep width / height and write the size fields (ldc_hw_setup_for_panel_size) */
    LDC_ID_98_BITS16_19  = 7,
    LDC_ID_NONE          = 8,   /* writes nothing; ldc_hw_set_timing passes its 1000 - t value with it */
    LDC_ID_ENABLE        = 9,   /* bit 31 of LDC_REG_CTRL */
    LDC_ID_0C_BITS8_12   = 10,  /* ldc_hw_set_strength */
    LDC_ID_E4_BITS24_31  = 11,  /* ldc_hw_set_timing, mode 4 */
    LDC_ID_110_BIT31     = 12,  /* ids 12..17: ldc_hw_init with fixed values */
    LDC_ID_140_BIT31     = 13,
    LDC_ID_138_BIT31     = 14,
    LDC_ID_130_BITS16_23 = 15,
    LDC_ID_160_BITS16_23 = 16,
    LDC_ID_138_BITS16_24 = 17
};

/* Limits of the kept width and height: ids 4 / 5 and ids 3 / 6. */
#define WIDTH_MIN        0x2d0      /* 720 */
#define WIDTH_MAX        0x2000     /* 8192, id 4 */
#define WIDTH_MAX_SIZE   0x1400     /* 5120, ids 3 and 6 */
#define HEIGHT_MIN       0x1e0      /* 480 */
#define HEIGHT_MAX       0x10e0     /* 4320, id 5 */
#define HEIGHT_MAX_SIZE  0xb40      /* 2880, ids 3 and 6 */

/* The cell grid of ldc_hw_run_mode3_pass is 12 rows by 24 columns. */
#define CELL_ROWS     12
#define CELL_COLUMNS  24

/* Return x with bits lo..hi replaced by v. */
static unsigned int fset(unsigned int x, unsigned int hi, unsigned int lo, unsigned int v)
{
    unsigned int m = (1 << hi) | ((1 << hi) - (1 << lo));

    return (x & ~m) | ((v << lo) & m);
}

/* Replace bits lo..hi of the register at address a by v. */
static void rset(unsigned int a, unsigned int hi, unsigned int lo, unsigned int v)
{
    R(a) = fset(R(a), hi, lo, v);
}

extern unsigned char ldc_last_register_offset;

/* What is left to do after the switch. */
enum {
    ACTION_NONE  = 0,
    ACTION_READ  = 1,
    ACTION_WRITE = 2,
    ACTION_INIT  = 3,
    ACTION_SIZE  = 4
};

/*
 * One access to the grid block at 0xD0040000, chosen by id (enum ldc_access_id).
 *
 *   id      what to do; ids 8 and above 17 do nothing
 *   value   in: the value to write or keep (read for every id); out: the register read by LDC_ID_READ
 *   width   used by LDC_ID_INIT and LDC_ID_SET_SIZE only
 *   height  likewise
 * Returns 1.
 *
 * Callers: ldc_hw_init and ldc_hw_command (ids 12..17), ldc_hw_set_timing (8, 11), ldc_hw_set_strength (10) and
 * ldc_hw_setup_for_panel_size (3 with 3840 x 2160, then 6 with the size of the panel timing row).
 *
 * Phases: the switch handles the single-field ids at once and leaves the others to the action chain after it:
 *   read / write at the offset kept by LDC_ID_SELECT_OFFSET (one byte: offsets 0..0xFF);
 *   LDC_ID_INIT: 28 fixed register writes, then width and height kept within their limits;
 *   LDC_ID_SET_SIZE: width and height kept within their limits, then written to LDC_REG_CTRL, the cell size
 *   (each rounded up: height / 12, width / 24) to LDC_REG_04, and fields derived from the cell size to LDC_REG_C4.
 * The fixed values of LDC_ID_INIT in LDC_REG_CTRL, LDC_REG_04 and bits 16..31 of LDC_REG_C4 are the ones
 * LDC_ID_SET_SIZE computes for 1920 x 1080 (0x438 = 1080, 0x780 = 1920, 0x5A = 90 = 1080 / 12, 0x50 = 80 =
 * 1920 / 24, 0x26 and 0x2C); the kept size is the width / height passed in.
 */
int ldc_hw_access_register(unsigned int id, unsigned int *value_ptr, unsigned int width, unsigned int height)
{
    unsigned char action = ACTION_NONE;
    unsigned int value = *value_ptr;

    switch (id) {
    case LDC_ID_SELECT_OFFSET:
        ldc_last_register_offset = value;
        break;
    case LDC_ID_READ:
        action = ACTION_READ;
        break;
    case LDC_ID_WRITE:
        action = ACTION_WRITE;
        break;
    case LDC_ID_INIT:
        action = ACTION_INIT;
        break;
    case LDC_ID_SET_WIDTH:
        DAT_a802d67a_hsize = value < WIDTH_MIN ? WIDTH_MIN : (value > WIDTH_MAX ? WIDTH_MAX : value);
        break;
    case LDC_ID_SET_HEIGHT:
        DAT_a802d678_vsize = value < HEIGHT_MIN ? HEIGHT_MIN : (value > HEIGHT_MAX ? HEIGHT_MAX : value);
        break;
    case LDC_ID_SET_SIZE:
        action = ACTION_SIZE;
        break;
    case LDC_ID_98_BITS16_19:
        rset(0xd0040098, 19, 16, value);
        break;
    case LDC_ID_NONE:
        break;
    case LDC_ID_ENABLE:
        rset(LDC_REG_CTRL, 31, 31, value);
        break;
    case LDC_ID_0C_BITS8_12:
        rset(0xd004000c, 12, 8, value);
        break;
    case LDC_ID_E4_BITS24_31:
        rset(0xd00400e4, 31, 24, value);
        break;
    case LDC_ID_110_BIT31:
        rset(0xd0040110, 31, 31, value);
        break;
    case LDC_ID_140_BIT31:
        rset(0xd0040140, 31, 31, value);
        break;
    case LDC_ID_138_BIT31:
        rset(0xd0040138, 31, 31, value);
        break;
    case LDC_ID_130_BITS16_23:
        rset(0xd0040130, 23, 16, value);
        break;
    case LDC_ID_160_BITS16_23:
        rset(0xd0040160, 23, 16, value);
        break;
    case LDC_ID_138_BITS16_24:
        rset(0xd0040138, 24, 16, value);
        break;
    }
    if (action == ACTION_READ) {
        *value_ptr = R(LDC_REG_BASE + ldc_last_register_offset);
    } else if (action == ACTION_WRITE) {
        R(LDC_REG_BASE + ldc_last_register_offset) = value;
    } else if (action == ACTION_INIT) {
        /* Fixed start values of the block. */
        R(LDC_REG_CTRL) = 0x7802438;            /* 1920 x 1080, enable bit clear */
        R(LDC_REG_04) = 0x501698c;
        R(0xd0040008) = 0x80000000;
        R(0xd0040008) = (R(0xd0040008) & ~3) | 2;
        R(0xd0040208) = (R(0xd0040208) & ~3) | 1;
        R(0xd004000c) = 0;
        R(0xd0040020) = 0xc2800100;
        R(0xd0040024) = 0;
        R(0xd0040028) = 0x2000200;
        R(0xd004002c) = 0x10200;
        R(0xd0040030) = 0x2fff04b0;
        R(0xd0040034) = 0x808d63;
        R(0xd00400c0) = 0x80000000;
        R(LDC_REG_C4) = 0x2c260000;
        R(0xd0040080) = 0x80112830;
        R(0xd0040090) = 0x8102080;
        R(0xd0040098) = 0xf0101010;             /* grid table selector (bits 12..15) 1 */
        R(0xd0040094) = 0x400717e0;
        R(0xd004009c) = 0x50506000;
        R(0xd00400ac) = 0x73c00380;
        R(0xd00400d4) = 0x3f00004;
        R(0xd00400d8) = 0x1110113;              /* mode (bits 0..3) 3 */
        R(0xd00400e0) = 0x4b321900;
        R(0xd00400e4) = 0x80808064;
        R(0xd00400e8) = 0xff010064;
        R(0xd00400f0) = 0xfffff0f0;
        R(0xd00400f4) = 0x20000000;
        R(0xd00400f8) = 0xc0fec0;
        /* Keep the given size; the registers are not written here. */
        DAT_a802d67a_hsize = width;
        DAT_a802d678_vsize = height;
        DAT_a802d67a_hsize = DAT_a802d67a_hsize < WIDTH_MIN ? WIDTH_MIN : (DAT_a802d67a_hsize > WIDTH_MAX_SIZE ? WIDTH_MAX_SIZE : DAT_a802d67a_hsize);
        DAT_a802d678_vsize = DAT_a802d678_vsize < HEIGHT_MIN ? HEIGHT_MIN : (DAT_a802d678_vsize > HEIGHT_MAX_SIZE ? HEIGHT_MAX_SIZE : DAT_a802d678_vsize);
    } else if (action == ACTION_SIZE) {
        unsigned int reg, cell_height, cell_width, width_field, height_field;
        unsigned short kept_height, kept_width;

        /* Keep the size within its limits. */
        DAT_a802d678_vsize = height;
        DAT_a802d67a_hsize = width;
        DAT_a802d67a_hsize = DAT_a802d67a_hsize < WIDTH_MIN ? WIDTH_MIN : (DAT_a802d67a_hsize > WIDTH_MAX_SIZE ? WIDTH_MAX_SIZE : DAT_a802d67a_hsize);
        DAT_a802d678_vsize = DAT_a802d678_vsize < HEIGHT_MIN ? HEIGHT_MIN : (DAT_a802d678_vsize > HEIGHT_MAX_SIZE ? HEIGHT_MAX_SIZE : DAT_a802d678_vsize);
        /* Height and width into LDC_REG_CTRL. */
        kept_height = DAT_a802d678_vsize;
        reg = R(LDC_REG_CTRL);
        reg = fset(reg, 12, 0, kept_height);
        kept_width = DAT_a802d67a_hsize;
        reg = fset(reg, 28, 16, kept_width);
        R(LDC_REG_CTRL) = reg;
        /* Cell size, rounded up, into LDC_REG_04; bits 0..8 get the fixed 0x18C in four ranges. */
        cell_height = kept_height / CELL_ROWS + (kept_height % CELL_ROWS != 0);
        cell_width = kept_width / CELL_COLUMNS + (kept_width % CELL_COLUMNS != 0);
        reg = R(LDC_REG_04);
        reg = fset(reg, 1, 0, 0);
        reg = fset(reg, 3, 2, 3);
        reg = fset(reg, 6, 4, 0);
        reg = fset(reg, 8, 7, 3);
        reg = fset(reg, 18, 10, cell_height);
        reg = fset(reg, 28, 20, cell_width);
        R(LDC_REG_04) = reg;
        /* LDC_REG_C4: two fields derived from the cell size (width_field even), bits 0..3 = width_field / 8,
         * bits 4..11 (the two shift counts) = 0. */
        width_field = (((cell_width >> 1) - 1) >> 1) << 1;
        height_field = (cell_height >> 1) - 1;
        reg = R(LDC_REG_C4);
        reg = fset(reg, 3, 0, width_field >> 3);
        reg = fset(reg, 11, 4, 0);
        reg = fset(reg, 23, 16, width_field);
        reg = fset(reg, 31, 24, height_field);
        R(LDC_REG_C4) = reg;
    }
    return 1;
}
