/* leon2m FUN_a0140a0c @ 0xa0140a0c-0xa0140ab4 (42 words).
 * When the byte DAT_a802cbd9 is non-zero: looks for the storage device i (only i = 0 is tested) whose area
 * b = DAT_001a69fe[i].b0 contains the halfword DAT_a802a47a, i.e. DAT_a802cbdc[b].h0 <= v < DAT_a802cbdc[b].h0 +
 * DAT_001a6a24[b].h0; calls FUN_a01405d0 with that i, or with 0xff when none matches, and clears DAT_a802cbd9.
 * The record layouts are those of FUN_a0140360 (38-byte device records, 36-byte area records, 12-byte RAM area
 * rows). Called by FUN_a01451fc.
 * Source form: the search is an inlined static helper with an early return of the index and 0xff after the loop;
 * the area number is held in a local.
 */
struct B38 { unsigned char b0, b1; unsigned short h2; unsigned char b4; char name[33]; };
struct A36 { unsigned short h0; unsigned char b2, b3; char name[32]; };
struct D12 { unsigned short h0; unsigned short h2; int w4; unsigned char b8, b9; unsigned char pad[2]; };
extern const struct B38 DAT_001a69fe[];
extern const struct A36 DAT_001a6a24[];
extern struct D12 DAT_a802cbdc[];
extern unsigned char DAT_a802cbd9;
extern unsigned short DAT_a802a47a;
extern void FUN_a01405d0(unsigned char);

static unsigned char find(void)
{
    unsigned char i, b;

    for (i = 0; i < 1; i++) {
        b = DAT_001a69fe[i].b0;
        if (DAT_a802cbdc[b].h0 <= DAT_a802a47a && DAT_a802a47a < DAT_a802cbdc[b].h0 + DAT_001a6a24[b].h0)
            return i;
    }
    return 0xff;
}

void FUN_a0140a0c(void)
{
    if (DAT_a802cbd9 != 0) {
        FUN_a01405d0(find());
        DAT_a802cbd9 = 0;
    }
}
