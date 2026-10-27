/* FUN_a0134684 (leon2m 0xa0134684-0xa01346ac, 40 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Increments the byte DAT_a802cb8d and wraps it to 0 when the result is above 3. Nothing in the image refers to it:
 * no call, branch, sethi/or constant or address word. It lies between FUN_a013453c and FUN_a01346ac. Source form:
 * the incremented byte in a local, two separate stores in the if/else.
 */
extern unsigned char DAT_a802cb8d;

void FUN_a0134684(void)
{
    unsigned char n = DAT_a802cb8d + 1;

    if (n > 3)
        DAT_a802cb8d = 0;
    else
        DAT_a802cb8d = n;
}
