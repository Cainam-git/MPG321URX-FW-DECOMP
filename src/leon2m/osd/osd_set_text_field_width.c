/* osd_set_text_field_width  (FUN_a00a3198)
 *
 * Store the text field width used by the text drawer.
 *   width: width in cells
 * Note: Byte 0xA802AFF4, also set by osd_draw_text from its fourth argument.
 * Name basis: descriptive - osd_draw_text stores its width argument in the same byte; no direct caller
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00a3198, flags -mcpu=v8 -O2 -g.
 * Source form: a direct store to the extern symbol (the store sits in the return delay slot). Nothing in the
 * image refers to this routine.
 */
extern unsigned char osd_text_field_width;

/*
 * Store the field width, in cells, that the text drawer uses. osd_draw_text stores its own width argument in
 * the same byte. No call, branch or address word in the image refers to this routine.
 */
void osd_set_text_field_width(unsigned char width)
{
    osd_text_field_width = width;
}
