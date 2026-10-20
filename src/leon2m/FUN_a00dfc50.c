/* leon2m FUN_a00dfc50 @ 0xa00dfc50-0xa00dff94 (209 words).
 * Returns FUN_a00df8f4(id) && FUN_a00dfa10(ver) && FUN_a00dfb30(gen): 1 when the phy ID, phy version and DDR
 * generation are all valid, otherwise 0 after the first failing check printed its messages.
 * The three checks and FUN_a00df80c are defined first in this file (they fix the shared string pool order) and
 * are inlined here.
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

int FUN_a00dfb30(unsigned int gen)
{
    int ok = 0;

    if (gen >= 3 && gen <= 4)
        ok = 1;
    else {
        FUN_a00df80c();
        FUN_a00e0bd8();
        FUN_a00df170("Invalid DDR generation: %d\n", gen);
    }
    return ok;
}

int FUN_a00dfc50(unsigned int id, unsigned int ver, unsigned int gen)
{
    return FUN_a00df8f4(id) && FUN_a00dfa10(ver) && FUN_a00dfb30(gen);
}
