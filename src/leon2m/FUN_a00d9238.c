/* leon2m FUN_a00d9238 @ 0xa00d9238-0xa00d934c (69 words). -mcpu=v8 -O3 -g.
 * void(void).
 * What it does: f = byte d290+0x1f (DAT_a802d290 record), v = byte d290+0x1e.
 *   1. f == 0 and the mapped port state of channel 0 (FUN_a0143c14(0)) is 10: FUN_a0124a08(), FUN_a01248ac(),
 *      FUN_a014512c(0, 0), 50 ms delay (func_0x4008d1a0(0x32)).
 *   2. f == 0 or bit 14 of word d290+0xa8 clear: FUN_a01479ec(1). Then always FUN_a0149978(0, v),
 *      FUN_a0148268(0, 1).
 *   3. f == 0: FUN_a0149978(1, v), FUN_a0148268(1, 1).
 *   4. tail call FUN_a0148358(0x1964).
 * f is re-read from memory after the calls (fw ldub after each call). Caller: the four per-port handlers
 * FUN_a00a0508/0780/09f8/0c70 on the 0x55aa magic path (they set d290+0x1e = FUN_a014459c(0) just before).
 * No timing value is read here; only state code 10 of channel 0 and the d290 flags choose the steps.
 * Code facts that fix the source: step 2 is ONE call guarded by '||' with the common pair after it (gcc's
 * bb-reorder copies the pair and the f test into both paths, as in the fw); FUN_a0148358 gets one argument
 * (only %o0 is set; its src/ definition lists a second one); FUN_a0143c14 returns u8 (fw and 0xff).
 * Struct G290 = only the fields used here (offsets). volatile: none. Aids: none.
 */
struct G290 {
  unsigned char p000[0x1e];
  unsigned char b01e;
  unsigned char b01f;
  unsigned char p020[0xa8 - 0x20];
  unsigned int w0a8;
};
extern struct G290 DAT_a802d290;
extern unsigned char FUN_a0143c14(unsigned char);
extern void FUN_a0124a08(void);
extern void FUN_a01248ac(void);
extern void FUN_a014512c(unsigned int, unsigned int);
extern void func_0x4008d1a0(int ms);
extern void FUN_a01479ec(unsigned char);
extern void FUN_a0149978(int, unsigned char);
extern void FUN_a0148268(int, int);
extern void FUN_a0148358(unsigned short);

void FUN_a00d9238(void)
{
  if (DAT_a802d290.b01f == 0 && FUN_a0143c14(0) == 10) {
    FUN_a0124a08();
    FUN_a01248ac();
    FUN_a014512c(0, 0);
    func_0x4008d1a0(0x32);
  }
  if (DAT_a802d290.b01f == 0 || !(DAT_a802d290.w0a8 & 0x4000))
    FUN_a01479ec(1);
  FUN_a0149978(0, DAT_a802d290.b01e);
  FUN_a0148268(0, 1);
  if (DAT_a802d290.b01f == 0) {
    FUN_a0149978(1, DAT_a802d290.b01e);
    FUN_a0148268(1, 1);
  }
  FUN_a0148358(0x1964);
}
