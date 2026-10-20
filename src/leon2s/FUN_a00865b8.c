/* leon2s FUN_a00865b8 @ 0xa00865b8  MATCH (-mcpu=v8 -Os -g)
 * The function takes a byte value `a` and a byte value `b`, selects a mode `c` (1 if `b == 1`, else 2), then repeatedly calls `FUN_a0086360` with `(a, 0x80, 0x600, c)`. After each call it increments a counter; if the call's low byte is zero it returns 1 immediately. It loops while the counter is ≤ 4, then returns 0. The main uncertainty is whether `i` should be `unsigned char` or `unsigned int` with explicit masking — the `and %i1, 0xff, %g1` before the compare suggests byte semantics, but the tool may need to try both.
 */
extern int FUN_a0086360(int, int, int, int);

int FUN_a00865b8(int a, int b)
{
    unsigned char i = 0;
    unsigned char c;
    
    if ((unsigned char)b == 1)
        c = 1;
    else
        c = 2;
    
    do {
        int r = FUN_a0086360((unsigned char)a, 0x80, 0x600, c);
        i++;
        if ((r & 0xff) == 0)
            return 1;
    } while (i <= 4);
    
    return 0;
}
