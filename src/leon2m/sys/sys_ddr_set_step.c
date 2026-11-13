/* sys_ddr_set_step  (FUN_a00dffb4)
 *
 * Record the current training step, interface and data byte for the error messages.
 * Name basis: proven - three words at 0xA802B530
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dffb4 @ 0xa00dffb4-0xa00dffcc (6 words), flags -mcpu=v8 -O2 -g.
 * Source form: three plain stores into a struct at the data label.
 */
/* The three words at sys_ddr_step_record; sys_ddr_print_step prints them as "%s phy%d byte%d". */
struct ddr_step_record {
    unsigned int step;      /* training step number (DDR_STEP_*) */
    unsigned int phy;       /* memory interface number */
    unsigned int byte;      /* data byte number */
};
extern struct ddr_step_record sys_ddr_step_record;

/*
 * Remember which training step is running on which memory interface and data byte, so that the error messages
 * of the training code can name them.
 */
void sys_ddr_set_step(unsigned int step, unsigned int phy, unsigned int byte)
{
    sys_ddr_step_record.step = step;
    sys_ddr_step_record.phy = phy;
    sys_ddr_step_record.byte = byte;
}
