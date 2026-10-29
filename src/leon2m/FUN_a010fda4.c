/* leon2m FUN_a010fda4 @ 0xa010fda4-0xa010fe50 (43 words), flags -mcpu=v8 -O3 -g.
 *
 * void(u8 c). For register block 0xD0032000 and then 0xD003A000: c == 1 clears bit 2 of the base register and
 * sets bit 1 of base | 0x270; any other c clears bit 1 of the base register and sets bit 0 of base | 0x270.
 * Source form: one static helper set(base, c), inlined twice, with the base as a const parameter.
 * Compiler aid: the block '{ struct Aid s = { c }; }' between the two calls emits no instructions. Its
 * initialisation puts a CLOBBER of the unused structure in front of the second c == 1 test; GCSE jump bypassing
 * only redirects a block holding a single set before its jump, so the second test is kept after both arms of the
 * first (the firmware re-tests c there), and the dead CLOBBER is deleted later.
 */
#define R(a) (*(volatile unsigned int *)(a))
struct Aid { unsigned int v; };

static void set(const unsigned int b, unsigned char c)
{
    if (c == 1) {
        R(b) &= ~4;
        R(b | 0x270) |= 2;
    } else {
        R(b) &= ~2;
        R(b | 0x270) |= 1;
    }
}

void FUN_a010fda4(unsigned char c)
{
    set(0xd0032000, c);
    {
        struct Aid s = { c };
    }
    set(0xd003a000, c);
}
