/* hdr_update_hdr10plus_tmds_port1  (FUN_a00638f8)
 *
 * Run the HDR10+ update when receiver 1 (HDMI 2.0 port 1) is the selected source.
 * Name basis: derived - calls hdr_update_hdr10plus_metadata when the selected mode is 1; callers are the
 *   port's receiver routines
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00638f8 @ 0xa00638f8 (-mcpu=v8 -Os -g)
 */
#define HDR_META_HDMI20_RX0 0                   /* HDR10+ metadata source modes, as in hdr_select_metadata_receiver */
#define HDR_META_HDMI20_RX1 1
#define HDR_META_HDMI21_RX0 2
#define HDR_META_HDMI21_RX1 3

extern unsigned char hdr_meta_source_mode;
extern int hdr_update_hdr10plus_metadata();

/*
 * Run the HDR10+ update when the selected metadata source is HDMI 2.0 receiver 1 (hdr_meta_source_mode
 * is 1). Called by hdr_update_and_ack_tmds_port1.
 */
void hdr_update_hdr10plus_tmds_port1(void)
{
  if (hdr_meta_source_mode == HDR_META_HDMI20_RX1) {
    hdr_update_hdr10plus_metadata();
    return;
  }
  return;
}
