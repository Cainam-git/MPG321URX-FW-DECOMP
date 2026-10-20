/* leon2m FUN_a00b2a1c @ 0xa00b2a1c-0xa00b2c18 (127 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Returns at once when (halfword 0xa802d006 == 5, bit 30 of word 0xa802d46c set and byte 0xa802d033 == 0), when
 * (halfword 0xa802d004 == 4, bit 31 of word 0xa802d46c set and byte 0xa802d033 == 0), or when byte 0xa802d474 or
 * byte 0xa802d475 is 1 (0xa802cff4 + 0x12 / + 0x10 / + 0x3f, 0xa802d290 + 0x1dc / + 0x1e4 / + 0x1e5). Otherwise
 * steps byte 0xa8025c55 backwards: with byte 0xa802d033 not 0 to (v + 3) & 3 (bit 15 of halfword 0xa802d00c set)
 * or (v + 2) & 3, then to 0 when it is 1 and byte 0xa802d472 is above 2, and calls FUN_a00b0710(3, v); with byte
 * 0xa802d033 == 0 to (v + 1) % 3 and FUN_a00b0710(2, v) (bit 15 set) or to (v + 1) & 1 and FUN_a00b0710(1, v). Finally,
 * unless the new value is 2 or 3, it is written into bit 15 of halfword 0xa802d002 (0xa802cff4 + 0xe). FUN_a00b27fc
 * steps forwards.
 */
struct Rcff4 {
    unsigned char pad[0xe];
    unsigned short he, h10, h12;
    unsigned char pad14[4];
    struct { unsigned short b15 : 1, rest : 15; } h18;
    unsigned char pad1a[0x25];
    unsigned char b3f;
};
struct R290 {
    unsigned char pad[0x1dc];
    unsigned int w1dc;
    unsigned char pad1e0[2];
    unsigned char b1e2, b1e3, b1e4, b1e5;
};
extern struct Rcff4 DAT_a802cff4;
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c55;
extern void FUN_a00b0710(unsigned char, unsigned char);

void FUN_a00b2a1c(void)
{
    if (DAT_a802cff4.h12 == 5 && (DAT_a802d290.w1dc & 0x40000000) && DAT_a802cff4.b3f == 0)
        return;
    if (DAT_a802cff4.h10 == 4 && (int)DAT_a802d290.w1dc < 0 && DAT_a802cff4.b3f == 0)
        return;
    if (DAT_a802d290.b1e4 == 1)
        return;
    if (DAT_a802d290.b1e5 == 1)
        return;
    if (DAT_a802cff4.b3f != 0) {
        if (DAT_a802cff4.h18.b15)
            DAT_a8025c55 = (DAT_a8025c55 + 3) & 3;
        else
            DAT_a8025c55 = (DAT_a8025c55 + 2) & 3;
        if (DAT_a802d290.b1e2 > 2 && DAT_a8025c55 == 1)
            DAT_a8025c55--;
        FUN_a00b0710(3, DAT_a8025c55);
    } else if (DAT_a802cff4.h18.b15) {
        DAT_a8025c55 = (DAT_a8025c55 + 1) % 3;
        FUN_a00b0710(2, DAT_a8025c55);
    } else {
        DAT_a8025c55 = (DAT_a8025c55 + 1) & 1;
        FUN_a00b0710(1, DAT_a8025c55);
    }
    if ((unsigned char)(DAT_a8025c55 - 2) > 1)
        DAT_a802cff4.he = (DAT_a802cff4.he & 0x7fff) | (DAT_a8025c55 << 15);
}
