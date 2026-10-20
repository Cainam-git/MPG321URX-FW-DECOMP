/* leon2m FUN_a00875ec @ 0xa00875ec-0xa008767c (36 words), flags -mcpu=v8 -O3 -g.
 * Code facts: save = low byte of word DAT_a802d290 + 0xb0 (ldub +0xb3); FUN_a00df170(s_000ff5e8
 * "APPBlurFree_AfterMute\r\n") (1 arg); FUN_a01438c8(0); FUN_a0150768(1, 0xff); FUN_a014bac4(2, 0x3ff);
 * FUN_a014bc58(0); FUN_a014dbf4(0); word +0xb0 = 0. If bit 14 of the u16 at DAT_a802cff4 + 0x3e is set it is
 * cleared (andn computed before the test, sth in the branch delay slot), else FUN_a00d8cd4(). Word +0xb0 = save.
 * void(void). The word is restored to the saved byte only; there is no else-store of the u16.
 * Source form: the bases are the symbols DAT_a802d290 / DAT_a802cff4; bit 14 is a 1-bit bit-field (the mask form
 * gives btst before andn). Aids: none.
 */
struct R290 { unsigned char pad[0xb0]; unsigned int wb0; };
struct Rcff4 { unsigned char pad[0x3e]; unsigned short b15 : 1, b14 : 1, rest : 14; };
extern struct R290 DAT_a802d290;
extern struct Rcff4 DAT_a802cff4;
extern char s_000ff5e8[];
extern void FUN_a00d8cd4(void);
extern void FUN_a00df170(char *);
extern void FUN_a01438c8(int);
extern void FUN_a014bac4(int, int);
extern void FUN_a014bc58(int);
extern void FUN_a014dbf4(int);
extern void FUN_a0150768(int, int);

void FUN_a00875ec(void)
{
  unsigned char save = DAT_a802d290.wb0;

  FUN_a00df170(s_000ff5e8);
  FUN_a01438c8(0);
  FUN_a0150768(1, 0xff);
  FUN_a014bac4(2, 0x3ff);
  FUN_a014bc58(0);
  FUN_a014dbf4(0);
  DAT_a802d290.wb0 = 0;
  if (DAT_a802cff4.b14)
    DAT_a802cff4.b14 = 0;
  else
    FUN_a00d8cd4();
  DAT_a802d290.wb0 = save;
}
