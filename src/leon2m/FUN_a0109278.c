/* leon2m FUN_a0109278 @ 0xa0109278-0xa01093a8 (304 bytes), flags -mcpu=v8 -O3 -g. Caller: FUN_a013d684 (four calls).
 * Writes the 16-bit values a and b with FUN_a00f308c (two byte registers per value) to a register pair selected
 * by port: 0: 0xcf011b08 = a, 0xcf011b18 = b; 1: 0xcf011b28, 0xcf011b38 and 0xcf011b88, 0xcf011b98; 2: 0xcf011b48,
 * 0xcf011b58 and 0xcf011ba8, 0xcf011bb8; 3: 0xcf011b68, 0xcf011b78 and 0xcf011bc8, 0xcf011bd8 (a to the first and
 * third, b to the second and fourth). Other port values write nothing.
 * Source form: a switch over port (compare tree); register addresses as pointer constants like FUN_a0109844.
 */
#define REG(a) ((volatile unsigned int *)(a))
extern void FUN_a00f308c(volatile unsigned int *r, unsigned int v);

void FUN_a0109278(unsigned char port, unsigned short a, unsigned short b)
{
    switch (port) {
    case 0:
        FUN_a00f308c(REG(0xcf011b08), a);
        FUN_a00f308c(REG(0xcf011b18), b);
        break;
    case 1:
        FUN_a00f308c(REG(0xcf011b28), a);
        FUN_a00f308c(REG(0xcf011b38), b);
        FUN_a00f308c(REG(0xcf011b88), a);
        FUN_a00f308c(REG(0xcf011b98), b);
        break;
    case 2:
        FUN_a00f308c(REG(0xcf011b48), a);
        FUN_a00f308c(REG(0xcf011b58), b);
        FUN_a00f308c(REG(0xcf011ba8), a);
        FUN_a00f308c(REG(0xcf011bb8), b);
        break;
    case 3:
        FUN_a00f308c(REG(0xcf011b68), a);
        FUN_a00f308c(REG(0xcf011b78), b);
        FUN_a00f308c(REG(0xcf011bc8), a);
        FUN_a00f308c(REG(0xcf011bd8), b);
        break;
    }
}
