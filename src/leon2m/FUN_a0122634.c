/* leon2m FUN_a0122634 @ 0xa0122634-0xa01227f0 (111 words).
 * For one of four register groups chosen by sel (4 = all four; the same groups as FUN_a0122480): n == 0 writes 0
 * to the group's control register (0xcf01cd0c / cd98 / ce24 / ceb0); otherwise it writes 0xff there and the low
 * byte of n * 17 - 17 to the four registers before it (0xcf01ccfc..cd08 / cd88..cd94 / ce14..ce20 / cea0..ceac).
 * No direct callers (reached through a pointer). volatile: hardware registers only.
 * Source form: the value n * 17 - 17 is computed once into an unsigned int local and narrowed at each store.
 */
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a0122634(unsigned int sel, unsigned int n)
{
    unsigned int x = n * 17 - 17;

    if (sel == 0 || sel == 4) {
        if (!n)
            R(0xcf01cd0c) = 0;
        else {
            R(0xcf01cd0c) = 0xff;
            R(0xcf01ccfc) = (unsigned char)x;
            R(0xcf01cd00) = (unsigned char)x;
            R(0xcf01cd04) = (unsigned char)x;
            R(0xcf01cd08) = (unsigned char)x;
        }
    }
    if (sel == 1 || sel == 4) {
        if (!n)
            R(0xcf01cd98) = 0;
        else {
            R(0xcf01cd98) = 0xff;
            R(0xcf01cd88) = (unsigned char)x;
            R(0xcf01cd8c) = (unsigned char)x;
            R(0xcf01cd90) = (unsigned char)x;
            R(0xcf01cd94) = (unsigned char)x;
        }
    }
    if (sel == 2 || sel == 4) {
        if (!n)
            R(0xcf01ce24) = 0;
        else {
            R(0xcf01ce24) = 0xff;
            R(0xcf01ce14) = (unsigned char)x;
            R(0xcf01ce18) = (unsigned char)x;
            R(0xcf01ce1c) = (unsigned char)x;
            R(0xcf01ce20) = (unsigned char)x;
        }
    }
    if (sel == 3 || sel == 4) {
        if (!n)
            R(0xcf01ceb0) = 0;
        else {
            R(0xcf01ceb0) = 0xff;
            R(0xcf01cea0) = (unsigned char)x;
            R(0xcf01cea4) = (unsigned char)x;
            R(0xcf01cea8) = (unsigned char)x;
            R(0xcf01ceac) = (unsigned char)x;
        }
    }
}
