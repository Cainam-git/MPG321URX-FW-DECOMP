/* input_blocks_init  (FUN_a01218c8)
 *
 * Set up block 8 and the eight input blocks and register their interrupt handler.
 * Name basis: proven - irq_set_source_handler and irq_unmask_sources; called from System_Initialize
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01218c8 @ 0xa01218c8-0xa0121b50 (162 words), flags -mcpu=v8 -O3 -g.
 * Source form: setup_bits is an unsigned char that is reused as the counter of the second loop (so GCC does not
 * fold (setup_bits & 0x1e) | 0x20); the first loop's counter is set to 0 before the record test.
 */

/* Block number that makes the register helpers address all eight input blocks at once. */
#define ALL_INPUT_BLOCKS 8

/* One record per input block at input_block_configs (12 bytes). */
struct input_block_config { unsigned int word_0, word_4, word_8; };
extern struct input_block_config input_block_configs[];
extern void input_capture_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern void input_measure_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern void input_measure_update_bits(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);
extern void input_block_power(unsigned char ch, unsigned char on);
extern void irq_set_source_handler(int, int, void (*)(void));
extern void irq_unmask_sources(int, int);
extern void sys_latch_unit_event_ch0(void);
extern void sys_latch_unit_event_ch1(void);
extern void sys_latch_unit_event_ch2(void);
extern void sys_latch_unit_event_ch3(void);
extern void sys_latch_unit_event_ch4(void);
extern void sys_latch_unit_event_ch6(void);
extern void sys_latch_unit_event_ch7(void);

#define R(a) (*(volatile unsigned int *)(a))

/*
 * Set the capture and measurement registers of the eight input blocks to their start values, switch the
 * blocks off and install the interrupt handlers of the blocks. No parameters, no result.
 *
 * Order: first the registers common to all blocks (written with block number 8, which the register helpers
 * take as "all eight"), then the per-block registers 0x29 and 0x1b, then more common registers, then every block
 * is switched off with input_block_power(block, 0), and last the handlers are installed. The per-block value
 * depends on word 4 of the block's input_block_configs record: if it is 1, register 0x29 gets (setup_bits | 4),
 * otherwise (setup_bits & 0xe0). setup_bits itself is 0x20 when record 0 has word 4 equal to 1, else 4.
 *
 * Interrupt group 5: sources 1, 2, 4 and 8 get the event latch routines of units 0..3, sources 0x4000, 0x1000
 * and 0x2000 those of units 4, 6 and 7. The sources 0xf, 0x1000, 0x2000 and 0x4000 are then unmasked.
 * Called by System_Initialize.
 */
void input_blocks_init(void)
{
    unsigned char block;
    unsigned char setup_bits;

    /* Registers common to all blocks. */
    input_capture_write8(ALL_INPUT_BLOCKS, 0x54, 0x24);
    input_capture_write8(ALL_INPUT_BLOCKS, 0x55, 0xc0);
    input_capture_write8(ALL_INPUT_BLOCKS, 0x56, 0x42);
    input_measure_write8(ALL_INPUT_BLOCKS, 0x16, 0x80);
    input_measure_write8(ALL_INPUT_BLOCKS, 0x17, 0x1f);
    input_measure_write8(ALL_INPUT_BLOCKS, 0x1a, 4);
    setup_bits = 4;
    block = 0;
    if (input_block_configs[0].word_4 == 1)
        setup_bits = 0x20;
    /* Registers 0x29 and 0x1b of each block; 0x29 depends on the block's own config word 4. */
    for (; block <= 7; block++) {
        if (input_block_configs[block].word_4 == 1)
            input_measure_write8(block, 0x29, setup_bits | 4);
        else
            input_measure_write8(block, 0x29, setup_bits & 0xe0);
        input_measure_write8(block, 0x1b, (setup_bits & 0x1e) | 0x20);
    }
    input_measure_write8(ALL_INPUT_BLOCKS, 0x18, 0x13);
    input_measure_write8(ALL_INPUT_BLOCKS, 0x19, 0x42);
    input_measure_write8(ALL_INPUT_BLOCKS, 0x1c, 0);
    input_measure_write8(ALL_INPUT_BLOCKS, 0x1d, 0);
    input_measure_write8(ALL_INPUT_BLOCKS, 0x1e, 0x3f);
    input_measure_write8(ALL_INPUT_BLOCKS, 0x1f, 0x1f);
    input_measure_write8(ALL_INPUT_BLOCKS, 0x10, 0xc5);
    input_measure_update_bits(ALL_INPUT_BLOCKS, 0x2e, 5, 1);
    input_capture_write8(ALL_INPUT_BLOCKS, 0x5b, 0x4a);
    input_capture_write8(ALL_INPUT_BLOCKS, 0x5c, 2);
    /* All blocks start switched off (setup_bits is the loop counter from here on). */
    for (setup_bits = 0; setup_bits <= 7; setup_bits++)
        input_block_power(setup_bits, 0);
    R(0xcf011408) = 0;
    irq_set_source_handler(5, 1, sys_latch_unit_event_ch0);
    irq_set_source_handler(5, 2, sys_latch_unit_event_ch1);
    irq_set_source_handler(5, 4, sys_latch_unit_event_ch2);
    irq_set_source_handler(5, 8, sys_latch_unit_event_ch3);
    irq_set_source_handler(5, 0x4000, sys_latch_unit_event_ch4);
    irq_set_source_handler(5, 0x1000, sys_latch_unit_event_ch6);
    irq_set_source_handler(5, 0x2000, sys_latch_unit_event_ch7);
    irq_unmask_sources(5, 0xf);
    irq_unmask_sources(5, 0x1000);
    irq_unmask_sources(5, 0x2000);
    irq_unmask_sources(5, 0x4000);
}
