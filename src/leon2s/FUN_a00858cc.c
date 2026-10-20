/* FUN_a00858cc (leon2s 0xa00858cc-0xa00858f0, 36 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Stores byte v into DAT_a807cd02 when port is 0, otherwise into DAT_a807cd2c. Called from FUN_a0070b7c.
 * DAT_a807cd02 is declared volatile, as in FUN_a0087734: in every function that accesses it (FUN_a00858cc,
 * FUN_a0087734, FUN_a00883d0) the firmware keeps the access out of the branch delay slot, which GCC does only for
 * volatile objects; DAT_a807cd2c is accessed normally.
 */
extern volatile unsigned char DAT_a807cd02;
extern unsigned char DAT_a807cd2c;

void FUN_a00858cc(unsigned char port, unsigned char v)
{
    if (port == 0)
        DAT_a807cd02 = v;
    else
        DAT_a807cd2c = v;
}
