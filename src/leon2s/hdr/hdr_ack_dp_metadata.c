/* hdr_ack_dp_metadata  (FUN_a00d2e9c)
 *
 * Acknowledge the metadata flag of a DisplayPort source.
 * Name basis: descriptive - register routine with (port, 5, 8) for sources 4 and 5
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d2e9c @ 0xa00d2e9c (-mcpu=v8 -Os -g)
 * Source form: an if chain that tests 0, 1, 2 and 3 first (each returns at once), then 4 and 5.
 */
extern unsigned char hdr_source;
extern int dp_status_reg_write8();

/*
 * For the DisplayPort sources only (hdr_source 4 or 5, port 0 / 1): call FUN_a0fb6fc0 with the port, the status
 * register 5 and the value 8, the bit that hdr_is_source_hdr_active tests. Sources 0 to 3 and other values:
 * nothing. Called by hdr_task after it has read the source's metadata.
 */
void hdr_ack_dp_metadata(void)
{
    unsigned char source = hdr_source;
    
    if (source == 0) return;
    if (source == 1) return;
    if (source == 2) return;
    if (source == 3) return;
    
    if (source == 4) {
        dp_status_reg_write8(0, 5, 8);
        return;
    }
    
    if (source == 5) {
        dp_status_reg_write8(1, 5, 8);
        return;
    }
}
