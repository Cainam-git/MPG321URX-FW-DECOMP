/* dp_mrx_init_regs_c6  (FUN_CODE_942e)
 *
 * Write a fixed set-up sequence into one DP receiver's registers 0xC6..0xDC.
 *   port: DP receiver 0/1
 * Name basis: descriptive - fixed dp_mrx_write_reg sequence; only caller DP_EnableMRX
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_942e @ 0x942e..0x9522 (244 bytes), OPTIMIZE(8,SPEED) LARGE.
 * Source form: the four group switches are byte locals set to constants (LARGE slots 0xA4B5..0xA4B8) and tested
 *   at run time, as in dp_mrx_init_regs_80_fc; port (0xA4B4) is read back before every call.
 */
void dp_mrx_write_reg(unsigned char ch, unsigned char reg, unsigned char v);
void dp_mrx_update_reg_bits(unsigned char bank, unsigned char idx, unsigned char mask, unsigned char set);
unsigned char dp_mrx_read_reg(unsigned char sel, unsigned char idx);

/*
 * dp_mrx_init_regs_c6 - write a fixed set-up into registers 0xC6..0xDC of one DP receiver.
 *   port  DP receiver 0 or 1
 * Register 0xC9 gets 0x81 when register 0xC7 reads back the 0x1E just written, else 0x03. Four groups of writes
 * are switched by local flags that are fixed in the code: the 0xCB / 0xCD group is off, the other three are on.
 * What the single registers control is not shown in this program.
 * Only caller: DP_EnableMRX (two calls).
 */
void dp_mrx_init_regs_c6(unsigned char port)
{
    unsigned char group_cb_cd, group_cd_bit6, group_d6_d9, group_da;

    group_cb_cd = 0;
    group_cd_bit6 = 1;
    group_d6_d9 = 1;
    group_da = 1;
    dp_mrx_write_reg(port, 0xc6, 0x14);
    dp_mrx_write_reg(port, 0xc7, 0x1e);
    dp_mrx_write_reg(port, 0xc8, 0x84);
    if (dp_mrx_read_reg(port, 0xc7) == 0x1e) {
        dp_mrx_write_reg(port, 0xc9, 0x81);
    } else {
        dp_mrx_write_reg(port, 0xc9, 0x03);
    }
    dp_mrx_update_reg_bits(port, 0xd0, 0x04, 1);
    dp_mrx_write_reg(port, 0xd3, 0x00);
    if (group_cb_cd) {
        dp_mrx_write_reg(port, 0xcb, 0x01);
        dp_mrx_write_reg(port, 0xcd, 0x80);
    }
    if (group_cd_bit6) {
        dp_mrx_update_reg_bits(port, 0xcd, 0x40, 1);
    }
    if (group_d6_d9) {
        dp_mrx_write_reg(port, 0xd6, 0xf0);
        dp_mrx_write_reg(port, 0xd8, 0x10);
        dp_mrx_write_reg(port, 0xd9, 0x10);
    }
    if (group_da) {
        dp_mrx_write_reg(port, 0xda, 0x01);
    }
    dp_mrx_write_reg(port, 0xdb, 0x00);
    dp_mrx_write_reg(port, 0xdc, 0x31);
}
