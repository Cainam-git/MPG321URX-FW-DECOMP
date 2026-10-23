/* leon2m FUN_a00a01fc @ 0xa00a01fc-0xa00a03e8 (123 words).
 * When byte DAT_a802d290+0x1a9 is 1: when bit 15 of halfword 0xa802cff4+4 is set its bit 10 is set and
 * FUN_a00808ac(4, 0) runs; word 0xa802afec = 0, FUN_a00b5080(), byte 0xa802cff4+0xa = 2, FUN_a00b0f48(),
 * afec = 0x116, DAT_a802b08e |= 2, byte +0x1aa = 0, halfword 0xa802d03c = func_0x4008d588(). Otherwise: byte
 * 0xa8025c54 = byte +0x11, 0xa8025c56 = byte +0x181, 0xa8025c55 = bit 11 of word +0xa8; m = FUN_a00b6b88(byte
 * +0x181, 0); FUN_a00a900c(afec - 21, 2); afec = m + 0x5c. When bit 11 was clear it is set, and unless bits 8..23
 * of word +0x180 are 0x0001: byte +0x11 = 1 when byte +0x181 is 4..6, FUN_a00db738(); then FUN_a00aacb4(2, 1).
 * Both then call FUN_a00a813c(1, m % 7, 0), FUN_a00a9650((afec - 0x5c) % 7, 1) and set byte 0xa802b08f to 0xc.
 * Same form as FUN_a00a03e8.
 * Source form: the bit 11 part goes through a block-local pointer to the record.
 */
struct D290 {
    unsigned char p000[0x11];
    unsigned char b011;
    unsigned char p012[0xa8 - 0x12];
    unsigned int w0a8;
    unsigned char p0ac[0x180 - 0xac];
    union { unsigned int w; unsigned char b[4]; } u180;
    unsigned char b181_pad[0x1a9 - 0x184];
    unsigned char b1a9;
    unsigned char b1aa;
};
struct CFF4 {
    unsigned short h0;
    unsigned short h2;
    unsigned short h4;
    unsigned char p6[4];
    unsigned char ba;
};
extern struct D290 DAT_a802d290;
extern struct CFF4 DAT_a802cff4;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802b08e, DAT_a802b08f;
extern unsigned char DAT_a8025c54, DAT_a8025c55, DAT_a8025c56;
extern unsigned short _DAT_a802d03c;
extern void FUN_a00808ac(int, int);
extern void FUN_a00b5080(void);
extern void FUN_a00b0f48(void);
extern unsigned short func_0x4008d588(void);
extern unsigned char FUN_a00b6b88(unsigned char, unsigned char);
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00db738(void);
extern void FUN_a00aacb4(int, int);

void FUN_a00a01fc(void)
{
    unsigned char m;

    if (DAT_a802d290.b1a9 == 1) {
        if ((short)(DAT_a802cff4.h4 & 0x8000)) {
            DAT_a802cff4.h4 |= 0x400;
            FUN_a00808ac(4, 0);
        }
        _DAT_a802afec = 0;
        FUN_a00b5080();
        DAT_a802cff4.ba = 2;
        FUN_a00b0f48();
        _DAT_a802afec = 0x116;
        DAT_a802b08e |= 2;
        DAT_a802d290.b1aa = 0;
        _DAT_a802d03c = func_0x4008d588();
        return;
    }
    DAT_a8025c55 = (DAT_a802d290.w0a8 >> 11) & 1;
    DAT_a8025c56 = DAT_a802d290.u180.b[1];
    DAT_a8025c54 = DAT_a802d290.b011;
    m = FUN_a00b6b88(DAT_a802d290.u180.b[1], 0);
    FUN_a00a900c(_DAT_a802afec - 21, 2);
    _DAT_a802afec = m + 0x5c;
    {
        struct D290 *p = &DAT_a802d290;

        if (!(p->w0a8 & 0x800)) {
            p->w0a8 |= 0x800;
            if ((p->u180.w & 0xffff00) != 0x100) {
                if ((unsigned char)(p->u180.b[1] - 4) <= 2)
                    p->b011 = 1;
                FUN_a00db738();
            }
            FUN_a00aacb4(2, 1);
        }
    }
    FUN_a00a813c(1, m % 7, 0);
    FUN_a00a9650((_DAT_a802afec - 0x5c) % 7, 1);
    DAT_a802b08f = 0xc;
}
