/* FUN_a0132850 (leon2m 0xa0132850-0xa01328d4, 132 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Calls FUN_a00fe718(c) as a tail call when c is 0, 1, 2 or 3. Nothing in the image refers to it: no call, branch,
 * sethi/or constant or address word. It lies between FUN_a01327e0 and FUN_a01328d4. Source form: a switch with a
 * constant argument per case.
 */
extern void FUN_a00fe718(unsigned char);

void FUN_a0132850(unsigned char c)
{
    switch (c) {
    case 0:
        FUN_a00fe718(0);
        break;
    case 1:
        FUN_a00fe718(1);
        break;
    case 2:
        FUN_a00fe718(2);
        break;
    case 3:
        FUN_a00fe718(3);
        break;
    }
}
