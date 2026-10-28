/* leon2m FUN_a014bac4 @ 0xa014bac4-0xa014bc58 (101 words; the asm header's '44 bytes' label is wrong, its range is
 * right). Dispatches setting id 0..18 to a setter, passing v converted to the setter's parameter type
 * (unsigned char or unsigned short): 0 FUN_a014f974, 1 FUN_a014f980, 2 FUN_a014f888, 3 FUN_a014f894,
 * 4..11 FUN_a014f8a0(1 << (id - 4), v), 12 FUN_a014f92c, 13 FUN_a014f938, 14 FUN_a014f944, 15 FUN_a014f98c,
 * 16 FUN_a014f95c, 17 FUN_a014f950, 18 FUN_a014f968; other ids do nothing. All calls are tail calls.
 * v is an unsigned short parameter: callers pass a 16-bit value (FUN_a008767c narrows its computed value to
 * 16 bits before the call).
 */
extern void FUN_a014f888(unsigned short);
extern void FUN_a014f894(unsigned short);
extern void FUN_a014f8a0(unsigned char, unsigned char);
extern void FUN_a014f92c(unsigned short);
extern void FUN_a014f938(unsigned char);
extern void FUN_a014f944(unsigned short);
extern void FUN_a014f950(unsigned short);
extern void FUN_a014f95c(unsigned short);
extern void FUN_a014f968(unsigned char);
extern void FUN_a014f974(unsigned char);
extern void FUN_a014f980(unsigned char);
extern void FUN_a014f98c(unsigned char);

void FUN_a014bac4(unsigned int id, unsigned short v)
{
    switch (id) {
    case 0:
        FUN_a014f974(v);
        break;
    case 1:
        FUN_a014f980(v);
        break;
    case 2:
        FUN_a014f888(v);
        break;
    case 3:
        FUN_a014f894(v);
        break;
    case 4:
        FUN_a014f8a0(0x1, v);
        break;
    case 5:
        FUN_a014f8a0(0x2, v);
        break;
    case 6:
        FUN_a014f8a0(0x4, v);
        break;
    case 7:
        FUN_a014f8a0(0x8, v);
        break;
    case 8:
        FUN_a014f8a0(0x10, v);
        break;
    case 9:
        FUN_a014f8a0(0x20, v);
        break;
    case 10:
        FUN_a014f8a0(0x40, v);
        break;
    case 11:
        FUN_a014f8a0(0x80, v);
        break;
    case 12:
        FUN_a014f92c(v);
        break;
    case 13:
        FUN_a014f938(v);
        break;
    case 14:
        FUN_a014f944(v);
        break;
    case 15:
        FUN_a014f98c(v);
        break;
    case 16:
        FUN_a014f95c(v);
        break;
    case 17:
        FUN_a014f950(v);
        break;
    case 18:
        FUN_a014f968(v);
        break;
    }
}
