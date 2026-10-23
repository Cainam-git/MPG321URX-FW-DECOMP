/* leon2m FUN_a0099658 @ 0xa0099658-0xa0099864 (131 words). Called from FUN_a0099864.
 * When word 0xa802afec is 0x47: byte DAT_a802d290+0x4a = 1; word +0xb0 non-zero -> cleared, FUN_a00d4998(),
 * FUN_a00d5f3c(); FUN_a00837e4() == 1 -> FUN_a00d91fc(0), the 0xa802cff4+4 flag step, afec = 0, FUN_a00b5080(),
 * byte +0x1a4 = 0, FUN_a0148268(0, 1), FUN_a0148268(1, 1), FUN_a00da254(), FUN_a00830f4(0); byte +0x1f non-zero ->
 * cleared, flag step, afec = 0, FUN_a00b5080(), FUN_a0124f44(), FUN_a00d91fc(0), FUN_a00da254(); bit 7 of word
 * +0xa8 set -> cleared, flag step, afec = 0, FUN_a00b5080(), FUN_a0124f44(), FUN_a00d91fc(0), FUN_a00da184(); then
 * FUN_a00d5eac(0), DAT_a802b08e |= 2, and it stops when afec is now 0. The flag step sets bit 10 of halfword
 * 0xa802cff4+4 and calls FUN_a00808ac(4, 0) when its bit 15 is set. Afterwards, when afec is above 0x45: byte
 * +0x4a = afec - 0x46 and FUN_a00d5eac(0) (tail call).
 */
struct Rcff4 {
    unsigned char pad[4];
    unsigned short b15 : 1, b14 : 4, b10 : 1, rest : 10;
};
struct R290 {
    unsigned char pad0[0x1f];
    unsigned char b1f;
    unsigned char pad20[0x4a - 0x20];
    unsigned char b4a;
    unsigned char pad4b[0xa8 - 0x4b];
    unsigned int wa8;
    unsigned int wac;
    unsigned int wb0;
    unsigned char padb4[0x1a4 - 0xb4];
    unsigned char b1a4;
};
extern struct Rcff4 DAT_a802cff4;
extern struct R290 DAT_a802d290;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802b08e;
extern void FUN_a00808ac(unsigned char, unsigned char);
extern void FUN_a00b5080(void);
extern unsigned char FUN_a00837e4(void);
extern void FUN_a00d4998(void);
extern void FUN_a00d5f3c(void);
extern void FUN_a00d5eac(int);
extern void FUN_a00d91fc(int);
extern void FUN_a0124f44(void);
extern void FUN_a00da184(void);
extern void FUN_a00da254(void);
extern void FUN_a0148268(int, int);
extern void FUN_a00830f4(int);

void FUN_a0099658(void)
{
    if (_DAT_a802afec == 0x47) {
        DAT_a802d290.b4a = 1;
        if (DAT_a802d290.wb0 != 0) {
            DAT_a802d290.wb0 = 0;
            FUN_a00d4998();
            FUN_a00d5f3c();
        }
        if (FUN_a00837e4() == 1) {
            FUN_a00d91fc(0);
            if (DAT_a802cff4.b15) {
                DAT_a802cff4.b10 = 1;
                FUN_a00808ac(4, 0);
            }
            _DAT_a802afec = 0;
            FUN_a00b5080();
            DAT_a802d290.b1a4 = 0;
            FUN_a0148268(0, 1);
            FUN_a0148268(1, 1);
            FUN_a00da254();
            FUN_a00830f4(0);
        }
        if (DAT_a802d290.b1f != 0) {
            DAT_a802d290.b1f = 0;
            if (DAT_a802cff4.b15) {
                DAT_a802cff4.b10 = 1;
                FUN_a00808ac(4, 0);
            }
            _DAT_a802afec = 0;
            FUN_a00b5080();
            FUN_a0124f44();
            FUN_a00d91fc(0);
            FUN_a00da254();
        }
        if (DAT_a802d290.wa8 & 0x80) {
            DAT_a802d290.wa8 &= ~0x80;
            if (DAT_a802cff4.b15) {
                DAT_a802cff4.b10 = 1;
                FUN_a00808ac(4, 0);
            }
            _DAT_a802afec = 0;
            FUN_a00b5080();
            FUN_a0124f44();
            FUN_a00d91fc(0);
            FUN_a00da184();
        }
        FUN_a00d5eac(0);
        DAT_a802b08e |= 2;
        if (_DAT_a802afec == 0)
            return;
    }
    if (_DAT_a802afec > 0x45) {
        DAT_a802d290.b4a = _DAT_a802afec - 0x46;
        FUN_a00d5eac(0);
    }
}
