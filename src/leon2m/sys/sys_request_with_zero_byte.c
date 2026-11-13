/* sys_request_with_zero_byte  (FUN_a0152010)
 *
 * Send a request with a zero byte and return the argument unchanged.
 * Returns: p1
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0152010 @ 0xa0152010 (-mcpu=v8 -O2 -g, the section default).
 * Source form: the decompiler's type names and the CONCAT44 return of both parameters are kept; the build depends
 * on them.
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))

extern void sys_store_request_byte(undefined1 *byte_ptr);

/*
 * Call sys_store_request_byte with a pointer to a local byte holding 0, and return the first parameter.
 *
 * Nothing in the firmware calls it.
 */
int sys_request_with_zero_byte(undefined4 value_1,undefined4 value_2)

{
  undefined1 zero_byte [1];
  
  zero_byte[0] = 0;
  sys_store_request_byte(zero_byte);
  return CONCAT44(value_2,value_1);
}
