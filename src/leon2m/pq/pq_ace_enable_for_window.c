/* pq_ace_enable_for_window  (FUN_a00f6c38)
 *
 * Switch ACE on for the selected picture window.
 * Name basis: descriptive - bit (window + 4) of 0xCF00EE80; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f6c38 @ 0xa00f6c38-0xa00f6c6c (52 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: the result is cast to unsigned char before the register write.
 */
#define REG (*(volatile unsigned int *)0xcf00ee80)   /* word register at 0xcf00ee80 */
extern unsigned char pq_selected_window;             /* the picture window that picture settings currently go to */
#define ACE_ENABLE_BIT_OFFSET 4                      /* base bit position for ACE enable */

/*
 * Enable ACE for the selected picture window.
 *
 * Sets the bit at position (pq_selected_window + ACE_ENABLE_BIT_OFFSET) in the register
 * and writes back the low byte of the result. No routine in the image calls it by name.
 */
void pq_ace_enable_for_window(void)
{
    REG = (unsigned char)(REG | (1 << (pq_selected_window + ACE_ENABLE_BIT_OFFSET)));
}
