/* panel_transform_row  (FUN_a0141840)
 *
 * Build the working copy of a panel timing row and hand it to the output set-up.
 * Name basis: derived - link type remapped, display mode from DispModeTransform, then
 *   panel_setup_output_after_row_change
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0141840 @ 0xa0141840, flags -mcpu=v8 -O3 -g (gcc 3.4.4).
 * Source form: the 88-byte row is copied byte by byte (unsigned char counter 0..0x57) into a local struct of eleven
 * 8-byte words, which is then passed by value; the link type is remapped with a switch on the 3-bit field.
 */
struct PanelRow { unsigned long long q[11]; };      /* one 0x58-byte timing row */

/* Bits 20..22 of the row's first word hold the link type. */
#define ROW_LINK_TYPE_MASK 0x700000
#define ROW_LINK_TYPE_1    0x100000
#define ROW_LINK_TYPE_2    0x200000
#define ROW_DISPLAY_MODE   6        /* byte offset of the display mode in the row */
extern unsigned char *panel_get_active_row(void);
extern unsigned char DispModeTransform(void);
extern void panel_set_working_row(struct PanelRow);
extern void panel_setup_output_after_row_change(void);
/*
 * Build the working copy of the active panel timing row and set up the output path with it.
 *
 * The copy is the active row with its link type (bits 20..22 of the first word) swapped: 1 becomes 2, 2 becomes 1,
 * 0 stays 0, other values are left as they are. The display mode byte (+6) of the copy is set from
 * DispModeTransform. The copy is stored as the working row (panel_set_working_row) and the output path is set up
 * again (panel_setup_output_after_row_change).
 *
 * Called by panel_api_set_active_row when a row is applied.
 */
void panel_transform_row(void)
{
    struct PanelRow row;                    /* working copy, passed by value */
    unsigned char *src = panel_get_active_row();
    unsigned char i;
    int link_type;
    for (i = 0; i <= 0x57; i++) ((unsigned char *)&row)[i] = src[i];
    link_type = (*(unsigned int *)src >> 20) & 7;
    switch (link_type) {
    case 0: *(unsigned int *)&row &= ~ROW_LINK_TYPE_MASK; break;
    case 1: *(unsigned int *)&row = (*(unsigned int *)&row & ~ROW_LINK_TYPE_MASK) | ROW_LINK_TYPE_2; break;
    case 2: *(unsigned int *)&row = (*(unsigned int *)&row & ~ROW_LINK_TYPE_MASK) | ROW_LINK_TYPE_1; break;
    }
    ((unsigned char *)&row)[ROW_DISPLAY_MODE] = DispModeTransform();
    panel_set_working_row(row);
    panel_setup_output_after_row_change();
}
