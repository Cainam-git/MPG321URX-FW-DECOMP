/* hdmi_rx21_score_lane  (FUN_a0079b84)
 *
 * Compute a quality score for one HDMI 2.1 lane from its eye status fields.
 *   port: PHY
 *   ch: lane
 *   rate: link rate
 *   eq_step: EQ value
 * Returns: score
 * Name basis: descriptive - the smaller top field and the distances of the middle and low field pairs from
 *   their centre values combined into one score; caller DRV_HDMI21_Set_PHY
 *
 * Matching notes
 * --------------
 * FUN_a0079b84 (leon2s 0xa0079b84-0xa0079e00, 636 bytes), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - every field is its own register read (three reads of each register);
 *  - the result is computed in a short variable;
 *  - each "larger distance" is preset to the second distance and replaced by the first when that is larger;
 *    the smaller top field is an if/else on top_31c > top_33c;
 *  - the two formula tests are written out twice ((a > 5) & (b < 4)) && use_first_formula / && !...
 */
extern const unsigned short hdmi_rx21_lane_regs_0x31c[];
extern const unsigned short hdmi_rx21_lane_regs_0x33c[];
extern unsigned int hdmi_phy_read_reg(unsigned int, unsigned short);

/* Fields of the lane registers 0x31C and 0x33C. */
#define TOP_FIELD_MASK   0x1f000000     /* bits 24..28 */
#define MID_FIELD_MASK   0xf0000        /* bits 16..19, a signed 4-bit value */
#define LOW_FIELD_MASK   0x1f00         /* bits 8..12, a signed 5-bit value */
#define MID_SIGN_FLIP    8              /* flipping the sign bit turns the value v into v + 8 ... */
#define LOW_SIGN_FLIP    0x10           /* ... and v + 0x10: the distance from 8 / 0x10 is then |v| */

#define FRL_RATE_5       5              /* rate code passed by DRV_HDMI21_Set_PHY */
#define EQ_STEP_8        8              /* largest step hdmi_rx21_pick_eq_step returns */

#define TOP_MIN_GOOD     5              /* the formulas apply when the smaller top field is above this ... */
#define MID_DIST_GOOD    4              /* ... and the larger middle distance is below this */

/*
 * Score one lane of an HDMI 2.1 receiver PHY from three fields of its lane registers 0x31C and 0x33C.
 * A higher score is better: DRV_HDMI21_Set_PHY, the only caller, keeps the RCT / CFT row with the highest score
 * among the rows without errors during its search at FRL rates 5 and 6.
 *
 *   port     the PHY (PHY 2 or 3)
 *   ch       the lane (0..3; above 3 all fields count as 0)
 *   rate     the FRL rate code
 *   eq_step  the lane's EQ step from hdmi_rx21_pick_eq_step (0, 2, 4 or 8)
 *
 * Inputs: top_min = the smaller of the two top fields; mid_dist and low_dist = the larger size of the two
 * middle and the two low fields, each read as a signed number.
 * With top_min above 5 and mid_dist below 4:
 *   rate 5 or eq_step 8:  top_min * 7 + (8 - mid_dist) * 8 - low_dist + 0x10
 *   otherwise:            ((8 - mid_dist) * 2 - low_dist) * 2 + top_min + 0x20
 * Else: top_min - mid_dist + 8.
 */
unsigned short hdmi_rx21_score_lane(unsigned int port, unsigned int ch, unsigned char rate, unsigned char eq_step)
{
    unsigned char use_first_formula;
    unsigned char top_31c = 0, top_33c = 0, mid_31c = 0, mid_33c = 0, low_31c = 0, low_33c = 0;
    unsigned char mid_dist_31c, mid_dist_33c, low_dist_31c, low_dist_33c, mid_dist, low_dist, top_min;
    unsigned int reg_31c, reg_33c;
    short score;

    use_first_formula = (rate == FRL_RATE_5) | (eq_step == EQ_STEP_8);
    if ((ch & 0xff) <= 3) {
        reg_31c = hdmi_rx21_lane_regs_0x31c[ch & 0xff];
        top_31c = (hdmi_phy_read_reg(port & 0xff, reg_31c) & TOP_FIELD_MASK) >> 24;
        reg_33c = hdmi_rx21_lane_regs_0x33c[ch & 0xff];
        top_33c = (hdmi_phy_read_reg(port & 0xff, reg_33c) & TOP_FIELD_MASK) >> 24;
        mid_31c = (hdmi_phy_read_reg(port & 0xff, reg_31c) & MID_FIELD_MASK) >> 16;
        mid_33c = (hdmi_phy_read_reg(port & 0xff, reg_33c) & MID_FIELD_MASK) >> 16;
        low_31c = (hdmi_phy_read_reg(port & 0xff, reg_31c) & LOW_FIELD_MASK) >> 8;
        low_33c = (hdmi_phy_read_reg(port & 0xff, reg_33c) & LOW_FIELD_MASK) >> 8;
    }
    mid_31c ^= MID_SIGN_FLIP;
    mid_33c ^= MID_SIGN_FLIP;
    low_31c ^= LOW_SIGN_FLIP;
    low_33c ^= LOW_SIGN_FLIP;
    if (mid_31c <= 7)
        mid_dist_31c = 8 - mid_31c;
    else
        mid_dist_31c = mid_31c - 8;
    if (mid_33c <= 7)
        mid_dist_33c = 8 - mid_33c;
    else
        mid_dist_33c = mid_33c - 8;
    mid_dist = mid_dist_33c;
    if (mid_dist_33c < mid_dist_31c)
        mid_dist = mid_dist_31c;
    if (low_31c <= 0xf)
        low_dist_31c = 0x10 - low_31c;
    else
        low_dist_31c = low_31c - 0x10;
    if (low_33c <= 0xf)
        low_dist_33c = 0x10 - low_33c;
    else
        low_dist_33c = low_33c - 0x10;
    low_dist = low_dist_33c;
    if (low_dist_33c < low_dist_31c)
        low_dist = low_dist_31c;
    if (top_31c > top_33c)
        top_min = top_33c;
    else
        top_min = top_31c;
    if (((top_min > TOP_MIN_GOOD) & (mid_dist < MID_DIST_GOOD)) && use_first_formula)
        score = top_min * 7 + (8 - mid_dist) * 8 - low_dist + 0x10;
    else if (((top_min > TOP_MIN_GOOD) & (mid_dist < MID_DIST_GOOD)) && !use_first_formula)
        score = ((8 - mid_dist) * 2 - low_dist) * 2 + top_min + 0x20;
    else
        score = top_min - mid_dist + 8;
    return score;
}
