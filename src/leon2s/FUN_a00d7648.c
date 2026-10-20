/* FUN_a00d7648 (leon2s 0xa00d7648-0xa00d76ac, 100 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Copies a descriptor: dst[0] = low 7 bits of src byte 0, dst[1] = high nibble of src byte 1, dst[2..17] =
 * src bytes 2..17, dst[18] = low 7 bits of src byte 0x12. The source header is read through bit-fields
 * (big-endian: the first field is the most significant bit).
 * Compiler aid: 'j++; j--;' after the loop emits no instructions; it makes GCC keep the running index in its
 * own register copy, as the firmware does.
 */
struct hdr {
    unsigned char a : 1;
    unsigned char b : 7;
    unsigned char c : 4;
    unsigned char d : 4;
};

void FUN_a00d7648(struct hdr *src, unsigned char *dst)
{
    unsigned char i;
    unsigned char j;
    unsigned char *s = (unsigned char *)src;

    dst[0] = src->b;
    dst[1] = src->c << 4;
    j = 2;
    for (i = 0; i < 16; i++)
        dst[j++] = s[i + 2];
    j++;
    j--;
    dst[j] = s[0x12] & 0x7f;
}
