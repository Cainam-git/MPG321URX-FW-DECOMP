/* leon2m FUN_a00fd594 @ 0xa00fd594-0xa00fd820 (163 words). -mcpu=v8 -O3 -g.
 * (written from the asm; no draft).
 * What it does: GlobalModeHandler main source selection, register set-up of block blk for the source class
 * cls (the port class codes of FUN_a00fd820; caller FUN_a0131518 passes DAT_a802a44c/a44d-related values).
 * Helpers (all per-block 8-bit registers): RMW(blk, reg, mask, set) = FUN_a00f1b5c, WR = FUN_a00f1ad4,
 * RD = FUN_a00f1e0c, WR2 = FUN_a00f1e50.
 *   always first: RMW(5c, 1, 0), RMW(3, 0x30, 0)  (clear bit 0 of reg 0x5c, bits 4..5 of reg 3);
 *   0x11, 0x12, 0x13, 0x21, 0xe8: WR(4, 0x80), RMW(3, 1, 0)      0x31: WR(4, 0x82), RMW(3, 1, 0)
 *   0x41: WR(4, 0x86), RMW(3, 1, 0)      0x51: WR(4, 0x8a), RMW(3, 1, 0)      0x61: WR(4, 0x8e), RMW(3, 1, 0)
 *   0x71: WR(4, 0x83), RMW(3, 1, 0)      0x81: WR(4, 0x83), RMW(3, 1, 1)   (reg 3 bit 0 SET only here)
 *   0x91: WR(4, 0x82), reg 0x40 &= 0xfc, hw 0xcf0115e0 = 0, hw 0xcf0115e4 = 4, RMW(3, 1, 0)
 *   0xa1: WR(4, 0x82), reg 0x40 = (reg 0x40 | 2) & 0xfe, hw 0xcf0115e0 = 0, 0xcf0115e4 = 4, RMW(3, 1, 0)
 *   0xb1: RMW(3, 0x20, 1), reg 0x40 = (reg 0x40 | 1) & 0xfd       0xc1: WR(4, 0x8a), RMW(3, 0x10, 1), RMW(3, 1, 0)
 *   0xe1: RMW(5c, 1, 1), RMW(5c, 8, 1), WR(4, 0x83), RMW(3, 1, 0)
 *   0xe2: RMW(5c, 1, 1), RMW(5c, 8, 0), WR(4, 0x83), RMW(3, 1, 0)       any other cls: nothing more.
 * Nothing here reads the input rate; reg 4 gets the class's fixed code.
 * The switch in natural value order gives the fw compare tree as is (root 0x71: 15 nodes with the 0x11..0x13
 * range made by gcc's group_case_nodes). volatile only on the real hardware registers. Aids: none.
 */
extern void FUN_a00f1b5c(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);
extern void FUN_a00f1ad4(unsigned char blk, unsigned char reg, unsigned char val);
extern unsigned char FUN_a00f1e0c(unsigned char blk, unsigned char reg);
extern void FUN_a00f1e50(unsigned char blk, unsigned char reg, unsigned char val);
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a00fd594(unsigned char blk, unsigned char cls)
{
    FUN_a00f1b5c(blk, 0x5c, 1, 0);
    FUN_a00f1b5c(blk, 3, 0x30, 0);
    switch (cls) {
    case 0x11: case 0x12: case 0x13: case 0x21: case 0xe8:
        FUN_a00f1ad4(blk, 4, 0x80);
        FUN_a00f1b5c(blk, 3, 1, 0);
        break;
    case 0x31:
        FUN_a00f1ad4(blk, 4, 0x82);
        FUN_a00f1b5c(blk, 3, 1, 0);
        break;
    case 0x41:
        FUN_a00f1ad4(blk, 4, 0x86);
        FUN_a00f1b5c(blk, 3, 1, 0);
        break;
    case 0x51:
        FUN_a00f1ad4(blk, 4, 0x8a);
        FUN_a00f1b5c(blk, 3, 1, 0);
        break;
    case 0x61:
        FUN_a00f1ad4(blk, 4, 0x8e);
        FUN_a00f1b5c(blk, 3, 1, 0);
        break;
    case 0x71:
        FUN_a00f1ad4(blk, 4, 0x83);
        FUN_a00f1b5c(blk, 3, 1, 0);
        break;
    case 0x81:
        FUN_a00f1ad4(blk, 4, 0x83);
        FUN_a00f1b5c(blk, 3, 1, 1);
        break;
    case 0x91:
        FUN_a00f1ad4(blk, 4, 0x82);
        FUN_a00f1e50(blk, 0x40, FUN_a00f1e0c(blk, 0x40) & 0xfc);
        R(0xcf0115e0) = 0;
        R(0xcf0115e4) = 4;
        FUN_a00f1b5c(blk, 3, 1, 0);
        break;
    case 0xa1:
        FUN_a00f1ad4(blk, 4, 0x82);
        FUN_a00f1e50(blk, 0x40, (FUN_a00f1e0c(blk, 0x40) | 2) & 0xfe);
        R(0xcf0115e0) = 0;
        R(0xcf0115e4) = 4;
        FUN_a00f1b5c(blk, 3, 1, 0);
        break;
    case 0xb1:
        FUN_a00f1b5c(blk, 3, 0x20, 1);
        FUN_a00f1e50(blk, 0x40, (FUN_a00f1e0c(blk, 0x40) | 1) & 0xfd);
        break;
    case 0xc1:
        FUN_a00f1ad4(blk, 4, 0x8a);
        FUN_a00f1b5c(blk, 3, 0x10, 1);
        FUN_a00f1b5c(blk, 3, 1, 0);
        break;
    case 0xe1:
        FUN_a00f1b5c(blk, 0x5c, 1, 1);
        FUN_a00f1b5c(blk, 0x5c, 8, 1);
        FUN_a00f1ad4(blk, 4, 0x83);
        FUN_a00f1b5c(blk, 3, 1, 0);
        break;
    case 0xe2:
        FUN_a00f1b5c(blk, 0x5c, 1, 1);
        FUN_a00f1b5c(blk, 0x5c, 8, 0);
        FUN_a00f1ad4(blk, 4, 0x83);
        FUN_a00f1b5c(blk, 3, 1, 0);
        break;
    }
}
