/* FUN_a0094fb0 (leon2s 0xa0094fb0-0xa0095054, 164 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Tail-calls FUN_a00734c4 with one of eight data addresses selected by v: 0..5 -> DAT_a00691f0, DAT_a0069210, DAT_a0069230,
 * DAT_a0069250, DAT_a0069270, DAT_a0069290; 6 -> DAT_a00692d0; any other value -> DAT_a00692b0. An if/else chain with one
 * call per arm (the firmware shares the call).
 */
extern char DAT_a00691f0[], DAT_a0069210[], DAT_a0069230[], DAT_a0069250[], DAT_a0069270[], DAT_a0069290[], DAT_a00692b0[],
    DAT_a00692d0[];
extern int FUN_a00734c4(const char *);

void FUN_a0094fb0(unsigned char v)
{
    if (v == 0)
        FUN_a00734c4(DAT_a00691f0);
    else if (v == 1)
        FUN_a00734c4(DAT_a0069210);
    else if (v == 2)
        FUN_a00734c4(DAT_a0069230);
    else if (v == 3)
        FUN_a00734c4(DAT_a0069250);
    else if (v == 4)
        FUN_a00734c4(DAT_a0069270);
    else if (v == 5)
        FUN_a00734c4(DAT_a0069290);
    else if (v == 6)
        FUN_a00734c4(DAT_a00692d0);
    else
        FUN_a00734c4(DAT_a00692b0);
}
