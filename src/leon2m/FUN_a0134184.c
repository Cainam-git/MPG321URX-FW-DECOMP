/* leon2m FUN_a0134184 @ 0xa0134184-0xa01341dc (22 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * When FUN_a00dd614(0x20) returns non-zero, prints "MailBox_SetWakeUpTimer : %02X\r\n" with the halfword v. Then
 * tail-calls func_0x4008f3f4(0x1c, 0, low byte of v, high byte of v, 1) (the RAM copy of FUN_a002f3f4, which sends
 * command 0x1c to the 8051 mailbox and waits for it to be taken).
 * Exact form: the low byte is taken into an unsigned char local before the test.
 */
extern unsigned char FUN_a00dd614(int);
extern int FUN_a00df170();
extern char s_001a5418[];
extern int func_0x4008f3f4();

void FUN_a0134184(unsigned short v)
{
    unsigned char lo = v;

    if (FUN_a00dd614(0x20))
        FUN_a00df170(s_001a5418, v);
    func_0x4008f3f4(0x1c, 0, lo, v >> 8, 1);
}
