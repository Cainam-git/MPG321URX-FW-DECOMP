/* leon2m FUN_a01412b8 @ 0xa01412b8  panel power request (hand; -mcpu=v8 -O3 -g)
 *
 * on = 1 (power on) / 0 (power off) request to the panel power sequencer FUN_a01413d0 (same unit, state byte
 * DAT_a802e110.state: 1 = off, 2..5 = power-on steps, 6 = on, 7..9 = power-off steps). DAT_a802cc09 = 0 first, then:
 * - already moving that way (on: 2..5, off: 7..9) or already there (on: 6, off: 1): nothing more;
 * - moving the other way (on while 7..9, off while 2..5): DAT_a802cc09 = 1 (request pending), for on also
 *   DAT_a802e110.req = 1;
 * - otherwise start the sequence: state = 2 (on) or 7 (off; also for any other 'on' value).
 * The compiler sinks the first DAT_a802cc09 = 0 into each path (no store at entry in the firmware).
 * Call path: GlobalModeHandler state 10 -> panel power request.
 */
struct PwrSeq
{
  unsigned char state;
  unsigned short t;
  unsigned short req : 1;
  unsigned short rest : 15;
};
extern struct PwrSeq DAT_a802e110;
extern unsigned char DAT_a802cc09;

void FUN_a01412b8(unsigned char on)
{
    DAT_a802cc09 = 0;
    if ((on == 1 && (unsigned char)(DAT_a802e110.state - 2) <= 3) || (on == 0 && (unsigned char)(DAT_a802e110.state - 7) <= 2))
        ;
    else if ((on == 1 && DAT_a802e110.state == 6) || (on == 0 && DAT_a802e110.state == 1))
        ;
    else if ((on == 0 && (unsigned char)(DAT_a802e110.state - 2) <= 3) || (on == 1 && (unsigned char)(DAT_a802e110.state - 7) <= 2)) {
        DAT_a802cc09 = 1;
        if (on == 1)
            DAT_a802e110.req = 1;
    } else {
        if (on == 1)
            DAT_a802e110.state = 2;
        else
            DAT_a802e110.state = 7;
    }
}
