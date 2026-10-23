/* leon2m FUN_a0141f98 @ 0xa0141f98-0xa01420e4 (83 words).
 * Port entry e (layout of the entries in FUN_a002f550: type = bits 12..15 of halfword +0, f5 = bit 15 of +2) and
 * index k (0 or 1; larger k returns at once). When type != 5, bit k of DAT_a802cc0b is cleared. When type == 5,
 * bit 19 of DAT_a802e3d0 is set and f5 is set: on the first pass (bit k of DAT_a802cc0b clear) the bit is set and
 * DAT_a802cc0c[k] = func_0x4008d588(); then, when func_0x4008d594(DAT_a802cc0c[k]) <= 999, it prints s_001a6ac0
 * "Mute when Hdcp22Auth\r\n" and sets type = 2. Finally, when type != 5, bit k of DAT_a802cc0a is cleared.
 * No direct callers (reached through a pointer).
 * Source form: the type tests use the bit-field directly (folds to the 0xf000 mask) and through an unsigned char
 * cast (keeps the sll/srl extraction), as the OUTER/IS5 forms of FUN_a002f550.
 */
struct EntryBits {
    unsigned short type:4;
    unsigned short b11:1;
    unsigned short f10:1;
    unsigned short f9:1;
    unsigned short f8:1;
    unsigned short lo:8;
    unsigned short f5:1;
    unsigned short h2_rest:15;
};
struct Entry {
    struct EntryBits b;
    unsigned short h[7];
};
extern unsigned char DAT_a802cc0a, DAT_a802cc0b;
extern unsigned short DAT_a802cc0c[];
extern unsigned int DAT_a802e3d0;
extern char s_001a6ac0[];
extern int FUN_a00df170(const char *, ...);
extern unsigned short func_0x4008d588(void);
extern unsigned short func_0x4008d594(unsigned short);

void FUN_a0141f98(struct Entry *e, unsigned char k)
{
    if (k > 1)
        return;
    if (e->b.type != 5)
        DAT_a802cc0b &= ~(1 << k);
    if ((unsigned char)e->b.type == 5 && (DAT_a802e3d0 & 0x80000) && e->b.f5) {
        if (!((DAT_a802cc0b >> k) & 1)) {
            DAT_a802cc0b |= 1 << k;
            DAT_a802cc0c[k] = func_0x4008d588();
        }
        if (func_0x4008d594(DAT_a802cc0c[k]) <= 999) {
            FUN_a00df170(s_001a6ac0);
            e->b.type = 2;
        }
    }
    if (e->b.type != 5)
        DAT_a802cc0a &= ~(1 << k);
}
