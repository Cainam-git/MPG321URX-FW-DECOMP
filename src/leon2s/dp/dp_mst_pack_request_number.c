/* dp_mst_pack_request_number  (FUN_a00d7638)
 *
 * Pack the request number into the byte stream of an MST reply.
 * Name basis: derived - one byte, low 7 bits; called from dp_mst_send_reply
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d7638 @ 0xa00d7638 (-mcpu=v8 -Os -g)
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();




/* Pack the request number: *out = *in & 0x7f. Called from dp_mst_send_reply. */
void dp_mst_pack_request_number(byte *in,byte *out)

{
  *out = *in & 0x7f;
  return;
}
