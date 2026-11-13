/* ipc_get_status_field  (FUN_a0138e5c)
 *
 * Read the 2-bit status field from mailbox portal 1.
 * Returns: 0..3
 * Name basis: descriptive - bits 1-2 of the word at offset 0 of portal 1
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0138e5c @ 0xa0138e5c, flags -mcpu=v8 -O3 -g.
 * Source form: the word starts at 0 and is read with ipc_mailbox_read; the routine reads no parameters.
 */
#define IPC_PORTAL_INPUT_CPU 1          /* mailbox portal of the input processor */
extern int ipc_mailbox_read();

/*
 * Read bits 1 and 2 of word 0 of the input processor's mailbox portal and return them as 0..3.
 *
 * Called from ipc_api_get_status_field, panel_api_get_brightness_level and panel_api_set_brightness.
 */
int ipc_get_status_field(void)
{
    unsigned int word;
    
    word = 0;
    ipc_mailbox_read(IPC_PORTAL_INPUT_CPU, 0, &word, 1);
    return (word >> 1) & 3;
}
