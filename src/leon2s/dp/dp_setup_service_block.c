/* dp_setup_service_block  (FUN_a00ad478)
 *
 * Write the service block registers with a factor of 1 or 8 and update the service flags.
 * Name basis: descriptive - registers 0xCF0132C0..0xCF0132D8
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ad478 @ 0xa00ad478, flags -mcpu=v8 -Os -g.
 */
/* The byte 0x11E of a DP port record; the other bytes are not used here. */
struct dp_input_record {
    unsigned char before_0x11e[0x11e];
    unsigned char byte_0x11e;
    unsigned char after_0x11e[0x12c - 0x11f];
};
extern struct dp_input_record dp_input_records[];   /* one 300-byte record per port */
extern unsigned char dp_service_block_byte;     /* bit 0 = port 0, bit 1 = port 1 */
extern int dp_is_port_ready_for_service(int);
extern void dp_pulse_hpd_block(void);
extern void dp_set_service_flag(unsigned char);
extern void dp_clear_port_pending_bit(unsigned char);

#define REG_CF0132C0 (*(volatile unsigned int *)0xcf0132c0)
#define REG_CF0132C4 (*(volatile unsigned int *)0xcf0132c4)
#define REG_CF0132C8 (*(volatile unsigned int *)0xcf0132c8)
#define REG_CF0132CC (*(volatile unsigned int *)0xcf0132cc)
#define REG_CF0132D8 (*(volatile unsigned int *)0xcf0132d8)

/*
 * Write the registers 0xCF0132C4 / C8 (factor * 9, factor * 15), 0xCF0132CC (1) and 0xCF0132D8 (0x30), with
 * factor 1 when "on" is non-zero and 8 otherwise, and start register 0xCF0132C0 with 1.
 *
 * Before the writes it calls dp_pulse_hpd_block when port 0 or port 1 is ready for service. After them, for each
 * port whose record byte 0x11E is 1 it sets the service flag and clears the port's pending bit; then it pulses
 * again and clears the port's bit in dp_service_block_byte for those ports.
 * dp_init_port calls it with 0; input_power_off_receivers_mode0 and input_power_off_receivers_mode1 call it with 1.
 *   on: non-zero selects factor 1, 0 selects factor 8
 */
void dp_setup_service_block(unsigned char on)
{
    unsigned char factor;

    factor = on ? 1 : 8;
    if ((dp_is_port_ready_for_service(0) & 0xff) == 1 || (dp_is_port_ready_for_service(1) & 0xff) == 1)
        dp_pulse_hpd_block();
    REG_CF0132D8 = 0x30;
    REG_CF0132C4 = factor * 9;
    REG_CF0132C8 = factor * 15;
    REG_CF0132CC = 1;
    if (dp_input_records[0].byte_0x11e == 1) {
        dp_set_service_flag(1);
        dp_clear_port_pending_bit(0);
    }
    if (dp_input_records[1].byte_0x11e == 1) {
        dp_set_service_flag(1);
        dp_clear_port_pending_bit(1);
    }
    dp_pulse_hpd_block();
    if (dp_input_records[0].byte_0x11e == 1)
        dp_service_block_byte &= ~1;
    if (dp_input_records[1].byte_0x11e == 1)
        dp_service_block_byte &= ~2;
    REG_CF0132C0 = 1;
}
