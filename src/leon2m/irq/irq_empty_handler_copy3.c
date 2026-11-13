/* irq_empty_handler_copy3  (FUN_a002c4b0)
 *
 * Return at once: an empty routine, identical in code to irq_empty_handler.
 * Note: Identical copy of irq_empty_handler; its address is in no table and no routine in the source refers to
 *   it.
 * Name basis: descriptive - empty body; the name marks it as a copy of irq_empty_handler, not as an interrupt
 *   handler
 *
 * Matching notes
 * --------------
 * FUN_a002c4b0 (leon2m 0xa002c4b0-0xa002c4b8, 8 bytes, leaf), flags -mcpu=v8 -O2 -g (the section default).
 * Source form: an empty void function (retl; nop).
 */

/*
 * Return at once; the same code as irq_empty_handler, whose address stands right after the interrupt level table.
 * Nothing in the image refers to this copy (no call, branch, sethi/or constant or address word).
 */
void irq_empty_handler_copy3(void)
{
}
