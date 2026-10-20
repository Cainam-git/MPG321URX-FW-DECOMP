/* leon2s FUN_a00b0138 @ 0xa00b0138-0xa00b0248 (68 words), flags -mcpu=v8 -Os -g.
 * Code facts: copies the 2 x {u16 a, u16 b} ROM table DAT_a00b4e04 to the stack (memcpy FUN_a00b15d8, 8
 * bytes); p = (u8) port; a = FUN_a00acac0(p), b = FUN_a00acb00(p) (u16). found = 1 if (a, b) equals one
 * table entry. found == 1: if bit 2 of FUN_a00a6bb8(p, 0x46) is set, FUN_a00a6c98(p, 0x46, 4, 0) and
 * changed = 1. found == 0: if bit 2 is clear, FUN_a00a6c98(port, 0x46, 4, 1) and changed = 1 (this arm
 * re-converts the int param: 'and %i0,0xff,%i0'). Returns changed (u8 0/1; 'and 1' = return narrowing).
 * Fixes vs the autoc draft (76.47, did not compile): one shared return of 'changed' (early returns let
 * gcse fold changed = 0 into each exit; the fw keeps %l2 live and returns 'and %l2,1' in three delay
 * slots), int param with a u8 copy p, u8 callee prototypes, memcpy returning void *. Aids: none.
 */
extern const unsigned short DAT_a00b4e04[];
extern unsigned char FUN_a00a6bb8(unsigned char, unsigned short);
extern void FUN_a00a6c98(unsigned char, unsigned short, unsigned char, unsigned char);
extern unsigned short FUN_a00acac0(unsigned char);
extern unsigned short FUN_a00acb00(unsigned char);
extern void *FUN_a00b15d8(void *, const void *, unsigned int);

unsigned char FUN_a00b0138(unsigned int param_1)
{
    unsigned short tab[4];
    unsigned char p;
    unsigned short a, b;
    unsigned char changed;
    unsigned char found;
    unsigned char i;

    FUN_a00b15d8(tab, DAT_a00b4e04, 8);
    p = param_1;
    a = FUN_a00acac0(p);
    b = FUN_a00acb00(p);
    changed = 0;
    found = 0;
    for (i = 0; i <= 1; i++) {
        if (a == tab[i * 2] && b == tab[i * 2 + 1]) {
            found = 1;
            break;
        }
    }
    if (found == 1) {
        if (FUN_a00a6bb8(p, 0x46) & 4) {
            FUN_a00a6c98(p, 0x46, 4, 0);
            changed = 1;
        }
    } else if (found == 0) {
        if ((FUN_a00a6bb8(param_1, 0x46) & 4) == 0) {
            FUN_a00a6c98(param_1, 0x46, 4, 1);
            changed = 1;
        }
    }
    return changed & 1;
}
