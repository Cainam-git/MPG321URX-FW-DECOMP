/* panel_output_get_source_select  (FUN_a0106228)
 *
 * Return 1, 2, 3 or 4 for the first set bit (0, 1, 2 or 4) of the output stage's source select.
 * Returns: 1..4, or 0 when none of those bits is set
 * Note: The register is read again for every test.
 * Name basis: descriptive - bits 0..2 and 4 of register 0xCF00ED80; sys_fill_output_size_record tests the
 *   result for 4
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0106228, flags -mcpu=v8 -O3 -g.
 * Source form: the register is read again for every test (volatile), and the result is an unsigned char local.
 */
#define reg_panel_output_source_select (*(volatile unsigned int *)0xcf00ed80)

/*
 * Read register 0xcf00ed80 back as a selector, the inverse of panel_output_set_source_select:
 * bit 0 set gives 1, else bit 1 gives 2, else bit 2 gives 3, else bit 4 gives 4 (the last term is
 * (register >> 2) & 4). Returns 0 when none of these bits is set.
 * Called from sys_fill_output_size_record, which tests for 4.
 */
unsigned int panel_output_get_source_select(void)
{
    unsigned char selector;

    selector = 1;
    if ((((reg_panel_output_source_select & 1) == 0) && (selector = 2, (reg_panel_output_source_select & 2) == 0)) &&
        (selector = 3, (reg_panel_output_source_select & 4) == 0)) {
        selector = reg_panel_output_source_select >> 2 & 4;
    }
    return selector;
}
