/* sys_dsc_dec_run_state  (FUN_a00a4880)
 *
 * Run the DSC decoder state machine: detect a compressed source, set up, watch.
 *   decoder
 * Name basis: derived - five states on 0xA807DC10; sys_dsc_dec_build_hdmi21_config, VBP_tmp (=
 *   sys_dsc_dec_write_config); caller input_poll_port_services
 *
 * Matching notes
 * --------------
 * FUN_a00a4880 (leon2s, 0xa00a4880-0xa00a4e68, 1512 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - bit 12 of register 0xc0 is cleared through the volatile local mask (the firmware stores 0x1000 to its
 *    stack slot and reads it back before each clear; this also keeps the last call a normal call);
 *  - regs_main has type volatile unsigned long * (its alias set lets the state store sit between the read and
 *    the write of register 0xb4);
 *  - the bit-12 test is written (unsigned char)(word >> 12) & 1 (srl + btst 1);
 *  - states 2 and 3 are if / else-if chains with one "back to DSC_STATE_DETECT" arm per failed test;
 *  - sys_dsc_dec_is_hdmi21_mode_lost and sys_dsc_dec_is_source_absent are declared with unsigned char results
 *    (the firmware masks both results).
 */

/* The states of one decoder (word 0 of its state record). */
enum {
    DSC_STATE_DETECT        = 0,    /* look for a compressed source */
    DSC_STATE_HDMI21_FOUND  = 1,    /* HDMI 2.1 source with DSC: wait for the decoder, then build the set-up */
    DSC_STATE_HDMI21_SETTLE = 2,    /* wait more than 40 ticks, then write the set-up to the registers */
    DSC_STATE_CHKSUM_WAIT   = 3,    /* wait for register 0xb4 bit 2 to clear ("ChkSum Check Timeout") */
    DSC_STATE_ACTIVE        = 4     /* decoder running: watch the source */
};

/* Input codes in sys_dsc_dec_command_value (sent with mailbox command 0x74). */
#define INPUT_CODE_HDMI21_0     0x51
#define INPUT_CODE_HDMI21_1     0x61
#define INPUT_CODE_DP_0         0x71    /* DisplayPort input 0 */
#define INPUT_CODE_DP_1         0x81    /* DisplayPort input 1 */

#define DSC_CHKSUM_TRIES        3       /* passes through DSC_STATE_CHKSUM_WAIT before the timeout */
#define DSC_SETTLE_TICKS        40      /* ticks from building the set-up to writing it */
#define DSC_DP_WATCH_TICKS      20      /* ticks from starting a DisplayPort stream to the first check */

/* Word offsets in the decoder's first register block (regs_main). */
#define DSC_REG_B4  (0xb4 / 4)          /* bit 1 set after the set-up is written; bit 2 waited for in state 3 */
#define DSC_REG_C0  (0xc0 / 4)          /* bit 12 follows dp_is_high_rate_mode in DSC_STATE_ACTIVE */
#define DSC_REG_C0_HIGH_RATE 0x1000

/* Bit 0 of this register is set for 100 delay units right after the set-up has been written. */
#define REG_cf02dc10 (*(volatile unsigned int *)0xcf02dc10)

/* State record of one decoder (8 bytes; the same records are read by sys_dsc_dec_is_source_absent). */
struct dsc_state_record {
    unsigned int state;             /* DSC_STATE_* */
    unsigned char chksum_tries;     /* passes left in DSC_STATE_CHKSUM_WAIT */
    unsigned char byte_0x05;        /* 1 makes sys_dsc_dec_is_source_absent answer 1; cleared here */
    unsigned char pad[2];
};
/* One 12-byte record per decoder with the bases of its three register blocks. */
struct dsc_decoder_record {
    volatile unsigned long *regs_main;
    volatile unsigned int *regs_second;
    unsigned int regs_third;
};
extern struct dsc_state_record sys_dsc_dec_state_records[];
extern struct dsc_decoder_record sys_dsc_dec_records[];
extern unsigned char sys_dsc_dec_restart_flag;
extern unsigned char sys_dsc_dec_command_value;
extern unsigned int sys_dsc_dec_dp_start_ticks;     /* tick count when a DisplayPort stream was started */
extern unsigned int sys_dsc_dec_dp_check_pending;     /* 1 from that start until the first check */
extern unsigned int sys_dsc_dec_hdmi21_build_ticks[];         /* tick count when the HDMI 2.1 set-up was built */
extern unsigned char sys_dsc_dec_hdmi21_configs[][0x50];  /* set-up records built for HDMI 2.1 */
extern unsigned char sys_dsc_dec_reg_ratios[];        /* result of sys_dsc_dec_calc_reg_ratio */
extern unsigned char sys_dsc_dec_port_configs[][0x90]; /* set-up read back from the registers */

extern unsigned char sys_dsc_dec_is_hdmi21_source(unsigned char);
extern unsigned char sys_dsc_dec_is_dp_source(unsigned char);
extern unsigned char sys_dsc_dec_is_hdmi21_mode_lost(unsigned char);
extern unsigned int dp_start_stream(unsigned int, unsigned int);
extern unsigned int timer_get_ticks(void);
extern unsigned int sys_dsc_dec_status_bit0(unsigned char);
extern void sys_dsc_dec_copy_block(unsigned char);
extern unsigned char sys_dsc_dec_calc_reg_ratio(unsigned char);
extern void sys_dsc_dec_build_hdmi21_config(unsigned short *, unsigned int);
extern void sys_dsc_dec_write_config(unsigned char, unsigned char *, unsigned int);
extern void timer_delay_units(unsigned int);
extern void sys_dsc_dec_read_config(unsigned char, unsigned char *);
extern void sys_dsc_dec_set_regb4_bit1(void);
extern unsigned char sys_dsc_dec_get_regb4_bit2(void);
extern unsigned char dp_is_high_rate_mode(unsigned char);
extern unsigned char sys_dsc_dec_is_source_absent(unsigned char);
extern int dbg_printf(const char *, ...);

/*
 * One step of the state machine of a DSC decoder. Called once per main-loop pass by input_poll_port_services
 * with decoder 0. The input it follows is the input code in sys_dsc_dec_command_value: 0x51 / 0x61 are the
 * HDMI 2.1 inputs, 0x71 / 0x81 the DisplayPort inputs. Mailbox command 0x74 stores a new code and sets
 * sys_dsc_dec_restart_flag, which sends the machine back to DSC_STATE_DETECT at its next step.
 *
 *   decoder  decoder number (the timeout text calls it port 'A' + decoder)
 *
 * The states, in the order a source passes through them:
 *   DSC_STATE_DETECT      an HDMI 2.1 input that carries DSC and has a detected mode goes to
 *                         DSC_STATE_HDMI21_FOUND. A DisplayPort input with a stream goes straight to
 *                         DSC_STATE_ACTIVE; for code 0x71 / 0x81 its stream is started from scratch
 *                         (dp_start_stream(n, 1)) and the start time is noted. Either way the restart flag is
 *                         cleared. Without a source the machine stays here.
 *   DSC_STATE_HDMI21_FOUND
 *                         waits until word 0 of the second register block is non-zero or bit 0 of register
 *                         0xb0 is set. Then it copies the 24 words between the first two register blocks,
 *                         keeps sys_dsc_dec_calc_reg_ratio, notes the time and builds the set-up record.
 *   DSC_STATE_HDMI21_SETTLE
 *                         more than 40 ticks later: writes the set-up record to the decoder, pulses bit 0 of
 *                         register 0xCF02DC10 and sets bit 1 of register 0xb4.
 *   DSC_STATE_CHKSUM_WAIT up to three passes for bit 2 of register 0xb4 to clear. When it clears, the set-up is
 *                         read back from the registers and the decoder is DSC_STATE_ACTIVE; after three
 *                         passes "Port%c ChkSum Check Timeout" is printed and the machine starts again.
 *   DSC_STATE_ACTIVE      for a DisplayPort source: from 20 ticks after the start, a stream started in
 *                         DSC_STATE_DETECT gets bit 1 of register 0xb4 set once; after that a set bit 2 of that
 *                         register starts the stream again (dp_start_stream(n, 0)). Bit 12 of register 0xc0
 *                         follows dp_is_high_rate_mode of the input; for any other source it is cleared. When
 *                         sys_dsc_dec_is_source_absent answers 1 the machine starts again.
 * In states 2 and 3 losing the HDMI 2.1 source or its mode sends the machine back to DSC_STATE_DETECT.
 */
void sys_dsc_dec_run_state(unsigned char decoder)
{
    volatile unsigned int mask;

    if (sys_dsc_dec_restart_flag == 1)
        sys_dsc_dec_state_records[decoder].state = DSC_STATE_DETECT;
    switch (sys_dsc_dec_state_records[decoder].state) {
    case DSC_STATE_DETECT:
        if (sys_dsc_dec_is_hdmi21_source(sys_dsc_dec_command_value) != 0) {
            /* HDMI 2.1 with DSC: wait here (restart flag kept) until the input has a detected mode. */
            if (sys_dsc_dec_is_hdmi21_mode_lost(sys_dsc_dec_command_value) != 0)
                break;
            sys_dsc_dec_state_records[decoder].state = DSC_STATE_HDMI21_FOUND;
        } else if (sys_dsc_dec_is_dp_source(sys_dsc_dec_command_value) != 0) {
            /* DisplayPort: start the stream from scratch and remember when. */
            if (sys_dsc_dec_command_value == INPUT_CODE_DP_0) {
                dp_start_stream(0, 1);
                sys_dsc_dec_dp_check_pending = 1;
            } else if (sys_dsc_dec_command_value == INPUT_CODE_DP_1) {
                dp_start_stream(1, 1);
                sys_dsc_dec_dp_check_pending = 1;
            }
            sys_dsc_dec_dp_start_ticks = timer_get_ticks();
            sys_dsc_dec_state_records[decoder].state = DSC_STATE_ACTIVE;
        } else {
            /* No compressed source: stay, and keep the restart flag. */
            sys_dsc_dec_state_records[decoder].state = DSC_STATE_DETECT;
            break;
        }
        sys_dsc_dec_restart_flag = 0;
        break;
    case DSC_STATE_HDMI21_FOUND:
        if (sys_dsc_dec_is_hdmi21_source(sys_dsc_dec_command_value) != 0) {
            /* The state set here is always replaced by one of the two arms below. */
            if (sys_dsc_dec_is_hdmi21_mode_lost(sys_dsc_dec_command_value) == 1)
                sys_dsc_dec_state_records[decoder].state = DSC_STATE_DETECT;
            if (*sys_dsc_dec_records[decoder].regs_second == 0 && sys_dsc_dec_status_bit0(decoder) == 0) {
                /* Nothing from the decoder yet: try again next pass. */
                sys_dsc_dec_state_records[decoder].state = DSC_STATE_HDMI21_FOUND;
            } else {
                sys_dsc_dec_copy_block(decoder);
                sys_dsc_dec_reg_ratios[decoder] = sys_dsc_dec_calc_reg_ratio(decoder);
                sys_dsc_dec_hdmi21_build_ticks[decoder] = timer_get_ticks();
                sys_dsc_dec_build_hdmi21_config((unsigned short *)sys_dsc_dec_hdmi21_configs[decoder], sys_dsc_dec_command_value);
                sys_dsc_dec_state_records[decoder].state = DSC_STATE_HDMI21_SETTLE;
            }
        } else
            sys_dsc_dec_state_records[decoder].state = DSC_STATE_DETECT;
        break;
    case DSC_STATE_HDMI21_SETTLE:
        if (sys_dsc_dec_is_hdmi21_source(sys_dsc_dec_command_value) != 1)
            sys_dsc_dec_state_records[decoder].state = DSC_STATE_DETECT;
        else if (sys_dsc_dec_is_hdmi21_mode_lost(sys_dsc_dec_command_value) == 1)
            sys_dsc_dec_state_records[decoder].state = DSC_STATE_DETECT;
        else if (timer_get_ticks() - sys_dsc_dec_hdmi21_build_ticks[decoder] > DSC_SETTLE_TICKS) {
            /* Program the decoder from the record built in DSC_STATE_HDMI21_FOUND (0: not the defaults). */
            sys_dsc_dec_write_config(decoder, sys_dsc_dec_hdmi21_configs[decoder], 0);
            REG_cf02dc10 |= 1;
            timer_delay_units(100);
            REG_cf02dc10 &= ~1;
            sys_dsc_dec_state_records[decoder].chksum_tries = DSC_CHKSUM_TRIES;
            sys_dsc_dec_records[decoder].regs_main[DSC_REG_B4] |= 2;
            sys_dsc_dec_state_records[decoder].state = DSC_STATE_CHKSUM_WAIT;
        }
        break;
    case DSC_STATE_CHKSUM_WAIT:
        if (sys_dsc_dec_is_hdmi21_source(sys_dsc_dec_command_value) != 1)
            sys_dsc_dec_state_records[decoder].state = DSC_STATE_DETECT;
        else if (sys_dsc_dec_is_hdmi21_mode_lost(sys_dsc_dec_command_value) == 1)
            sys_dsc_dec_state_records[decoder].state = DSC_STATE_DETECT;
        else if (sys_dsc_dec_state_records[decoder].chksum_tries != 0) {
            sys_dsc_dec_state_records[decoder].chksum_tries--;
            if (!(sys_dsc_dec_records[decoder].regs_main[DSC_REG_B4] & 4)) {
                /* Bit 2 cleared: keep what the decoder now holds. */
                sys_dsc_dec_read_config(decoder, sys_dsc_dec_port_configs[decoder]);
                sys_dsc_dec_state_records[decoder].state = DSC_STATE_ACTIVE;
            }
        } else {
            sys_dsc_dec_state_records[decoder].state = DSC_STATE_DETECT;
            dbg_printf("Port%c ChkSum Check Timeout\n", (char)(decoder + 0x41));
        }
        break;
    case DSC_STATE_ACTIVE:
        if (sys_dsc_dec_is_dp_source(sys_dsc_dec_command_value) == 1) {
            if (timer_get_ticks() - sys_dsc_dec_dp_start_ticks > DSC_DP_WATCH_TICKS) {
                if (sys_dsc_dec_dp_check_pending == 1) {
                    /* First check after the start: bit 1 of register 0xb4 of decoder 0. */
                    sys_dsc_dec_dp_check_pending = 0;
                    sys_dsc_dec_set_regb4_bit1();
                } else if (sys_dsc_dec_get_regb4_bit2() != 0) {
                    /* Bit 2 of register 0xb4 of decoder 0 set: start the stream again. */
                    if (sys_dsc_dec_command_value == INPUT_CODE_DP_0)
                        dp_start_stream(0, 0);
                    else if (sys_dsc_dec_command_value == INPUT_CODE_DP_1)
                        dp_start_stream(1, 0);
                }
            }
            /* Make bit 12 of register 0xc0 follow dp_is_high_rate_mode of the input. */
            if (!((unsigned char)(sys_dsc_dec_records[decoder].regs_main[DSC_REG_C0] >> 12) & 1)) {
                if (sys_dsc_dec_command_value == INPUT_CODE_DP_0 && dp_is_high_rate_mode(0) == 1)
                    sys_dsc_dec_records[decoder].regs_main[DSC_REG_C0] |= DSC_REG_C0_HIGH_RATE;
                else if (sys_dsc_dec_command_value == INPUT_CODE_DP_1 && dp_is_high_rate_mode(1) == 1)
                    sys_dsc_dec_records[decoder].regs_main[DSC_REG_C0] |= DSC_REG_C0_HIGH_RATE;
            } else {
                if (sys_dsc_dec_command_value == INPUT_CODE_DP_0 && dp_is_high_rate_mode(0) == 0) {
                    mask = DSC_REG_C0_HIGH_RATE;
                    sys_dsc_dec_records[decoder].regs_main[DSC_REG_C0] &= ~mask;
                } else if (sys_dsc_dec_command_value == INPUT_CODE_DP_1 && dp_is_high_rate_mode(1) == 0) {
                    mask = DSC_REG_C0_HIGH_RATE;
                    sys_dsc_dec_records[decoder].regs_main[DSC_REG_C0] &= ~mask;
                }
            }
        } else {
            /* Not a DisplayPort source: bit 12 off. */
            if ((unsigned char)(sys_dsc_dec_records[decoder].regs_main[DSC_REG_C0] >> 12) & 1) {
                mask = DSC_REG_C0_HIGH_RATE;
                sys_dsc_dec_records[decoder].regs_main[DSC_REG_C0] &= ~mask;
            }
        }
        if (sys_dsc_dec_is_source_absent(decoder) == 1) {
            sys_dsc_dec_state_records[decoder].byte_0x05 = 0;
            sys_dsc_dec_state_records[decoder].state = DSC_STATE_DETECT;
        }
        break;
    }
}
