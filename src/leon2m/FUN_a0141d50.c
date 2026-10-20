/* leon2m FUN_a0141d50 @ 0xa0141d50-0xa0141e0c (47 words).
 * Writes v into bits 12-15 (4-bit field) of the first halfword of one of the four 18-byte records at 0xa802e116,
 * selected by t: 0x51 -> record 0, 0x61 -> 1, 0x71 -> 2, 0x81 -> 3; other t do nothing. Source form: the case
 * labels in the order 0x71, 0x51, 0x61, 0x81 (the order sets the compare chain and registers).
 * Called from FUN_a01302e0 and FUN_a0130438.
 */
struct EntryBits {
    unsigned short type:4;
    unsigned short rest:12;
};
struct Entry {
    struct EntryBits b;
    unsigned short h[8];
};
extern struct Entry DAT_a802e116[4];

void FUN_a0141d50(unsigned char t, unsigned char v)
{
    switch (t) {
    case 0x71: DAT_a802e116[2].b.type = v; break;
    case 0x51: DAT_a802e116[0].b.type = v; break;
    case 0x61: DAT_a802e116[1].b.type = v; break;
    case 0x81: DAT_a802e116[3].b.type = v; break;
    }
}
