/* ipc_poll_command  (FUN_a0072900)
 *
 * Read a command message from the main processor and carry it out when valid.
 * Name basis: proven - reads mailbox slot 8, ipc_verify_message, then ipc_dispatch_command
 *
 * Matching notes
 * --------------
 * FUN_a0072900 (leon2s 0xa0072900), flags -mcpu=v8 -Os -g.
 * Ghidra's type and symbol names are kept: the two parameters are passed through as a 64-bit return value
 * (CONCAT44), and the result of ipc_verify_message is held in a pointer variable of which only the low byte is
 * tested.
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4, uint;
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
#define true 1
#define false 0
extern void ipc_read_mailbox_slot();
extern int ipc_verify_message();
extern int ipc_dispatch_command();
extern int lib_memset();

#define IPC_SLOT_COMMAND  8             /* mailbox slot the command comes in */
#define IPC_COMMAND_WORDS 8             /* a command message is 8 words (32 bytes) */

/*
 * Read the command slot (slot 8) of the input-processor mailbox into a local buffer and, when
 * ipc_verify_message accepts the message, run it with ipc_dispatch_command.
 *
 * Neither parameter is used; the routine returns the first one.
 */
int ipc_poll_command(undefined4 param_1,undefined4 param_2)

{
  undefined1 *valid;
  undefined1 message [4 * IPC_COMMAND_WORDS];
  
  lib_memset(message,0,0x20);
  ipc_read_mailbox_slot(IPC_SLOT_COMMAND,0,message,IPC_COMMAND_WORDS);
  valid = ipc_verify_message(message,IPC_COMMAND_WORDS);
  if (((uint)valid & 0xff) != 0) {
    ipc_dispatch_command(message);
  }
  return CONCAT44(param_2,param_1);
}
