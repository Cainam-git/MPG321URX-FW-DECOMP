/* leon2s FUN_a00916a8 @ 0xa00916a8-0xa00918ec (145 words, leaf), flags -mcpu=v8 -Os -g.
 * void (u8 port). Record d = ARR_a807d580[port] (7 words), source s = ARR_a807a8fc[port] (0x14 bytes).
 * Returns at once unless bit 2 of d's word 4 is set; then clears that bit and copies fields of s into d:
 * byte s+3 -> d byte 1; halfword s+4 -> d word 2; bytes s+9 -> d+0x11, s+6 -> d+0xd, s+0xa -> d+0xf,
 * s+7 -> d+0xe, s+8 -> d+0x12, s+0xc -> d+0x17; single bits of the halfword s+0 (bit 14 -> word 0 bit 31,
 * 12 -> 30, 11..9 -> 7..5, 13 -> word 3 bit 31, 8 -> word 4 bit 31, 4 -> word 0 bit 1, 7 -> 4, 6 -> 3,
 * 5 -> 2 and word 5 bit 15, 3 -> word 0 bit 0, 2..0 -> word 4 bits 7..5) and of the halfword s+2 (bit 13 ->
 * word 0 bit 29, 15 -> word 4 bit 4, 14 -> word 4 bit 3). Finally, when bit 13 of d's word 5 is clear,
 * bit 4 of d's word 0 is written again from bit 7 of s+0.
 * Source form: bit-fields on both records, written in the firmware's store order; the halfword s+2 is a
 * union of its bit-fields and two bytes (byte s+3 is read with ldub); d's word-4 bit 4 is a _Bool
 * bit-field (the firmware normalises the copied bit with cmp/addx).
 */
struct Dst {
    unsigned int a31 : 1;
    unsigned int a30 : 1;
    unsigned int a29 : 1;
    unsigned int a24 : 5;
    unsigned int a16 : 8;
    unsigned int a8 : 8;
    unsigned int a7 : 1;
    unsigned int a6 : 1;
    unsigned int a5 : 1;
    unsigned int a4 : 1;
    unsigned int a3 : 1;
    unsigned int a2 : 1;
    unsigned int a1 : 1;
    unsigned int a0 : 1;
    unsigned int w1;
    unsigned int w2;
    unsigned int c31 : 1;
    unsigned int c24 : 7;
    unsigned int c16 : 8;
    unsigned int c8 : 8;
    unsigned int c0 : 8;
    unsigned int d31 : 1;
    unsigned int d24 : 7;
    unsigned int d16 : 8;
    unsigned int d8 : 8;
    unsigned int d7 : 1;
    unsigned int d6 : 1;
    unsigned int d5 : 1;
    _Bool d4 : 1;
    unsigned int d3 : 1;
    unsigned int d2 : 1;
    unsigned int d0 : 2;
    unsigned int e16 : 16;
    unsigned int e15 : 1;
    unsigned int e14 : 1;
    unsigned int e13 : 1;
    unsigned int e8 : 5;
    unsigned int e0 : 8;
    unsigned int w6;
};
struct Src {
    unsigned short f15 : 1;
    unsigned short f14 : 1;
    unsigned short f13 : 1;
    unsigned short f12 : 1;
    unsigned short f11 : 1;
    unsigned short f10 : 1;
    unsigned short f9 : 1;
    unsigned short f8 : 1;
    unsigned short f7 : 1;
    unsigned short f6 : 1;
    unsigned short f5 : 1;
    unsigned short f4 : 1;
    unsigned short f3 : 1;
    unsigned short f2 : 1;
    unsigned short f1 : 1;
    unsigned short f0 : 1;
    union {
        struct {
            unsigned short g15 : 1;
            unsigned short g14 : 1;
            unsigned short g13 : 1;
            unsigned short g8 : 5;
            unsigned short g0 : 8;
        } f;
        unsigned char b[2];
    } u2;
    unsigned short h2;
    unsigned char b6;
    unsigned char b7;
    unsigned char b8;
    unsigned char b9;
    unsigned char b10;
    unsigned char b11;
    unsigned char b12;
    unsigned char b13;
    unsigned short h14;
    unsigned short h16;
    unsigned short h18;
};
extern struct Dst ARR_a807d580[];
extern struct Src ARR_a807a8fc[];

void FUN_a00916a8(unsigned char port)
{
    if (!ARR_a807d580[port].d2)
        return;
    ARR_a807d580[port].d2 = 0;
    ARR_a807d580[port].a16 = ARR_a807a8fc[port].u2.b[1];
    ARR_a807d580[port].a31 = ARR_a807a8fc[port].f14;
    ARR_a807d580[port].w2 = ARR_a807a8fc[port].h2;
    ARR_a807d580[port].a30 = ARR_a807a8fc[port].f12;
    ARR_a807d580[port].a7 = ARR_a807a8fc[port].f11;
    ARR_a807d580[port].a6 = ARR_a807a8fc[port].f10;
    ARR_a807d580[port].a5 = ARR_a807a8fc[port].f9;
    ARR_a807d580[port].d16 = ARR_a807a8fc[port].b9;
    ARR_a807d580[port].c31 = ARR_a807a8fc[port].f13;
    ARR_a807d580[port].d31 = ARR_a807a8fc[port].f8;
    ARR_a807d580[port].c16 = ARR_a807a8fc[port].b6;
    ARR_a807d580[port].c0 = ARR_a807a8fc[port].b10;
    ARR_a807d580[port].c8 = ARR_a807a8fc[port].b7;
    ARR_a807d580[port].d8 = ARR_a807a8fc[port].b8;
    ARR_a807d580[port].a29 = ARR_a807a8fc[port].u2.f.g13;
    ARR_a807d580[port].a1 = ARR_a807a8fc[port].f4;
    ARR_a807d580[port].a4 = ARR_a807a8fc[port].f7;
    ARR_a807d580[port].a3 = ARR_a807a8fc[port].f6;
    ARR_a807d580[port].a2 = ARR_a807a8fc[port].f5;
    ARR_a807d580[port].e15 = ARR_a807a8fc[port].f5;
    ARR_a807d580[port].a0 = ARR_a807a8fc[port].f3;
    ARR_a807d580[port].d7 = ARR_a807a8fc[port].f2;
    ARR_a807d580[port].d6 = ARR_a807a8fc[port].f1;
    ARR_a807d580[port].d5 = ARR_a807a8fc[port].f0;
    ARR_a807d580[port].d4 = ARR_a807a8fc[port].u2.f.g15;
    ARR_a807d580[port].d3 = ARR_a807a8fc[port].u2.f.g14;
    ARR_a807d580[port].e0 = ARR_a807a8fc[port].b12;
    if (!ARR_a807d580[port].e13)
        ARR_a807d580[port].a4 = ARR_a807a8fc[port].f7;
}
