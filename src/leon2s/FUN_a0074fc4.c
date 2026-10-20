/* FUN_a0074fc4 (leon2s 0xa0074fc4-0xa007501c, 88 bytes), flags -mcpu=v8 -Os -g.
 * Compares the halfword at offset 0xa of the 24-byte record port of DAT_a807cc64 with FUN_a0074f60(port)
 * (taken as a halfword); returns 1 when they differ by more than 2, else 0.
 * abs() is the GCC built-in (sra/xor/sub); an if (d < 0) d = -d form swaps the xor operands.
 */
struct Rec24 { unsigned char _0[0xa]; unsigned short ha; unsigned char _c[0xc]; };
extern struct Rec24 DAT_a807cc64[];
extern unsigned short FUN_a0074f60(unsigned char);
extern int abs(int);

int FUN_a0074fc4(unsigned char port)
{
    int d = DAT_a807cc64[port].ha - FUN_a0074f60(port);

    return abs(d) > 2;
}
