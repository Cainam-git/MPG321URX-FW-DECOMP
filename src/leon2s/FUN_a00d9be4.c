/* leon2s FUN_a00d9be4 @ 0xa00d9be4-0xa00d9d50 (364 bytes, 91 words)
 * Flags: -mcpu=v8 -Os -g.
 * void(void). idx = DAT_a8078832. It returns when the byte tables DAT_a8078830[idx] and DAT_a8078828[idx]
 * are equal. v = FUN_a00d7cd0() & 0xff (the callee returns a u8; the firmware re-masks it into a u32),
 * m = v & 0xe0. m == 0x80: nothing happens. m == 0x40: DAT_a8078828[idx] = (v + 1) & 0xf. Any other m: a
 * 20-byte local block is filled by FUN_a00d6890(&s, 0, 1). Bit 13 of its word +16 is cleared at entry (word
 * ld/andn/st) and read back after the call as a 16-bit field at bits 8..23 (srl 8; btst 0x20), so word +16
 * is a union of a plain word and that bit-field. Return when that bit is clear. lo = (w0 >> 24) & 0xf,
 * hi = w0 >> 28 (plain u32 shifts; with bit-fields the compare becomes signed 'bl', the firmware has 'bcs').
 * lo == 0: a copy of 0x13 bytes with func_0xa0fc15d8 (returns void *) into a block-local buffer,
 * FUN_a00d9524(buf), FUN_a00d9698(). lo >= hi: the same into a 2nd buffer, then the store if idx != 0.
 * Otherwise a 3rd buffer: FUN_a00d97bc(buf), FUN_a00d985c(). Then DAT_a8078828[idx] = (v + 1) & 0xf.
 * m != 0x80 && m != 0x40 is the first arm (the firmware ANDs the two '!=' values with btst).
 * The flag is cleared in the word, and the three copies use separate buffers. No volatile.
 */
struct Msg {
    unsigned int w0;
    unsigned int w[3];
    union { unsigned int w; struct { unsigned int x:8; unsigned int flags:16; unsigned int y:8; } b; } u4;
};
extern unsigned char DAT_a8078832;
extern unsigned char DAT_a8078830[];
extern unsigned char DAT_a8078828[];
extern unsigned char FUN_a00d7cd0(void);
extern void FUN_a00d6890(struct Msg *, int, int);
extern void FUN_a00d9524(unsigned char *);
extern void FUN_a00d9698(void);
extern void FUN_a00d97bc(unsigned char *);
extern void FUN_a00d985c(void);
extern void *func_0xa0fc15d8(void *, const void *, unsigned int);

void FUN_a00d9be4(void)
{
    struct Msg s;
    unsigned int v;
    unsigned int m;
    unsigned int lo;

    s.u4.w &= ~0x2000;
    if (DAT_a8078830[DAT_a8078832] == DAT_a8078828[DAT_a8078832])
        return;
    v = FUN_a00d7cd0() & 0xff;
    m = v & 0xe0;
    if (m != 0x80 && m != 0x40) {
        FUN_a00d6890(&s, 0, 1);
        if ((s.u4.b.flags & 0x20) == 0)
            return;
        lo = s.w0 >> 24 & 0xf;
        if (lo == 0) {
            unsigned char b1[0x13];
            func_0xa0fc15d8(b1, &s, 0x13);
            FUN_a00d9524(b1);
            FUN_a00d9698();
        } else {
            if (lo >= s.w0 >> 28) {
                unsigned char b2[0x13];
                func_0xa0fc15d8(b2, &s, 0x13);
                FUN_a00d9524(b2);
                FUN_a00d9698();
                if (DAT_a8078832 != 0)
                    goto store;
            }
            {
                unsigned char b3[0x13];
                func_0xa0fc15d8(b3, &s, 0x13);
                FUN_a00d97bc(b3);
                FUN_a00d985c();
            }
        }
    store:
        DAT_a8078828[DAT_a8078832] = (v + 1) & 0xf;
    } else if (m == 0x40) {
        DAT_a8078828[DAT_a8078832] = (v + 1) & 0xf;
    }
}
