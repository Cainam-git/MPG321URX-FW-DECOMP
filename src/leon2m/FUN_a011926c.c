/* FUN_a011926c (leon2m 0xa011926c-0xa01192d0, 100 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Rounds a up to a multiple of 36 when the byte DAT_a802c9c0[b] is 0x18 ((a + 35) / 36 * 36), otherwise up to a
 * multiple of 9. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies
 * between FUN_a01191fc and FUN_a01192d0.
 */
extern unsigned char DAT_a802c9c0[];

unsigned int FUN_a011926c(unsigned int a, unsigned char b)
{
    if (DAT_a802c9c0[b] == 0x18)
        return (a + 0x23) / 36 * 36;
    return (a + 8) / 9 * 9;
}
