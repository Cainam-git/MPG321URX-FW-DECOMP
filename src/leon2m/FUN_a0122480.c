/* leon2m FUN_a0122480 @ 0xa0122480-0xa0122634 (109 words).
 * Writes v to one of four groups of eight hardware registers chosen by sel (4 = all four groups):
 * sel 0: 0xcf01cd30..0xcf01cd4c, sel 1: 0xcf01cdbc..0xcf01cdd8, sel 2: 0xcf01ce48..0xcf01ce64,
 * sel 3: 0xcf01ced4..0xcf01cef0 (each a run of eight words). No direct callers (reached through a pointer).
 * volatile: hardware registers only.
 */
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a0122480(unsigned int sel, unsigned int v)
{
    if (sel == 0 || sel == 4) {
        R(0xcf01cd30) = v;
        R(0xcf01cd34) = v;
        R(0xcf01cd38) = v;
        R(0xcf01cd3c) = v;
        R(0xcf01cd40) = v;
        R(0xcf01cd44) = v;
        R(0xcf01cd48) = v;
        R(0xcf01cd4c) = v;
    }
    if (sel == 1 || sel == 4) {
        R(0xcf01cdbc) = v;
        R(0xcf01cdc0) = v;
        R(0xcf01cdc4) = v;
        R(0xcf01cdc8) = v;
        R(0xcf01cdcc) = v;
        R(0xcf01cdd0) = v;
        R(0xcf01cdd4) = v;
        R(0xcf01cdd8) = v;
    }
    if (sel == 2 || sel == 4) {
        R(0xcf01ce48) = v;
        R(0xcf01ce4c) = v;
        R(0xcf01ce50) = v;
        R(0xcf01ce54) = v;
        R(0xcf01ce58) = v;
        R(0xcf01ce5c) = v;
        R(0xcf01ce60) = v;
        R(0xcf01ce64) = v;
    }
    if (sel == 3 || sel == 4) {
        R(0xcf01ced4) = v;
        R(0xcf01ced8) = v;
        R(0xcf01cedc) = v;
        R(0xcf01cee0) = v;
        R(0xcf01cee4) = v;
        R(0xcf01cee8) = v;
        R(0xcf01ceec) = v;
        R(0xcf01cef0) = v;
    }
}
