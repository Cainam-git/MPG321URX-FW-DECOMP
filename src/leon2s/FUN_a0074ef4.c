/* leon2s FUN_a0074ef4 @ 0xa0074ef4-0xa0074f60 (27 words), flags -mcpu=v8 -Os -g.
 * Code facts: reads entry idx of the 4-byte table DAT_a00b3a64 (byte +0 rct, halfword +2 cft, the AeqEnt layout of
 * DRV_HDMI_EQScan_FSM_PHY_PreAEQ); for ch < 3 tail-calls FUN_a00a7488(port, DAT_a00b3b78[ch], 0xff0000f0,
 * (rct & 0xf) | (cft << 8)).
 * Same form as the matching block of DRV_HDMI_EQScan_FSM_PHY_PreAEQ (rct and cft read into locals before the
 * 'ch < 3' test, rct first). Aids: none.
 */
struct AeqEnt { unsigned char rct; unsigned char _1; unsigned short cft; };
extern const struct AeqEnt DAT_a00b3a64[];
extern const unsigned short DAT_a00b3b78[];
extern void FUN_a00a7488(unsigned int, unsigned short, unsigned int, unsigned int);

void FUN_a0074ef4(unsigned char port, unsigned char ch, unsigned char idx)
{
    unsigned short cft;
    unsigned char rct;

    rct = DAT_a00b3a64[idx].rct;
    cft = DAT_a00b3a64[idx].cft;
    if (ch < 3)
        FUN_a00a7488(port, DAT_a00b3b78[ch], 0xff0000f0, (rct & 0xf) | (cft << 8));
}
