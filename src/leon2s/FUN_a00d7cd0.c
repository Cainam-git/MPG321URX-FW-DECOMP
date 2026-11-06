/* FUN_a00d7cd0 (leon2s 0xa00d7cd0-0xa00d7e6c, 412 bytes), flags -mcpu=v8 -Os -g.
 * int (void), only caller FUN_a00d9be4 (which masks the result with 0xff). With s = DAT_a8078832, a = DAT_a8078828[s]
 * and b = DAT_a8078830[s] (ring indices 0..15): cnt = 0x10 - (a - b) when b < a, else b - a. Scans cnt entries of the
 * 16-entry ring of 0x30-byte packets ARR_a807963d[s], entry j = (DAT_a8078828[s] + i) & 0xf for i = 0, 1, ...: with
 * k = (packet byte 0 >> 4) - 1 (int), off = k / 2, plus 1 when k is odd, the flag byte is packet byte off + 2.
 * For i == 0, bit 7 of the flag byte set (signed test) sets first. Bit 6 set: found = 1 unless first, stop. Bit 7 set
 * with i != 0: i is decremented, found = 1, stop. Returns ((DAT_a8078828[s] + i) & 0xf) | 0x40 when found,
 * (DAT_a8078828[s] + i) & 0xf when the scan stopped early without found, 0x80 when all cnt entries were passed.
 * Source form: the packet address is written row + (j * 3 << 4) for byte 0 and the bit-7 test; the second flag byte
 * read goes through the unsigned char row index x = j * 3 and the unsigned short byte offset o = x << 4 into
 * ARR_a807963d[DAT_a8078832] (fw 'sll; and 0x3f0': the zero-extended byte index keeps a mask after the shift);
 * DAT_a8078832 and DAT_a8078828[s] are named directly in the loop (fw reloads them before the loop).
 */
extern unsigned char DAT_a8078832;
extern unsigned char DAT_a8078828[];
extern unsigned char DAT_a8078830[];
extern unsigned char ARR_a807963d[][0x300];

int FUN_a00d7cd0(void)
{
    unsigned char a, b, i, off, v, first, found;
    unsigned char cnt;
    unsigned char *row, *p;
    unsigned int j;
    int k;
    unsigned char x;
    unsigned short o;

    b = DAT_a8078830[DAT_a8078832];
    a = DAT_a8078828[DAT_a8078832];
    found = 0;
    first = 0;
    if (b < a)
        cnt = 0x10 - (a - b);
    else
        cnt = b - a;
    for (i = 0; i < cnt; i++) {
        j = (DAT_a8078828[DAT_a8078832] + i) & 0xf;
        row = ARR_a807963d[DAT_a8078832];
        x = j * 3;
        k = ((row + (j * 3 << 4))[0] >> 4) - 1;
        off = k / 2;
        if (k & 1)
            off++;
        if (i == 0 && (signed char)(row + (j * 3 << 4))[off + 2] < 0)
            first = 1;
        o = x << 4;
        v = ARR_a807963d[DAT_a8078832][o + off + 2];
        if (v & 0x40) {
            if (!first)
                found = 1;
            break;
        }
        if ((v & 0x80) && i != 0) {
            i--;
            found = 1;
            break;
        }
    }
    if (i < cnt) {
        if (found)
            return ((DAT_a8078828[DAT_a8078832] + i) & 0xf) | 0x40;
        return (DAT_a8078828[DAT_a8078832] + i) & 0xf;
    }
    return 0x80;
}
