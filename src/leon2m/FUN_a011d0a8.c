/* FUN_a011d0a8: copies 8 bytes from 0x9f1b0600 into a zeroed local buffer (u8-counter byte loop, the static
 * helper also used by FUN_a011cf88) and maps the 16-bit value bytes[4] * 0x100 + bytes[5] to a code:
 * 0x500 -> 1, 0x501 -> 2, 0x502 -> 3, 0x504 -> 4, 0x550 -> 5, 0x551 -> 6, 0x552 -> 7, anything else -> 0.
 * The result is returned masked with 7. Caller: FUN_a0154580.
 */
static void rd8(unsigned char *d, const unsigned char *s, unsigned char n)
{
    unsigned char i;
    for (i = 0; i < n; i++)
        d[i] = s[i];
}

unsigned char FUN_a011d0a8(void)
{
    unsigned char buf[8] = {0};
    unsigned char r;

    rd8(buf, (const unsigned char *)0x9f1b0600, 8);
    switch ((unsigned short)(buf[4] * 0x100 + buf[5])) {
    case 0x500: r = 1; break;
    case 0x501: r = 2; break;
    case 0x502: r = 3; break;
    case 0x504: r = 4; break;
    case 0x550: r = 5; break;
    case 0x551: r = 6; break;
    case 0x552: r = 7; break;
    default: r = 0; break;
    }
    return r & 7;
}
