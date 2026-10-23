/* leon2m FUN_a00d4084 @ 0xa00d4084-0xa00d40c4 (64 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Limits byte 0xa802d290+0x49 to 5, stores it back and tail-calls FUN_a01471a0(0, 0xd, 3 * value) (byte argument).
 * Source form: the value is an unsigned short local passed as (unsigned char)v * 3, as in the same step of
 * FUN_a00dbcf0.
 */
struct R290 { unsigned char p000[0x49]; unsigned char b049; };
extern struct R290 DAT_a802d290;
extern void FUN_a01471a0(int, int, unsigned char);

void FUN_a00d4084(void)
{
    unsigned short v = DAT_a802d290.b049;

    if (v > 5)
        v = 5;
    DAT_a802d290.b049 = v;
    FUN_a01471a0(0, 0xd, (unsigned char)v * 3);
}
