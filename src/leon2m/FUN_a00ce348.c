/* leon2m FUN_a00ce348 @ 0xa00ce348..0xa00ce5dc (660 bytes)  port-4 UART command task.
 * BYTE-EXACT: jf 100 match=True and rawcmp 0 / 165 words at -mcpu=v8 -O3 -g (also at -mcpu=v8 -O3 -g -msoft-float).
 * Hand, from an 82.53 % draft.
 *
 * What the code does (code facts):
 *   r = FUN_a00baef8(4) (the port-4 frame reader / framer); switch on r:
 *   0x20: clear the port-4 receive state, then send the 6-byte reply "56006\r" (FUN_a01487e8(4, 6, DAT_a802d078)).
 *   0x10: clear, then send "5600-\r".   (both are tail calls)
 *   0x40, 0x80: clear only.
 *   2: idx = FUN_a00bb1c4() (inlined: first row 0..0x82 of the command table FUN_a015463c whose chars 2..6 match the
 *      received bytes DAT_a802d0d0[2..6], 0xff entries = wildcard; 0xff = none). idx <= 0x82 -> FUN_a00bfcc4(4, idx)
 *      (the 131-case command switch; case 2 = FUN_a00bf110 UartSetI2CEnable = MSI tool update entry); else reply
 *      "56006\r". Then clear.
 *   4: c = FUN_a00bb260(4); c > 0x99 or FUN_a00ccf34(4, c) == 0xff -> reply "5600-\r". Then clear.
 *   other values: nothing.
 *   Clear = DAT_a802b09c (rx count) = 0 and DAT_a802d0d0[0], [1], [7], [10], [0x19] = 0 (same order as the port-4
 *   arm of byte-exact FUN_a00bf110).
 * This is the only caller path from the Big chip main task (FUN_a0085984) to the UART command switch.
 *
 * Matching facts: FUN_a01487e8 takes 3 arguments (port, len, frame) - the fw passes DAT_a802d078 in %o2;
 *   FUN_a00ccf34 takes 2 arguments (its asm: save; and %i1,0xff; cmp %i1,0x99) and case 4 passes the FUN_a00bb260
 *   result (fw keeps it in %o1 up to the call) - this fixed the j == 7 delay slot, the clear's registers and case 4
 *   (82.53 -> 100); switch CASE ORDER 0x20, 0x10, 0x40/0x80, 2, 4, default (all 720 orders scored);
 *   the clear AFTER the switch (cases 2/4/0x40 break to it, 0x10/0x20 return); c is reused for the FUN_a00bb260 value.
 * COMPILER AID (no code, no data): the inlined FUN_a00bb1c4 reads the buffer through a
 *   second declaration with an asm label, extern unsigned char DAT_rx[] __asm__("DAT_a802d0d0") - same link symbol and
 *   bytes. Why: with one declaration gcse PRE shares HIGH(DAT_a802d0d0) between the loop and the clear (fw
 *   recomputes it): plain declaration = 58.82; a const-int address = 99.39 (1 word, ldub operand order) and is not
 *   relocatable, so not used.
 */
extern unsigned char FUN_a00baef8(unsigned char);
extern void FUN_a01487e8(unsigned char, int, unsigned char *);
extern unsigned char FUN_a015463c(unsigned short, unsigned short);
extern void FUN_a00bfcc4(unsigned char, unsigned char);
extern unsigned char FUN_a00bb260(unsigned char);
extern unsigned char FUN_a00ccf34(unsigned char, unsigned char);

extern unsigned char DAT_a802d078[];
extern unsigned char DAT_a802d0d0[];
extern unsigned char DAT_a802b09c;
extern unsigned char DAT_rx[] __asm__("DAT_a802d0d0");

static void rx_clear(void)
{
    DAT_a802b09c = 0;
    DAT_a802d0d0[0x0] = 0;
    DAT_a802d0d0[0x1] = 0;
    DAT_a802d0d0[0x7] = 0;
    DAT_a802d0d0[0xa] = 0;
    DAT_a802d0d0[0x19] = 0;
}

static void reply(unsigned char c)
{
    DAT_a802d078[0] = '5';
    DAT_a802d078[1] = '6';
    DAT_a802d078[2] = '0';
    DAT_a802d078[3] = '0';
    DAT_a802d078[4] = c;
    DAT_a802d078[5] = '\r';
    FUN_a01487e8(4, 6, DAT_a802d078);
}

static unsigned char find_cmd(void)
{
    unsigned char idx, j;

    for (idx = 0; idx <= 0x82; idx++) {
        for (j = 2; j <= 6; j++) {
            if (FUN_a015463c(idx, j) != 0xff && FUN_a015463c(idx, j) != DAT_rx[j])
                break;
        }
        if (j == 7)
            return idx;
    }
    return 0xff;
}

void FUN_a00ce348(void)
{
    unsigned char c;

    switch (FUN_a00baef8(4)) {
    case 0x20:
        rx_clear();
        reply('6');
        return;
    case 0x10:
        rx_clear();
        reply('-');
        return;
    case 0x40:
    case 0x80:
        break;
    case 2:
        c = find_cmd();
        if (c <= 0x82)
            FUN_a00bfcc4(4, c);
        else
            reply('6');
        break;
    case 4:
        c = FUN_a00bb260(4);
        if (c > 0x99 || FUN_a00ccf34(4, c) == 0xff)
            reply('-');
        break;
    default:
        return;
    }
    rx_clear();
}
