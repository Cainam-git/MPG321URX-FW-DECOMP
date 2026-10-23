/* FUN_a0091578 (leon2s 0xa0091578-0xa00916a8, 304 bytes), flags -mcpu=v8 -Os -g.
 * Calls FUN_a0091540(port), then sets fields of the 0x1c-byte record ARR_a807d580[port] (bit numbers count from
 * the least significant bit of each word): word +0: bits 30, 4..2, 29, 1..0, 15..8 and 7..6 cleared, bit 5 set;
 * word +4: bit 31 cleared; word +8 = 0x94; word +0xc: bit 31 and bytes +0xd, +0xe, +0xf cleared; word +0x10:
 * bit 7 set, bits 6..3, 31, 2..0 and byte +0x12 cleared, byte +0x11 = 8; word +0x14: bits 31, 30, 14, 15,
 * 13, 12 cleared, byte +0x15 = 5, bit 11 set. Clears bytes +5, +6 and +7 of DAT_a8079538.
 * Source form: every field is a bit-field (big-endian, first field = most significant bit) assigned in its
 * own statement; the three DAT_a8079538 byte clears come before the last two field writes.
 */
struct Rec1c {
    /* +0x00 */
    unsigned int w0_31 : 1, w0_30 : 1, w0_29 : 1, : 13, w0_b2 : 8, w0_76 : 2, w0_5 : 1, w0_42 : 3, w0_10 : 2;
    /* +0x04 */
    unsigned int w1_31 : 1, : 31;
    /* +0x08 */
    unsigned int w2;
    /* +0x0c */
    unsigned int w3_31 : 1, : 7, w3_b1 : 8, w3_b2 : 8, w3_b3 : 8;
    /* +0x10 */
    unsigned int w4_31 : 1, : 7, w4_b1 : 8, w4_b2 : 8, w4_7 : 1, w4_63 : 4, w4_20 : 3;
    /* +0x14 */
    unsigned int w5_31 : 1, w5_30 : 1, : 6, w5_b1 : 8, w5_15 : 1, w5_14 : 1, w5_13 : 1, w5_12 : 1, w5_11 : 1, : 11;
    /* +0x18 */
    unsigned int w6;
};
extern struct Rec1c ARR_a807d580[];
extern unsigned char DAT_a8079538[];
extern void FUN_a0091540(unsigned char);

void FUN_a0091578(unsigned char port)
{
    FUN_a0091540(port);
    ARR_a807d580[port].w0_30 = 0;
    ARR_a807d580[port].w0_5 = 1;
    ARR_a807d580[port].w0_42 = 0;
    ARR_a807d580[port].w4_7 = 1;
    ARR_a807d580[port].w4_63 = 0;
    ARR_a807d580[port].w4_b1 = 8;
    ARR_a807d580[port].w3_31 = 0;
    ARR_a807d580[port].w4_31 = 0;
    ARR_a807d580[port].w4_b2 = 0;
    ARR_a807d580[port].w3_b1 = 0;
    ARR_a807d580[port].w3_b3 = 0;
    ARR_a807d580[port].w3_b2 = 0;
    ARR_a807d580[port].w0_29 = 0;
    ARR_a807d580[port].w0_10 = 0;
    ARR_a807d580[port].w1_31 = 0;
    ARR_a807d580[port].w2 = 0x94;
    ARR_a807d580[port].w0_b2 = 0;
    ARR_a807d580[port].w0_76 = 0;
    ARR_a807d580[port].w5_31 = 0;
    ARR_a807d580[port].w5_30 = 0;
    ARR_a807d580[port].w5_14 = 0;
    ARR_a807d580[port].w5_b1 = 5;
    ARR_a807d580[port].w5_15 = 0;
    ARR_a807d580[port].w5_13 = 0;
    ARR_a807d580[port].w5_12 = 0;
    DAT_a8079538[5] = 0;
    DAT_a8079538[6] = 0;
    DAT_a8079538[7] = 0;
    ARR_a807d580[port].w4_20 = 0;
    ARR_a807d580[port].w5_11 = 1;
}
