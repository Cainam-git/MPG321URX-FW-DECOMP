/* dp_tx_update_hpd_status  (FUN_a0083870)
 *
 * Read the hot-plug registers of the link outputs into the status byte and event word.
 *   mode: bit 0 status, bit 1 events
 * Name basis: derived - five HPD registers 0xCF018884..0xCF01A084 gated by the dp_tx_mode_requested_* getters;
 *   main-loop service
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0083870 @ 0xa0083870-0xa0083e28 (1464 bytes), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - the five registers are read once at entry into unsigned char locals, in register order;
 *  - each register is written back as (value & 0x3f) | bit, one write per event bit;
 *  - the edge tests of the HDMI transmitter bits are if / else-if chains, and the previous value of bit 1 is
 *    stored as (status >> 1) & 1.
 */

/* Hot-plug registers of the five link outputs, one per event group 0..4. Group 0 is output 0 ('DPTX');
   outputs 1..4 ('eDP') reach groups 1..4 through dp_tx_output_map (see dp_tx_get_hpd_event_bits). */
#define HPD_REG_0 (*(volatile unsigned int *)0xcf018884)
#define HPD_REG_1 (*(volatile unsigned int *)0xcf019484)
#define HPD_REG_2 (*(volatile unsigned int *)0xcf019884)
#define HPD_REG_3 (*(volatile unsigned int *)0xcf019c84)
#define HPD_REG_4 (*(volatile unsigned int *)0xcf01a084)

/* Bits of a hot-plug register (low byte). An event bit is written back with 1 to clear it. */
#define HPD_LINE        0x08    /* the hot-plug line: set = connected (dp_tx_is_connected) */
#define HPD_EVENT_A     0x40    /* event: plug when HPD_LINE is set, unplug when it is clear */
#define HPD_EVENT_B     0x80    /* event: bit 2 of the group (a sink check on a connected output) */
#define HPD_KEEP_BITS   0x3f    /* bits 0..5, kept in the write-back */

/* Argument bits. The only caller, input_poll_port_services, passes both (3) every main-loop pass. */
#define HPD_UPDATE_STATUS 1
#define HPD_UPDATE_EVENTS 2

/* dp_tx_hpd_status: one bit per output, published to the main processor (mailbox word 3, bits 8..15). */
#define HPD_STATUS_HDMI_TX0 0x01    /* hot-plug bit of HDMI transmitter 0 (bank 0 register 9, bit 1) */
#define HPD_STATUS_HDMI_TX1 0x02
#define HPD_STATUS_GROUP0   0x04    /* groups 0..4: HPD_LINE of the register */
#define HPD_STATUS_GROUP1   0x08
#define HPD_STATUS_GROUP2   0x10
#define HPD_STATUS_GROUP3   0x20
#define HPD_STATUS_GROUP4   0x40
#define HDMI_TX_REG_HPD     9       /* bank 0 register of an HDMI transmitter; bit 1 = HDMI_TX_HPD_BIT */
#define HDMI_TX_HPD_BIT     2

/* dp_tx_hpd_event_bits: three bits per group (PLUG, UNPLUG, B), two per HDMI transmitter (RISE, FALL). The
   hot-plug action routines read them with dp_tx_get_hpd_event_bits; every pass with HPD_UPDATE_EVENTS starts
   from zero. */
#define EVENT_PLUG      1       /* dp_tx_get_hpd_pulse returns HPD_PLUG ('IsHPDAction_On') for it */
#define EVENT_UNPLUG    2       /* ... HPD_UNPLUG ('IsHPDAction_Off') */
#define EVENT_B         4       /* tested by dp_tx_hpd_event_bit2 */
#define EVENT_RISE      1       /* HDMI transmitter status bit went 0 -> 1 */
#define EVENT_FALL      2       /* ... 1 -> 0 */
#define GROUP0_SHIFT    0
#define GROUP1_SHIFT    3
#define GROUP2_SHIFT    6
#define HDMI_TX0_SHIFT  9
#define HDMI_TX1_SHIFT  11
#define GROUP3_SHIFT    13
#define GROUP4_SHIFT    16
#define EVENT_BIT(kind, shift) ((kind) << (shift))

extern unsigned char dp_tx_hpd_status;
extern unsigned int dp_tx_hpd_event_bits;
extern unsigned char dp_tx_hpd_prev_bit0;
extern unsigned char dp_tx_hpd_prev_bit1;

extern unsigned char dp_tx_mode_requested_0(void);
extern unsigned char dp_tx_mode_requested_1(void);
extern unsigned char dp_tx_mode_requested_2(void);
extern unsigned char dp_tx_mode_requested_3(void);
extern unsigned char dp_tx_mode_requested_4(void);
extern unsigned char hdmi_tx_is_port0_enabled(void);
extern unsigned char hdmi_tx_is_port1_enabled(void);
extern short hdmi_tx_reg_read8(unsigned int param_1, unsigned short param_2, unsigned short param_3);

/*
 * Bring the hot-plug state of the link outputs and the two HDMI transmitters up to date.
 *
 *   mode  HPD_UPDATE_STATUS: refresh the status byte; HPD_UPDATE_EVENTS: collect the events of this pass
 *
 * A register group or HDMI transmitter takes part only while its bit in input_command_flags (the port action
 * flag byte from the main processor) is set: bits 2..6 for groups 0..4 (dp_tx_mode_requested_0..4), bits 0 and
 * 1 for HDMI transmitters 0 and 1.
 *
 * Phases:
 *   1. Read the five hot-plug registers once.
 *   2. Status: copy each group's line bit and each HDMI transmitter's hot-plug bit into dp_tx_hpd_status.
 *   3. Events: clear dp_tx_hpd_event_bits; for each group record and clear the register's event bits; for each
 *      HDMI transmitter compare its status bit with the value of the last pass and record a rise or fall.
 */
void dp_tx_update_hpd_status(unsigned char mode)
{
    /* 1. One read of each register; the event bits below come from these values. */
    unsigned char hpd0 = HPD_REG_0;
    unsigned char hpd1 = HPD_REG_1;
    unsigned char hpd2 = HPD_REG_2;
    unsigned char hpd3 = HPD_REG_3;
    unsigned char hpd4 = HPD_REG_4;

    /* 2. Status byte. */
    if (mode & HPD_UPDATE_STATUS) {
        if (dp_tx_mode_requested_0()) {
            if (hpd0 & HPD_LINE)
                dp_tx_hpd_status |= HPD_STATUS_GROUP0;
            else
                dp_tx_hpd_status &= ~HPD_STATUS_GROUP0;
        }
        if (dp_tx_mode_requested_1()) {
            if (hpd1 & HPD_LINE)
                dp_tx_hpd_status |= HPD_STATUS_GROUP1;
            else
                dp_tx_hpd_status &= ~HPD_STATUS_GROUP1;
        }
        if (dp_tx_mode_requested_2()) {
            if (hpd2 & HPD_LINE)
                dp_tx_hpd_status |= HPD_STATUS_GROUP2;
            else
                dp_tx_hpd_status &= ~HPD_STATUS_GROUP2;
        }
        if (dp_tx_mode_requested_3()) {
            if (hpd3 & HPD_LINE)
                dp_tx_hpd_status |= HPD_STATUS_GROUP3;
            else
                dp_tx_hpd_status &= ~HPD_STATUS_GROUP3;
        }
        if (dp_tx_mode_requested_4()) {
            if (hpd4 & HPD_LINE)
                dp_tx_hpd_status |= HPD_STATUS_GROUP4;
            else
                dp_tx_hpd_status &= ~HPD_STATUS_GROUP4;
        }
        if (hdmi_tx_is_port0_enabled()) {
            if (hdmi_tx_reg_read8(0, 0, HDMI_TX_REG_HPD) & HDMI_TX_HPD_BIT)
                dp_tx_hpd_status |= HPD_STATUS_HDMI_TX0;
            else
                dp_tx_hpd_status &= ~HPD_STATUS_HDMI_TX0;
        }
        if (hdmi_tx_is_port1_enabled()) {
            if (hdmi_tx_reg_read8(1, 0, HDMI_TX_REG_HPD) & HDMI_TX_HPD_BIT)
                dp_tx_hpd_status |= HPD_STATUS_HDMI_TX1;
            else
                dp_tx_hpd_status &= ~HPD_STATUS_HDMI_TX1;
        }
    }

    /* 3. Events of this pass. */
    if (mode & HPD_UPDATE_EVENTS) {
        dp_tx_hpd_event_bits = 0;
        if (dp_tx_mode_requested_0()) {
            if (hpd0 & HPD_EVENT_A) {
                HPD_REG_0 = (hpd0 & HPD_KEEP_BITS) | HPD_EVENT_A;
                if (hpd0 & HPD_LINE)
                    dp_tx_hpd_event_bits |= EVENT_BIT(EVENT_PLUG, GROUP0_SHIFT);
                else
                    dp_tx_hpd_event_bits |= EVENT_BIT(EVENT_UNPLUG, GROUP0_SHIFT);
            }
            if (hpd0 & HPD_EVENT_B) {
                HPD_REG_0 = (hpd0 & HPD_KEEP_BITS) | HPD_EVENT_B;
                dp_tx_hpd_event_bits |= EVENT_BIT(EVENT_B, GROUP0_SHIFT);
            }
        }
        if (dp_tx_mode_requested_1()) {
            if (hpd1 & HPD_EVENT_A) {
                HPD_REG_1 = (hpd1 & HPD_KEEP_BITS) | HPD_EVENT_A;
                if (hpd1 & HPD_LINE)
                    dp_tx_hpd_event_bits |= EVENT_BIT(EVENT_PLUG, GROUP1_SHIFT);
                else
                    dp_tx_hpd_event_bits |= EVENT_BIT(EVENT_UNPLUG, GROUP1_SHIFT);
            }
            if (hpd1 & HPD_EVENT_B) {
                HPD_REG_1 = (hpd1 & HPD_KEEP_BITS) | HPD_EVENT_B;
                dp_tx_hpd_event_bits |= EVENT_BIT(EVENT_B, GROUP1_SHIFT);
            }
        }
        if (dp_tx_mode_requested_2()) {
            if (hpd2 & HPD_EVENT_A) {
                HPD_REG_2 = (hpd2 & HPD_KEEP_BITS) | HPD_EVENT_A;
                if (hpd2 & HPD_LINE)
                    dp_tx_hpd_event_bits |= EVENT_BIT(EVENT_PLUG, GROUP2_SHIFT);
                else
                    dp_tx_hpd_event_bits |= EVENT_BIT(EVENT_UNPLUG, GROUP2_SHIFT);
            }
            if (hpd2 & HPD_EVENT_B) {
                HPD_REG_2 = (hpd2 & HPD_KEEP_BITS) | HPD_EVENT_B;
                dp_tx_hpd_event_bits |= EVENT_BIT(EVENT_B, GROUP2_SHIFT);
            }
        }
        if (dp_tx_mode_requested_3()) {
            if (hpd3 & HPD_EVENT_A) {
                HPD_REG_3 = (hpd3 & HPD_KEEP_BITS) | HPD_EVENT_A;
                if (hpd3 & HPD_LINE)
                    dp_tx_hpd_event_bits |= EVENT_BIT(EVENT_PLUG, GROUP3_SHIFT);
                else
                    dp_tx_hpd_event_bits |= EVENT_BIT(EVENT_UNPLUG, GROUP3_SHIFT);
            }
            if (hpd3 & HPD_EVENT_B) {
                HPD_REG_3 = (hpd3 & HPD_KEEP_BITS) | HPD_EVENT_B;
                dp_tx_hpd_event_bits |= EVENT_BIT(EVENT_B, GROUP3_SHIFT);
            }
        }
        if (dp_tx_mode_requested_4()) {
            if (hpd4 & HPD_EVENT_A) {
                HPD_REG_4 = (hpd4 & HPD_KEEP_BITS) | HPD_EVENT_A;
                if (hpd4 & HPD_LINE)
                    dp_tx_hpd_event_bits |= EVENT_BIT(EVENT_PLUG, GROUP4_SHIFT);
                else
                    dp_tx_hpd_event_bits |= EVENT_BIT(EVENT_UNPLUG, GROUP4_SHIFT);
            }
            if (hpd4 & HPD_EVENT_B) {
                HPD_REG_4 = (hpd4 & HPD_KEEP_BITS) | HPD_EVENT_B;
                dp_tx_hpd_event_bits |= EVENT_BIT(EVENT_B, GROUP4_SHIFT);
            }
        }
        /* HDMI transmitters: edges of the status bit, against the value stored on the last pass. */
        if (hdmi_tx_is_port0_enabled()) {
            if (dp_tx_hpd_prev_bit0 == 0 && (dp_tx_hpd_status & HPD_STATUS_HDMI_TX0))
                dp_tx_hpd_event_bits |= EVENT_BIT(EVENT_RISE, HDMI_TX0_SHIFT);
            else if (dp_tx_hpd_prev_bit0 == 1 && !(dp_tx_hpd_status & HPD_STATUS_HDMI_TX0))
                dp_tx_hpd_event_bits |= EVENT_BIT(EVENT_FALL, HDMI_TX0_SHIFT);
            dp_tx_hpd_prev_bit0 = dp_tx_hpd_status & HPD_STATUS_HDMI_TX0;
        }
        if (hdmi_tx_is_port1_enabled()) {
            if (dp_tx_hpd_prev_bit1 == 0 && (dp_tx_hpd_status & HPD_STATUS_HDMI_TX1))
                dp_tx_hpd_event_bits |= EVENT_BIT(EVENT_RISE, HDMI_TX1_SHIFT);
            else if (dp_tx_hpd_prev_bit1 == 1 && !(dp_tx_hpd_status & HPD_STATUS_HDMI_TX1))
                dp_tx_hpd_event_bits |= EVENT_BIT(EVENT_FALL, HDMI_TX1_SHIFT);
            dp_tx_hpd_prev_bit1 = (dp_tx_hpd_status >> 1) & 1;
        }
    }
}
