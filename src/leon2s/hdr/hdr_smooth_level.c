/* hdr_smooth_level  (FUN_a00d3704)
 *
 * Move the stored level a step towards a target, or set it at once.
 * Name basis: derived - blend with weight 0x28 on the value at 0xA80785E0
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d3704 @ 0xa00d3704-0xa00d378c (34 words), flags -mcpu=v8 -Os -g.
 * Source form: the two compares of hdr_blend_level with the level (bgu / bcc) are written as an if and an else if
 * with the same body; the tail call of hdr_tmo_set_table_index takes one argument (the firmware sets only %i0 before
 * the call and the restore).
 */
typedef unsigned int uint;

extern unsigned int hdr_blend_level;
extern unsigned short hdr_gain;
extern uint hdr_blend_values(int param_1, int param_2, int param_3);
extern void hdr_tmo_set_table_index(unsigned short param_1);

#define BLEND_WEIGHT  0x28              /* weight of the new level per call, in 256ths */
#define LEVEL_MAX     0x514             /* upper limit of the level written to the block */

/*
 * Write a level to hdr_tmo_set_table_index, either at once or approached in steps.
 *
 *   level  target level
 *   mode   1: move hdr_blend_level (the level times 256) towards level by one blend with weight 0x28 and use
 *          its rounded value instead of level; any other value: set hdr_blend_level to level times 256 and use
 *          level as it is.
 *
 * The level is limited to 0x514 above and to hdr_gain (the "u16HDRGain" value printed by the HDR code)
 * below, then handed to hdr_tmo_set_table_index. Called by hdr_update_smoothed_level.
 */
void hdr_smooth_level(uint level, int mode)
{
    uint limited;
    uint blended;
    
    if (mode == 1) {
        blended = hdr_blend_level;
        if (blended > level) {
            hdr_blend_level = hdr_blend_values(level << 8, blended, BLEND_WEIGHT);
        } else if (blended < level) {
            hdr_blend_level = hdr_blend_values(level << 8, blended, BLEND_WEIGHT);
        }
        level = (hdr_blend_level + 0x80) >> 8;
    } else {
        hdr_blend_level = level << 8;
    }
    
    limited = LEVEL_MAX;
    if (level < LEVEL_MAX + 1) {
        limited = hdr_gain;
        if (level >= hdr_gain) {
            limited = level;
        }
    }
    
    hdr_tmo_set_table_index((unsigned short)limited);
}
