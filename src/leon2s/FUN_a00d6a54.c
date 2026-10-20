/* FUN_a00d6a54 (leon2s 0xa00d6a54-0xa00d6b4c, 248 bytes), flags -mcpu=v8 -Os -g.
 * n = FUN_a00d68cc(msg, buf) fills the 16-byte stack buffer buf. type 1: buf[0..n) is copied to
 * ARR_a807a398 + DAT_a8078808[DAT_a8078832] * 11 + DAT_a8078832 * 0xb0 (11-byte entries, 0xb0 bytes per
 * DAT_a8078832 value); type 3: to ARR_a807a520[DAT_a80787ff & 0xf] (0x30-byte records). Other types copy
 * nothing. The third parameter is not used (callers pass it).
 * Source forms: switch on type; the counter is set to 0 before the n != 0 test of each case and the copy is
 * a do-while; the destination pointer is a local of each case block; the first destination is written as
 * byte offsets in Ghidra's order (entry * 11 first).
 */
extern unsigned char DAT_a8078832;
extern unsigned char DAT_a8078808[];
extern unsigned char DAT_a80787ff;
extern unsigned char ARR_a807a398[][16][11];
extern unsigned char ARR_a807a520[][0x30];
extern int FUN_a00d68cc(void *msg, unsigned char *out);

void FUN_a00d6a54(void *msg, unsigned char type, int unused)
{
    unsigned char buf[16];
    unsigned char n;
    unsigned char i;

    n = FUN_a00d68cc(msg, buf);
    switch (type) {
    case 1:
        i = 0;
        if (n != 0) {
            unsigned char *dst = (unsigned char *)ARR_a807a398 + DAT_a8078808[DAT_a8078832] * 11 + DAT_a8078832 * 0xb0;
            do {
                dst[i] = buf[i];
                i++;
            } while (i < n);
        }
        break;
    case 3:
        i = 0;
        if (n != 0) {
            unsigned char *dst = ARR_a807a520[DAT_a80787ff & 0xf];
            do {
                dst[i] = buf[i];
                i++;
            } while (i < n);
        }
        break;
    }
}
