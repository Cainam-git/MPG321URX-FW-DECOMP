/* leon2m FUN_a013b544 @ 0xa013b544-0xa013b5a0 (23 words), flags -mcpu=v8 -O3 -g. Callers: FUN_a014a2a0,
 * FUN_a014c7bc.
 * Replaces byte +2 of the 3-byte record at 0xa802a468 with c and keeps bytes +0 and +1: the body of FUN_a013b4e8
 * (stores the three bytes into the record, puts them into entries 3, 7 and 11 of a 12-entry halfword stack buffer
 * and calls FUN_a00f6fe4(bit 0 of byte 0xa802cbbc, bit 1 of that byte, buffer, 0x70)) is defined here as a static
 * function and inlined with the arguments (record byte 0, record byte 1, c).
 */
struct R468 { unsigned char a, b, c; };
extern struct R468 DAT_a802a468;
extern unsigned char DAT_a802cbbc;
extern void FUN_a00f6fe4(unsigned char, unsigned char, unsigned short *, int);

static void set3(unsigned char p1, unsigned char p2, unsigned char p3)
{
    unsigned short buf[12];

    DAT_a802a468.a = p1;
    DAT_a802a468.b = p2;
    DAT_a802a468.c = p3;
    buf[3] = p1;
    buf[7] = p2;
    buf[11] = p3;
    FUN_a00f6fe4(DAT_a802cbbc & 1, (DAT_a802cbbc >> 1) & 1, buf, 0x70);
}

void FUN_a013b544(unsigned char c)
{
    set3(DAT_a802a468.a, DAT_a802a468.b, c);
}
