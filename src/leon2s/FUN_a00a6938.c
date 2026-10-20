/* leon2s FUN_a00a6938 @ 0xa00a6938-0xa00a69b4 (31 words), flags -mcpu=v8 -Os -g.
 * Read twin of FUN_a00a6f08.
 * Code facts: stable-read loop: v = FUN_a00a68d0(port, reg); up to 6 times, re-read and stop when
 * the 16-bit values match; else v = a fresh read and n++ (n <= 4). Returns (u16)v.
 * Required forms: the a6f08 loop form; the callee is declared with an unsigned int
 * return: the fw caller re-extends every result (sll/srl 16 on both sides of the compare, srl at the
 * return), which a u16-returning prototype removes. The callee's value fits in 16 bits (its retl
 * path extends), so the wider type changes no value. Aids: none.
 */
extern unsigned int FUN_a00a68d0(unsigned char, unsigned short);

unsigned short FUN_a00a6938(unsigned char port, unsigned short reg)
{
  unsigned int v;
  unsigned char n;

  v = FUN_a00a68d0(port, reg);
  for (n = 0; (unsigned short)v != (unsigned short)FUN_a00a68d0(port, reg) && n <= 4; n++)
    v = FUN_a00a68d0(port, reg);
  return v;
}
