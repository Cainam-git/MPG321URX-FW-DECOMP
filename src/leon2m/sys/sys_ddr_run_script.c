/* sys_ddr_run_script  (FUN_a00e0e44)
 *
 * Run the memory training script: one command byte after the other.
 * Name basis: proven - 62-way command switch over the script bytes; calls every training step
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e0e44 @ 0xa00e0e44-0xa00e1f50 (1091 words), flags -mcpu=v8 -O3 -g.
 * The switch uses the jump table at 0x00080d30 for 0..61; larger values go to the default.
 * Source forms the exact build depends on:
 *  - the argument copy loops written 'pos++; args[nargs] = script[pos]; nargs++;';
 *  - the case bodies in this source order, each with its own block-scope locals in this declaration order; the
 *    nine "bad!Invalid command ID" commands as separate case bodies;
 *  - 'last_unit' at function scope; commands 48/58, 52 and 53 use the function-scope locals cmd_version ..
 *    cmd_arg7 for their argument bytes; commands 24, 25, 27, 42, 43, 48/58 and 49/57 read args[0] into
 *    unit_arg before the other argument bytes;
 *  - accesses to addresses taken from the script are volatile.
 * The script pointer and length are declared as DAT_a802d654_DDRScript / DAT_a802d658_DDRScriptLen (here reached
 * through the macros script / script_length). The registers of the two address high parts (firmware %i3 for
 * 0xa802d654 at 0xa00e0e58, %i4 for 0xa802d658 at 0xa00e0e48) follow these symbol names: GCC orders the hoisted
 * address parts by a hash of the symbol names. The original names are not in the firmware; these are
 * descriptive names in the style of the firmware's own identifiers ('DDRStress', 'pre_DDRStressCnt') that give
 * the firmware order.
 */

/* The script being run and its length in bytes, set by sys_ddr_init before the call. */
#define script          DAT_a802d654_DDRScript
#define script_length   DAT_a802d658_DDRScriptLen

/*
 * Command bytes of the script. Names follow the routine each command calls; 42 and 43 carry the firmware's own
 * names (sys_ddr_phy_adjust_field prints "phy_reg_add/sub"), 21 the name in its message "setstatus NOT support".
 * The step names in brackets are those the called routine records with sys_ddr_set_step.
 */
enum ddr_script_command {
    SCRIPT_CMD_PRINT            = 1,    /* text up to a zero byte, sent to the debug serial port */
    SCRIPT_CMD_SKIP_TEXT        = 2,    /* text up to a zero byte, skipped */
    SCRIPT_CMD_SET_PLL          = 4,
    SCRIPT_CMD_WRITE_BITS       = 5,    /* bit field of a word at an address */
    SCRIPT_CMD_DELAY            = 6,
    SCRIPT_CMD_SKIP_1           = 7,    /* one argument byte, nothing done */
    SCRIPT_CMD_WRITE_BYTE       = 8,
    SCRIPT_CMD_WRITE_WORD       = 9,
    SCRIPT_CMD_WRITE_WORD_TWICE = 10,   /* at address + 0xc0150000 and address + 0xc1150000 */
    SCRIPT_CMD_SETSTATUS        = 21,
    SCRIPT_CMD_TRAIN_REG_D5     = 22,   /* [CLK_TREE] */
    SCRIPT_CMD_PHY_UPDATE_BITS  = 24,
    SCRIPT_CMD_PHY_WRITE        = 25,
    SCRIPT_CMD_PHY_CHECK        = 27,
    SCRIPT_CMD_RESET_FIFOS      = 30,
    SCRIPT_CMD_RESET_FIFOS_2    = 31,   /* same as 30 */
    SCRIPT_CMD_UPDATE_BITS      = 32,   /* address, mask, value as three words */
    SCRIPT_CMD_SETUP_PHY        = 34,   /* [ZQK] */
    SCRIPT_CMD_READ_DESKEW      = 38,   /* [R_DESKEW] */
    SCRIPT_CMD_SKIP_2           = 41,   /* two argument bytes, nothing done */
    SCRIPT_CMD_PHY_REG_ADD      = 42,
    SCRIPT_CMD_PHY_REG_SUB      = 43,
    SCRIPT_CMD_SKIP_3           = 44,   /* three argument bytes, nothing done */
    SCRIPT_CMD_DUTY_0           = 45,   /* [DUTY] sys_ddr_calibrate_drivers with duty_idx 0 */
    SCRIPT_CMD_DUTY_1           = 46,   /*        ... duty_idx 1 */
    SCRIPT_CMD_DUTY_2           = 47,   /*        ... duty_idx 2 */
    SCRIPT_CMD_WRITE_LEVELING   = 48,   /* [WL] last two arguments passed as 0 */
    SCRIPT_CMD_QS_GATE          = 49,   /* [QSEN] last two arguments passed as 0 */
    SCRIPT_CMD_CHECK_PHY_BYTE   = 50,   /* [PSD] */
    SCRIPT_CMD_WRITE_DESKEW     = 51,   /* [W_DESKEW] */
    SCRIPT_CMD_FIND_READ_EYE    = 52,   /* [R_EYE] */
    SCRIPT_CMD_WRITE_EYE        = 53,   /* [W_EYE] */
    SCRIPT_CMD_READ_EYE         = 54,   /* [R_VREF] */
    SCRIPT_CMD_TRAIN_VREF       = 55,   /* [W_VREF] */
    SCRIPT_CMD_SET_VREF         = 56,
    SCRIPT_CMD_QS_GATE_ARGS     = 57,   /* as 49, with the last two arguments from the script */
    SCRIPT_CMD_WRITE_LEVELING_ARGS = 58, /* as 48, with the last two arguments from the script */
    SCRIPT_CMD_END              = 61
};

/* First argument byte of a per-unit command: a memory interface number, or ALL_UNITS. */
#define ALL_UNITS        0xff
#define ALL_UNITS_ENTRY  4      /* row of sys_ddr_script_unit_ranges used for ALL_UNITS */

/* First and last memory interface a command works on. Rows in FW.021: 0..0, 1..1, 2..2, 0..1, 0..2. */
struct unit_range { int first; int last; };
struct win { int a; int b; };
extern unsigned char *DAT_a802d654_DDRScript;
extern unsigned int DAT_a802d658_DDRScriptLen;
extern const struct unit_range sys_ddr_script_unit_ranges[];
extern int dbg_printf(const char *fmt, ...);
extern int uart_put_string_blocking(const char *s);
extern void uart_put_char_blocking(signed char c);
extern void sys_ddr_delay(unsigned int n);
extern void sys_ddr_set_pll(unsigned int id, int value_a, int value_b);
extern void sys_ddr_reset_fifos(unsigned char phy);
extern void sys_ddr_phy_adjust_field(int phy, unsigned int addr, unsigned int delta, unsigned int mask, unsigned int limit, int keep, unsigned int sat, int add);
extern void sys_ddr_phy_write(int phy, unsigned int addr, unsigned int val);
extern void sys_ddr_phy_update_bits(unsigned int phy, unsigned int addr, unsigned int mask, unsigned int val);
extern int sys_ddr_check_phy_reg_or_fail(int phy, unsigned int addr, unsigned int mask, unsigned int expect);
extern void reg_update_bits_at_copy(unsigned int address, unsigned int mask, unsigned int value);
extern void sys_ddr_train_clk_tree(unsigned int phy, unsigned int version, unsigned int generation);
extern int sys_ddr_calibrate_drivers(unsigned int phy, unsigned int version, unsigned int generation, unsigned int duty_idx);
extern int sys_ddr_check_phy_byte(unsigned int dev, unsigned int ofs, int byte_idx);
extern int sys_ddr_train_qs_gate(unsigned int, unsigned int, unsigned int, unsigned int, int, int, unsigned int, unsigned int);
extern int sys_ddr_train_read_deskew(unsigned int, unsigned int, unsigned int, unsigned int);
extern struct win sys_ddr_find_read_eye(unsigned int, unsigned int, unsigned int, int, unsigned int);
extern int sys_ddr_train_read_eye(unsigned int unit, unsigned int p2, unsigned int p3, int b, int pct, unsigned int p6);
extern int sys_ddr_train_write_deskew(unsigned int, unsigned int, unsigned int, unsigned int, int, unsigned int);
extern struct win sys_ddr_train_write_eye(unsigned int, unsigned int, unsigned int, int, unsigned int, unsigned int);
extern int sys_ddr_train_write_leveling(unsigned int unit, unsigned int p1, unsigned int type, int b, int p4, int p5, int p6, int p7);
extern int sys_ddr_train_vref(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern int sys_ddr_set_vref(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern int sys_ddr_setup_phy(unsigned int p, int full);

/*
 * Carry out the memory set-up script, starting at byte pos of the script. Called with pos 0 by sys_ddr_init
 * (from startup_init_display_clocks) and by its copy sys_ddr_init_select_script, after they have chosen the old
 * or the new script and set script / script_length.
 *
 * The script is a byte stream. Each command is one command byte followed by a fixed number of argument bytes
 * (commands 1 and 2: a text up to a zero byte). Multi-byte numbers in the script are big-endian.
 *
 * For each command, in order:
 *  1. read the command byte at pos and pick the case;
 *  2. copy the argument bytes into args[] (pos moves onto the last one);
 *  3. carry the command out: either once, or - for the per-unit commands - once for every memory interface of
 *     the row of sys_ddr_script_unit_ranges that argument byte 0 selects (ALL_UNITS selects ALL_UNITS_ENTRY);
 *  4. step pos onto the next command byte.
 *
 * SCRIPT_CMD_END returns. When pos reaches script_length without it, the routine never returns (it stays in
 * an endless loop). Each of the two scripts in FW.021 is 0x1429 bytes long and has SCRIPT_CMD_END as its last
 * byte.
 *
 * Per-unit commands: the argument bytes after the unit byte are passed to the routine in order. For the training
 * steps (22, 38, 45..58 except 50 and 56) the first two are the version and generation values that the step
 * passes to sys_ddr_check_arguments, the third (where present) is the data byte. Commands 24, 25 and 27 take a
 * 12-bit register number from the low nibble of byte 1 and byte 2; 42 and 43 a 16-bit one.
 * Command codes 18, 23, 28, 33, 35, 36, 37, 39 and 40 print "bad!Invalid command ID"; codes without a case
 * print "ERROR". Neither consumes argument bytes.
 */
void sys_ddr_run_script(unsigned int pos)
{
    unsigned char args[16];
    unsigned char nargs;
    unsigned int data_word;
    int i;
    int last_unit;
    unsigned int cmd_arg4, cmd_arg5, cmd_arg7, cmd_arg6, cmd_version, cmd_generation, cmd_byte;

    while (pos < script_length) {
        nargs = 0;
        /* 1. command byte */
        switch (script[pos]) {
        case SCRIPT_CMD_END:
            return;
        case SCRIPT_CMD_SET_PLL:
            /* args: id, value_a (16 bits), value_b (16 bits) */
            for (i = 0; i < 5; i++) {
                pos++;
                args[nargs] = script[pos];
                nargs++;
            }
            sys_ddr_set_pll(args[0], args[1] << 8 | args[2], args[3] << 8 | args[4]);
            break;
        case SCRIPT_CMD_DELAY:
            /* args: delay in tens of sys_ddr_delay units */
            for (i = 0; i < 1; i++) {
                pos++;
                args[nargs] = script[pos];
                nargs++;
            }
            sys_ddr_delay(args[0] * 10);
            break;
        case SCRIPT_CMD_WRITE_BYTE:
            /* args: address (32 bits), byte value */
            for (i = 0; i < 5; i++) {
                pos++;
                args[nargs] = script[pos];
                nargs++;
            }
            *(volatile unsigned char *)(args[0] << 24 | args[1] << 16 | args[2] << 8 | args[3]) = args[4];
            break;
        case 28:
            dbg_printf("bad!Invalid command ID %d!!\n", script[pos]);
            break;
        case SCRIPT_CMD_WRITE_WORD:
            /* args: address (32 bits), word value (32 bits) */
            for (i = 0; i < 8; i++) {
                pos++;
                args[nargs] = script[pos];
                nargs++;
            }
            *(volatile unsigned int *)(args[0] << 24 | args[1] << 16 | args[2] << 8 | args[3]) = args[4] << 24 | args[5] << 16 | args[6] << 8 | args[7];
            break;
        case SCRIPT_CMD_WRITE_WORD_TWICE:
            /* args: address offset (32 bits), word value (32 bits) */
            {
                unsigned int address;
                for (i = 0; i < 8; i++) {
                    pos++;
                    args[nargs] = script[pos];
                    nargs++;
                }
                address = args[0] << 24 | args[1] << 16 | args[2] << 8 | args[3];
                data_word = args[4] << 24 | args[5] << 16 | args[6] << 8 | args[7];
                *(volatile unsigned int *)(address + 0xc0150000) = data_word;
                *(volatile unsigned int *)(address + 0xc1150000) = data_word;
            }
            break;
        case SCRIPT_CMD_PHY_REG_ADD:
            /* args: unit, register (16 bits), delta, mask, limit, keep, saturate value */
            {
                unsigned int delta;
                unsigned int mask;
                unsigned int limit;
                unsigned int keep;
                unsigned int saturate;
                int range;
                unsigned int unit_arg;
                int unit;
                unsigned short addr;
                for (i = 0; i < 8; i++) {
                    pos++;
                    args[nargs] = script[pos];
                    nargs++;
                }
                unit_arg = args[0];
                addr = args[1] << 8 | args[2];
                delta = args[3];
                mask = args[4];
                limit = args[5];
                keep = args[6];
                saturate = args[7];
                if (unit_arg == ALL_UNITS)
                    range = ALL_UNITS_ENTRY;
                else
                    range = unit_arg;
                last_unit = sys_ddr_script_unit_ranges[range].last;
                for (unit = sys_ddr_script_unit_ranges[range].first; unit <= last_unit; unit++)
                    sys_ddr_phy_adjust_field(unit, addr, delta, mask, limit, keep, saturate, 1);
            }
            break;
        case SCRIPT_CMD_PHY_REG_SUB:
            /* args: as SCRIPT_CMD_PHY_REG_ADD; the field is stepped down */
            {
                unsigned int delta;
                unsigned int mask;
                unsigned int limit;
                unsigned int keep;
                unsigned int saturate;
                int range;
                unsigned int unit_arg;
                int unit;
                unsigned short addr;
                for (i = 0; i < 8; i++) {
                    pos++;
                    args[nargs] = script[pos];
                    nargs++;
                }
                unit_arg = args[0];
                addr = args[1] << 8 | args[2];
                delta = args[3];
                mask = args[4];
                limit = args[5];
                keep = args[6];
                saturate = args[7];
                if (unit_arg == ALL_UNITS)
                    range = ALL_UNITS_ENTRY;
                else
                    range = unit_arg;
                last_unit = sys_ddr_script_unit_ranges[range].last;
                for (unit = sys_ddr_script_unit_ranges[range].first; unit <= last_unit; unit++)
                    sys_ddr_phy_adjust_field(unit, addr, delta, mask, limit, keep, saturate, 0);
            }
            break;
        case 23:
            dbg_printf("bad!Invalid command ID %d!!\n", script[pos]);
            break;
        case SCRIPT_CMD_SKIP_1:
            for (i = 0; i < 1; i++) {
                pos++;
                args[nargs] = script[pos];
                nargs++;
            }
            break;
        case SCRIPT_CMD_SETSTATUS:
            /* one argument byte; the command is not carried out */
            for (i = 0; i < 1; i++) {
                pos++;
                args[nargs] = script[pos];
                nargs++;
            }
            uart_put_string_blocking("setstatus NOT support\n");
            break;
        case SCRIPT_CMD_PHY_UPDATE_BITS:
            /* args: unit, register (12 bits), mask, value */
            {
                unsigned int mask;
                int range;
                unsigned int unit_arg;
                int unit;
                unsigned int addr;
                unsigned int value;
                for (i = 0; i < 5; i++) {
                    pos++;
                    args[nargs] = script[pos];
                    nargs++;
                }
                unit_arg = args[0];
                addr = (args[1] & 0xf) << 8 | args[2];
                mask = args[3];
                value = args[4];
                if (unit_arg == ALL_UNITS)
                    range = ALL_UNITS_ENTRY;
                else
                    range = unit_arg;
                last_unit = sys_ddr_script_unit_ranges[range].last;
                for (unit = sys_ddr_script_unit_ranges[range].first; unit <= last_unit; unit++)
                    sys_ddr_phy_update_bits(unit, addr, mask, value);
            }
            break;
        case SCRIPT_CMD_PHY_WRITE:
            /* args: unit, register (12 bits), value */
            {
                unsigned int value;
                int range;
                unsigned int unit_arg;
                int unit;
                unsigned int addr;
                for (i = 0; i < 4; i++) {
                    pos++;
                    args[nargs] = script[pos];
                    nargs++;
                }
                unit_arg = args[0];
                addr = (args[1] & 0xf) << 8 | args[2];
                value = args[3];
                if (unit_arg == ALL_UNITS)
                    range = ALL_UNITS_ENTRY;
                else
                    range = unit_arg;
                last_unit = sys_ddr_script_unit_ranges[range].last;
                for (unit = sys_ddr_script_unit_ranges[range].first; unit <= last_unit; unit++)
                    sys_ddr_phy_write(unit, addr, value);
            }
            break;
        case SCRIPT_CMD_PHY_CHECK:
            /* args: unit, register (12 bits), mask, expected value; the result is not used */
            {
                unsigned int addr;
                unsigned int mask;
                unsigned int expect;
                int range;
                unsigned int unit_arg;
                int unit;
                for (i = 0; i < 5; i++) {
                    pos++;
                    args[nargs] = script[pos];
                    nargs++;
                }
                unit_arg = args[0];
                addr = (args[1] & 0xf) << 8 | args[2];
                mask = args[3];
                expect = args[4];
                if (unit_arg == ALL_UNITS)
                    range = ALL_UNITS_ENTRY;
                else
                    range = unit_arg;
                last_unit = sys_ddr_script_unit_ranges[range].last;
                for (unit = sys_ddr_script_unit_ranges[range].first; unit <= last_unit; unit++)
                    sys_ddr_check_phy_reg_or_fail(unit, addr, mask, expect);
            }
            break;
        case SCRIPT_CMD_RESET_FIFOS:
        case SCRIPT_CMD_RESET_FIFOS_2:
            /* args: unit, passed on directly (no unit loop) */
            for (i = 0; i < 1; i++) {
                pos++;
                args[nargs] = script[pos];
                nargs++;
            }
            sys_ddr_reset_fifos(args[0]);
            break;
        case SCRIPT_CMD_UPDATE_BITS:
            /* args: address, mask, value (32 bits each) */
            for (i = 0; i < 12; i++) {
                pos++;
                args[nargs] = script[pos];
                nargs++;
            }
            reg_update_bits_at_copy(args[0] << 24 | args[1] << 16 | args[2] << 8 | args[3], args[4] << 24 | args[5] << 16 | args[6] << 8 | args[7],
                         args[8] << 24 | args[9] << 16 | args[10] << 8 | args[11]);
            break;
        case SCRIPT_CMD_WRITE_BITS:
            /* args: address (32 bits), high bit, low bit, value (32 bits, shifted up to the low bit) */
            for (i = 0; i < 10; i++) {
                pos++;
                args[nargs] = script[pos];
                nargs++;
            }
            reg_update_bits_at_copy(args[0] << 24 | args[1] << 16 | args[2] << 8 | args[3], (1 << (args[4] + 1)) - (1 << args[5]),
                         (args[6] << 24 | args[7] << 16 | args[8] << 8 | args[9]) << args[5]);
            break;
        case SCRIPT_CMD_TRAIN_REG_D5:
            /* args: unit, version, generation */
            {
                unsigned int version;
                unsigned int generation;
                int range;
                int unit;
                for (i = 0; i < 3; i++) {
                    pos++;
                    args[nargs] = script[pos];
                    nargs++;
                }
                version = args[1];
                generation = args[2];
                if (args[0] == ALL_UNITS)
                    range = ALL_UNITS_ENTRY;
                else
                    range = args[0];
                last_unit = sys_ddr_script_unit_ranges[range].last;
                for (unit = sys_ddr_script_unit_ranges[range].first; unit <= last_unit; unit++)
                    sys_ddr_train_clk_tree(unit, version, generation);
            }
            break;
        case SCRIPT_CMD_DUTY_0:
            /* args: unit, version, generation */
            {
                unsigned int version;
                unsigned int generation;
                int range;
                int unit;
                for (i = 0; i < 3; i++) {
                    pos++;
                    args[nargs] = script[pos];
                    nargs++;
                }
                version = args[1];
                generation = args[2];
                if (args[0] == ALL_UNITS)
                    range = ALL_UNITS_ENTRY;
                else
                    range = args[0];
                last_unit = sys_ddr_script_unit_ranges[range].last;
                for (unit = sys_ddr_script_unit_ranges[range].first; unit <= last_unit; unit++)
                    sys_ddr_calibrate_drivers(unit, version, generation, 0);
            }
            break;
        case SCRIPT_CMD_DUTY_1:
            /* args: unit, version, generation */
            {
                unsigned int version;
                unsigned int generation;
                int range;
                int unit;
                for (i = 0; i < 3; i++) {
                    pos++;
                    args[nargs] = script[pos];
                    nargs++;
                }
                version = args[1];
                generation = args[2];
                if (args[0] == ALL_UNITS)
                    range = ALL_UNITS_ENTRY;
                else
                    range = args[0];
                last_unit = sys_ddr_script_unit_ranges[range].last;
                for (unit = sys_ddr_script_unit_ranges[range].first; unit <= last_unit; unit++)
                    sys_ddr_calibrate_drivers(unit, version, generation, 1);
            }
            break;
        case 36:
            dbg_printf("bad!Invalid command ID %d!!\n", script[pos]);
            break;
        case 18:
            dbg_printf("bad!Invalid command ID %d!!\n", script[pos]);
            break;
        case SCRIPT_CMD_DUTY_2:
            /* args: unit, version, generation */
            {
                unsigned int version;
                unsigned int generation;
                int range;
                int unit;
                for (i = 0; i < 3; i++) {
                    pos++;
                    args[nargs] = script[pos];
                    nargs++;
                }
                version = args[1];
                generation = args[2];
                if (args[0] == ALL_UNITS)
                    range = ALL_UNITS_ENTRY;
                else
                    range = args[0];
                last_unit = sys_ddr_script_unit_ranges[range].last;
                for (unit = sys_ddr_script_unit_ranges[range].first; unit <= last_unit; unit++)
                    sys_ddr_calibrate_drivers(unit, version, generation, 2);
            }
            break;
        case SCRIPT_CMD_CHECK_PHY_BYTE:
            /* args: unit, offset (subtracted from the value copied to register 0x161 + byte), data byte */
            {
                unsigned int offset;
                unsigned int byte;
                int range;
                int unit;
                for (i = 0; i < 3; i++) {
                    pos++;
                    args[nargs] = script[pos];
                    nargs++;
                }
                offset = args[1];
                byte = args[2];
                if (args[0] == ALL_UNITS)
                    range = ALL_UNITS_ENTRY;
                else
                    range = args[0];
                last_unit = sys_ddr_script_unit_ranges[range].last;
                for (unit = sys_ddr_script_unit_ranges[range].first; unit <= last_unit; unit++)
                    sys_ddr_check_phy_byte(unit, offset, byte);
            }
            break;
        case 33:
            dbg_printf("bad!Invalid command ID %d!!\n", script[pos]);
            break;
        case SCRIPT_CMD_WRITE_DESKEW:
            /* args: unit, version, generation, data byte, arg4 (the routine's last parameter; 4 is passed
             * before it) */
            {
                unsigned int arg4;
                unsigned int version;
                unsigned int generation;
                unsigned int byte;
                int range;
                int unit;
                for (i = 0; i < 5; i++) {
                    pos++;
                    args[nargs] = script[pos];
                    nargs++;
                }
                version = args[1];
                generation = args[2];
                byte = args[3];
                arg4 = args[4];
                if (args[0] == ALL_UNITS)
                    range = ALL_UNITS_ENTRY;
                else
                    range = args[0];
                last_unit = sys_ddr_script_unit_ranges[range].last;
                for (unit = sys_ddr_script_unit_ranges[range].first; unit <= last_unit; unit++)
                    sys_ddr_train_write_deskew(unit, version, generation, byte, 4, arg4);
            }
            break;
        case SCRIPT_CMD_READ_DESKEW:
            /* args: unit, version, generation, data byte */
            {
                unsigned int version;
                unsigned int generation;
                unsigned int byte;
                int range;
                int unit;
                for (i = 0; i < 4; i++) {
                    pos++;
                    args[nargs] = script[pos];
                    nargs++;
                }
                version = args[1];
                generation = args[2];
                byte = args[3];
                if (args[0] == ALL_UNITS)
                    range = ALL_UNITS_ENTRY;
                else
                    range = args[0];
                last_unit = sys_ddr_script_unit_ranges[range].last;
                for (unit = sys_ddr_script_unit_ranges[range].first; unit <= last_unit; unit++)
                    sys_ddr_train_read_deskew(unit, version, generation, byte);
            }
            break;
        case 40:
            dbg_printf("bad!Invalid command ID %d!!\n", script[pos]);
            break;
        case 39:
            dbg_printf("bad!Invalid command ID %d!!\n", script[pos]);
            break;
        case SCRIPT_CMD_QS_GATE:
        case SCRIPT_CMD_QS_GATE_ARGS:
            /* args: unit, version, generation, data byte, offset_down, final_offset (the last two used by
             * SCRIPT_CMD_QS_GATE_ARGS only); sweep and sweep_to_end are passed as 0 */
            {
                unsigned char command;
                unsigned int offset_down;
                unsigned int final_offset;
                unsigned int version;
                unsigned int generation;
                unsigned int byte;
                int range;
                unsigned int unit_arg;
                int unit;
                command = script[pos];
                for (i = 0; i < 6; i++) {
                    pos++;
                    args[nargs] = script[pos];
                    nargs++;
                }
                unit_arg = args[0];
                version = args[1];
                generation = args[2];
                byte = args[3];
                offset_down = 0;
                final_offset = 0;
                if (command == SCRIPT_CMD_QS_GATE_ARGS) {
                    offset_down = args[4];
                    final_offset = args[5];
                }
                if (unit_arg == ALL_UNITS)
                    range = ALL_UNITS_ENTRY;
                else
                    range = unit_arg;
                last_unit = sys_ddr_script_unit_ranges[range].last;
                for (unit = sys_ddr_script_unit_ranges[range].first; unit <= last_unit; unit++)
                    sys_ddr_train_qs_gate(unit, version, generation, byte, 0, 0, offset_down, final_offset);
            }
            break;
        case SCRIPT_CMD_SETUP_PHY:
            /* args: unit; full set-up (second parameter 1) */
            {
                int range;
                int unit;
                for (i = 0; i < 1; i++) {
                    pos++;
                    args[nargs] = script[pos];
                    nargs++;
                }
                if (args[0] == ALL_UNITS)
                    range = ALL_UNITS_ENTRY;
                else
                    range = args[0];
                last_unit = sys_ddr_script_unit_ranges[range].last;
                for (unit = sys_ddr_script_unit_ranges[range].first; unit <= last_unit; unit++)
                    sys_ddr_setup_phy(unit, 1);
            }
            break;
        case SCRIPT_CMD_WRITE_LEVELING:
        case SCRIPT_CMD_WRITE_LEVELING_ARGS:
            /* args: unit, version, generation, data byte, arg4, arg5, arg6, arg7 (arg6 and arg7 used by
             * SCRIPT_CMD_WRITE_LEVELING_ARGS only) */
            {
                unsigned char command;
                int range;
                unsigned int unit_arg;
                int unit;
                command = script[pos];
                for (i = 0; i < 8; i++) {
                    pos++;
                    args[nargs] = script[pos];
                    nargs++;
                }
                unit_arg = args[0];
                cmd_version = args[1];
                cmd_generation = args[2];
                cmd_byte = args[3];
                cmd_arg4 = args[4];
                cmd_arg5 = args[5];
                cmd_arg6 = 0;
                cmd_arg7 = 0;
                if (command == SCRIPT_CMD_WRITE_LEVELING_ARGS) {
                    cmd_arg6 = args[6];
                    cmd_arg7 = args[7];
                }
                if (unit_arg == ALL_UNITS)
                    range = ALL_UNITS_ENTRY;
                else
                    range = unit_arg;
                last_unit = sys_ddr_script_unit_ranges[range].last;
                for (unit = sys_ddr_script_unit_ranges[range].first; unit <= last_unit; unit++)
                    sys_ddr_train_write_leveling(unit, cmd_version, cmd_generation, cmd_byte, cmd_arg4, cmd_arg5, cmd_arg6, cmd_arg7);
            }
            break;
        case SCRIPT_CMD_WRITE_EYE:
            /* args: unit, version, generation, data byte, arg4, arg5 (passed in the order arg5, arg4) */
            {
                int range;
                int unit;
                for (i = 0; i < 6; i++) {
                    pos++;
                    args[nargs] = script[pos];
                    nargs++;
                }
                cmd_version = args[1];
                cmd_generation = args[2];
                cmd_byte = args[3];
                cmd_arg4 = args[4];
                cmd_arg5 = args[5];
                if (args[0] == ALL_UNITS)
                    range = ALL_UNITS_ENTRY;
                else
                    range = args[0];
                last_unit = sys_ddr_script_unit_ranges[range].last;
                for (unit = sys_ddr_script_unit_ranges[range].first; unit <= last_unit; unit++)
                    sys_ddr_train_write_eye(unit, cmd_version, cmd_generation, cmd_byte, cmd_arg5, cmd_arg4);
            }
            break;
        case SCRIPT_CMD_FIND_READ_EYE:
            /* args: unit, version, generation, data byte, arg4 */
            {
                int range;
                int unit;
                for (i = 0; i < 5; i++) {
                    pos++;
                    args[nargs] = script[pos];
                    nargs++;
                }
                cmd_version = args[1];
                cmd_generation = args[2];
                cmd_byte = args[3];
                cmd_arg4 = args[4];
                if (args[0] == ALL_UNITS)
                    range = ALL_UNITS_ENTRY;
                else
                    range = args[0];
                last_unit = sys_ddr_script_unit_ranges[range].last;
                for (unit = sys_ddr_script_unit_ranges[range].first; unit <= last_unit; unit++)
                    sys_ddr_find_read_eye(unit, cmd_version, cmd_generation, cmd_byte, cmd_arg4);
            }
            break;
        case 35:
            dbg_printf("bad!Invalid command ID %d!!\n", script[pos]);
            break;
        case 37:
            dbg_printf("bad!Invalid command ID %d!!\n", script[pos]);
            break;
        case SCRIPT_CMD_READ_EYE:
            /* args: unit, version, generation, data byte, arg4, pct (passed in the order pct, arg4) */
            {
                unsigned int pct;
                unsigned int version;
                unsigned int generation;
                unsigned int byte;
                unsigned int arg4;
                int range;
                int unit;
                for (i = 0; i < 6; i++) {
                    pos++;
                    args[nargs] = script[pos];
                    nargs++;
                }
                version = args[1];
                generation = args[2];
                byte = args[3];
                arg4 = args[4];
                pct = args[5];
                if (args[0] == ALL_UNITS)
                    range = ALL_UNITS_ENTRY;
                else
                    range = args[0];
                last_unit = sys_ddr_script_unit_ranges[range].last;
                for (unit = sys_ddr_script_unit_ranges[range].first; unit <= last_unit; unit++)
                    sys_ddr_train_read_eye(unit, version, generation, byte, pct, arg4);
            }
            break;
        case SCRIPT_CMD_TRAIN_VREF:
            /* args: unit, version, generation, data byte, arg4 .. arg7 */
            {
                unsigned int arg6;
                unsigned int arg7;
                unsigned int version;
                unsigned int generation;
                unsigned int byte;
                unsigned int arg4;
                unsigned int arg5;
                int range;
                int unit;
                for (i = 0; i < 8; i++) {
                    pos++;
                    args[nargs] = script[pos];
                    nargs++;
                }
                version = args[1];
                generation = args[2];
                byte = args[3];
                arg4 = args[4];
                arg5 = args[5];
                arg6 = args[6];
                arg7 = args[7];
                if (args[0] == ALL_UNITS)
                    range = ALL_UNITS_ENTRY;
                else
                    range = args[0];
                last_unit = sys_ddr_script_unit_ranges[range].last;
                for (unit = sys_ddr_script_unit_ranges[range].first; unit <= last_unit; unit++)
                    sys_ddr_train_vref(unit, version, generation, byte, arg4, arg5, arg6, arg7);
            }
            break;
        case SCRIPT_CMD_SET_VREF:
            /* args: unit, three bytes the routine does not use, speed, up, step */
            {
                unsigned int step;
                unsigned int arg1;
                unsigned int arg2;
                unsigned int arg3;
                unsigned int speed;
                unsigned int up;
                int range;
                int unit;
                for (i = 0; i < 7; i++) {
                    pos++;
                    args[nargs] = script[pos];
                    nargs++;
                }
                arg1 = args[1];
                arg2 = args[2];
                arg3 = args[3];
                speed = args[4];
                up = args[5];
                step = args[6];
                if (args[0] == ALL_UNITS)
                    range = ALL_UNITS_ENTRY;
                else
                    range = args[0];
                last_unit = sys_ddr_script_unit_ranges[range].last;
                for (unit = sys_ddr_script_unit_ranges[range].first; unit <= last_unit; unit++)
                    sys_ddr_set_vref(unit, arg1, arg2, arg3, speed, up, step);
            }
            break;
        case SCRIPT_CMD_SKIP_2:
            for (i = 0; i < 2; i++) {
                pos++;
                args[nargs] = script[pos];
                nargs++;
            }
            break;
        case SCRIPT_CMD_SKIP_3:
            for (i = 0; i < 3; i++) {
                pos++;
                args[nargs] = script[pos];
                nargs++;
            }
            break;
        case SCRIPT_CMD_PRINT:
            /* send the text byte by byte; pos ends on its zero byte */
            for (;;) {
                if (script[++pos] == 0)
                    break;
                uart_put_char_blocking(script[pos]);
            }
            dbg_printf("\n");
            break;
        case SCRIPT_CMD_SKIP_TEXT:
            while (script[++pos] != 0)
                ;
            break;
        default:
            uart_put_string_blocking("ERROR\n");
            break;
        }
        /* 4. next command byte */
        pos++;
    }
    /* The script ran out without SCRIPT_CMD_END. */
    for (;;)
        ;
}
