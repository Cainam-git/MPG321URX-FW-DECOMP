/* leon2m FUN_a010e448 @ 0xa010e448-0xa010e624 (476 bytes). Flags -mcpu=v8 -O3 -g.
 *
 * void FUN_a010e448(c, on): sets (on != 0) or clears (on == 0) bit 24 of word 9 (offset 0x24) of the register
 * blocks of the channel tables T1 = DAT_0019aec4 and T2 = DAT_0019aebc (2 block pointers each), ch = (unsigned char)c.
 *   w = T1[ch > 1 ? 0 : ch]->w[9], read in each arm; the new value is written to T1 then T2; a channel > 1
 *   writes blocks 0 and 1 of that table. Same family as FUN_a010d068 (3-entry tables).
 * Source form: ch is an unsigned int holding (unsigned char)c, computed once before the 'on' test; the T1 channel
 *   parameter of the static helper set2(ch, k, v) is unsigned int (k stays unsigned char and is masked again from
 *   c); the SET macro is the FUN_a010d914 form: one 'unsigned int i' serves the loop and the single-entry arm
 *   ('i = n; tab[i]'); with a loop-local counter the end of the T2 loop is laid out differently.
 */
struct Regs { unsigned int w[10]; };
extern volatile struct Regs *const DAT_0019aec4[2];
extern volatile struct Regs *const DAT_0019aebc[2];

#define SET(tab, n, f, val) do { unsigned int i; if ((n) > 1) { for (i = 0; i <= 1; i++) tab[i]->f = val; } else { i = (n); tab[i]->f = val; } } while (0)

static void set2(unsigned int ch, unsigned char k, unsigned int v)
{
    SET(DAT_0019aec4, ch, w[9], v);
    SET(DAT_0019aebc, k, w[9], v);
}

void FUN_a010e448(unsigned short c, unsigned char on)
{
    unsigned int ch = (unsigned char)c;
    unsigned int w;

    if (on == 0) {
        {
            unsigned char idx = ch > 1 ? 0 : c;
            w = DAT_0019aec4[idx]->w[9];
        }
        set2(ch, c, w & ~0x1000000);
    } else {
        {
            unsigned char idx = ch > 1 ? 0 : c;
            w = DAT_0019aec4[idx]->w[9];
        }
        set2(ch, c, w | 0x1000000);
    }
}
