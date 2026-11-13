/* sys_dsc_dec_write_default_config  (FUN_a00a5cb4)
 *
 * Write the default set-up record to the DSC decoder.
 *   p1: decoder
 * Name basis: derived - sys_dsc_dec_fill_default_config then sys_dsc_dec_write_config(.., 1)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a5cb4 @ 0xa00a5cb4 (-mcpu=v8 -Os -g)
 * Source form: Ghidra's type and symbol names are kept; the routine is declared void but ends with a
 * 'return CONCAT44(..) & ..' statement that returns nothing at run time.
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
extern void sys_dsc_dec_fill_default_config();
extern int sys_dsc_dec_write_config();

/* Fill an 80-byte set-up record with the default values (sys_dsc_dec_fill_default_config) and write it to the
 * decoder with sys_dsc_dec_write_config(.., 1).
 *   decoder: decoder number, low byte only
 */
void sys_dsc_dec_write_default_config(uint decoder,undefined4 unused)

{
  undefined1 config [80];
  
  sys_dsc_dec_fill_default_config(decoder & 0xff,config);
  sys_dsc_dec_write_config(decoder & 0xff,config,1);
  return CONCAT44(unused,decoder) & 0xffffffff000000ff;
}
