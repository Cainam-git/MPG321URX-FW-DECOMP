/* FUN_a00d87fc (leon2s 0xa00d87fc-0xa00d8b90, 916 bytes), flags -mcpu=v8 -Os -g. void (void).
 * 12-byte stack response r (word w0, word addr, byte len; zero-initialised) filled by FUN_a00d73b4(&r, 0, 1,
 * 0x17). Stack command h (fp-288): bits 24..30 = 0x20, bits 16..19 = bits 20..23 of r.w0, byte 2 = r.len.
 * When bits 20..23 of r.w0 are 1: the r.len bytes are read in chunks of up to 16 with func_0xa0f96400(0, 0x90,
 * r.addr + off, chunk - 1, &h.b[3 + off]); a chunk whose call returns 0 is cleared. Otherwise r.addr selects a
 * range (0..0xb, 0x30..0x3f, 0x100..0x101, 0x68000..0x6802b, 0xe, 0x60..0x6f, 0x90..0x91, 0x120, 0x160,
 * 0x2200..0x2210) with start off = low bits of r.addr, limit lim and table base: byte i of h.b[3..] is the low byte
 * of word DAT_a00b383c[(base & 0x7f) + off + i] of the register block DAT_a80760a4[DAT_a8078832]; for
 * 0x40..0x4f it is DAT_a80760b8[off + i]; copying stops at r.len bytes or off + i == lim, and the rest of the
 * r.len bytes is cleared. Then FUN_a00d791c(&h, 2, 1, 7, h byte 2 + 3).
 * Source forms the exact build depends on: off is one u16 variable for both the chunk offset and the range
 * start; the copy is a for loop with the condition 'i < len && off + i < lim' (signed first test); the chunk
 * test 'len > 0x10' first; the table index written (base & 0x7f) + off + i and the byte source (src + off)[i].
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
struct rsp {
    unsigned int w0;
    unsigned int addr;
    unsigned char len;
};
extern unsigned char DAT_a8078832;
extern volatile unsigned int *DAT_a80760a4[];
extern const unsigned short DAT_a00b383c[];
extern unsigned char DAT_a80760b8[];
extern void FUN_a00d73b4(void *, int, int, int);
extern unsigned char func_0xa0f96400(unsigned int, unsigned int, unsigned int, signed char, unsigned char *);
extern void FUN_a00d791c(void *, int, int, int, unsigned short);

void FUN_a00d87fc(void)
{
    struct rsp r = {0, 0, 0};
    union cmd h;
    unsigned short len;
    unsigned short off;
    unsigned char chunk;
    unsigned char lim;
    unsigned char base;
    unsigned char flag;
    unsigned char *src;
    unsigned char i;

    FUN_a00d73b4(&r, 0, 1, 0x17);
    h.h.type = 0x20;
    h.h.n = (r.w0 >> 20) & 0xf;
    h.h.cnt = r.len;
    len = r.len;
    base = 0;
    src = 0;
    flag = 0;
    off = 0;
    if ((r.w0 & 0xf00000) == 0x100000) {
        while (len != 0) {
            if (len > 0x10) {
                chunk = 0x10;
                len -= 0x10;
            } else {
                chunk = len;
                len = 0;
            }
            if (func_0xa0f96400(0, 0x90, r.addr + off, chunk - 1, &h.b[3 + off]) == 0) {
                for (i = 0; i < chunk; i++)
                    h.b[3 + off + i] = 0;
            }
            off += chunk;
        }
    } else {
        if (r.addr <= 0xb) {
            off = r.addr & 0xf;
            lim = 0xb;
        } else if (r.addr - 0x30 <= 0xf) {
            off = r.addr & 0xf;
            lim = 0xf;
            base = 0xf;
        } else if (r.addr - 0x100 <= 1) {
            off = r.addr & 0xf;
            lim = 2;
            base = 0x2d;
        } else if (r.addr - 0x68000 <= 0x2b) {
            off = r.addr & 0x2f;
            lim = 0x2c;
            base = 0x79;
        } else if (r.addr == 0xe) {
            lim = 1;
            base = 0xd;
        } else if (r.addr - 0x60 <= 0xf) {
            off = r.addr & 0xf;
            lim = 0x10;
            base = 0x1f;
        } else if (r.addr - 0x90 <= 1) {
            off = r.addr & 0xf;
            lim = 2;
            base = 0x2c;
        } else if (r.addr == 0x120) {
            lim = 1;
            base = 0x40;
        } else if (r.addr == 0x160) {
            lim = 1;
            base = 0x41;
        } else if (r.addr - 0x2200 <= 0x10) {
            off = r.addr & 0x1f;
            lim = 0x11;
            base = 0x65;
        } else {
            lim = 0;
            off = 0;
            if (r.addr - 0x40 <= 0xf) {
                off = r.addr & 0xf;
                src = DAT_a80760b8;
                lim = 0x10;
                flag = 1;
            }
        }
        for (i = 0; i < len && off + i < lim; i++) {
            if (flag == 0)
                h.b[3 + i] = DAT_a80760a4[DAT_a8078832][DAT_a00b383c[(base & 0x7f) + off + i]];
            else
                h.b[3 + i] = (src + off)[i];
        }
        for (; i < len; i++)
            h.b[3 + i] = 0;
    }
    FUN_a00d791c(&h, 2, 1, 7, h.h.cnt + 3);
}
