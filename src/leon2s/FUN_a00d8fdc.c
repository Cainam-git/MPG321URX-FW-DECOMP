/* FUN_a00d8fdc (leon2s 0xa00d8fdc-0xa00d904c, 112 bytes), flags -mcpu=v8 -Os -g.
 * Form of FUN_a00d8f58: clears the first halfword of the response r (fp-16) and of the 8-byte command header h
 * (fp-24), fills r with FUN_a00d73b4(&r, 0, 1, 0x1b), sets header bits 24..30 to 0x24 and bits 20..23 to bits
 * 20..23 of r's first word, and sends h with FUN_a00d791c(&h, 2, 1, 0xb, 2). void.
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
extern void FUN_a00d73b4(void *, int, int, int);
extern void FUN_a00d791c(void *, int, int, int, int);

void FUN_a00d8fdc(void)
{
    union rsp r;
    union hdr h;

    r.h[0] = 0;
    h.h[0] = 0;
    FUN_a00d73b4(&r, 0, 1, 0x1b);
    h.f.type = 0x24;
    h.f.b20 = r.w0.n;
    FUN_a00d791c(&h, 2, 1, 0xb, 2);
}
