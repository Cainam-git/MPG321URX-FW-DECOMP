/* FUN_a007ec30 (leon2s 0xa007ec30-0xa007ed0c, 220 bytes), flags -mcpu=v8 -Os -g.
 * port (u8), a, b. When FUN_a0073520(port) is not 0: with i = (port != 2) and w = word +0xc of the 0x34-byte
 * record ARR_a807db00[i], calls FUN_a00a73ac(0x10, w + 0x74) when the low byte of a is 1, else
 * FUN_a00a73d4(0x10, w + 0x74); then the same with 0x12 for the low byte of b. Otherwise calls
 * FUN_a00a67b8(port, 0x2f6, 1, a) and FUN_a00a67b8(port, 0x2f6, 4, b) (fourth parameter unsigned char).
 * Source form: a and b are unsigned int parameters converted to unsigned char locals inside the first arm; the
 * conversion is shared with the byte argument of the other arm (the firmware masks each once, after the
 * FUN_a0073520 call).
 */
struct Port34 { unsigned char pad[0xc]; unsigned int base; unsigned char rest[0x34 - 0x10]; };

extern struct Port34 ARR_a807db00[];
extern unsigned char FUN_a0073520(unsigned char);
extern void FUN_a00a67b8(unsigned char, unsigned short, unsigned char, unsigned char);
extern void FUN_a00a73ac(unsigned int, int);
extern void FUN_a00a73d4(unsigned int, int);

void FUN_a007ec30(unsigned char port, unsigned int a, unsigned int b)
{
    unsigned char idx;

    if (FUN_a0073520(port)) {
        unsigned char x = a;
        unsigned char y = b;
        idx = port != 2;
        if (x == 1)
            FUN_a00a73ac(0x10, ARR_a807db00[idx].base + 0x74);
        else
            FUN_a00a73d4(0x10, ARR_a807db00[idx].base + 0x74);
        if (y == 1)
            FUN_a00a73ac(0x12, ARR_a807db00[idx].base + 0x74);
        else
            FUN_a00a73d4(0x12, ARR_a807db00[idx].base + 0x74);
    } else {
        FUN_a00a67b8(port, 0x2f6, 1, a);
        FUN_a00a67b8(port, 0x2f6, 4, b);
    }
}
