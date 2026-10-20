/* FUN_a00910ec (leon2s 0xa00910ec-0xa00911bc, 208 bytes), flags -mcpu=v8 -Os -g.
 * v = FUN_a0074f60(port & 1), multiplied by 4 when byte 4 of the 24-byte record port & 1 of ARR_a807cc64 is
 * non-zero. Then v = v / FUN_a0090d7c(port) * 8 / (low byte of FUN_a0090dec(port)) (signed divisions), doubled
 * when bits 5..7 of FUN_a00a657c(port, 0x144) equal 3 (value 0x60). Returns v as a halfword.
 * Source form: one unsigned short variable v holds every intermediate result; port & 1 is written at each use.
 */
struct rec {
    unsigned char f0[4];
    unsigned char f4;
    unsigned char f5[19];
};

extern struct rec ARR_a807cc64[];
extern unsigned short FUN_a0074f60(unsigned char);
extern unsigned char FUN_a0090d7c(unsigned char port);
extern int FUN_a0090dec(unsigned char param_1);
extern unsigned int FUN_a00a657c(unsigned char, unsigned short);

unsigned short FUN_a00910ec(unsigned char port)
{
    unsigned short v = FUN_a0074f60(port & 1);
    unsigned char a;
    unsigned char b;

    if (ARR_a807cc64[port & 1].f4)
        v <<= 2;
    a = FUN_a0090d7c(port);
    b = FUN_a0090dec(port);
    v = v / a * 8 / b;
    if ((FUN_a00a657c(port, 0x144) & 0xe0) == 0x60)
        v = v * 2;
    return v;
}
