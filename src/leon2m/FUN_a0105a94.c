/* leon2m FUN_a0105a94 @ 0xa0105a94-0xa0105af0 (23 words), flags -mcpu=v8 -O3 -g:
 * BYTE-EXACT: jf 100.00 match=True, rawcmp 0/23.
 * What it does: returns the clock counter FUN_a0102fd0(id) (u16) for clock id = a ? (bit 0 of hw reg 0xcf011a00 ?
 *   4 : 0) : (b ? 2 : 3). Only caller: the Vx1 panel-link set-up FUN_a01227f0, as FUN_a0105a94(1, 0): clock 4 or 0
 *   by the register bit, used for "Vx1 Lane BW = %ld": it returns the measured clock
 *   that sets the Vx1 lane bandwidth. It does not compare the clock with anything.
 * Code facts (fw, 0xa0105ad0..): one call (the 4 source calls are cross-jumped after reload), then
 *   'sll %o0,16,%o0; srl %o0,16,%o2' (first 16-bit pair) and 'sll %o2,16,%i0; srl %i0,16,%i0' (the u16 return).
 * Mechanism of the last 3 words (from the .greg / .rnreg dumps):
 *   - rnreg gives the fw registers only when r (the first srl result) is in %i0 after global alloc. rnreg then
 *     keeps the return chain in %i0 (tick > 0), renames r to %o2 (lowest tick; %o0 is unavailable because the
 *     shift temp is live at r's def), and the shift temp keeps %o0.
 *   - With 'r = clk(...)' per arm, the shift temp is a LOCAL pseudo in %o0. set_preference then gives r the
 *     preferences {o0, i0}, and find_reg (global.c) takes the lowest-numbered one, %o0.
 *   - Here the first pair is written as '(unsigned int)FUN_a0102fd0(id) << 16' in each inner arm and 'r = t >> 16'
 *     once per outer arm. t crosses a block boundary, so it is a GLOBAL pseudo: no preference reaches r.
 *     r's def has a SUBREG destination (r is HImode), so expand_preferences skips it. r keeps only the %i0
 *     preference of the return temp and gets %i0.
 *   - The per-outer-arm 'r = t >> 16' keeps r's def and the return extension in different blocks at combine
 *     time, so the return zero-extension stays (one 'r = t >> 16' after the if/else folds it: 86.96).
 *   - Signed 'int t' and '* 0x10000 / 0x10000' give the same code. Unsigned 'r', or 'return t >> 16' in the arms,
 *     give 86.96.
 * Aid: the identity '(u16 value << 16) >> 16' (t holds the u16 clock in its high half). It is
 *   code with the same value, not a no-op statement: FUN_a0102fd0 returns an unsigned short, so (x << 16) >> 16
 *   == x for every return value. The final code has no extra instruction; the fw's own sll/srl pair is this
 *   shift pair. No volatile except the hw register 0xcf011a00.
 */
extern unsigned short FUN_a0102fd0(unsigned char mode);

unsigned short FUN_a0105a94(unsigned char a, unsigned char b)
{
    unsigned int t;
    unsigned short r;

    if (a) {
        if (*(volatile unsigned int *)0xcf011a00 & 1)
            t = (unsigned int)FUN_a0102fd0(4) << 16;
        else
            t = (unsigned int)FUN_a0102fd0(0) << 16;
        r = t >> 16;
    } else {
        if (b)
            t = (unsigned int)FUN_a0102fd0(2) << 16;
        else
            t = (unsigned int)FUN_a0102fd0(3) << 16;
        r = t >> 16;
    }
    return r;
}
