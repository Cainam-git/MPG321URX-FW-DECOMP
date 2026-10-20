/* leon2m FUN_a0141edc @ 0xa0141edc-0xa0141f98 (47 words).
 * For port <= 3 and a record e whose bits 12-15 (4-bit field) equal 5: bit 10 = FUN_a0110f4c(port) & 1, bit 9 =
 * FUN_a0110f4c(port) & 1, and when bit 9 is then set, bit 8 = FUN_a0110f54(port) & 1. Same form as the per-record
 * code in FUN_a002f550: the outer test reads the field through an (unsigned char) cast (sll/srl extraction), the
 * inner one is the plain field test (folded to (h & 0xf000) == 0x5000); the inner else arm, which clears bits 9-10,
 * is unreachable but present in the code. No direct callers were found.
 */
struct EntryBits {
    unsigned short type:4;
    unsigned short b11:1;
    unsigned short f10:1;
    unsigned short f9:1;
    unsigned short f8:1;
    unsigned short lo:8;
};
struct Entry {
    struct EntryBits b;
    unsigned short h[8];
};
extern int FUN_a0110f4c(unsigned char port);
extern int FUN_a0110f54(unsigned char port);

void FUN_a0141edc(struct Entry *e, unsigned char port)
{
    if (port <= 3 && (unsigned char)e->b.type == 5) {
        if (e->b.type == 5) {
            e->b.f10 = FUN_a0110f4c(port);
            e->b.f9 = FUN_a0110f4c(port);
            if (e->b.f9)
                e->b.f8 = FUN_a0110f54(port);
        } else {
            e->b.f10 = 0;
            e->b.f9 = 0;
        }
    }
}
