/* leon2s FUN_a006d3d8 @ 0xa006d3d8 (-mcpu=v8 -Os -g)
 * Using `unsigned char` for the loop counter means the compiler will naturally emit an `and %o4, 0xff, %g1` when widening the counter for the multiplication index or comparison, matching the target's sequence. The increment `i = i + 1` avoids an explicit mask operation since the type truncation handles it. The comparison `i <= 8` on the unsigned char gives the `bleu` branch with the masked value.
 */
extern unsigned char DAT_a807a824[];

void FUN_a006d3d8(void)
{
    unsigned char i = 0;
    unsigned int j;
    
    do {
        j = i * 20;
        i = i + 1;
        DAT_a807a824[j] = 1;
    } while (i <= 8);
}
