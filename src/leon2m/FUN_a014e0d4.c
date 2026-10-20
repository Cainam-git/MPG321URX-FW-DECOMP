/* leon2m FUN_a014e0d4 @ 0xa014e0d4-0xa014e144 (28 words).
 * Tail-calls FUN_a010adc0(a, b) with (a, b) = (0, 0) for v 0, (0, 1) for v 1, (1, 0) for v 2 and (1, 1) for v 3;
 * other values do nothing. Routine after FUN_a014e0a4 (separated from FUN_a014e050 in the function table).
 */
extern void FUN_a010adc0(unsigned char, unsigned char);

void FUN_a014e0d4(unsigned char v)
{
    switch (v) {
    case 0:
        FUN_a010adc0(0, 0);
        break;
    case 1:
        FUN_a010adc0(0, 1);
        break;
    case 2:
        FUN_a010adc0(1, 0);
        break;
    case 3:
        FUN_a010adc0(1, 1);
        break;
    }
}
