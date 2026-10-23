/* leon2m FUN_a0140500 @ 0xa0140500-0xa01405d0 (52 words).
 * For a storage device dev whose ROM record byte DAT_001a69fe[dev].b0 = b has bit 7 set: FUN_a0124ed0(), then
 * FUN_a0134464(base & ~0xfff) (passed as unsigned short), then FUN_a0124eb4() as a tail call. base is computed
 * by area_base(b), i.e. with b itself as the record index: c = DAT_001a69fe[b].b0; when the area record
 * DAT_001a6a24[c].b3 is 0, base = DAT_a802cbdc[c].b8 * (DAT_001a69fe[b].b4 << 8) + DAT_a802cbdc[c].h0, else
 * base = (DAT_001a69fe[b].b1 << 11) + DAT_a802cbdc[c].h0. Record layouts as in FUN_a0140360.
 * Called by FUN_a012d554 and FUN_a014ad90.
 * Source form: area_base is an inlined static helper that masks each return value with ~0xfff (the firmware
 * masks in both arms and narrows to 16 bits at the join).
 */
struct B38 { unsigned char b0, b1; unsigned short h2; unsigned char b4; char name[33]; };
struct A36 { unsigned short h0; unsigned char b2, b3; char name[32]; };
struct D12 { unsigned short h0; unsigned short h2; int w4; unsigned char b8, b9; unsigned char pad[2]; };
extern const struct B38 DAT_001a69fe[];
extern const struct A36 DAT_001a6a24[];
extern struct D12 DAT_a802cbdc[];
extern void FUN_a0124ed0(void);
extern void FUN_a0124eb4(void);
extern void FUN_a0134464(unsigned short);

static unsigned int area_base(unsigned char dev)
{
    unsigned char b = DAT_001a69fe[dev].b0;

    if (DAT_001a6a24[b].b3 == 0)
        return (DAT_a802cbdc[b].b8 * (DAT_001a69fe[dev].b4 << 8) + DAT_a802cbdc[b].h0) & ~0xfff;
    return ((DAT_001a69fe[dev].b1 << 11) + DAT_a802cbdc[b].h0) & ~0xfff;
}

void FUN_a0140500(unsigned char dev)
{
    unsigned char b = DAT_001a69fe[dev].b0;

    if ((signed char)DAT_001a69fe[dev].b0 < 0) {
        FUN_a0124ed0();
        FUN_a0134464(area_base(b));
        FUN_a0124eb4();
    }
}
