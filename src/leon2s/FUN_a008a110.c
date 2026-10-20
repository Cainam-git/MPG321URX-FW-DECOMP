/* FUN_a008a110 (leon2s 0xa008a110-0xa008a1b4, 164 bytes), flags -mcpu=v8 -Os -g.
 * For sel 0xc and 0xe: calls FUN_a00a71fc(port, 3, 0x40, en << 6). When en is non-zero, sel 0xc then clears
 * and sel 0xe sets bit port + 4 of hardware register 0xcf014770. Other sel values do nothing.
 * Source form: a switch on sel (an if/else chain masks port separately in each arm).
 */
#define REG_4770 (*(volatile unsigned int *)0xcf014770)

extern void FUN_a00a71fc(unsigned char, unsigned short, unsigned char, unsigned char);

void FUN_a008a110(unsigned char sel, unsigned char port, unsigned char en)
{
    switch (sel) {
    case 0xc:
        FUN_a00a71fc(port, 3, 0x40, en << 6);
        if (en)
            REG_4770 &= ~(1 << (port + 4));
        break;
    case 0xe:
        FUN_a00a71fc(port, 3, 0x40, en << 6);
        if (en)
            REG_4770 |= 1 << (port + 4);
        break;
    }
}
