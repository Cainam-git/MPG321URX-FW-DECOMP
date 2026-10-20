/* leon2m FUN_a00b8774 @ 0xa00b8774-0xa00b87d4 (24 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 24 words.
 * Code facts: u16 0xa802b092 = 0x72c; u16 0xa802b094 = 0 (clrh, before the call); FUN_a0103808(0, 0, 0, 0)
 * (return unused); FUN_a00b7f9c(0x1b); FUN_a014512c(1, 0); u16 at 0xa802cff4+0x18 |= 0x1000. void(void).
 * Fix vs the autoc draft (66.67): BEHAVIOUR: 0xa802b094 is a u16 cleared to 0, not FUN_a0103808's return;
 * real base DAT_a802cff4 (draft used the mid-record word _DAT_a802d00c); real prototypes. Aids: none.
 */
struct Rcff4 { unsigned char pad[0x18]; unsigned short h18; };
extern struct Rcff4 DAT_a802cff4;
extern unsigned short _DAT_a802b092;
extern unsigned short _DAT_a802b094;
extern void FUN_a0103808(int, int, int, int);
extern void FUN_a00b7f9c(int);
extern void FUN_a014512c(unsigned int, unsigned int);

void FUN_a00b8774(void)
{
  _DAT_a802b092 = 0x72c;
  _DAT_a802b094 = 0;
  FUN_a0103808(0, 0, 0, 0);
  FUN_a00b7f9c(0x1b);
  FUN_a014512c(1, 0);
  DAT_a802cff4.h18 |= 0x1000;
}
