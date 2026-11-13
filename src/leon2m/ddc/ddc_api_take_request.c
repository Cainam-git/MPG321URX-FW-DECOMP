/* ddc_api_take_request  (FUN_a0148698)
 *
 * Copy the received DDC/CI request out and mark the record free.
 * Name basis: derived - forwards to ddc_take_request
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0148698 @ 0xa0148698 (-mcpu=v8 -O2 -g)
 * Code: ddc_take_request().
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern int ddc_take_request();

/*
 * Take the received DDC/CI request: calls ddc_take_request with no arguments written here. The caller
 * (ddc_handle_request) passes the three pointers (port, length, request bytes) and they reach ddc_take_request
 * unchanged in the same argument registers.
 */
void ddc_api_take_request(void)

{
  ddc_take_request();
  return;
}