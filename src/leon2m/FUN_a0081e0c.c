/* leon2m FUN_a0081e0c @ 0xa0081e0c-0xa0081ea8 (39 words, includes the merged ret/restore tail FUN_a0081ea0),
 * flags -mcpu=v8 -O3 -g. BYTE-EXACT: jf 100.00 match=True, rawcmp.py 0 mismatches / 39 words.
 * Code facts: if (word 0xa802d290 & 0x5000) == 0x1000 and the u16 at 0xa802d290+0x1f6 != 0x55aa:
 * FUN_a00df170(s_000fedc8, 1); FUN_a008ef48(); FUN_a008ee6c(0xff, 1); FUN_a008ee6c(0x40, 0);
 * byte 0xa802af41 |= 1; FUN_a0143d98(); tail FUN_a00869b0(3, 3000). Otherwise plain return. void(void).
 * The same block is inlined in src/leon2m/FUN_a0081ea8.c (lines 215-222).
 * Fix vs the autoc draft (65.85): real base DAT_a802d290 as a struct (draft: a volatile char and mid-record
 * _DAT_a802d486); format string symbol s_000fedc8; void with no params. Aids: none.
 */
struct R290 { unsigned int w000; unsigned char pad[0x1f2]; unsigned short h1f6; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a802af41;
extern const char s_000fedc8[];
extern int FUN_a00df170(const char *fmt, ...);
extern void FUN_a008ef48(void);
extern void FUN_a008ee6c(int, int);
extern void FUN_a0143d98(void);
extern void FUN_a00869b0(int, int);

void FUN_a0081e0c(void)
{
  if ((DAT_a802d290.w000 & 0x5000) == 0x1000 && DAT_a802d290.h1f6 != 0x55aa) {
    FUN_a00df170(s_000fedc8, 1);
    FUN_a008ef48();
    FUN_a008ee6c(0xff, 1);
    FUN_a008ee6c(0x40, 0);
    DAT_a802af41 |= 1;
    FUN_a0143d98();
    FUN_a00869b0(3, 3000);
  }
}
