/* leon2m FUN_a01131d4 @ 0xa01131d4-0xa011337c (106 words, including the unreachable ret/restore tail).
 * Does nothing when m equals DAT_a8027a94. Otherwise reads register 0xcf011a00 twice (saved, cur), stores m to
 * DAT_a8027a94 and DAT_a802c98f, calls FUN_a011855c(); for each set bit i (0..4) of cur: func_0x4008e3c4(i, 1) and
 * bit i cleared in 0xcf011800 and 0xcf011a00; then func_0x4008d1a0(0x32), 0xcf011d8c = 0, FUN_a01118cc(i, byte i of
 * the ROM row DAT_001a6adc[DAT_a802c98e][DAT_a802c98f]) for i = 0..5, FUN_a0112b2c(); for each set bit i (0..4)
 * of saved: func_0x4008e3c4(i, 0) and bit i set again in both registers; finally FUN_a01185d4() when bit 5 of
 * saved is set. Called by FUN_a012fcf4. volatile: hardware registers only.
 */
#define R(a) (*(volatile unsigned int *)(a))

struct Row6 { unsigned char b[0x16]; };
extern const struct Row6 DAT_001a6adc[][2];
extern unsigned char DAT_a8027a94;
extern unsigned char DAT_a802c98e, DAT_a802c98f;
extern void FUN_a011855c(void);
extern void FUN_a01118cc(unsigned char, unsigned char);
extern void FUN_a0112b2c(void);
extern void FUN_a01185d4(void);
extern void func_0x4008e3c4(unsigned int, unsigned int);
extern void func_0x4008d1a0(int ms);

void FUN_a01131d4(unsigned char m)
{
    unsigned char saved, cur, i;

    if (DAT_a8027a94 == m)
        return;
    saved = R(0xcf011a00);
    cur = R(0xcf011a00);
    DAT_a8027a94 = m;
    DAT_a802c98f = m;
    FUN_a011855c();
    for (i = 0; i <= 4; i++) {
        if ((cur >> i) & 1) {
            func_0x4008e3c4(i, 1);
            R(0xcf011800) &= ~(1 << i);
            R(0xcf011a00) &= ~(1 << i);
        }
    }
    func_0x4008d1a0(0x32);
    R(0xcf011d8c) = 0;
    for (i = 0; i <= 5; i++)
        FUN_a01118cc(i, DAT_001a6adc[DAT_a802c98e][DAT_a802c98f].b[i]);
    FUN_a0112b2c();
    for (i = 0; i <= 4; i++) {
        if ((saved >> i) & 1) {
            func_0x4008e3c4(i, 0);
            R(0xcf011800) |= 1 << i;
            R(0xcf011a00) |= 1 << i;
        }
    }
    if (saved & 0x20)
        FUN_a01185d4();
}
