/* fwupd_wait_ready_line  (FUN_CODE_d059)
 *
 * Wait until the main chip's ready line P1.1 goes from low to high, with a time limit.
 *   limit: time limit in units of 0xFFFF polling rounds
 * Returns: 1 when the line was low and went high in time; 0 when the limit ran out or the line was already
 *   high
 * Name basis: derived - polls P1.1 while it is low for up to limit * 0xFFFF rounds; called after the service
 *   packets
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE. The round limit is formed as 'rounds = 0xffff; rounds = limit * rounds;'
 * (a 32-bit product, Keil long library).
 */
sfr P1 = 0x90;
sbit READY_LINE = P1 ^ 1;   /* P1.1, read after each service packet */
void timer_delay_units(unsigned char n);

#define ROUNDS_PER_UNIT  0xffff

/* fwupd_wait_ready_line: wait for P1.1 to go from low to high.
 *
 * limit: the time limit, in units of ROUNDS_PER_UNIT rounds of timer_delay_units(1).
 * Returns 1 when the line was low and went high before the limit ran out; 0 when the limit ran out, and also 0 when
 * the line was already high after the first wait (no polling then).
 *
 * The routine starts with timer_delay_units(2) and ends with timer_delay_units(1) in every case. The service
 * routines call it after their packets (limit 100, or 0x0FA0 after the flash status writes and the tag blocks). */
unsigned char fwupd_wait_ready_line(unsigned int limit)
{
    unsigned char ok;
    unsigned long rounds;
    ok = 1;
    rounds = ROUNDS_PER_UNIT;
    rounds = limit * rounds;
    timer_delay_units(2);
    if (!READY_LINE) {
        while (rounds > 0 && !READY_LINE) {
            timer_delay_units(1);
            rounds--;
        }
        if (rounds == 0) ok = 0; else ok = 1;
    } else ok = 0;
    timer_delay_units(1);
    return ok;
}
