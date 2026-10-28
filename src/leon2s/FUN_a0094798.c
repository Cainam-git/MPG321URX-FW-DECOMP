/* FUN_a0094798 (leon2s 0xa0094798-0xa009498c, 500 bytes), flags -mcpu=v8 -Os -g.
 * Prints byte 1 of the 0x1c-byte record ARR_a807d580[port] ("HDMITX_LINK_Source_Selection"), then picks a 4-bit
 * code r from it: 0x11..0x13 and 0x21: port + 2; 0x91: 0xa; 0x31/0x41/0x51/0x61: 4/5/6/7 when bit 30 of the
 * record's first word is set; 0xc1: 0xb; others 0. r becomes 0xe when bit 1 of that word is set and r is 0, and
 * 0xc when bit 3 is set. The code goes into the high nibble (port != 0) or the low nibble (port 0) of register
 * 0xcf011634.
 * Source form: the cases 0x71, 0x81, 0xe1 and 0xf1 are listed with the default result 0 (they keep the
 * firmware's compare tree, rooted at 0x61); the 0x91 case follows the port + 2 group; the byte is read through
 * a byte pointer to the record after the three bit-field reads.
 */
struct Rec1c {
    unsigned int w0_31 : 1, w0_30 : 1, : 26, w0_3 : 1, : 1, w0_1 : 1, : 1;
    unsigned int w[6];
};
extern struct Rec1c ARR_a807d580[];
extern int FUN_a0073044(const char *, ...);
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a0094798(unsigned int port)
{
    unsigned char p = port;
    unsigned char *rb = (unsigned char *)&ARR_a807d580[p];
    unsigned char b30 = ARR_a807d580[p].w0_30;
    unsigned char b3 = ARR_a807d580[p].w0_3;
    unsigned char b1 = ARR_a807d580[p].w0_1;
    unsigned char vic = rb[1];
    unsigned char r = 0;

    FUN_a0073044("\x1b[0m\t\t - HDMITX_LINK_Source_Selection : 0x%x\r\n", vic);
    switch (vic) {
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x21:
        r = port + 2;
        break;
    case 0x91:
        r = 0xa;
        break;
    case 0x31:
        if (b30)
            r = 4;
        break;
    case 0x41:
        if (b30)
            r = 5;
        break;
    case 0x51:
        if (b30)
            r = 6;
        break;
    case 0x61:
        if (b30)
            r = 7;
        break;
    case 0x71:
    case 0x81:
        r = 0;
        break;
    case 0xc1:
        r = 0xb;
        break;
    case 0xe1:
        r = 0;
        break;
    case 0xf1:
        r = 0;
        break;
    }
    if (b1 && r == 0)
        r = 0xe;
    if (b3)
        r = 0xc;
    if (p)
        R(0xcf011634) = (R(0xcf011634) & 0xf) | (r << 4);
    else
        R(0xcf011634) = (R(0xcf011634) & 0xf0) | r;
}
