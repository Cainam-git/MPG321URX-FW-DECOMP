/* FUN_a00c22a0 (leon2s 0xa00c22a0-0xa00c2488, 488 bytes), flags -mcpu=v8 -Os -g.
 * Loads three 128-byte tables into a port block. Pulses bit 1 of reg 0 (ROM routine func_0xa0fb7f1c); each
 * table comes from ROM (0x9f1b74b8, 0x9f1b7175, 0x9f1b7438) when DAT_a807d628 is set, otherwise read with
 * func_0xa0f9d2e0 (addresses 0x50a, 0x285, 0x48a) into a stack buffer, and is sent with FUN_a00c99a4 in
 * modes 5, 3 and 4; then DAT_a8078d38 is sent in mode 0 and regs 0 / 3 are written (func_0xa0fb7ee0).
 * Source form: the counter is initialised at its declaration, so the first copy loop has no own init.
 */
extern unsigned char DAT_a807d628;
extern unsigned char DAT_a8078d38[];
extern const unsigned char DAT_9f1b74b8[];
extern const unsigned char DAT_9f1b7148[];
extern const unsigned char DAT_9f1b7438[];
extern void func_0xa0fb7f1c(unsigned int, short, unsigned int, unsigned int);
extern void func_0xa0fb7ee0(unsigned int, unsigned int, unsigned int);
extern void func_0xa0f9d2e0(unsigned short, unsigned short, unsigned char *);
extern void FUN_a00c99a4(unsigned int, unsigned char *, unsigned char, unsigned char, unsigned short);

void FUN_a00c22a0(unsigned char port)
{
    unsigned char a[128];
    unsigned char b[128];
    unsigned char c[128];
    unsigned short i = 0;

    func_0xa0fb7f1c(port, 0, 2, 1);
    func_0xa0fb7f1c(port, 0, 2, 0);
    if (DAT_a807d628 != 0) {
        for (; i < 0x80; i++)
            a[i] = DAT_9f1b74b8[i];
    } else {
        func_0xa0f9d2e0(0x50a, 0x80, a);
    }
    FUN_a00c99a4(port, a, 5, 0, 0x400);
    if (DAT_a807d628 != 0) {
        for (i = 0; i < 0x80; i++)
            b[i] = DAT_9f1b7148[i + 0x2d];
    } else {
        func_0xa0f9d2e0(0x285, 0x80, b);
    }
    FUN_a00c99a4(port, b, 3, 0, 0x400);
    if (DAT_a807d628 != 0) {
        for (i = 0; i < 0x80; i++)
            c[i] = DAT_9f1b7438[i];
    } else {
        func_0xa0f9d2e0(0x48a, 0x80, c);
    }
    FUN_a00c99a4(port, c, 4, 0, 0x400);
    FUN_a00c99a4(port, DAT_a8078d38, 0, 0, 0x400);
    func_0xa0fb7ee0(port, 0, 0);
    func_0xa0fb7ee0(port, 3, 1);
}
