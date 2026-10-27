/* FUN_a014a258 (leon2m 0xa014a258-0xa014a2a0, 72 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores v to the byte DAT_a802e3e5, DAT_a802e3e6 or DAT_a802e3e7 for c = 0, 1 or 2; other values do nothing.
 * Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a014a210 and FUN_a014a2a0. Source form: a switch with one extern byte per case.
 */
extern unsigned char DAT_a802e3e5, DAT_a802e3e6, DAT_a802e3e7;

void FUN_a014a258(unsigned char c, unsigned char v)
{
    switch (c) {
    case 0:
        DAT_a802e3e5 = v;
        break;
    case 1:
        DAT_a802e3e6 = v;
        break;
    case 2:
        DAT_a802e3e7 = v;
        break;
    }
}
