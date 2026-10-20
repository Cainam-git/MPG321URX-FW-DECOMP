/* leon2m FUN_a009bf48 @ 0xa009bf48-0xa009bfb4 (27 words), flags -mcpu=v8 -O3 -g.
 * Same shape as FUN_a0092444 / FUN_a0092364.
 * Code facts: FUN_a00a93bc(word 0xa802afec - 0x3f, as u8); loop: t = (lduh 0xa802afee = low half of word
 * 0xa802afec) - 0x3e; t = t % 4 (signed: sra/srl 30/add/and -4/sub); word 0xa802afec = t + 0x3f; repeat until
 * FUN_a00aad30(t) == 1 (u8 in, u8 out). Tail FUN_a00a9650(afec - 0x3f, 1). void(void).
 * Source form: the half-word read is (unsigned short)_DAT_a802afec (no separate afee symbol); u8 params/returns,
 * void; plain 't % 4'. Aids: none.
 */
extern unsigned int _DAT_a802afec;
extern void FUN_a00a93bc(unsigned char);
extern unsigned char FUN_a00aad30(unsigned char);
extern void FUN_a00a9650(unsigned char, int);

void FUN_a009bf48(void)
{
  int t;

  FUN_a00a93bc(_DAT_a802afec - 0x3f);
  do {
    t = (unsigned short)_DAT_a802afec - 0x3e;
    t = t % 4;
    _DAT_a802afec = t + 0x3f;
  } while (FUN_a00aad30(t) != 1);
  FUN_a00a9650(_DAT_a802afec - 0x3f, 1);
}
