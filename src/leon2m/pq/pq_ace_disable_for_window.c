/* pq_ace_disable_for_window  (FUN_a00f6408)
 *
 * Switch ACE off for the selected picture window.
 * Name basis: descriptive - bit (window + 4) of 0xCF00EE80; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f6408 @ 0xa00f6408-0xa00f643c (52 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: the result is cast to unsigned char before the register write.
 */

/* bits 1..2: window for ACE access; bit 4 + window: ACE on */
#define ACE_CTRL (*(volatile unsigned int *)0xcf00ee80)
#define ACE_ON_SHIFT 4                  /* the on bit of window w is bit 4 + w */

extern unsigned char pq_selected_window;

/*
 * Clear the ACE on bit of the picture window that picture settings currently go to (pq_selected_window) and
 * write back only the low byte of the register. The counterpart of pq_ace_enable_for_window. Nothing in the
 * firmware refers to this routine: no call, branch, constant or address word.
 */
void pq_ace_disable_for_window(void)
{
    ACE_CTRL = (unsigned char)(ACE_CTRL & ~(1 << (pq_selected_window + ACE_ON_SHIFT)));
}
