/* leon2m FUN_a00dfa10 @ 0xa00dfa10-0xa00dfb30 (72 words).
 * Checks a phy version: returns 1 when it is 2. Otherwise calls FUN_a00df80c() (prints the step name from the word
 * at 0xa802b530 and the words at 0xa802b534 / 0xa802b538 as "%s phy%d byte%d"), FUN_a00e0bd8(), prints
 * "Invalid phy version: %d" and returns 0.
 * FUN_a00df80c and FUN_a00df8f4 are defined first in this file: the shared string pool is laid out in their order.
 * FUN_a00df80c is inlined. The function table ends this function at 0xa00dfa98; the code (jump-table case blocks)
 * runs to 0xa00dfb30.
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

int FUN_a00dfa10(unsigned int ver)
{
    int ok = (ver == 2);

    if (!ok) {
        FUN_a00df80c();
        FUN_a00e0bd8();
        FUN_a00df170("Invalid phy version: %d\n", ver);
    }
    return ok;
}
