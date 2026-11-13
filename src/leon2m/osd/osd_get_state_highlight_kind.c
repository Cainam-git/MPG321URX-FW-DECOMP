/* osd_get_state_highlight_kind  (FUN_a00a8a78)
 *
 * Return the key guide kind (0, 1 or 2) of the current menu state for a choice row.
 *   row: choice row; used only in menu states 0xC0..0xC2
 * Returns: 0, 1 or 2
 * Note: The row matters only in states 0xC0..0xC2 (row 2 gives 1, other rows 0). Nothing calls this copy.
 * Name basis: descriptive - switch over menu states 0x3F..0xF9; osd_highlight_choice_row holds the same switch
 *   as its own copy
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a8a78 @ 0xa00a8a78, flags -mcpu=v8 -O3 -g.
 * Nothing calls this copy; osd_highlight_choice_row carries the same switch inlined (as a static copy of its
 * own). The groups are the cases of a switch with a jump table (values 0x3f..0xf9). The 0xc0..0xc2 group is the
 * second-to-last case group: GCC places it first after the jump. The result is returned as (kind & 3).
 */
extern unsigned short osd_get_menu_state(void);

/* Result: how the key guide of a choice row is set (see osd_highlight_choice_row). */
enum {
    HIGHLIGHT_KIND_SELECT     = 0,      /* key guide 'Move' / 'Select' */
    HIGHLIGHT_KIND_ENTER      = 1,      /* key guide 'Move' / 'Enter' */
    HIGHLIGHT_KIND_KEEP_GUIDE = 2       /* key guide left as it is */
};

/*
 * Classify the current menu state by what the key guide shows for a choice row.
 *
 *   row  the choice row; it only matters in the states 0xC0..0xC2 (the OLED Care detection choices), where
 *        row 2 is of kind HIGHLIGHT_KIND_ENTER and the other rows of kind HIGHLIGHT_KIND_SELECT
 *
 * Returns HIGHLIGHT_KIND_ENTER for 25 states (among them 0x3F..0x41, 0x44, 0x45, 0x53, 0x56, 0x58..0x5B,
 * 0x7A..0x7C, 0x82, 0x83, 0xDC, 0xE1 and 0xE6), HIGHLIGHT_KIND_KEEP_GUIDE for 12 states (0x69..0x6B, 0xAF, 0xB0,
 * 0xCA..0xCC, 0xF5, 0xF7..0xF9) and HIGHLIGHT_KIND_SELECT for every other state.
 */
unsigned char osd_get_state_highlight_kind(unsigned char row)
{
    unsigned char kind = HIGHLIGHT_KIND_SELECT;

    switch (osd_get_menu_state()) {
    case 0x3f:
    case 0x40:
    case 0x41:
    case 0x44:
    case 0x45:
    case 0x53:
    case 0x56:
    case 0x58:
    case 0x59:
    case 0x5a:
    case 0x5b:
    case 0x6f:
    case 0x7a:
    case 0x7b:
    case 0x7c:
    case 0x82:
    case 0x83:
    case 0xb3:
    case 0xba:
    case 0xbd:
    case 0xbe:
    case 0xbf:
    case 0xdc:
    case 0xe1:
    case 0xe6:
        kind = HIGHLIGHT_KIND_ENTER;
        break;
    case 0xc0:
    case 0xc1:
    case 0xc2:
        if (row == 2)
            kind = HIGHLIGHT_KIND_ENTER;
        break;
    case 0x69:
    case 0x6a:
    case 0x6b:
    case 0xaf:
    case 0xb0:
    case 0xca:
    case 0xcb:
    case 0xcc:
    case 0xf5:
    case 0xf7:
    case 0xf8:
    case 0xf9:
        kind = HIGHLIGHT_KIND_KEEP_GUIDE;
        break;
    }
    return kind & 3;
}
