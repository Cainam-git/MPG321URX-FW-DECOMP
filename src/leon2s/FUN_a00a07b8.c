/* leon2s FUN_a00a07b8 @ 0xa00a07b8-0xa00a0910, -mcpu=v8 -Os -g (leaf).
 * (port, unsigned int id), void. For id < 0x40, e = 8-byte entry DAT_a00b4a00[id] (word type, bytes +4 and
 * +6): bit = (u8)(e->b4 * 8 + e->b6). A jump-table switch on e->type (types > 7: nothing) sets bit `bit`
 * (1 << bit) in one register of the block whose pointer is word 0 of the 0x34-byte record
 * ARR_a807db00[port], keeping only the listed part of the old value: types 0..2 word +0x70 (keeps & 0xff),
 * 3 +0x74 (& ~0xff), 4 +0x78 (& 0xffffff), 5 +0x7c (& ~0xff), 6 +0x80 (& 0xffffff), 7 +0x90 (& 0xff00ff00).
 * The record pointers are register-block pointers (volatile: the firmware keeps the stores out of the
 * branch delay slots). The jump table is the 8 words at 0xa00a0798.
 * Source form: an entry pointer e for all three entry reads.
 */
struct Ent { unsigned int type; unsigned char b4; unsigned char b5; unsigned char b6; unsigned char b7; };
struct Port34 { volatile unsigned int *regs; unsigned char rest[0x30]; };
extern struct Ent DAT_a00b4a00[];
extern struct Port34 ARR_a807db00[];

void FUN_a00a07b8(unsigned int port, unsigned int id)
{
    unsigned char bit;
    struct Ent *e;

    if (id < 0x40) {
        e = &DAT_a00b4a00[id];
        bit = e->b4 * 8 + e->b6;
        switch (e->type) {
        case 0:
        case 1:
        case 2:
            ARR_a807db00[port & 0xff].regs[0x70 / 4] = (ARR_a807db00[port & 0xff].regs[0x70 / 4] & 0xff) | (1 << bit);
            break;
        case 3:
            ARR_a807db00[port & 0xff].regs[0x74 / 4] = (ARR_a807db00[port & 0xff].regs[0x74 / 4] & ~0xff) | (1 << bit);
            break;
        case 4:
            ARR_a807db00[port & 0xff].regs[0x78 / 4] = (ARR_a807db00[port & 0xff].regs[0x78 / 4] & 0xffffff) | (1 << bit);
            break;
        case 5:
            ARR_a807db00[port & 0xff].regs[0x7c / 4] = (ARR_a807db00[port & 0xff].regs[0x7c / 4] & ~0xff) | (1 << bit);
            break;
        case 6:
            ARR_a807db00[port & 0xff].regs[0x80 / 4] = (ARR_a807db00[port & 0xff].regs[0x80 / 4] & 0xffffff) | (1 << bit);
            break;
        case 7:
            ARR_a807db00[port & 0xff].regs[0x90 / 4] = (ARR_a807db00[port & 0xff].regs[0x90 / 4] & 0xff00ff00) | (1 << bit);
            break;
        }
    }
}
