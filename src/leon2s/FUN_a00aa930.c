/* FUN_a00aa930 (leon2s 0xa00aa930-0xa00aaf90, 1632 bytes), flags -mcpu=v8 -Os -g.
 * Register set-up by mode for one hardware bank (FUN_a00a7acc reads a register byte, FUN_a00a7b64 writes one,
 * FUN_a00a7bf8 (bank, reg, mask, on) sets or clears mask bits). Called from FUN_a00883d0. A switch on mode 0..10
 * (jump table at 0xa00aa904, mode 7 and modes above 10 take the default arm):
 * - modes 0, 1, 2, 4, 5, 6 and default: bank 0: register 9 = (old value & 8) | v9, register 10 = v10; other
 *   banks: bit 0x80 of register 9 set (modes 0, 1, 2, 6) or cleared (4, 5, default) through FUN_a00a7bf8,
 *   then bank 1 register 0x63 = (old value of the bank's register 0x63 & 0x8f) | v63 (mode 5 and default
 *   write it to the bank itself). (v9, v10, v63): mode 0 (0x91, 0x11, 0x10), 1 (0xa2, 0x22, 0x20),
 *   2 (0xe6, 0x66, 0x60), 4 (0x44, 0x44, 0x40), 5 (0x33, 0x33, 0x30), 6 (0xd5, 0x55, 0x50), default (0x80, 0, 0).
 * - before that, modes 3, 9, 10 write the index/value pairs 0x2c/0x2d (0xa = 0xfc, 0xb = 0, 0xc = 2, 1, 0),
 *   mode 6 writes 0x2c = 0xe, 0x2d = 0, mode 8 writes ten pairs (index 0..9) and 0xe = 1.
 * - modes 3, 8, 9, 10: bank 0: register 9 = (old value & 8) | 0x77 (0xd5 in mode 8), register 10 = 0x77
 *   (0x55); other banks: bank 1 register 0x64 = 7, register 9 = 0x77 (mode 8: bit 0x80 set through
 *   FUN_a00a7bf8), bank 1 register 0x63 = 0xf5 (0xd5 in mode 8).
 * - mode 0 ends with FUN_a00aa88c(bank, 1), the default arm starts with FUN_a00aa88c(bank, 0).
 * Source form: the cases are written in the order 0, 1, 2, 4, 5, 6, 8, 9, 10, 3, default; the FUN_a00aa88c
 * calls are written inside both arms of the bank test (one shared call after the if changes the argument
 * order of the FUN_a00a7bf8 call in mode 0).
 */
extern unsigned char FUN_a00a7acc(unsigned char, short);
extern void FUN_a00a7b64(unsigned char, short, unsigned char);
extern void FUN_a00a7bf8(unsigned char, short, unsigned char, unsigned char);
extern void FUN_a00aa88c(unsigned int, unsigned int);

void FUN_a00aa930(unsigned char bank, unsigned char mode)
{
    switch (mode) {
    case 0:
        if (bank == 0) {
            FUN_a00a7b64(0, 9, (FUN_a00a7acc(0, 9) & 8) | 0x91);
            FUN_a00a7b64(0, 10, 0x11);
            FUN_a00aa88c(0, 1);
        } else {
            FUN_a00a7bf8(bank, 9, 0x80, 1);
            FUN_a00a7b64(1, 0x63, (FUN_a00a7acc(bank, 0x63) & 0x8f) | 0x10);
            FUN_a00aa88c(bank, 1);
        }
        break;
    case 1:
        if (bank == 0) {
            FUN_a00a7b64(0, 9, (FUN_a00a7acc(0, 9) & 8) | 0xa2);
            FUN_a00a7b64(0, 10, 0x22);
        } else {
            FUN_a00a7bf8(bank, 9, 0x80, 1);
            FUN_a00a7b64(1, 0x63, (FUN_a00a7acc(bank, 0x63) & 0x8f) | 0x20);
        }
        break;
    case 2:
        if (bank == 0) {
            FUN_a00a7b64(0, 9, (FUN_a00a7acc(0, 9) & 8) | 0xe6);
            FUN_a00a7b64(0, 10, 0x66);
        } else {
            FUN_a00a7bf8(bank, 9, 0x80, 1);
            FUN_a00a7b64(1, 0x63, (FUN_a00a7acc(bank, 0x63) & 0x8f) | 0x60);
        }
        break;
    case 4:
        if (bank == 0) {
            FUN_a00a7b64(0, 9, (FUN_a00a7acc(0, 9) & 8) | 0x44);
            FUN_a00a7b64(0, 10, 0x44);
        } else {
            FUN_a00a7bf8(bank, 9, 0x80, 0);
            FUN_a00a7b64(1, 0x63, (FUN_a00a7acc(bank, 0x63) & 0x8f) | 0x40);
        }
        break;
    case 5:
        if (bank == 0) {
            FUN_a00a7b64(0, 9, (FUN_a00a7acc(0, 9) & 8) | 0x33);
            FUN_a00a7b64(0, 10, 0x33);
        } else {
            FUN_a00a7bf8(bank, 9, 0x80, 0);
            FUN_a00a7b64(bank, 0x63, (FUN_a00a7acc(bank, 0x63) & 0x8f) | 0x30);
        }
        break;
    case 6:
        FUN_a00a7b64(bank, 0x2c, 0xe);
        FUN_a00a7b64(bank, 0x2d, 0x0);
        if (bank == 0) {
            FUN_a00a7b64(0, 9, (FUN_a00a7acc(0, 9) & 8) | 0xd5);
            FUN_a00a7b64(0, 10, 0x55);
        } else {
            FUN_a00a7bf8(bank, 9, 0x80, 1);
            FUN_a00a7b64(1, 0x63, (FUN_a00a7acc(bank, 0x63) & 0x8f) | 0x50);
        }
        break;
    case 8:
        FUN_a00a7b64(bank, 0x2c, 0x0);
        FUN_a00a7b64(bank, 0x2d, 0x1f);
        FUN_a00a7b64(bank, 0x2c, 0x1);
        FUN_a00a7b64(bank, 0x2d, 0x7c);
        FUN_a00a7b64(bank, 0x2c, 0x2);
        FUN_a00a7b64(bank, 0x2d, 0xf0);
        FUN_a00a7b64(bank, 0x2c, 0x3);
        FUN_a00a7b64(bank, 0x2d, 0xc1);
        FUN_a00a7b64(bank, 0x2c, 0x4);
        FUN_a00a7b64(bank, 0x2d, 0x7);
        FUN_a00a7b64(bank, 0x2c, 0x5);
        FUN_a00a7b64(bank, 0x2d, 0x1f);
        FUN_a00a7b64(bank, 0x2c, 0x6);
        FUN_a00a7b64(bank, 0x2d, 0x7c);
        FUN_a00a7b64(bank, 0x2c, 0x7);
        FUN_a00a7b64(bank, 0x2d, 0xf0);
        FUN_a00a7b64(bank, 0x2c, 0x8);
        FUN_a00a7b64(bank, 0x2d, 0xc1);
        FUN_a00a7b64(bank, 0x2c, 0x9);
        FUN_a00a7b64(bank, 0x2d, 0x7);
        FUN_a00a7b64(bank, 0x2c, 0xe);
        FUN_a00a7b64(bank, 0x2d, 0x1);
        if (bank == 0) {
            FUN_a00a7b64(0, 9, (FUN_a00a7acc(0, 9) & 8) | 0xd5);
            FUN_a00a7b64(0, 10, 0x55);
        } else {
            FUN_a00a7b64(1, 0x64, 7);
            FUN_a00a7bf8(bank, 9, 0x80, 1);
            FUN_a00a7b64(1, 0x63, 0xd5);
        }
        break;
    case 9:
        FUN_a00a7b64(bank, 0x2c, 0xa);
        FUN_a00a7b64(bank, 0x2d, 0xfc);
        FUN_a00a7b64(bank, 0x2c, 0xb);
        FUN_a00a7b64(bank, 0x2d, 0x0);
        FUN_a00a7b64(bank, 0x2c, 0xc);
        FUN_a00a7b64(bank, 0x2d, 0x1);
        if (bank == 0) {
            FUN_a00a7b64(0, 9, (FUN_a00a7acc(0, 9) & 8) | 0x77);
            FUN_a00a7b64(0, 10, 0x77);
        } else {
            FUN_a00a7b64(1, 0x64, 7);
            FUN_a00a7b64(bank, 9, 0x77);
            FUN_a00a7b64(1, 0x63, 0xf5);
        }
        break;
    case 10:
        FUN_a00a7b64(bank, 0x2c, 0xa);
        FUN_a00a7b64(bank, 0x2d, 0xfc);
        FUN_a00a7b64(bank, 0x2c, 0xb);
        FUN_a00a7b64(bank, 0x2d, 0x0);
        FUN_a00a7b64(bank, 0x2c, 0xc);
        FUN_a00a7b64(bank, 0x2d, 0x0);
        if (bank == 0) {
            FUN_a00a7b64(0, 9, (FUN_a00a7acc(0, 9) & 8) | 0x77);
            FUN_a00a7b64(0, 10, 0x77);
        } else {
            FUN_a00a7b64(1, 0x64, 7);
            FUN_a00a7b64(bank, 9, 0x77);
            FUN_a00a7b64(1, 0x63, 0xf5);
        }
        break;
    case 3:
        FUN_a00a7b64(bank, 0x2c, 0xa);
        FUN_a00a7b64(bank, 0x2d, 0xfc);
        FUN_a00a7b64(bank, 0x2c, 0xb);
        FUN_a00a7b64(bank, 0x2d, 0x0);
        FUN_a00a7b64(bank, 0x2c, 0xc);
        FUN_a00a7b64(bank, 0x2d, 0x2);
        if (bank == 0) {
            FUN_a00a7b64(0, 9, (FUN_a00a7acc(0, 9) & 8) | 0x77);
            FUN_a00a7b64(0, 10, 0x77);
        } else {
            FUN_a00a7b64(1, 0x64, 7);
            FUN_a00a7b64(bank, 9, 0x77);
            FUN_a00a7b64(1, 0x63, 0xf5);
        }
        break;
    default:
        if (bank == 0) {
            FUN_a00aa88c(0, 0);
            FUN_a00a7b64(0, 9, (FUN_a00a7acc(0, 9) & 8) | 0x80);
            FUN_a00a7b64(0, 10, 0);
        } else {
            FUN_a00aa88c(bank, 0);
            FUN_a00a7bf8(bank, 9, 0x80, 0);
            FUN_a00a7b64(bank, 0x63, FUN_a00a7acc(bank, 0x63) & 0x8f);
        }
        break;
    }
}
