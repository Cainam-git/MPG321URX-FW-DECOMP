/* FUN_a01202c0 (leon2m 0xa01202c0-0xa012043c, 380 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Writes the byte (b << 6) | a | (d << 3) to register DAT_001a2fb0[c] + 0x50 and sets bit 0 of register
 * DAT_001a2fb0[c] + 0x51 (both of entries 0 and 1 for c = 2, nothing for c above 2), each preceded by setting bits
 * 0..1 of the word register 0xcf011428; registers at 0xcf000000 + 4 * index. Nothing in the image refers to it: no
 * call, branch, sethi/or constant or address word. It lies between FUN_a01200f8 and FUN_a012043c. Source form:
 * static put/set helpers (the FUN_a0120678 form) inlined.
 */
#define R28 (*(volatile unsigned int *)0xcf011428)
#define REGI(i) (*(volatile unsigned int *)(0xcf000000 | ((i) << 2)))
extern const unsigned short DAT_001a2fb0[];
static void put(unsigned int c, unsigned int r, unsigned char v)
{
    unsigned char i;
    R28 |= 3;
    if (c == 2) {
        for (i = 0; i <= 1; i++)
            REGI(DAT_001a2fb0[i] + r) = v;
    } else if (c <= 1)
        REGI(DAT_001a2fb0[c] + r) = v;
}
static void setb(unsigned int c, unsigned int r, unsigned char m)
{
    unsigned char i;
    R28 |= 3;
    if (c == 2) {
        for (i = 0; i <= 1; i++)
            REGI(DAT_001a2fb0[i] + r) = (unsigned char)(REGI(DAT_001a2fb0[i] + r) | m);
    } else if (c <= 1)
        REGI(DAT_001a2fb0[c] + r) = (unsigned char)(REGI(DAT_001a2fb0[c] + r) | m);
}
void FUN_a01202c0(unsigned int c, unsigned int a, unsigned int b, unsigned int d)
{
    put(c, 0x50, (b << 6) | a | (d << 3));
    setb(c, 0x51, 1);
}
