/* hdr_update_hdr10plus_tmds_port0  (FUN_a0063924)
 *
 * Run the HDR10+ update when receiver 0 (HDMI 2.0 port 0) is the selected source.
 * Name basis: derived - calls hdr_update_hdr10plus_metadata when the selected mode is 0; callers are the
 *   port's receiver routines
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0063924 @ 0xa0063924 (-mcpu=v8 -Os -g)
 */
#define HDR_META_HDMI20_RX0 0                   /* HDR10+ metadata source modes, as in hdr_select_metadata_receiver */
#define HDR_META_HDMI20_RX1 1
#define HDR_META_HDMI21_RX0 2
#define HDR_META_HDMI21_RX1 3

extern unsigned char hdr_meta_source_mode;
extern int hdr_update_hdr10plus_metadata();

/*
 * Run the HDR10+ update when the selected metadata source is HDMI 2.0 receiver 0 (hdr_meta_source_mode
 * is 0). Called by hdr_update_and_ack_tmds_port0.
 */
void hdr_update_hdr10plus_tmds_port0(void)
{
  if (hdr_meta_source_mode == HDR_META_HDMI20_RX0) {
    hdr_update_hdr10plus_metadata();
    return;
  }
  return;
}
