/*
 * FUN_a00acc54 (leon2s, 0xa00acc54-0xa00aceec, 664 bytes), flags -mcpu=v8 -Os -g.
 * unsigned short (u8 port). Reads two 24-bit values from the port registers with FUN_a00a6bb8(port, reg):
 * a = 0x82:0x83:0x84, d = 0x85:0x86:0x87 (high byte first). With bit 5 of register 3 set, a is stored to
 * DAT_a8079320[port]. Otherwise, with s = DAT_a8079320[port], a is replaced by s when it lies just past a
 * byte or halfword wrap of s (a > s with low bits 2..7 of a all set and a - s - 0xf9 < 11; a < s with them
 * clear and s - a - 0xf9 < 11; the same for bits 10..15 with 0xf801 and 0xbff), else stored to
 * DAT_a8079320[port]. d == 0 becomes 1. v = a * 0x10e, 0x21c, 0x32a or 0xa2 for bits 0..1 of register 0x80
 * = 1, 2, 3 or 0; the result r = v / d is shifted left by 3 when bit 4 of register 0xd7 is set, else by
 * 2 when bit 2 of 0xd7 is set, else by 1 when bit 5 of register 0xd5 is set, and returned as 16 bits.
 * Source form: the bytes are accumulated with '<<= 8; |= byte' statements; one complete formula 'd = a * k / d'
 * per case, as in FUN_a00aceec; case 0 and the default both use 0xa2: the compare tree at 0xa00ace48 has root 1
 * (a case 0 node, 'ble' to the 0xa2 block at 0xa00ace74) and the case 3 test at 0xa00ace68 falls into the same
 * default block; the explicit case equal to the default is also written in FUN_a00acb94.
 */
extern unsigned int DAT_a8079320[];
extern unsigned char FUN_a00a6bb8(unsigned int, unsigned short);

unsigned short FUN_a00acc54(unsigned char port)
{
    unsigned int a;
    unsigned int d;

    a = FUN_a00a6bb8(port, 0x82);
    a <<= 8;
    a |= FUN_a00a6bb8(port, 0x83);
    a <<= 8;
    a |= FUN_a00a6bb8(port, 0x84);
    d = FUN_a00a6bb8(port, 0x85);
    d <<= 8;
    d |= FUN_a00a6bb8(port, 0x86);
    d <<= 8;
    d |= FUN_a00a6bb8(port, 0x87);
    if (FUN_a00a6bb8(port, 3) & 0x20)
        DAT_a8079320[port] = a;
    else if ((a > DAT_a8079320[port] && (a & 0xfc) == 0xfc && a - DAT_a8079320[port] - 0xf9 < 0xb)
             || (a < DAT_a8079320[port] && (a & 0xfc) == 0 && DAT_a8079320[port] - a - 0xf9 < 0xb)
             || (a > DAT_a8079320[port] && (a & 0xfc00) == 0xfc00 && a - DAT_a8079320[port] - 0xf801 < 0xbff)
             || (a < DAT_a8079320[port] && (a & 0xfc00) == 0 && DAT_a8079320[port] - a - 0xf801 < 0xbff))
        a = DAT_a8079320[port];
    else
        DAT_a8079320[port] = a;
    if (d == 0)
        d = 1;
    switch (FUN_a00a6bb8(port, 0x80) & 3) {
    case 0:
        d = a * 0xa2 / d;
        break;
    case 1:
        d = a * 0x10e / d;
        break;
    case 2:
        d = a * 0x21c / d;
        break;
    case 3:
        d = a * 0x32a / d;
        break;
    default:
        d = a * 0xa2 / d;
        break;
    }
    if (FUN_a00a6bb8(port, 0xd7) & 0x10)
        d <<= 3;
    else if (FUN_a00a6bb8(port, 0xd7) & 4)
        d <<= 2;
    else if (FUN_a00a6bb8(port, 0xd5) & 0x20)
        d *= 2;
    return d;
}
