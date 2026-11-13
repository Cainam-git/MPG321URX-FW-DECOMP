/* panel_vx1_setup_transmitter  (FUN_a0121f58)
 *
 * Set up the V-by-One transmitter blocks for the display mode.
 * Note: Modes 5..7 fill the first block (0xFF at +0x2C) and write 0x80 to the second block's +0x2C; modes
 *   8..10 fill two blocks, other modes all four.
 * Name basis: derived - one, two or four of the blocks at 0xCF01CCEC + 0x8C * n by the working row's display
 *   mode; called only by panel_vx1_setup_lanes
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0121f58, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: the display mode is read from the row twice (once before each
 * switch) into the unsigned char display_mode; the arms for modes 5..7 and 8..10 of the first switch write the
 * same values and are kept as two arms.
 */
#define R(a) (*(volatile unsigned int *)(a))
extern unsigned char *panel_working_row_ptr;
extern int timer_sleep_ticks();

#define ROW_DISPLAY_MODE 6      /* byte +6 of the panel timing row (display_mode) */
#define WAIT_TICKS       1

/*
 * Set up the V-by-One transmitter registers (block 0xCF01CCxx..0xCF01CFxx) before the lanes are started.
 *
 * Called only by panel_vx1_setup_lanes, which runs in power-on state 4 for link type 1 and writes its own
 * registers after this routine returns.
 *
 * First a fixed series of writes with three waits of WAIT_TICKS. Then the working panel row's display mode
 * (byte +6, filled in by panel_transform_row) picks how many of the four transmitter register blocks are filled
 * (the blocks start at 0xCF01CCEC, 0xCF01CD78, 0xCF01CE04, 0xCF01CE90, 0x8C bytes apart):
 *   modes 5..7    first block only (0xFF in its +0x2C register; the second block gets 0x80 there, the others 0)
 *   modes 8..10   first two blocks
 *   other modes   all four blocks
 * Before that, 0xCF01CC6C gets 0x66 in every case and 0xCF01CC70 gets 0 for modes 5..10, 0x66 for the others.
 * What the registers do is not stated by any firmware text.
 */
void panel_vx1_setup_transmitter(void)
{
    unsigned char display_mode;

    R(0xcf01cfa8) = 0;
    R(0xcf01cf9c) = 0x70;
    R(0xcf01cf94) = 0x82;
    R(0xcf01cfa0) = 0x62;
    R(0xcf01cf9c) = 0x30;
    R(0xcf01cf98) = 2;
    R(0xcf01cc58) = 1;
    display_mode = panel_working_row_ptr[ROW_DISPLAY_MODE];
    /* The two switches test the same row byte; the first one sets 0xCF01CC6C / 0xCF01CC70. */
    switch (display_mode) {
    case 5: case 6: case 7:
        R(0xcf01cc6c) = 0x66;
        R(0xcf01cc70) = 0;
            break;
    case 8: case 9: case 10:
        R(0xcf01cc6c) = 0x66;
        R(0xcf01cc70) = 0;
        break;
    default:
        R(0xcf01cc6c) = 0x66;
        R(0xcf01cc70) = 0x66;
    }
    R(0xcf01cc68) = 0x66;
    R(0xcf01cf18) = 5;
    R(0xcf01cfa4) = 5;
    timer_sleep_ticks(WAIT_TICKS);
    R(0xcf01cf9c) = 0x31;
    R(0xcf01cc14) = 1;
    R(0xcf01cf94) = 0xd3;
    timer_sleep_ticks(WAIT_TICKS);
    R(0xcf01cf94) = 0x53;
    R(0xcf01cfa0) = 0x62;
    timer_sleep_ticks(WAIT_TICKS);
    /* The first register of each of the four blocks. */
    R(0xcf01ccec) = 0x81;
    R(0xcf01cd78) = 0x81;
    R(0xcf01ce04) = 0x81;
    R(0xcf01ce90) = 0x81;
    display_mode = panel_working_row_ptr[ROW_DISPLAY_MODE];
    /* Second switch: how many blocks are filled (see the comment above the routine). */
    switch (display_mode) {
    case 5: case 6: case 7:
        R(0xcf01cd18) = 0xff;
        R(0xcf01cda4) = 0x80;
        R(0xcf01ce30) = 0;
        R(0xcf01cebc) = 0;
        R(0xcf01cd28) = 0;
        R(0xcf01cdb4) = 0;
        R(0xcf01ce40) = 0;
        R(0xcf01cecc) = 0;
        R(0xcf01ccf0) = 0x18;
        R(0xcf01ccf8) = 0xff;
        R(0xcf01cd84) = 0;
        R(0xcf01ce10) = 0;
        R(0xcf01ce9c) = 0;
            break;
    case 8: case 9: case 10:
        R(0xcf01cd18) = 0xff;
        R(0xcf01cda4) = 0xff;
        R(0xcf01ce30) = 0;
        R(0xcf01cebc) = 0;
        R(0xcf01cd28) = 0;
        R(0xcf01cdb4) = 0;
        R(0xcf01ce40) = 0;
        R(0xcf01cecc) = 0;
        R(0xcf01ccf0) = 0x18;
        R(0xcf01ccf8) = 0xff;
        R(0xcf01cd84) = 0xff;
        R(0xcf01ce10) = 0;
        R(0xcf01ce9c) = 0;
        break;
    default:
        R(0xcf01cd18) = 0xff;
        R(0xcf01cda4) = 0xff;
        R(0xcf01ce30) = 0xff;
        R(0xcf01cebc) = 0xff;
        R(0xcf01cd28) = 0;
        R(0xcf01cdb4) = 0;
        R(0xcf01ce40) = 0;
        R(0xcf01cecc) = 0;
        R(0xcf01ccf0) = 0x18;
        R(0xcf01ccf8) = 0xff;
        R(0xcf01cd84) = 0xff;
        R(0xcf01ce10) = 0xff;
        R(0xcf01ce9c) = 0xff;
    }
}
