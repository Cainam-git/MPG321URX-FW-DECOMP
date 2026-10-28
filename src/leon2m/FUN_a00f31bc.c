/* leon2m FUN_a00f31bc @ 0xa00f31bc-0xa00f328c (52 words), flags -mcpu=v8 -O3 -g.
 * Called by FUN_a00f4e60 and FUN_a00f557c. Read-modify-writes the hardware registers A = 0xcf020080,
 * B = 0xcf02006c and C = 0xcf02003c (volatile) by sel:
 *   sel == 2:  B &= ~0xe0, A &= ~0x10, A |= 0x80, C &= ~0xe0;
 *   sel == 0:  B &= ~0xe0, A &= ~0x80, A |= 0x10, C &= ~0xe0;
 *   other sel: A &= ~0x90, B |= 0xe0, C |= 0xe0.
 * Source form: the two cases are tested inside 'if (sel <= 3)' (fw 'cmp 3; bgu' first), sel == 2 before sel == 0,
 * each with its own return; the other values fall through to the common block.
 */
#define R80 (*(volatile unsigned int *)0xcf020080)
#define R6C (*(volatile unsigned int *)0xcf02006c)
#define R3C (*(volatile unsigned int *)0xcf02003c)

void FUN_a00f31bc(unsigned int sel)
{
    if (sel <= 3) {
        if (sel == 2) {
            R6C &= ~0xe0;
            R80 &= ~0x10;
            R80 |= 0x80;
            R3C &= ~0xe0;
            return;
        }
        if (sel == 0) {
            R6C &= ~0xe0;
            R80 &= ~0x80;
            R80 |= 0x10;
            R3C &= ~0xe0;
            return;
        }
    }
    R80 &= ~0x90;
    R6C |= 0xe0;
    R3C |= 0xe0;
}
