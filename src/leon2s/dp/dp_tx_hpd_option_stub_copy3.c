/* dp_tx_hpd_option_stub_copy3  (FUN_a00b12c4)
 *
 * Return 0 (an HPD option that is switched off in this build).
 * Returns: 0
 * Note: Identical copy of dp_tx_hpd_option_stub.
 * Name basis: descriptive - constant 0; tested by dp_set_bank_registers
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b12c4 @ 0xa00b12c4 (-mcpu=v8 -Os -g)
 * Source form: Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();



/* Constant 0: the option is off in this build. dp_set_bank_registers tests it. */
undefined4 dp_tx_hpd_option_stub_copy3(void)

{
  return 0;
}
