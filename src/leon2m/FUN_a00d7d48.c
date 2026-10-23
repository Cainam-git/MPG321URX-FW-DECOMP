/* leon2m FUN_a00d7d48 @ 0xa00d7d48-0xa00d7de0 (38 words).
 * Returns 4 when FUN_a014bd70(0) is 1. Otherwise, when FUN_a01438dc(0) is 1, maps FUN_a014ba68() 1, 2, 3, 4
 * to 1, 2, 3, 5; every other case returns 0. Called from many routines (FUN_a0099864, FUN_a00a0508, ...).
 * Source form: an int result initialised to 5 and set in each arm of the switch.
 */
extern unsigned char FUN_a014bd70(unsigned char ch);
extern unsigned char FUN_a01438dc(unsigned char ch);
extern unsigned char FUN_a014ba68(void);

int FUN_a00d7d48(void)
{
    int r = 5;

    if (FUN_a014bd70(0) == 1)
        r = 4;
    else if (FUN_a01438dc(0) == 1) {
        switch (FUN_a014ba68()) {
        case 1: r = 1; break;
        case 2: r = 2; break;
        case 3: r = 3; break;
        case 4: r = 5; break;
        default: r = 0; break;
        }
    } else
        r = 0;
    return r;
}
