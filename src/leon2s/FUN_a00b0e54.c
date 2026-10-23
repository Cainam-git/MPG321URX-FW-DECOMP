/* leon2s FUN_a00b0e54 @ 0xa00b0e54-0xa00b1028, -mcpu=v8 -Os -g.
 * void. Two 8-byte stack tables a = {0, 1, 2, 3, 4, 5, 8, 9} and b = {0, 1, 2, 3, 4, 5, 6, 7} (initialisers at
 * 0xa00b4e0c / 0xa00b4e14, copied with memcpy = FUN_a00b15d8). For j = 0..7 and i = 0..4: when v =
 * DAT_a8078768[i] equals j, a[v] = i + 4 and b[v] = 6 or 4: 6 for i <= 3 when FUN_a0083ec4() returns non-zero,
 * 6 for i > 3 when it returns 0. Then the registers 0xcf0117c0.. 0xcf0117dc get (b[2k + 1] << 4) | b[2k] and
 * (a[2k + 1] << 4) | a[2k], 0xcf0117e0 = (DAT_a8078768[3] << 4) | [2], 0xcf0117e4 = 0x13, 0xcf0117e8 =
 * ([1] << 4) | [0], 0xcf0117ec = DAT_a8078768[4] | 0x70.
 * Source form: b[v] stored directly in each arm, the i <= 3 test written first in both arms.
 */
extern unsigned char DAT_a8078768[];
extern unsigned char FUN_a0083ec4(void);
extern void *memcpy(void *, const void *, unsigned int) __asm__("FUN_a00b15d8");

#define R(o) (*(volatile unsigned int *)(0xcf0117c0 + (o)))

void FUN_a00b0e54(void)
{
    unsigned char a[8] = { 0, 1, 2, 3, 4, 5, 8, 9 };
    unsigned char b[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
    unsigned char i, j, v, x;

    for (j = 0; j <= 7; j++) {
        for (i = 0; i <= 4; i++) {
            v = DAT_a8078768[i];
            if (v == j) {
                a[v] = i + 4;
                if (FUN_a0083ec4()) {
                    if (i <= 3)
                        b[v] = 6;
                    else
                        b[v] = 4;
                } else {
                    if (i <= 3)
                        b[v] = 4;
                    else
                        b[v] = 6;
                }
            }
        }
    }
    R(0x00) = b[1] << 4 | b[0];
    R(0x04) = b[3] << 4 | b[2];
    R(0x08) = b[5] << 4 | b[4];
    R(0x0c) = b[7] << 4 | b[6];
    R(0x10) = a[1] << 4 | a[0];
    R(0x14) = a[3] << 4 | a[2];
    R(0x18) = a[5] << 4 | a[4];
    R(0x1c) = a[7] << 4 | a[6];
    R(0x20) = DAT_a8078768[3] << 4 | DAT_a8078768[2];
    R(0x24) = 0x13;
    R(0x28) = DAT_a8078768[1] << 4 | DAT_a8078768[0];
    R(0x2c) = DAT_a8078768[4] | 0x70;
}
