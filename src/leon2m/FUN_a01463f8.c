/* FUN_a01463f8 (leon2m 0xa01463f8-0xa014648c, 148 bytes), flags -mcpu=v8 -O3 -g.
 * Dispatches on c: FUN_a011c6c8(v, sel), FUN_a011c77c(v, sel), FUN_a011c830(v, sel) or FUN_a011c8e4(v, sel) for c =
 * 0, 1, 2, 3, as tail calls; other c do nothing. Called by FUN_a008ef48.
 */
extern void FUN_a011c77c(unsigned short v, unsigned char sel);
extern void FUN_a011c830(unsigned short v, unsigned char sel);
extern void FUN_a011c6c8(unsigned short v, unsigned char sel);
extern void FUN_a011c8e4(unsigned short v, unsigned char sel);

void FUN_a01463f8(unsigned char c, unsigned short v, unsigned char sel)
{
    switch (c) {
    case 0:
        FUN_a011c6c8(v, sel);
        break;
    case 1:
        FUN_a011c77c(v, sel);
        break;
    case 2:
        FUN_a011c830(v, sel);
        break;
    case 3:
        FUN_a011c8e4(v, sel);
        break;
    }
}
