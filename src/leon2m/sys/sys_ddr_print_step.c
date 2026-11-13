/* sys_ddr_print_step  (FUN_a00df80c)
 *
 * Print the name of the current training step with the interface and data byte.
 * Name basis: proven - one of 13 step names from the record at 0xA802B530
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00df80c @ 0xa00df80c-0xa00df8f4 (58 words), flags -mcpu=v8 -O3 -g.
 * Source form: the same definition comes first in the source of sys_ddr_check_phy_id, which inlines it. The name
 * pointer starts as "unknown" and is replaced in the switch.
 */
/* The training steps; the names are the firmware's own texts. */
enum {
    DDR_STEP_INIT = 0, DDR_STEP_CLK_TREE = 1, DDR_STEP_ZQK = 2, DDR_STEP_DUTY = 3, DDR_STEP_PSD = 4,
    DDR_STEP_WL = 5, DDR_STEP_QSEN = 6, DDR_STEP_R_DESKEW = 7, DDR_STEP_R_EYE = 8, DDR_STEP_R_VREF = 9,
    DDR_STEP_W_DESKEW = 10, DDR_STEP_W_EYE = 11, DDR_STEP_W_VREF = 12
};

/* The record at sys_ddr_step_record; the field names come from the print format "%s phy%d byte%d". */
struct ddr_step_record {
    unsigned int step;
    unsigned int phy;
    unsigned int byte;
};
extern struct ddr_step_record sys_ddr_step_record;
extern int dbg_printf(const char *fmt, ...);
extern void sys_ddr_print_fatal_prefix(void);

/* Print the name of the current training step with the interface (phy) and byte numbers of the record. */
void sys_ddr_print_step(void)
{
    const char *name = "unknown";

    switch (sys_ddr_step_record.step) {
    case DDR_STEP_INIT: name = "INIT"; break;
    case DDR_STEP_CLK_TREE: name = "CLK_TREE"; break;
    case DDR_STEP_ZQK: name = "ZQK"; break;
    case DDR_STEP_DUTY: name = "DUTY"; break;
    case DDR_STEP_PSD: name = "PSD"; break;
    case DDR_STEP_WL: name = "WL"; break;
    case DDR_STEP_QSEN: name = "QSEN"; break;
    case DDR_STEP_R_DESKEW: name = "R_DESKEW"; break;
    case DDR_STEP_R_EYE: name = "R_EYE"; break;
    case DDR_STEP_R_VREF: name = "R_VREF"; break;
    case DDR_STEP_W_DESKEW: name = "W_DESKEW"; break;
    case DDR_STEP_W_EYE: name = "W_EYE"; break;
    case DDR_STEP_W_VREF: name = "W_VREF"; break;
    }
    dbg_printf("%s phy%d byte%d\n", name, sys_ddr_step_record.phy, sys_ddr_step_record.byte);
}
