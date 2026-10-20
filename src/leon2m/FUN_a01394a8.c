/* leon2m FUN_a01394a8 @ 0xa01394a8
 * Posts the word 0x38000000 | (bit 0 of param_1) into mailbox portal 2 at offset 0x20. Reads the slot
 * (MailBox_Read, func_0x4008c4d0); while it is non-zero it waits func_0x4008d1a0(1) and re-reads, at most 100
 * times; the word is written (MailBox_Write, func_0x4008c5f8) only if the slot became 0, else nothing is sent.
 * Same mailbox shape as FUN_a01393f0; the counter is decremented between the wait and the re-read.
 * Callers: none found by direct call (reached indirectly).
 *
 * Required form: the bit is kept in an unsigned char local and turned into 0/1 with a separate 'v = on != 0;'
 * statement before the OR; this keeps the firmware's compare (cmp %g0 / addx). An unsigned int local lets the
 * compiler drop the compare, and '0x38000000 | (on != 0)' in one expression becomes a branch.
 */
extern void func_0x4008c4d0(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void func_0x4008c5f8(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void func_0x4008d1a0(int ms);

void FUN_a01394a8(unsigned int param_1)
{
    unsigned char on = param_1 & 1;
    unsigned int v = 0xffffffff;
    int n = 100;

    func_0x4008c4d0(2, 0x20, &v, 1);

    if (v == 0) goto build;

    do {
        func_0x4008d1a0(1);
        n--;
        func_0x4008c4d0(2, 0x20, &v, 1);
    } while (n != 0 && v != 0);

    if (v == 0) {
build:
        v = on != 0;
        v |= 0x38 << 24;
        func_0x4008c5f8(2, 0x20, &v, 1);
    }
}
