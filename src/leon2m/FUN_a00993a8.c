/* FUN_a00993a8 (leon2m 0xa00993a8-0xa0099440, 152 bytes), flags -mcpu=v8 -O3 -g.
 * Toggles bit 30 of the word at DAT_a802d290 + 0x1f4, calls FUN_a00a5420(1, bit) and FUN_a01243bc(1), then
 * FUN_a0124a68() when the bit is now set or FUN_a0124ab0() when clear, then FUN_a0124b40() and FUN_a00db174(), and
 * sets bit 1 of the byte DAT_a802b08e. Source form: a union of the word and a bit-field view; the bit is set to
 * ~(word >> 30) and tested on the word with 0x40000000.
 */
union F1f4 { unsigned int w; struct { unsigned int b31:1, b30:1, rest:30; } f; };
struct G290 { unsigned char p0[0x1f4]; union F1f4 u; };
extern struct G290 DAT_a802d290;
extern unsigned char DAT_a802b08e;
extern void FUN_a00a5420(unsigned char i0, unsigned char i1);
extern void FUN_a01243bc(unsigned char);
extern void FUN_a0124a68(void);
extern void FUN_a0124ab0(void);
extern void FUN_a0124b40(void);
extern void FUN_a00db174(void);

void FUN_a00993a8(void)
{
    DAT_a802d290.u.f.b30 = ~(DAT_a802d290.u.w >> 30);
    FUN_a00a5420(1, DAT_a802d290.u.f.b30);
    FUN_a01243bc(1);
    if (DAT_a802d290.u.w & 0x40000000)
        FUN_a0124a68();
    else
        FUN_a0124ab0();
    FUN_a0124b40();
    FUN_a00db174();
    DAT_a802b08e |= 2;
}
