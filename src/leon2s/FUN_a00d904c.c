/* FUN_a00d904c (leon2s 0xa00d904c-0xa00d90dc, 144 bytes), flags -mcpu=v8 -Os -g.
 * Form of FUN_a00d8f58: clears the first halfword of the response r (fp-16) and of the 8-byte command header h
 * (fp-24), fills r with FUN_a00d73b4(&r, 0, 1, 0x1c), sets header bits 24..30 to 0x25 and bits 20..23 to bits
 * 20..23 of r's first word, and sends h with FUN_a00d791c(&h, 2, 1, 0xc, 2). Then sets bit 5 of the word that
 * DAT_a80760a4[DAT_a8078832] points to. void.
 * Source form: bit-fields (big-endian, first field = MSB) as in FUN_a00d8f58; the halfword clears are stores
 * through a halfword view of each union (the firmware uses clrh).
 */
struct cmd_hdr {
    unsigned int b31 : 1;
    unsigned int type : 7;
    unsigned int b20 : 4;
    unsigned int n : 4;
    unsigned int lo : 16;
    unsigned int w1;
};
struct rsp_w0 {
    unsigned int hi : 8;
    unsigned int n : 4;
    unsigned int rest : 20;
};
union rsp { struct rsp_w0 w0; unsigned short h[4]; };
union hdr { struct cmd_hdr f; unsigned short h[4]; };
extern volatile unsigned int *DAT_a80760a4[];
extern unsigned char DAT_a8078832;
extern void FUN_a00d73b4(void *, int, int, int);
extern void FUN_a00d791c(void *, int, int, int, int);

void FUN_a00d904c(void)
{
    union rsp r;
    union hdr h;

    r.h[0] = 0;
    h.h[0] = 0;
    FUN_a00d73b4(&r, 0, 1, 0x1c);
    h.f.type = 0x25;
    h.f.b20 = r.w0.n;
    FUN_a00d791c(&h, 2, 1, 0xc, 2);
    *DAT_a80760a4[DAT_a8078832] |= 0x20;
}
