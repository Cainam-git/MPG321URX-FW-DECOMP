/* leon2m FUN_a012c188 @ 0xa012c188..0xa012c320 (102 words). BYTE-EXACT:
 * jf 100.00 match=True, rawcmp 0/102 with -mcpu=v8 -O3 -g.
 * Where it runs: start-up step 2 FUN_a015266c, near the end, AFTER FUN_a0141964 (the display start-up that reaches
 * FUN_a0106d64) and after FUN_a01243dc. Job: load the EDIDs into the 8051's DDC slaves.
 * Code:
 *  - For the 7 ports i = 0..6: v = FUN_a01255a0(i) (u16, the DDC buffer size of port i, printed as MaxLen);
 *    nibble i of the RAM word DAT_a802cb08 = v >> 7 (old nibble cleared first, then the new one ORed in).
 *  - If the function pointer DAT_a802cc48 is set: call it and return.
 *  - Else for i = 0..6: port not enabled (FUN_a012536c(i) != 1): FUN_a0133f84(1 << i) (8051 command). Enabled:
 *    x = FUN_a0125380(i); k = settings byte RAM 0xA802E1A0 + 0x1B + i (the EDID choice, from the stored record that
 *    FUN_a0153c74 loaded); data = DAT_a802cc10[k], len = ROM u16 table DAT_001a6ad8[k]; if len > FUN_a01255a0(i):
 *    print "DDC_%d : MaxLen %d / EDID_%d : Len %d" (0x001A4F08) and HANG for ever (nop; nop; b,a loop); else
 *    FUN_a01356fc(1, len) (queue room wait, no timeout), FUN_a0136a10(x, len, data), FUN_a0133fbc(1 << i, len, x >> 7).
 * Two places block: the queue wait in FUN_a01356fc(1, len), which has no timeout, and the endless loop when the EDID
 * selected by the stored settings byte k is longer than the DDC buffer of its port.
 * The hang loop is written as for (;;) with two asm nops (documented no-code aid: the fw loop body
 * is two nop instructions).
 * Byte-exact levers: data read BEFORE len, both indexed by DAT_a802e1a0[0x1b + i] written out; the nibble update as two
 * statements 'w &= ~(0xf << s); w |= (x >> 7) << s;' (the one-expression form swaps two temp registers).
 */
extern unsigned int DAT_a802cb08;
extern void (*DAT_a802cc48)(void);
extern unsigned char DAT_a802e1a0[];
extern const unsigned short DAT_001a6ad8[];
extern unsigned int DAT_a802cc10[];
extern char s_001a4f08[];
extern unsigned short FUN_a01255a0(unsigned char);
extern unsigned char FUN_a012536c(unsigned char);
extern unsigned short FUN_a0125380(unsigned char);
extern void FUN_a0133f84(unsigned char);
extern void FUN_a01356fc(unsigned char, unsigned short);
extern void FUN_a0136a10(unsigned short, unsigned short, unsigned int);
extern void FUN_a0133fbc(unsigned char, unsigned short, unsigned char);
extern int FUN_a00df170(const char *, ...);

void FUN_a012c188(void)
{
    unsigned short i;
    unsigned short x, len;
    unsigned char k, sh;
    unsigned int data;

    for (i = 0; i < 7; i++) {
        x = FUN_a01255a0(i);
        DAT_a802cb08 &= ~(0xf << ((unsigned char)i * 4));
        DAT_a802cb08 |= (x >> 7) << ((unsigned char)i * 4);
    }
    if (DAT_a802cc48 != 0) {
        DAT_a802cc48();
        return;
    }
    for (i = 0; i < 7; i++) {
        if (FUN_a012536c(i) == 1) {
        x = FUN_a0125380(i);
        data = DAT_a802cc10[DAT_a802e1a0[0x1b + i]];
        len = DAT_001a6ad8[DAT_a802e1a0[0x1b + i]];
        if (len > FUN_a01255a0(i)) {
            FUN_a00df170(s_001a4f08, i, FUN_a01255a0(i), DAT_a802e1a0[0x1b + i], len);
            for (;;) {
                __asm__ volatile ("nop");
                __asm__ volatile ("nop");
            }
        }
        FUN_a01356fc(1, len);
        FUN_a0136a10(x, len, data);
        FUN_a0133fbc(1 << i, len, x >> 7);
        } else
            FUN_a0133f84(1 << i);
    }
}
