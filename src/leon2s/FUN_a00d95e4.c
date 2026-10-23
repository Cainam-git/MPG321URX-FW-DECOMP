/* FUN_a00d95e4 (leon2s 0xa00d95e4-0xa00d9698, 180 bytes), flags -mcpu=v8 -Os -g.
 * Selects table tab = ARR_a807963d[DAT_a8078832] (16 records of 0x30 bytes per DAT_a8078832 value) and record
 * idx = DAT_a8078828[DAT_a8078832] & 0xf. From record byte 0: hi = bits 4..7, lo = bits 0..3; n = hi - 1 (int),
 * k = n / 2, plus 1 when n is odd; bit = bit 4 of record byte k + 2. When hi > lo, record byte k + 3 is copied
 * to ARR_a8079c3d[lo * 2 + bit]. Returns record byte k + 3.
 * Source form: byte 0 is read as tab[idx][0]; the record pointer p = tab[idx] is taken after k (taking it
 * before the byte 0 read, or indexing tab[idx][k + 2] directly, changes the add operands and registers).
 */
extern unsigned char DAT_a8078832;
extern unsigned char DAT_a8078828[];
extern unsigned char ARR_a807963d[][16][0x30];
extern unsigned char ARR_a8079c3d[];

unsigned char FUN_a00d95e4(void)
{
    unsigned char port = DAT_a8078832;
    unsigned char idx = DAT_a8078828[port] & 0xf;
    unsigned char (*tab)[0x30] = ARR_a807963d[port];
    unsigned char b = tab[idx][0];
    unsigned char hi = (b & 0xf0) >> 4;
    unsigned char lo = b & 0xf;
    int n = hi - 1;
    unsigned char k = n / 2;
    unsigned char bit;
    unsigned char *p;

    if (n & 1)
        k++;
    p = tab[idx];
    bit = (p[k + 2] & 0x10) >> 4;
    if (hi > lo)
        ARR_a8079c3d[lo * 2 + bit] = p[k + 3];
    return p[k + 3];
}
