/* leon2m FUN_a01542c4 @ 0xa01542c4-0xa015440c (82 words), -mcpu=v8 -O3 -g.
 * What it does: the mode-table STORE (sibling of the lookup FUN_a01541ec). FUN_a013f370 calls it with the channel
 *   record + 6 after a new input timing is applied and FUN_a01541ec found no table row for it (FUN_a0145360 also
 *   calls it per channel). The table is 20 rows of 16 bytes at settings-EEPROM offset 0x300 (I2C device 0,
 *   FUN_a0140360 = read, FUN_a0140e74 = write, 5 args). It reads rows 0..19 into a zeroed local row and stops at the
 *   first row whose u16 +0x0e equals m->h36 (the key). It then fills the row from the mode record: h0 = h08,
 *   h2 = h18, h4 = h1a, h6 = h22, h8 = h24, ha = h26, bc = b20, bd = b34, he = h36. No match: the row index is the
 *   ring index DAT_a802e1a0 byte +0x1a, the ring index becomes (idx + 1) % 20 and the 0x50-byte settings block is
 *   written back (FUN_a0140e74(0, 0x470, 0x50, &DAT_a802e1a0, 0)). Last: the row is written at 0x300 + idx * 16
 *   (a matched row is overwritten in place).
 *   The first time a timing is seen (key h36 not in the table) it gets the next ring
 *   row (oldest of 20 overwritten); later passes find the row and rewrite it with the same values.
 * Levers: the row address in u16 ARITHMETIC '(unsigned short)(i << 4) + (unsigned short)0x300' (HImode add
 *   keeps the fw sll/srl 16 and the PRE copy); 'r.he == m->h36' (load order); the loop counter i reused for the ring
 *   index. The ring-block row ADDRESS is computed BEFORE the ring update ('i = b1a; addr = ...;
 *   b1a = (i + 1) % 20;'): the fw adds 1 to the raw ldub and masks only for the address (without this form 14 words differ).
 * Aids: none. No volatile.
 */
struct Mode {
    unsigned char p00[8];
    unsigned short h08;
    unsigned char p0a[0x18 - 0x0a];
    unsigned short h18, h1a;
    unsigned char p1c[0x20 - 0x1c];
    unsigned char b20, p21;
    unsigned short h22, h24, h26;
    unsigned char p28[0x34 - 0x28];
    unsigned char b34, p35;
    unsigned short h36;
};
struct Row { unsigned short h0, h2, h4, h6, h8, ha; unsigned char bc, bd; unsigned short he; };
struct Set { unsigned char p00[0x1a]; unsigned char b1a; unsigned char p1b[0x50 - 0x1b]; };
extern struct Set DAT_a802e1a0;
extern void FUN_a0140360(int dev, unsigned short addr, int len, void *buf);
extern void FUN_a0140e74(int dev, unsigned short addr, int len, void *buf, int x);

void FUN_a01542c4(struct Mode *m)
{
    struct Row r = { 0 };
    unsigned char i, found = 0;
    unsigned short addr;

    for (i = 0; i < 20; i++) {
        addr = (unsigned short)(i << 4) + (unsigned short)0x300;
        FUN_a0140360(0, addr, 0x10, &r);
        if (r.he == m->h36) {
            found = 1;
            break;
        }
    }
    r.h0 = m->h08;
    r.h2 = m->h18;
    r.h4 = m->h1a;
    r.h6 = m->h22;
    r.h8 = m->h24;
    r.ha = m->h26;
    r.bc = m->b20;
    r.bd = m->b34;
    r.he = m->h36;
    if (!found) {
        i = DAT_a802e1a0.b1a;
        addr = (unsigned short)(i << 4) + (unsigned short)0x300;
        DAT_a802e1a0.b1a = (i + 1) % 20;
        FUN_a0140e74(0, 0x470, 0x50, &DAT_a802e1a0, 0);
    }
    FUN_a0140e74(0, addr, 0x10, &r, 0);
}
