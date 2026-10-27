/* FUN_a00c0db4 (leon2m 0xa00c0db4-0xa00c0de0, 44 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores 1 to the byte DAT_a802b09b when c is 0 or 4. Nothing in the image refers to it: no call, branch, sethi/or
 * constant or address word. It lies between FUN_a00c0d10 and FUN_a00c0de0. Source form: a switch with cases 0 and
 * 4.
 */
extern unsigned char DAT_a802b09b;
void FUN_a00c0db4(unsigned char c)
{
    switch (c) {
    case 0:
    case 4:
        DAT_a802b09b = 1;
        break;
    }
}
