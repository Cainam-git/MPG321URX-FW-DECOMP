/* hdr_select_source  (FUN_a00d25f4)
 *
 * Store the source that the HDR service follows and reset its state.
 * Returns: the source
 * Name basis: derived - byte at 0xA8078C37; set by a command from the main processor
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d25f4 @ 0xa00d25f4 (-mcpu=v8 -Os -g)
 * Source form: the decompiler's type names and its CONCAT44 macro are kept; the return value is
 * CONCAT44(second, source), a 64-bit value of which the caller sees the low word.
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
extern unsigned char hdr_source;
extern unsigned char hdr_status_code;
extern int hdr_select_metadata_receiver();

/*
 * Make source (0..5, see hdr_select_metadata_receiver for the receivers) the source that the HDR service
 * follows: store it in hdr_source, set up the metadata receiver for it and clear hdr_status_code. Returns the
 * source. Called by the mailbox command "select HDR source" (IPC_CMD_SELECT_HDR_SOURCE) and by hdr_init.
 * The second parameter is not used.
 */
int hdr_select_source(uint source,undefined4 unused)

{
  hdr_source = (undefined1)source;
  hdr_select_metadata_receiver(source & 0xff);
  hdr_status_code = 0;
  return CONCAT44(unused,source);
}