/* leon2m FUN_a01393f0 @ 0xa01393f0  MATCH (-mcpu=v8 -O2 -g)
 * Posts the word (param_1 << 24) | ((param_2 & 0xff) << 16) | param_3 into mailbox portal 2 at offset 0x20. Reads
 * the slot (MailBox_Read, func_0x4008c4d0); while it is non-zero it waits func_0x4008d1a0(1) and re-reads, at most
 * 100 times; the word is written (MailBox_Write, func_0x4008c5f8) only if the slot became 0, else nothing is sent.
 * Same mailbox shape as FUN_a0139ed0 with a caller-built command word.
 *
 * Required form: the zero test before the loop jumps straight to the write (goto build), followed by a do-while
 * with the count and slot tests at the bottom; this gives the target's early check and the closing b,a.
 */
extern void func_0x4008c4d0(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void func_0x4008c5f8(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void func_0x4008d1a0(int ms);

void FUN_a01393f0(unsigned int param_1, unsigned int param_2, unsigned short param_3)
{
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
        v = (param_1 << 24) | ((param_2 & 0xff) << 16) | (param_3 & 0xffff);
        func_0x4008c5f8(2, 0x20, &v, 1);
    }
}
