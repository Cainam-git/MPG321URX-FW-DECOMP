/* leon2m FUN_a010d068 @ 0xa010d068-0xa010d244 (476 bytes). Flags -mcpu=v8 -O3 -g.
 *
 * void FUN_a010d068(c, on): sets (on != 0) or clears (on == 0) bit 24 of word 0x3D (offset 0xF4) of the register
 * blocks of the channel tables T1 = DAT_0019aed8 and T2 = DAT_0019aecc (3 block pointers each), ch = (unsigned char)c.
 *   w = T1[ch > 2 ? 0 : ch]->w[0x3d], read in each arm; the new value is written to T1 then T2; a channel > 2
 *   writes blocks 0..2 of that table. Same SET form as FUN_a010f50c and FUN_a010d244.
 * Source form: ch is an unsigned int holding (unsigned char)c, computed once before the 'on' test, and the
 *   T1 channel parameter of the static helper set2(ch, k, v) is unsigned int (the T2 channel k stays
 *   unsigned char and is masked again from the parameter c).
 */
struct Regs { unsigned int w[0x40]; };
extern volatile struct Regs *const DAT_0019aed8[3];
extern volatile struct Regs *const DAT_0019aecc[3];

#define SET(tab, n, f, val) do { if ((n) > 2) { unsigned int i; for (i = 0; i <= 2; i++) tab[i]->f = val; } \
                                 else tab[n]->f = val; } while (0)

static void set2(unsigned int ch, unsigned char k, unsigned int v)
{
    SET(DAT_0019aed8, ch, w[0x3d], v);
    SET(DAT_0019aecc, k, w[0x3d], v);
}

void FUN_a010d068(unsigned short c, unsigned char on)
{
    unsigned int ch = (unsigned char)c;
    unsigned int w;

    if (on == 0) {
        {
            unsigned char idx = ch > 2 ? 0 : c;
            w = DAT_0019aed8[idx]->w[0x3d];
        }
        set2(ch, c, w & ~0x1000000);
    } else {
        {
            unsigned char idx = ch > 2 ? 0 : c;
            w = DAT_0019aed8[idx]->w[0x3d];
        }
        set2(ch, c, w | 0x1000000);
    }
}
