/* hdcp_rx_dp_poll_v_calculation  (FUN_a00c5ae4)
 *
 * On status bit 3 of a DisplayPort input, run hdcp_rx_dp_calculate_v when register 0x2A8 bit 1 is set.
 * Note: Sets bit 23 of the port's 16-byte copy-protection input record afterwards.
 * Name basis: derived - status register 0x30 bit 3, register 0x2A8 bit 1, then hdcp_rx_dp_calculate_v
 *   ('Calculate V'); called by input_update_port_records for ports above 3
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c5ae4 @ 0xa00c5ae4, flags -mcpu=v8 -Os -g.
 * Source form: Ghidra's declarations are kept; the parameter is an int of which only the low byte is used
 * where it indexes the record table, and the register routines are declared without parameter lists.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
#define true 1
#define false 0
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
extern int hdcp_rx_dp_calculate_v();
extern int dp_reg_read8();
extern void dp_reg_update_bits();
extern int dp_status_reg_read8();
extern int dp_status_reg_write8();
extern int timer_delay_long_units();
extern unsigned int hdcp_rx_record_hdmi20[][4];

/*
 * Per-pass service of one DisplayPort input, called by input_update_port_records for a port above 3 whose
 * record has bit 22 set. Parameter port: the port number; the DP unit is port - 4 (low byte).
 * It acts only when bit 3 of status register 0x30 of the unit is set. Then:
 *   1. write 8 to register 0x30 through the status-register write routine, set bit 7 of 0x30;
 *   2. if bit 1 of register 0x2A8 is set: clear bit 1 of 0x2A9, set bit 2 of 0x226, clear bit 7 of 0x30, run
 *      hdcp_rx_dp_calculate_v(unit), set bit 3 of 0x30, set bit 7 of 0x30, set bit 0 of 0x2A9, clear bit 7
 *      of 0x30, wait 200 delay units;
 *   3. clear bit 7 and set bit 6 of register 0x30;
 *   4. set bit 23 of word 0 of the port's 16-byte copy-protection input record (hdcp_rx_record_hdmi20).
 * The meaning of these registers is not shown in the firmware.
 */
void hdcp_rx_dp_poll_v_calculation(int port)

{
  unsigned short value;
  int unused;
  uint dp_unit;
  
  dp_unit = port - 4 & 0xff;
  value = dp_status_reg_read8(dp_unit,0x30);
  if ((value & 8) != 0) {
    dp_status_reg_write8(dp_unit,0x30,8);
    dp_reg_update_bits(dp_unit,0x30,0x80,1);
    value = dp_reg_read8(dp_unit,0x2a8);
    if ((value & 2) != 0) {
      dp_reg_update_bits(dp_unit,0x2a9,2,0);
      dp_reg_update_bits(dp_unit,0x226,4,1);
      dp_reg_update_bits(dp_unit,0x30,0x80,0);
      hdcp_rx_dp_calculate_v(dp_unit);
      dp_reg_update_bits(dp_unit,0x30,8,1);
      dp_reg_update_bits(dp_unit,0x30,0x80,1);
      dp_reg_update_bits(dp_unit,0x2a9,1,1);
      dp_reg_update_bits(dp_unit,0x30,0x80,0);
      timer_delay_long_units(200);
    }
    dp_reg_update_bits(dp_unit,0x30,0x80,0);
    dp_reg_update_bits(dp_unit,0x30,0x40,1);
    hdcp_rx_record_hdmi20[(unsigned char)port][0] |= 0x800000;
  }
}