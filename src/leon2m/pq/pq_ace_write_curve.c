/* pq_ace_write_curve  (FUN_a00f7434)
 *
 * Write a curve of 16-bit points to the ACE block, or the default curve.
 * Name basis: derived - byte stream to 0xCF00EEC8 between writes of 0xCF00EEC4; same block as 'Config ACE'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f7434 @ 0xa00f7434-0xa00f7534, flags -mcpu=v8 -O3 -g.
 * Source form: the loop is a do-while with the index compared after the increment; the low and high byte of a
 * point are separate statements with a delay call between them; the closing ACE_CURVE_CTRL write uses the byte
 * kept in curve_ctrl, not a new read. pq_ace_init holds a copy of this routine as a static function.
 */
#define R(a) (*(volatile unsigned int *)(a))

/* ACE registers (names as in pq_ace_init). */
#define ACE_CTRL       0xcf00ee80   /* bits 1..2: window for ACE access; bit 4 + window: ACE on */
#define ACE_CONFIG     0xcf00eec0   /* bit 5 cleared for a curve */
#define ACE_CURVE_CTRL 0xcf00eec4
#define ACE_CURVE_DATA 0xcf00eec8   /* curve points, low byte then high byte */

/* Curve data (as pq_ace_init names it): the index of the last point, then points[0..last_point]. */
struct ace_curve_data {
    unsigned char last_point;
    unsigned short points[1];
};

extern unsigned char pq_selected_window;
extern struct ace_curve_data pq_ace_default_curve;
extern void reg_table_port_delay(void);
extern void panel_wait_sync_pulse(void);

/*
 * Write a curve of 16-bit points into the ACE block of the selected picture window and switch ACE on for that
 * window.
 *
 *   curve  last_point and last_point + 1 points; 0 = pq_ace_default_curve
 *
 * Bits 1..2 of ACE_CTRL get pq_selected_window, bit 5 of ACE_CONFIG is cleared, and ACE_CURVE_CTRL keeps its low
 * four bits with bits 4 and 6 set (bits 5, 7 and 8..31 cleared). After the points, bit 7 of ACE_CURVE_CTRL is
 * set, the routine waits for one sync pulse, sets bit 4 + pq_selected_window of ACE_CTRL and clears bit 7 of
 * ACE_CURVE_CTRL again. Both ACE_CTRL writes also clear bits 8..31.
 *
 * Callers: pq_auto_level_update_curve and pq_api_load_ace_table; pq_ace_init holds its own copy of these steps.
 */
void pq_ace_write_curve(struct ace_curve_data *curve)
{
    unsigned char i;
    unsigned char curve_ctrl;
    struct ace_curve_data *selected_curve;

    R(ACE_CTRL) = (R(ACE_CTRL) & 0xf9) | (pq_selected_window << 1);
    R(ACE_CONFIG) &= ~0x20;
    curve_ctrl = (R(ACE_CURVE_CTRL) & 0x0f) | 0x50;
    R(ACE_CURVE_CTRL) = curve_ctrl;
    /* Use the default curve when no curve is supplied. */
    if (curve == 0)
        selected_curve = &pq_ace_default_curve;
    else
        selected_curve = curve;
    /* last_point + 1 points, low byte then high byte, a delay after each byte. */
    i = 0;
    do {
        R(ACE_CURVE_DATA) = selected_curve->points[i] & 0xff;
        reg_table_port_delay();
        R(ACE_CURVE_DATA) = selected_curve->points[i] >> 8;
        i++;
        reg_table_port_delay();
    } while (i <= selected_curve->last_point);
    /* Bit 7 set, one sync pulse, ACE on for the window, bit 7 cleared. */
    R(ACE_CURVE_CTRL) = curve_ctrl | 0x90;
    panel_wait_sync_pulse();
    R(ACE_CTRL) = (R(ACE_CTRL) | (1 << (pq_selected_window + 4))) & 0xff;
    R(ACE_CURVE_CTRL) &= ~0x80;
}
