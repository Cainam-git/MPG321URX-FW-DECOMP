/* leon2m FUN_a0143fc4 @ 0xa0143fc4  Flags: -mcpu=v8 -O3 -g.
 * Stores its argument in DAT_a802a47d and clears the 1-bit flag f7 = bit 7 of byte 0xA802D991 (a bit-field: a
 * plain &= 0x7f schedules differently). Called by the APP event generator
 * FUN_a0080c10 (row 1e) when FUN_a0143fb8() reports set (argument 0 there).
 */
extern unsigned char DAT_a802a47d;
struct Pd { unsigned char b0; unsigned char f7 : 1; unsigned char rest : 7; };
extern struct Pd DAT_a802d990;

void FUN_a0143fc4(unsigned char v)
{
    DAT_a802a47d = v;
    DAT_a802d990.f7 = 0;
}
