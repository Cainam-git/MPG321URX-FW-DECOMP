/* leon2m FUN_a00eb708 @ 0xa00eb708-0xa00eba64 (860 bytes), flags -mcpu=v8 -O3 -g. Callers: FUN_a00eba64,
 * FUN_a00ec6b8. FUN_a00eb708(unit, b, d): register fields written with FUN_a00e0774, (reg, mask, shift) from entry b
 * of three word tables (b == -1 passes the table addresses themselves, as in FUN_a00e9c80 / FUN_a00ec340), with
 * w = the word DAT_a802d66c: field(0xa8026918/908/8f8) = w; field(0xa80268e8/8d8/8c8) = w + d;
 * field(0xa80268b8/8a8/898) = w + d - 4; field(0xa8026948/938/928) = 3 when d > 8, else 0; then 0 to the fields
 * (0xa8026768/758, 0xa802b6e8), (0xa8026718/708, 0xa802b6d8), (0xa8026798/788/778) and (0xa8026748/738/728).
 * Source form: each write is its own if (b == -1)/else statement (GCC threads the repeated tests); the d > 8 arm
 * first; DAT_a802d66c read again for each value.
 */
extern unsigned int DAT_a802d66c;
extern void FUN_a00e0774(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int DAT_a8026918[], DAT_a8026908[], DAT_a80268f8[], DAT_a80268e8[], DAT_a80268d8[], DAT_a80268c8[], DAT_a80268b8[], DAT_a80268a8[], DAT_a8026898[], DAT_a8026948[], DAT_a8026938[], DAT_a8026928[], DAT_a8026768[], DAT_a8026758[], DAT_a802b6e8[], DAT_a8026718[], DAT_a8026708[], DAT_a802b6d8[], DAT_a8026798[], DAT_a8026788[], DAT_a8026778[], DAT_a8026748[], DAT_a8026738[], DAT_a8026728[];

void FUN_a00eb708(unsigned int unit, int b, int d)
{
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a8026918, (unsigned int)DAT_a8026908, (unsigned int)DAT_a80268f8, DAT_a802d66c);
    else
        FUN_a00e0774(unit, DAT_a8026918[b], DAT_a8026908[b], DAT_a80268f8[b], DAT_a802d66c);
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a80268e8, (unsigned int)DAT_a80268d8, (unsigned int)DAT_a80268c8, DAT_a802d66c + d);
    else
        FUN_a00e0774(unit, DAT_a80268e8[b], DAT_a80268d8[b], DAT_a80268c8[b], DAT_a802d66c + d);
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a80268b8, (unsigned int)DAT_a80268a8, (unsigned int)DAT_a8026898, DAT_a802d66c + d - 4);
    else
        FUN_a00e0774(unit, DAT_a80268b8[b], DAT_a80268a8[b], DAT_a8026898[b], DAT_a802d66c + d - 4);
    if (d > 8) {
        if (b == -1)
            FUN_a00e0774(unit, (unsigned int)DAT_a8026948, (unsigned int)DAT_a8026938, (unsigned int)DAT_a8026928, 3);
        else
            FUN_a00e0774(unit, DAT_a8026948[b], DAT_a8026938[b], DAT_a8026928[b], 3);
    } else {
        if (b == -1)
            FUN_a00e0774(unit, (unsigned int)DAT_a8026948, (unsigned int)DAT_a8026938, (unsigned int)DAT_a8026928, 0);
        else
            FUN_a00e0774(unit, DAT_a8026948[b], DAT_a8026938[b], DAT_a8026928[b], 0);
    }
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a8026768, (unsigned int)DAT_a8026758, (unsigned int)DAT_a802b6e8, 0);
    else
        FUN_a00e0774(unit, DAT_a8026768[b], DAT_a8026758[b], DAT_a802b6e8[b], 0);
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a8026718, (unsigned int)DAT_a8026708, (unsigned int)DAT_a802b6d8, 0);
    else
        FUN_a00e0774(unit, DAT_a8026718[b], DAT_a8026708[b], DAT_a802b6d8[b], 0);
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a8026798, (unsigned int)DAT_a8026788, (unsigned int)DAT_a8026778, 0);
    else
        FUN_a00e0774(unit, DAT_a8026798[b], DAT_a8026788[b], DAT_a8026778[b], 0);
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a8026748, (unsigned int)DAT_a8026738, (unsigned int)DAT_a8026728, 0);
    else
        FUN_a00e0774(unit, DAT_a8026748[b], DAT_a8026738[b], DAT_a8026728[b], 0);
}
