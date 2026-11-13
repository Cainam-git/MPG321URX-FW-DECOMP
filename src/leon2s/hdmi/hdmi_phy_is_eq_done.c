/* hdmi_phy_is_eq_done  (FUN_a0074c48)
 *
 * Return whether the equaliser of a PHY has finished (link table flag).
 *   phy
 * Returns: 1 when done
 * Name basis: derived - byte 1 of the PHY table entry, cleared by the EQ clock check on 'Restart EQ'; caller
 *   TMDS link state machine
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0074c48 @ 0xa0074c48, flags -mcpu=v8 -Os -g.
 * Source form: the byte offset is added inside the index (the +1 gives the target's ldub [%g1+1]); the
 * result is the unsigned char type bool.
 */
#define PHY_RECORD_SIZE 24      /* bytes per entry of hdmi_phy_records */
#define PHY_RECORD_EQ_DONE 1    /* byte +1 */

extern unsigned char hdmi_phy_records[];

/* Returns 1 when byte +1 (eq_done) of the PHY's 24-byte record is 1, otherwise 0.
 *   phy: PHY index (low 8 bits used) */
unsigned char hdmi_phy_is_eq_done(unsigned int phy)
{
    return (hdmi_phy_records[(phy & 0xff) * PHY_RECORD_SIZE + PHY_RECORD_EQ_DONE] ^ 1) == 0;
}
