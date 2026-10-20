/* leon2m FUN_a00df8f4 @ 0xa00df8f4-0xa00dfa10 (71 words).
 * Checks a phy ID: returns 1 when id <= 2. Otherwise calls FUN_a00df80c(), which prints "%s phy%d byte%d" with
 * the name of the step in the word at 0xa802b530 (0 INIT, 1 CLK_TREE, 2 ZQK, 3 DUTY, 4 PSD, 5 WL, 6 QSEN,
 * 7 R_DESKEW, 8 R_EYE, 9 R_VREF, 10 W_DESKEW, 11 W_EYE, 12 W_VREF, others "unknown") and the words at
 * 0xa802b534 / 0xa802b538; then FUN_a00e0bd8(), prints "Invalid phy ID: %d" and returns 0.
 * FUN_a00df80c is defined in this file (it comes first, so its code fixes the order of the shared strings) and is
 * inlined here. The firmware function table ends FUN_a00df80c at 0xa00df85c and this function at 0xa00df978;
 * the code runs to 0xa00df8f4 and 0xa00dfa10 (jump-table case blocks).
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

int FUN_a00df8f4(unsigned int id)
{
    int ok = 0;

    if (id <= 2)
        ok = 1;
    else {
        FUN_a00df80c();
        FUN_a00e0bd8();
        FUN_a00df170("Invalid phy ID: %d\n", id);
    }
    return ok;
}
