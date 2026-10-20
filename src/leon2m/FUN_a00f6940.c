/* leon2m FUN_a00f6940 @ 0xa00f6940-0xa00f6ab4, flags -mcpu=v8 -O3 -g. No direct callers found.
 * For p 0..4 (jump table at 0x96394) it first writes (0xcf00ec84 & 0xfc) | p to 0xcf00ec84, then:
 *   p 0 and 4: 0xcf00ee40 |= 0x40, 0xcf00ee20 = 0x80, 0xcf00ee24 = 1
 *   p 1:       0xcf00ee40 |= 0x80, 0xcf00ee28 = 0x80, 0xcf00ee2c = 1
 *   p 2:       0xcf00ee68 = 0x40,  0xcf00ee30 = 0x80, 0xcf00ee34 = 1
 *   p 3:       0xcf00ee68 = 0x80,  0xcf00ee38 = 0x80, 0xcf00ee3c = 1
 * For every p it then sets bits 0..2 of 0xcf00ee50 and writes the bytes a, b, c to 0xcf00ee44, 0xcf00ee48,
 * 0xcf00ee4c. Source form: one shared "case 0: case 4:" body and ascending case order (separate bodies or
 * other orders change the register choice or the block order).
 */
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a00f6940(unsigned int p, unsigned char a, unsigned char b, unsigned char c)
{
    switch (p) {
    case 0:
    case 4:
        R(0xcf00ec84) = (R(0xcf00ec84) & 0xfc) | p;
        R(0xcf00ee40) |= 0x40;
        R(0xcf00ee20) = 0x80;
        R(0xcf00ee24) = 1;
        break;
    case 1:
        R(0xcf00ec84) = (R(0xcf00ec84) & 0xfc) | p;
        R(0xcf00ee40) |= 0x80;
        R(0xcf00ee28) = 0x80;
        R(0xcf00ee2c) = 1;
        break;
    case 2:
        R(0xcf00ec84) = (R(0xcf00ec84) & 0xfc) | p;
        R(0xcf00ee68) = 0x40;
        R(0xcf00ee30) = 0x80;
        R(0xcf00ee34) = 1;
        break;
    case 3:
        R(0xcf00ec84) = (R(0xcf00ec84) & 0xfc) | p;
        R(0xcf00ee68) = 0x80;
        R(0xcf00ee38) = 0x80;
        R(0xcf00ee3c) = 1;
        break;
    }
    R(0xcf00ee50) |= 7;
    R(0xcf00ee44) = a;
    R(0xcf00ee48) = b;
    R(0xcf00ee4c) = c;
}
