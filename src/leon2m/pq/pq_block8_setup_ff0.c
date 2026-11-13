/* pq_block8_setup_ff0  (FUN_a0118b0c)
 *
 * Program registers 0xCF012FF0..FF8 from a size field of the working panel timing row.
 * Name basis: descriptive - unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0118b0c @ 0xa0118b0c, flags -mcpu=v8 -O3 -g.
 * Source form: panel_working_row_ptr is declared as an unsigned int and the field is read through a cast of
 * that value; reg_table_port_write_second is declared without a prototype.
 */
extern unsigned int panel_working_row_ptr;
#define BLOCK8_E80 (*(volatile unsigned int *)0xcf012e80)   /* 0 in pq_block8_stop, 1 in pq_block8_start */
#define BLOCK8_FF0 (*(volatile unsigned int *)0xcf012ff0)
#define BLOCK8_FF4 (*(volatile unsigned int *)0xcf012ff4)
#define BLOCK8_FF8 (*(volatile unsigned int *)0xcf012ff8)
extern void reg_table_port_write_second();

#define FF0_BIT7           0x80
#define BLOCK8_TABLE       0xf4             /* table number at the table port (as in pq_block8_set_timing) */
#define BLOCK8_TABLE_BYTES 0x400
#define E80_VALUE_6        6

/* Lines of the working panel timing row (struct panel_timing_row, field active_size1 at +0xA). */
#define ROW_ACTIVE_LINES(row_address) (*(unsigned short *)((row_address) + 10))
#define LINES_LIMIT_2160   0x86f            /* more than 2159 lines */
#define LINES_LIMIT_1080   0x437            /* more than 1079 lines */

/*
 * Clear bit 7 of BLOCK8_FF0, write 6 to BLOCK8_E80 and write a 1024-byte table to picture block 8 through the
 * table port's second data register. Then, from the line count of the working panel timing row:
 * 2160 lines or more: FF0 = 0xB, FF4 = 0, FF8 = 1; 1080..2159 lines: FF0 = 0xA, FF4 = 0x40, FF8 = 0;
 * fewer lines: the three registers are not written.
 *
 *   table   the 1024 bytes for the table port
 *   unused  not used
 *
 * Nothing in the firmware calls this routine.
 */
void pq_block8_setup_ff0(unsigned int table, unsigned int unused) {
    unsigned int active_lines;

    BLOCK8_FF0 = BLOCK8_FF0 & ~FF0_BIT7;
    BLOCK8_E80 = E80_VALUE_6;
    reg_table_port_write_second(BLOCK8_TABLE, 0, BLOCK8_TABLE_BYTES, table);
    active_lines = ROW_ACTIVE_LINES(panel_working_row_ptr);
    if (active_lines > LINES_LIMIT_2160) {
        BLOCK8_FF0 = 0xb;
        BLOCK8_FF4 = 0;
        BLOCK8_FF8 = 1;
    } else if (active_lines > LINES_LIMIT_1080) {
        BLOCK8_FF0 = 0xa;
        BLOCK8_FF4 = 0x40;
        BLOCK8_FF8 = 0;
    }
}
