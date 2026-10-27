/* FUN_a006cc24 (leon2s 0xa006cc24-0xa006cfac, 904 bytes), flags -mcpu=v8 -Os -g.
 * void (n, src, arg, dst). Clears the local word arrays in[480] and out[256] with FUN_a00b15ac, writes 0x81 to
 * register 0xcf011f80, then walks i = 0, 3, 6, .. < n over in[] taken modulo 480: at every i that is a
 * multiple of 480 and while blk <= last ((n + 479) / 480 - 1) it calls FUN_a006cb98(in, src, last, part,
 * rem, blk, arg) with rem = n % 480 and part = (rem != 0), then blk++. The word w = in[i % 480] gives two
 * 16-bit counts: the low half copies in[(i + 1) % 480] that many times into out[], the high half copies
 * in[(i + 2) % 480]. Whenever out[] holds 0x100 words it is passed to FUN_a006c788(out, (dst >> 5) +
 * page * 32, 32) and page++. A count of 0xffff prints "error1!! ..." (w, i) or "error2!! ..." (w, i,
 * in[(i + 1) % 480]) with FUN_a0073044 and ends the walk. Without an error, a partly filled out[] (cnt words)
 * is passed as FUN_a006c788(out, (dst >> 5) + page * 32, (cnt + 7) >> 3).
 * Source forms the exact build depends on: part initialised to 0 at its declaration and set again in both
 * arms of 'if (rem == 0)' (the firmware's 'mov %l7,%i1' copy of err's zero); last, err, cnt, rem assigned in
 * that order; 'out[cnt] = ...; cnt++;' and 'page++' as their own statements.
 */
#define REG_CF011F80 (*(volatile unsigned int *)0xcf011f80)

extern void *FUN_a00b15ac(void *, int, unsigned int);
extern int FUN_a0073044(const char *, ...);
extern void FUN_a006cb98(unsigned int *, unsigned int, unsigned short, unsigned char, unsigned short,
                         unsigned short, unsigned int);
extern void FUN_a006c788(unsigned int *, unsigned int, unsigned int);

void FUN_a006cc24(unsigned int n, unsigned int src, unsigned int arg, unsigned int dst)
{
    unsigned int in[480];
    unsigned int out[256];
    unsigned short rem, last, blk, cnt, page, num;
    unsigned char part = 0, err;
    unsigned int i, j, w;

    FUN_a00b15ac(in, 0, sizeof in);
    FUN_a00b15ac(out, 0, sizeof out);
    last = (n + 479) / 480 - 1;
    err = 0;
    cnt = 0;
    rem = n % 480;
    if (rem == 0)
        part = 0;
    else
        part = 1;
    REG_CF011F80 = 0x81;
    blk = 0;
    page = 0;
    for (i = 0; i < n; i += 3) {
        if (i % 480 == 0) {
            if (blk <= last) {
                FUN_a006cb98(in, src, last, part, rem, blk, arg);
                blk++;
            }
        }
        w = in[i % 480];
        num = w;
        if (num == 0xffff) {
            FUN_a0073044("error1!! (0x%08lX) (%ld)\r\n", w, i);
            err = 1;
            break;
        }
        for (j = 0; j < num; j++) {
            out[cnt] = in[(i + 1) % 480];
            cnt++;
            if (cnt == 0x100) {
                cnt = 0;
                FUN_a006c788(out, (dst >> 5) + page * 32, 32);
                page++;
            }
        }
        num = w >> 16;
        if (num == 0xffff) {
            FUN_a0073044("error2!! (0x%08lX) (%ld) (0x%08lX)\r\n", w, i, in[(i + 1) % 480]);
            err = 1;
            break;
        }
        for (j = 0; j < num; j++) {
            out[cnt] = in[(i + 2) % 480];
            cnt++;
            if (cnt == 0x100) {
                cnt = 0;
                FUN_a006c788(out, (dst >> 5) + page * 32, 32);
                page++;
            }
        }
    }
    if (cnt != 0 && !err)
        FUN_a006c788(out, (dst >> 5) + page * 32, (cnt + 7) >> 3);
}
