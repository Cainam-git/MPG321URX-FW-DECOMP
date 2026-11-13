/* pq_window_set_rect  (FUN_a00f6d00)
 *
 * Write the four coordinates of the selected picture window.
 * Name basis: derived - four 16-bit values to 0xCF00EC88..0xCF00ECA4
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f6d00 @ 0xa00f6d00, flags -mcpu=v8 -O3 -g.
 * Source form: each byte converted with an (unsigned char) cast; the firmware keeps a register window (save)
 * although the routine makes no call, which this form reproduces (masking with & 0xff gives a leaf routine
 * instead).
 */

#define R(a) (*(volatile unsigned int *)(a))

/* Rectangle registers of the picture window chosen in WINDOW_SELECT_A (0xCF00EC84, bits 0..1); each takes one
   byte of a 16-bit value. */
#define WINDOW_X_LOW        0xcf00ec88
#define WINDOW_X_HIGH       0xcf00ec8c
#define WINDOW_WIDTH_LOW    0xcf00ec90
#define WINDOW_WIDTH_HIGH   0xcf00ec94
#define WINDOW_Y_LOW        0xcf00ec98
#define WINDOW_Y_HIGH       0xcf00ec9c
#define WINDOW_HEIGHT_LOW   0xcf00eca0
#define WINDOW_HEIGHT_HIGH  0xcf00eca4

/*
 * Write position and size of the selected picture window, low byte first. The register order is x, width,
 * y, height.
 *
 * Callers: pq_api_set_window_rect (after pq_select_window; the panel's active size from 0, 0),
 * sys_setup_channel_window (a channel's window, or the panel's active size from 0, 0) and
 * pq_fga_handle_command (a calibration window, or the full panel).
 */
void pq_window_set_rect(unsigned short x, unsigned short y, unsigned short width, unsigned short height)
{
    R(WINDOW_X_LOW) = (unsigned char)x;
    R(WINDOW_X_HIGH) = (unsigned char)(x >> 8);
    R(WINDOW_WIDTH_LOW) = (unsigned char)width;
    R(WINDOW_WIDTH_HIGH) = (unsigned char)(width >> 8);
    R(WINDOW_Y_LOW) = (unsigned char)y;
    R(WINDOW_Y_HIGH) = (unsigned char)(y >> 8);
    R(WINDOW_HEIGHT_LOW) = (unsigned char)height;
    R(WINDOW_HEIGHT_HIGH) = (unsigned char)(height >> 8);
}
