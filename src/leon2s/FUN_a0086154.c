/* FUN_a0086154 (leon2s 0xa0086154-0xa00862e4, 400 bytes), flags -mcpu=v8 -Os -g.
 * (port, type, len, out). n = 1 for type 0x80 / 0x40 / 0, else len + 2 (signed char). DAT_a8078a0e = 0 and
 * DAT_a807cd50[0] = 0xff; while bit 3 of FUN_a00a78b4(port, 0x34) is set: reads FUN_a00a78b4(port, 0x37) into
 * DAT_a807cd50[DAT_a8078a0e++] while DAT_a8078a0e < n (else the read is discarded), then
 * FUN_a00a7940(port, 0x34, 8, 1). DAT_a807cd50[0] == 0: for type 0x80 / 0x40 / 0 returns 0 when one byte was
 * read, else 0xff; for other types, when DAT_a8078a0e == n copies DAT_a807cd50[1..n-1] to out[0..n-2] and
 * returns 0, else 0xff. DAT_a807cd50[0] == 0x20 returns 0x20; other values return 0xff.
 * Callers: FUN_a00862e4 (its fifth parameter is out).
 * Source form: out is 'volatile unsigned char *', the type of the buffer the caller chain passes in:
 * FUN_a00883d0 (volatile DAT_a80789f0) -> FUN_a0086400 -> FUN_a00862e4 -> out. The volatile store keeps the
 * copy-loop stb before the loop cmp; the bl slot is filled from the loop head.
 */
extern unsigned char DAT_a807cd50[];
extern unsigned char DAT_a8078a0e;
extern unsigned char FUN_a00a78b4(unsigned char, unsigned char);
extern void FUN_a00a7940(unsigned char, unsigned char, unsigned char, unsigned char);

unsigned char FUN_a0086154(unsigned char port, unsigned char type, unsigned char len, volatile unsigned char *out)
{
    signed char n;
    unsigned char i;

    if (type == 0x80 || type == 0x40 || type == 0)
        n = 1;
    else
        n = len + 2;
    DAT_a8078a0e = 0;
    DAT_a807cd50[0] = 0xff;
    while (FUN_a00a78b4(port, 0x34) & 8) {
        if (DAT_a8078a0e < n)
            DAT_a807cd50[DAT_a8078a0e++] = FUN_a00a78b4(port, 0x37);
        else
            FUN_a00a78b4(port, 0x37);
        FUN_a00a7940(port, 0x34, 8, 1);
    }
    if (DAT_a807cd50[0] == 0) {
        if (type == 0x80 || type == 0x40 || type == 0) {
            if (DAT_a8078a0e == 1)
                return 0;
            return 0xff;
        }
        if (DAT_a8078a0e == n) {
            for (i = 1; i < n; i++)
                out[i - 1] = DAT_a807cd50[i];
            return 0;
        }
        return 0xff;
    }
    if (DAT_a807cd50[0] == 0x20)
        return 0x20;
    return 0xff;
}
