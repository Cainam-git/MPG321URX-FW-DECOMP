/* leon2m FUN_a0147790 @ 0xa0147790-0xa0147814 (33 words).
 * Returns the value of FUN_a00fc334() when it is 0..4, 6 or 7 (jump table). For 5 it returns 5 only when
 * FUN_a00fca40() (the 3-word routine at 0xa00fca40 that returns byte 0xa802c97f) returns 0x40, and 0 otherwise;
 * values above 7 give 0. Source form: case 5 breaks on 0x40 and otherwise falls through into the default arm.
 * Called from FUN_a0085984.
 */
extern int FUN_a00fc334(void);
extern unsigned char FUN_a00fca40(void);

int FUN_a0147790(void)
{
    int r;

    switch (FUN_a00fc334()) {
    case 0:
        r = 0;
        break;
    case 1:
        r = 1;
        break;
    case 2:
        r = 2;
        break;
    case 3:
        r = 3;
        break;
    case 4:
        r = 4;
        break;
    case 5:
        r = 5;
        if (FUN_a00fca40() == 0x40)
            break;
    default:
        r = 0;
        break;
    case 6:
        r = 6;
        break;
    case 7:
        r = 7;
        break;
    }
    return r;
}
