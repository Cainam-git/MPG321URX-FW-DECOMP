/* leon2m FUN_a0146298 @ 0xa0146298-0xa0146324 (35 words), flags -mcpu=v8 -O3 -g, leaf (sibling call).
 * Calls FUN_a0119698(k, v) with k = n: a switch on n (jump table 0xa01432c8, cases 0..4) sets k to the case
 * value, the default case to n. GCC copies the call block into every case (case order in the image 3, 4, 0, 1, 2;
 * the default enters case 3's copy after its 'mov 3'), each copy masking v to a byte.
 * Source form: k is an unsigned char initialised to n in its declaration, the switch assigns k in every case
 * (default: k = n), and one call follows the switch.
 */
extern void FUN_a0119698(unsigned int blk, unsigned int v);

void FUN_a0146298(unsigned char n, unsigned char v)
{
    unsigned char k = n;

    switch (n) {
    case 0:
        k = 0;
        break;
    case 1:
        k = 1;
        break;
    case 2:
        k = 2;
        break;
    case 3:
        k = 3;
        break;
    case 4:
        k = 4;
        break;
    default:
        k = n;
        break;
    }
    FUN_a0119698(k, v);
}
