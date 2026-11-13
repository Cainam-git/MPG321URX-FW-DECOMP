/* irq_raise_software_irq_bit0  (FUN_a00b192c)
 *
 * Write 1 to software interrupt register 0x9F020024 (bit 0).
 * Name basis: descriptive - write of 1 to core register 0x9F020024
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b192c @ 0xa00b192c (-mcpu=v8 -Os -g)
 * Source form: the register write goes through reg_write32_copy, declared without a prototype; the decompiler's
 * type names are kept.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern int reg_write32_copy();

#define SOFTWARE_IRQ_REG 0x9f020024     /* written by the callers below; each call writes one bit value */
#define SOFTWARE_IRQ_BIT0 1

/*
 * Write 1 (bit 0) to SOFTWARE_IRQ_REG. Called by ipc_request_8051_access when it is asked to use the
 * interrupt (mode IPC_8051_IRQ_REQUEST) instead of the shared byte.
 */
void irq_raise_software_irq_bit0(void)

{
  reg_write32_copy(SOFTWARE_IRQ_REG,SOFTWARE_IRQ_BIT0);
  return;
}
