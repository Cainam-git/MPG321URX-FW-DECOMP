/* ldc_hw_setup_for_panel_size  (FUN_a00fc044)
 *
 * Set the grid block up for the size of the active panel timing row.
 * Name basis: derived - reads the two size fields of the row; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fc044, flags -mcpu=v8 -O3 -g.
 * ldc_hw_command is declared int-returning (with void the delay slot is filled differently).
 */

#define R(a) (*(volatile unsigned int *)(a))

/* Ids of ldc_hw_access_register used here. */
#define LDC_ID_INIT      3
#define LDC_ID_SET_SIZE  6

/* Commands of ldc_hw_command. */
#define LDC_COMMAND_INIT         1
#define LDC_COMMAND_SET_STRENGTH 4

/* Interrupt level and source mask of the grid block's interrupt. */
#define LDC_IRQ_LEVEL  0xc
#define LDC_IRQ_SOURCE 0x100

extern unsigned char ldc_hw_mode3_pass_entry[];

/* The start of a panel timing row; h08 and h0a are its width and height fields (+0x08, +0x0A). */
struct PanelParam { unsigned int w0; unsigned short h4; unsigned char b6, b7; unsigned short h08, h0a; };
extern struct PanelParam *panel_working_row_ptr;
extern unsigned short ldc_started_flag;
extern unsigned int ldc_hw_access_register(unsigned int, unsigned int *, unsigned int, unsigned int);
extern int ldc_hw_command(unsigned int, unsigned int, unsigned int);
extern void irq_set_source_handler(int, int, unsigned int);
extern void irq_unmask_sources(int, int);

/*
 * Start the grid block for the panel row now in use: register 0xCF00EFC0 = 0xC0, register id 3 with 3840 x 2160,
 * register id 6 with the width and height fields of the working row (panel_working_row_ptr), then the same start as
 * ldc_hw_start (init command, ldc_started_flag, set-strength command, enable bit, interrupt handler). The last
 * step writes the fixed values 0xC0, 0x40, 0, 0, 0x80, 0x80, 0x13, 0 to the words 0xCF010300..0xCF01031C and 0x80
 * to 0xCF010330, with 0xCF00ED80 set to 8 before and to 0 after. No routine calls this one.
 */
void ldc_hw_setup_for_panel_size(void)
{
    unsigned int value = 0;

    R(0xcf00efc0) = 0xc0;
    ldc_hw_access_register(LDC_ID_INIT, &value, 0xf00, 0x870);
    ldc_hw_access_register(LDC_ID_SET_SIZE, &value, panel_working_row_ptr->h08, panel_working_row_ptr->h0a);
    ldc_hw_command(0, LDC_COMMAND_INIT, 0);
    ldc_started_flag = 1;
    ldc_hw_command(0, LDC_COMMAND_SET_STRENGTH, 0);
    R(0xd0040000) |= 0x80000000;
    irq_set_source_handler(LDC_IRQ_LEVEL, LDC_IRQ_SOURCE, ldc_hw_mode3_pass_entry);
    irq_unmask_sources(LDC_IRQ_LEVEL, LDC_IRQ_SOURCE);
    R(0xcf00ed80) = 8;
    R(0xcf010300) = 0xc0;
    R(0xcf010304) = 0x40;
    R(0xcf010308) = 0;
    R(0xcf01030c) = 0;
    R(0xcf010310) = 0x80;
    R(0xcf010314) = 0x80;
    R(0xcf010318) = 0x13;
    R(0xcf01031c) = 0;
    R(0xcf010330) = 0x80;
    R(0xcf00ed80) = 0;
}
