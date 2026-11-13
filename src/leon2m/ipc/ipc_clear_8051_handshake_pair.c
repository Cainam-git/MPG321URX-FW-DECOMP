/* ipc_clear_8051_handshake_pair  (FUN_a002cf78)
 *
 * On chip code 0xE0, clear the shared bytes F212 and F211.
 *   param_1: returned unchanged
 * Returns: param_1
 * Note: Counterpart of ipc_take_8051_handshake_pair. sys_get_chip_revision returns only 0x80..0x84, so the
 *   0xE0 test never holds; no routine calls this one.
 * Name basis: descriptive - code: registers 0xCF03C844/848
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002cf78 @ 0xa002cf78, flags -mcpu=v8 -O2 -g.
 * Source form: the decompiler's form is kept, because it matches the firmware: two arguments, the return value
 * built with CONCAT44(arg1, arg0) and returned as int (which is arg0). The two registers are volatile words.
 */
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
#define reg_ipc_8051_shared_f211 (*(volatile unsigned int *)0xcf03c844)
#define reg_ipc_8051_shared_f212 (*(volatile unsigned int *)0xcf03c848)
extern int sys_get_chip_revision();

/* The only chip revision value on which this routine does anything. */
#define CHIP_REVISION_HANDSHAKE 0xe0

/*
 * Clear the two shared handshake bytes of the 8051 (XDATA 0xF212, then 0xF211), the bytes that
 * ipc_take_8051_handshake_pair sets. Only done when sys_get_chip_revision returns CHIP_REVISION_HANDSHAKE.
 *   arg0: returned unchanged
 *   arg1: not used
 * Returns arg0. Nothing in the main program calls this routine.
 */
int ipc_clear_8051_handshake_pair(unsigned int arg0, unsigned int arg1)
{
  unsigned int revision;

  revision = sys_get_chip_revision();
  if ((revision & 0xff) == CHIP_REVISION_HANDSHAKE) {
    reg_ipc_8051_shared_f212 = 0;
    reg_ipc_8051_shared_f211 = 0;
  }
  return CONCAT44(arg1, arg0);
}
