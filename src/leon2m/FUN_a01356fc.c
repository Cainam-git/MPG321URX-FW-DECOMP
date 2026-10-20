/* leon2m FUN_a01356fc @ 0xa01356fc..0xa013588c (100 words)  waits for the Big chip -> 8051 message queue
 * Called FUN_a01356fc(3, 0) by FUN_a01439d8 (start-up step 5, BEFORE the hook and before WAIT 3)
 * and FUN_a01356fc(2, 0) in step 7 (after the hook).
 * Queue: two RAM index bytes DAT_a802cb96 / DAT_a802cb97 of a 36-slot ring that FUN_a01350dc advances. By mode:
 *  - 1: while n > 16 * k: FUN_a01350dc(), with k = cb96 - cb97 + 36 if cb97 > cb96, 36 if equal, cb96 - cb97 - 1
 *    if cb97 < cb96; the loop ends when n <= 16 * k.
 *  - 2: while cb97 != cb96: FUN_a01350dc() (drain the ring).
 *  - 3: drain as in 2, then repeat: read the 8051 mailbox (portal 0 = 0x9F0A0100) words +0x10, +0x24, +0x38, +0x4C
 *    one by one (MailBox_Read func_0x4008c4d0) and or them together, until the result is 0.
 *  - any other mode: nothing.
 * All three modes wait without timeout: modes 1/2 until FUN_a01350dc has moved the queue on, mode 3 in addition
 * until the 8051 has cleared all four mailbox words, which requires a running 8051 that serves its mailbox. The
 * call (3, 0) from FUN_a01439d8 is therefore a no-timeout wait on the 8051 in start-up step 5, before WAIT 3 and
 * before the hook.
 * Exact form: the switch on the u8 mode, the mailbox loop as for (i; 20 * i + 16 <= 0x50).
 */
extern unsigned char DAT_a802cb96, DAT_a802cb97;
extern void FUN_a01350dc(void);
extern void func_0x4008c4d0(unsigned char, unsigned char, unsigned int *, unsigned char);

void FUN_a01356fc(unsigned char mode, unsigned short n)
{
    unsigned int w = 0;
    unsigned int acc;
    unsigned char i;
    unsigned short k;

    switch (mode) {
    case 1:
        for (;;) {
            if (DAT_a802cb97 > DAT_a802cb96)
                k = DAT_a802cb96 - DAT_a802cb97 + 36;
            else if (DAT_a802cb97 >= DAT_a802cb96)
                k = 36;
            else
                k = DAT_a802cb96 - DAT_a802cb97 - 1;
            if (n <= (unsigned short)(k << 4))
                break;
            FUN_a01350dc();
        }
        break;
    case 2:
        while (DAT_a802cb97 != DAT_a802cb96)
            FUN_a01350dc();
        break;
    case 3:
        while (DAT_a802cb97 != DAT_a802cb96)
            FUN_a01350dc();
        do {
            acc = 0;
            for (i = 0; i * 20 + 16 <= 0x50; i++) {
                func_0x4008c4d0(0, i * 20 + 16, &w, 1);
                acc |= w;
            }
        } while (acc != 0);
        break;
    }
}
