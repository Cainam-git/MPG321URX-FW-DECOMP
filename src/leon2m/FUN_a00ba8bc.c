/* leon2m FUN_a00ba8bc @ 0xa00ba8bc-0xa00ba950 (37 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0 mismatches, prompt flags (no extra flag).
 * Code facts: clears bytes DAT_a802d0d0[0..0x31] (u8 loop counter, clrb [base + i]),
 * DAT_a802b09c = 0, clears DAT_a802d078[0..0x18], then FUN_a0148794(1, 0x10, 4, 0x1c200) and
 * FUN_a0148794(1, 4, 2, 0x1c200). void. The last call is NOT a sibcall (call; mov 2,%o2; nop; ret;
 * restore) and the frame is the minimum (save -104): no stack slot.
 * Fixes vs the autoc draft: void (the draft returned 0, restore %g0,0,%o0); the first table
 * is the symbol DAT_a802d0d0 (the draft's constant pointer swapped the clrb address operands).
 * Cause of the missing sibcall: sibcall.c:644/674 refuses sibcalls in a function that used
 * ADDRESSOF. The two calls go through an inlined static helper call_148794() that takes the port as a
 * pointer to a local (port = 1); the address is purged back to a constant, so no code and no slot
 * remain (the plain form gives a sibcall, 75.68; passing the baud through the helper or a local
 * makes gcc keep the full 0x1c200 in %l0 instead of the fw's shared HIGH + 'or' per call, 89.47).
 * Aid: the inlined helper with a pointer argument (code-free; it only removes the sibcall).
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
