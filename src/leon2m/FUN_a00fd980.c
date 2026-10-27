/* FUN_a00fd980 (leon2m 0xa00fd980-0xa00fd9a0, 32 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * When c is non-zero, stores it to the byte DAT_a802c980 and returns 1; otherwise returns 0. Nothing in the image
 * refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a00fd820 and FUN_a00fd9a0.
 * Source form: an int result variable set to 0 and to 1 (returned through %g1).
 */
extern unsigned char DAT_a802c980;

int FUN_a00fd980(unsigned char c)
{
    int r = 0;

    if (c != 0) {
        DAT_a802c980 = c;
        r = 1;
    }
    return r;
}
