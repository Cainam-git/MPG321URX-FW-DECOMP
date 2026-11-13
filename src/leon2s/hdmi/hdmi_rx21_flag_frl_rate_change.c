/* hdmi_rx21_flag_frl_rate_change  (FUN_a009f5c8)
 *
 * Flag an HDMI 2.1 receiver whose FRL rate changed after link training.
 *   port: HDMI 2.1 receiver 0/1
 * Name basis: derived - rate bits 24..27 of word 0x90 differ from the stored rate while the state is past 4
 *   and not 7
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009f5c8, flags -mcpu=v8 -Os -g (section default).
 * Source form: the block behind the block6 pointer is read through a volatile pointer; a plain pointer narrows the
 * word load and shift to a byte load.
 */
/* Register block addresses of an HDMI 2.1 receiver (13 words per receiver, table at 0xA807DB00). */
struct hdmi_rx21_reg_blocks {
    unsigned char block0_5[0x18];
    volatile unsigned int *block6;      /* +0x18: 0xCE009600 (+0x1000 for receiver 1) */
    unsigned char block7_12[0x34 - 0x1c];
};

/* Link training record of one receiver (0xB0 bytes, table at 0xA807D680): the field used here. */
struct hdmi_rx21_lts_record {
    unsigned char lane_count;           /* +0 */
    unsigned char frl_rate;             /* +1 */
    unsigned char frl_rate_in_phy;      /* +2: the rate set in the PHY */
    unsigned char rest[0xb0 - 3];
};

#define B6_LTS_STATUS         (0x90 / 4)    /* word of block 6; bits 24..27 = FRL rate */
#define LTS_STATE_AFTER_TRAIN 4             /* states above this are past the link training */
#define RX_DETECT_LTS_L       7

extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern struct hdmi_rx21_lts_record hdmi_rx21_lts_records[];
extern unsigned char hdmi_rx21_frl_rate_change_flags[];
extern unsigned char hdmi_rx21_frl_rate_restart_requests[];
extern unsigned int hdmi_rx21_rx_detect_states[];

/*
 * Set hdmi_rx21_frl_rate_restart_requests[port] to 1 when the FRL rate in bits 24..27 of block 6 word 0x90 is no longer the rate
 * stored in the link training record (frl_rate_in_phy), the receiver's hdmi_rx21_frl_rate_change_flags entry
 * is set and its link-training state is above 4 and not 7. hdmi_rx21_run_rx_detect_fsm reads hdmi_rx21_frl_rate_restart_requests.
 *   port  HDMI 2.1 receiver 0/1
 */
void hdmi_rx21_flag_frl_rate_change(unsigned char port)
{
    if (((ARR_a807db00[port].block6[B6_LTS_STATUS] >> 24) & 0xf) != hdmi_rx21_lts_records[port].frl_rate_in_phy
        && hdmi_rx21_frl_rate_change_flags[port] != 0
        && hdmi_rx21_rx_detect_states[port] > LTS_STATE_AFTER_TRAIN
        && hdmi_rx21_rx_detect_states[port] != RX_DETECT_LTS_L)
        hdmi_rx21_frl_rate_restart_requests[port] = 1;
}
