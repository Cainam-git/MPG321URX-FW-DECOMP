/* leon2s FUN_a008fb7c @ 0xa008fb7c-0xa008fdc8, -mcpu=v8 -Os -g.
 * (u8 port), returns u8. Ports other than 0 and 1 return 8; k = port. When bits 0..2 of FUN_a00a657c(port, 0x45)
 * are 4, sets bits 0+4 (port 0) or 1+5 (port 1) of the register 0xcf00f224, else clears bit 0 / 1. When
 * FUN_a008fb5c(port) is 3, sets bit 4 / 5 of 0xcf011640, else clears bits 4 and 0 / 5 and 1. Then by bits 0..2
 * of FUN_a00a657c(port, 0x45): 4 / 5 / 6 / 7 write that value (other values: 4) through FUN_a00a7488(k, 0x1f08,
 * 0xfffffff8, v) and give the result 8 / 10 / 12 / 16 (others 8). Ends with FUN_a00a67b8(port, 0xd9, 2, 0).
 * Source forms: the port tests are switches (as in MODEDET_handler_2); FUN_a00a657c is declared with an int
 * result (signed case compare).
 * Compiler aid: 'k++; k--;' in the port-0 arm of the 0xcf00f224 clear emits no instructions; it keeps combine
 * from knowing that k is 0 or 1, so the 'and 0xff' of the firmware stays on each FUN_a00a7488 argument.
 */
extern int FUN_a00a657c(unsigned char, unsigned short);
extern unsigned char FUN_a008fb5c(unsigned char);
extern void FUN_a00a7488(unsigned int, unsigned short, unsigned int, unsigned int);
extern void FUN_a00a67b8(unsigned char, unsigned short, unsigned char, unsigned char);

#define R224 (*(volatile unsigned int *)0xcf00f224)
#define R640 (*(volatile unsigned int *)0xcf011640)

unsigned char FUN_a008fb7c(unsigned char port)
{
    unsigned char k;
    unsigned char r = 8;

    switch (port) {
    case 0:
        k = 0;
        break;
    case 1:
        k = 1;
        break;
    default:
        return 8;
    }
    if ((FUN_a00a657c(port, 0x45) & 7) == 4) {
        switch (port) {
        case 0:
            R224 |= 0x11;
            break;
        case 1:
            R224 |= 0x22;
            break;
        }
    } else {
        switch (port) {
        case 0:
            R224 &= ~1;
            k++; /* compiler aid, see the header */
            k--;
            break;
        case 1:
            R224 &= ~2;
            break;
        }
    }
    if (FUN_a008fb5c(port) == 3) {
        switch (port) {
        case 0:
            R640 |= 0x10;
            break;
        case 1:
            R640 |= 0x20;
            break;
        }
    } else {
        switch (port) {
        case 0:
            R640 &= ~0x10;
            R640 &= ~1;
            break;
        case 1:
            R640 &= ~0x20;
            R640 &= ~2;
            break;
        }
    }
    switch (FUN_a00a657c(port, 0x45) & 7) {
    case 4:
        FUN_a00a7488(k, 0x1f08, 0xfffffff8, 4);
        r = 8;
        break;
    case 5:
        FUN_a00a7488(k, 0x1f08, 0xfffffff8, 5);
        r = 10;
        break;
    case 6:
        FUN_a00a7488(k, 0x1f08, 0xfffffff8, 6);
        r = 12;
        break;
    case 7:
        FUN_a00a7488(k, 0x1f08, 0xfffffff8, 7);
        r = 16;
        break;
    default:
        FUN_a00a7488(k, 0x1f08, 0xfffffff8, 4);
        break;
    }
    FUN_a00a67b8(port, 0xd9, 2, 0);
    return r;
}
