/* leon2m FUN_a010f7a4 @ 0xa010f7a4  program half the active row's +0x08 value into an output block
 * Flags: -mcpu=v8 -O3 -g -msoft-float.
 *
 * ch selects a channel record (ch == 1: 0xA802D804, else 0xA802D704); sets bit 0 of its byte +0x3E. v = transformed
 * row (DAT_a802d6a4) halfword +0x08 >> 1. ch == 0: 0xD0032018 = 0xD003A018 = v, then bit 20 set in 0xD0032000 and
 * 0xD003A000; any other ch: 0xD003201C = 0xD003A01C = v, then bit 21 set in both. Reads the panel
 * row.
 */
#define R(a) (*(volatile unsigned int *)(a))
struct ChBlk { unsigned char pad[0x3e]; unsigned char b3e; };
struct PanelParam { unsigned int w0; unsigned short h4; unsigned char b6, b7; unsigned short h08; };
extern struct ChBlk DAT_a802d704, DAT_a802d804;
extern struct PanelParam *DAT_a802d6a4;

void FUN_a010f7a4(unsigned char ch)
{
    struct ChBlk *p;
    unsigned int v;

    p = &DAT_a802d704;
    if (ch == 1) p = &DAT_a802d804;
    p->b3e |= 1;
    v = DAT_a802d6a4->h08 >> 1;
    if (ch == 0) {
        R(0xd0032018) = v;
        R(0xd003a018) = v;
        R(0xd0032000) |= 0x100000;
        R(0xd003a000) |= 0x100000;
    } else {
        R(0xd003201c) = v;
        R(0xd003a01c) = v;
        R(0xd0032000) |= 0x200000;
        R(0xd003a000) |= 0x200000;
    }
}
