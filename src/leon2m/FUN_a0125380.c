/* leon2m FUN_a0125380 @ 0xa0125380..0xa01253bc (60 bytes, 15 words)
 * Flags: -mcpu=v8 -O3 -g (also exact with -msoft-float; -O2 gives other code).
 * What it does (code facts): maps id -> row through the byte table DAT_a802d880[id]; row 0xff
 * means "none" and returns 0xffff, otherwise returns the halfword at offset +6 of the 22-byte
 * (0x16 stride) ROM record DAT_001a42a8[row] (same table that FUN_a01250a8 / FUN_a01252c4 /
 * FUN_a01252e0 read at other offsets). Return type unsigned short (fw sll/srl 16 on return).
 * Callers: FUN_a012c188, FUN_a012c320, FUN_a012c80c, FUN_a012cd68.
 * Aids: none. The record is a plain struct (6 bytes, u16 at +6, 14 bytes = 22); a byte-pointer
 * cast form '*(u16 *)(tab + n * 0x16 + 6)' gives 20.00 (no hoisted address).
 */
struct rec { unsigned char b00[6]; unsigned short h06; unsigned char b08[14]; };
extern unsigned char DAT_a802d880[];
extern struct rec DAT_001a42a8[];

unsigned short FUN_a0125380(unsigned char id)
{
  unsigned char n = DAT_a802d880[id];
  unsigned short r = 0xffff;
  if (n != 0xff)
    r = DAT_001a42a8[n].h06;
  return r;
}
