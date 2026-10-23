/* leon2s FUN_a00a0930 @ 0xa00a0930-0xa00a0b10, -mcpu=v8 -Os -g.
 * (u8 port, unsigned int id, u8 mode), void. For id < 0x40: FUN_a00a07b8(port, id); e = 8-byte entry
 * DAT_a00b4a00[id]; bit = (u8)(e->b5 * 8 + e->b6). A jump-table switch on e->type selects the register word of
 * the block whose pointer is word 0 of the 0x34-byte record ARR_a807db00[port]: types 0..2 +0x74 (keeps the bits
 * above 7), 3 +0x78 (keeps & 0xffffff), 4..6 +0x7c (above bit 7), 7 +0x90 (& 0xff00ff00). mode == 1 or's in
 * mode << bit after the mask; any other mode clears bit `bit` and applies the mask. Types above 7: nothing.
 * Counterpart of FUN_a00a07b8 (same table and blocks; register-block pointers, volatile). The jump table is the
 * 8 words at 0xa00a0b10.
 */
struct Ent { unsigned int type; unsigned char b4; unsigned char b5; unsigned char b6; unsigned char b7; };
struct Port34 { volatile unsigned int *regs; unsigned char rest[0x30]; };
extern struct Ent DAT_a00b4a00[];
extern struct Port34 ARR_a807db00[];
extern void FUN_a00a07b8(unsigned int, unsigned int);

void FUN_a00a0930(unsigned char port, unsigned int id, unsigned char mode)
{
    struct Ent *e;
    unsigned char bit;

    if (id < 0x40) {
        FUN_a00a07b8(port, id);
        e = &DAT_a00b4a00[id];
        bit = e->b5 * 8 + e->b6;
        switch (e->type) {
        case 0:
        case 1:
        case 2:
            if (mode == 1)
                ARR_a807db00[port].regs[0x74 / 4] = (ARR_a807db00[port].regs[0x74 / 4] & ~0xff) | (mode << bit);
            else
                ARR_a807db00[port].regs[0x74 / 4] = ARR_a807db00[port].regs[0x74 / 4] & ~(1 << bit) & ~0xff;
            break;
        case 3:
            if (mode == 1)
                ARR_a807db00[port].regs[0x78 / 4] = (ARR_a807db00[port].regs[0x78 / 4] & 0xffffff) | (mode << bit);
            else
                ARR_a807db00[port].regs[0x78 / 4] = ARR_a807db00[port].regs[0x78 / 4] & ~(1 << bit) & 0xffffff;
            break;
        case 4:
        case 5:
        case 6:
            if (mode == 1)
                ARR_a807db00[port].regs[0x7c / 4] = (ARR_a807db00[port].regs[0x7c / 4] & ~0xff) | (mode << bit);
            else
                ARR_a807db00[port].regs[0x7c / 4] = ARR_a807db00[port].regs[0x7c / 4] & ~(1 << bit) & ~0xff;
            break;
        case 7:
            if (mode == 1)
                ARR_a807db00[port].regs[0x90 / 4] = (ARR_a807db00[port].regs[0x90 / 4] & 0xff00ff00) | (mode << bit);
            else
                ARR_a807db00[port].regs[0x90 / 4] = ARR_a807db00[port].regs[0x90 / 4] & ~(1 << bit) & 0xff00ff00;
            break;
        }
    }
}
