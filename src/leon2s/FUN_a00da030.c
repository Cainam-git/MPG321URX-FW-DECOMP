/* FUN_a00da030 (leon2s 0xa00da030-0xa00da288, 600 bytes), flags -mcpu=v8 -Os -g.
 * void (u8 cnt). s = DAT_a8078832. Copies 0x30 bytes from the 0x200-byte ring DAT_a8079f98[s], starting at the
 * halfword DAT_a807880a[s] (index & 0x1ff), into the stack buffer buf. n = (byte DAT_a8078800[s] * 11 of the
 * 0xb0-byte row DAT_a807a398[s] >> 4) - 1, f = DAT_a8079c62[s][DAT_a8078800[s]], k = n / 2 plus 1 when n is
 * odd, len = cnt limited to DAT_a8078868. With R = DAT_a807609c[DAT_a8078832] (volatile word pointers):
 * f == 0 writes buf[0..len-1] to R[k + 3 ..] and FUN_a00d9988(buf, len, 0, 0x30) to R[k + len + 3];
 * otherwise the same at R[k + 0x33 ..]. Finally DAT_a807880a[DAT_a8078832] advances by len (& 0x1ff).
 * Source form: the row byte is read as '*(DAT_a807a398[s] + idx * 11)'; the FUN_a00d9988 result goes through
 * the unsigned char sum before the store.
 */
extern unsigned char DAT_a8078832;
extern unsigned char DAT_a8078868;
extern unsigned char DAT_a8078800[];
extern unsigned short DAT_a807880a[];
extern unsigned char DAT_a8079f98[][0x200];
extern unsigned char DAT_a807a398[][0xb0];
extern unsigned char DAT_a8079c62[][0x10];
extern volatile unsigned int *DAT_a807609c[];
extern unsigned char FUN_a00d9988(unsigned char *, int, int, int);

void FUN_a00da030(unsigned char cnt)
{
    unsigned char buf[0x30];
    unsigned char s;
    unsigned short rd;
    unsigned char i;
    int n;
    unsigned char k;
    unsigned char len;
    unsigned char f;
    unsigned char sum;

    s = DAT_a8078832;
    rd = DAT_a807880a[s];
    for (i = 0; i < 0x30; i++)
        buf[i] = DAT_a8079f98[s][(rd + i) & 0x1ff];
    n = (*(DAT_a807a398[s] + DAT_a8078800[s] * 11) >> 4) - 1;
    f = DAT_a8079c62[s][DAT_a8078800[s]];
    k = n / 2;
    if (n & 1)
        k++;
    if (cnt > DAT_a8078868)
        len = DAT_a8078868;
    else
        len = cnt;
    if (f == 0) {
        for (i = 0; i < len; i++)
            DAT_a807609c[DAT_a8078832][k + i + 3] = buf[i];
        sum = FUN_a00d9988(buf, len, 0, 0x30);
        DAT_a807609c[DAT_a8078832][k + len + 3] = sum;
    } else {
        for (i = 0; i < len; i++)
            DAT_a807609c[DAT_a8078832][k + i + 0x33] = buf[i];
        sum = FUN_a00d9988(buf, len, 0, 0x30);
        DAT_a807609c[DAT_a8078832][k + len + 0x33] = sum;
    }
    DAT_a807880a[DAT_a8078832] = (DAT_a807880a[DAT_a8078832] + len) & 0x1ff;
}
