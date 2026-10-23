/* leon2m FUN_a012cfac @ 0xa012cfac..0xa012d4f8 (339 words) "FGA_Init", start-up step 2 (FUN_a015266c)
 * (after WAIT 3 FUN_a0136fc4, before FUN_a0141964).
 * Flags -mcpu=v8 -O3 -g -msoft-float (without -msoft-float it does not match; see item 3 below).
 * In plain words: at every power-on this checks one marker byte in the EEPROM that says "the FGA colour
 * defaults were written". If the marker is 0x77..0x7A it returns at once and writes nothing. Otherwise it writes the
 * default FGA tables into the EEPROM and finally the marker 0x77, so the next boot skips the writes.
 * What it does (code facts):
 *  - saved = FUN_a00fe47c() (u16: (reg 0xCF009BB4 << 8) | reg 0xCF009BB8, a plain register read); print "FGA_Init".
 *  - Location of the FGA block, from the RAM copy of the settings record S (0xA802E1A0, loaded by FUN_a0153c74):
 *    dev = byte S[0x34], addr = u16 S[0x35..0x36] (bitfield in the word at +0x34), sel = byte S[0x37].
 *    fga_off(sub) = ((sel <= 1 ? 0x120 : 0x240) & 0x360) + sub. FW.021 ROM defaults: dev 0, addr 0x0500, sel 1 ->
 *    marker at EEPROM 0x620.
 *  - Reads ONE marker byte: FUN_a0140360(dev, addr + fga_off(0), 1, &mark). If mark - 0x77 <= 3 (0x77..0x7A):
 *    return, no write (0xA012D024 -> 0xA012D4F0).
 *  - Else print "Load Default FGA %02X" (mark) and write defaults, all through FUN_a0140e74 (flag 0):
 *     1. 27 bytes (col[], 3 rows of 9) at addr + fga_off(0x10): for each set bit of 0x92 (bits 0x02, 0x10, 0x80)
 *        a colour triple from the RAM P block 0xA802E1F0 (0x02 -> P[6..8], 0x10 -> P[9..0xB], 0x80 -> P[0x12..0x14];
 *        the switch also has 0x20, 0x40, 0x100 arms and FF FF FF as default) goes to column pos (0, 3, 6) of all
 *        three rows.
 *     2. 54 bytes (3 rows of 18) at addr + fga_off(0x30): for each set bit of 7, an 18-byte ROM row: bit 0x01 ->
 *        0x1A4F70, 0x02 -> 0x1A4F58, 0x04 -> 0x1A4F40 (the switch has arms for all 8 bits of the byte; the other
 *        arms and the default all give 0x1A4F70).
 *     3. for each set bit of 0x508 (0x008, 0x100, 0x400), at addr + off (off from 0): if sel <= 1 and bit != 0x200:
 *        0x008 -> 0x1A5108, 0x100 -> 0x1A50A8, 0x400 -> 0x1A5048 (0x60 bytes each, off += 0x60); else two 0x60-byte
 *        tables 0x1A4FE8 and 0x1A4F88 (off += 0x60 after each). FW.021 (sel 1): addr + 0x000 / 0x060 / 0x0C0, so the
 *        three tables end exactly at addr + 0x120 (= 3 x 0x60; sel > 1: 6 x 0x60 = 0x240).
 *     4. FUN_a00fe44c(saved | 0x10) (registers 0xCF009BB4 / 0xCF009BB8 written back with bit 4 of the low byte set),
 *        FUN_a010af50() (clears bit 3 of 0xCF00EAC8), then marker 0x77 at addr + fga_off(0) (1 byte), then
 *        FUN_a01405d0(dev) (returns at once for a dev whose ROM record b0 bit 7 is clear, i.e. FW.021 dev 0).
 * Can it wait or fail? Its own loops run over constant bit masks and fixed lengths: all bounded.
 * The waits are in the callees: the marker read (FUN_a0140360 -> FUN_a002bb28, bounded except FUN_a002ab04's
 * late-ACK
 * loop), and on the default path every FUN_a0140e74 chunk (27 B = 2 chunks, 54 B = 4, 3 x 0x60 = 18, marker 1: 25
 * chunks for sel <= 1) ends in the ready poll 'while (!FUN_a002be7c(dev)) ;' that has NO counter.
 * Write errors are not seen (FUN_a0140e74 ignores them). The marker is written LAST, so an interrupted default load
 * is redone at the next boot.
 * FW.012 has the same function; it differs only in the %lo parts of moved string and RAM addresses.
 * Source forms and compiler aids (no code emitted): (1) the column stride is a local 'int n = 9' and the store is
 * col[pos + k * n + j], which gives the fw's 'smul k, 9' (a literal 9 is always synthesized as sll 3 + add), and
 * 'pos + ...' first lets the loop pass hoist fp-8 + pos as in the fw.
 * (2) loop-2 switch arms for every bit 0x01..0x80 (5 of them = 0x1A4F70, same as default) give the fw's compare
 * tree (root 8, 'cmp 2; ble', right root 0x20); fewer arms drop the tree nodes, 7 arms below 0x80 give a jump table.
 * (3) -msoft-float: in the -dL loop dump the 0x1A4F58 / 0x1A4F40 sethi are then 'not desirable' and only the
 * 0x1A4F70 sethi (7 uses) is hoisted, as in the fw; with hard float all three are hoisted. loop.c's
 * threshold counts non-fixed registers, and -msoft-float makes the FP registers fixed.
 * (4) loop 3: the 'sel <= 1 && !(bit & 0x200)' arm written FIRST (arm order decides block order /
 * registers), off += 0x60 after each of the two tables (gives the fw's (off + 0x60) + addr and the merged off +=
 * 0xC0).
 * (5) 'bits = .., bit = 1' in the for-init (bits set first, as in the fw); loop 2 uses u8 bits / bit (fw btst 0xff).
 * (6) frame 208 with rgb[3], col, rows declared first and the scalar mark after them; fga_off() a static
 * helper with if/else so the '& 0x360' survives; addr + fga_off(sub) keeps the fw's (base + sub) + addr order.
 */
struct FgaLoc { unsigned char dev; unsigned int addr : 16; unsigned char sel; };
struct Rec1a0 { unsigned char a[0x34]; struct FgaLoc fga; unsigned char rest[0x18]; };
extern struct Rec1a0 DAT_a802e1a0;
extern unsigned char DAT_a802e1f0[];
extern const unsigned char DAT_001a4f40[], DAT_001a4f58[], DAT_001a4f70[];
extern const unsigned char DAT_001a4f88[], DAT_001a4fe8[], DAT_001a5048[], DAT_001a50a8[], DAT_001a5108[];
extern char s_001a51c8[], s_001a51d8[];
extern unsigned short FUN_a00fe47c(void);
extern void FUN_a00fe44c(unsigned short);
extern void FUN_a010af50(void);
extern int FUN_a00df170(const char *, ...);
extern void FUN_a0140360(unsigned char, unsigned short, unsigned short, void *);
extern void FUN_a0140e74(unsigned char, unsigned short, unsigned short, void *, unsigned char);
extern void FUN_a01405d0(unsigned char);

static unsigned short fga_off(unsigned short sub)
{
    unsigned short o;
    if (DAT_a802e1a0.fga.sel <= 1)
        o = 0x120;
    else
        o = 0x240;
    return (o & 0x360) + sub;
}

void FUN_a012cfac(void)
{
    unsigned char rgb[3];
    unsigned char col[27];
    unsigned char rows[3][18];
    unsigned char mark = 0;
    unsigned char row;
    unsigned short pos;
    unsigned char k;
    unsigned short saved, base, bits, bit, off;
    unsigned char bits8, bit8;
    int n = 9;
    const unsigned char *p;

    saved = FUN_a00fe47c();
    FUN_a00df170(s_001a51c8);
    base = fga_off(0);
    FUN_a0140360(DAT_a802e1a0.fga.dev, DAT_a802e1a0.fga.addr + base, 1, &mark);
    if ((unsigned char)(mark - 0x77) <= 3)
        return;
    FUN_a00df170(s_001a51d8, mark);

    pos = 0;
    row = 0;
    for (bits = 0x92, bit = 1; bits != 0; bits &= ~bit) {
        while (!(bits & bit))
            bit <<= 1;
        switch (bit) {
        case 0x02: rgb[0] = DAT_a802e1f0[6]; rgb[1] = DAT_a802e1f0[7]; rgb[2] = DAT_a802e1f0[8]; break;
        case 0x10: rgb[0] = DAT_a802e1f0[9]; rgb[1] = DAT_a802e1f0[0xa]; rgb[2] = DAT_a802e1f0[0xb]; break;
        case 0x20: rgb[0] = DAT_a802e1f0[0xc]; rgb[1] = DAT_a802e1f0[0xd]; rgb[2] = DAT_a802e1f0[0xe]; break;
        case 0x40: rgb[0] = DAT_a802e1f0[0xf]; rgb[1] = DAT_a802e1f0[0x10]; rgb[2] = DAT_a802e1f0[0x11]; break;
        case 0x80: rgb[0] = DAT_a802e1f0[0x12]; rgb[1] = DAT_a802e1f0[0x13]; rgb[2] = DAT_a802e1f0[0x14]; break;
        case 0x100: rgb[0] = DAT_a802e1f0[0x15]; rgb[1] = DAT_a802e1f0[0x16]; rgb[2] = DAT_a802e1f0[0x17]; break;
        default: rgb[0] = 0xff; rgb[1] = 0xff; rgb[2] = 0xff; break;
        }
        for (k = 0; k < 3; k++) {
            col[pos + k * n + 0] = rgb[0];
            col[pos + k * n + 1] = rgb[1];
            col[pos + k * n + 2] = rgb[2];
        }
        pos += 3;
    }
    FUN_a0140e74(DAT_a802e1a0.fga.dev, DAT_a802e1a0.fga.addr + fga_off(0x10), 0x1b, col, 0);


    for (bits8 = 7, bit8 = 1; bits8 != 0; bits8 &= ~bit8) {
        while (!(bits8 & bit8))
            bit8 <<= 1;
        switch (bit8) {
        case 0x01: p = DAT_001a4f70; break;
        case 0x02: p = DAT_001a4f58; break;
        case 0x04: p = DAT_001a4f40; break;
        case 0x08: p = DAT_001a4f70; break;
        case 0x10: p = DAT_001a4f70; break;
        case 0x20: p = DAT_001a4f70; break;
        case 0x40: p = DAT_001a4f70; break;
        case 0x80: p = DAT_001a4f70; break;
        default: p = DAT_001a4f70; break;
        }
        for (k = 0; k < 18; k++)
            rows[row][k] = p[k];
        row++;
    }
    FUN_a0140e74(DAT_a802e1a0.fga.dev, DAT_a802e1a0.fga.addr + fga_off(0x30), 0x36, rows, 0);

    off = 0;
    for (bits = 0x508, bit = 1; bits != 0; bits &= ~bit) {
        while (!(bits & bit))
            bit <<= 1;
        if (DAT_a802e1a0.fga.sel <= 1 && !(bit & 0x200)) {
            if (bit & 0x008) {
                FUN_a0140e74(DAT_a802e1a0.fga.dev, DAT_a802e1a0.fga.addr + off, 0x60, (void *)DAT_001a5108, 0);
                off += 0x60;
            } else if (bit & 0x100) {
                FUN_a0140e74(DAT_a802e1a0.fga.dev, DAT_a802e1a0.fga.addr + off, 0x60, (void *)DAT_001a50a8, 0);
                off += 0x60;
            } else if (bit & 0x400) {
                FUN_a0140e74(DAT_a802e1a0.fga.dev, DAT_a802e1a0.fga.addr + off, 0x60, (void *)DAT_001a5048, 0);
                off += 0x60;
            }
        } else {
            FUN_a0140e74(DAT_a802e1a0.fga.dev, DAT_a802e1a0.fga.addr + off, 0x60, (void *)DAT_001a4fe8, 0);
            off += 0x60;
            FUN_a0140e74(DAT_a802e1a0.fga.dev, DAT_a802e1a0.fga.addr + off, 0x60, (void *)DAT_001a4f88, 0);
            off += 0x60;
        }
    }
    FUN_a00fe44c(saved | 0x10);
    FUN_a010af50();
    mark = 0x77;
    FUN_a0140e74(DAT_a802e1a0.fga.dev, DAT_a802e1a0.fga.addr + base, 1, &mark, 0);
    FUN_a01405d0(DAT_a802e1a0.fga.dev);
}
