/* FUN_a0062718 (leon2s 0xa0062718-0xa00627a8, 144 bytes), flags -mcpu=v8 -Os -g.
 * Unsigned interpolation step called by FUN_a00627a8. For x >= lo: returns b when hi >= x, else a. For x < lo:
 * returns a when hi <= x, b when hi >= lo, otherwise a plus (b - a) * (hi - x) / (lo - x) when b >= a, or a minus
 * (a - b) * (hi - x) / (lo - x) when b < a.
 * Source form: the x >= lo case is tested first and the result is kept in the parameter a ('a = b', 'a +=',
 * 'a -=') with one return.
 */
unsigned int FUN_a0062718(unsigned int a, unsigned int b, unsigned int x, unsigned int lo, unsigned int hi)
{
    if (x >= lo) {
        if (hi >= x)
            a = b;
    } else if (hi > x) {
        if (hi >= lo)
            a = b;
        else if (b >= a)
            a += (b - a) * (hi - x) / (lo - x);
        else
            a -= (a - b) * (hi - x) / (lo - x);
    }
    return a;
}
