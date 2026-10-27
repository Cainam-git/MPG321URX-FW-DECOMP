/* FUN_a0104eb0 (leon2m 0xa0104eb0-0xa0104f48, 152 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Inlined sequence of FUN_a0104e50(v), FUN_a0104e80(v) and FUN_a0104cb0(): merges bits 1..4 and then bits 5..7 of v
 * into the word register 0xcf012890 (each result byte also written to 0xcf012990), then sets or clears bit 0 of
 * both from bit 26 of *DAT_a802d6a4. Nothing in the image refers to it: no call, branch, sethi/or constant or
 * address word. It lies between FUN_a0104e80 and FUN_a0104f48. Source form: the three routines are static helpers
 * inlined here.
 */
#define REG90 (*(volatile unsigned int *)0xcf012890)
#define REG190 (*(volatile unsigned int *)0xcf012990)
extern unsigned int *DAT_a802d6a4;

static void set_lo(unsigned int v)
{
    unsigned char x = (REG90 & ~0x1eu) | (v & 0x1e);

    REG90 = x;
    REG190 = x;
}

static void set_hi(unsigned int v)
{
    unsigned char x = (REG90 & 0x1f) | (v & ~0x1fu);

    REG90 = x;
    REG190 = x;
}

static void set_b0(void)
{
    if (*DAT_a802d6a4 & 0x4000000) {
        REG90 |= 1;
        REG190 |= 1;
    } else {
        REG90 &= ~1u;
        REG190 &= ~1u;
    }
}

void FUN_a0104eb0(unsigned char v)
{
    set_lo(v);
    set_hi(v);
    set_b0();
}
