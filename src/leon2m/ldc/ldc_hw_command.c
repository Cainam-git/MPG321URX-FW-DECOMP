/* ldc_hw_command  (FUN_a00fbdcc)
 *
 * Run one of the grid block's commands: init, suspend, timing or strength.
 * Name basis: derived - switch on the command selector
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fbdcc @ 0xa00fbdcc, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: ldc_hw_init and ldc_hw_suspend_or_resume are the matched same-file
 * functions, defined here and inlined by GCC; ldc_hw_init is declared inline (GCC 3.4 at -O3 does not inline it
 * otherwise; as a non-static inline function it also keeps its own copy in the image, as the firmware has at
 * 0xa00fb9ec).
 */

#define LDC_REG_CTRL (*(volatile unsigned int *)0xd0040000)     /* bit 31 enable */
#define LDC_ENABLE_BIT 0x80000000

/* Commands of ldc_hw_command. */
enum {
    LDC_COMMAND_INIT           = 1,
    LDC_COMMAND_SUSPEND_RESUME = 2,
    LDC_COMMAND_SET_TIMING     = 3,
    LDC_COMMAND_SET_STRENGTH   = 4
};

extern void ldc_hw_load_curve_first(void);
extern void ldc_hw_load_curve_second(void);
extern int ldc_hw_access_register(unsigned int id, unsigned int *v, unsigned int w, unsigned int h);
extern int ldc_hw_set_timing(unsigned char, unsigned int);
extern int ldc_hw_set_strength(unsigned char, unsigned char);
extern unsigned short DAT_a802d678_vsize;
extern unsigned short DAT_a802d67a_hsize;
extern unsigned char ldc_saved_enable_bit;
extern unsigned char ldc_cmd_strength_arg;
extern unsigned short ldc_cmd_timing_arg;
extern unsigned char ldc_cmd_suspend_arg;

/*
 * Load both 17-point curves into the grid block, then write fixed values through ldc_hw_access_register with the
 * ids 0xC to 0x11, in this order: 0, 1, 0, 0x80, 0x80, 0x100. Always returns 1.
 */
__inline__ int ldc_hw_init(void)
{
    unsigned int value_id_11, value_id_10, value_id_f, value_id_e, value_id_d, value_id_c;
    value_id_f = 0x80;
    value_id_d = 1;
    value_id_10 = 0x80;
    value_id_11 = 0x100;
    value_id_c = 0;
    value_id_e = 0;

    ldc_hw_load_curve_first();
    ldc_hw_load_curve_second();
    ldc_hw_access_register(0xc, &value_id_c, DAT_a802d67a_hsize, DAT_a802d678_vsize);
    ldc_hw_access_register(0xd, &value_id_d, DAT_a802d67a_hsize, DAT_a802d678_vsize);
    ldc_hw_access_register(0xe, &value_id_e, DAT_a802d67a_hsize, DAT_a802d678_vsize);
    ldc_hw_access_register(0xf, &value_id_f, DAT_a802d67a_hsize, DAT_a802d678_vsize);
    ldc_hw_access_register(0x10, &value_id_10, DAT_a802d67a_hsize, DAT_a802d678_vsize);
    ldc_hw_access_register(0x11, &value_id_11, DAT_a802d67a_hsize, DAT_a802d678_vsize);
    return 1;
}

/* Replace the bits of *reg selected by mask with val shifted left by shift. */
static void wr(volatile unsigned int *reg, unsigned int mask, unsigned int shift, unsigned int val)
{
    *reg = (*reg & ~mask) | ((val << shift) & mask);
}

/*
 * Suspend (nonzero 'suspend') or resume (0) the grid block: suspending keeps the enable bit (bit 31 of the
 * control register) in ldc_saved_enable_bit and clears it; resuming writes the kept bit back. Always returns 1.
 */
int ldc_hw_suspend_or_resume(unsigned char suspend)
{
    if (suspend) {
        unsigned int v = LDC_REG_CTRL;
        ldc_saved_enable_bit = v >> 31;
        LDC_REG_CTRL = v & ~LDC_ENABLE_BIT;
    } else
        wr(&LDC_REG_CTRL, LDC_ENABLE_BIT, 31, ldc_saved_enable_bit);
    return 1;
}

/*
 * Run one command of the grid block.
 *
 *   selector  passed to the timing and strength commands (the callers pass 0)
 *   command   1 initialise (ldc_hw_init), 2 suspend or resume with the stored argument ldc_cmd_suspend_arg,
 *             3 set the mode with ldc_cmd_timing_arg (ldc_hw_set_timing), 4 set the level with ldc_cmd_strength_arg
 *             (ldc_hw_set_strength)
 *   unused    not read
 *
 * Returns the result of the command (1 on success), 0 for any other command number. Called by ldc_hw_start and by
 * ldc_hw_setup_for_panel_size with the commands 1 and 4.
 */
int ldc_hw_command(unsigned int selector, unsigned int command, unsigned int unused)
{
    unsigned char result = 0;

    switch (command) {
    case LDC_COMMAND_INIT:
        result = ldc_hw_init();
        break;
    case LDC_COMMAND_SUSPEND_RESUME:
        result = ldc_hw_suspend_or_resume(ldc_cmd_suspend_arg);
        break;
    case LDC_COMMAND_SET_TIMING:
        result = ldc_hw_set_timing(selector, ldc_cmd_timing_arg);
        break;
    case LDC_COMMAND_SET_STRENGTH:
        result = ldc_hw_set_strength(selector, ldc_cmd_strength_arg);
        break;
    }
    return result;
}
