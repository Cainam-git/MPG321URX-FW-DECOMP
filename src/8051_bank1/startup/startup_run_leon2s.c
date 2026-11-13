/* startup_run_leon2s  (FUN_CODE_8f5a)
 *
 * Release the input processor from reset so it starts running.
 * Name basis: proven - prints 'Leon2 (Sub) RUN...'; core control 0x9F120008
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_8f5a @ 0x8f5a, OPTIMIZE(8,SPEED) (0xF9 bytes: a 4-byte constant follows a library call inline).
 * Source form: each step reads the register into startup_core_reg_value, changes it there and writes it back.
 */
typedef union { unsigned long l; unsigned char b[4]; } DW;
extern DW xdata reg_ahb_read_addr;
extern DW xdata reg_ahb_write_addr;
extern DW xdata reg_ahb_write_value;
extern DW xdata startup_core_reg_addr;
extern DW xdata startup_core_reg_value;
extern DW reg_ahb_read32(void);
extern void reg_ahb_write32(void);
extern void lib_printf517(void *fmt, ...) large;

#define LEON2S_CORE_CTRL     0x9F120008  /* startup_setup_leon2s writes 0x1001 here */
#define CORE_CTRL_BIT12        0x00001000
#define CORE_CTRL_RUN_CLEAR    0x00001003  /* bits 0, 1 and 12, cleared to start the processor */

/*
 * startup_run_leon2s - start the input (Leon2S) processor: over the AHB bridge, set bit 12 of its core control register,
 * then clear bits 0, 1 and 12, and print "Leon2 (Sub) RUN...". Each step reads the register first.
 * Only caller: startup_load_core_images, after the program images are in place.
 */
void startup_run_leon2s(void)
{
    startup_core_reg_addr.l = LEON2S_CORE_CTRL;
    reg_ahb_read_addr = startup_core_reg_addr;
    startup_core_reg_value = reg_ahb_read32();
    startup_core_reg_value.l |= CORE_CTRL_BIT12;
    reg_ahb_write_addr = startup_core_reg_addr;
    reg_ahb_write_value = startup_core_reg_value;
    reg_ahb_write32();
    startup_core_reg_addr.l = LEON2S_CORE_CTRL;
    reg_ahb_read_addr = startup_core_reg_addr;
    startup_core_reg_value = reg_ahb_read32();
    startup_core_reg_value.l &= ~CORE_CTRL_RUN_CLEAR;
    reg_ahb_write_addr = startup_core_reg_addr;
    reg_ahb_write_value = startup_core_reg_value;
    reg_ahb_write32();
    lib_printf517((void code *)0x81f0);   /* "Leon2 (Sub) RUN...\r\n" */
}
