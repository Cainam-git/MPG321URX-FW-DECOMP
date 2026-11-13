/* pq_ace_configure  (FUN_a00f7894)
 *
 * Write the ACE configuration bits and print them.
 * Name basis: proven - prints 'Config ACE (%d) : (%d)'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f7894 @ 0xa00f7894, flags -mcpu=v8 -O3 -g.
 * Source form: the switch on config_arg[2] has three case labels; the case for 0 is written explicitly
 * and lies below 8, which makes GCC's compare tree 'cmp 8; be; bg'. The callers pass a 3-byte struct by
 * value, which arrives here as a pointer to the caller's copy.
 */
#define R(a) (*(volatile unsigned int *)(a))

#define ACE_CTRL   0xcf00ee80   /* bits 1..2: window for ACE access */
#define ACE_CONFIG 0xcf00eec0   /* bits 2..3: the sum code read by pq_ace_read_histogram */
#define ACE_SUM_COUNT_8  8      /* sum_count value that selects code 1 */
#define ACE_SUM_COUNT_16 16     /* sum_count value that selects code 2 */

extern unsigned char pq_selected_window;
extern int dbg_printf(const char *fmt, ...);

/*
 * Configure ACE for the selected window and print the configuration.
 *
 * config_arg points to the 3-byte ACE configuration (struct ace_config_arg of pq_auto_level_task):
 *   [0] = config_bit7, [1] = config_bit6, [2] = sum_count.
 * sum_count selects a code: 8 -> 1, 16 -> 2, anything else -> 0. pq_ace_read_histogram reads
 * 4 << code sums, so 8 and 16 give 8 and 16 sums and every other value 4.
 *
 * Bits 1..2 of ACE_CTRL get pq_selected_window. ACE_CONFIG keeps bits 1, 3, 4 and 5 and gets byte 0 shifted to
 * bit 7, byte 1 to bit 6 and the code to bits 2..3; bit 3 is not cleared first, so when it was set it stays
 * set (code 1 then reads back as 3, code 0 as 2). Both writes clear bits 8..31 before the new bits are added. Then
 * "Config ACE (window) : (sum_count)" is printed.
 *
 * Callers: pq_auto_level_task and pq_api_config_ace; pq_ace_init holds its own copy of these steps.
 */
void pq_ace_configure(unsigned char *config_arg)
{
    unsigned char sum_count_code = 0;

    switch (config_arg[2]) {
    case 0:
        sum_count_code = 0;
        break;
    case ACE_SUM_COUNT_8:
        sum_count_code = 1;
        break;
    case ACE_SUM_COUNT_16:
        sum_count_code = 2;
        break;
    }
    R(ACE_CTRL) = (R(ACE_CTRL) & 0xf9) | (pq_selected_window << 1);
    R(ACE_CONFIG) = (R(ACE_CONFIG) & 0x3a) | (config_arg[0] << 7) | (config_arg[1] << 6) | (sum_count_code << 2);
    dbg_printf("Config ACE (%d) : (%d)\r\n", pq_selected_window, config_arg[2]);
}
