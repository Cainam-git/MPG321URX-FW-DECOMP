/*
 * FUN_a00d38a8 (leon2s, 0xa00d38a8-0xa00d3c40, 920 bytes), flags -mcpu=v8 -Os -g.
 * void (void). Reads three values for the source selected by DAT_a8078c37 into the structure
 * DAT_a807d548 (word +4 = 2-bit value, halfwords +0x1c and +0x20 = 16-bit values from a low and a high
 * byte register):
 * - 0 / 1: func_0xa0fb657c(0 / 1, reg) with registers 0x1b4, 0x1c6 + 0x1c7, 0x1ca + 0x1cb;
 * - 2 / 3: func_0xa0fb69b4(0 / 1, reg) with registers 0x504, 0x516 + 0x517, 0x51a + 0x51b;
 * - 4 / 5: indirect reads through func_0xa0fb6c00(0 / 1, 0x73, index) and func_0xa0fb6bb8(0 / 1, 0x74)
 *   with indexes 6, 0x18 + 0x19, 0x1c + 0x1d (each low byte is stored first, then the high byte is added);
 * - other values: nothing.
 * Then halfword +0x1c is limited to 10000.
 * Source forms: an if/else chain on DAT_a8078c37 (no jump table); the low byte of the register pairs is
 * held in an unsigned int local.
 */
struct rec_d548 {
    unsigned int w0;
    unsigned int w4;
    unsigned char _8[0x14];
    unsigned short h1c;
    unsigned char _1e[2];
    unsigned short h20;
};
extern struct rec_d548 DAT_a807d548;
extern unsigned char DAT_a8078c37;
extern unsigned char func_0xa0fb657c(unsigned char, unsigned short);
extern unsigned char func_0xa0fb69b4(unsigned char, unsigned short);
extern void func_0xa0fb6c00(unsigned char, unsigned short, unsigned char);
extern unsigned char func_0xa0fb6bb8(unsigned char, unsigned short);

void FUN_a00d38a8(void)
{
    unsigned int lo;

    if (DAT_a8078c37 == 0) {
        DAT_a807d548.w4 = func_0xa0fb657c(0, 0x1b4) & 3;
        lo = func_0xa0fb657c(0, 0x1c6);
        DAT_a807d548.h1c = (func_0xa0fb657c(0, 0x1c7) << 8) + lo;
        lo = func_0xa0fb657c(0, 0x1ca);
        DAT_a807d548.h20 = (func_0xa0fb657c(0, 0x1cb) << 8) + lo;
    } else if (DAT_a8078c37 == 1) {
        DAT_a807d548.w4 = func_0xa0fb657c(1, 0x1b4) & 3;
        lo = func_0xa0fb657c(1, 0x1c6);
        DAT_a807d548.h1c = (func_0xa0fb657c(1, 0x1c7) << 8) + lo;
        lo = func_0xa0fb657c(1, 0x1ca);
        DAT_a807d548.h20 = (func_0xa0fb657c(1, 0x1cb) << 8) + lo;
    } else if (DAT_a8078c37 == 2) {
        DAT_a807d548.w4 = func_0xa0fb69b4(0, 0x504) & 3;
        lo = func_0xa0fb69b4(0, 0x516);
        DAT_a807d548.h1c = (func_0xa0fb69b4(0, 0x517) << 8) + lo;
        lo = func_0xa0fb69b4(0, 0x51a);
        DAT_a807d548.h20 = (func_0xa0fb69b4(0, 0x51b) << 8) + lo;
    } else if (DAT_a8078c37 == 3) {
        DAT_a807d548.w4 = func_0xa0fb69b4(1, 0x504) & 3;
        lo = func_0xa0fb69b4(1, 0x516);
        DAT_a807d548.h1c = (func_0xa0fb69b4(1, 0x517) << 8) + lo;
        lo = func_0xa0fb69b4(1, 0x51a);
        DAT_a807d548.h20 = (func_0xa0fb69b4(1, 0x51b) << 8) + lo;
    } else if (DAT_a8078c37 == 4) {
        func_0xa0fb6c00(0, 0x73, 6);
        DAT_a807d548.w4 = func_0xa0fb6bb8(0, 0x74) & 3;
        func_0xa0fb6c00(0, 0x73, 0x18);
        DAT_a807d548.h1c = func_0xa0fb6bb8(0, 0x74);
        func_0xa0fb6c00(0, 0x73, 0x19);
        DAT_a807d548.h1c = (func_0xa0fb6bb8(0, 0x74) << 8) + DAT_a807d548.h1c;
        func_0xa0fb6c00(0, 0x73, 0x1c);
        DAT_a807d548.h20 = func_0xa0fb6bb8(0, 0x74);
        func_0xa0fb6c00(0, 0x73, 0x1d);
        DAT_a807d548.h20 = (func_0xa0fb6bb8(0, 0x74) << 8) + DAT_a807d548.h20;
    } else if (DAT_a8078c37 == 5) {
        func_0xa0fb6c00(1, 0x73, 6);
        DAT_a807d548.w4 = func_0xa0fb6bb8(1, 0x74) & 3;
        func_0xa0fb6c00(1, 0x73, 0x18);
        DAT_a807d548.h1c = func_0xa0fb6bb8(1, 0x74);
        func_0xa0fb6c00(1, 0x73, 0x19);
        DAT_a807d548.h1c = (func_0xa0fb6bb8(1, 0x74) << 8) + DAT_a807d548.h1c;
        func_0xa0fb6c00(1, 0x73, 0x1c);
        DAT_a807d548.h20 = func_0xa0fb6bb8(1, 0x74);
        func_0xa0fb6c00(1, 0x73, 0x1d);
        DAT_a807d548.h20 = (func_0xa0fb6bb8(1, 0x74) << 8) + DAT_a807d548.h20;
    }
    if (DAT_a807d548.h1c > 10000)
        DAT_a807d548.h1c = 10000;
}
