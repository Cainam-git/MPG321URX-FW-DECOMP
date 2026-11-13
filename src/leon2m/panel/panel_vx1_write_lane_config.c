/* panel_vx1_write_lane_config  (FUN_a01222c8)
 *
 * Write the lane configuration registers from two bytes of the working panel timing row.
 * Name basis: descriptive - registers 0xCF00EB40..0xCF00EB60; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01222c8, flags -mcpu=v8 -O3 -g.
 * Source form: the same statements as the register block in the middle of panel_vx1_setup_lanes: a two-level if
 * for 0xcf00eb40 and one case per display mode in the order 10, 9, 8, 7, 6, 5, default (the arms that write the
 * same value are kept apart).
 */
#define R(a) (*(volatile unsigned int *)(a))
extern unsigned char *panel_working_row_ptr;

#define ROW_DISPLAY_MODE 6      /* byte +6 of the panel timing row (display_mode) */
#define ROW_BPC          7      /* byte +7 of the panel timing row (bpc: 8 or 10 are told apart here) */

/*
 * Write the V-by-One transmitter set-up registers 0xCF00EB40..0xCF00EB60 from two bytes of the working panel row.
 *
 *   0xCF00EB40  from the row's bpc: 10 gives 2, 8 gives 1, anything else 3
 *   0xCF00EB54  from the row's display mode: 9 and 10 give 5, 5 to 8 give 1, anything else 7
 *   the rest    fixed values; 0xCF00EB44 (reg_panel_vx1_reset) gets 0 and 0xCF00EB48 (reg_panel_vx1_lock_status) gets 4
 *
 * Nothing calls this routine. panel_vx1_setup_lanes (the one the power sequencer calls) contains the same
 * statements; it writes 0xCF00EB58 and 0xCF00EB44 once more before them and waits 10 ticks after them.
 */
void panel_vx1_write_lane_config(void)
{
    if (panel_working_row_ptr[ROW_BPC] == 10)
        R(0xcf00eb40) = 2;
    else if (panel_working_row_ptr[ROW_BPC] == 8)
        R(0xcf00eb40) = 1;
    else
        R(0xcf00eb40) = 3;
    R(0xcf00eb44) = 0;
    R(0xcf00eb48) = 4;
    R(0xcf00eb4c) = 0;
    R(0xcf00eb50) = 0;
    switch (panel_working_row_ptr[ROW_DISPLAY_MODE]) {
    case 10:
        R(0xcf00eb54) = 5;
        break;
    case 9:
        R(0xcf00eb54) = 5;
        break;
    case 8:
        R(0xcf00eb54) = 1;
        break;
    case 7:
        R(0xcf00eb54) = 1;
        break;
    case 6:
        R(0xcf00eb54) = 1;
        break;
    case 5:
        R(0xcf00eb54) = 1;
        break;
    default:
        R(0xcf00eb54) = 7;
        break;
    }
    R(0xcf00eb58) = 7;
    R(0xcf00eb60) = R(0xcf00eb60) & 0xfc;       /* clear the two low bits */
    R(0xcf00eb5c) = 0;
}
