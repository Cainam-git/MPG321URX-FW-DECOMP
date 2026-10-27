/* leon2m FUN_a0109148 @ 0xa0109148-0xa0109278 (304 bytes), flags -mcpu=v8 -O3 -g. Caller: FUN_a013d684.
 * Writes the 16-bit values a and b with FUN_a00f308c (two byte registers per value) to a register pair selected
 * by port: 0: 0xcf011b00 = a, 0xcf011b10 = b; 1: 0xcf011b20, 0xcf011b30 and 0xcf011b80, 0xcf011b90; 2: 0xcf011b40,
 * 0xcf011b50 and 0xcf011ba0, 0xcf011bb0; 3: 0xcf011b60, 0xcf011b70 and 0xcf011bc0, 0xcf011bd0 (a to the first and
 * third, b to the second and fourth). Other port values write nothing.
 * Source form: a switch over port (compare tree); register addresses as pointer constants like FUN_a0109844.
 */
#define REG(a) ((volatile unsigned int *)(a))
extern void FUN_a00f308c(volatile unsigned int *r, unsigned int v);

void FUN_a0109148(unsigned char port, unsigned short a, unsigned short b)
{
    switch (port) {
    case 0:
        FUN_a00f308c(REG(0xcf011b00), a);
        FUN_a00f308c(REG(0xcf011b10), b);
        break;
    case 1:
        FUN_a00f308c(REG(0xcf011b20), a);
        FUN_a00f308c(REG(0xcf011b30), b);
        FUN_a00f308c(REG(0xcf011b80), a);
        FUN_a00f308c(REG(0xcf011b90), b);
        break;
    case 2:
        FUN_a00f308c(REG(0xcf011b40), a);
        FUN_a00f308c(REG(0xcf011b50), b);
        FUN_a00f308c(REG(0xcf011ba0), a);
        FUN_a00f308c(REG(0xcf011bb0), b);
        break;
    case 3:
        FUN_a00f308c(REG(0xcf011b60), a);
        FUN_a00f308c(REG(0xcf011b70), b);
        FUN_a00f308c(REG(0xcf011bc0), a);
        FUN_a00f308c(REG(0xcf011bd0), b);
        break;
    }
}
