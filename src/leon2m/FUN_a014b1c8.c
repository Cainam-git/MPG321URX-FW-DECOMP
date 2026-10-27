/* FUN_a014b1c8 (leon2m 0xa014b1c8-0xa014b280, 184 bytes), flags -mcpu=v8 -O3 -g.
 * Maps x = FUN_a01421c4(FUN_a0142218(FUN_a0125198(c))) = 0x61, 0x71, 0x81 to k = 1, 2, 3 (0x51 and anything else to
 * 0) like FUN_a014af84, then calls FUN_a012c320(FUN_a0125124(byte +0x10 of DAT_a802e116[k]), a, b, &v, 1) with v a
 * local copy of d. Source form: the FUN_a014af84 mapping; d is copied into a local halfword (declared first) whose
 * address is passed.
 */
struct E12 { unsigned char p0[0x10]; unsigned char b10; unsigned char p11; };
extern struct E12 DAT_a802e116[];
extern int FUN_a0125198(unsigned char);
extern unsigned char FUN_a0142218(unsigned char v);
extern unsigned char FUN_a01421c4(unsigned char x);
extern unsigned char FUN_a0125124(unsigned int param_1);
extern void FUN_a012c320(unsigned char, unsigned short, int, unsigned short *, unsigned char);

void FUN_a014b1c8(unsigned char c, unsigned short a, int b, unsigned short d)
{
    unsigned short v = d;
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
    FUN_a012c320(FUN_a0125124(DAT_a802e116[k & 3].b10), a, b, &v, 1);
}
