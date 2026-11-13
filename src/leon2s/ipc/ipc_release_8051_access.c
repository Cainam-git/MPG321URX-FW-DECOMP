/* ipc_release_8051_access  (FUN_a0062b94)
 *
 * Tell the 8051 controller the shared table write is finished.
 * Name basis: derived - writes 0xAA to shared byte F202 (0xCF03C808) after the table write that
 *   ipc_request_8051_access granted
 *
 * Matching notes
 * --------------
 * FUN_a0062b94 (leon2s 0xa0062b94), flags -mcpu=v8 -Os -g.
 * The register is a volatile word macro placed after the names list.
 */
#define IPC_8051_ACCESS_DONE 0xaa           /* value written to shared 8051 byte F202 */
#define reg_ipc_8051_shared_f202 (*(volatile unsigned int *)0xcf03c808)

/*
 * End an access to the shared 8051 table: write 0xAA to shared 8051 byte F202 (0xCF03C808 = 0xCF03C800 + 4 * 2,
 * see docs/MAILBOX.md and WORDS "shared 8051 bytes").
 * It is called after ipc_request_8051_access returned 1 and the table write is finished (HDR tone-mapping
 * update).
 */
void ipc_release_8051_access(void)
{
    reg_ipc_8051_shared_f202 = IPC_8051_ACCESS_DONE;
}
