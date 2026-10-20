/* leon2m FUN_a01420e4 @ 0xa01420e4-0xa0142110 (11 words), flags -mcpu=v8 -O3 -g.
 * Code facts: leaf; i = (u8)param; returns bit 6 of the halfword at +2 of entry i of the 18-byte (0x12) record
 * array DAT_a802e116 (the 7-entry table GlobalModeHandler FUN_a0131518 walks as DAT_a802e116[]). Its only caller
 * is FUN_a0132964 (the check dc6c uses in states 9 and 12 to keep a channel running or restart it). Aids: none.
 */
struct Ent { unsigned short h0; unsigned short h2; unsigned char p04[0x12 - 4]; };
extern struct Ent DAT_a802e116[];

unsigned int FUN_a01420e4(unsigned char i)
{
    return (DAT_a802e116[i].h2 >> 6) & 1;
}
