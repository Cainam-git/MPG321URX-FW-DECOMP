/* leon2m FUN_a00ba8bc @ 0xa00ba8bc-0xa00ba950 (37 words), flags -mcpu=v8 -O3 -g.
 * Code facts: clears bytes DAT_a802d0d0[0..0x31] (u8 loop counter, clrb [base + i]), DAT_a802b09c = 0, clears
 * DAT_a802d078[0..0x18], then FUN_a0148794(1, 0x10, 4, 0x1c200) and FUN_a0148794(1, 4, 2, 0x1c200). void (plain
 * restore, no return value). The last call is NOT a sibcall (call; mov 2,%o2; nop; ret; restore) and the frame is
 * the minimum (save -104): no stack slot.
 * Source form: the first table is the symbol DAT_a802d0d0 (a constant pointer swaps the clrb address operands).
 * sibcall.c:644/674 refuses sibcalls in a function that used ADDRESSOF. The two calls go through an inlined static
 * helper call_148794() that takes the first argument as a pointer to a local (value 1); the address is purged back
 * to a constant, so no code and no slot remain (the plain form gives a sibcall; passing the 0x1c200 argument
 * through the helper or a local makes gcc keep the full 0x1c200 in %l0 instead of the fw's shared HIGH + 'or' per
 * call).
 * Compiler aid: the inlined helper with a pointer argument (code-free; it only removes the sibcall).
 */
extern unsigned char DAT_a802d0d0[];
extern unsigned char DAT_a802d078[];
extern unsigned char DAT_a802b09c;
extern void FUN_a0148794(unsigned char, unsigned char, unsigned char, unsigned int);

static void call_148794(const unsigned char *port, unsigned char b, unsigned char c)
{
  FUN_a0148794(*port, b, c, 0x1c200);
}

void FUN_a00ba8bc(void)
{
  unsigned char i, port = 1;

  for (i = 0; i <= 0x31; i++)
    DAT_a802d0d0[i] = 0;
  DAT_a802b09c = 0;
  for (i = 0; i <= 0x18; i++)
    DAT_a802d078[i] = 0;
  call_148794(&port, 0x10, 4);
  call_148794(&port, 4, 2);
}
