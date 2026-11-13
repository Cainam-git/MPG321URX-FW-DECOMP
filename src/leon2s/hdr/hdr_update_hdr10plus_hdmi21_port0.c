/* hdr_update_hdr10plus_hdmi21_port0  (FUN_a00638cc)
 *
 * Run the HDR10+ update when receiver 2 (HDMI 2.1 port 0) is the selected source.
 * Name basis: derived - calls hdr_update_hdr10plus_metadata when the selected mode is 2; callers are the
 *   port's receiver routines
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00638cc @ 0xa00638cc (-mcpu=v8 -Os -g)
 */
#define HDR_META_HDMI20_RX0 0                   /* HDR10+ metadata source modes, as in hdr_select_metadata_receiver */
#define HDR_META_HDMI20_RX1 1
#define HDR_META_HDMI21_RX0 2
#define HDR_META_HDMI21_RX1 3

extern unsigned char hdr_meta_source_mode;
extern int hdr_update_hdr10plus_metadata();

/*
 * Run the HDR10+ update when the selected metadata source is HDMI 2.1 receiver 0 (hdr_meta_source_mode
 * is 2). Called by hdmi_rx21_service_irq_port0.
 */
void hdr_update_hdr10plus_hdmi21_port0(void)
{
  if (hdr_meta_source_mode == HDR_META_HDMI21_RX0) {
    hdr_update_hdr10plus_metadata();
    return;
  }
  return;
}
