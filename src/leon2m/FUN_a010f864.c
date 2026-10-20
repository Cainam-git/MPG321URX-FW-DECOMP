/* leon2m FUN_a010f864 @ 0xa010f864-0xa010f8fc (38 words).
 * ch selects a record (ch == 1: 0xA802D804, else 0xA802D704) and clears bit 0 of its byte +0x3E. ch == 0
 * then clears bit 20 of hardware registers 0xD0032000 and 0xD003A000; any other ch clears bit 21 of both.
 * Counterpart of FUN_a010f7a4, which sets the same bits. No direct callers were found.
 */
#define R(a) (*(volatile unsigned int *)(a))
struct ChBlk { unsigned char pad[0x3e]; unsigned char b3e; };
extern struct ChBlk DAT_a802d704, DAT_a802d804;

void FUN_a010f864(unsigned char ch)
{
    struct ChBlk *p;

    p = &DAT_a802d704;
    if (ch == 1) p = &DAT_a802d804;
    p->b3e &= ~1;
    if (ch == 0) {
        R(0xd0032000) &= ~0x100000;
        R(0xd003a000) &= ~0x100000;
    } else {
        R(0xd0032000) &= ~0x200000;
        R(0xd003a000) &= ~0x200000;
    }
}
