/* leon2s FUN_a00a8844 @ 0xa00a8844-0xa00a88b8 (29 words), flags -mcpu=v8 -Os -g.
 * Three stack buffers: a[4] at %fp-16 = {0, 0x10, 0, 0} (word clear + stb 0x10 at -15), b[4] at %fp-24 =
 * {0x40, 0, 0, 0}, c[8] at %fp-32 filled by FUN_a00b15d8(c, &DAT_a00b4dc8, 4) (4-byte copy). Then
 * FUN_a00a8708(port, 0, a), (port, 1, c), (port, 2, b) with port = param_1 & 0xff. void.
 * Source form: both small buffers are 4-byte arrays zero-initialised with '= { 0 }' and then one byte store
 * each (a '{0, 0x10}' initialiser becomes a memcpy from .rodata); FUN_a00b15d8 copies bytes and is declared
 * returning void * (a void declaration moves 'mov %l0,%o0' out of the call delay slot).
 */
extern unsigned char DAT_a00b4dc8[];
extern void FUN_a00a8708(unsigned char, unsigned char, unsigned char *);
extern void *FUN_a00b15d8(void *, const void *, unsigned int); /* memcpy: its asm copies via %o5 and returns %o0 = dest */

void FUN_a00a8844(unsigned char param_1)
{
  unsigned char a[4] = { 0 };
  unsigned char b[4] = { 0 };
  unsigned char c[8];

  a[1] = 0x10;
  b[0] = 0x40;

  FUN_a00b15d8(c, DAT_a00b4dc8, 4);
  FUN_a00a8708(param_1, 0, a);
  FUN_a00a8708(param_1, 1, c);
  FUN_a00a8708(param_1, 2, b);
}
