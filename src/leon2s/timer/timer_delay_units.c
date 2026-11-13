/* timer_delay_units  (FUN_a00b160c)
 *
 * Wait in a counted idle loop for a number of delay units.
 * Name basis: proven - outer 16-bit counter with an inner idle loop
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source form: five separate loops, one per range of units, each 'for (pass_count = 0; pass_count < N; ...)
 * nop' inside a do/while on the 16-bit round counter; the inner test 'pass_count < count' compiles to
 * cmp %g1, count - 1 / bleu after the increment (cmp %g1, 0x30 for 0x31).
 */
extern void timer_delay_units(unsigned int units);

/*
 * Busy-wait for a number of delay units; it reads no timer, so it takes as long as the loops take to run.
 *
 *   units  number of outer rounds (a 16-bit counter counts them); 0 returns at once
 *
 * Each round runs an inner loop of nops. The length of that loop depends on units: 0x21 passes for
 * 0..4 units, 0x2E for 5..0x13, 0x2F for 0x14..0x5F, 0x30 for 0x60..0x1EA, 0x31 above 0x1EA. The five
 * loops are written out one by one because the compare constant differs.
 * Callers: waits in the HDMI and audio set-up code, with 1, 5, 0x14, 100 or 500 units.
 */
void timer_delay_units(unsigned int units)
{
    unsigned short round;
    unsigned short pass_count;
    
    if (units > 0x1ea) {
        round = 0;
        if (units != 0) {
            do {
                for (pass_count = 0; pass_count < 0x31; pass_count++) __asm__("nop");
                round = round + 1;
            } while ((round & 0xffff) < units);
        }
    }
    else if (units > 0x5f) {
        round = 0;
        if (units != 0) {
            do {
                for (pass_count = 0; pass_count < 0x30; pass_count++) __asm__("nop");
                round = round + 1;
            } while ((round & 0xffff) < units);
        }
    }
    else if (units > 0x13) {
        round = 0;
        if (units != 0) {
            do {
                for (pass_count = 0; pass_count < 0x2f; pass_count++) __asm__("nop");
                round = round + 1;
            } while ((round & 0xffff) < units);
        }
    }
    else if (units > 4) {
        round = 0;
        if (units != 0) {
            do {
                for (pass_count = 0; pass_count < 0x2e; pass_count++) __asm__("nop");
                round = round + 1;
            } while ((round & 0xffff) < units);
        }
    }
    else {
        round = 0;
        if (units != 0) {
            do {
                for (pass_count = 0; pass_count < 0x21; pass_count++) __asm__("nop");
                round = round + 1;
            } while ((round & 0xffff) < units);
        }
    }
    return;
}
