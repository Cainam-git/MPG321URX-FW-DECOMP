/* leon2m FUN_a00ed530 @ 0xa00ed530-0xa00ed70c (119 words), flags -mcpu=v8 -O3 (no -g: the -g build puts a nop between the last call and the return). Caller: FUN_a00ed70c.
 * Writes v & 0xf to the register field (reg, mask, shift) of entry b of the word tables 0xa8026918 / 0xa8026908 /
 * 0xa80268f8 with FUN_a00e0774 (b == -1 passes the table addresses themselves), then the value 0 (v 6..11) or 1
 * (other v) to the fields of the tables 0xa80267c8 / 0xa80267b8 / 0xa80267a8 and 0xa8026868 / 0xa8026858 /
 * 0xa8026848. Returns 0.
 * Source form: each write is its own if (b == -1)/else statement (as in FUN_a00ed70c); v is masked to 4 bits
 * first.
 */
extern void FUN_a00e0774(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int DAT_a8026918[], DAT_a8026908[], DAT_a80268f8[];
extern unsigned int DAT_a80267c8[], DAT_a80267b8[], DAT_a80267a8[];
extern unsigned int DAT_a8026868[], DAT_a8026858[], DAT_a8026848[];

int FUN_a00ed530(unsigned int unit, int b, unsigned char v)
{
    v &= 0xf;
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a8026918, (unsigned int)DAT_a8026908, (unsigned int)DAT_a80268f8, v & 0xf);
    else
        FUN_a00e0774(unit, DAT_a8026918[b], DAT_a8026908[b], DAT_a80268f8[b], v & 0xf);
    if ((unsigned char)(v - 6) <= 5) {
        if (b == -1)
            FUN_a00e0774(unit, (unsigned int)DAT_a80267c8, (unsigned int)DAT_a80267b8, (unsigned int)DAT_a80267a8, 0);
        else
            FUN_a00e0774(unit, DAT_a80267c8[b], DAT_a80267b8[b], DAT_a80267a8[b], 0);
        if (b == -1)
            FUN_a00e0774(unit, (unsigned int)DAT_a8026868, (unsigned int)DAT_a8026858, (unsigned int)DAT_a8026848, 0);
        else
            FUN_a00e0774(unit, DAT_a8026868[b], DAT_a8026858[b], DAT_a8026848[b], 0);
    } else {
        if (b == -1)
            FUN_a00e0774(unit, (unsigned int)DAT_a80267c8, (unsigned int)DAT_a80267b8, (unsigned int)DAT_a80267a8, 1);
        else
            FUN_a00e0774(unit, DAT_a80267c8[b], DAT_a80267b8[b], DAT_a80267a8[b], 1);
        if (b == -1)
            FUN_a00e0774(unit, (unsigned int)DAT_a8026868, (unsigned int)DAT_a8026858, (unsigned int)DAT_a8026848, 1);
        else
            FUN_a00e0774(unit, DAT_a8026868[b], DAT_a8026858[b], DAT_a8026848[b], 1);
    }
    return 0;
}
