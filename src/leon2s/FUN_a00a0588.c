/* leon2s FUN_a00a0588 @ 0xa00a0588-0xa00a0798, -mcpu=v8 -Os -g (leaf).
 * (port, unsigned int id), returns u8 0 or 1. id >= 0x40 returns 0. e = 8-byte entry DAT_a00b4a00[id];
 * a = e->b4 * 8 + e->b6, b = e->b5 * 8 + e->b6. A jump-table switch on e->type (table: the 8 words at
 * 0xa00a0568; types > 7 return 0) tests an enable bit and then a status bit (1 << a) in the register block
 * ARR_a807db00[port & 0xff].regs: types 0..2: for id 4 and 0x16 status word +0x70 directly, otherwise enable
 * (1 << b) in word +0x74 above bit 7, status +0x70; 3: enable (1 << b) in +0x78 below bit 24, status +0x74;
 * 4..6: enable (1 << a) in +0x7c above bit 7, status +0x78 / +0x7c / +0x80; 7: (1 << a) in +0x90 under
 * 0xff00ff00, status +0x90. Returns 1 when both are set. Same table and blocks as FUN_a00a07b8.
 * Source form: the id test is an early 'return 0' before the result is used.
 */
struct Ent { unsigned int type; unsigned char b4; unsigned char b5; unsigned char b6; unsigned char b7; };
struct Port34 { volatile unsigned int *regs; unsigned char rest[0x30]; };
extern struct Ent DAT_a00b4a00[];
extern struct Port34 ARR_a807db00[];

unsigned char FUN_a00a0588(unsigned int port, unsigned int id)
{
    unsigned char r = 0;
    struct Ent *e;
    unsigned int a, b;

    if (id >= 0x40)
        return 0;
    e = &DAT_a00b4a00[id];
    a = e->b4 * 8 + e->b6;
    b = e->b5 * 8 + e->b6;
    switch (e->type) {
    case 0:
    case 1:
    case 2:
        if (id == 4 || id == 0x16) {
            if (ARR_a807db00[port & 0xff].regs[0x70 / 4] & (1 << a))
                r = 1;
        } else if (ARR_a807db00[port & 0xff].regs[0x74 / 4] & (1 << b) & ~0xff) {
            if (ARR_a807db00[port & 0xff].regs[0x70 / 4] & (1 << a))
                r = 1;
        }
        break;
    case 3:
        if (ARR_a807db00[port & 0xff].regs[0x78 / 4] & (1 << b) & 0xffffff) {
            if (ARR_a807db00[port & 0xff].regs[0x74 / 4] & (1 << a))
                r = 1;
        }
        break;
    case 4:
        if (ARR_a807db00[port & 0xff].regs[0x7c / 4] & (1 << a) & ~0xff) {
            if (ARR_a807db00[port & 0xff].regs[0x78 / 4] & (1 << a))
                r = 1;
        }
        break;
    case 5:
        if (ARR_a807db00[port & 0xff].regs[0x7c / 4] & (1 << a) & ~0xff) {
            if (ARR_a807db00[port & 0xff].regs[0x7c / 4] & (1 << a))
                r = 1;
        }
        break;
    case 6:
        if (ARR_a807db00[port & 0xff].regs[0x7c / 4] & (1 << a) & ~0xff) {
            if (ARR_a807db00[port & 0xff].regs[0x80 / 4] & (1 << a))
                r = 1;
        }
        break;
    case 7:
        if (ARR_a807db00[port & 0xff].regs[0x90 / 4] & (1 << a) & 0xff00ff00) {
            if (ARR_a807db00[port & 0xff].regs[0x90 / 4] & (1 << a))
                r = 1;
        }
        break;
    }

    return r;
}
