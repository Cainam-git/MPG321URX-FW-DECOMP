/* leon2s FUN_a007af6c @ 0xa007af6c-0xa007afdc (28 words).
 * Template FUN_a007ae94: Test a port status bit: record bit 0x12 or register 0x2f6 bit 2, by FUN_a0073520.
 * This function is the same code as FUN_a007ae94 (its source comment explains the details), compiled with
 * other constants (template -> this function):
 * 0x4 -> 0x2, 0x12 -> 0x9, 0x74 -> 0x60, 0x2f6 -> 0x2e1, 0xa007ae94 -> 0xa007af6c
 */
struct PortRec { unsigned char pad[0xc]; unsigned int w0c; unsigned char pad2[0x34 - 0x10]; };
extern struct PortRec ARR_a807db00[];
extern unsigned char FUN_a0073520(unsigned char);
extern unsigned int FUN_a00a657c(unsigned char, unsigned short);
extern unsigned int FUN_a00a7408(unsigned int, unsigned int);

unsigned int FUN_a007af6c(unsigned char p)
{
    unsigned int r;
    unsigned int i;
    struct PortRec *rec;

    if (FUN_a0073520(p) != 0) {
        i = p != 2;
        rec = &ARR_a807db00[i];
        for (;;)
            break;
        r = FUN_a00a7408(0x9, rec->w0c + 0x60);
    } else {
        r = FUN_a00a657c(p, 0x2e1) & 2;
    }
    return r != 0;
}
