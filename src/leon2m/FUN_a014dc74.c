/* FUN_a014dc74 (leon2m 0xa014dc74-0xa014dd10, 156 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * With m = 0xf when on is non-zero (else 0), calls FUN_a00fe880(0xd, 0x40, m), (0xf, 4, m), (0xd, 0x80, m) or (0xf,
 * 8, m) as a tail call for c = 1, 2, 3 or 4. Nothing in the image refers to it: no call, branch, sethi/or constant
 * or address word. It lies between FUN_a014dc28 and FUN_a014dd10. Source form: m written as 'on == 0 ? 0 : 0xf'.
 */
extern void FUN_a00fe880(unsigned char a, unsigned char b, unsigned int c);
void FUN_a014dc74(unsigned char c, unsigned char on)
{
    unsigned int m = on == 0 ? 0 : 0xf;
    switch (c) {
    case 1:
        FUN_a00fe880(0xd, 0x40, m);
        break;
    case 2:
        FUN_a00fe880(0xf, 4, m);
        break;
    case 3:
        FUN_a00fe880(0xd, 0x80, m);
        break;
    case 4:
        FUN_a00fe880(0xf, 8, m);
        break;
    }
}
