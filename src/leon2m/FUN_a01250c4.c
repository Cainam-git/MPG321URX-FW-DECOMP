/* leon2m FUN_a01250c4 @ 0xa01250c4-0xa0125124 (24 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 24 words. Leaf.
 * Code facts: scans the 8 rows of the ROM table DAT_001a42a8 (0x16-byte rows, smul 0x16) with a u8 index and
 * returns the first index whose byte +1 == 2 and whose u16 +0x14 has bit 0x400 set; 0xff when none matches.
 * Fix vs the autoc draft (66.67): real base DAT_001a42a8 as a struct array (draft used 0x1a42a9 / 0x1a42bc
 * constants); a plain u8 for loop with break and 'if (i == 8) i = 0xff'. Aids: none.
 */
struct rec { unsigned char b00, b01; unsigned char b02[0x12]; unsigned short h14; };
extern const struct rec DAT_001a42a8[];

unsigned char FUN_a01250c4(void)
{
  unsigned char i;

  for (i = 0; i < 8; i++)
    if (DAT_001a42a8[i].b01 == 2 && (DAT_001a42a8[i].h14 & 0x400))
      break;
  if (i == 8)
    i = 0xff;
  return i;
}
