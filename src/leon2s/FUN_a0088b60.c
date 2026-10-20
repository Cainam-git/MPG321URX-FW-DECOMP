/* FUN_a0088b60 (leon2s, 0xa0088b60-0xa0088c5c, 63 words). Flags -mcpu=v8 -Os -g.
 Code facts: void (u8 port). Returns early if FUN_a0088af0(port) == 0, or (FUN_a00866a4() != 0, port 0) when FUN_a008639c(0, 0x90, 0x111, &st)
 fails or bit 0 of st is set. Loop i = 0..15: off = i << 4; DAT_a80789f0 = off; FUN_a00863d4(port, 0x40, 0x50, 0, &DAT_a80789f0);
 FUN_a0086400(port, 0x10, 0x50, 0xf, DAT_9f1b0000 + off); stop if FUN_a0088af0(port) == 0 or bit 7 of the hardware register 0xcf018884.
 After 16 passes DAT_a8078a0a = 1.
 Fixes vs draft: BEHAVIOUR the 5th argument of 863d4 is the address of DAT_a80789f0 (the draft passed an uninitialised local);
 0x9f1b0000 is a symbol (sethi + or %lo 0); one 'off = i << 4' temp shared by the store and the address. Aids: none.
 */
extern unsigned char DAT_a80789f0;
extern unsigned char DAT_a8078a0a;
extern unsigned char DAT_9f1b0000[];
#define _DAT_cf018884 (*(volatile unsigned int *)0xcf018884)
extern unsigned char FUN_a008639c(unsigned int, unsigned int, unsigned int, unsigned char *);
extern unsigned char FUN_a00863d4(unsigned char, unsigned int, unsigned int, unsigned int, unsigned char *);
extern unsigned char FUN_a0086400(unsigned char, unsigned int, unsigned int, unsigned int, unsigned char *);
extern unsigned char FUN_a00866a4(void);
extern unsigned char FUN_a0088af0(unsigned char);

void FUN_a0088b60(unsigned char port)
{
    unsigned char i;
    unsigned char st;
    unsigned int off;

    if (FUN_a0088af0(port) == 0)
        return;
    if (FUN_a00866a4() != 0 && port == 0) {
        if (FUN_a008639c(0, 0x90, 0x111, &st) != 0)
            return;
        if ((st & 1) != 0)
            return;
    }
    i = 0;
    do {
        off = i << 4;
        DAT_a80789f0 = off;
        FUN_a00863d4(port, 0x40, 0x50, 0, &DAT_a80789f0);
        FUN_a0086400(port, 0x10, 0x50, 0xf, DAT_9f1b0000 + off);
        i++;
        if (FUN_a0088af0(port) == 0)
            return;
        if ((_DAT_cf018884 & 0x80) != 0)
            return;
    } while (i <= 0xf);
    DAT_a8078a0a = 1;
}
