/* leon2m FUN_a013874c @ 0xa013874c-0xa01387a4 (22 words), flags -mcpu=v8 -O2 -g. Called by FUN_a01451fc.
 * Polls mailbox portal 1, word offset 0xc (func_0x4008c4d0 = MailBox_Read(portal, offset, buf, words)) until
 * bit 30 of the word is set; on every round with debug level 0x20 enabled (FUN_a00dd614) it prints
 * "wait sub power down\n" (string 0x1a5618, FUN_a00df170). The word starts at 0.
 * Source form: the buffer address is taken once into a pointer local (fw keeps it in %l1); the bit test reads
 * the most significant byte of the word (ldub [%fp-12]; btst 0x40).
 */
extern void func_0x4008c4d0(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern unsigned char FUN_a00dd614(unsigned int level);
extern int FUN_a00df170();
extern const char s_001a5618[];

void FUN_a013874c(void)
{
    unsigned int status = 0;
    unsigned int *p = &status;

    do {
        func_0x4008c4d0(1, 0xc, p, 1);
        if (FUN_a00dd614(0x20))
            FUN_a00df170(s_001a5618);
    } while (!(((unsigned char *)&status)[0] & 0x40));
}
