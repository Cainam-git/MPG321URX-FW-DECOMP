/* leon2s FUN_a008f4d0 @ 0xa008f4d0-0xa008f4ec (7 words), flags -mcpu=v8 -Os -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp_l2s.py 0/7 mismatches.
 * Code facts: leaf; returns 1 when the (u8) port is 1, else 0 (fw: cmp 1; bne; clr / mov 1; retl with 'and 1').
 * Caller FUN_a00908d0 (RX status poll, LINK_STANDBY state 5) passes this flag to FUN_a007517c, which gates the
 * "no AVI InfoFrame for > 0x32 ticks" flag rec+0xac; LINK_STANDBY also calls it at entry.
 * Matching form: the accepted 0/1 u8 flag lever 'u8 r = 0; if (...) r = 1; return r & 1;' (fw 'and 1' at the join).
 * Aids: none.
 */
unsigned char FUN_a008f4d0(unsigned char port)
{
    unsigned char r = 0;
    if (port == 1)
        r = 1;
    return r & 1;
}
