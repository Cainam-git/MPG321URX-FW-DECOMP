/* ddc_api_get_request_state  (FUN_a0148680)
 *
 * Return the state byte of the received DDC/CI request.
 * Returns: state
 * Name basis: derived - forwards to ddc_get_request_state
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0148680 @ 0xa0148680 (-mcpu=v8 -O2 -g)
 * Returns the byte result of ddc_get_request_state(), zero-extended.
 * Source form: Ghidra's type and symbol names are kept.
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
extern undefined1 ddc_get_request_state(void);

/*
 * Return the state byte of the received DDC/CI request (ddc_get_request_state), zero-extended: 1 while a
 * complete request waits to be taken. Caller: ddc_handle_request, which then takes the request with ddc_api_take_request.
 * The two parameters are not used; the odd shape (the second one is put into the upper half of a 64-bit
 * result) is what the build needs.
 */
int ddc_api_get_request_state(undefined4 param_1, undefined4 param_2)

{
  byte state;

  state = ddc_get_request_state();
  return CONCAT44(param_2,(uint)state);
}