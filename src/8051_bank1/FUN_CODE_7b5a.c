/* 8051_bank1 FUN_CODE_7b5a @ 0x7b5a..0x7ca8 (334 bytes)  STBC "###SYSTEM CRASH, RESET###" check of the
 * ring bytes 0xF204..0xF24C. Built with OPTIMIZE(8,SPEED) (also with REGFILE(R.ORC) and LARGE; OPTIMIZE(7) gives
 * 344 bytes). Source form: the two signature tests are SEPARATE ifs with the
 * same body (Keil level 8 merges the first body into 'SJMP' to the second: the fw CJNE/CJNE/SJMP shape; one '||'
 * condition gives XRL/JZ and 333 bytes); 0xF209/0xF20A and 0xF20D/0xF20E are 2-byte arrays (fw INC DPTR).
 * Called by the 8051 application main FUN_CODE_3fe7 once at start-up (grace bit BITS_20_0 = 1) and on every pass of
 * its endless loop while the run state XDATA 0xA770 == 2 (grace bit 0 then).
 * What the code does (code facts):
 *  - Service signature 0x87, 0x78 in mailbox bytes 0xF209/0xF20A or 0xF20D/0xF20E: restart timer A (0xA35A = now)
 *    and return (no check). now = FUN_CODE_d94a() (16-bit tick counter).
 *  - Grace bit set: restart both timers (0xA35A, 0xA35C).
 *  - Token ring 1: when 0xF20C (end of the ring) equals 0xF204 (the token this chip wrote), the token has gone round:
 *    token = (0xA359 += 7) -> 0xF204, timer A = now. Ring 2: when 0xF248 equals 0xF240 and 0xF24C != 0x87:
 *    token = (0xA359 += 13) -> 0xF240, timer B = now. (The printed names call the three bytes of each ring
 *    stbc / main / sub: ring 1 = 0xF204 / 0xF208 / 0xF20C, ring 2 = 0xF240 / 0xF244 / 0xF248.)
 *  - If now - timer A > 15000 or now - timer B > 10000 ticks: prints "###SYSTEM CRASH, RESET###\r\n" (CODE 0x55F5),
 *    "stbc cnt = %02x, main cnt = %02x, sub_cnt = %02x\r\n" (0x5611) with ring 1 and "stbc relible cnt = ..."
 *    (0x5644) with ring 2, STOPS Leon2 Main (FUN_CODE_cbac) and Leon2 Sub (FUN_CODE_cbf2), 0xF150 = 9,
 *    0xF152 |= 0x40, FUN_CODE_7a0b(), 0xF00A = 0x55 and loops forever ('SJMP $' at 0x7CA5). No reset is written
 *    here; the main loop's per-pass 0xF0E0 = 0x55 write stops with it.
 * Consequence: a Big chip that halts (fatal trap path, error mode, endless wait) never copies F204 to F208, so after the 15000-tick limit this 8051 stops both Leon2 cores and itself: from then on nothing in the
 *   monitor serves the mailbox, the UART relay or the flash command loop FUN_CODE_6c34. (The Big chip
 *   forwards the token with FUN_a002ced8: 0xF204 -> 0xF208.)
 * volatile: 0xF2xx / 0xF150 / 0xF152 / 0xF00A are hardware registers (mailbox / control), the rest is RAM.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f204, DAT_EXTMEM_f208, DAT_EXTMEM_f209[2];
extern unsigned char volatile xdata DAT_EXTMEM_f20c, DAT_EXTMEM_f20d[2];
extern unsigned char volatile xdata DAT_EXTMEM_f240, DAT_EXTMEM_f244, DAT_EXTMEM_f248, DAT_EXTMEM_f24c;
extern unsigned char volatile xdata DAT_EXTMEM_f150, DAT_EXTMEM_f152, DAT_EXTMEM_f00a;
extern unsigned char xdata DAT_EXTMEM_a359;
extern unsigned int xdata DAT_EXTMEM_a35a, DAT_EXTMEM_a35c;
extern bit BITS_20_0;
extern unsigned int FUN_CODE_d94a(void);
extern void FUN_CODE_2820(void *fmt, ...) large;
extern void FUN_CODE_cbac(void);
extern void FUN_CODE_cbf2(void);
extern void FUN_CODE_7a0b(void);

void FUN_CODE_7b5a(void)
{
    if (DAT_EXTMEM_f209[0] == 0x87 && DAT_EXTMEM_f209[1] == 0x78) {
        DAT_EXTMEM_a35a = FUN_CODE_d94a();
        return;
    }
    if (DAT_EXTMEM_f20d[0] == 0x87 && DAT_EXTMEM_f20d[1] == 0x78) {
        DAT_EXTMEM_a35a = FUN_CODE_d94a();
        return;
    }
    if (BITS_20_0) {
        DAT_EXTMEM_a35a = FUN_CODE_d94a();
        DAT_EXTMEM_a35c = FUN_CODE_d94a();
    }
    if (DAT_EXTMEM_f204 == DAT_EXTMEM_f20c) {
        DAT_EXTMEM_a359 += 7;
        DAT_EXTMEM_f204 = DAT_EXTMEM_a359;
        DAT_EXTMEM_a35a = FUN_CODE_d94a();
    }
    if (DAT_EXTMEM_f240 == DAT_EXTMEM_f248 && DAT_EXTMEM_f24c != 0x87) {
        DAT_EXTMEM_a359 += 13;
        DAT_EXTMEM_f240 = DAT_EXTMEM_a359;
        DAT_EXTMEM_a35c = FUN_CODE_d94a();
    }
    if (FUN_CODE_d94a() - DAT_EXTMEM_a35a > 15000 || FUN_CODE_d94a() - DAT_EXTMEM_a35c > 10000) {
        FUN_CODE_2820((void code *)0x55f5);
        FUN_CODE_2820((void code *)0x5611, (unsigned int)DAT_EXTMEM_f204, (unsigned int)DAT_EXTMEM_f208,
                      (unsigned int)DAT_EXTMEM_f20c);
        FUN_CODE_2820((void code *)0x5644, (unsigned int)DAT_EXTMEM_f240, (unsigned int)DAT_EXTMEM_f244,
                      (unsigned int)DAT_EXTMEM_f248);
        FUN_CODE_cbac();
        FUN_CODE_cbf2();
        DAT_EXTMEM_f150 = 9;
        DAT_EXTMEM_f152 |= 0x40;
        FUN_CODE_7a0b();
        DAT_EXTMEM_f00a = 0x55;
        for (;;) ;
    }
}
