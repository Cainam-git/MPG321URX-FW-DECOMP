/* sys_ddr_train_write_leveling  (FUN_a00ed70c)
 *
 * Run the write levelling of one data byte of a memory interface.
 * Note: A wrong MR1 bit 0 returns -1 without the clean-up: register 0x149 stays 0xFF and bit 1 of 0x8E and bit
 *   7 of 0x281 stay set.
 * Name basis: proven - prints 'Error: DDR3 MR1 Bit0 is not 0.' / 'Error: DDR4 MR1 Bit0 is not 1.' and the WL
 *   message
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ed70c @ 0xa00ed70c-0xa00edc70 (345 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - each read and write is its own 'if (byte == -1) ... else ...' statement (as in sys_ddr_train_read_eye);
 *  - two zero-initialised int[2][2] arrays (state, flags; store order of the clears);
 *  - in the state-1 arm the value != 0 block ends with 'goto next_round' over the
 *    sys_ddr_set_write_level_fields call to the found test (no else; delay slot of the value == 0 branch at
 *    0xa00ed924 filled from the shared call block).
 */
extern int sys_ddr_phy_read(unsigned int, unsigned int);
extern void sys_ddr_set_step(unsigned int, unsigned int, unsigned int);
extern int sys_ddr_check_arguments(unsigned int, unsigned int, unsigned int);
extern void sys_ddr_print_step(void);
extern void sys_ddr_print_error_prefix(void);
extern int dbg_printf(const char *fmt, ...);
extern unsigned int sys_ddr_phy_read_field(unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_phy_write_field(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern int sys_ddr_set_write_level_fields(unsigned int, int, unsigned char);
extern unsigned int sys_ddr_read_reg17_word(unsigned int);
extern void sys_ddr_send_mode_register(unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_phy_update_bits(unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_phy_write(unsigned int, unsigned int, unsigned int);
extern void sys_ddr_reset_fifos(unsigned int);
extern void sys_ddr_print_info_prefix(void);
/* Each field is entry `byte` of three tables (register, mask, shift). Write-levelling field 1 is the value read
   back each round; write-levelling field 2 is set to 1 at the start. Field 5 is the field
   sys_ddr_set_write_level_fields writes the step into; fields 4 and 3 are set from it at the end. */
extern unsigned int sys_ddr_write_leveling_field2_regs[], sys_ddr_write_leveling_field2_masks[], sys_ddr_write_leveling_field2_shifts[];
extern unsigned int sys_ddr_write_leveling_field1_regs[], sys_ddr_write_leveling_field1_masks[], sys_ddr_write_leveling_field1_shifts[];
extern unsigned int sys_ddr_write_delay_field5_regs[], sys_ddr_write_delay_field5_masks[], sys_ddr_write_delay_field5_shifts[];
extern unsigned int sys_ddr_write_delay_field4_regs[], sys_ddr_write_delay_field4_masks[], sys_ddr_write_delay_field4_shifts[];
extern unsigned int sys_ddr_write_delay_field3_regs[], sys_ddr_write_delay_field3_masks[], sys_ddr_write_delay_field3_shifts[];

#define DDR_STEP_WL 5               /* training step number, printed as WL by sys_ddr_print_step */
#define DDR3 3                      /* ddr_generation values */
#define DDR4 4

/* Memory interface registers used here; their purpose is not shown. */
#define REG_149 0x149               /* saved, set to 0xFF, cleared at the end and then restored */
#define REG_281 0x281               /* bit 7 set at the start */
#define REG_8E  0x8e                /* bit 1 set for the duration; bit 0 pulsed once per round */

#define MR1_BIT0      1             /* bit 0 of the value read from registers 0x17 / 0x18 ("MR1 Bit0") */
#define MR_BIT7       0x80          /* set in that value while the rounds run, cleared afterwards */
#define START_STEP    6             /* step written before the rounds and after a search without result */
#define FIRST_STEP    7             /* round n writes step n + 7 */
#define ROUNDS        16
#define FIELD3_OFFSET 4             /* field 3 = field 4 - 4 */

/* state[0][byte]: where the search stands. */
enum { WAIT_FOR_ZERO = 0, WAIT_FOR_ONE = 1, FOUND = 2 };

/*
 * Write levelling of one data byte of one memory interface (training step WL).
 *
 *   unit             memory interface number
 *   phy_version      with ddr_generation, checked by sys_ddr_check_arguments
 *   ddr_generation   3 or 4; selects the expected bit 0 of the "MR1" value
 *   byte             data byte; with -1 the tables' own addresses are passed in place of an entry
 *   round_limit      a result found in a round above it sets flags[0][byte], which nothing reads
 *   field4_offset    field 4 is set to field 5 + field4_offset at the end (field 3 to that minus 4)
 *   offset_negative  non-zero: level_offset is subtracted instead of added
 *   level_offset     added to the step found (0: nothing changed)
 *
 * Returns 0, or -1 when bit 0 of the "MR1" value is wrong (after printing the step and an error message).
 * Called by the memory script (sys_ddr_run_script): command WRITE_LEVELING passes its arguments 4 and 5 with
 * offset_negative and level_offset 0, command WRITE_LEVELING_ARGS passes arguments 4 to 7.
 *
 * Phases:
 *   0. Save register 0x149, record the step, check the arguments.
 *   1. Set write-levelling field 2 to 1, the step to 6, bit 7 of register 0x281, register 0x149 to 0xFF and bit 1
 *      of register 0x8E.
 *   2. Check bit 0 of the value of registers 0x17 / 0x18, which the messages call MR1: it must be 1 for DDR4 and
 *      0 for DDR3. A wrong bit returns -1 at once, without the clean-up of phase 6.
 *   3. Send that value with bit 7 set (sys_ddr_send_mode_register(unit, 6, 1, ...)).
 *   4. Up to 16 rounds: pulse bit 0 of register 0x8E and read write-levelling field 1. The search first waits for
 *      the field to read 0, then for it to read non-zero; that round ends the search and leaves the step where it
 *      is. Every other round writes step round + 7 (sys_ddr_set_write_level_fields keeps the low 4 bits).
 *      Without a result the step goes back to 6 and "WL phy%d wr_msg_b%d=1" is printed.
 *   5. Add level_offset to the step (field 5) when it is not 0; field 4 = field 5 + field4_offset, field 3 =
 *      field 4 - 4.
 *   6. Send the "MR1" value again with bit 7 clear, clear register 0x149 and bit 1 of register 0x8E, reset the
 *      FIFOs (sys_ddr_reset_fifos) and put the saved register 0x149 back.
 * The state and flag arrays are local 2 x 2 arrays used through [0][byte] only.
 */

int sys_ddr_train_write_leveling(unsigned int unit, unsigned int phy_version, unsigned int ddr_generation, int byte, int round_limit, int field4_offset, int offset_negative, int level_offset)
{
    int state[2][2] = {{0}};
    int flags[2][2] = {{0}};
    int saved_reg149, round_index, found, status;
    unsigned int value;

    /* Phase 0. */
    saved_reg149 = sys_ddr_phy_read(unit, REG_149);
    sys_ddr_set_step(DDR_STEP_WL, unit, byte);
    sys_ddr_check_arguments(unit, phy_version, ddr_generation);
    /* Phase 1: set-up. */
    if (byte == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_leveling_field2_regs, (unsigned int)sys_ddr_write_leveling_field2_masks, (unsigned int)sys_ddr_write_leveling_field2_shifts, 1);
    else
        sys_ddr_phy_write_field(unit, sys_ddr_write_leveling_field2_regs[byte], sys_ddr_write_leveling_field2_masks[byte], sys_ddr_write_leveling_field2_shifts[byte], 1);
    sys_ddr_set_write_level_fields(unit, byte, START_STEP);
    sys_ddr_phy_write_field(unit, REG_281, 0x80, 7, 1);
    sys_ddr_phy_update_bits(unit, REG_149, 0xff, 0xff);
    sys_ddr_phy_write_field(unit, REG_8E, 2, 1, 1);
    /* Phase 2: the "MR1" bit 0 check. */
    if (ddr_generation == DDR4) {
        if (!(sys_ddr_read_reg17_word(unit) & MR1_BIT0)) {
            sys_ddr_print_step();
            sys_ddr_print_error_prefix();
            dbg_printf("Error: DDR4 MR1 Bit0 is not 1.\n");
            return -1;
        }
    } else if (ddr_generation == DDR3) {
        if (sys_ddr_read_reg17_word(unit) & MR1_BIT0) {
            sys_ddr_print_step();
            sys_ddr_print_error_prefix();
            dbg_printf("Error: DDR3 MR1 Bit0 is not 0.\n");
            return -1;
        }
    }
    /* Phase 3. */
    sys_ddr_send_mode_register(unit, 6, 1, sys_ddr_read_reg17_word(unit) | MR_BIT7);
    /* Phase 4: the rounds. */
    found = 0;
    for (round_index = 0; round_index <= ROUNDS - 1; round_index++) {
        sys_ddr_phy_write_field(unit, REG_8E, 1, 0, 1);
        sys_ddr_phy_write_field(unit, REG_8E, 1, 0, 0);
        if (state[0][byte] == WAIT_FOR_ZERO) {
            if (byte == -1)
                value = sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_write_leveling_field1_regs, (unsigned int)sys_ddr_write_leveling_field1_masks, (unsigned int)sys_ddr_write_leveling_field1_shifts);
            else
                value = sys_ddr_phy_read_field(unit, sys_ddr_write_leveling_field1_regs[byte], sys_ddr_write_leveling_field1_masks[byte], sys_ddr_write_leveling_field1_shifts[byte]);
            if (value == 0)
                state[0][byte]++;
            sys_ddr_set_write_level_fields(unit, byte, round_index + FIRST_STEP);
        } else if (state[0][byte] == WAIT_FOR_ONE) {
            if (byte == -1)
                value = sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_write_leveling_field1_regs, (unsigned int)sys_ddr_write_leveling_field1_masks, (unsigned int)sys_ddr_write_leveling_field1_shifts);
            else
                value = sys_ddr_phy_read_field(unit, sys_ddr_write_leveling_field1_regs[byte], sys_ddr_write_leveling_field1_masks[byte], sys_ddr_write_leveling_field1_shifts[byte]);
            if (value != 0) {
                /* Found: the step stays where it is. */
                state[0][byte]++;
                found++;
                if (round_index > round_limit)
                    flags[0][byte] = 1;
                goto next_round;
            }
            sys_ddr_set_write_level_fields(unit, byte, round_index + FIRST_STEP);
        }
    next_round:
        if (found == 1)
            goto apply_offsets;
    }
    if (state[0][byte] <= WAIT_FOR_ONE) {
        /* No result in 16 rounds. */
        sys_ddr_set_write_level_fields(unit, byte, START_STEP);
        flags[0][byte]++;
        sys_ddr_print_info_prefix();
        dbg_printf("WL phy%d wr_msg_b%d=1\n", unit, byte);
    }
apply_offsets:
    /* Phase 5: offsets. */
    if (level_offset != 0) {
        if (offset_negative != 0)
            level_offset = -level_offset;
        if (byte == -1)
            value = sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_write_delay_field5_regs, (unsigned int)sys_ddr_write_delay_field5_masks, (unsigned int)sys_ddr_write_delay_field5_shifts);
        else
            value = sys_ddr_phy_read_field(unit, sys_ddr_write_delay_field5_regs[byte], sys_ddr_write_delay_field5_masks[byte], sys_ddr_write_delay_field5_shifts[byte]);
        status = sys_ddr_set_write_level_fields(unit, byte, value + level_offset);
        if (status != 0)
            return status;
    }
    if (byte == -1)
        value = sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_write_delay_field5_regs, (unsigned int)sys_ddr_write_delay_field5_masks, (unsigned int)sys_ddr_write_delay_field5_shifts);
    else
        value = sys_ddr_phy_read_field(unit, sys_ddr_write_delay_field5_regs[byte], sys_ddr_write_delay_field5_masks[byte], sys_ddr_write_delay_field5_shifts[byte]);
    if (byte == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field4_regs, (unsigned int)sys_ddr_write_delay_field4_masks, (unsigned int)sys_ddr_write_delay_field4_shifts, value + field4_offset);
    else
        sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field4_regs[byte], sys_ddr_write_delay_field4_masks[byte], sys_ddr_write_delay_field4_shifts[byte], value + field4_offset);
    if (byte == -1)
        value = sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_write_delay_field4_regs, (unsigned int)sys_ddr_write_delay_field4_masks, (unsigned int)sys_ddr_write_delay_field4_shifts);
    else
        value = sys_ddr_phy_read_field(unit, sys_ddr_write_delay_field4_regs[byte], sys_ddr_write_delay_field4_masks[byte], sys_ddr_write_delay_field4_shifts[byte]);
    if (byte == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field3_regs, (unsigned int)sys_ddr_write_delay_field3_masks, (unsigned int)sys_ddr_write_delay_field3_shifts, value - FIELD3_OFFSET);
    else
        sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field3_regs[byte], sys_ddr_write_delay_field3_masks[byte], sys_ddr_write_delay_field3_shifts[byte], value - FIELD3_OFFSET);
    /* Phase 6: clean-up. */
    sys_ddr_send_mode_register(unit, 6, 1, sys_ddr_read_reg17_word(unit) & 0xfff7f);
    sys_ddr_phy_write(unit, REG_149, 0);
    sys_ddr_phy_write_field(unit, REG_8E, 2, 1, 0);
    sys_ddr_reset_fifos(unit);
    sys_ddr_phy_write(unit, REG_149, saved_reg149);
    return 0;
}
