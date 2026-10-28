/* leon2m FUN_a014f3d8 @ 0xa014f3d8-0xa014f620 (146 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * When no four-bit field of the halfword DAT_a802cc80 equals c: if FUN_a014eb14() (the first free field 1 or 3,
 * printed with s_001a7328; 4 when none) returns more than 3, the body of FUN_a014f208 clears every field of
 * DAT_a802cc80 whose value is none of the 9 bytes DAT_a802a480[0..8] and removes that value from the fields of
 * DAT_a802cc82; then FUN_a014ebf8(c). Finally FUN_a013863c(c, p2, index of the field equal to c (4 when none), 1).
 * Source form: FUN_a014eb14 and FUN_a014f208 are the matched same-file functions, defined here and inlined by GCC
 * (FUN_a014f208 with its two static helpers, the first one renamed match9 here because this file also has the
 * field-index helper find of FUN_a014ebf8); flags as FUN_a014f208 (-msoft-float).
 */
extern unsigned short DAT_a802cc80;
extern unsigned short DAT_a802cc82;
extern unsigned char DAT_a802a480[9];
extern char s_001a7328[];
extern int FUN_a00df170();
extern void FUN_a014ebf8(unsigned char c);
extern void FUN_a013863c(unsigned char, unsigned char, unsigned char, unsigned char);

static unsigned char find(unsigned char c)
{
    unsigned char i;

    for (i = 0; i < 4; i++)
        if (((DAT_a802cc80 >> (i * 4)) & 0xf) == c)
            break;
    return i;
}

static unsigned short match9(unsigned char n)
{
    unsigned char j, d;
    unsigned short mask = 0;

    for (j = 0; j < 9; j++) {
        d = DAT_a802a480[j];
        if (n == d)
            mask |= 1 << j;
    }
    return mask;
}

static void drop(unsigned char n)
{
    unsigned char k;

    for (k = 0; k < 4; k++) {
        if (((DAT_a802cc82 >> (k * 4)) & 0xf) == n) {
            DAT_a802cc82 = ((int)((unsigned int)DAT_a802cc82 << (16 - k * 4)) >> (16 - k * 4)) |
                           ((DAT_a802cc82 >> (k * 4 + 4)) << (k * 4));
            break;
        }
    }
}

void FUN_a014f208(void)
{
    unsigned char i;
    unsigned char n;

    for (i = 0; i < 4; i++) {
        n = (DAT_a802cc80 >> (i * 4)) & 0xf;
        if (match9(n) == 0) {
            DAT_a802cc80 &= ~(0xf << (i * 4));
            drop(n);
        }
    }
}

unsigned char FUN_a014eb14(void)
{
    unsigned char tab[2] = {1, 3};
    unsigned char i, r = 4;

    for (i = 0; i < 2; i++)
        if (((DAT_a802cc80 >> (tab[i] * 4)) & 0xf) == 0)
            break;
    if (i < 2)
        r = tab[i];
    FUN_a00df170(s_001a7328, r);
    return r;
}

void FUN_a014f3d8(unsigned char c, unsigned char p2)
{
    if (find(c) >= 4) {
        if (FUN_a014eb14() > 3)
            FUN_a014f208();
        FUN_a014ebf8(c);
    }
    FUN_a013863c(c, p2, find(c), 1);
}
