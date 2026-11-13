/* Disable_DPMRX  (FUN_CODE_de2e)
 *
 * Log and switch off the DisplayPort receivers' standby request handling.
 * Name basis: proven - (original name printed: 'Disable_DPMRX'); mailbox command 0x2B, then
 *   dp_mrx_disable_aux_irqs
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_de2e @ 0xde2e  OPTIMIZE(8,SPEED)
 * The text pointer is held in a local `void *` so that it is passed as a three-byte generic pointer.
 */
extern void lib_printf517(void *text);
extern void dp_mrx_disable_aux_irqs(void);

/* Print "Disable_DPMRX" (text at code 0x6AE7), then call
 * dp_mrx_disable_aux_irqs. Twin of Enable_DPMRX. */
void Disable_DPMRX(void)
{
    void *text = (void code *)0x6ae7;
    lib_printf517(text);
    dp_mrx_disable_aux_irqs();
}
