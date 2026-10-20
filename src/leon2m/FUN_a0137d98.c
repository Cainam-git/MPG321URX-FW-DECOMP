/* leon2m FUN_a0137d98 @ 0xa0137d98-0xa0137de0 (18 words), flags -mcpu=v8 -O3 -g.
 * Same callee as FUN_a0137c4c.
 * Code facts: builds a 5-byte stack packet buf = {id, p[0], p[1], p[2], p[3]} (u8 param id stored with stb,
 * no extension; p is a byte pointer) and sends it with FUN_a01370dc(0x40, 5, buf, 0). Returns nothing (the fw
 * never sets %i0). The 'nop' after the call is gcc's own.
 * Source form: the stores in ascending buffer order (sched emits the p[3] load/store first); no other source
 * order of the five stores gives the firmware's code. Aids: none.
 */
extern void FUN_a01370dc(int, int, unsigned char *, int);

void FUN_a0137d98(unsigned char id, unsigned char *p)
{
  unsigned char buf[5];

  buf[0] = id;
  buf[1] = p[0];
  buf[2] = p[1];
  buf[3] = p[2];
  buf[4] = p[3];
  FUN_a01370dc(0x40, 5, buf, 0);
}
