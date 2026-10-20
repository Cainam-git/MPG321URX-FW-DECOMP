/* FUN_a00d76f4 (leon2s, 0xa00d76f4-0xa00d7734, 64 bytes, 16 words, leaf).
 * Flags: -mcpu=v8 -Os -g.
 * Packs three u16 words of param_1 into five bytes of param_2: [0] = (w0 >> 8) & 0x7f, [1] = w0 & 0xf0
 * (bits 4..7 kept in place), [2] = w1 >> 9, [3] = w2 >> 8, [4] = low byte of w2; each word is re-read with
 * lduh.
 * Source form: byte 1 is written as the nibble moved back into place '((w0 >> 4 & 0xf) << 4)'; the plain
 * mask '(u8)(w0 & 0xf0)' gives 'and %g1,-16' (QImode constant), the firmware has 'and 0xf0'.
 */
void FUN_a00d76f4(unsigned short *param_1, unsigned char *param_2)
{
    unsigned int tmp;
    tmp = param_1[0];
    param_2[0] = (unsigned char)((tmp >> 8) & 0x7f);
    tmp = param_1[0];
    param_2[1] = (unsigned char)((tmp >> 4 & 0xf) << 4);
    tmp = param_1[1];
    param_2[2] = (unsigned char)(tmp >> 9);
    tmp = param_1[2];
    param_2[3] = (unsigned char)(tmp >> 8);
    tmp = param_1[2];
    param_2[4] = (unsigned char)tmp;
}
