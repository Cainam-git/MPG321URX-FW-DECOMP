/* leon2m FUN_a002e46c @ 0xa002e46c-0xa002e658 (123 words).
 * Returns an address for index k (jump table at 0xa002e408): k 0..0x12 give word 0xa802c990 plus 0, 0x40000,
 * 0xc0000, 0x140000, 0x180000, 0x1c0000, 0x200000, 0x220000, 0x240000, 0x260000, 0x280000, 0x290000, 0x2a0000,
 * 0x2b0000, 0x2d0000, 0x2f0000, 0x300000, 0x2d0000 and 0x2c0000; k 0x13 and 0x14 give words 0xa802c994 and
 * 0xa802c998; k 0x15..0x18 return func_0x00093164(0xcf011880, 0xcf0118b0, 0xcf0118e0 or 0xcf011910); other k give 0.
 */
extern unsigned int DAT_a802c990, DAT_a802c994, DAT_a802c998;
extern unsigned int func_0x00093164(unsigned int);

unsigned int FUN_a002e46c(unsigned char k)
{
    unsigned int r = 0;

    switch (k) {
    case 0:
        r = DAT_a802c990;
        break;
    case 0x1:
        r = DAT_a802c990 + 0x40000;
        break;
    case 0x2:
        r = DAT_a802c990 + 0xc0000;
        break;
    case 0x3:
        r = DAT_a802c990 + 0x140000;
        break;
    case 0x4:
        r = DAT_a802c990 + 0x180000;
        break;
    case 0x5:
        r = DAT_a802c990 + 0x1c0000;
        break;
    case 0x6:
        r = DAT_a802c990 + 0x200000;
        break;
    case 0x7:
        r = DAT_a802c990 + 0x220000;
        break;
    case 0x8:
        r = DAT_a802c990 + 0x240000;
        break;
    case 0x9:
        r = DAT_a802c990 + 0x260000;
        break;
    case 0xa:
        r = DAT_a802c990 + 0x280000;
        break;
    case 0xb:
        r = DAT_a802c990 + 0x290000;
        break;
    case 0xc:
        r = DAT_a802c990 + 0x2a0000;
        break;
    case 0xd:
        r = DAT_a802c990 + 0x2b0000;
        break;
    case 0x12:
        r = DAT_a802c990 + 0x2c0000;
        break;
    case 0xe:
    case 0x11:
        r = DAT_a802c990 + 0x2d0000;
        break;
    case 0xf:
        r = DAT_a802c990 + 0x2f0000;
        break;
    case 0x10:
        r = DAT_a802c990 + 0x300000;
        break;
    case 0x13:
        r = DAT_a802c994;
        break;
    case 0x14:
        r = DAT_a802c998;
        break;
    case 0x15:
        r = func_0x00093164(0xcf011880);
        break;
    case 0x16:
        r = func_0x00093164(0xcf0118b0);
        break;
    case 0x17:
        r = func_0x00093164(0xcf0118e0);
        break;
    case 0x18:
        r = func_0x00093164(0xcf011910);
        break;
    }
    return r;
}
