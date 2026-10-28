/* leon2m FUN_a00fccbc @ 0xa00fccbc-0xa00fcdd8 (71 words), -mcpu=v8 -O3 -g. No direct callers found.
 * Writes 0x32 to register 0xcf012084 and the three bytes of entry i of a 16 x 3 byte table ("eng", "spa", "fra",
 * "ger", "ita", "por", "rus", "zho", "swe", "pol", "cze", "kor", "zho", "jpn", "dut", "fin") to 0xcf012088,
 * 0xcf01208c and 0xcf012090. Then the inlined xfer(0xf, 4): 0x2e to 0xcf012034; when the function pointer
 * _DAT_a802c970 is set it is called with (0xf, 4), else 0xf goes to 0xcf012080 and 4 to 0xcf012040; it polls
 * 0xcf012034 for any of the bits 0x2e, calling func_0x4008ced8() between polls, until func_0x4008d594 of the start
 * value func_0x4008d588() exceeds 1000; finally it reads 0xcf012034 and writes 0x2e to it.
 * Source form: the table is an initialised const local array (firmware 0x19a466 holds its initialiser); GCC copies
 * it to the stack with a memcpy call, and memcpy is declared with the link name FUN_a013c910 (an __asm__ name, no
 * code).
 */
#define R(a) (*(volatile unsigned int *)(a))

extern void *memcpy(void *dst, const void *src, unsigned int n) __asm__("FUN_a013c910");
extern void (*_DAT_a802c970)(int, int);
extern unsigned short func_0x4008d588(void);
extern unsigned short func_0x4008d594(unsigned short start);
extern void func_0x4008ced8(void);

static void xfer(unsigned char mode, unsigned char op)
{
    unsigned short t0;

    R(0xcf012034) = 0x2e;
    if (_DAT_a802c970 != 0)
        _DAT_a802c970(mode, op);
    else {
        R(0xcf012080) = mode;
        R(0xcf012040) = op;
    }
    t0 = func_0x4008d588();
    while (!(R(0xcf012034) & 0x2e)) {
        func_0x4008ced8();
        if (func_0x4008d594(t0) > 1000)
            break;
    }
    (void)R(0xcf012034);
    R(0xcf012034) = 0x2e;
}

void FUN_a00fccbc(unsigned int i)
{
    const unsigned char tab[16][3] = {
        { 'e', 'n', 'g' }, { 's', 'p', 'a' }, { 'f', 'r', 'a' }, { 'g', 'e', 'r' },
        { 'i', 't', 'a' }, { 'p', 'o', 'r' }, { 'r', 'u', 's' }, { 'z', 'h', 'o' },
        { 's', 'w', 'e' }, { 'p', 'o', 'l' }, { 'c', 'z', 'e' }, { 'k', 'o', 'r' },
        { 'z', 'h', 'o' }, { 'j', 'p', 'n' }, { 'd', 'u', 't' }, { 'f', 'i', 'n' }
    };

    R(0xcf012084) = 0x32;
    R(0xcf012088) = tab[i][0];
    R(0xcf01208c) = tab[i][1];
    R(0xcf012090) = tab[i][2];
    xfer(0xf, 4);
}
