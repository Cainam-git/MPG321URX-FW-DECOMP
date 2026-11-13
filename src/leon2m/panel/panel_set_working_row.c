/* panel_set_working_row  (FUN_a0105c0c)
 *
 * Store the working copy of the panel timing row.
 * Name basis: proven - 0x58-byte row stored at 0xA802D6A8, pointer at 0xA802D6A4
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0105c0c, flags -mcpu=v8 -O3 -g.
 * The row is passed by value (11 doublewords); the build depends on it being a struct of unsigned long long.
 */
/* One panel timing row: 0x58 bytes, 11 doublewords (same layout as the rows of panel_mode_rows). */
struct panel_mode_row { unsigned long long words[11]; };

extern struct panel_mode_row panel_working_row;
extern struct panel_mode_row *panel_working_row_ptr;

/*
 * Make row the active panel timing row: copy it to panel_working_row and point panel_working_row_ptr at it.
 * Routines that need a timing value of the active row read it through panel_working_row_ptr.
 * Called with the transformed row from panel_transform_row and startup_init_display_output.
 */
void panel_set_working_row(struct panel_mode_row row)
{
    panel_working_row = row;
    panel_working_row_ptr = &panel_working_row;
}
