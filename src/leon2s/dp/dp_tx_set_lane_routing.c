/* dp_tx_set_lane_routing  (FUN_a0085914)
 *
 * Write the lane selection bits of a DP output path from its lane counts.
 *   port: path
 * Name basis: descriptive - low 3 bits of 0xCF010C00 or 0xCF0116DC from the stored lane counts and the source
 *   code
 *
 * Matching notes
 * --------------
 * FUN_a0085914 (leon2s 0xa0085914-0xa0085b14), flags -mcpu=v8 -Os -g.
 * Source form: the new value `route` is an unsigned char copied from the masked register word; the port != 0 arm
 * uses its own word variable; the bit-3 step tests '(route & 7) == 2' first. dp_tx_limits_others is volatile:
 * the firmware reads byte 1 again for the second compare.
 */
#define R(a) (*(volatile unsigned int *)(a))
extern volatile unsigned char dp_tx_limits_others[];
extern unsigned char dp_tx_lane_route_byte;
extern unsigned char DAT_a807a94d;
extern unsigned char dp_tx_reg_read8(unsigned int, unsigned short);
extern unsigned char input_get_port_source_code(unsigned int);
extern unsigned int dp_get_unit_route_bit(unsigned char, int);
extern unsigned char hdmi_rx21_get_two_port_mode(unsigned int);
extern void dp_tx_reg_update_bits(unsigned int port, short reg, unsigned int mask, unsigned int mode);

/*
 * Set the 3-bit lane selection of a DP output path from its lane counts, then pulse bit 3 of transmitter
 * register 0 (set, then clear).
 *
 *   port  0 or another output (only the low byte is used)
 *
 * Called from dp_tx_init_port_link_regs, TRAINING_NORESPONSE and from the routine at 0xa0087ec8 (with 0).
 *
 * Other outputs: bit 4 of 0xcf010c08 is set; the low 3 bits of 0xcf010c00 become the sum of two parts, 2 or 1
 * when the lane count (byte 1 of the limit pair shared by these outputs, labelled dp_tx_limits_others) is 4 or 2, plus 1 or 2 when dp_tx_lane_route_byte
 * is 2 or 4.
 *
 * Output 0: bit 4 of 0xcf010c00 is set; the low 3 bits of 0xcf0116dc are chosen from the lane count in
 * register 3 (low nibble) and from the source code of the path (input_get_port_source_code): with 4 lanes:
 * source 0x81 / 0x71 give 1 unless dp_get_unit_route_bit (unit 0 / 1) returns 1, then 0; source 0x51 / 0x61
 * give 1 when hdmi_rx21_get_two_port_mode (receiver 0 / 1) returns 1, else 2; any other source gives 2. With 2
 * lanes the value is 1 unless the source is 0x81 or 0x71; with any other lane count it is 0. When bit 3 of register 0x6f is set, a value of 2 becomes 4
 * and every other value is incremented.
 */
void dp_tx_set_lane_routing(unsigned int port)
{
    unsigned int reg_value;
    unsigned char route;
    unsigned char source;

    if ((unsigned char)port) {
        unsigned int reg_word;

        R(0xcf010c08) = (R(0xcf010c08) | 0x10) & 0xff;
        reg_word = R(0xcf010c00) & ~7;
        route = reg_word;
        if (dp_tx_limits_others[1] == 4)
            route = reg_word | 2;
        else if (dp_tx_limits_others[1] == 2)
            route = reg_word | 1;
        if (dp_tx_lane_route_byte == 2)
            route++;
        else if (dp_tx_lane_route_byte == 4)
            route += 2;
        R(0xcf010c00) = route & 0xff;
    } else {
        R(0xcf010c00) = (R(0xcf010c00) | 0x10) & 0xff;
        reg_value = R(0xcf0116dc) & ~7;
        route = reg_value;
        if ((dp_tx_reg_read8(0, 3) & 0xf) == 4) {
            source = input_get_port_source_code(0);
            if (source == 0x81) {
                if ((unsigned char)dp_get_unit_route_bit(0, DAT_a807a94d) != 1)
                    route = reg_value | 1;
            } else if (source == 0x71) {
                if ((unsigned char)dp_get_unit_route_bit(1, DAT_a807a94d) != 1)
                    route = reg_value | 1;
            } else if (source == 0x51) {
                if (hdmi_rx21_get_two_port_mode(0) == 1)
                    route = reg_value | 1;
                else
                    route = reg_value | 2;
            } else if (source == 0x61) {
                if (hdmi_rx21_get_two_port_mode(1) == 1)
                    route = reg_value | 1;
                else
                    route = reg_value | 2;
            } else
                route = reg_value | 2;
        } else if ((dp_tx_reg_read8(0, 3) & 0xf) == 2) {
            source = input_get_port_source_code(0);
            if (source != 0x81) {
                if (source != 0x71)
                    route = reg_value | 1;
            }
        }
        if (dp_tx_reg_read8(0, 0x6f) & 8) {
            if ((route & 7) == 2)
                route = (route & ~7) | 4;
            else
                route++;
        }
        R(0xcf0116dc) = route & 0xff;
    }
    dp_tx_reg_update_bits((unsigned char)port, 0, 8, 1);
    dp_tx_reg_update_bits((unsigned char)port, 0, 8, 0);
}
