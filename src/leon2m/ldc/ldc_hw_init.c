/* ldc_hw_init  (FUN_a00fb9ec)
 *
 * Load both curves and write the fixed start values of the grid block.
 * Name basis: descriptive - ids 0x0C..0x11 with fixed values; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fb9ec, flags -mcpu=v8 -O3 -g.
 * Source form: six separate locals; the order of their assignments decides the store schedule.
 */
extern void ldc_hw_load_curve_first(void);
extern void ldc_hw_load_curve_second(void);
extern unsigned int ldc_hw_access_register(unsigned int id, unsigned int *v, unsigned int w, unsigned int h);
extern unsigned short DAT_a802d67a_hsize;       /* width kept for the grid block */
extern unsigned short DAT_a802d678_vsize;       /* height kept for the grid block */

/*
 * Load the two 17-point curves, then write one fixed value through each of the register ids 0xC to 0x11
 * (ids 12..17 of ldc_hw_access_register): 0, 1, 0, 0x80, 0x80, 0x100 in that order. Always returns 1.
 * No routine calls this copy; ldc_hw_command has the same code inline for its init command.
 */
int ldc_hw_init(void)
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
