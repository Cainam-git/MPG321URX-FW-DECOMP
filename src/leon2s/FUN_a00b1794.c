/* FUN_a00b1794 (leon2s 0xa00b1794-0xa00b17e8, 84 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Busy loop: n outer passes of 50000 inner passes, each inner pass a single nop. Both counters are halfwords;
 * the inner limit is an unsigned int variable (gives the firmware's 'cmp 50000; bcs').
 */
void FUN_a00b1794(unsigned short n)
{
    unsigned short i, j;
    unsigned int m = 50000;

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            __asm__("nop");
}
