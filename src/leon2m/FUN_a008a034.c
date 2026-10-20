/* leon2m FUN_a008a034 @ 0xa008a034-0xa008a09c (26 words). -mcpu=v8 -O3 -g.
 * What it does (leaf, APP event pump FUN_a008a210 callee): v = 4; when bits 6..7 of the event code p are
 * 0b10 (p & 0xc0 == 0x80): i = byte table DAT_00100068[p & 0x3f]; if i != 4, v = byte table DAT_00100060[i].
 * Then, when v <= 3, FUN_a0088714() (a leaf that only sets the byte DAT_a8024028 = 2; it takes no argument:
 * its asm never reads %o0) as a tail call.
 * Not rate-dependent (event-code decode).
 * Facts used: p is an int (no 'and 0xff' on %o0 in the fw); FUN_a0088714 is void(void).
 * Lever: the switch keeps an explicit 'case 0x40: v = 4;' (the fw tests 0x40 first and branches straight to
 * the v test: that case has its own label in the source; without it gcc drops the 0x40 compare). Its body
 * is the default value, so behaviour is the same as 'if ((p & 0xc0) == 0x80)'. volatile: none. Aids: none.
 */
extern const unsigned char DAT_00100060[], DAT_00100068[];
extern void FUN_a0088714(void);
void FUN_a008a034(int p)
{
unsigned char v = 4; switch (p & 0xc0) { case 0x40: v = 4; break; case 0x80: { unsigned char i = DAT_00100068[p & 0x3f]; if (i != 4) v = DAT_00100060[i]; } break; } if (v <= 3) FUN_a0088714();
}
