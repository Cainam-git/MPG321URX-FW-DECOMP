/* FUN_a014ebf8 (leon2m 0xa014ebf8-0xa014f208, 1552 bytes), flags -mcpu=v8 -O3 -g. Called by FUN_a014f3d8.
 * Places the value c into the four-bit fields of the halfword DAT_a802cc80 (field i = bits 4i..4i+3) and keeps the
 * four-bit list in DAT_a802cc82 up to date:
 *  - c == 4 (field 0) and c == 6 (field 2): when that field holds a value k != 0, k is moved first: s = first of the
 *    fields {1, 3} that is 0, else 4 (printed with s_001a7328 "IsAnyACRAvailable %d"). s <= 3: field s = k,
 *    FUN_a013863c(k, i, s, 1) for every i in 0..8 with DAT_a802a480[i] == k, then c goes into the first zero field of
 *    DAT_a802cc82. s == 4: DAT_a802cc82 = (DAT_a802cc82 >> 4) | (c << 12), the field of DAT_a802cc80 holding the
 *    four bits shifted out (index 0..3, 4 when none) gets k, and the same FUN_a013863c calls are made for that index.
 *    Finally field 0 (c == 4) or field 2 (c == 6) is set to c.
 *  - any other c: s as above; s <= 3: field s = c and c goes into the first zero field of DAT_a802cc82; s == 4:
 *    the DAT_a802cc82 shift with c, and the field holding the shifted-out bits gets c.
 * The helpers are same-file copies of FUN_a014ea54, FUN_a014eaa8, FUN_a014ead0, FUN_a014eb14 and FUN_a014eba4, which
 * GCC inlines at -O3.
 * Source form: the first-zero-field insert of the c == 4 / c == 6 arms is called with the variable c, the shift
 * insert and the final field store with the constants 4 and 6; the s > 3 case is the first arm of each test.
 */
extern unsigned short DAT_a802cc80;
extern unsigned short DAT_a802cc82;
extern unsigned char DAT_a802a480[];
extern char s_001a7328[];
extern int FUN_a00df170();
extern void FUN_a013863c(unsigned char, unsigned char, unsigned char, unsigned char);

static void put82(unsigned char c)
{
    unsigned char i;
    for (i = 0; i < 4; i++)
        if (((DAT_a802cc82 >> (i * 4)) & 0xf) == 0) {
            DAT_a802cc82 |= c << (i * 4);
            break;
        }
}

static unsigned char push82(unsigned char c)
{
    unsigned short x = DAT_a802cc82;

    DAT_a802cc82 = (x >> 4) | (c << 12);
    return x & 0xf;
}

static unsigned char find(unsigned char c)
{
    unsigned char i;

    for (i = 0; i < 4; i++)
        if (((DAT_a802cc80 >> (i * 4)) & 0xf) == c)
            break;
    return i;
}

static unsigned char free_slot(void)
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

static inline unsigned char get(unsigned char n) { return DAT_a802a480[n]; }

static void notify(unsigned char a, unsigned char b)
{
    unsigned char i;
    for (i = 0; i <= 8; i++)
        if (a == get(i))
            FUN_a013863c(a, i, b, 1);
}

void FUN_a014ebf8(unsigned char c)
{
    unsigned char k, s;

    if (c == 4) {
        k = DAT_a802cc80 & 0xf;
        if (k != 0) {
            s = free_slot();
            if (s > 3) {
                s = find(push82(4));
                DAT_a802cc80 = (DAT_a802cc80 & ~(0xf << (s * 4))) | (k << (s * 4));
                notify(k, s);
            } else {
                DAT_a802cc80 = (DAT_a802cc80 & ~(0xf << (s * 4))) | (k << (s * 4));
                notify(k, s);
                put82(c);
            }
        }
        DAT_a802cc80 = (DAT_a802cc80 & ~0xf) | 4;
    } else if (c == 6) {
        k = (DAT_a802cc80 >> 8) & 0xf;
        if (k != 0) {
            s = free_slot();
            if (s > 3) {
                s = find(push82(6));
                DAT_a802cc80 = (DAT_a802cc80 & ~(0xf << (s * 4))) | (k << (s * 4));
                notify(k, s);
            } else {
                DAT_a802cc80 = (DAT_a802cc80 & ~(0xf << (s * 4))) | (k << (s * 4));
                notify(k, s);
                put82(c);
            }
        }
        DAT_a802cc80 = (DAT_a802cc80 & ~0xf00) | 0x600;
    } else {
        s = free_slot();
        if (s > 3) {
            s = find(push82(c));
            DAT_a802cc80 = (DAT_a802cc80 & ~(0xf << (s * 4))) | (c << (s * 4));
        } else {
            DAT_a802cc80 = (DAT_a802cc80 & ~(0xf << (s * 4))) | (c << (s * 4));
            put82(c);
        }
    }
}
