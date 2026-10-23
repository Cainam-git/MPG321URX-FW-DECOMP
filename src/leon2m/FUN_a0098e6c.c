/* leon2m FUN_a0098e6c @ 0xa0098e6c-0xa0098f28 (47 words), flags -mcpu=v8 -O3 -g.
 * Calls FUN_a00a900c(word 0xa802afec - 42, 2). Then, from bits 5 and 6 of word 0xa802d338 (offset 0xa8 of
 * the block at 0xa802d290): when bit 6 is set, word 0xa802afec becomes 0xb2 + bit 5 and byte 0xa8025c56 becomes
 * bit 5 + 1; otherwise it becomes 0xb1 and the byte gets bit 6 (0). FUN_a00a9650(word - 0xb1, 1) and
 * FUN_a00a813c(1, word - 0xb1, 0) follow.
 * Source form: bit 6 is tested through the word view of the union ('w & 0x40', clear case first) and read through
 * the bit-field view, so the stored bit is computed (srl/and) rather than known as 0.
 */
struct G290 {
    unsigned char pad0[0xa8];
    union {
        struct {
            unsigned int hi25 : 25;
            unsigned int b6 : 1;
            unsigned int b5 : 1;
            unsigned int lo5 : 5;
        } f;
        unsigned int w;
    } u;
};
extern struct G290 DAT_a802d290;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a8025c56;
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a813c(int, unsigned char, int);

void FUN_a0098e6c(void)
{
    FUN_a00a900c(_DAT_a802afec - 42, 2);
    if (!(DAT_a802d290.u.w & 0x40)) {
        _DAT_a802afec = 0xb1;
        DAT_a8025c56 = DAT_a802d290.u.f.b6;
    } else {
        _DAT_a802afec = DAT_a802d290.u.f.b5 + 0xb2;
        DAT_a8025c56 = DAT_a802d290.u.f.b5 + 1;
    }
    FUN_a00a9650(_DAT_a802afec - 0xb1, 1);
    FUN_a00a813c(1, _DAT_a802afec - 0xb1, 0);
}
