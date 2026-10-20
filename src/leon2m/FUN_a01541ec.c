/* leon2m FUN_a01541ec @ 0xa01541ec-0xa01542c4 (54 words), -mcpu=v8 -O3 -g.
 * BYTE-EXACT: jf 100.00 match=True, rawcmp 0/54.
 * What it does: the mode-table LOOKUP (sibling of the store FUN_a01542c4). FUN_a013f370 calls it with the channel
 *   record + 6 when a new input timing is applied; if it returns 0, FUN_a01542c4 stores the timing. It reads up to
 *   20 rows of 16 bytes from the settings EEPROM with FUN_a0140360(0, 0x300 + i * 16, 0x10, &row) (row zeroed
 *   first) and stops at the first row whose u16 +0x0e equals m->h36 (the key). Found: copies the row back into the
 *   mode record (h08/h18/h1a/h22/h24/h26 = row halfwords 0..5, b20 = row[12], b34 = row[13]) and returns 1;
 *   not found: returns 0 and changes nothing.
 *   If this timing (key h36) was stored before, the 6 halfwords and 2 bytes saved for it
 *   replace the record's values here, before FUN_a013f370 goes on.
 * Levers: the row address in u16 ARITHMETIC '(unsigned short)(i << 4) + (unsigned short)0x300' (HImode add
 *   keeps the fw sll/srl 16). The tail is written 'if (found == 1) { copy; return 1; } return 0;' (gives the fw
 *   layout: the found block gets its own copy of the found test, the loop-exit test jumps into the copy) and the
 *   copy statements in ROW order h0..ha, bc, bd (fw load/store order; a b34-first order makes sched move b20).
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
extern void FUN_a0140360(int dev, unsigned short addr, int len, void *buf);

unsigned char FUN_a01541ec(struct Mode *m)
{
    struct Row r = { 0 };
    unsigned char i, found = 0, ret;

    for (i = 0; i < 20; i++) {
        FUN_a0140360(0, (unsigned short)(i << 4) + (unsigned short)0x300, 0x10, &r);
        if (m->h36 == r.he) {
            found = 1;
            break;
        }
    }
    if (found == 1) {
        m->h08 = r.h0;
        m->h18 = r.h2;
        m->h1a = r.h4;
        m->h22 = r.h6;
        m->h24 = r.h8;
        m->h26 = r.ha;
        m->b20 = r.bc;
        m->b34 = r.bd;
        return 1;
    }
    return 0;
}
