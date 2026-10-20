/* leon2m FUN_a013cf84 @ 0xa013cf84-0xa013cfc4 (16 words), flags -mcpu=v8 -O3 -g. Caller: FUN_a0143d98.
 * Leaf. Sets bit 25 (0x2000000) of the word at +0x70 of each of the four 0x78-byte records at 0xa802df30
 * (words 0xa802dfa0, 0xa802e018, 0xa802e090, 0xa802e108).
 */
struct Rec { unsigned char pad[0x70]; unsigned int w70; unsigned int pad74; };
extern struct Rec DAT_a802df30[];

void FUN_a013cf84(void)
{
    DAT_a802df30[0].w70 |= 0x2000000;
    DAT_a802df30[1].w70 |= 0x2000000;
    DAT_a802df30[2].w70 |= 0x2000000;
    DAT_a802df30[3].w70 |= 0x2000000;
}
