/* sys_watch_main_core  (FUN_CODE_7b5a)
 *
 * Check that both LEON processors are alive (two token rounds) and power off if a round takes too long.
 * Note: After a crash the 8051 loops forever.
 * Name basis: proven - prints '###SYSTEM CRASH, RESET###', 'stbc cnt = ...'; 15000 / 10000 tick limits
 *   (docs/MAP.md)
 *
 * Matching notes
 * --------------
 * Compiler flags: OPTIMIZE(8,SPEED) (also exact with REGFILE(R.ORC) and LARGE; OPTIMIZE(7) gives 344 bytes).
 * Source forms: the two service-mark tests are SEPARATE ifs with the same body (Keil level 8 merges the first body
 *   into an SJMP to the second: the firmware's CJNE/CJNE/SJMP shape; one '||' condition gives XRL/JZ and 333
 *   bytes); 0xF209/0xF20A and 0xF20D/0xF20E are 2-byte arrays (INC DPTR).
 * volatile: the 0xF2xx bytes and 0xF150 / 0xF152 / 0xF00A; the rest is RAM.
 */

#define SERVICE_MARK_0           0x87  /* 0x87, 0x78 in either service pair: no crash check */
#define SERVICE_MARK_1           0x78
#define RING2_HOLD_MARK          0x87  /* 0xF24C = 0x87: ring 2 is not advanced */
#define RING1_TOKEN_STEP         7
#define RING2_TOKEN_STEP         13
#define RING1_TIMEOUT_TICKS      15000
#define RING2_TIMEOUT_TICKS      10000
#define STOP_REG_F150_VALUE      9     /* the same two writes as before mailbox commands 0x16 and 0x17 */
#define STOP_REG_F152_BIT6       0x40
#define PASS_MARK                0x55

extern unsigned char volatile xdata reg_ipc_alive_stbc_cnt, reg_ipc_alive_main_cnt, reg_ipc_alive_main_service[2];
extern unsigned char volatile xdata reg_ipc_alive_sub_cnt, reg_ipc_alive_sub_service[2];
extern unsigned char volatile xdata reg_ipc_reliable_stbc_cnt, reg_ipc_reliable_main_cnt, reg_ipc_reliable_sub_cnt, DAT_EXTMEM_f24c;
extern unsigned char volatile xdata DAT_EXTMEM_f150, DAT_EXTMEM_f152, DAT_EXTMEM_f00a;
extern unsigned char xdata sys_watch_token;
extern unsigned int xdata sys_watch_ring1_ticks, sys_watch_ring2_ticks;
extern bit sys_shared_bit_param;
extern unsigned int timer_get_ticks(void);
extern void lib_printf517(void *fmt, ...) large;
extern void sys_stop_leon2m(void);
extern void sys_stop_leon2s(void);
extern void power_off_sequence(void);

/* Watch the two alive rings of the shared bytes at XDATA 0xF200.. and shut everything down when one stops.
 * Called by sys_main once at start-up with sys_shared_bit_param set, then on every pass of its loop while the run
 * state is RUNNING, with the bit clear.
 *
 * A ring is three bytes: the 8051 writes a token into the first ("stbc"), the main processor copies it into the
 * second ("main"; ipc_signal_alive copies 0xF204 -> 0xF208 and 0xF240 -> 0xF244), and the input processor copies
 * that into the third ("sub"; for example in its dp_mst_read_payload_words, 0xF208 -> 0xF20C). When the third byte
 * equals the first, the token has gone round: the 8051 writes the next token and notes the tick count.
 *
 * In order:
 *   1. When either service pair (0xF209/0xF20A, 0xF20D/0xF20E) holds 0x87 0x78, ring 1's stamp is renewed and
 *      nothing else is checked.
 *   2. With sys_shared_bit_param set, both stamps are renewed.
 *   3. Ring 1 (0xF204 / 0xF208 / 0xF20C): a completed round sends token + 7 and renews stamp 1.
 *   4. Ring 2 (0xF240 / 0xF244 / 0xF248): the same with token + 13, unless 0xF24C holds 0x87. Both rings take their
 *      next token from the same counter.
 *   5. More than 15000 ticks since stamp 1 or 10000 since stamp 2: print "###SYSTEM CRASH, RESET###" and the
 *      three bytes of each ring, stop both LEON processors, run power_off_sequence, write 0x55 to 0xF00A and stop
 *      here for good (endless loop, no return to sys_main).
 */
void sys_watch_main_core(void)
{
    /* 1. Service pairs. */
    if (reg_ipc_alive_main_service[0] == SERVICE_MARK_0 && reg_ipc_alive_main_service[1] == SERVICE_MARK_1) {
        sys_watch_ring1_ticks = timer_get_ticks();
        return;
    }
    if (reg_ipc_alive_sub_service[0] == SERVICE_MARK_0 && reg_ipc_alive_sub_service[1] == SERVICE_MARK_1) {
        sys_watch_ring1_ticks = timer_get_ticks();
        return;
    }
    /* 2. Start-up: begin both time-outs now. */
    if (sys_shared_bit_param) {
        sys_watch_ring1_ticks = timer_get_ticks();
        sys_watch_ring2_ticks = timer_get_ticks();
    }
    /* 3. Ring 1 round complete? */
    if (reg_ipc_alive_stbc_cnt == reg_ipc_alive_sub_cnt) {
        sys_watch_token += RING1_TOKEN_STEP;
        reg_ipc_alive_stbc_cnt = sys_watch_token;
        sys_watch_ring1_ticks = timer_get_ticks();
    }
    /* 4. Ring 2 round complete? */
    if (reg_ipc_reliable_stbc_cnt == reg_ipc_reliable_sub_cnt && DAT_EXTMEM_f24c != RING2_HOLD_MARK) {
        sys_watch_token += RING2_TOKEN_STEP;
        reg_ipc_reliable_stbc_cnt = sys_watch_token;
        sys_watch_ring2_ticks = timer_get_ticks();
    }
    /* 5. Time-out: report, shut down, stop. */
    if (timer_get_ticks() - sys_watch_ring1_ticks > RING1_TIMEOUT_TICKS || timer_get_ticks() - sys_watch_ring2_ticks > RING2_TIMEOUT_TICKS) {
        lib_printf517((void code *)0x55f5);    /* "###SYSTEM CRASH, RESET###\r\n" */
        lib_printf517((void code *)0x5611, (unsigned int)reg_ipc_alive_stbc_cnt, (unsigned int)reg_ipc_alive_main_cnt,
                      (unsigned int)reg_ipc_alive_sub_cnt);    /* "stbc cnt = %02x, main cnt = %02x, sub_cnt = %02x\r\n" */
        lib_printf517((void code *)0x5644, (unsigned int)reg_ipc_reliable_stbc_cnt, (unsigned int)reg_ipc_reliable_main_cnt,
                      (unsigned int)reg_ipc_reliable_sub_cnt);    /* "stbc relible cnt = ..." */
        sys_stop_leon2m();
        sys_stop_leon2s();
        DAT_EXTMEM_f150 = STOP_REG_F150_VALUE;
        DAT_EXTMEM_f152 |= STOP_REG_F152_BIT6;
        power_off_sequence();
        DAT_EXTMEM_f00a = PASS_MARK;
        for (;;) ;
    }
}
