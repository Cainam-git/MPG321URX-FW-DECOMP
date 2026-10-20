/* leon2m FUN_a00d80d8 @ 0xa00d80d8-0xa00d8100 (10 words).
 * Takes an index byte and two halfword pointers. Selects the 16-byte record (eight halfwords) with that index in
 * the table at 0x1984c8 and stores its halfword 0 through the first pointer and its halfword 4 through the second.
 * No callers found by address (reached through a pointer or jump table).
 */
struct Rec16 {
    unsigned short h[8];
};
extern const struct Rec16 DAT_001984c8[];

void FUN_a00d80d8(unsigned char idx, unsigned short *a, unsigned short *b)
{
    *a = DAT_001984c8[idx].h[0];
    *b = DAT_001984c8[idx].h[4];
}
