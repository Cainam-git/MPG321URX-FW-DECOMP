/* leon2m FUN_a0140360 @ 0xa0140360..0xa0140500 (104 words), BYTE-EXACT: -mcpu=v8 -O3 -g (also
 * -msoft-float), jf 100.00 match=True, rawcmp 0/104, exact.py None.
 *
 * What it does, in plain words: "read len bytes of settings storage device 'dev' starting at offset addr into buf".
 * It is the settings-read wrapper used by FUN_a0153c74 (start-up settings check) and by
 * FUN_a012cfac (FGA_Init). It looks up the 38-byte ROM record DAT_001a69fe[dev] (byte 0 = b0, the storage kind):
 *  - b0 bit 7 CLEAR: an I2C storage chip. The 10-byte bus descriptor DAT_001a69e0[b0] (5 u16: pins / device / mode)
 *    is copied to the stack and func_0x4008bb28(&desc, addr, len, buf) does the read (= FUN_a002bb28 in the RAM
 *    piece, byte-exact: bit-banged I2C random read, bounded except FUN_a002ab04's late-ACK loop).
 *  - b0 bit 7 SET: a memory-mapped area (no bus traffic). base = D[b0].h0 + (b1 << 11) + E[dev].h0 when the area
 *    record A36[b0].b2 != 0, else D[b0].h0 (+ D[b0].b8 * (rec.b4 << 8) unless b8 == 0xFF); then len bytes are copied
 *    from CPU address 0x00000000 + base + addr (DAT_00000000, the flash window) into buf. (D = DAT_a802cbdc 12-byte
 *    rows, E = DAT_a802cc00 4-byte rows, A36 = ROM DAT_001a6a24, all set up by FUN_a01400e0.)
 * The only loop is the copy loop bounded by len; no return value (void, the fw ends both paths with 'ret; restore',
 * the call result is dropped). Every wait is in FUN_a002bb28 and below.
 * ROM data (FW.021): record 0 at ROM 0x1A69FE (file 0x2AE9FE) = 00 00 00 80 00 "DG_EEPROM1" (b0 = 0 -> the I2C
 * path), bus descriptor 0 at ROM 0x1A69E0 = 06 80 06 40 00 04 A0 02 80 00 (as noted in FUN_a002bb28).
 *
 * Exact-form levers (gcc 3.4.4 -O3, all are plain C, no aids):
 *  1. 'goto out;' at the end of the flash arm. The GOTO branch predictor (c-semantics.c PRED_GOTO) makes the
 *     flash arm less probable (-dl dump: flash-arm block freq / entry block freq 1719/4490 = 38% -> 1719/8185 = 21%;
 *     the copy loop stays the hottest block = 10000, so the entry block's weight rises). Global-alloc priority
 *     (global.c allocno_compare = floor_log2(refs) * freq / live_length, computed from the dump): the
 *     dev*0x26 product (3 of its 5 refs in the entry block) goes 933 -> 1575, above b (zero-extended b0, 7 refs in
 *     the flash arm, 1137 / 1218). Allocation order then becomes product -> o3, b -> o1, record base 0x1A69FE -> o0,
 *     dev -> o2 = the fw. (The competitor for o3 is b, not the record base: the -dg order is
 *     216 122 131(b) 115 121(product) ... 118(base).)
 *  2. Term order 'D[b].h0 + (b1 << 11) + E[dev].h0' in the kind != 0 arm: the RTL order decides regrename's chain
 *     order (-frename-registers, least-recently-used tick), which gives the record address o3 and b*2 o4 in that
 *     arm; then reorg sees the same 'add b, b, %o4' in both kind arms and puts it unannulled in the 'be' delay slot.
 *  3. Copy loop: 'k = i; ... buf[i] = p[k];' with an unsigned int k. A u16 index expands as (zero_extend i), and
 *     simplify-rtx canonical order (commutative_operand_precedence: a non-object before a REG) puts it FIRST, giving
 *     'ldub [i + p]'; a REG index keeps 'ldub [p + i]' as in the fw, while the store keeps '[i + buf]'. 'p =
 *     DAT_00000000 + off; p += addr;' inside the loop gives the fw hoist order (window + off) + addr.
 * Effect of the levers: 51.43 with the copy loop shape alone, 85.71 with lever 1, 96.15 with lever 2, 100 with
 * lever 3.
 */
struct B38 { unsigned char b0, b1; unsigned short h2; unsigned char b4; char name[33]; };
struct A36 { unsigned short h0; unsigned char b2, b3; char name[32]; };
struct D12 { unsigned short h0; unsigned short h2; int w4; unsigned char b8, b9; unsigned char pad[2]; };
struct E4 { unsigned short h0; unsigned char b2, b3; };
struct Bus { unsigned short h[5]; };
extern const struct B38 DAT_001a69fe[];   /* ROM storage-device records, 38 bytes each */
extern const struct A36 DAT_001a6a24[];   /* ROM area records, 36 bytes each */
extern const struct Bus DAT_001a69e0[];   /* ROM I2C bus descriptors, 10 bytes each */
extern struct D12 DAT_a802cbdc[];         /* RAM area table (FUN_a01400e0) */
extern struct E4 DAT_a802cc00[];          /* RAM per-device offsets (FUN_a01400e0) */
extern const unsigned char DAT_00000000[]; /* CPU address 0: flash window */
extern void func_0x4008bb28(struct Bus *, unsigned short, unsigned short, unsigned char *); /* FUN_a002bb28 */

/* memory-mapped read: copy len bytes from the flash window at off + addr (inlined into FUN_a0140360) */
static void flash_copy(unsigned int off, unsigned short addr, unsigned short len, unsigned char *buf)
{
    unsigned short i;
    const unsigned char *p;
    unsigned int k;
    for (i = 0; i < len; i++) {
        k = i;
        p = DAT_00000000 + off;
        p += addr;
        buf[i] = p[k];
    }
}

void FUN_a0140360(unsigned char dev, unsigned short addr, unsigned short len, unsigned char *buf)
{
    struct Bus d;
    unsigned char b;
    unsigned short base;

    if ((signed char)DAT_001a69fe[dev].b0 < 0) {
        b = DAT_001a69fe[dev].b0;
        if (DAT_001a6a24[b].b2 == 0) {
            base = DAT_a802cbdc[b].b8 == 0xff ? DAT_a802cbdc[b].h0
                 : DAT_a802cbdc[b].b8 * (DAT_001a69fe[dev].b4 << 8) + DAT_a802cbdc[b].h0;
        } else
            base = DAT_a802cbdc[b].h0 + (DAT_001a69fe[dev].b1 << 11) + DAT_a802cc00[dev].h0;
        flash_copy(base, addr, len, buf);
        goto out;
    }
    b = DAT_001a69fe[dev].b0;
    d = DAT_001a69e0[b];
    func_0x4008bb28(&d, addr, len, buf);
out:
    ;
}
