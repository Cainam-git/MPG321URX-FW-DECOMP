/* dp_mst_pack_port_reply_copy  (FUN_a00d7828)
 *
 * Pack the port-only reply into the byte stream of an MST reply.
 * Note: Identical copy of dp_mst_pack_port_reply.
 * Name basis: derived - request number and port nibble; called from dp_mst_send_reply
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d7828 @ 0xa00d7828 (-mcpu=v8 -Os -g)
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();




/* Pack the port-only reply: out[0] = in[0] & 0x7f, out[1] = in[1] & 0xf. Called from dp_mst_send_reply. */
void dp_mst_pack_port_reply_copy(byte *in,byte *out)

{
  *out = *in & 0x7f;
  out[1] = in[1] & 0xf;
  return;
}
