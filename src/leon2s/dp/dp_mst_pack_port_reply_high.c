/* dp_mst_pack_port_reply_high  (FUN_a00d7844)
 *
 * Pack the port-only reply with the port in the upper nibble into the byte stream of an MST reply.
 * Name basis: derived - request number and port << 4; called from dp_mst_send_reply
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d7844 (7 words, leaf; twin pair FUN_a00d7844/FUN_a00d7860). Flags -mcpu=v8 -Os -g.
 * Source form: the second value goes through an unsigned short temp (firmware 'and %g1,0xf0' in SImode; the
 * direct byte form gives the QImode mask 'and -16'), as in dp_mst_pack_enum_path_reply.
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




/* Pack the port-only reply with the port in the upper nibble: out[0] = in[0] & 0x7f,
 * out[1] = in[1] & 0xf0. Called from dp_mst_send_reply. */
void dp_mst_pack_port_reply_high(byte *in,byte *out)

{
  unsigned short high_nibble;

  *out = *in & 0x7f;
  high_nibble = in[1] & 0xf0;
  out[1] = high_nibble;
  return;
}
