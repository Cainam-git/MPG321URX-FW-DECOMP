/* pq_window_enable  (FUN_a00f6898)
 *
 * Switch picture window 0..3 on.
 * Name basis: derived - bit 0 or 1 of 0xCF00EC80 or 0xCF00ECA8 and the matching bits of 0xCF00EE40 /
 *   0xCF00EE68
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f6898 @ 0xa00f6898-0xa00f6940 (42 words). -mcpu=v8 -O3 -g.
 * Source form: reads-first order (one statement per register gave ld/st/ld/st); a plain switch gives the fw
 * compare tree 'cmp 1; be; bcc'; volatile only on the real hardware registers.
 */
#define R(a) (*(volatile unsigned int *)(a))

#define REG_CF00EC80 0xcf00ec80     /* WINDOW_CTRL_01: windows 0 and 1 */
#define REG_CF00EE40 0xcf00ee40
#define REG_CF00ECA8 0xcf00eca8     /* WINDOW_CTRL_23: windows 2 and 3 */
#define REG_CF00EE68 0xcf00ee68

#define ENABLE_BIT_0 1
#define ENABLE_BIT_1 2
#define ENABLE_BITS_0_1 3
#define ENABLE_BITS_2_3 0xc

/*
 * Switch picture window 0..3 on; any other number does nothing.
 *
 * Windows 0 and 1 use 0xCF00EC80 and 0xCF00EE40, windows 2 and 3 use 0xCF00ECA8 and 0xCF00EE68. The even
 * window sets bit 0 of the first register and bits 0..1 of the second, the odd window bit 1 and bits 2..3.
 * Both registers are read before either is written, and each written value is cut to 8 bits.
 *
 * Callers: pq_api_enable_window, pq_api_enable_channel_window, pq_fga_handle_command,
 * input_channel_bring_up_task.
 */
void pq_window_enable(unsigned int window)
{
    unsigned int first_reg_value, second_reg_value;

    switch (window) {
    case 0:
        first_reg_value = R(REG_CF00EC80); second_reg_value = R(REG_CF00EE40);
        R(REG_CF00EC80) = (first_reg_value | ENABLE_BIT_0) & 0xff; R(REG_CF00EE40) = (second_reg_value | ENABLE_BITS_0_1) & 0xff;
        break;
    case 1:
        first_reg_value = R(REG_CF00EC80); second_reg_value = R(REG_CF00EE40);
        R(REG_CF00EC80) = (first_reg_value | ENABLE_BIT_1) & 0xff; R(REG_CF00EE40) = (second_reg_value | ENABLE_BITS_2_3) & 0xff;
        break;
    case 2:
        first_reg_value = R(REG_CF00ECA8); second_reg_value = R(REG_CF00EE68);
        R(REG_CF00ECA8) = (first_reg_value | ENABLE_BIT_0) & 0xff; R(REG_CF00EE68) = (second_reg_value | ENABLE_BITS_0_1) & 0xff;
        break;
    case 3:
        first_reg_value = R(REG_CF00ECA8); second_reg_value = R(REG_CF00EE68);
        R(REG_CF00ECA8) = (first_reg_value | ENABLE_BIT_1) & 0xff; R(REG_CF00EE68) = (second_reg_value | ENABLE_BITS_2_3) & 0xff;
        break;
    }
}
