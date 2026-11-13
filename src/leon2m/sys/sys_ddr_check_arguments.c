/* sys_ddr_check_arguments  (FUN_a00dfc50)
 *
 * Check the interface number, its version and the memory type in one go.
 * Returns: 1 when all are valid
 * Name basis: proven - the three checks above, inlined
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dfc50 @ 0xa00dfc50-0xa00dff94 (209 words), flags -mcpu=v8 -O3 -g.
 * Source form: sys_ddr_print_step and the three checks are defined first in this file (they fix the shared string
 * pool order) and are inlined here.
 */
/* Training steps and their printed names; the number is kept in sys_ddr_step_record. */
enum {
    DDR_STEP_INIT       = 0,
    DDR_STEP_CLK_TREE   = 1,
    DDR_STEP_ZQK        = 2,
    DDR_STEP_DUTY       = 3,
    DDR_STEP_PSD        = 4,
    DDR_STEP_WL         = 5,
    DDR_STEP_QSEN       = 6,
    DDR_STEP_R_DESKEW   = 7,
    DDR_STEP_R_EYE      = 8,
    DDR_STEP_R_VREF     = 9,
    DDR_STEP_W_DESKEW   = 10,
    DDR_STEP_W_EYE      = 11,
    DDR_STEP_W_VREF     = 12
};

/* What the checks accept. */
#define DDR_PHY_ID_MAX       2              /* memory interface numbers 0..2 */
#define DDR_PHY_VERSION      2
#define DDR_GENERATION_MIN   3              /* DDR3 */
#define DDR_GENERATION_MAX   4              /* DDR4 */

/* The record of the training step in progress, for the error messages. */
struct ddr_step_record {
    unsigned int step;                      /* DDR_STEP_* */
    unsigned int phy;                       /* memory interface number */
    unsigned int byte;                      /* data byte */
};
extern struct ddr_step_record sys_ddr_step_record;
extern int dbg_printf(const char *fmt, ...);
extern void sys_ddr_print_fatal_prefix(void);

/* The step-line printer of sys_ddr_print_step (see sys_ddr_print_step), defined first in this file as in the others. */
void sys_ddr_print_step(void)
{
    const char *step_name = "unknown";

    switch (sys_ddr_step_record.step) {
    case DDR_STEP_INIT: step_name = "INIT"; break;
    case DDR_STEP_CLK_TREE: step_name = "CLK_TREE"; break;
    case DDR_STEP_ZQK: step_name = "ZQK"; break;
    case DDR_STEP_DUTY: step_name = "DUTY"; break;
    case DDR_STEP_PSD: step_name = "PSD"; break;
    case DDR_STEP_WL: step_name = "WL"; break;
    case DDR_STEP_QSEN: step_name = "QSEN"; break;
    case DDR_STEP_R_DESKEW: step_name = "R_DESKEW"; break;
    case DDR_STEP_R_EYE: step_name = "R_EYE"; break;
    case DDR_STEP_R_VREF: step_name = "R_VREF"; break;
    case DDR_STEP_W_DESKEW: step_name = "W_DESKEW"; break;
    case DDR_STEP_W_EYE: step_name = "W_EYE"; break;
    case DDR_STEP_W_VREF: step_name = "W_VREF"; break;
    }
    dbg_printf("%s phy%d byte%d\n", step_name, sys_ddr_step_record.phy, sys_ddr_step_record.byte);
}

/* Copy of sys_ddr_check_phy_id (sys_ddr_check_phy_id), defined first in this file. */
int sys_ddr_check_phy_id(unsigned int id)
{
    int ok = 0;

    if (id <= DDR_PHY_ID_MAX)
        ok = 1;
    else {
        sys_ddr_print_step();
        sys_ddr_print_fatal_prefix();
        dbg_printf("Invalid phy ID: %d\n", id);
    }
    return ok;
}

/* Copy of sys_ddr_check_phy_version (sys_ddr_check_phy_version), defined first in this file. */
int sys_ddr_check_phy_version(unsigned int ver)
{
    int ok = (ver == DDR_PHY_VERSION);

    if (!ok) {
        sys_ddr_print_step();
        sys_ddr_print_fatal_prefix();
        dbg_printf("Invalid phy version: %d\n", ver);
    }
    return ok;
}

/* Copy of sys_ddr_check_generation (sys_ddr_check_generation), defined first in this file. */
int sys_ddr_check_generation(unsigned int gen)
{
    int ok = 0;

    if (gen >= DDR_GENERATION_MIN && gen <= DDR_GENERATION_MAX)
        ok = 1;
    else {
        sys_ddr_print_step();
        sys_ddr_print_fatal_prefix();
        dbg_printf("Invalid DDR generation: %d\n", gen);
    }
    return ok;
}

/*
 * Check the three arguments that every training routine starts with.
 *
 *   id    memory interface number (valid: 0..2)
 *   ver   interface version (valid: 2)
 *   gen   DDR generation (valid: 3 or 4)
 *
 * Returns 1 when all three are valid. The checks run in this order and stop at the first failure, which prints
 * its own message (see sys_ddr_check_phy_id and the two after it) and makes the result 0.
 *
 * All callers (the training routines) call it as a statement and drop the result, so what it does for them is
 * the error output.
 */
int sys_ddr_check_arguments(unsigned int id, unsigned int ver, unsigned int gen)
{
    return sys_ddr_check_phy_id(id) && sys_ddr_check_phy_version(ver) && sys_ddr_check_generation(gen);
}
