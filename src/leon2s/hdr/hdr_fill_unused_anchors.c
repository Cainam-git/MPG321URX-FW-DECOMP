/* hdr_fill_unused_anchors  (FUN_a00629fc)
 *
 * Set the Bezier anchors beyond the used count to full scale.
 *   metadata: metadata record
 * Name basis: derived - 0x3FF into anchors from num_bezier_curve_anchors up to 14
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00629fc @ 0xa00629fc (-mcpu=v8 -Os -g)
 * Source form: the counter is an unsigned char that is incremented before the store, and the loop variable is
 * its zero-extended copy (the decompiler's form is kept).
 */
/* The part of the HDR10+ metadata record that holds the Bezier anchors. */
struct anchor_part {
    unsigned char pad_0x00[0x58];
    unsigned char num_bezier_curve_anchors;     /* +0x58 */
    unsigned char byte_0x59;
    unsigned short bezier_curve_anchor[15];     /* +0x5A */
};

#define MAX_ANCHORS      15                     /* size of bezier_curve_anchor */
#define ANCHOR_FULL_SCALE 0x3ff

/*
 * Set the anchors of the metadata record that lie beyond the used count (num_bezier_curve_anchors .. 14) to
 * 0x3ff.
 *   metadata: the HDR10+ metadata record
 */
void hdr_fill_unused_anchors(struct anchor_part *metadata)
{
  unsigned char next;
  unsigned int slot;

  next = metadata->num_bezier_curve_anchors;
  slot = next;
  while (slot < MAX_ANCHORS) {
    next = next + 1;
    metadata->bezier_curve_anchor[slot] = ANCHOR_FULL_SCALE;
    slot = next & 0xff;
  }
  return;
}
