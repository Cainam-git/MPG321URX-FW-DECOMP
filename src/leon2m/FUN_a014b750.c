/* FUN_a014b750 (leon2m 0xa014b750-0xa014b844, 244 bytes), flags -mcpu=v8 -O3 -g.
 * The FUN_a014b65c mapping with FUN_a01254b8 as the final call: maps x =
 * FUN_a01421c4(FUN_a0142218(FUN_a0125198(c))) = 0x61, 0x71, 0x81 to k = 1, 2, 3 (else 0) and calls
 * FUN_a01254b8(FUN_a0125124(byte +0x10 of DAT_a802e116[k]), b) as a tail call. Source form: the form of
 * FUN_a014b65c.
 */
struct E12 { unsigned char p0[0x10]; unsigned char b10; unsigned char p11; };
extern struct E12 DAT_a802e116[];
extern int FUN_a0125198(unsigned char);
extern unsigned char FUN_a0142218(unsigned char v);
extern unsigned char FUN_a01421c4(unsigned char x);
extern unsigned char FUN_a0125124(unsigned int param_1);
extern void FUN_a01254b8(unsigned char n, unsigned char on);

void FUN_a014b750(unsigned char c, unsigned char b)
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
    FUN_a01254b8(FUN_a0125124(DAT_a802e116[k & 3].b10), b);
}
