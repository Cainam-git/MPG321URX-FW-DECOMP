/* leon2s FUN_a00c9810 @ 0xa00c9810-0xa00c9968, -mcpu=v8 -Os -g.
 * (u8 port, u8 *p, u16 len), void. func_0xa0fc1794(2); p[0] = func_0xa0fb7fd8(port, 0, 0xf4);
 * blocks = (len >> 4) + 1; func_0xa0f83044(0x9f1c20f8, len, blocks) (ROM calls/addresses outside the image).
 * For each block: reads func_0xa0fb7fd8(port, 0, 0xf5) & 0x1f until it equals len - 1 (len <= 0x10) or 0x10,
 * repeating that wait while the u8 counter tries (0x14, set once) counts down past 0; then reads up to 16
 * bytes with func_0xa0fb7fd8(port, 0, 0xf4): the bytes whose running u16 index n is 0x8b..0x20a go to
 * DAT_a807cf08[ei++], the others to p[di++]; returns when len reaches 0.
 * Source form: the p arm is written first (n - 0x8b > 0x17f); n++ before len--.
 */
extern void func_0xa0fc1794(int);
extern unsigned char func_0xa0fb7fd8(unsigned char, int, unsigned short);
extern int func_0xa0f83044(const char *, ...);
extern unsigned char DAT_a807cf08[];

void FUN_a00c9810(unsigned char port, unsigned char *p, unsigned short len)
{
    unsigned short blocks, b, n, ei;
    unsigned char tries, di, i, v;

    func_0xa0fc1794(2);
    p[0] = func_0xa0fb7fd8(port, 0, 0xf4);
    blocks = (len >> 4) + 1;
    func_0xa0f83044((const char *)0x9f1c20f8, len, blocks);
    tries = 0x14;
    di = 0;
    ei = 0;
    n = 0;
    for (b = 0; b < blocks; b++) {
        do {
            do {
                v = func_0xa0fb7fd8(port, 0, 0xf5) & 0x1f;
            } while (len <= 0x10 ? v != len - 1 : v != 0x10);
        } while (tries-- != 0);
        for (i = 0; i <= 0xf; i++) {
            v = func_0xa0fb7fd8(port, 0, 0xf4);
            if ((unsigned short)(n - 0x8b) > 0x17f)
                p[di++] = v;
            else
                DAT_a807cf08[ei++] = v;
            n++;
            len--;
            if (len == 0)
                return;
        }
    }
}
