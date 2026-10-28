/* FUN_a00d791c (leon2s 0xa00d791c-0xa00d7bf8, 732 bytes), flags -mcpu=v8 -Os -g.
 * void (p, a, b, type, n), old-style definition with unsigned char a, b, type and unsigned short n.
 * Clears bytes 0..n-1 of the 256-byte stack buffer buf, then a switch on type calls one routine with (p, buf):
 * 0 FUN_a00d74ec, 1 FUN_a00d7638, 0x11 FUN_a00d7648, 2 FUN_a00d76ac, 3 FUN_a00d76f4, 6 FUN_a00d7734,
 * 7 FUN_a00d7744, 8 FUN_a00d77a8, 9 FUN_a00d77c4, 0xa FUN_a00d7828, 0xb FUN_a00d7844, 0xc FUN_a00d7860,
 * 0x38 FUN_a00d787c, 0xf FUN_a00d78d8; r = 1 for type 0x11, otherwise 0.
 * When a == 2 and b == 1, with s = DAT_a8078832: DAT_a807a4f8[s][DAT_a8078808[s]] = n; buf[i] is written to
 * DAT_a8079f98[s][(ARR_a807880e[s] + i) % 512] for i < n; then ARR_a807880e[s] = (ARR_a807880e[s] + n) % 512,
 * c = DAT_a8078808[s], DAT_a8079c62[s][c] = r and DAT_a8078808[s] = (c + 1) % 16.
 * Source form: DAT_a8078832 is named directly as the index in the first store and in the copy loop and read
 * once into idx for the closing updates (this keeps a separate address computation for that read); the
 * DAT_a8079c62 store comes before the DAT_a8078808 update.
 */
extern unsigned char DAT_a8078832;
extern unsigned char DAT_a8078808[];
extern unsigned short ARR_a807880e[];
extern unsigned char DAT_a807a4f8[][16];
extern unsigned char DAT_a8079c62[][16];
extern unsigned char DAT_a8079f98[][0x200];
extern void FUN_a00d74ec(void *, unsigned char *);
extern void FUN_a00d7638(void *, unsigned char *);
extern void FUN_a00d7648(void *, unsigned char *);
extern void FUN_a00d76ac(void *, unsigned char *);
extern void FUN_a00d76f4(void *, unsigned char *);
extern void FUN_a00d7734(void *, unsigned char *);
extern void FUN_a00d7744(void *, unsigned char *);
extern void FUN_a00d77a8(void *, unsigned char *);
extern void FUN_a00d77c4(void *, unsigned char *);
extern void FUN_a00d7828(void *, unsigned char *);
extern void FUN_a00d7844(void *, unsigned char *);
extern void FUN_a00d7860(void *, unsigned char *);
extern void FUN_a00d787c(void *, unsigned char *);
extern void FUN_a00d78d8(void *, unsigned char *);

void FUN_a00d791c(p, a, b, type, n)
    void *p;
    unsigned char a;
    unsigned char b;
    unsigned char type;
    unsigned short n;
{
    unsigned char buf[256];
    unsigned char i;
    unsigned char idx;
    unsigned char r = 0;
    unsigned char c;

    for (i = 0; i < n; i++)
        buf[i] = 0;
    switch (type) {
    case 0:
        FUN_a00d74ec(p, buf);
        r = 0;
        break;
    case 1:
        FUN_a00d7638(p, buf);
        r = 0;
        break;
    case 0x11:
        FUN_a00d7648(p, buf);
        r = 1;
        break;
    case 2:
        FUN_a00d76ac(p, buf);
        r = 0;
        break;
    case 3:
        FUN_a00d76f4(p, buf);
        r = 0;
        break;
    case 6:
        FUN_a00d7734(p, buf);
        r = 0;
        break;
    case 7:
        FUN_a00d7744(p, buf);
        r = 0;
        break;
    case 8:
        FUN_a00d77a8(p, buf);
        r = 0;
        break;
    case 9:
        FUN_a00d77c4(p, buf);
        r = 0;
        break;
    case 0xa:
        FUN_a00d7828(p, buf);
        r = 0;
        break;
    case 0xb:
        FUN_a00d7844(p, buf);
        r = 0;
        break;
    case 0xc:
        FUN_a00d7860(p, buf);
        r = 0;
        break;
    case 0x38:
        FUN_a00d787c(p, buf);
        r = 0;
        break;
    case 0xf:
        FUN_a00d78d8(p, buf);
        r = 0;
        break;
    }
    if (a == 2) {
      if (b == 1) {
        DAT_a807a4f8[DAT_a8078832][DAT_a8078808[DAT_a8078832]] = n;
        for (i = 0; i < n; i++)
            DAT_a8079f98[DAT_a8078832][(ARR_a807880e[DAT_a8078832] + i) % 512] = buf[i];
        idx = DAT_a8078832;
        ARR_a807880e[idx] = (ARR_a807880e[idx] + n) % 512;
        c = DAT_a8078808[idx];
        DAT_a8079c62[idx][c] = r;
        DAT_a8078808[idx] = (c + 1) % 16;
      }
    }
}
