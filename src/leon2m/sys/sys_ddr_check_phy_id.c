/* sys_ddr_check_phy_id  (FUN_a00df8f4)
 *
 * Check that a memory interface number is valid.
 * Returns: 1 when valid
 * Name basis: proven - prints 'Invalid phy ID' for numbers above 2
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00df8f4 @ 0xa00df8f4-0xa00dfa10 (71 words), flags -mcpu=v8 -O3 -g.
 * Source form: sys_ddr_print_step (sys_ddr_print_step) is defined in this file before this routine, so its code fixes
 * the order of the shared strings, and it is inlined here. The firmware function table ends sys_ddr_print_step at
 * 0xa00df85c and this routine at 0xa00df978; the code runs to 0xa00df8f4 and 0xa00dfa10 (jump-table case blocks).
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

/*
 * Print where the memory-interface training is: the name of the current step, the interface number and the data
 * byte, as "<step> phy<n> byte<n>". The three numbers come from sys_ddr_step_record. A step number outside 0..12
 * prints "unknown". The error paths print this line before the error text.
 */
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

/*
 * Check a memory interface number.
 *
 *   id   the interface number
 *
 * Returns 1 when id is 0, 1 or 2. Otherwise it prints the step line, the "[FATAL] ddr_fatal: " prefix and
 * "Invalid phy ID: <id>", and returns 0. Nothing is stopped here; the caller decides what to do with the 0.
 *
 * Callers: sys_ddr_set_pll (the result is dropped) and sys_ddr_check_arguments.
 */
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
