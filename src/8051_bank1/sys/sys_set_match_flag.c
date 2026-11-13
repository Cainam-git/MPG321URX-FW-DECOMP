/* sys_set_match_flag  (FUN_CODE_dd63)
 *
 * Store whether the last device check matched.
 *   matched: 1 match
 * Name basis: descriptive - flag 0xA70C; only caller i2c_sw_match_device_id (I2C read compared with a 6-byte
 *   field)
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_dd63 @ 0xdd63  OPTIMIZE(8,SPEED) LARGE
 * Source form: the if/else produces the target's compare and the two separate store paths.
 */
extern xdata unsigned char i2c_sw_id_match_flag;

/* Store 1 in i2c_sw_id_match_flag when matched is 1, else 0.
 *   matched: result of the device ID check
 * Only caller: i2c_sw_match_device_id. */
void sys_set_match_flag(char matched)
{
    if (matched == 0x01) {
        i2c_sw_id_match_flag = 0x01;
    } else {
        i2c_sw_id_match_flag = 0x00;
    }
}
