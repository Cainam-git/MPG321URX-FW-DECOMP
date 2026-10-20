/* leon2s FUN_a00dcc50 @ 0xa00dcc50 (-mcpu=v8 -Os -g)
 * **Uncertainty:** None major — the structure is clear from the two load-store pairs. The only question is whether the compiler will merge the two stores; the volatile qualifier should prevent that.
 */
typedef unsigned int uint;

#define _DAT_cf0116dc (*(volatile unsigned int *)0xcf0116dc)

void FUN_a00dcc50(uint param_1)
{
  _DAT_cf0116dc = _DAT_cf0116dc & 0x3f;
  _DAT_cf0116dc = _DAT_cf0116dc | (param_1 & 0xff) << 6;
  return;
}
