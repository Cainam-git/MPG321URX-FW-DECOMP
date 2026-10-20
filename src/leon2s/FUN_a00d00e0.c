/* leon2s FUN_a00d00e0 @ 0xa00d00e0-0xa00d01f4 (69 words), flags -mcpu=v8 -Os -g.
 * ch (u8). Word 0 of the 24-byte record DAT_a8078bb0[ch]: bits 16..17 = 1. If FUN_a00cfb20(ch + 8) != 0:
 * bits 16..17 = 3. Else: clears bit 22; func_0xa0fb7940(ch, 0, 0x20, 1) then (.., 0); if bit 0 of
 * func_0xa0fb7acc(0, 6): hw reg 0xcf018d54 |= 2, 0xcf018ddc &= ~1; else 0xcf018d54 &= ~2; then
 * 0xcf018d54 &= ~0x20, 0xcf018d00 &= ~3, 0xcf018e50 &= ~0x11. void.
 * In the bit-0 arm d54 |= 2 comes before ddc &= ~1. FUN_a00cfb20 takes one int arg (it shifts %i0
 * directly). Source form: the '!= 0' arm first; a record struct indexed by ch. volatile only on the
 * 0xcf... hw registers.
 */
struct Rec18 { unsigned int w0; unsigned char pad[0x14]; };
extern struct Rec18 DAT_a8078bb0[];
extern int FUN_a00cfb20(unsigned int);
extern void func_0xa0fb7940(unsigned char, unsigned int, unsigned int, unsigned int);
extern unsigned int func_0xa0fb7acc(unsigned int, unsigned int);

#define R(a) (*(volatile unsigned int *)(a))

void FUN_a00d00e0(unsigned char ch)
{
    DAT_a8078bb0[ch].w0 = (DAT_a8078bb0[ch].w0 & ~0x30000) | 0x10000;
    if (FUN_a00cfb20(ch + 8) != 0) {
        DAT_a8078bb0[ch].w0 |= 0x30000;
    } else {
        DAT_a8078bb0[ch].w0 &= ~0x400000;
        func_0xa0fb7940(ch, 0, 0x20, 1);
        func_0xa0fb7940(ch, 0, 0x20, 0);
        if (func_0xa0fb7acc(0, 6) & 1) {
            R(0xcf018d54) |= 2;
            R(0xcf018ddc) &= ~1;
        } else {
            R(0xcf018d54) &= ~2;
        }
        R(0xcf018d54) &= ~0x20;
        R(0xcf018d00) &= ~3;
        R(0xcf018e50) &= ~0x11;
    }
}
