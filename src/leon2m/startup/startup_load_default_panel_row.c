/* startup_load_default_panel_row  (FUN_a0124180)
 *
 * Copy the ROM default panel timing row into the active row.
 * Name basis: proven - 0x58-byte row from ROM 0x1A30D0 to RAM 0xA802E378
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0124180, flags -mcpu=v8 -O3 -g.
 * One struct assignment; GCC expands it into 11 ldd/std pairs (one pair spilled to the frame, as in the
 * firmware). The firmware copies with ldd/std, so both objects are 8-byte aligned: the row's two 64-bit fields
 * (clk_min / clk_max at +0x10 / +0x18, as in panel_api_set_active_row) give that alignment, so no aligned attribute is
 * needed. The field layout is the one other leon2m files use for panel_active_row; an all-u64 array struct gives the
 * same instructions but a different slot for the spill reload.
 */

/* One panel timing row (0x58 bytes). Only the fields other routines read are named. */
struct Row {
    unsigned int w0;
    unsigned short h4;
    unsigned char b6, b7;
    unsigned short h08, h0a;
    unsigned char b0c[4];
    unsigned long long clk_min, clk_max;
    unsigned char b20[0x2e];
    unsigned short h4e, h50, h52;
    unsigned char b54[4];
};
extern struct Row panel_active_row;
extern const struct Row panel_default_row;

/*
 * Copy the whole ROM default row (panel_default_row) into the active row (panel_active_row). Called by
 * startup_load_default_records.
 */
void startup_load_default_panel_row(void)
{
    panel_active_row = panel_default_row;
}
