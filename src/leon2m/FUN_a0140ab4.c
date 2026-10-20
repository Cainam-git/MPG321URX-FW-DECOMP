/* leon2m FUN_a0140ab4 @ 0xa0140ab4-0xa0140b78 (49 words), flags -mcpu=v8 -O3 -g.
 * Code facts: if the pending byte DAT_a802cbd9 is set and func_0x4008d594(DAT_a802cc04) (ROM ms-elapsed,
 * u16 result re-extended sll/srl) is above 1000: one pass (u8 i < 1; fw 'cmp i,0; be') over the ROM 38-byte
 * records DAT_001a69fe[i].b0 -> b; v = u16 DAT_a802cbdc[b].h0 (12-byte RAM records); match when
 * v <= DAT_a802a47a < v + DAT_001a6a24[b].h0 (36-byte ROM records, the same tables FUN_a01405d0 reads).
 * FUN_a01405d0(r) with r = i on a match, else 0xff; then DAT_a802cbd9 = 0. void (fw never sets %i0).
 * Form: r is an int set on two labelled paths (the fw 'and %o0,0xff' in the call slot is the u8 argument
 * conversion of a non-u8 value; with a u8 i it folds to a nop). Draft fixes: void, real record types, the
 * single call. Aids: none.
 */
struct R38 { unsigned char b0; unsigned char rest[37]; };
struct R36 { unsigned short h0; unsigned char rest[34]; };
struct R12 { unsigned short h0; unsigned char rest[10]; };
extern const struct R38 DAT_001a69fe[];
extern const struct R36 DAT_001a6a24[];
extern struct R12 DAT_a802cbdc[];
extern unsigned char DAT_a802cbd9;
extern unsigned short DAT_a802cc04;
extern unsigned short DAT_a802a47a;
extern unsigned short func_0x4008d594(unsigned short);
extern void FUN_a01405d0(unsigned char);

void FUN_a0140ab4(void)
{
    unsigned char i;
    int r;

    if (DAT_a802cbd9 == 0)
        return;
    if (func_0x4008d594(DAT_a802cc04) <= 1000)
        return;
    for (i = 0; i < 1; i++) {
        unsigned char b = DAT_001a69fe[i].b0;
        unsigned short v = DAT_a802cbdc[b].h0;
        if (v <= DAT_a802a47a && DAT_a802a47a < v + DAT_001a6a24[b].h0)
            goto found;
    }
    r = 0xff;
    goto out;
found:
    r = i;
out:
    FUN_a01405d0(r);
    DAT_a802cbd9 = 0;
}
