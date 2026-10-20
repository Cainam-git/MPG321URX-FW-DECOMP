/* leon2m FUN_a014468c @ 0xa014468c-0xa01446e0 (21 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 21 words.
 * Code facts: leaf lookup in a ROM table of 5 three-byte entries at 0x1a6da3 {a, val, key}: for i = 0..4 (u8)
 * if entry[i].key (+2) == k return entry[i].val (+1); not found -> 0xff.
 * Fix vs the autoc draft (75 band, 77.27): the table is ONE symbol DAT_001a6da3 as an array of 3-byte structs
 * (fw sethi|or 0x1a6da3 once, then i*3 + base, [+2] / [+1]); the draft used two raw addresses. Aids: none.
 */
struct E3 { unsigned char a, val, key; };
extern const struct E3 DAT_001a6da3[];

unsigned char FUN_a014468c(unsigned char k)
{
    unsigned char i;

    for (i = 0; i <= 4; i++)
        if (DAT_001a6da3[i].key == k)
            return DAT_001a6da3[i].val;
    return 0xff;
}
