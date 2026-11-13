/* hdcp_tx_hdmi_read_hdcp2_version  (FUN_a00c8328)
 *
 * Read the receiver's HDCP 2 version byte.
 * Name basis: proven - DDC device 0x74, offset 0x50, one byte (HDCP2Version in the HDMI specification)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c8328 @ 0xa00c8328, flags -mcpu=v8 -Os -g.
 * Source form: the Ghidra typedefs and parameter types are kept; the two DDC routines are declared without a
 * prototype.
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
extern int hdmi_tx_ddc_start();
extern int hdmi_tx_ddc_read();

#define HDCP_DDC_DEVICE         0x74            /* device address used for all handshake reads */
#define HDCP_DDC_HDCP2_VERSION  0x50            /* offset of the HDCP2Version byte */

/*
 * Read the one-byte HDCP2Version of the screen on HDMI output `port`: start a one-byte DDC read at offset
 * 0x50 of device 0x74 and read the byte into the buffer buf. Returns the result of hdmi_tx_ddc_read.
 *
 * Called from hdcp_tx_hdmi_probe_receiver.
 */
unsigned char hdcp_tx_hdmi_read_hdcp2_version(uint port,undefined4 buf)

{
  port = port & 0xff;
  hdmi_tx_ddc_start(port,HDCP_DDC_DEVICE,HDCP_DDC_HDCP2_VERSION,1);
  return hdmi_tx_ddc_read(port,buf,1);
}
