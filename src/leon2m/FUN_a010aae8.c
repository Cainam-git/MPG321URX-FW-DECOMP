/* leon2m FUN_a010aae8 @ 0xa010aae8-0xa010abd4 (59 words). BYTE-EXACT: -mcpu=v8 -O3 -g, jf 100 match=True,
 * rawcmp 0/59.
 * What it does (leaf): per-port fill colour: writes the three bytes c0, c1, c2 to the hardware registers
 *   port 0: 0xcf011fc4 / fc8 / fcc     port 1: 0xcf011fd0 / fd4 / fd8
 *   port 2: 0xcf011fdc / fe0 / fe4     port 3: 0xcf011fe8 / fec / ff0     other port: nothing.
 * Callers: the fill colour set FUN_a0145fe8 (colour-cycling chain) and the GlobalModeHandler state 5 entry
 * FUN_a01518c8 (as FUN_a010aae8(port, 0, 0, 0): black). Not rate-dependent.
 * All four parameters are u8 (fw 'and 0xff' at each store). volatile only on the real hardware registers.
 * Aids: none.
 */
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a010aae8(unsigned char port, unsigned char c0, unsigned char c1, unsigned char c2)
{
    switch (port) {
    case 0: R(0xcf011fc4) = c0; R(0xcf011fc8) = c1; R(0xcf011fcc) = c2; break;
    case 1: R(0xcf011fd0) = c0; R(0xcf011fd4) = c1; R(0xcf011fd8) = c2; break;
    case 2: R(0xcf011fdc) = c0; R(0xcf011fe0) = c1; R(0xcf011fe4) = c2; break;
    case 3: R(0xcf011fe8) = c0; R(0xcf011fec) = c1; R(0xcf011ff0) = c2; break;
    }
}
