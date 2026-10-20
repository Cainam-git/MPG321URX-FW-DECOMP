/* leon2m FUN_a00decf4 @ 0xa00decf4-0xa00ded78 (33 words).
 * When byte 0xa802b0c4 is nonzero: stores a in the word 0xa802b0e4 and c in the word 0xa802b0e8, calls
 * func_0x4008c268(0xc00a0024, 0, 0x80) and, when on is nonzero, func_0x4008c25c(0xc00a0020, (b * 10) & 0xffffff)
 * and func_0x4008c268(0xc00a0024, 0x80, 0x80).
 */
struct B0c4 {
    unsigned char on;
    unsigned char pad[3];
    unsigned int w4;
    unsigned int w8;
    unsigned char padc[0x20 - 0xc];
    unsigned int w20;
    unsigned int w24;
};
extern struct B0c4 DAT_a802b0c4;
extern void func_0x4008c268(unsigned int, unsigned int, unsigned int);
extern void func_0x4008c25c(unsigned int, unsigned int);

void FUN_a00decf4(unsigned char on, unsigned int a, unsigned int b, unsigned int c)
{
    if (DAT_a802b0c4.on) {
        DAT_a802b0c4.w20 = a;
        DAT_a802b0c4.w24 = c;
        func_0x4008c268(0xc00a0024, 0, 0x80);
        if (on) {
            func_0x4008c25c(0xc00a0020, (b * 10) & 0xffffff);
            func_0x4008c268(0xc00a0024, 0x80, 0x80);
        }
    }
}
