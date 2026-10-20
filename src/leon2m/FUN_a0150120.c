/* leon2m FUN_a0150120 @ 0xa0150120-0xa0150230 (68 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 68 words.
 * Code facts: FreeSync mode switch: on == 1 and mode == 1: print "##BFree_Mode_GEN2_ON", FUN_a011e028(b, 1),
 * FUN_a011e220(b, 1), FUN_a011dd9c(b, u16 0xa802a49e), FUN_a011d748(b, 0xff, u16 0xa802a4a0, 0) with b = byte
 * 0xa802a49a; on == 1 otherwise: print "##BFree_Mode_GEN1_ON", FUN_a011e148(b); both then FUN_a014fe78(1);
 * on != 1: print "##BFree_Mode_OFF", FUN_a011e148(b), FUN_a014fe78(0). Common tail: FUN_a014faa8(),
 * FUN_a011e220(0x1f, 1), FUN_a011e388(0x1f, 1), tail FUN_a011e028(0x1f, 1) (bb-reorder duplicates it per arm).
 * Fix vs the autoc draft (78.08): one common tail after the if/else (the draft wrote it twice: 59.42); void;
 * FUN_a011e148 takes ONE argument; strings named. Aids: none.
 */
extern unsigned char DAT_a802a49a;
extern unsigned short _DAT_a802a49e;
extern unsigned short _DAT_a802a4a0;
extern const char s_001a7380[], s_001a7398[], s_001a73b0[];
extern int FUN_a00df170();
extern void FUN_a011d748(unsigned char, unsigned char, unsigned short, int);
extern void FUN_a011dd9c(unsigned char, unsigned short);
extern void FUN_a011e028(unsigned char, int);
extern void FUN_a011e148(unsigned char);
extern void FUN_a011e220(unsigned char, int);
extern void FUN_a011e388(unsigned char, int);
extern void FUN_a014faa8(void);
extern void FUN_a014fe78(int);

void FUN_a0150120(unsigned char on, unsigned char mode)
{
  if (on == 1) {
    if (mode == 1) {
      FUN_a00df170(s_001a7398);
      FUN_a011e028(DAT_a802a49a, 1);
      FUN_a011e220(DAT_a802a49a, 1);
      FUN_a011dd9c(DAT_a802a49a, _DAT_a802a49e);
      FUN_a011d748(DAT_a802a49a, 0xff, _DAT_a802a4a0, 0);
    } else {
      FUN_a00df170(s_001a73b0);
      FUN_a011e148(DAT_a802a49a);
    }
    FUN_a014fe78(1);
  } else {
    FUN_a00df170(s_001a7380);
    FUN_a011e148(DAT_a802a49a);
    FUN_a014fe78(0);
  }
  FUN_a014faa8();
  FUN_a011e220(0x1f, 1);
  FUN_a011e388(0x1f, 1);
  FUN_a011e028(0x1f, 1);
}
