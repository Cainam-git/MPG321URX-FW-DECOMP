/* leon2m FUN_a00b6514 @ 0xa00b6514-0xa00b65e4 (52 words), flags -mcpu=v8 -O3 -g.
 * Code facts: row = (u8)(byte 0xa802d433 * 2 + 9); col = 0x2a, or 0x2b / 0x2d / 0x2e for p1 == 1 / 2 / 3 (u8);
 * FUN_a0146c40(0, 0, 0); FUN_a014667c(0, 0, 0, 0, 0, 0xc, 0, 0, 0, 0, 0) (11 args, 5 on the stack);
 * FUN_a0146870(0, col*24, row*36 + 0x1a, col*24 + 0x17, row*36 + 0x51, 0); tail call FUN_a0146c40(0, 1, 0). The +9
 * belongs to the row before the *36 (fw 'add %g1, 9' then 'and 0xff' then *36).
 * Source form: row and col are u8 locals.
 * Compiler aids: none.
 */
extern unsigned char DAT_a802d433;
extern void FUN_a014667c(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a0146870(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a0146c40(unsigned int, unsigned int, unsigned int);

void FUN_a00b6514(unsigned char param_1)
{
    unsigned char row;
    unsigned char col;

    row = DAT_a802d433 * 2 + 9;
    col = 0x2a;
    if (param_1 == 1) {
        col = 0x2b;
    } else if (param_1 == 2) {
        col = 0x2d;
    } else if (param_1 == 3) {
        col = 0x2e;
    }
    FUN_a0146c40(0, 0, 0);
    FUN_a014667c(0, 0, 0, 0, 0, 0xc, 0, 0, 0, 0, 0);
    FUN_a0146870(0, col * 0x18, row * 36 + 0x1a, col * 0x18 + 0x17, row * 36 + 0x51, 0);
    FUN_a0146c40(0, 1, 0);
}
