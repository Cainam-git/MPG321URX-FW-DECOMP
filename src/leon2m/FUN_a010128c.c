/* FUN_a010128c (leon2m 0xa010128c-0xa01012a8, 28 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Returns 1 when c is 0 or 1, otherwise 0. Nothing in the image refers to it: no call, branch, sethi/or constant or
 * address word. It lies between FUN_a01011c0 and FUN_a01012a8. Source form: a switch with cases 0 and 1 (GCC emits
 * one unsigned range compare, cmp 1 / bleu, with the 1 in the delay slot).
 */
unsigned char FUN_a010128c(unsigned char c)
{
    switch (c) {
    case 0:
    case 1:
        return 1;
    default:
        return 0;
    }
}
