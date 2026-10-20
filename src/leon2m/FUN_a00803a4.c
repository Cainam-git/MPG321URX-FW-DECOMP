/* leon2m FUN_a00803a4 @ 0xa00803a4  check of up to four sources (callee of the OLED FRC handler FUN_a01295e4,
 * which calls FUN_a00dac38(1,1,1) only when this returns 1)
 *
 * For i = 0..3, source i is checked when: i == 0 always; i == 1 when byte 0xA802D2AF (+0x1F of 0xA802D290) != 0;
 * i == 2 when that byte is 4..7; i == 3 when it is 7. A checked source whose FUN_a0143c14(i) (low byte) is above 4
 * makes the result 0 at once; otherwise the result is 1. The source tests are an if/else-if chain on i
 * (not a switch), sel = 0 at the top of each round.
 */
struct Frc { unsigned char b00[0x1f]; unsigned char b1f; };
extern struct Frc DAT_a802d290;
extern unsigned char FUN_a0143c14(unsigned char);
unsigned char FUN_a00803a4(void)
{
    unsigned char ok = 1;
    unsigned char i;
    for (i = 0; i <= 3; i++) {
        unsigned char sel = 0;
        if (i == 0) sel = 1;
        else if (i == 1) { if (DAT_a802d290.b1f != 0) sel = 1; }
        else if (i == 2) { if ((unsigned char)(DAT_a802d290.b1f - 4) <= 3) sel = 1; }
        else if (i == 3) { if (DAT_a802d290.b1f == 7) sel = 1; }
        if (sel && FUN_a0143c14(i) > 4) { ok = 0; break; }
    }
    return ok & 1;
}
