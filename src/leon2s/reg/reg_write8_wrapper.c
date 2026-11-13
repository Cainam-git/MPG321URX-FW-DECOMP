/* reg_write8_wrapper  (FUN_a00615f4)
 *
 * Write one byte of a register (out-of-line wrapper of reg_write8).
 * Name basis: derived - body only forwards to reg_write8; no direct caller (reached through a pointer or
 *   unused)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00615f4 @ 0xa00615f4-0xa0061608 (5 words), flags -mcpu=v8 -Os -g.
 * Tail call with the caller's return address handed on; the last word is the nop the compiler places behind
 * such a call sequence. The value is declared unsigned char, so it is masked to its low byte on the way.
 */
extern void reg_write8(unsigned int addr, unsigned int value);

/* Call reg_write8(addr, value) with value cut to a byte. No routine calls this wrapper. */
void reg_write8_wrapper(unsigned int addr, unsigned char value)
{
    reg_write8(addr, value);
}
