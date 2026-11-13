/* hdcp_tx_hdmi_write_an  (FUN_a00c8688)
 *
 * Send the session's random value to the receiver.
 * Name basis: proven - DDC device 0x74, offset 0x18, eight bytes (An)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c8688 @ 0xa00c8688, flags -mcpu=v8 -Os -g.
 * Source form: the Ghidra typedefs, the parameter types and the stray 'return CONCAT44(...)' in the void routine
 * are kept; the DDC routines are declared without a prototype.
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
extern int hdmi_tx_ddc_reset();
extern int hdmi_tx_ddc_write();

#define HDCP_DDC_DEVICE 0x74                    /* device address used for all handshake writes */
#define HDCP_DDC_AN     0x18                    /* offset of the 8-byte An */
#define AN_LENGTH       8

/*
 * Write the 8-byte An (the value read by hdcp_tx_hdmi_generate_an) to the screen on HDMI output `port`: DDC
 * device 0x74, offset 0x18. The DDC channel is reset first (hdmi_tx_ddc_reset).
 *
 * Called from hdcp_tx_hdmi_state_run_checks.
 */
void hdcp_tx_hdmi_write_an(uint port,undefined4 an)

{
  hdmi_tx_ddc_reset(port & 0xff);
  hdmi_tx_ddc_write(port & 0xff,an,HDCP_DDC_DEVICE,HDCP_DDC_AN,AN_LENGTH);
  return CONCAT44(an,port) & 0xffffffff000000ff;
}
