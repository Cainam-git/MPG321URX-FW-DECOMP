/* FUN_a014af84 (leon2m 0xa014af84-0xa014b01c, 152 bytes), flags -mcpu=v8 -O3 -g.
 * Computes x = FUN_a01421c4(FUN_a0142218(FUN_a0125198(c))), maps x = 0x61, 0x71, 0x81 to k = 1, 2, 3 (0x51 and
 * anything else to 0) and returns FUN_a0125124(byte +0x10 of 0x12-byte entry k of DAT_a802e116). Source form: k = 0
 * before a switch that lists case 0x51 with the default value (keeps the compare-tree root at 0x61).
 */
struct E12 { unsigned char p0[0x10]; unsigned char b10; unsigned char p11; };
extern struct E12 DAT_a802e116[];
extern int FUN_a0125198(unsigned char);
extern unsigned char FUN_a0142218(unsigned char v);
extern unsigned char FUN_a01421c4(unsigned char x);
extern unsigned char FUN_a0125124(unsigned int param_1);

unsigned char FUN_a014af84(unsigned char c)
{
    unsigned char x = FUN_a01421c4(FUN_a0142218(FUN_a0125198(c)));
    unsigned char k = 0;

    switch (x) {
    case 0x51:
        k = 0;
        break;
    case 0x61:
        k = 1;
        break;
    case 0x71:
        k = 2;
        break;
    case 0x81:
        k = 3;
        break;
    }
    return FUN_a0125124(DAT_a802e116[k & 3].b10);
}
