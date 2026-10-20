/* leon2m FUN_a00d4888 @ 0xa00d4888-0xa00d48cc (17 words), flags -mcpu=v8 -O3 -g.
 * Leaf frame, sibcall (mov %o7 form).
 * Code facts: if bit 20 of word 0xa802d290+0xac is set and byte rec+0x1f == 0: tail FUN_a014782c(4). void(void).
 * Fix vs the autoc draft (70.59): real base DAT_a802d290 as a struct (draft: _DAT_a802d33c / DAT_a802d2af
 * mid-record names, the +0x1f byte declared as a word), one record pointer for both reads. Aids: none.
 */
struct R290 { unsigned char pad[0x1f]; unsigned char b1f; unsigned char pad2[0xac - 0x20]; unsigned int wac; };
extern struct R290 DAT_a802d290;
extern void FUN_a014782c(int);

void FUN_a00d4888(void)
{
  struct R290 *p = &DAT_a802d290;

  if ((p->wac & 0x100000) != 0 && p->b1f == 0)
    FUN_a014782c(4);
}
