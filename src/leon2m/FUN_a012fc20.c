/* leon2m FUN_a012fc20 @ 0xa012fc20 (-mcpu=v8 -O3 -g)
 * c = byte 0xA802A44C. c == 0xff returns 0xff. Otherwise P = bits 12..15 of word 0 of the 0x78-byte channel record c at
 * 0xA802DF30, and the function returns byte +0xa of the 0x2A-byte port record P at 0xA802E224 (the port byte that
 * FUN_a0142168 maps to a port-entry index).
 */
extern unsigned char DAT_a802a44c;   // 0xa802a44c
extern unsigned char DAT_a802df30;   // 0xa802df30

unsigned char FUN_a012fc20(void)
{
    unsigned char result;

    unsigned int offset;
    unsigned int value;
    short nibble;
    unsigned char *table;
    
    if (DAT_a802a44c == 0xff) {
        result = 0xff;
    } else {
        value = *(unsigned int *)(&DAT_a802df30 + (DAT_a802a44c * 0x78));
        nibble = (value >> 0xc) & 0xf;
        table = (unsigned char *)0xa802e224;
        result = table[nibble * 0x2a + 0xa];
    }
    return result;
}
