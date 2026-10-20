/* FUN_a00d2678 (leon2s, 0xa00d2678-0xa00d27fc, 97 words). Flags -mcpu=v8 -Os -g. jf 100.00 match=True, rawcmp_l2s 0 mismatches.
 Code facts: (sel, u8 unused). src = DAT_9f1c3fa0 for sel 1, else none. Register 0xd0013fe0 field write (2,0)=7 via func_0xa0f71528/714b8/71534.
 For i = 0..0x400: field (0x12,8) = i written to 0xd0013fe0; with a src and sum < 0xfff, a byte b: b <= 0xef adds b, else adds ((b & 0xf) << 8) + the
 next byte (escape pair); i != 0x400 writes sum to 0xd0013fe8, i == 0x400 does FUN_a00d21e0(&v, 0xb, 0, 0xfff) on 0xd0013fec. Then 0xd0013fec
 field (0x1f,0x1e) = 0 and 3. Returns 1.
 Fixes vs draft: BEHAVIOUR the high nibble term was truncated to a u8 (always 0 in the draft); the <= 0xef and != 0x400 arms come first
 in the source (fw fall-through order); 0x9f1c3fa0 as a symbol array. Aids: none.
 */
extern unsigned char DAT_9f1c3fa0[];
extern void FUN_a00d21e0(unsigned int *, unsigned int, unsigned int, unsigned int);
extern void func_0xa0f714b8(unsigned int *, unsigned int, unsigned int, unsigned int);
extern unsigned int func_0xa0f71528(unsigned int);
extern void func_0xa0f71534(unsigned int, unsigned int);

int FUN_a00d2678(int sel, unsigned char param_2)
{
    unsigned int v;
    unsigned char *src;
    unsigned int sum;
    unsigned int pos;
    unsigned int i;
    unsigned int b;

    v = 0;
    src = 0;
    if (sel == 0)
        ;
    else if (sel == 1)
        src = DAT_9f1c3fa0;
    v = func_0xa0f71528(0xd0013fe0);
    func_0xa0f714b8(&v, 2, 0, 7);
    func_0xa0f71534(0xd0013fe0, v);
    sum = 0;
    pos = 0;
    i = 0;
    do {
        func_0xa0f714b8(&v, 0x12, 8, i);
        func_0xa0f71534(0xd0013fe0, v);
        if (src != 0 && sum < 0xfff) {
            b = src[pos];
            if (b <= 0xef) {
                sum += b;
            } else {
                pos++;
                sum += ((b & 0xf) << 8) + src[pos];
            }
            pos++;
        }
        if (i != 0x400) {
            func_0xa0f71534(0xd0013fe8, sum);
        } else {
            v = func_0xa0f71528(0xd0013fec);
            FUN_a00d21e0(&v, 0xb, 0, 0xfff);
            func_0xa0f71534(0xd0013fec, v);
        }
        i++;
    } while (i <= 0x400);
    v = func_0xa0f71528(0xd0013fec);
    func_0xa0f714b8(&v, 0x1f, 0x1e, 0);
    func_0xa0f71534(0xd0013fec, v);
    func_0xa0f714b8(&v, 0x1f, 0x1e, 3);
    func_0xa0f71534(0xd0013fec, v);
    return 1;
}
