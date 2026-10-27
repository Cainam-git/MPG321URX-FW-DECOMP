/* leon2m FUN_a00edc70 @ 0xa00edc70-0xa00ee188 (326 words), flags -mcpu=v8 -O3 -g. Called by FUN_a00ee1e8.
 * Returns the two-word structure {a, b}; {-1, -1} when idx > 0x49 or (byte 0 of entry idx of the 3-byte table
 * DAT_a8026998) & 0x3f is above 0x32. Otherwise FUN_a00e406c(unit, 6, 6, (m << 10) | 0x80), FUN_a00dffa4(1) and
 * FUN_a00e406c(unit, 6, 6, (m << 10) | x | 0x80) with x = that table byte; six register fields are read with
 * FUN_a00e0754 (reg, mask and shift from entry b of three word tables, b == -1 passes the table addresses
 * themselves): 0xa80268e8/d8/c8, 0xa80268b8/a8/98, 0xa8026798/88/78, 0xa8026768/58 + 0xa802b6e8,
 * 0xa8026748/38/28, 0xa8026718/08 + 0xa802b6d8. res = FUN_a00ec6b8(unit, p1, p2, b, p9, p8); the six fields are
 * written back with FUN_a00e0774 in the same order. Unless both words of res are -1, each word w becomes
 * (w >> 8) * k + (w & 0xff).
 * Source form: each read and write is its own if (b == -1)/else statement (as in FUN_a00e9c80); the table at
 * 0xa8026718 is declared as ARR_a8026718: the symbol name sets the order of the address pseudos and so the
 * register choices.
 */
struct win { int a; int b; };
extern void FUN_a00dffa4();
extern void FUN_a00e406c(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int FUN_a00e0754(unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00e0774(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern struct win FUN_a00ec6b8(unsigned int, unsigned int, unsigned int, int, unsigned int, unsigned int);
extern unsigned char DAT_a8026998[][3];
extern unsigned int DAT_a80268e8[], DAT_a80268d8[], DAT_a80268c8[];
extern unsigned int DAT_a80268b8[], DAT_a80268a8[], DAT_a8026898[];
extern unsigned int DAT_a8026798[], DAT_a8026788[], DAT_a8026778[];
extern unsigned int DAT_a8026768[], DAT_a8026758[], DAT_a802b6e8[];
extern unsigned int DAT_a8026748[], DAT_a8026738[], DAT_a8026728[];
extern unsigned int ARR_a8026718[], DAT_a8026708[], DAT_a802b6d8[];


struct win FUN_a00edc70(unsigned int unit, unsigned int p1, unsigned int p2, unsigned int m, unsigned int idx, int b,
                        int k, unsigned int p8, unsigned int p9)
{
    struct win res;
    unsigned char x;
    unsigned int s1, s2, s3, s4, s5, s6;

    if (idx > 0x49 || (DAT_a8026998[idx][0] & 0x3f) > 0x32U) {
        res.b = -1;
        res.a = -1;
        return res;
    }
    x = DAT_a8026998[idx][0];
    FUN_a00e406c(unit, 6, 6, (m << 10) | 0x80);
    FUN_a00dffa4(1);
    FUN_a00e406c(unit, 6, 6, (m << 10) | x | 0x80);
    if (b == -1)
        s1 = FUN_a00e0754(unit, (unsigned int)DAT_a80268e8, (unsigned int)DAT_a80268d8, (unsigned int)DAT_a80268c8);
    else
        s1 = FUN_a00e0754(unit, DAT_a80268e8[b], DAT_a80268d8[b], DAT_a80268c8[b]);
    if (b == -1)
        s2 = FUN_a00e0754(unit, (unsigned int)DAT_a80268b8, (unsigned int)DAT_a80268a8, (unsigned int)DAT_a8026898);
    else
        s2 = FUN_a00e0754(unit, DAT_a80268b8[b], DAT_a80268a8[b], DAT_a8026898[b]);
    if (b == -1)
        s3 = FUN_a00e0754(unit, (unsigned int)DAT_a8026798, (unsigned int)DAT_a8026788, (unsigned int)DAT_a8026778);
    else
        s3 = FUN_a00e0754(unit, DAT_a8026798[b], DAT_a8026788[b], DAT_a8026778[b]);
    if (b == -1)
        s4 = FUN_a00e0754(unit, (unsigned int)DAT_a8026768, (unsigned int)DAT_a8026758, (unsigned int)DAT_a802b6e8);
    else
        s4 = FUN_a00e0754(unit, DAT_a8026768[b], DAT_a8026758[b], DAT_a802b6e8[b]);
    if (b == -1)
        s5 = FUN_a00e0754(unit, (unsigned int)DAT_a8026748, (unsigned int)DAT_a8026738, (unsigned int)DAT_a8026728);
    else
        s5 = FUN_a00e0754(unit, DAT_a8026748[b], DAT_a8026738[b], DAT_a8026728[b]);
    if (b == -1)
        s6 = FUN_a00e0754(unit, (unsigned int)ARR_a8026718, (unsigned int)DAT_a8026708, (unsigned int)DAT_a802b6d8);
    else
        s6 = FUN_a00e0754(unit, ARR_a8026718[b], DAT_a8026708[b], DAT_a802b6d8[b]);
    res = FUN_a00ec6b8(unit, p1, p2, b, p9, p8);
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a80268e8, (unsigned int)DAT_a80268d8, (unsigned int)DAT_a80268c8, s1);
    else
        FUN_a00e0774(unit, DAT_a80268e8[b], DAT_a80268d8[b], DAT_a80268c8[b], s1);
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a80268b8, (unsigned int)DAT_a80268a8, (unsigned int)DAT_a8026898, s2);
    else
        FUN_a00e0774(unit, DAT_a80268b8[b], DAT_a80268a8[b], DAT_a8026898[b], s2);
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a8026798, (unsigned int)DAT_a8026788, (unsigned int)DAT_a8026778, s3);
    else
        FUN_a00e0774(unit, DAT_a8026798[b], DAT_a8026788[b], DAT_a8026778[b], s3);
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a8026768, (unsigned int)DAT_a8026758, (unsigned int)DAT_a802b6e8, s4);
    else
        FUN_a00e0774(unit, DAT_a8026768[b], DAT_a8026758[b], DAT_a802b6e8[b], s4);
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a8026748, (unsigned int)DAT_a8026738, (unsigned int)DAT_a8026728, s5);
    else
        FUN_a00e0774(unit, DAT_a8026748[b], DAT_a8026738[b], DAT_a8026728[b], s5);
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)ARR_a8026718, (unsigned int)DAT_a8026708, (unsigned int)DAT_a802b6d8, s6);
    else
        FUN_a00e0774(unit, ARR_a8026718[b], DAT_a8026708[b], DAT_a802b6d8[b], s6);
    if (res.b == -1 && res.a == -1)
        return res;
    res.a = (res.a >> 8) * k + (res.a & 0xff);
    res.b = (res.b >> 8) * k + (res.b & 0xff);
    return res;
}
