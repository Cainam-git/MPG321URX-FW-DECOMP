/* leon2s FUN_a00d2f20 @ 0xa00d2f20-0xa00d3114 (-mcpu=v8 -Os -g).
 * int (unsigned int mode), returns 1. By mode: 1 -> DAT_a8078c44 = 0x10e, byte table DAT_9f1c43a8; 4 -> 0x13b,
 * DAT_9f1c5600; 5 -> 0x15b, DAT_9f1c51a8; 6 -> 0x1a9, DAT_9f1c4d08; 7 and 8 -> 0x10e and return at once; 3 and
 * every other value -> 0x10e, DAT_9f1c5a38 (the tables sit 0xF10000 higher in the image).
 * Register word 0xd0013fd0 (read with func_0xa0f71528, fields set with func_0xa0f714b8(&v, hi, lo, val), written
 * with func_0xa0f71534): fields (2,0) = 7 and (5,4) = 0, written back. For i = 0..0x400: field (0x13,8) = i,
 * written back; while sum <= 0x3fffe the next table byte c is added to sum (c > 0xef: ((c & 0xf) << 8) plus the
 * following byte); sum is written to 0xd0013fd8 (i != 0x400) or into field (0x11,0) of 0xd0013fdc (i == 0x400);
 * when DAT_a8078c44 < i < DAT_a8078c44 + 500: DAT_a8077c0c[i - DAT_a8078c44] = sum.
 * The switch jumps through the table at 0xa00d2f00 (0x9f1c2f00 in the code). Source form: case 3 is written out
 * with the default body (the table sends 2 to the default block and 3 to its own copy).
 */
extern unsigned int func_0xa0f71528(unsigned int);
extern void func_0xa0f71534(unsigned int, unsigned int);
extern void func_0xa0f714b8(unsigned int *, unsigned int, unsigned int, unsigned int);
extern unsigned short DAT_a8078c44;
extern unsigned int DAT_a8077c0c[];
extern const unsigned char DAT_9f1c43a8[];
extern const unsigned char DAT_9f1c4d08[];
extern const unsigned char DAT_9f1c51a8[];
extern const unsigned char DAT_9f1c5600[];
extern const unsigned char DAT_9f1c5a38[];

int FUN_a00d2f20(unsigned int mode)
{
    unsigned int v = 0;
    unsigned int w = 0;
    const unsigned char *tab;
    unsigned int sum, k, i;
    unsigned char c;

    switch (mode) {
    case 1:
        DAT_a8078c44 = 0x10e;
        tab = DAT_9f1c43a8;
        break;
    case 3:
        DAT_a8078c44 = 0x10e;
        tab = DAT_9f1c5a38;
        break;
    case 4:
        DAT_a8078c44 = 0x13b;
        tab = DAT_9f1c5600;
        break;
    case 5:
        DAT_a8078c44 = 0x15b;
        tab = DAT_9f1c51a8;
        break;
    case 6:
        DAT_a8078c44 = 0x1a9;
        tab = DAT_9f1c4d08;
        break;
    case 7:
    case 8:
        DAT_a8078c44 = 0x10e;
        return 1;
    default:
        DAT_a8078c44 = 0x10e;
        tab = DAT_9f1c5a38;
        break;
    }
    v = func_0xa0f71528(0xd0013fd0);
    func_0xa0f714b8(&v, 2, 0, 7);
    func_0xa0f714b8(&v, 5, 4, 0);
    func_0xa0f71534(0xd0013fd0, v);
    sum = 0;
    k = 0;
    for (i = 0; i <= 0x400; i++) {
        func_0xa0f714b8(&v, 0x13, 8, i);
        func_0xa0f71534(0xd0013fd0, v);
        if (sum <= 0x3fffe) {
            c = tab[k];
            if (c > 0xef)
                sum += ((c & 0xf) << 8) + tab[++k];
            else
                sum += c;
            k++;
        }
        if (i != 0x400)
            func_0xa0f71534(0xd0013fd8, sum);
        else {
            w = func_0xa0f71528(0xd0013fdc);
            func_0xa0f714b8(&w, 0x11, 0, sum);
            func_0xa0f71534(0xd0013fdc, w);
        }
        if (DAT_a8078c44 < i && i < DAT_a8078c44 + 500)
            DAT_a8077c0c[i - DAT_a8078c44] = sum;
    }
    return 1;
}
