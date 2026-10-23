/* leon2m FUN_a00da4b8 @ 0xa00da4b8-0xa00da65c (105 words).
 * UserGetCECSourceMode: stores m = FUN_a0083d80() in byte 0xa802d290+0x1b4. When bit 20 of the word at +0xac is
 * set, byte +0x1f is 0, m <= 2 and FUN_a01445fc(FUN_a014448c(0)) returns 0: sets bit 7 of the halfword
 * 0xa802cff4+0xa, copies bit 10 of word +0xa8 to bit 11 and bytes +0x183 / +0x184 to +0x181 / +0x182; then, when
 * chk() is true and byte +0x181 is 4..6, bytes +0x183 and +0x181 become 7 and bit 1 of byte 0xa802b08e is set.
 * Otherwise clears bit 7 of the halfword, copies bit 9 to bit 11 and bytes +0x185 / +0x186 to +0x181 / +0x182.
 * Ends with the trace print of byte +0x1b4, bit 11, byte +0x182 and byte +0x181.
 * chk(): FUN_a014bd70(0) == 1, or FUN_a01438dc(0) == 1 and FUN_a014ba68() is 1..4 (static helper, inlined).
 * Source forms: the record at 0xa802cff4 is reached through a constant address (#define), so GCC does not
 * separate its halfword store from the DAT_a802d290 byte loads, which keeps those loads ahead of the bit merge;
 * in the chk() block the stores are written b181, b183, then the DAT_a802b08e update.
 */
struct Wa8 {
    unsigned int p0 : 20;
    unsigned int b11 : 1;
    unsigned int b10 : 1;
    unsigned int b9 : 1;
    unsigned int b8 : 1;
    unsigned int p1 : 8;
};
struct R290 {
    unsigned char pad0[0x1f];
    unsigned char b1f;
    unsigned char pad20[0xa8 - 0x20];
    struct Wa8 wa8;
    unsigned int wac;
    unsigned char padb0[0x181 - 0xb0];
    unsigned char b181;
    unsigned char b182;
    unsigned char b183;
    unsigned char b184;
    unsigned char b185;
    unsigned char b186;
    unsigned char pad187[0x1b4 - 0x187];
    unsigned char b1b4;
};
struct Rcff4 {
    unsigned char pad[0xa];
    unsigned short h0a;
};
extern struct R290 DAT_a802d290;
#define DAT_a802cff4 (*(struct Rcff4 *)0xa802cff4)
extern unsigned char DAT_a802b08e;
extern int FUN_a00df170(const char *fmt, ...);
extern unsigned char FUN_a0083d80(void);
extern unsigned char FUN_a014448c(int);
extern unsigned char FUN_a01445fc(unsigned char);
extern unsigned char FUN_a014bd70(int);
extern unsigned char FUN_a01438dc(int);
extern unsigned char FUN_a014ba68(void);

static int chk(void)
{
    if (FUN_a014bd70(0) == 1)
        return 1;
    if (FUN_a01438dc(0) == 1) {
        switch (FUN_a014ba68()) {
        case 1: return 1;
        case 2: return 1;
        case 3: return 1;
        case 4: return 1;
        }
    }
    return 0;
}

static int cec_ok(unsigned char m)
{
    if (!(DAT_a802d290.wac & 0x100000))
        return 0;
    if (DAT_a802d290.b1f != 0)
        return 0;
    if (m > 2)
        return 0;
    if (FUN_a01445fc(FUN_a014448c(0)))
        return 0;
    return 1;
}

void FUN_a00da4b8(void)
{
    unsigned char m = FUN_a0083d80();

    DAT_a802d290.b1b4 = m;
    if (cec_ok(m)) {
        unsigned char y, x;

        y = DAT_a802d290.b184;
        x = DAT_a802d290.b183;
        DAT_a802d290.wa8.b11 = DAT_a802d290.wa8.b10;
        DAT_a802d290.b182 = y;
        DAT_a802cff4.h0a |= 0x80;
        DAT_a802d290.b181 = x;
        if (chk() && (unsigned char)(DAT_a802d290.b181 - 4) <= 2) {
            DAT_a802d290.b181 = 7;
            DAT_a802d290.b183 = 7;
            DAT_a802b08e |= 2;
        }
    } else {
        unsigned char y, x;

        y = DAT_a802d290.b186;
        x = DAT_a802d290.b185;
        DAT_a802d290.wa8.b11 = DAT_a802d290.wa8.b9;
        DAT_a802d290.b182 = y;
        DAT_a802cff4.h0a &= ~0x80;
        DAT_a802d290.b181 = x;
    }
    FUN_a00df170("\x1b[1;35mUserGetCECSourceMode %x(%x)%x,%x\r\n\x1b[m", DAT_a802d290.b1b4,
                 DAT_a802d290.wa8.b11, DAT_a802d290.b182, DAT_a802d290.b181);
}
