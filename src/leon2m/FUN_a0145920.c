/* leon2m FUN_a0145920 @ 0xa0145920-0xa0145af8 (118 words; the asm header's '44 bytes' label is wrong, its range is
 * right). Getter for the 36 bytes of the RAM block at 0xA802E1F0: id 0..23 returns byte id, ids 24..26 return
 * bytes 0x21..0x23, ids 27..35 return bytes 0x18..0x20; any other id returns 0xff (an int -1 narrowed to the
 * unsigned char result). No direct callers (reached through a pointer).
 */
extern unsigned char DAT_a802e1f0[0x24];

unsigned char FUN_a0145920(unsigned int id)
{
    int r = -1;

    switch (id) {
    case 0:
        r = DAT_a802e1f0[0x00];
        break;
    case 1:
        r = DAT_a802e1f0[0x01];
        break;
    case 2:
        r = DAT_a802e1f0[0x02];
        break;
    case 3:
        r = DAT_a802e1f0[0x03];
        break;
    case 4:
        r = DAT_a802e1f0[0x04];
        break;
    case 5:
        r = DAT_a802e1f0[0x05];
        break;
    case 6:
        r = DAT_a802e1f0[0x06];
        break;
    case 7:
        r = DAT_a802e1f0[0x07];
        break;
    case 8:
        r = DAT_a802e1f0[0x08];
        break;
    case 9:
        r = DAT_a802e1f0[0x09];
        break;
    case 10:
        r = DAT_a802e1f0[0x0a];
        break;
    case 11:
        r = DAT_a802e1f0[0x0b];
        break;
    case 12:
        r = DAT_a802e1f0[0x0c];
        break;
    case 13:
        r = DAT_a802e1f0[0x0d];
        break;
    case 14:
        r = DAT_a802e1f0[0x0e];
        break;
    case 15:
        r = DAT_a802e1f0[0x0f];
        break;
    case 16:
        r = DAT_a802e1f0[0x10];
        break;
    case 17:
        r = DAT_a802e1f0[0x11];
        break;
    case 18:
        r = DAT_a802e1f0[0x12];
        break;
    case 19:
        r = DAT_a802e1f0[0x13];
        break;
    case 20:
        r = DAT_a802e1f0[0x14];
        break;
    case 21:
        r = DAT_a802e1f0[0x15];
        break;
    case 22:
        r = DAT_a802e1f0[0x16];
        break;
    case 23:
        r = DAT_a802e1f0[0x17];
        break;
    case 24:
        r = DAT_a802e1f0[0x21];
        break;
    case 25:
        r = DAT_a802e1f0[0x22];
        break;
    case 26:
        r = DAT_a802e1f0[0x23];
        break;
    case 27:
        r = DAT_a802e1f0[0x18];
        break;
    case 28:
        r = DAT_a802e1f0[0x19];
        break;
    case 29:
        r = DAT_a802e1f0[0x1a];
        break;
    case 30:
        r = DAT_a802e1f0[0x1b];
        break;
    case 31:
        r = DAT_a802e1f0[0x1c];
        break;
    case 32:
        r = DAT_a802e1f0[0x1d];
        break;
    case 33:
        r = DAT_a802e1f0[0x1e];
        break;
    case 34:
        r = DAT_a802e1f0[0x1f];
        break;
    case 35:
        r = DAT_a802e1f0[0x20];
        break;
    }
    return r;
}
