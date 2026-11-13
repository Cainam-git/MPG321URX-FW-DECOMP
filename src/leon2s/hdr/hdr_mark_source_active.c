/* hdr_mark_source_active  (FUN_a00d36a4)
 *
 * Mark the current source as HDR-active, or clear the mark.
 * Name basis: descriptive - bit (source) of the byte at 0xA8078C35 when the state byte is above 1
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d36a4 @ 0xa00d36a4 (-mcpu=v8 -Os -g)
 * Source form: the decompiler's byte-width store; the bit is built as (unsigned char)(1 << hdr_source).
 */
extern unsigned char hdr_source_active_flag;
extern unsigned char hdr_source;
extern unsigned char hdr_status_code;

/*
 * When hdr_status_code is above 1, set the bit of the current source (hdr_source) in hdr_source_active_flag;
 * otherwise clear the whole byte. hdr_task calls it first at every step.
 */
void hdr_mark_source_active(void)
{
    if (hdr_status_code > 1) {
        hdr_source_active_flag = (unsigned char)(1 << hdr_source) | hdr_source_active_flag;
    } else {
        hdr_source_active_flag = 0;
    }
}
