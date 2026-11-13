/* sys_ddr_check_phy_version  (FUN_a00dfa10)
 *
 * Check that the memory interface version is supported.
 * Returns: 1 when valid
 * Name basis: proven - prints 'Invalid phy version' unless it is 2; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dfa10 @ 0xa00dfa10-0xa00dfb30 (72 words), flags -mcpu=v8 -O3 -g.
 * Source form: sys_ddr_print_step and sys_ddr_check_phy_id are defined first in this file: the shared string pool
 * is laid out in their order. sys_ddr_print_step is inlined. The function table ends this routine at 0xa00dfa98;
 * the code (jump-table case blocks) runs to 0xa00dfb30.
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

/*
 * Check the version of the memory interface.
 *
 *   ver   the version number
 *
 * Returns 1 when ver is 2. Otherwise it prints the step line, the "[FATAL] ddr_fatal: " prefix and
 * "Invalid phy version: <ver>", and returns 0. Nothing in the image calls this routine by itself; it is
 * part of sys_ddr_check_arguments.
 */
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
