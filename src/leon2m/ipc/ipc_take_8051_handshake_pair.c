/* ipc_take_8051_handshake_pair  (FUN_a002cf04)
 *
 * On chip code 0xE0, set the shared bytes F211 and F212 to 1, waiting while they read 2.
 *   param_1: returned unchanged
 * Returns: param_1
 * Note: Spins without limit. sys_get_chip_revision returns only 0x80..0x84, so the 0xE0 test never holds; no
 *   routine calls this one.
 * Name basis: descriptive - code: registers 0xCF03C844/848 = 8051 XDATA 0xF211/0xF212
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002cf04 @ 0xa002cf04, flags -mcpu=v8 -O3 -g.
 * Source form: the decompiler's form is kept, because it matches the firmware: two arguments, the return value
 * built with CONCAT44(arg1, arg0) and returned as int (which is arg0), and the revision held in an unsigned local.
 * The two registers are volatile words.
 */
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
#define reg_ipc_8051_shared_f211 (*(volatile unsigned int *)0xcf03c844)
#define reg_ipc_8051_shared_f212 (*(volatile unsigned int *)0xcf03c848)
extern int sys_get_chip_revision();

/* The only chip revision value on which this routine does anything. */
#define CHIP_REVISION_HANDSHAKE 0xe0

/*
 * Set the two shared handshake bytes of the 8051 (XDATA 0xF211, then 0xF212) to 1.
 * Only done when sys_get_chip_revision returns CHIP_REVISION_HANDSHAKE. For each byte: while it does not read 1,
 * write 1 unless it reads 2 (a value of 2 is left alone). ipc_clear_8051_handshake_pair clears both bytes again.
 *   arg0: returned unchanged
 *   arg1: not used
 * Returns arg0. Nothing in the main program calls this routine.
 */
int ipc_take_8051_handshake_pair(unsigned int arg0, unsigned int arg1)
{
  unsigned int revision;

  revision = sys_get_chip_revision();
  if ((revision & 0xff) == CHIP_REVISION_HANDSHAKE) {
    do {
      if (reg_ipc_8051_shared_f211 != 2) {
        reg_ipc_8051_shared_f211 = 1;
      }
    } while (reg_ipc_8051_shared_f211 != 1);
    do {
      if (reg_ipc_8051_shared_f212 != 2) {
        reg_ipc_8051_shared_f212 = 1;
      }
    } while (reg_ipc_8051_shared_f212 != 1);
  }
  return CONCAT44(arg1, arg0);
}
