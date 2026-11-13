/* pq_load_gamma  (FUN_a012eeb0)
 *
 * Load the gamma table set with a given number.
 * Name basis: proven - prints 'LoadGamma : %d'; switch over 0x11..0x30
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012eeb0 @ 0xa012eeb0-0xa012f12c (636 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: the device_settings_byte_0x37 test is written '== 0' first (the firmware's fall-through order).
 */

/* Gamma numbers: the switch value selects which table is loaded. */
#define GAMMA_FGA_FIRST       0x11     /* loads the stored FGA gamma block of bit (1 << (v & 0xf)) */
#define GAMMA_FGA_DOUBLE_BLOCK 0x19    /* loads the double FGA block (bit 0x200) */
#define GAMMA_CURVE_INTERP    0x20     /* unpacks and interpolates a ROM curve set */
#define GAMMA_FIXED_TABLE     0x30     /* loads a fixed secondary-LUT table set */

#define GAMMA_SLEEP_TICKS     0x32    /* wait after switching off a LUT that was on (timer ticks) */
#define CHANNEL_STRIDE_CURVE  0x140   /* bytes between the channels' curve tables */
#define CHANNEL_STRIDE_TABLE  0x40    /* bytes between the channels' secondary tables */

extern int dbg_printf(const char *fmt, ...);
extern unsigned char pq_gamma_is_primary_lut_enabled(void);
extern void pq_gamma_enable_primary_lut(void);
extern void pq_gamma_disable_primary_lut(void);
extern unsigned char pq_gamma_is_secondary_lut_enabled(void);
extern void pq_gamma_enable_secondary_lut(void);
extern void pq_gamma_disable_secondary_lut(void);
extern void pq_gamma_write_secondary_lut(int, int);
extern void pq_gamma_disable_first_curve_stage(void);
extern void pq_gamma_disable_second_curve_stage(void);
extern void pq_gamma_set_lut_options(unsigned char, unsigned char);
extern void pq_fga_load_gamma_from_storage(unsigned int bit);
extern void pq_load_gamma_curve_interpolated(unsigned char ch, const unsigned char *s);
extern void timer_sleep_ticks(int ms);
extern unsigned char device_settings_byte_0x37;
extern unsigned int pq_gamma_set_table[], pq_gamma_set_table_curve[];

/*
 * Load the gamma table set chosen by v.
 *
 *   v  a gamma number in 0x11..0x30, see the switch below
 *
 * For gamma numbers 0x11..0x18 and 0x1A, device settings byte +0x37 decides which LUT the stored block goes
 * into: 0 the secondary LUT, any other value the primary LUT. 0x19 and 0x20 always use the primary LUT, 0x30
 * the secondary. The LUT about to be loaded is switched off first (with a wait of 50 ticks when it was on), the
 * other LUT is switched off without a wait, and the loaded LUT is switched on at the end. Only the table index
 * 0 is ever used for 0x20 and 0x30 (v & 0xf is 0).
 *
 * Callers: pq_api_set_gamma_and_reapply, sys_api_config.
 */
void pq_load_gamma(unsigned char v)
{
    dbg_printf("\rLoadGamma : %02X\r\n", v);
    switch (v) {
    case 0x11: case 0x12: case 0x13: case 0x14: case 0x15: case 0x16: case 0x17: case 0x18: case 0x1a:
        /* One stored FGA block, selected by bit (1 << (v & 0xf)) of the block keys. */
        if (device_settings_byte_0x37 == 0) {
            if (pq_gamma_is_secondary_lut_enabled()) {
                pq_gamma_disable_secondary_lut();
                timer_sleep_ticks(GAMMA_SLEEP_TICKS);
            }
            pq_gamma_disable_primary_lut();
            pq_gamma_disable_first_curve_stage();
            pq_gamma_disable_second_curve_stage();
            pq_fga_load_gamma_from_storage((unsigned short)(1 << (v & 0xf)));
            pq_gamma_enable_secondary_lut();
        } else {
            if (pq_gamma_is_primary_lut_enabled()) {
                pq_gamma_disable_primary_lut();
                timer_sleep_ticks(GAMMA_SLEEP_TICKS);
            }
            pq_gamma_disable_secondary_lut();
            pq_gamma_set_lut_options(0, 1);
            pq_fga_load_gamma_from_storage((unsigned short)(1 << (v & 0xf)));
            pq_gamma_enable_primary_lut();
        }
        break;
    case 0x19:
        /* The double block (two blocks, bit 0x200 = 1 << (0x19 & 0xf)), always into the primary LUT. */
        if (pq_gamma_is_primary_lut_enabled()) {
            pq_gamma_disable_primary_lut();
            timer_sleep_ticks(GAMMA_SLEEP_TICKS);
        }
        pq_gamma_disable_secondary_lut();
        pq_gamma_set_lut_options(0, 1);
        pq_fga_load_gamma_from_storage(0x200);
        pq_gamma_enable_primary_lut();
        break;
    case 0x20:
        /* A ROM curve set, unpacked and interpolated into the primary LUT of all three channels. */
        if (pq_gamma_is_primary_lut_enabled()) {
            pq_gamma_disable_primary_lut();
            timer_sleep_ticks(GAMMA_SLEEP_TICKS);
        }
        pq_gamma_disable_secondary_lut();
        pq_gamma_disable_first_curve_stage();
        pq_gamma_disable_second_curve_stage();
        pq_gamma_set_lut_options(1, 1);
        pq_load_gamma_curve_interpolated(0, (const unsigned char *)pq_gamma_set_table_curve[v & 0xf]);
        pq_load_gamma_curve_interpolated(1, (const unsigned char *)(pq_gamma_set_table_curve[v & 0xf] + CHANNEL_STRIDE_CURVE));
        pq_load_gamma_curve_interpolated(2, (const unsigned char *)(pq_gamma_set_table_curve[v & 0xf] + CHANNEL_STRIDE_CURVE * 2));
        pq_gamma_enable_primary_lut();
        break;
    case 0x30:
        /* A fixed table set into the secondary LUT of all three channels. */
        if (pq_gamma_is_secondary_lut_enabled()) {
            pq_gamma_disable_secondary_lut();
            timer_sleep_ticks(GAMMA_SLEEP_TICKS);
        }
        pq_gamma_disable_primary_lut();
        pq_gamma_disable_first_curve_stage();
        pq_gamma_disable_second_curve_stage();
        pq_gamma_write_secondary_lut(0, pq_gamma_set_table[v & 0xf]);
        pq_gamma_write_secondary_lut(1, pq_gamma_set_table[v & 0xf] + CHANNEL_STRIDE_TABLE);
        pq_gamma_write_secondary_lut(2, pq_gamma_set_table[v & 0xf] + CHANNEL_STRIDE_TABLE * 2);
        pq_gamma_enable_secondary_lut();
        break;
    default:
        /* A gamma number outside the table: switch every LUT and curve stage off. */
        pq_gamma_disable_primary_lut();
        pq_gamma_disable_secondary_lut();
        pq_gamma_disable_first_curve_stage();
        pq_gamma_disable_second_curve_stage();
        break;
    }
}
