/* FUN_a01192d0 (leon2m 0xa01192d0-0xa011932c, 92 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Rounds a down to a multiple of 36 when the byte DAT_a802c9c0[b] is 0x18, otherwise to a multiple of 9. Nothing in
 * the image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a011926c and
 * FUN_a011932c.
 */
extern unsigned char DAT_a802c9c0[];

unsigned int FUN_a01192d0(unsigned int a, unsigned char b)
{
    if (DAT_a802c9c0[b] == 0x18)
        return a / 36 * 36;
    return a / 9 * 9;
}
