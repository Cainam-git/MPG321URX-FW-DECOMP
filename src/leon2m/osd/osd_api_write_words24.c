/* osd_api_write_words24  (FUN_a0146c00)
 *
 * Send 24-bit entries to a menu layer's memory.
 * Name basis: derived - forwards to osd_ram_write_words24
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0146c00 @ 0xa0146c00, flags -mcpu=v8 -O2 -g.
 * Source form: the callee is declared without a prototype and returns int; the data pointer is a word, the layer a
 * byte.
 */
extern int osd_ram_write_words24();

/* Pass the address of the data and the menu layer (0 or 1) on to osd_ram_write_words24. Called by osd_draw_text. */
void osd_api_write_words24(unsigned int data,unsigned char layer)

{
  osd_ram_write_words24(data,layer);
  return;
}
