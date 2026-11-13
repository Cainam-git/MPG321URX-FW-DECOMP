/* hdmi_tx_run_step  (FUN_a00950a0)
 *
 * Carry out one numbered set-up step (0..17) of an HDMI TX port.
 *   port: HDMI TX port
 *   cmd: step number
 * Name basis: derived - switch over the TX record; steps match the '(1) Input Source Selection' .. '(9) Check
 *   PSTABLE' prints
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00950a0 @ 0xa00950a0-0xa009584c (1964 bytes; jump table 0xa0095058), flags -mcpu=v8 -Os -g
 * (section default).
 * Source forms the exact build depends on:
 *  - old-style definition with unsigned char port and step (masked at every use);
 *  - the channel record is a union of a word view and a byte view, each field read again from the table;
 *  - in step 7 the bound 5 is held in the local limit, and rate_5_up is set to 0 before 'if (frl_rate >= limit)
 *    rate_5_up = 1;' inside the frl_rate > 3 arm, with an explicit else arm setting both flags to 0 (gives the
 *    cmp/subx store flag).
 */

/* The set-up steps. hdmi_tx_run_setup_steps runs them in its numbered phases, printed as '[HDMI_TX]: (n)'. */
enum hdmi_tx_step {
    TX_STEP_SELECT_SOURCE      = 0,     /* '(1) Input Source Selection' */
    TX_STEP_PACKETS_BYPASS     = 1,     /* '(2) Packet Configuration' with packet_bypass set */
    TX_STEP_PACKETS_OWN_AVI    = 2,     /* '(2) Packet Configuration' with packet_bypass clear */
    TX_STEP_PACKETS_OFF        = 3,
    TX_STEP_PACKETS_ON         = 4,     /* '(8) Packet Enable/Disable' */
    TX_STEP_CLOCK_SOURCE_TMDS  = 5,     /* '(3) Clock Source Configuration', frl_mode clear */
    TX_STEP_CLOCK_SOURCE_FRL   = 6,     /* '(3) Clock Source Configuration', frl_mode set */
    TX_STEP_PHY_CLOCK          = 7,     /* '(7) HTX PHY CLK Configuration' */
    TX_STEP_PHY_POWER_ON       = 8,     /* '(6) HTX PHY Power ON' */
    TX_STEP_STOP               = 9,     /* used by hdmi_tx_run_setup_steps and hdmi_tx_service_port */
    TX_STEP_LINK_TMDS          = 10,    /* '(5) HTX PHY+Link Configuration', 'TMDS Mode' */
    TX_STEP_LINK_FRL           = 11,    /* '(5) ...', 'FRL Mode' */
    TX_STEP_DSC                = 12,    /* '(5) ...', 'DSC Enable' */
    TX_STEP_REG7C_ON           = 13,    /* '(9) Check PSTABLE/Timing' */
    TX_STEP_REG7C_OFF          = 14,
    TX_STEP_RESET_KEEP_PACKETS = 15,    /* '(9) Check PSTABLE/Timing' */
    TX_STEP_INIT_CORE_REGS     = 16,    /* hdmi_tx_init */
    TX_STEP_INPUT_TIMING       = 17     /* '(4) HTX Link_Input_Timing' */
};

/* Input codes (byte +1 or +0x17 of the TX channel record). */
enum {
    INPUT_CODE_DP_0 = 0x71,
    INPUT_CODE_DP_1 = 0x81,
    SOURCE_CODE_E1  = 0xe1              /* with 0xE1 / 0xE2 the input code is in byte +0x17 */
};

/* Bits of the channel record's words (struct hdmi_tx_channel_record in hdmi_tx_apply_pending_request). */
#define CTRL_BIT30_SHIFT      30        /* word 0: ctrl_bit30 */
#define FRL_MODE_SHIFT        4         /* word 0: frl_mode */
#define CHANNEL_DSC_ENABLE    0x08      /* word 0: dsc_enable */
#define CHANNEL_BIT0          0x01      /* word 0: bit0 */
#define PACKET_SPD            0x40      /* word 0x10: spd_packet */
#define PACKET_AUDIO          0x20      /* word 0x10: audio_packet */
#define PACKET_MPEG           0x10      /* word 0x10: mpeg_packet */
#define PACKET_PPS            0x08      /* word 0x10: pps_packet */
#define WORD14_BIT11          0x800
#define WORD14_BIT12          0x1000    /* with ctrl_bit31 it lets hdmi_tx_run_setup_steps work */

#define DEPTH_8_BITS          8         /* bits per colour */
#define CHIP_REV_81           0x81      /* sys_get_chip_revision: revisions above take the other path */
#define FRL_RATE_LOW_MAX      3         /* frl_rate above this: first flag of hdmi_tx_phy_switch_power */
#define FRL_RATE_SECOND_HIGH  5         /* frl_rate 5 and above: second flag */
#define BANK4_VALUE_ABOVE_100 0x15E     /* hdmi_tx_bank4_value for a pixel clock above 100 MHz */
#define BANK4_VALUE_UP_TO_100 0xB4

/* TX channel record of one HDMI output (28 bytes, hdmi_tx_output_records), seen as words and as bytes. */
struct hdmi_tx_channel_words {
    unsigned int word0;
    unsigned char bytes_0x4[4];
    int pixel_clock;                    /* +8, in MHz (hdmi_tx_phy_tune_for_tmds_clock) */
    unsigned char bytes_0xc[4];
    unsigned int word_0x10;
    unsigned int word_0x14;
    unsigned short half_0x18;           /* written by TX_STEP_INPUT_TIMING */
    unsigned char bytes_0x1a[2];
};
struct hdmi_tx_channel_bytes {
    unsigned char byte_0x0, source_code, audio_source;
    unsigned char bytes_0x3[0x11 - 3];
    unsigned char color_depth;          /* +0x11 */
    unsigned char bytes_0x12[3];
    unsigned char frl_rate;             /* +0x15 */
    unsigned char byte_0x16;
    unsigned char input_code;           /* +0x17 */
    unsigned char bytes_0x18[4];
};
union hdmi_tx_channel_record { struct hdmi_tx_channel_words w; struct hdmi_tx_channel_bytes b; };
extern union hdmi_tx_channel_record hdmi_tx_output_records[];
extern unsigned int hdmi_tx_bank4_value;
extern unsigned short dsc_encoder_record_height;
#define REG_CF02DC10 (*(volatile unsigned int *)0xcf02dc10)    /* bit 3 pulsed before the PPS packet is enabled */
extern void hdmi_tx_select_link_source(unsigned char);
extern void CONV2HDMITX_UpdateInterface(unsigned char, union hdmi_tx_channel_record *);
extern void HDMITX_PacketSwitch_Bypass(unsigned int, unsigned int);
extern void hdmi_tx_set_color_depth(unsigned int, int);
extern unsigned char hdmi_tx_set_packet_switch(unsigned char, unsigned char, unsigned char, unsigned short, unsigned char, unsigned char);
extern void hdmi_tx_send_avi_infoframe(unsigned char);
extern void hdmi_tx_setup_audio(unsigned char, unsigned char);
extern void hdmi_tx_set_sync_polarity(unsigned char);
extern void hdmi_tx_set_reg_f1_f2_bit0(unsigned int);
extern void hdmi_tx_enable_avi_packet(unsigned char, unsigned char);
extern void hdmi_tx_enable_extra_infoframe(unsigned char, unsigned char);
extern void hdmi_tx_enable_audio_infoframe(unsigned char, unsigned char);
extern void hdmi_tx_enable_packet_bits67(unsigned char, unsigned char);
extern void hdmi_tx_enable_pps_packet(unsigned char, unsigned char);
extern int dbg_print_string(const char *);
extern void timer_delay_units(unsigned int);
extern void hdmi_tx_select_source_port(unsigned char, unsigned char, unsigned char);
extern void hdmi_tx_set_source_route_bits(unsigned char, unsigned char, unsigned char);
extern void hdmi_tx_set_frl_clock(unsigned char, unsigned char);
extern void hdmi_tx_setup_clock_path(unsigned char, unsigned char, unsigned char);
extern unsigned char sys_get_chip_revision(void);
extern void hdmi_tx_reg_update_bits(unsigned int, unsigned int, short, unsigned int, unsigned int);
extern void hdmi_tx_phy_switch_power(unsigned char, unsigned char, unsigned char, unsigned char);
extern void hdmi_tx_phy_enable_outputs(unsigned char, unsigned char);
extern void hdmi_tx_phy_power_down(unsigned char);
extern void hdmi_tx_stop_packets(unsigned char);
extern void hdmi_tx_set_reg7c_low_nibble(unsigned char, unsigned char);
extern void hdmi_tx_reg_write_field(unsigned char, unsigned char, unsigned short, unsigned int, unsigned int);
extern void hdmi_tx_clear_active(unsigned char);
extern void hdmi_tx_set_reg8_bits45(unsigned char);
extern void hdmi_tx_phy_tune_for_tmds_clock(unsigned char, int);
extern void hdmi_tx_set_low_clock_bits(unsigned char, unsigned char, int);
extern void hdmi_tx_set_bank4_mode(unsigned char, unsigned char, unsigned char);
extern void hdmi_tx_phy_setup_frl(unsigned char, unsigned char);
extern void hdmi_tx_set_regfd_mode(unsigned char, unsigned char);
extern void hdmi_tx_set_frl_reg28_bit2(unsigned char, unsigned char);
extern void hdmi_tx_set_frl_reg28_bits(unsigned char, unsigned char);
extern void hdmi_tx_set_bank4_offsets(unsigned char, unsigned int);
extern void hdmi_tx_pulse_regf1_bit7(unsigned char);
extern void hdmi_tx_build_pps_packet(unsigned char);
extern void hdmi_tx_dsc_setup(unsigned char);
extern void hdmi_tx_reset_keep_packets(unsigned char);
extern void hdmi_tx_init_core_regs(unsigned char);
extern short hdmi_tx_reg_read8(unsigned int, unsigned short, unsigned short);

/*
 * Carry out one set-up step of an HDMI output.
 *
 *   port  HDMI TX port 0 or 1
 *   step  enum hdmi_tx_step; other values do nothing
 *
 * Called by hdmi_tx_run_setup_steps (the sequence of steps), hdmi_tx_service_port (TX_STEP_STOP) and
 * hdmi_tx_init (TX_STEP_INIT_CORE_REGS). The TX channel record of the port is changed by steps 1 (through
 * CONV2HDMITX_UpdateInterface), 9 and 17.
 *
 * In short, the steps:
 *   source      0  select the input (hdmi_tx_select_link_source).
 *   packets     1  take the format of the input (CONV2HDMITX_UpdateInterface) and pass its packets through
 *                  (HDMITX_PacketSwitch_Bypass); 2 set the three packet groups for the input and send an own
 *                  AVI InfoFrame. Both set the colour depth (8 with dsc_enable, and in step 1 also with
 *                  ctrl_bit30), the audio (when audio_packet is set) and the sync polarity.
 *               3  all packets off; 4 the AVI packet and each packet whose bit is set on.
 *   clocks      5 / 6  connect the input as clock source (TMDS / FRL with its link clock); 7 the clock path and
 *                  PHY power order; 8 PHY outputs on.
 *   link       10  TMDS: PHY tuned for the TMDS clock (pixel_clock * color_depth / 8); 11 FRL: PHY and bank 4
 *                  set-up for the FRL rate; 12 DSC: HDR dynamic metadata packet, DSC set-up, 8 bits.
 *   stop        9  PHY power down, packets off, port marked not active, word 0x14 bit 11 set and bit 12 cleared.
 *   misc       13 / 14  register 0x7C low nibble and bank 1 register 0xD bits 3..7 set / cleared;
 *              15  transmitter reset keeping the packets; 16 core register start values;
 *              17  half_0x18: the DSC encoder record's picture height with dsc_enable, else bank 0 registers
 *                  0x62 (low) and 0x63 (high).
 */
void hdmi_tx_run_step(port, step)
    unsigned char port, step;
{
    unsigned char frl_rate, rate_4_up, rate_5_up;
    unsigned int low_byte;
    unsigned int word0;
    unsigned char limit;

    switch (step) {
    case TX_STEP_SELECT_SOURCE:
        hdmi_tx_select_link_source(port);
        break;
    case TX_STEP_PACKETS_BYPASS:
        CONV2HDMITX_UpdateInterface(port, &hdmi_tx_output_records[port]);
        HDMITX_PacketSwitch_Bypass(port, hdmi_tx_output_records[port].b.input_code);
        if (((unsigned char)(hdmi_tx_output_records[port].w.word0 >> CTRL_BIT30_SHIFT) & 1) || (hdmi_tx_output_records[port].w.word0 & CHANNEL_DSC_ENABLE))
            hdmi_tx_set_color_depth(port, DEPTH_8_BITS);
        else
            hdmi_tx_set_color_depth(port, hdmi_tx_output_records[port].b.color_depth);
        if (hdmi_tx_output_records[port].w.word_0x10 & PACKET_AUDIO)
            hdmi_tx_setup_audio(port, hdmi_tx_output_records[port].b.audio_source);
        hdmi_tx_set_sync_polarity(port);
        hdmi_tx_set_reg_f1_f2_bit0(port);
        break;
    case TX_STEP_PACKETS_OWN_AVI:
        if (!(hdmi_tx_output_records[port].w.word0 & CHANNEL_DSC_ENABLE))
            hdmi_tx_set_color_depth(port, hdmi_tx_output_records[port].b.color_depth);
        else
            hdmi_tx_set_color_depth(port, DEPTH_8_BITS);
        /* The three packet groups for the input code (byte +0x17 when the source code is 0xE1 / 0xE2). */
        if ((unsigned char)(hdmi_tx_output_records[port].b.source_code - SOURCE_CODE_E1) <= 1) {
            hdmi_tx_set_packet_switch(0, hdmi_tx_output_records[port].b.input_code, port, 0, 1, 0);
            hdmi_tx_set_packet_switch(1, hdmi_tx_output_records[port].b.input_code, port, 0x27, 0, 0);
            hdmi_tx_set_packet_switch(2, hdmi_tx_output_records[port].b.input_code, port, 0, 0, 0);
        } else {
            hdmi_tx_set_packet_switch(0, hdmi_tx_output_records[port].b.source_code, port, 0, 1, 0);
            hdmi_tx_set_packet_switch(1, hdmi_tx_output_records[port].b.source_code, port, 0x27, 0, 0);
            hdmi_tx_set_packet_switch(2, hdmi_tx_output_records[port].b.source_code, port, 0, 0, 0);
        }
        /* A DisplayPort input behind code 0xE1 / 0xE2: group 0 once more with the last flag set. */
        if ((unsigned char)(hdmi_tx_output_records[port].b.source_code - SOURCE_CODE_E1) <= 1 &&
            (hdmi_tx_output_records[port].b.input_code == INPUT_CODE_DP_0 || hdmi_tx_output_records[port].b.input_code == INPUT_CODE_DP_1))
            hdmi_tx_set_packet_switch(0, hdmi_tx_output_records[port].b.input_code, port, 0, 0, 1);
        hdmi_tx_send_avi_infoframe(port);
        if (hdmi_tx_output_records[port].w.word_0x10 & PACKET_AUDIO)
            hdmi_tx_setup_audio(port, hdmi_tx_output_records[port].b.audio_source);
        hdmi_tx_set_sync_polarity(port);
        hdmi_tx_set_reg_f1_f2_bit0(port);
        break;
    case TX_STEP_PACKETS_OFF:
        hdmi_tx_enable_avi_packet(port, 0);
        hdmi_tx_enable_extra_infoframe(port, 0);
        hdmi_tx_enable_audio_infoframe(port, 0);
        hdmi_tx_enable_packet_bits67(port, 0);
        hdmi_tx_enable_pps_packet(port, 0);
        break;
    case TX_STEP_PACKETS_ON:
        hdmi_tx_enable_avi_packet(port, 1);
        dbg_print_string("\033[0m\t\t - AVI Packet Enable \n");
        if (hdmi_tx_output_records[port].w.word_0x10 & PACKET_SPD) {
            hdmi_tx_enable_extra_infoframe(port, 1);
            dbg_print_string("\033[0m\t\t - SPD Packet Enable \n");
        }
        if (hdmi_tx_output_records[port].w.word_0x10 & PACKET_AUDIO) {
            hdmi_tx_enable_audio_infoframe(port, 1);
            dbg_print_string("\033[0m\t\t - Audio INFO Packet Enable \n");
        }
        if (hdmi_tx_output_records[port].w.word_0x10 & PACKET_MPEG) {
            hdmi_tx_enable_packet_bits67(port, 1);
            dbg_print_string("\033[0m\t\t - MPEG Packet Enable \n");
        }
        if (hdmi_tx_output_records[port].w.word_0x10 & PACKET_PPS) {
            REG_CF02DC10 |= 8;
            timer_delay_units(100);
            REG_CF02DC10 &= ~8;
            hdmi_tx_enable_pps_packet(port, 1);
            dbg_print_string("\033[0m\t\t - PPS Packet Enable \n");
        }
        break;
    case TX_STEP_CLOCK_SOURCE_TMDS:
        hdmi_tx_select_source_port(port, hdmi_tx_output_records[port].b.source_code, hdmi_tx_output_records[port].w.word0 & CHANNEL_BIT0);
        break;
    case TX_STEP_CLOCK_SOURCE_FRL:
        hdmi_tx_select_source_port(port, hdmi_tx_output_records[port].b.source_code, 0);
        hdmi_tx_set_source_route_bits(port, hdmi_tx_output_records[port].b.source_code, 0);
        hdmi_tx_set_frl_clock(port, hdmi_tx_output_records[port].b.frl_rate);
        break;
    case TX_STEP_PHY_CLOCK:
        /* Clock path, and bank 3 register 0xF2 bit 2 (set only with ctrl_bit30, frl_mode and a revision
           above 0x81; on older chips it is left alone when ctrl_bit30 is clear). */
        word0 = hdmi_tx_output_records[port].w.word0;
        if (!((unsigned char)(word0 >> CTRL_BIT30_SHIFT) & 1)) {
            hdmi_tx_setup_clock_path(port, (word0 >> FRL_MODE_SHIFT) & 1, hdmi_tx_output_records[port].b.color_depth);
            if (sys_get_chip_revision() > CHIP_REV_81)
                hdmi_tx_reg_update_bits(port, 3, 0xf2, 4, 0);
        } else {
            if (((unsigned char)(word0 >> FRL_MODE_SHIFT) & 1) && sys_get_chip_revision() > CHIP_REV_81)
                hdmi_tx_reg_update_bits(port, 3, 0xf2, 4, 1);
            else
                hdmi_tx_reg_update_bits(port, 3, 0xf2, 4, 0);
            hdmi_tx_setup_clock_path(port, (hdmi_tx_output_records[port].w.word0 >> FRL_MODE_SHIFT) & 1, DEPTH_8_BITS);
        }
        /* PHY power order by the FRL rate: two flags for rates 4 and up and 5 and up. */
        frl_rate = hdmi_tx_output_records[port].b.frl_rate;
        limit = FRL_RATE_SECOND_HIGH;
        if (frl_rate > FRL_RATE_LOW_MAX) {
            rate_4_up = 1;
            rate_5_up = 0;
            if (frl_rate >= limit)
                rate_5_up = 1;
        } else {
            rate_4_up = 0;
            rate_5_up = 0;
        }
        hdmi_tx_phy_switch_power(port, (hdmi_tx_output_records[port].w.word0 >> FRL_MODE_SHIFT) & 1, rate_4_up & 1, rate_5_up & 1);
        break;
    case TX_STEP_PHY_POWER_ON:
        hdmi_tx_phy_enable_outputs(port, (hdmi_tx_output_records[port].w.word0 >> FRL_MODE_SHIFT) & 1);
        break;
    case TX_STEP_STOP:
        hdmi_tx_phy_power_down(port);
        hdmi_tx_stop_packets(port);
        hdmi_tx_set_reg7c_low_nibble(port, 0);
        hdmi_tx_reg_write_field(port, 1, 0xd, 0xf8, 0);
        hdmi_tx_clear_active(port);
        hdmi_tx_output_records[port].w.word_0x14 = (hdmi_tx_output_records[port].w.word_0x14 | WORD14_BIT11) & ~WORD14_BIT12;
        break;
    case TX_STEP_LINK_TMDS:
        hdmi_tx_set_reg8_bits45(port);
        hdmi_tx_phy_tune_for_tmds_clock(port, hdmi_tx_output_records[port].w.pixel_clock * hdmi_tx_output_records[port].b.color_depth / 8);
        hdmi_tx_set_low_clock_bits(port, hdmi_tx_output_records[port].b.color_depth, hdmi_tx_output_records[port].w.pixel_clock);
        break;
    case TX_STEP_LINK_FRL:
        hdmi_tx_set_bank4_mode(port, hdmi_tx_output_records[port].b.frl_rate, (hdmi_tx_output_records[port].w.word0 >> 3) & 1);
        hdmi_tx_phy_setup_frl(port, hdmi_tx_output_records[port].b.frl_rate);
        hdmi_tx_set_regfd_mode(port, (hdmi_tx_output_records[port].w.word0 >> CTRL_BIT30_SHIFT) & 1);
        hdmi_tx_set_frl_reg28_bit2(port, 1);
        hdmi_tx_set_frl_reg28_bits(port, 1);
        if (hdmi_tx_output_records[port].w.pixel_clock > 100)
            hdmi_tx_bank4_value = BANK4_VALUE_ABOVE_100;
        else
            hdmi_tx_bank4_value = BANK4_VALUE_UP_TO_100;
        hdmi_tx_set_bank4_offsets(port, hdmi_tx_bank4_value);
        hdmi_tx_pulse_regf1_bit7(port);
        break;
    case TX_STEP_DSC:
        hdmi_tx_build_pps_packet(port);
        hdmi_tx_dsc_setup(port);
        hdmi_tx_set_color_depth(port, DEPTH_8_BITS);
        break;
    case TX_STEP_REG7C_ON:
        hdmi_tx_set_reg7c_low_nibble(port, 1);
        hdmi_tx_reg_write_field(port, 1, 0xd, 0xf8, 0xf8);
        break;
    case TX_STEP_REG7C_OFF:
        hdmi_tx_set_reg7c_low_nibble(port, 0);
        hdmi_tx_reg_write_field(port, 1, 0xd, 0xf8, 0);
        break;
    case TX_STEP_RESET_KEEP_PACKETS:
        hdmi_tx_reset_keep_packets(port);
        break;
    case TX_STEP_INIT_CORE_REGS:
        hdmi_tx_init_core_regs(port);
        break;
    case TX_STEP_INPUT_TIMING:
        if (hdmi_tx_output_records[port].w.word0 & CHANNEL_DSC_ENABLE) {
            hdmi_tx_output_records[port].w.half_0x18 = dsc_encoder_record_height;
        } else {
            low_byte = (unsigned char)hdmi_tx_reg_read8(port, 0, 0x62);
            hdmi_tx_output_records[port].w.half_0x18 = ((unsigned char)hdmi_tx_reg_read8(port, 0, 0x63) << 8) + low_byte;
        }
        break;
    }
}
