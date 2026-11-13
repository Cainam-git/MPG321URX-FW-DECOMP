/* dp_mrx_init_regs_80_fc  (FUN_CODE_45aa)
 *
 * Write a fixed set-up sequence into one DP receiver's registers 0x80..0xFC.
 *   port: DP receiver 0/1
 * Name basis: descriptive - fixed dp_mrx_write_reg sequence from register 0x80 (= 0x12) up to 0xFC; only
 *   caller DP_EnableMRX
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_45aa @ 0x45aa  (OPTIMIZE(8,SPEED) LARGE).
 * LARGE slots: port 0xA4B4, then the three byte locals option_87_80 = 0 (0xA4B5), option_87_bit6 = 1 (0xA4B6),
 * option_dd_block = 0 (0xA4B7). They are set at the start and tested later; with constant values the firmware still
 * holds both call groups of each test, so they must stay locals (not #if).
 * port is read back from its slot before every call (the option set without REGFILE(R.ORC)); the last call is a
 * tail jump (LJMP). Keil shares the common tails of both arms. No aids.
 */
void dp_mrx_write_reg(unsigned char port, unsigned char reg, unsigned char value);
void dp_mrx_update_reg_bits(unsigned char port, unsigned char reg, unsigned char mask, unsigned char set);

/*
 * dp_mrx_init_regs_80_fc - write the fixed set-up values into the registers of one DisplayPort receiver.
 *   port  DisplayPort receiver 0 or 1
 * Called only by DP_EnableMRX, on chips whose reg_chip_id reads 0x20, once for each receiver (each time followed by
 * dp_mrx_init_regs_c6). The function of the single registers is not shown; the values are the firmware's.
 * Values the 8051 later reads back or changes: reg 0x8D gets 0x84 and regs 0x97 / 0x98 get 0x77, the values
 * dp_aux_track_link_training writes to 0x97 / 0x98 when the low nibble of reg 0x8D is 4.
 *
 * Three local options choose between two value groups each. They are fixed in the code (0, 1, 0), so the
 * firmware runs the second group of the first and third and the first group of the second:
 *   option_87_80     regs 0x85 / 0x87 / 0xAF = 0 / 0x80 / 1, else 0 / 0 / 0           (runs: else)
 *   option_87_bit6   bit 6 of reg 0x87 set, else cleared                             (runs: set)
 *   option_dd_block  17 values for regs 0xDD..0xEA and 0xF7..0xF9, else 0xDD and 0xEA cleared  (runs: else)
 */
void dp_mrx_init_regs_80_fc(unsigned char port)
{
    unsigned char option_87_80, option_87_bit6, option_dd_block;

    option_87_80 = 0;
    option_87_bit6 = 1;
    option_dd_block = 0;
    dp_mrx_write_reg(port, 0x80, 0x12);
    dp_mrx_write_reg(port, 0x81, 0x14);
    dp_mrx_write_reg(port, 0x82, 0x84);
    dp_mrx_write_reg(port, 0x83, 0x81);
    dp_mrx_write_reg(port, 0x84, 0x01);
    dp_mrx_write_reg(port, 0x85, 0x00);
    dp_mrx_write_reg(port, 0x86, 0x01);
    dp_mrx_write_reg(port, 0x8a, 0x06);
    dp_mrx_write_reg(port, 0x8c, 0x0a);
    dp_mrx_write_reg(port, 0x8d, 0x84);
    dp_mrx_write_reg(port, 0x95, 0x41);
    dp_mrx_write_reg(port, 0x96, 0x00);
    dp_mrx_write_reg(port, 0x97, 0x77);
    dp_mrx_write_reg(port, 0x98, 0x77);
    dp_mrx_write_reg(port, 0x99, 0x81);
    dp_mrx_write_reg(port, 0x9a, 0x01);
    dp_mrx_write_reg(port, 0x9b, 0x11);
    dp_mrx_write_reg(port, 0x9c, 0x11);
    dp_mrx_write_reg(port, 0xc2, 0x41);
    if (option_87_80) {
        dp_mrx_write_reg(port, 0x85, 0x00);
        dp_mrx_write_reg(port, 0x87, 0x80);
        dp_mrx_write_reg(port, 0xaf, 0x01);
    } else {
        dp_mrx_write_reg(port, 0x85, 0x00);
        dp_mrx_write_reg(port, 0x87, 0x00);
        dp_mrx_write_reg(port, 0xaf, 0x00);
    }
    dp_mrx_write_reg(port, 0xbc, 0x00);
    dp_mrx_write_reg(port, 0xc3, 0x00);
    dp_mrx_write_reg(port, 0xfc, 0x01);
    if (option_87_bit6) {
        dp_mrx_update_reg_bits(port, 0x87, 0x40, 1);
    } else {
        dp_mrx_update_reg_bits(port, 0x87, 0x40, 0);
    }
    if (option_dd_block) {
        dp_mrx_write_reg(port, 0xdd, 0x0d);
        dp_mrx_write_reg(port, 0xde, 0x21);
        dp_mrx_write_reg(port, 0xdf, 0x00);
        dp_mrx_write_reg(port, 0xe0, 0x76);
        dp_mrx_write_reg(port, 0xe1, 0xab);
        dp_mrx_write_reg(port, 0xe2, 0x01);
        dp_mrx_write_reg(port, 0xe3, 0x01);
        dp_mrx_write_reg(port, 0xf7, 0x40);
        dp_mrx_write_reg(port, 0xf8, 0x82);
        dp_mrx_write_reg(port, 0xe4, 0x1f);
        dp_mrx_write_reg(port, 0xe5, 0x0e);
        dp_mrx_write_reg(port, 0xe6, 0x22);
        dp_mrx_write_reg(port, 0xe7, 0x08);
        dp_mrx_write_reg(port, 0xe8, 0x01);
        dp_mrx_write_reg(port, 0xf9, 0xf5);
        dp_mrx_write_reg(port, 0xe9, 0x4c);
        dp_mrx_write_reg(port, 0xea, 0xff);
    } else {
        dp_mrx_write_reg(port, 0xdd, 0x00);
        dp_mrx_write_reg(port, 0xea, 0x00);
    }
    dp_mrx_write_reg(port, 0xae, 0x07);
    dp_mrx_write_reg(port, 0xeb, 0x00);
    dp_mrx_write_reg(port, 0xa7, 0x01);
}
