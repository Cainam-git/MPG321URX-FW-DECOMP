/* FUN_a00c1ac0 (leon2s 0xa00c1ac0-0xa00c1c18, 344 bytes), flags -mcpu=v8 -Os -g.
 * For i = 0, 1 of two blocks, through ROM register routines: block A (16-byte records
 * DAT_a807d5c8[i]) in state 5 or 6 with bit 5 of reg 0x318 set: write 0x60 to reg 0x318, set bit 4 of reg
 * 0x308, state = 7. Block B (records DAT_a807d5e8[i]) in state 5 or 6 with bit 6 of reg 0xa8 set: writes
 * 0xa8 = 0x60, 0xa6 = 9, 0xa4 = 0, 0xa5 = 0, 0xa7 = 0x10, 0xa4 = 0x20, state = 7.
 * Source form: a record pointer local per iteration.
 */
struct rec16 {
    unsigned char _0[0xd];
    unsigned char st;
    unsigned char _e[2];
};
extern struct rec16 DAT_a807d5c8[];
extern struct rec16 DAT_a807d5e8[];
extern unsigned int func_0xa0fb657c(unsigned char, unsigned short);
extern void func_0xa0fb65c4(unsigned char, unsigned short, unsigned char);
extern void func_0xa0fb67b8(unsigned char, unsigned short, unsigned int, unsigned char);
extern unsigned int func_0xa0fb69b4(unsigned char, unsigned short);
extern void func_0xa0fb69fc(unsigned char, unsigned short, unsigned char);

void FUN_a00c1ac0(void)
{
    unsigned char i;
    struct rec16 *r;

    for (i = 0; i < 2; i++) {
        r = &DAT_a807d5c8[i];
        if ((unsigned char)(r->st - 5) <= 1 && (func_0xa0fb657c(i, 0x318) & 0x20)) {
            func_0xa0fb65c4(i, 0x318, 0x60);
            func_0xa0fb67b8(i, 0x308, 0x10, 1);
            r->st = 7;
        }
    }
    for (i = 0; i < 2; i++) {
        r = &DAT_a807d5e8[i];
        if ((unsigned char)(r->st - 5) <= 1 && (func_0xa0fb69b4(i, 0xa8) & 0x40)) {
            func_0xa0fb69fc(i, 0xa8, 0x60);
            func_0xa0fb69fc(i, 0xa6, 9);
            func_0xa0fb69fc(i, 0xa4, 0);
            func_0xa0fb69fc(i, 0xa5, 0);
            func_0xa0fb69fc(i, 0xa7, 0x10);
            func_0xa0fb69fc(i, 0xa4, 0x20);
            r->st = 7;
        }
    }
}
