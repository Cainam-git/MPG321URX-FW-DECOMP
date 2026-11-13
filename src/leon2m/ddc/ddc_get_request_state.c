/* ddc_get_request_state  (FUN_a0133ad8)
 *
 * Return the state byte of the received DDC/CI request.
 * Returns: state
 * Name basis: derived - byte at 0xA802DA4A; read by the DDC/CI request handler
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0133ad8 @ 0xa0133ad8 (-mcpu=v8 -O2)
 * Source form: Ghidra's return type name (undefined1) and the typedef block are kept.
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

/* The last byte (+0x84) of the received DDC/CI request record. ipc_8051_decode_message sets it to 1 when the
   request is complete; ddc_take_request clears it. */
extern unsigned char ddc_rx_request_state;

/*
 * Return the state byte of the DDC/CI request received from the 8051: 1 while a complete request waits to be
 * taken, 0 otherwise. Reached through ddc_api_get_request_state.
 */
undefined1 ddc_get_request_state(void)

{
  return ddc_rx_request_state;
}
