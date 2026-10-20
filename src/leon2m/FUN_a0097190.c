/* leon2m FUN_a0097190 @ 0xa0097190-0xa00972cc (79 words). No direct callers (reached through a table).
 * Calls FUN_a00808ac(4, 0), then compares the low bytes of FUN_a01445fc(byte 0xa802d290+0x1e) and
 * FUN_a01445fc(byte 0xa802d290+0x1a3). Both paths first set bit 10 of the halfword 0xa802cff8 (0xa802cff4 + 4)
 * and call FUN_a00808ac(4, 0) when its bit 15 is set, clear word 0xa802afec and call FUN_a00b5080.
 * Equal: stores 0xfe to word 0xa802afec when FUN_a0143c14(0) is not 10, bit 9 of word 0xa802d290 is clear and
 * byte 0xa802d290+0x1f is 0. Different: copies byte +0x1a3 to +0x1e and tail-calls FUN_a00b8804.
 * Exact form: the equal case is written first; FUN_a01445fc returns int and both results are compared as bytes;
 * bit 15 is tested as '(short)(h4 & 0x8000)' (as FUN_a00a0508).
 */
struct D290 {
    unsigned int w000;
    unsigned char p004[0x1e - 4];
    unsigned char b1e;
    unsigned char b1f;
    unsigned char p020[0x1a3 - 0x20];
    unsigned char b1a3;
};
struct CFF4 {
    unsigned short h0;
    unsigned short h2;
    unsigned short h4;
};
extern struct D290 DAT_a802d290;
extern struct CFF4 DAT_a802cff4;
extern unsigned int _DAT_a802afec;
extern void FUN_a00808ac(int, int);
extern int FUN_a01445fc(unsigned char);
extern void FUN_a00b5080(void);
extern unsigned char FUN_a0143c14(unsigned char);
extern void FUN_a00b8804(void);

void FUN_a0097190(void)
{
    FUN_a00808ac(4, 0);
    if ((unsigned char)FUN_a01445fc(DAT_a802d290.b1e) == (unsigned char)FUN_a01445fc(DAT_a802d290.b1a3)) {
        if ((short)(DAT_a802cff4.h4 & 0x8000)) {
            DAT_a802cff4.h4 |= 0x400;
            FUN_a00808ac(4, 0);
        }
        _DAT_a802afec = 0;
        FUN_a00b5080();
        if (FUN_a0143c14(0) != 10 && !(DAT_a802d290.w000 & 0x200) && DAT_a802d290.b1f == 0)
            _DAT_a802afec = 0xfe;
        return;
    }
    if ((short)(DAT_a802cff4.h4 & 0x8000)) {
        DAT_a802cff4.h4 |= 0x400;
        FUN_a00808ac(4, 0);
    }
    _DAT_a802afec = 0;
    FUN_a00b5080();
    DAT_a802d290.b1e = DAT_a802d290.b1a3;
    FUN_a00b8804();
}
