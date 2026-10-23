/*
 * FUN_a00d7e6c (leon2s, 0xa00d7e6c-0xa00d82c8, 1116 bytes), flags -mcpu=v8 -Os -g.
 * void (void). Builds a 120-byte message on the stack and passes it with FUN_a00d791c(&m, 2, 1, 0, len).
 * Message layout: word 0 bit-fields (bit 31, id = bits 24..30); bytes 1..16; then 20-byte records rec[k]
 * from byte 16, each a bit-field word (top byte = last data byte of the part before; f20 = bits 20..23,
 * f16 = bits 16..19, b15, f12 = bits 12..14, f8 = bits 8..11, b7, b6, b5), byte +4 = n and 16 data bytes at
 * +5..+20 (written through the byte view m.b).
 * - id = 1; bytes 1..16 = low bytes of the registers DAT_a00b383c[15 + i] of the block
 *   DAT_a80760a4[DAT_a8078832].
 * - count = DAT_a80760ac + 2 when DAT_a8078832 == 0, else 2; rec[0].f16 = count; len = 0x12.
 * - For k < count: k == 0: rec[0] b15 = 1, f12 = 1, f8 = 0, b7 = b6 = 1, len += 2. k == 1: rec[1] b15 = 0,
 *   f12 = 3, f8 = 8, b7 = 0, b6 = 1, n = register DAT_a00b383c[101], data = registers DAT_a00b383c[15 + i];
 *   rec[2].f20 = 1, f16 = 2; len += 0x14. k == 2 with DAT_a807883f != 0: func_0xa0f96400(0, 0x90, 0 / 0x21,
 *   0, buf) give DAT_a8078846 and DAT_a8078843; b15 = 0, f8 = 1, f12 = 3 (DAT_a8078846 < 0x12) or 2,
 *   b7 = bit 0 of DAT_a8078843, b6 = 1, b5 = 0, n = DAT_a8078846, data = 16 bytes of
 *   func_0xa0f96400(0, 0x90, 0x30, 0xf, buf); rec[3].f20 = f16 = 0; sets bit 0 of register DAT_a00b383c[5];
 *   len += 0x14. k == 2 with DAT_a807883f == 0: b15 = 0, f12 = 0, f8 = 1, b7 = b6 = b5 = 0, n = 0, data
 *   cleared, rec[3].f20 = f16 = 0, clears bit 0 of register DAT_a00b383c[5]; len += 0x14.
 * - After the call: DAT_a8078840 = 1, _DAT_a80787f8 = 0.
 * Source forms: DAT_a8078832 is read into a local for the first block; later blocks index
 * DAT_a80760a4[DAT_a8078832] directly; the count is an unsigned int compared as unsigned short; records
 * are indexed with the variable k; 'len += 0x14' is written in each arm of the k == 2 test (one add after
 * merging; the extra references give len its register).
 */
struct Rec {
    unsigned int top : 8;
    unsigned int f20 : 4;
    unsigned int f16 : 4;
    unsigned int b15 : 1;
    unsigned int f12 : 3;
    unsigned int f8 : 4;
    unsigned int b7 : 1;
    unsigned int b6 : 1;
    unsigned int b5 : 1;
    unsigned int f0 : 5;
    unsigned char n;
    unsigned char d[15];
};
union Msg {
    unsigned char b[120];
    struct {
        unsigned int b31 : 1;
        unsigned int id : 7;
        unsigned int r : 24;
        unsigned char pad[12];
        struct Rec rec[5];
    } s;
};
extern unsigned char DAT_a8078832;
extern unsigned char DAT_a807883f;
extern unsigned char DAT_a8078840;
extern unsigned char DAT_a8078843;
extern unsigned char DAT_a8078846;
extern unsigned char DAT_a80760ac;
extern unsigned short _DAT_a80787f8;
extern const unsigned short DAT_a00b383c[];
extern volatile unsigned int *DAT_a80760a4[];
extern int func_0xa0f96400(int, int, int, int, unsigned char *);
extern void FUN_a00d791c(void *, int, int, int, unsigned short);

void FUN_a00d7e6c(void)
{
    unsigned char buf[16];
    union Msg m;
    unsigned char sel;
    volatile unsigned int *t;
    unsigned char i;
    unsigned char k;
    unsigned int n;
    unsigned int len;

    m.s.id = 1;
    sel = DAT_a8078832;
    t = DAT_a80760a4[sel];
    for (i = 0; i < 16; i++)
        m.b[1 + i] = t[DAT_a00b383c[i + 15]];
    if (sel == 0) {
        n = DAT_a80760ac + 2;
        m.s.rec[0].f16 = n;
    } else {
        m.s.rec[0].f16 = 2;
        n = 2;
    }
    len = 0x12;
    for (k = 0; k < (unsigned short)n; k++) {
        if (k == 0) {
            m.s.rec[k].b15 = 1;
            m.s.rec[k].f12 = 1;
            m.s.rec[k].f8 = 0;
            m.s.rec[k].b7 = 1;
            m.s.rec[k].b6 = 1;
            len += 2;
        } else if (k == 1) {
            m.s.rec[k].b15 = 0;
            m.s.rec[k].f12 = 3;
            m.s.rec[k].f8 = 8;
            m.s.rec[k].b7 = 0;
            m.s.rec[k].b6 = 1;
            m.s.rec[k].n = DAT_a80760a4[DAT_a8078832][DAT_a00b383c[101]];
            for (i = 0; i < 16; i++)
                m.b[k * 20 + 21 + i] = DAT_a80760a4[DAT_a8078832][DAT_a00b383c[i + 15]];
            m.s.rec[k + 1].f20 = 1;
            m.s.rec[k + 1].f16 = 2;
            len += 0x14;
        } else if (k == 2) {
            if (DAT_a807883f) {
                func_0xa0f96400(0, 0x90, 0, 0, buf);
                DAT_a8078846 = buf[0];
                func_0xa0f96400(0, 0x90, 0x21, 0, buf);
                DAT_a8078843 = buf[0];
                m.s.rec[k].b15 = 0;
                m.s.rec[k].f8 = 1;
                if (DAT_a8078846 < 0x12)
                    m.s.rec[k].f12 = 3;
                else
                    m.s.rec[k].f12 = 2;
                if (DAT_a8078843 & 1)
                    m.s.rec[k].b7 = 1;
                else
                    m.s.rec[k].b7 = 0;
                m.s.rec[k].b6 = 1;
                m.s.rec[k].b5 = 0;
                m.s.rec[k].n = DAT_a8078846;
                func_0xa0f96400(0, 0x90, 0x30, 0xf, buf);
                for (i = 0; i < 16; i++)
                    m.b[k * 20 + 21 + i] = buf[i];
                m.s.rec[k + 1].f20 = 0;
                m.s.rec[k + 1].f16 = 0;
                DAT_a80760a4[DAT_a8078832][DAT_a00b383c[5]] |= 1;
                len += 0x14;
            } else {
                m.s.rec[k].b15 = 0;
                m.s.rec[k].f12 = 0;
                m.s.rec[k].f8 = 1;
                m.s.rec[k].b7 = 0;
                m.s.rec[k].b6 = 0;
                m.s.rec[k].b5 = 0;
                m.s.rec[k].n = 0;
                for (i = 0; i < 16; i++)
                    m.b[k * 20 + 21 + i] = 0;
                m.s.rec[k + 1].f20 = 0;
                m.s.rec[k + 1].f16 = 0;
                DAT_a80760a4[DAT_a8078832][DAT_a00b383c[5]] &= ~1;
                len += 0x14;
            }
        }
    }
    FUN_a00d791c(&m, 2, 1, 0, len);
    DAT_a8078840 = 1;
    _DAT_a80787f8 = 0;
}
