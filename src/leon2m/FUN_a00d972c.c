/* leon2m FUN_a00d972c @ 0xa00d972c-0xa00d9764 (14 words), flags -mcpu=v8 -O3 -g.
 * Code facts: v = byte 0xa802d290+0x14; if v > 100: v = 100; store v back; FUN_a014a11c(2, v & 0xff);
 * tail call FUN_a00d94fc().
 * Fix vs the autoc draft (78.57): the record as struct pointer (fw sethi|or of 0xa802d290 + field 0x14; the draft
 * named mid-record DAT_a802d2a4) and v is an 'unsigned short' local: the fw compares the ldub value directly and
 * re-extends only for the u8 argument ('and 0xff' in the call delay slot). Tried 15 v/param type pairs:
 * u32 85.71, int 78.57, short 92.86, u8 66.67, u16 + u8 param = 100. Aids: none.
 */
struct R290 { unsigned char pad[0x14]; unsigned char b14; };
extern struct R290 DAT_a802d290;
extern void FUN_a014a11c(int, unsigned char);
extern void FUN_a00d94fc(void);

void FUN_a00d972c(void)
{
    struct R290 *p = &DAT_a802d290;
    unsigned short v = p->b14;

    if (v > 100)
        v = 100;
    p->b14 = v;
    FUN_a014a11c(2, v);
    FUN_a00d94fc();
}
