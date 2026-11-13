/* sys_publish_chip_status_code  (FUN_a01544d4)
 *
 * Set status 3 for chip revision class 8 with model code 3, else 0, and write it to a register.
 * Name basis: descriptive - tests sys_chip_revision high nibble for 8 and sys_chip_model_code for 3;
 *   sys_write_status_register writes register 0xCF03C880
 *
 * Matching notes
 * --------------
 * FUN_a01544d4 (leon2m 0xa01544d4-0xa0154574, 160 bytes), flags -mcpu=v8 -g (no optimisation level).
 * Source form: unoptimised code (the file is compiled like its neighbour irq_empty_handler_copy92); a switch with case 3 and
 * default, each arm storing the code and then writing it to the register.
 */
extern unsigned char sys_chip_revision, sys_chip_model_code;
extern unsigned int sys_link_status_code;
extern void sys_write_status_register(unsigned int);

#define CHIP_REVISION_CLASS_MASK 0xf0   /* the high four bits of sys_chip_revision */
#define CHIP_REVISION_CLASS_8    0x80
#define CHIP_MODEL_3             3

/*
 * When the high four bits of the chip revision byte are 8: store the status code 3 (chip model code 3) or 0 (any
 * other model code) in sys_link_status_code and write it to the status register (sys_write_status_register).
 * For other revisions nothing happens.
 *
 * Called by sys_refresh_status_and_signal_alive, which refreshes the input status codes and signals the 8051.
 */
void sys_publish_chip_status_code(void)
{
    if ((sys_chip_revision & CHIP_REVISION_CLASS_MASK) == CHIP_REVISION_CLASS_8) {
        switch (sys_chip_model_code) {
        case CHIP_MODEL_3:
            sys_link_status_code = 3;
            sys_write_status_register(sys_link_status_code);
            break;
        default:
            sys_link_status_code = 0;
            sys_write_status_register(sys_link_status_code);
            break;
        }
    }
}
