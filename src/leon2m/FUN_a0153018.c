/* leon2m FUN_a0153018 @ 0xA0153018..0xA015373C (457 words), a main-loop task (usage-time counters, per-port
 * service, FUN_a0154580 -> FUN_a002ced8 at the end), called from main FUN_a00295a4's main loop (RAM 0x400895C8, no argument,
 * result not used) after FUN_a01387a4.
 * -mcpu=v8 -O3 -g -msoft-float.
 * What it does, in order (code facts from the asm):
 * 1. Calls func_0x4008f550, FUN_a0142910, FUN_a01298d8, FUN_a013dc6c, FUN_a0131518, FUN_a01413d0.
 * 2. Every 200 ms (func_0x4008d594(u16 0xA802CF94) > 200, then 0xA802CF94 = tick now): v = -1 if
 *    FUN_a011996c(0) or FUN_a011996c(1) is non-zero, else 0; when v differs from int 0xA802A4BC it calls
 *    FUN_a013a728(v); stores v there.
 * 3. found = some port i in 0..3 has FUN_a013ce6c(i) == 0x0C (by its use: port state 12). If found:
 *    FUN_a012a774(0). Then FUN_a0140ab4(); if soft timer 0 has run out (FUN_a013b7e0(0) == 0; 9 u16
 *    down-counters at 0xA802CBBE) and FUN_a0124828() != 0 (func_0x4008cd38(13, 32) == 1): FUN_a013b754(0, 20000)
 *    re-arms timer 0, then the usage-time counters of the saved-settings record S = 0xA802E1A0 (only while
 *    FUN_a012792c() == 0 and FUN_a0127944() == 0): counter A on every 3rd such pass (byte 0xA802CF92 cycles 1..3):
 *    byte S+0x08 counts 0..59, on 60 it restarts and u16 S+0x09 + 1 (stops at 0xFFFF) and FUN_a0153970(S, 0)
 *    (writes the record); counter B on every 3rd pass (byte 0xA802CF91): byte S+0x0F (on 60: 0, u16 S+0x11 + 1,
 *    print ROM 0x1A75C0) and byte S+0x10 (on 60: 0, u16 S+0x13 + 1, print ROM 0x1A75D8), then FUN_a0153970(S, 0)
 *    when S+0x0F or S+0x10 is a multiple of 3 (FUN_a0127ab8() != 0), of 10 (setting 0x10 == 1) or of 30 (else).
 * 4. bits = FUN_a0137754(); on change stored in byte 0xA802CF96 and FUN_a013777c(bits). For the 4 entries of the
 *    ROM table 0x1A74A6 (type, id): type 4/8/0x10/0x20 -> on = bit 2/3/4/5 of bits, dev = byte +0x10 of port entry
 *    0/1/2/3 (0xA802E116, stride 0x12); dev 0xFF = skip; FUN_a0124e44(dev) == 0 -> soft timer id has run out
 *    (FUN_a013b7e0(id) == 0) and !on -> FUN_a01519d8(type); FUN_a0124e44(dev) != 0 and on -> FUN_a0151aa4(type, 1).
 *    dev is set to 0xFF ONCE before the port loop (fw 0xA01530C8, delay slot of the FUN_a0137754 call), not per
 *    entry: an entry of another type would reuse the previous dev (all 4 ROM entries are of these types).
 * 5. FUN_a0150248(u16 +0x20 of entry ((word 0xA802DF30 >> 12) & 15) of the 0x2A-byte table 0xA802E224 / 10);
 *    func_0x4008c194(1) == 0x55 -> func_0x4008fa34(); FUN_a014d5f4(); if bit 21 of word 0xA802E3D0 and ports 0 and
 *    3 are in state 0x0C: every 20th pass FUN_a0150df8() (byte 0xA802CF97 counts). Last: FUN_a0154580() (tail
 *    call, 'call; restore' at 0xA015326C and 0xA015359C; it ends with FUN_a002ced8 and returns int 0,
 *    fw 0xA015462C 'clr %g1; mov %g1, %i0').
 * Can it wait or fail? Its own code has no unbounded loop (two 4-step port loops); waits only inside callees.
 *
 * Source form (affects the last 88 words, register names only; gcc 3.4.4 global.c / regrename.c read):
 *   (1) 'extern int FUN_a0154580 (void)' (its real type): the value-returning tail call puts %i0 into
 *       regs_ever_live, so global.c find_reg pass 0 ('never allocate a register for the first time') gives the
 *       FIRST call-saved pseudo %i0 (first-loop i), and found then gets %l0, as in the fw.
 *       'int FUN_a0153018 (void) { ... return FUN_a0154580 (); }' gives the same code; the void form is kept
 *       since main ignores the result. With 'void FUN_a0154580' the registers differ.
 *   (2) The FUN_a0124e44 test is written '!FUN_a0124e44 (dev)' with the timer arm first. Why:
 *       regrename.c walks blocks in index order and gives each chain the free register renamed LEAST recently
 *       (tick[]). With the timer arm first, its chains take %o4 (sll) and %o2 (add) while 'on' (%l0) is live, so
 *       the FUN_a0151aa4 arm then finds %l0 the oldest free register for i*2 (fw 'bne,a; add %i0,%i0,%l0').
 *   (3) case 4: 'dev = ...;' before 'on = ...;' (fw 'be,a' takes the dev load, 'mov %l6,%l0' in the 'b' slot).
 */
struct Rec
{
  unsigned char p00[8];
  unsigned char b08;
  unsigned short h09;
  unsigned char p0b[4];
  unsigned char b0f;
  unsigned char b10;
  unsigned short h11;
  unsigned short h13;
  unsigned char p15[0x3b];
} __attribute__ ((packed, aligned (4)));
struct Port
{
  unsigned char b[0x12];
};
struct T2a
{
  unsigned char p[0x20];
  unsigned short h20;
  unsigned char q[8];
};
struct PT
{
  unsigned char type;
  unsigned char id;
};
extern struct Rec DAT_a802e1a0;
extern struct Port DAT_a802e116[4];
extern struct T2a DAT_a802e224[16];
extern const struct PT DAT_001a74a6[4];
extern unsigned short DAT_a802cf94;
extern unsigned char DAT_a802cf91, DAT_a802cf92, DAT_a802cf96, DAT_a802cf97;
extern int DAT_a802a4bc;
extern unsigned int DAT_a802df30, DAT_a802e3d0;
extern char s_001a75c0[], s_001a75d8[];
extern void func_0x4008f550 (void);
extern void FUN_a0142910 (void);
extern void FUN_a01298d8 (void);
extern void FUN_a013dc6c (void);
extern void FUN_a0131518 (void);
extern void FUN_a01413d0 (void);
extern unsigned short func_0x4008d594 (unsigned short);
extern unsigned short func_0x4008d588 (void);
extern unsigned char FUN_a011996c (int);
extern void FUN_a013a728 (int);
extern unsigned char FUN_a013ce6c (unsigned char);
extern void FUN_a012a774 (int);
extern void FUN_a0140ab4 (void);
extern unsigned short FUN_a013b7e0 (unsigned char);
extern unsigned char FUN_a0124828 (void);
extern void FUN_a013b754 (int, int);
extern unsigned char FUN_a012792c (void);
extern unsigned char FUN_a0127944 (void);
extern void FUN_a0153970 (struct Rec *, int);
extern int FUN_a00df170 (const char *, ...);
extern unsigned char FUN_a0127ab8 (void);
extern unsigned short FUN_a0145af8 (int);
extern unsigned char FUN_a0137754 (void);
extern void FUN_a013777c (unsigned char);
extern unsigned char FUN_a0124e44 (unsigned char);
extern void FUN_a0151aa4 (unsigned char, int);
extern void FUN_a01519d8 (unsigned char);
extern void FUN_a0150248 (unsigned short);
extern unsigned char func_0x4008c194 (int);
extern void func_0x4008fa34 (void);
extern void FUN_a014d5f4 (void);
extern void FUN_a0150df8 (void);
extern int FUN_a0154580 (void);

void FUN_a0153018 (void)
{
  unsigned char i, found, bits, on, dev;
  int v;

  func_0x4008f550 ();
  FUN_a0142910 ();
  FUN_a01298d8 ();
  FUN_a013dc6c ();
  FUN_a0131518 ();
  FUN_a01413d0 ();
  if (func_0x4008d594 (DAT_a802cf94) > 200)
    {
      DAT_a802cf94 = func_0x4008d588 ();
      v = 0;
      if (FUN_a011996c (0))
        v = -1;
      else if (FUN_a011996c (1))
        v = -1;
      if (v != DAT_a802a4bc)
        FUN_a013a728 (v);
      DAT_a802a4bc = v;
    }
  found = 0;
  for (i = 0; i < 4; i++)
    if (FUN_a013ce6c (i) == 0xc)
      {
        found = 1;
        break;
      }
  if (found)
    FUN_a012a774 (0);
  FUN_a0140ab4 ();
  if (FUN_a013b7e0 (0) == 0 && FUN_a0124828 ())
    {
      FUN_a013b754 (0, 20000);
      if (!FUN_a012792c () && !FUN_a0127944 ())
        {
          if (++DAT_a802cf92 > 3)
            {
              DAT_a802cf92 = 1;
              if (++DAT_a802e1a0.b08 > 59)
                {
                  DAT_a802e1a0.b08 = 0;
                  if (DAT_a802e1a0.h09 != 0xffff)
                    {
                      DAT_a802e1a0.h09++;
                      FUN_a0153970 (&DAT_a802e1a0, 0);
                    }
                }
            }
        }
      if (!FUN_a012792c () && !FUN_a0127944 ())
        {
          if (++DAT_a802cf91 > 3)
            {
              DAT_a802cf91 = 1;
              DAT_a802e1a0.b10++;
              if (++DAT_a802e1a0.b0f > 59)
                {
                  DAT_a802e1a0.b0f = 0;
                  if (DAT_a802e1a0.h11 != 0xffff)
                    {
                      DAT_a802e1a0.h11++;
                      FUN_a00df170 (s_001a75c0, DAT_a802e1a0.h11);
                    }
                }
              if (DAT_a802e1a0.b10 > 59)
                {
                  DAT_a802e1a0.b10 = 0;
                  if (DAT_a802e1a0.h13 != 0xffff)
                    {
                      DAT_a802e1a0.h13++;
                      FUN_a00df170 (s_001a75d8, DAT_a802e1a0.h13);
                    }
                }
              if (FUN_a0127ab8 ())
                {
                  if (DAT_a802e1a0.b0f % 3 == 0 || DAT_a802e1a0.b10 % 3 == 0)
                    FUN_a0153970 (&DAT_a802e1a0, 0);
                }
              else if (FUN_a0145af8 (0x10) == 1)
                {
                  if (DAT_a802e1a0.b0f % 10 == 0 || DAT_a802e1a0.b10 % 10 == 0)
                    FUN_a0153970 (&DAT_a802e1a0, 0);
                }
              else if (DAT_a802e1a0.b0f % 30 == 0 || DAT_a802e1a0.b10 % 30 == 0)
                FUN_a0153970 (&DAT_a802e1a0, 0);
            }
        }
    }
  dev = 0xff;
  bits = FUN_a0137754 ();
  if (DAT_a802cf96 != bits)
    {
      DAT_a802cf96 = bits;
      FUN_a013777c (bits);
    }
  for (i = 0; i < 4; i++)
    {
      on = 0;
      switch (DAT_001a74a6[i].type)
        {
        case 4:
          dev = DAT_a802e116[0].b[0x10];
          on = (bits >> 2) & 1;
          break;
        case 8:
          on = (bits >> 3) & 1;
          dev = DAT_a802e116[1].b[0x10];
          break;
        case 0x10:
          on = (bits >> 4) & 1;
          dev = DAT_a802e116[2].b[0x10];
          break;
        case 0x20:
          on = (bits >> 5) & 1;
          dev = DAT_a802e116[3].b[0x10];
          break;
        }
      if (dev != 0xff)
        {
          if (!FUN_a0124e44 (dev))
            {
              if (FUN_a013b7e0 (DAT_001a74a6[i].id) == 0 && !on)
                FUN_a01519d8 (DAT_001a74a6[i].type);
            }
          else if (on)
            FUN_a0151aa4 (DAT_001a74a6[i].type, 1);
        }
    }
  FUN_a0150248 (DAT_a802e224[(DAT_a802df30 >> 12) & 0xf].h20 / 10);
  if (func_0x4008c194 (1) == 0x55)
    func_0x4008fa34 ();
  FUN_a014d5f4 ();
  if (DAT_a802e3d0 & 0x200000)
    if (FUN_a013ce6c (0) == 0xc && FUN_a013ce6c (3) == 0xc)
      {
        if (DAT_a802cf97 % 20 == 0)
          FUN_a0150df8 ();
        DAT_a802cf97++;
      }
  FUN_a0154580 ();
}
