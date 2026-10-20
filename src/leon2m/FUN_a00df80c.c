/* leon2m FUN_a00df80c @ 0xa00df80c-0xa00df8f4 (58 words).
 * Picks the string "INIT", "CLK_TREE", "ZQK", "DUTY", "PSD", "WL", "QSEN", "R_DESKEW", "R_EYE", "R_VREF", "W_DESKEW",
 * "W_EYE" or "W_VREF" for values 0..12 of the step byte of the block at 0xa802b530 ("unknown" otherwise) and prints it
 * with FUN_a00df170("%s phy%d byte%d\n", ...) and the block's phy and byte fields (field names from that format
 * string). The same definition comes first in the source of FUN_a00df8f4, which inlines it.
 */
struct Step {
    unsigned int step;
    unsigned int phy;
    unsigned int byte;
};
extern struct Step DAT_a802b530;
extern int FUN_a00df170(const char *fmt, ...);
extern void FUN_a00e0bd8(void);

void FUN_a00df80c(void)
{
    const char *n = "unknown";

    switch (DAT_a802b530.step) {
    case 0: n = "INIT"; break;
    case 1: n = "CLK_TREE"; break;
    case 2: n = "ZQK"; break;
    case 3: n = "DUTY"; break;
    case 4: n = "PSD"; break;
    case 5: n = "WL"; break;
    case 6: n = "QSEN"; break;
    case 7: n = "R_DESKEW"; break;
    case 8: n = "R_EYE"; break;
    case 9: n = "R_VREF"; break;
    case 10: n = "W_DESKEW"; break;
    case 11: n = "W_EYE"; break;
    case 12: n = "W_VREF"; break;
    }
    FUN_a00df170("%s phy%d byte%d\n", n, DAT_a802b530.phy, DAT_a802b530.byte);
}
