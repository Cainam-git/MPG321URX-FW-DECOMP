/* leon2s FUN_a00a2320 @ 0xa00a2320 (-mcpu=v8 -Os -g)
 * Table 0xA807DB00 holds records of 0x34 bytes; q = word +4 of record p1. Calls FUN_a00a73ac(0x15, q + 0x24) when
 * p2 == 1, otherwise FUN_a00a73d4(0x15, q + 0x24). Same code as FUN_a009c794 with other constants.
 * See FUN_a009c794 for the explanation; this copy's constants differ, so its comments were removed.
 */
struct Port34 { unsigned int pad0; unsigned char *ctl; unsigned char pad8[0x2c]; };
extern struct Port34 ARR_a807db00[];
extern void FUN_a00a73ac(int, unsigned char *);
extern void FUN_a00a73d4(int, unsigned char *);

void FUN_a00a2320(unsigned char port, unsigned char on)
{
  if (on == 1) {
    FUN_a00a73ac(0x15, ARR_a807db00[port].ctl + 0x24);
    return;
  }
  FUN_a00a73d4(0x15, ARR_a807db00[port].ctl + 0x24);
}
