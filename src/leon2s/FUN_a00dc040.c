/* FUN_a00dc040 (leon2s 0xa00dc040-0xa00dc078, 56 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Stores v to the byte DAT_a807883a; when v is 0 also clears the bytes DAT_a80787ff, DAT_a80787fe,
 * DAT_a80787fd and DAT_a80787fc (each with its own sethi: separate symbols).
 */
extern unsigned char DAT_a807883a;
extern unsigned char DAT_a80787ff;
extern unsigned char DAT_a80787fe;
extern unsigned char DAT_a80787fd;
extern unsigned char DAT_a80787fc;

void FUN_a00dc040(unsigned char v)
{
    DAT_a807883a = v;
    if (v == 0) {
        DAT_a80787ff = 0;
        DAT_a80787fe = 0;
        DAT_a80787fd = 0;
        DAT_a80787fc = 0;
    }
}
