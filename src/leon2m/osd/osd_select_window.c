/* osd_select_window  (FUN_a002e6e4)
 *
 * Select which of the eight windows of a menu layer the next window writes go to.
 *   window: value 0..7
 *   block: block 0 or 1
 * Name basis: derived - code only; callers osd_api_set_window_effect, osd_api_set_window_rect,
 *   osd_api_set_level_all_windows loop v = 0..7
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002e6e4, flags -mcpu=v8 -O3 -g.
 * Source form: rd and wr are static helpers (block test inside each).
 */

/* Register of a menu layer's register block, by word address (the register block sits at 0xCF000000). */
#define OSD_REG(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))

#define REG_WINDOW_SELECT 0xa5          /* register 0xA5: bits 0..2 = the selected window */
#define WINDOW_SELECT_KEEP 0xf8        /* bits 3..7 of that register are kept */

extern unsigned short osd_layer_bases[2];

/* Read register reg of block (0 or 1; any other value counts as 0). */
static unsigned char rd(unsigned char block, unsigned char reg)
{
    if (block >= 2) block = 0;
    return OSD_REG(osd_layer_bases[block] + reg);
}

/* Write register reg of block (0 or 1; any other value counts as 0). */
static void wr(unsigned char block, unsigned char reg, unsigned char val)
{
    if (block >= 2) block = 0;
    OSD_REG(osd_layer_bases[block] + reg) = val;
}

/*
 * Select which of the eight windows of a menu layer the following window writes go to. A window number of
 * 8 or more is ignored.
 *   window: window number 0..7
 *   block:  register block of the menu layer, 0 or 1
 */
void osd_select_window(unsigned int window, unsigned char block)
{
    if (window < 8)
        wr(block, REG_WINDOW_SELECT, (rd(block, REG_WINDOW_SELECT) & WINDOW_SELECT_KEEP) | window);
}
