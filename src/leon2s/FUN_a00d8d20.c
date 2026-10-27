/* leon2s FUN_a00d8d20 @ 0xa00d8d20-0xa00d8f58 (142 words), flags -mcpu=v8 -Os -g.
 * 30-byte stack response r (fp-40) cleared by func_0xa0fc15ac(&r, 0, 0x1e) and filled by
 * FUN_a00d73b4(&r, 0, 1, 0x19). off (u16) = r.b[17] + 0x100 when bits 16..17 of r's first word are 2,
 * bits 8..14 are 0x30 and r.b[4] == 1; 0 for those bits with r.b[4] != 1; r.b[4] otherwise.
 * Stack command h (fp-304): bits 24..30 = 0x22, bits 16..19 = bits 20..23 of r's first word, byte 2 = r.b[29]
 * (other bits of the first word are left as they were). For (r.b[28] & 0x7f) == 0x50, 0x51 or 0x53, r.b[29]
 * bytes are copied to h.b[3..]: from DAT_9f1b0000[off..] when bits 20..23 of r's first word are not 8,
 * otherwise per byte from DAT_9f1cc8f0[off + i] when func_0xa0fc1494(DAT_a8078832) == 1, else from
 * DAT_9f1cc770[off + i] when a second call returns 2 (no store for other results). For other values the r.b[29]
 * bytes are cleared. Then FUN_a00d791c(&h, 2, 1, 9, h byte 2 + 3). void.
 * Source form: the fields of r's first word as shifts and masks of the word (bit-fields merge the two first
 * tests into one masked compare); bit-fields for the first word of h; the last FUN_a00d791c parameter is
 * unsigned short.
 */
struct cmd_hdr {
    unsigned int b31 : 1;
    unsigned int type : 7;
    unsigned int b20 : 4;
    unsigned int n : 4;
    unsigned int cnt : 8;
    unsigned int lo : 8;
};
union cmd {
    struct cmd_hdr h;
    unsigned char b[0x104];
};
union rsp {
    unsigned int w0;
    unsigned char b[30];
};
extern unsigned char DAT_a8078832;
extern const unsigned char DAT_9f1b0000[];
extern const unsigned char DAT_9f1cc8f0[];
extern const unsigned char DAT_9f1cc770[];
extern void *func_0xa0fc15ac(void *, int, unsigned int);
extern unsigned char func_0xa0fc1494(unsigned char);
extern void FUN_a00d73b4(void *, int, int, int);
extern void FUN_a00d791c(void *, int, int, int, unsigned short);

void FUN_a00d8d20(void)
{
    union rsp r;
    union cmd h;
    unsigned short off;
    unsigned char i;
    unsigned char c;

    func_0xa0fc15ac(&r, 0, 0x1e);
    FUN_a00d73b4(&r, 0, 1, 0x19);
    off = 0;
    if (((r.w0 >> 16) & 3) == 2 && ((r.w0 >> 8) & 0x7f) == 0x30) {
        if (r.b[4] == 1)
            off = r.b[17] + 0x100;
    } else
        off = r.b[4];
    h.h.type = 0x22;
    h.h.n = (r.w0 >> 20) & 0xf;
    h.h.cnt = r.b[29];
    c = r.b[28] & 0x7f;
    if (c == 0x50 || c == 0x51 || c == 0x53) {
        if (((r.w0 >> 16) & 0xf0) != 0x80) {
            for (i = 0; i < r.b[29]; i++)
                h.b[3 + i] = DAT_9f1b0000[off + i];
        } else {
            for (i = 0; i < r.b[29]; i++) {
                if (func_0xa0fc1494(DAT_a8078832) == 1)
                    h.b[3 + i] = DAT_9f1cc8f0[off + i];
                else if (func_0xa0fc1494(DAT_a8078832) == 2)
                    h.b[3 + i] = DAT_9f1cc770[off + i];
            }
        }
    } else {
        for (i = 0; i < r.b[29]; i++)
            h.b[3 + i] = 0;
    }
    FUN_a00d791c(&h, 2, 1, 9, h.h.cnt + 3);
}
