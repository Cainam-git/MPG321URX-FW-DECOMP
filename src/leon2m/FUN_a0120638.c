/* leon2m FUN_a0120638 @ 0xa0120638-0xa0120678 (64 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Reads the low two bits v of register 0xcf0116d8 and returns 2 for v == 2, 3 for v == 3, otherwise 1 (masked
 * with 3).
 * Source form: a switch with 'default' first, then case 2 and case 3, into an unsigned char result (GCC turns the
 * v == 3 / default pair into the (-(v == 3) & 2) + 1 store-flag sequence).
 */
#define REG_cf0116d8 (*(volatile unsigned int *)0xcf0116d8)

unsigned char FUN_a0120638(void)
{
    unsigned int v = REG_cf0116d8 & 3;
    unsigned char r;

    switch (v) {
    default:
        r = 1;
        break;
    case 2:
        r = 2;
        break;
    case 3:
        r = 3;
        break;
    }
    return r & 3;
}
