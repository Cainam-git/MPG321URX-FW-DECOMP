/* leon2s FUN_a00c1778 @ 0xa00c1778-0xa00c18fc (-mcpu=v8 -Os -g).
 * Resets the 16-byte record DAT_a807d5c8[port]: clears bit-fields 31..27 and bytes +0xd, +0xc, +8 (word),
 * sets field 26..24 to 5 and byte +5 to 0x22, clears bytes +4 and +2 and bits 23..21, sets field 20..16 to 1;
 * clears DAT_a807d630[port] and DAT_a807d5c0[port]; writes 0xff to DAT_a807d5c6, DAT_a807d629, DAT_a807d62b and
 * DAT_a807d636. When flag is set: ports 0/1 call func_0xa0fb67b8 for registers 0x31f, 0x309 (mask 0x80) and 0x321
 * (mask 0xe), other ports func_0xa0fb6aa0(port - 2, ...) for 0xc00 and 9; when flag is clear
 * func_0xa0fb6c98(port - 4, 0x407, 0x80, 1).
 * Source form: the statement order of the byte stores is the firmware's store order.
 */
struct rec16 {
    unsigned int b31 : 1;
    unsigned int b30 : 1;
    unsigned int b29 : 1;
    unsigned int b28 : 1;
    unsigned int b27 : 1;
    unsigned int f24 : 3;
    unsigned int b23 : 1;
    unsigned int b22 : 1;
    unsigned int b21 : 1;
    unsigned int f16 : 5;
    unsigned char b2;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    unsigned char b7;
    unsigned int t;
    unsigned char bc;
    unsigned char bd;
    unsigned char be;
    unsigned char bf;
};
extern struct rec16 DAT_a807d5c8[];
extern unsigned char DAT_a807d636;
extern unsigned char DAT_a807d630[];
extern unsigned char DAT_a807d5c0[];
extern unsigned char DAT_a807d5c6;
extern unsigned char DAT_a807d629;
extern unsigned char DAT_a807d62b;
extern void func_0xa0fb6c98(unsigned char, unsigned short, unsigned char, unsigned char);
extern void func_0xa0fb6aa0(unsigned char, unsigned short, unsigned char, unsigned char);
extern void func_0xa0fb67b8(unsigned char, unsigned short, unsigned char, unsigned char);

void FUN_a00c1778(unsigned char port, unsigned char flag)
{
    DAT_a807d5c8[port].b31 = 0;
    DAT_a807d5c8[port].b30 = 0;
    DAT_a807d5c8[port].b29 = 0;
    DAT_a807d5c8[port].b28 = 0;
    DAT_a807d5c8[port].b27 = 0;
    DAT_a807d5c8[port].bd = 0;
    DAT_a807d5c8[port].bc = 0;
    DAT_a807d5c8[port].t = 0;
    DAT_a807d5c8[port].f24 = 5;
    DAT_a807d5c8[port].b5 = 0x22;
    DAT_a807d5c8[port].b4 = 0;
    DAT_a807d5c8[port].b2 = 0;
    DAT_a807d5c8[port].b23 = 0;
    DAT_a807d5c8[port].b22 = 0;
    DAT_a807d5c8[port].b21 = 0;
    DAT_a807d5c8[port].f16 = 1;
    DAT_a807d630[port] = 0;
    DAT_a807d5c0[port] = 0;
    DAT_a807d5c6 = 0xff;
    DAT_a807d629 = 0xff;
    DAT_a807d62b = 0xff;
    DAT_a807d636 = 0xff;
    if (flag != 0) {
        if (port <= 1) {
            func_0xa0fb67b8(port, 0x31f, 0x80, 1);
            func_0xa0fb67b8(port, 0x309, 0x80, 1);
            func_0xa0fb67b8(port, 0x321, 0xe, 1);
        } else {
            func_0xa0fb6aa0(port - 2, 0xc00, 1, 1);
            func_0xa0fb6aa0(port - 2, 9, 0x40, 1);
        }
    } else {
        func_0xa0fb6c98(port - 4, 0x407, 0x80, 1);
    }
}
