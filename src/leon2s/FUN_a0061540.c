/* FUN_a0061540 (leon2s 0xa0061540-0xa006155c, 28 bytes, leaf), flags -mcpu=v8 -Os -g.
 * *p = (*p & ~m) | (v & m) on a volatile word pointer (the store stays before retl). Called by the wrapper
 * FUN_a00615cc.
 * Source form: 'v &= m;' as its own statement gives the firmware's and/andn order.
 */
void FUN_a0061540(volatile unsigned int *p, unsigned int v, unsigned int m)
{
    v &= m;
    *p = (*p & ~m) | v;
}
