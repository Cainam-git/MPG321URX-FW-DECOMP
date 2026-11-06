/* leon2s FUN_a00700cc @ 0xa00700cc-0xa00703b8 (187 words), flags -mcpu=v8 -Os -g.
 * Publishes the input port records and status words to the Big chip.
 *
 * 1. ids[7] = port ids from mailbox word 0 (FUN_a006fca8). For each slot k (0..6) with id = ids[k] in 1..9:
 *    n = id - 1, rec = port record 0xA807A824 + 20 * n. When the record's 'changed' bytes +0xf or +0x10 are 1:
 *    print "InputPortidx  %d" n, FUN_a006fbac(id, n, buf) builds the 4-word descriptor (buf[0] byte 1 = rec+0xd,
 *    the flags byte whose bit 2 reaches the Big chip's 0xA802CBD4 port bit), FUN_a006fad4(slot map[2k+1], 0, buf, 4)
 *    writes it to mailbox portal 1 slot k+1 (read by the Big chip's FUN_a01387a4); if +0x10 was 1: FUN_a006fc58(k)
 *    and clear it; clear +0xf.
 * 2. word 2 byte 0 -> DAT_a80788d3; word 3 bits 8..15 = FUN_a0083e28(); FUN_a006fedc() (word 3 bits 24..31);
 *    word 3 bits 0..5 = DAT_a80788d2 & 0x3f, DAT_a80788d2 &= ~DAT_a80788dd, bits 6..7 = FUN_a0088f84() & 3;
 *    if DAT_a80788d2 != 0: print "RxHPDStatus : %02X" DAT_a80788d2 and pulse 0x9f1cc264(0/1) + 0x9f1cc0a8()
 *    for bits 4/5 of the word.
 * 3. word 0 (DAT_a80788e0): bits 1..2 = 0x9f1c3efc() & 3, write; bits 4..31 = the 7 port type nibbles
 *    (rec[i].b0 & 0xf, 4 bits each), write. This nibble is the type the Big chip tests for 5 (FUN_a0142910
 *    copies entry bit 4 only then).
 *
 * Source form: the id test is 'switch (id) { case 1: ... case 9: }' on the unsigned char id (fw a0070120
 * 'and %o4, 0xff' + 'add -1' + 'cmp 8', separate from n's 'add %o4, -1' at a0070100); n and the record pointer
 * are computed inside the case arm (fw record address a0070100-a007011c, ahead of the test at a0070120);
 * the slot loop has its own counter k, the type loop uses i; the type loop bound is the port count local
 * 'cnt = 7' as in FUN_a006fca8 (fw a0070378 'cmp 7; bcs', the slot loop 'cmp 6; bleu'); the HPD print has its
 * %02X argument DAT_a80788d2; the word-3 block reads DAT_a80788d2 once into c (fw a0070260); memcpy (the
 * block copy of the map[] initializer) is the firmware memcpy FUN_a00b15d8.
 */
struct PortRec { unsigned char b0, b1; unsigned short h2, h4, h6, h8, ha; unsigned char bc, bd, be, bf, b10, b11, b12, b13; };
extern struct PortRec DAT_a807a824[];
extern void *memcpy(void *, const void *, unsigned int) __asm__("FUN_a00b15d8");
extern unsigned char DAT_a80788d2, DAT_a80788d3, DAT_a80788dd;
extern unsigned int DAT_a80788e0;
extern char s_a0066498[], s_a00664b0[];
extern int FUN_a0073044();
extern void FUN_a006fca8(unsigned char *ids);
extern void FUN_a006fbac(unsigned char id, unsigned char n, unsigned int *buf);
extern void FUN_a006fad4(unsigned char slot, int word, unsigned int *buf, unsigned char n);
extern void FUN_a006faa8(unsigned char slot, int word, unsigned int *buf, unsigned char n);
extern void FUN_a006fc58(unsigned char i);
extern void FUN_a006fedc(void);
extern unsigned char FUN_a0083e28(void);
extern unsigned char FUN_a0088f84(void);
extern void func_0x9f1cc264(int);
extern void func_0x9f1cc0a8(void);
extern int func_0x9f1c3efc(void);


void FUN_a00700cc(void)
{
    unsigned char map[14] = { 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 7 };
    unsigned int buf[4];
    unsigned char ids[8];
    unsigned int w52, w56, w60, types;
    unsigned char i, k;
    unsigned char cnt = 7;

    FUN_a006fca8(ids);
    for (k = 0; k < 7; k++) {
        unsigned char id;
        unsigned char n;
        struct PortRec *r;
        id = ids[k];
        switch (id) {
        case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
            n = id - 1;
            r = &DAT_a807a824[n];
            if (r->bf == 1 || r->b10 == 1) {
                FUN_a0073044(s_a0066498, n);
                FUN_a006fbac(id, n, buf);
                FUN_a006fad4(map[k * 2 + 1], 0, buf, 4);
                if (r->b10 == 1) {
                    FUN_a006fc58(k);
                    r->b10 = 0;
                }
                r->bf = 0;
            }
            break;
        }
    }
    FUN_a006faa8(0, 2, &w52, 1);
    DAT_a80788d3 = w52 >> 24;
    w56 = 0;
    FUN_a006faa8(0, 3, &w56, 1);
    w56 &= 0xffff00ff;
    w56 |= FUN_a0083e28() << 8;
    FUN_a006fad4(0, 3, &w56, 1);
    FUN_a006fedc();
    w60 = 0;
    FUN_a006faa8(0, 3, &w60, 1);
    {
        unsigned char c = DAT_a80788d2;
        unsigned int w = w60;
        unsigned char d = c & ~DAT_a80788dd;
        unsigned int lo = c & 0x3f;
        w &= ~0xff;
        DAT_a80788d2 = d;
        w60 = w | lo;
    }
    w60 |= (FUN_a0088f84() & 3) << 6;
    if (DAT_a80788d2 != 0) {
        FUN_a0073044(s_a00664b0, DAT_a80788d2);
        if (w60 & 0x10) { func_0x9f1cc264(0); func_0x9f1cc0a8(); }
        if (w60 & 0x20) { func_0x9f1cc264(1); func_0x9f1cc0a8(); }
    }
    FUN_a006fad4(0, 3, &w60, 1);
    DAT_a80788e0 &= ~6;
    DAT_a80788e0 |= (func_0x9f1c3efc() & 3) * 2;
    FUN_a006fad4(0, 0, &DAT_a80788e0, 1);
    types = 0;
    for (i = 0; i < cnt; i++)
        types |= (DAT_a807a824[i].b0 & 0xf) << (i * 4);
    DAT_a80788e0 = (DAT_a80788e0 & 0xf) | types << 4;
    FUN_a006fad4(0, 0, &DAT_a80788e0, 1);
}
