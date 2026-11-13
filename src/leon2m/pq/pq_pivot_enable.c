/* pq_pivot_enable  (FUN_a010a2cc)
 *
 * Switch picture rotation on (mode 1 or 2) or off.
 * Name basis: proven - prints 'PIVOT_Enable' / 'PIVOT_Disable'; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010a2cc @ 0xa010a2cc-0xa010a3a8 (55 words), flags -mcpu=v8 -O3 -g.
 */
#define REG_cf01e400 (*(volatile unsigned int *)0xcf01e400)
#define REG_cf01e600 (*(volatile unsigned int *)0xcf01e600)
#define REG_cf01ea40 (*(volatile unsigned int *)0xcf01ea40)   /* bit 7 is read by pq_pivot_is_enabled */

#define PIVOT_ENABLE_BIT 0x10          /* bit 4 of REG_cf01e400 and REG_cf01e600 */
#define PIVOT_MODE_MASK  0xc0          /* bits 6-7 of REG_cf01ea40 */
#define PIVOT_MODE1_BITS 0x81          /* mode 1: bits 6-7 = 10, bit 0 set */
#define PIVOT_MODE2_BITS 0xc1          /* mode 2: bits 6-7 = 11, bit 0 set */
#define PIVOT_LOW_BITS_MASK 0x3f       /* bits 0-5 of REG_cf01ea40 */
#define PIVOT_DELAY_TICKS 200          /* timer_sleep_ticks between the two bit-4 writes */

extern int dbg_printf(const char *fmt, ...);
extern void timer_sleep_ticks(int ticks);

/*
 * Switch picture rotation on (mode 1 or 2) or off (any other mode).
 *
 * Mode 1 or 2: set bit 4 of REG_cf01e400, sleep PIVOT_DELAY_TICKS (timer_sleep_ticks(200)), set bit 4 of
 * REG_cf01e600, then give REG_cf01ea40 bits 7..6 = 10 (mode 1) or 11 (mode 2) and set bit 0, keeping bits 1..5
 * (bits 8..31 cleared); print "PIVOT_Enable".
 * Other modes: clear bits 6..7 of REG_cf01ea40 (bit 0 stays) and bit 4 of REG_cf01e400 and REG_cf01e600;
 * print "PIVOT_Disable".
 *
 * Nothing calls this routine.
 */
void pq_pivot_enable(unsigned char mode)
{
    if ((unsigned char)(mode - 1) <= 1) {   /* mode is 1 or 2 */
        REG_cf01e400 |= PIVOT_ENABLE_BIT;
        timer_sleep_ticks(PIVOT_DELAY_TICKS);
        REG_cf01e600 |= PIVOT_ENABLE_BIT;
        if (mode == 1)
            REG_cf01ea40 = (REG_cf01ea40 & PIVOT_LOW_BITS_MASK) | PIVOT_MODE1_BITS;
        else
            REG_cf01ea40 = (REG_cf01ea40 & PIVOT_LOW_BITS_MASK) | PIVOT_MODE2_BITS;
        dbg_printf("\nPIVOT_Enable\r\n");
    } else {
        REG_cf01ea40 &= ~PIVOT_MODE_MASK;
        REG_cf01e400 &= ~PIVOT_ENABLE_BIT;
        REG_cf01e600 &= ~PIVOT_ENABLE_BIT;
        dbg_printf("\nPIVOT_Disable\r\n");
    }
}
