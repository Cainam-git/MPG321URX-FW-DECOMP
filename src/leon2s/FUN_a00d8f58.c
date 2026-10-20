/* leon2s FUN_a00d8f58 @ 0xa00d8f58-0xa00d8fdc (33 words), flags -mcpu=v8 -Os -g.
 * Code facts: 260-byte response buffer r (fp-272) cleared by the ROM memset func_0xa0fc15ac(&r, 0, 0x104),
 * filled by FUN_a00d73b4(&r, 0, 1, 0x1a); then an 8-byte command header h (fp-280): bits 24..30 = 0x23
 * and bits 16..19 = bits 20..23 of r's first word (other header bits are left as they were on the stack),
 * sent with FUN_a00d791c(&h, 2, 1, 10, 2). void.
 * Fixes vs the autoc draft (75.76): BIT-FIELDS (big-endian, first field = MSB) for both header fields and
 * the response nibble (fw andn/or sequence); declaration order r before h (frame slots); the ROM memset
 * returns void * (a void prototype moves the 'mov %l0,%o0' out of the call delay slot). Aids: none.
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
union rsp {
    struct rsp_w0 w0;
    unsigned int w[65];
};
extern void *func_0xa0fc15ac(void *, int, unsigned int);
extern void FUN_a00d73b4(void *, int, int, int);
extern void FUN_a00d791c(void *, int, int, int, int);

void FUN_a00d8f58(void)
{
    union rsp r;
    struct cmd_hdr h;

    func_0xa0fc15ac(&r, 0, 0x104);
    FUN_a00d73b4(&r, 0, 1, 0x1a);
    h.type = 0x23;
    h.n = r.w0.n;
    FUN_a00d791c(&h, 2, 1, 10, 2);
}
