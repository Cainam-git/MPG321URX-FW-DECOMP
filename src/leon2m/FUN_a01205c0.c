/* leon2m FUN_a01205c0 @ 0xa01205c0-0xa0120638 (30 words).
 * For n = 1, 2 or 3 replaces the low two bits of hardware register 0xcf0116d8 with n (keeps bits 2-7, clears bits
 * 8-31); other n leave the register unchanged. FUN_a0120638 reads the same two bits. Called from FUN_a01423dc.
 * An if/else chain with one read-modify-write per value (a switch gives a range test instead of the compare chain).
 */
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a01205c0(unsigned char n)
{
    if (n == 1)
        R(0xcf0116d8) = (R(0xcf0116d8) & 0xfc) | 1;
    else if (n == 2)
        R(0xcf0116d8) = (R(0xcf0116d8) & 0xfc) | 2;
    else if (n == 3)
        R(0xcf0116d8) = (R(0xcf0116d8) & 0xfc) | 3;
}
