/* leon2s FUN_a00c10c4 @ 0xa00c10c4-0xa00c12d8, -mcpu=v8 -Os -g.
 * (u8 port, u8 *a, u8 *b, u8 *c, u8 *d), void; c is not used. With w(reg, v) = func_0xa0fb69fc(port, reg, v)
 * (ROM call outside the image): func_0xa0fb6aa0(port, 0x40, 0x10, 1); then four blocks, each selected with
 * w(0xa6, sel) and written byte by byte as w(0xa5, low byte of index), w(0xa4, high byte), w(0xa7, data):
 * sel 0x30 with a[0..15]; after w(0xa6, 9), w(0xa4, 0), w(0xa5, 1), w(0xa7, 0), w(0xa7, 1): sel 0xa with
 * b[0..0x209], sel 0xa again with DAT_a8078620[0..10] at indices 0x20a.., and sel 0x20 with d[0..0x13f].
 * Source form: u16 index; the third block's index is a separate u16 variable.
 */
extern unsigned char DAT_a8078620[];
extern void func_0xa0fb6aa0(unsigned char, unsigned short, unsigned char, unsigned char);
extern void func_0xa0fb69fc(unsigned char, unsigned short, unsigned char);

void FUN_a00c10c4(unsigned char port, unsigned char *a, unsigned char *b, unsigned char *c, unsigned char *d)
{
    unsigned short i, j;

    func_0xa0fb6aa0(port, 0x40, 0x10, 1);
    func_0xa0fb69fc(port, 0xa6, 0x30);
    for (i = 0; i <= 0xf; i++) {
        func_0xa0fb69fc(port, 0xa5, i);
        func_0xa0fb69fc(port, 0xa4, i >> 8);
        func_0xa0fb69fc(port, 0xa7, a[i]);
    }
    func_0xa0fb69fc(port, 0xa6, 9);
    func_0xa0fb69fc(port, 0xa4, 0);
    func_0xa0fb69fc(port, 0xa5, 1);
    func_0xa0fb69fc(port, 0xa7, 0);
    func_0xa0fb69fc(port, 0xa7, 1);
    func_0xa0fb69fc(port, 0xa6, 0xa);
    for (i = 0; i <= 0x209; i++) {
        func_0xa0fb69fc(port, 0xa5, i);
        func_0xa0fb69fc(port, 0xa4, i >> 8);
        func_0xa0fb69fc(port, 0xa7, b[i]);
    }
    func_0xa0fb69fc(port, 0xa6, 0xa);
    for (i = 0; i <= 0xa; i++) {
        j = i + 0x20a;
        func_0xa0fb69fc(port, 0xa5, j);
        func_0xa0fb69fc(port, 0xa4, j >> 8);
        func_0xa0fb69fc(port, 0xa7, DAT_a8078620[i]);
    }
    func_0xa0fb69fc(port, 0xa6, 0x20);
    for (i = 0; i <= 0x13f; i++) {
        func_0xa0fb69fc(port, 0xa5, i);
        func_0xa0fb69fc(port, 0xa4, i >> 8);
        func_0xa0fb69fc(port, 0xa7, d[i]);
    }
}
