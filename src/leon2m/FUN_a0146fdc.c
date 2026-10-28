/* leon2m FUN_a0146fdc @ 0xa0146fdc-0xa014705c (32 words); -mcpu=v8 -O2 -g and -O3 -g give the same code. No direct callers.
 * x = c for c 0..3, else 4; then FUN_a00f6898(x & 7) when b is 1, otherwise FUN_a00f67d0(x & 7) (tail calls;
 * compare FUN_a0146ef4, which passes the same two callees a record field).
 * Source form: x = 4 at its declaration and a switch with cases 0..3 only (a default arm gives another layout).
 */
extern void FUN_a00f67d0(int p);
extern void FUN_a00f6898(unsigned int p);

void FUN_a0146fdc(unsigned char c, unsigned char b)
{
    unsigned char x = 4;

    switch (c) {
    case 0:
        x = 0;
        break;
    case 1:
        x = 1;
        break;
    case 2:
        x = 2;
        break;
    case 3:
        x = 3;
        break;
    }
    if (b == 1)
        FUN_a00f6898(x & 7);
    else
        FUN_a00f67d0(x & 7);
}
