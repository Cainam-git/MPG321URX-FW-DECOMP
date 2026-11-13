/* sys_ir_ring_read_byte  (FUN_CODE_d697)
 *
 * Take the next byte from the 128-byte IR ring, 0xFF when it is empty.
 * Returns: byte or 0xFF
 * Name basis: derived - ring 0xA566; read by the IR matcher and sent as report type 5 after 'Reload IR'
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d697 @ 0xd697  Options: OPTIMIZE(8,SPEED) REGFILE(R.ORC) (also level 7 with REGFILE).
 * Source form: the result lives in R6 only with REGFILE(R.ORC) (without it Keil puts it in DATA: 57 %).
 */
#define IR_RING_SIZE  0x80  /* entries in the infrared pulse ring */
#define IR_RING_EMPTY 0xff  /* value returned when the ring holds nothing */

extern unsigned char xdata sys_ir_ring_read_index;
extern unsigned char xdata sys_ir_ring_buffer[];
unsigned char sys_ir_ring_is_empty(void);

/*
 * Take the next value out of the 128-byte infrared pulse ring: returns it and moves the read index on, wrapping
 * at 0x80. Returns 0xFF when the ring is empty.
 */
unsigned char sys_ir_ring_read_byte(void)
{
    unsigned char value;

    if (sys_ir_ring_is_empty() == 0) {
        value = sys_ir_ring_buffer[sys_ir_ring_read_index];
        sys_ir_ring_read_index++;
        if (sys_ir_ring_read_index == IR_RING_SIZE) sys_ir_ring_read_index = 0;
    } else value = IR_RING_EMPTY;
    return value;
}
