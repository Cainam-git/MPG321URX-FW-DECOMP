/* leon2m FUN_a0097dec @ 0xa0097dec-0xa0097f48 (87 words).
 * When word 0xa802afec - 0x7f differs from byte 0xa8025c54: FUN_a00a93bc(byte 0xa8025c54) and
 * FUN_a00a813c(1, byte 0xa8025c54, 0). v = 0 for afec 0x7f, 1 for afec 0x80, else byte 0xa8025c54; when byte
 * DAT_a802d290+0x2f differs from v it is set to v and FUN_a00d91fc(0), FUN_a0148268(0, 1), FUN_a0148268(1, 1)
 * and FUN_a00da254() run. Then FUN_a00a93bc(afec - 0x7f), FUN_a00a813c(1, +0x2f, 1), FUN_a00a9650(+0x2f, 0),
 * FUN_a00a9468(1, 2); afec = 0x25; FUN_a00a900c(2, 1), FUN_a00a9468(1, 2), FUN_a00b34d4(0, 1); byte 0xa802b08f = 5.
 * Source form: each afec case has its own compare, store and call sequence (GCC merges the call sequences).
 */
struct R290 {
    unsigned char pad0[0x2f];
    unsigned char b2f;
};
extern struct R290 DAT_a802d290;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a8025c54;
extern unsigned char DAT_a802b08f;
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a9468(unsigned int, unsigned int);
extern void FUN_a00b34d4(int, int);
extern void FUN_a00d91fc(unsigned char);
extern void FUN_a0148268(int, int);
extern void FUN_a00da254(void);

void FUN_a0097dec(void)
{
    if (_DAT_a802afec - 0x7f != DAT_a8025c54) {
        FUN_a00a93bc(DAT_a8025c54);
        FUN_a00a813c(1, DAT_a8025c54, 0);
    }
    if (_DAT_a802afec == 0x7f) {
        if (DAT_a802d290.b2f != 0) {
            DAT_a802d290.b2f = 0;
            FUN_a00d91fc(0);
            FUN_a0148268(0, 1);
            FUN_a0148268(1, 1);
            FUN_a00da254();
        }
    } else if (_DAT_a802afec == 0x80) {
        if (DAT_a802d290.b2f != 1) {
            DAT_a802d290.b2f = 1;
            FUN_a00d91fc(0);
            FUN_a0148268(0, 1);
            FUN_a0148268(1, 1);
            FUN_a00da254();
        }
    } else if (DAT_a802d290.b2f != DAT_a8025c54) {
        DAT_a802d290.b2f = DAT_a8025c54;
        FUN_a00d91fc(0);
        FUN_a0148268(0, 1);
        FUN_a0148268(1, 1);
        FUN_a00da254();
    }
    FUN_a00a93bc(_DAT_a802afec - 0x7f);
    FUN_a00a813c(1, DAT_a802d290.b2f, 1);
    FUN_a00a9650(DAT_a802d290.b2f, 0);
    FUN_a00a9468(1, 2);
    _DAT_a802afec = 0x25;
    FUN_a00a900c(2, 1);
    FUN_a00a9468(1, 2);
    FUN_a00b34d4(0, 1);
    DAT_a802b08f = 5;
}
