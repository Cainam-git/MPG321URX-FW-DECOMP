/* leon2m FUN_a01410a4 @ 0xa01410a4-0xa014110c (26 words).
 * Builds a 16-byte structure on the stack and passes it by value to FUN_a0118e04 (which copies it to 0xa8027a98):
 * word 0 has bits 31, 29 and 30 cleared (1-bit fields, in that order), word 1 = 2, word 2 = 0x1a3668 and
 * word 3 = 0x1a3648 (the record tables also passed by FUN_a014118c). The other 29 bits of word 0 are not written
 * by the firmware either: they keep whatever the stack slot held. Called from FUN_a015209c.
 */
struct RecA { unsigned char b[0x1e]; };
struct RecB { unsigned char e[16][2]; };
extern struct RecA DAT_001a3668[];
extern struct RecB DAT_001a3648[];

struct Cfg {
    unsigned int f31:1, f30:1, f29:1, rest:29;
    unsigned int n;
    struct RecA *a;
    struct RecB *b;
};
extern void FUN_a0118e04(struct Cfg c);

void FUN_a01410a4(void)
{
    struct Cfg c;

    c.f31 = 0;
    c.f29 = 0;
    c.f30 = 0;
    c.n = 2;
    c.a = DAT_001a3668;
    c.b = DAT_001a3648;
    FUN_a0118e04(c);
}
