/* FUN_a00b14b0 (leon2s 0xa00b14b0-0xa00b14dc, 44 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Returns byte 0x129 of the 300-byte record port of ARR_a807dc18 for port 0 or 1, else 0.
 * Source form: early return of 0 (a result variable adds a final and 0xff).
 */
extern unsigned char ARR_a807dc18[][300];
unsigned char FUN_a00b14b0(unsigned char port)
{
    if (port > 1)
        return 0;
    return ARR_a807dc18[port][0x129];
}
