/* pq_block8_set_timing  (FUN_a01186e0)
 *
 * Program the timing of picture block 8 from the working panel timing row.
 * Name basis: descriptive - from two size fields of the row; uses the table memory port
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01186e0 @ 0xa01186e0-0xa011898c (684 bytes, 171 words), flags -mcpu=v8 -O3 -g.
 * Source forms:
 *  - registers as 'volatile unsigned long' (the alias set differs from the unsigned int record word, so the mode
 *    load is scheduled between the 0x71 / 0x10 stores as in the firmware); the mode is read after both stores;
 *  - word 0 of pq_block8_config is read twice: as a mask (flags.word & CONFIG_BIT29) and as a one-bit field
 *    (flags.bits.bit29 == 1; '== 1' gives the firmware's branch layout, '!= 0' does not);
 *  - half_lines is read BEFORE the four size register stores; '(unsigned char) width_units' for the low byte;
 *  - case order 4, 1, 2, 3, default (separate case 1 and case 2 bodies).
 */
#define R(a) (*(volatile unsigned long *)(a))

#define PQ_BLOCK0_REG_EE    R(0xcf009bb8)   /* register 0xEE of picture block 0; bit 1 is cleared here */
#define FRC_CHANNEL_ON      R(0xcf011800)
#define FRC_CTRL            R(0xcf011a00)
#define BLOCK8_FRC_BIT      0x20            /* set in both by pq_block8_start, cleared by pq_block8_stop */

/* Registers of picture block 8 (0xCF012E00..0xCF012FFF). */
#define BLOCK8_WIDTH_LOW    R(0xcf012e0c)
#define BLOCK8_WIDTH_HIGH   R(0xcf012e10)
#define BLOCK8_LINES_LOW    R(0xcf012e1c)
#define BLOCK8_LINES_HIGH   R(0xcf012e20)
#define BLOCK8_MODE         R(0xcf012e40)   /* bits 0..1: the mode field of pq_block8_set_mode */
#define BLOCK8_MODE_FLAGS   R(0xcf012e44)   /* bit 0: mode 1; bit 5: width counted in units of 8 */
#define BLOCK8_E60          R(0xcf012e60)
#define BLOCK8_E64          R(0xcf012e64)
#define BLOCK8_E6C          R(0xcf012e6c)
#define BLOCK8_E80          R(0xcf012e80)   /* 0 in pq_block8_stop, 1 in pq_block8_start */
#define BLOCK8_F00          R(0xcf012f00)
#define BLOCK8_F04          R(0xcf012f04)
#define BLOCK8_F08          R(0xcf012f08)
#define BLOCK8_F0C          R(0xcf012f0c)
#define BLOCK8_F10          R(0xcf012f10)
#define BLOCK8_F14          R(0xcf012f14)
#define BLOCK8_F18          R(0xcf012f18)
#define BLOCK8_F1C          R(0xcf012f1c)
#define BLOCK8_F20          R(0xcf012f20)
#define MODE_FLAG_MODE1     1
#define MODE_FLAG_UNITS_OF_8 0x20

#define BLOCK8_TABLE        0xf4            /* table number at the table port (reg_table_port_write) */
#define BLOCK8_TABLE_BYTES  0x400

/* The start of the working panel timing row (struct panel_timing_row, 0x58 bytes). */
struct panel_timing_row { unsigned int flags; unsigned short half_0x4; unsigned char display_mode, bpc; unsigned short active_size0; unsigned short active_size1; };
/* pq_block8_config: the configuration record of picture block 8 (pq_load_block8_config stores it). */
#define CONFIG_BIT29 0x20000000
struct pq_block8_config_bits { unsigned int load_tables : 1, bit30 : 1, bit29 : 1, rest : 29; };
struct pq_block8_config_record {
    union { unsigned int word; struct pq_block8_config_bits bits; } flags;     /* +0x0 */
    unsigned int mode;                  /* +0x4: 1..4, as for pq_block8_set_mode */
    unsigned int config_table;          /* +0x8 */
    unsigned int value_table;           /* +0xC */
};
extern struct panel_timing_row *panel_working_row_ptr;
extern struct pq_block8_config_record pq_block8_config;
extern void timer_sleep_ticks(int ticks);
extern int reg_table_port_write();

/*
 * Load the response level table into picture block 8 and program the block's mode, size and fixed registers.
 *
 *   level_table  address of the 0x400-byte table of the response level (pq_response_level_tables[level]); it
 *                goes to table 0xF4 through the table port, from offset 0
 *
 * Order: bit 1 of register 0xEE of picture block 0 cleared, a wait of 51 ticks, BLOCK8_E80 = 4, the table.
 * Then the mode field from pq_block8_config.mode, set as pq_block8_set_mode does (1 and 2 give field value 1,
 * 3 gives 2, 4 gives 3, others 0; bit 0 of BLOCK8_MODE_FLAGS only for mode 1). After a short wait the size
 * from the working panel timing row: the active width in units of 16 pixels (8 when bit 5 of BLOCK8_MODE_FLAGS
 * is set), rounded up, and half the active lines. Then fixed values, with three more registers and BLOCK8_E6C
 * = 0x12 when bit 29 of the configuration flags is set, and the block's bit in the two converter registers.
 *
 * Only caller: pq_apply_response_level, when the level differs from the last one applied. It then sets mode 2
 * (device_settings_pip_mode 0) or 3 with pq_block8_set_mode and starts the block (pq_block8_start).
 */
void pq_block8_set_timing(unsigned int level_table)
{
    unsigned short active_width, width_units, half_lines;
    unsigned char width_has_remainder;
    unsigned int mode;

    PQ_BLOCK0_REG_EE &= ~2;
    timer_sleep_ticks(0x32);
    BLOCK8_E80 = 4;
    reg_table_port_write(BLOCK8_TABLE, 0, BLOCK8_TABLE_BYTES, level_table);
    BLOCK8_MODE = 0x71;
    BLOCK8_MODE_FLAGS = 0x10;
    mode = pq_block8_config.mode;
    if (mode == 1) BLOCK8_MODE_FLAGS |= MODE_FLAG_MODE1;
    else BLOCK8_MODE_FLAGS &= ~MODE_FLAG_MODE1;
    switch (mode) {
    case 4: BLOCK8_MODE = (BLOCK8_MODE & 0xfc) | 3; break;
    case 1: BLOCK8_MODE = (BLOCK8_MODE & 0xfc) | 1; break;
    case 2: BLOCK8_MODE = (BLOCK8_MODE & 0xfc) | 1; break;
    case 3: BLOCK8_MODE = (BLOCK8_MODE & 0xfc) | 2; break;
    default: BLOCK8_MODE = BLOCK8_MODE & 0xfc; break;
    }
    timer_sleep_ticks(1);
    /* The active width in units of 16 (or 8) pixels, rounded up by one when the low four bits are not 0. */
    active_width = panel_working_row_ptr->active_size0;
    width_has_remainder = (active_width & 0xf) != 0;
    if (!(BLOCK8_MODE_FLAGS & MODE_FLAG_UNITS_OF_8)) width_units = (active_width >> 4) + width_has_remainder;
    else width_units = (active_width >> 3) + width_has_remainder;
    half_lines = panel_working_row_ptr->active_size1 >> 1;
    BLOCK8_WIDTH_LOW = (unsigned char) width_units;
    BLOCK8_WIDTH_HIGH = width_units >> 8;
    BLOCK8_LINES_LOW = half_lines & 0xff;
    BLOCK8_LINES_HIGH = half_lines >> 8;
    timer_sleep_ticks(1);
    if (pq_block8_config.flags.word & CONFIG_BIT29) {
        BLOCK8_F18 = 0xe;
        BLOCK8_F1C = 1;
        BLOCK8_F20 = 1;
    }
    BLOCK8_E60 = 3;
    BLOCK8_E64 = 0xb;
    FRC_CHANNEL_ON |= BLOCK8_FRC_BIT;
    FRC_CTRL |= BLOCK8_FRC_BIT;
    if (pq_block8_config.flags.bits.bit29 == 1) BLOCK8_E6C = 0x12;
    else BLOCK8_E6C = 0;
    BLOCK8_F00 = 0x40;
    BLOCK8_F04 = 0;
    BLOCK8_F08 = 0;
    BLOCK8_F0C = 0xff;
    BLOCK8_F10 = 0xff;
    BLOCK8_F14 = 0x1f;
}
