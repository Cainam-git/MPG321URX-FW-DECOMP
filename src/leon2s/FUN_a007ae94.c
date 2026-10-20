/* FUN_a007ae94 (leon2s 0xa007ae94-0xa007af04, 112 bytes), flags -mcpu=v8 -Os -g.
 * When FUN_a0073520(p) is non-zero: tests bit 0x12 of the word array at (word +0xc of the 0x34-byte port
 * record ARR_a807db00[p != 2]) + 0x74 bytes through FUN_a00a7408; otherwise tests bit 2 of register 0x2f6
 * of port p (FUN_a00a657c). Returns 1 when the tested bit is set, else 0.
 * Source forms: both arms store into one result that is tested once with '!= 0' (shared addx); the record
 * pointer is taken before the call. Aid: 'for (;;) break;' generates no code; it ends a CSE region between
 * the record pointer and the call, which gives the firmware's instruction order (table address before the
 * index multiply, the bit number in the call delay slot).
 */
struct PortRec { unsigned char pad[0xc]; unsigned int w0c; unsigned char pad2[0x34 - 0x10]; };
extern struct PortRec ARR_a807db00[];
extern unsigned char FUN_a0073520(unsigned char);
extern unsigned int FUN_a00a657c(unsigned char, unsigned short);
extern unsigned int FUN_a00a7408(unsigned int, unsigned int);

unsigned int FUN_a007ae94(unsigned char p)
{
    unsigned int r;
    unsigned int i;
    struct PortRec *rec;

    if (FUN_a0073520(p) != 0) {
        i = p != 2;
        rec = &ARR_a807db00[i];
        for (;;)
            break;
        r = FUN_a00a7408(0x12, rec->w0c + 0x74);
    } else {
        r = FUN_a00a657c(p, 0x2f6) & 4;
    }
    return r != 0;
}
