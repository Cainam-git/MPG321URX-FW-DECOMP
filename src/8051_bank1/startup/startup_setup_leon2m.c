/* startup_setup_leon2m  (FUN_CODE_4a85)
 *
 * Set the main processor's boot address and core registers before it starts.
 * Name basis: proven - boot base 0xA0028000 via the AHB bridge; prints 'Leon2 vs AHB clk is 3:1'; docs/MAP.md
 *   (code window 0x108000)
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_4a85 @ 0x4a85, OPTIMIZE(8,SPEED) LARGE (0x234 bytes: a 4-byte constant follows a library call
 * inline, so the routine runs past the first such call).
 * Source form: every write is the same three statements (copy address and value into the bridge inputs, call
 * reg_ahb_write32); the table loop steps i twice per pass, with the post-increments inside the index.
 */
typedef union { unsigned long l; unsigned char b[4]; } DW;

/* The Leon2M record of the share block (startup_share_copy +0x0C, 0x24 bytes); only the two words used here. */
struct leon2m_share_record {
    unsigned char before_0x18[0x18];
    unsigned long dataram_ones_value;   /* +0x18 (startup_share_copy +0x24) */
    unsigned long dataram_zeros_value;  /* +0x1C (startup_share_copy +0x28) */
};
extern volatile unsigned char xdata reg_chip_id;
extern DW xdata startup_core_reg_addr;
extern DW xdata startup_core_reg_value;
extern DW xdata reg_ahb_write_addr;
extern DW xdata reg_ahb_write_value;
extern void reg_ahb_write32(void);   /* parameters in its overlay: addr = 0xA4EC, val = 0xA4F0 */
extern void lib_printf517(void *fmt, ...) large;

/* CODE 0x8252: 8 (register, value) pairs, written in order:
 *   0x9F0000E0 = 5, 0x9F020000 = 0xA0028000 (the Leon2M reset slot trap_reset_entry, docs/MAP.md),
 *   0x9F020008 = 0x1001 (LEON2M_CORE_CTRL; startup_run_leon2m later clears bits 0, 1 and 12),
 *   0x9F02000C = 0x50000000, 0x9F01010C = 0x9F010110 = 0x9F010108 = 0xFFFFFFFF, 0x9F010104 = 0x72310CAD. */
#define LEON2M_CORE_REG_TABLE  ((unsigned long code *)0x8252)
#define CORE_REG_TABLE_WORDS   16
#define DATARAM_REG_ONES       0x9F020200  /* read back by the Leon2M data RAM check (startup_init_core) */
#define DATARAM_REG_ZEROS      0x9F020204  /* likewise */
#define CHIP_ID_1A             0x1A        /* reg_chip_id value */

/*
 * startup_setup_leon2m - write the main processor's core registers over the AHB bridge before it is started.
 *   record  the Leon2M record of the share block (startup_share_copy +0x0C)
 * Writes the fixed table at CODE 0x8252, then the two words of the record into DATARAM_REG_ONES and
 * DATARAM_REG_ZEROS, prints "Leon2 vs AHB clk is 3:1", writes 0x9F0000E0 = 5 and 0x9F02000C = 0x50000000 once
 * more, and on chip 0x1A also 0x9F020308 = 0x723105A5 and 0x9F020300 = 0x25. The purpose of the single
 * registers is not shown in this program.
 * Only caller: startup_load_core_images, before startup_run_leon2m starts the processor.
 */
void startup_setup_leon2m(struct leon2m_share_record *record)
{
    int i;
    for (i = 0; i < CORE_REG_TABLE_WORDS; ) {
        startup_core_reg_addr.l = LEON2M_CORE_REG_TABLE[i++];
        startup_core_reg_value.l = LEON2M_CORE_REG_TABLE[i++];
        reg_ahb_write_addr = startup_core_reg_addr; reg_ahb_write_value = startup_core_reg_value; reg_ahb_write32();
    }
    startup_core_reg_addr.l = DATARAM_REG_ONES;
    startup_core_reg_value.l = record->dataram_ones_value;
    reg_ahb_write_addr = startup_core_reg_addr; reg_ahb_write_value = startup_core_reg_value; reg_ahb_write32();
    startup_core_reg_addr.l = DATARAM_REG_ZEROS;
    startup_core_reg_value.l = record->dataram_zeros_value;
    reg_ahb_write_addr = startup_core_reg_addr; reg_ahb_write_value = startup_core_reg_value; reg_ahb_write32();
    lib_printf517((void code *)0x81d6);   /* "Leon2 vs AHB clk is 3:1\r\n" */
    startup_core_reg_addr.l = 0x9F0000E0;
    startup_core_reg_value.l = 0x00000005;
    reg_ahb_write_addr = startup_core_reg_addr; reg_ahb_write_value = startup_core_reg_value; reg_ahb_write32();
    startup_core_reg_addr.l = 0x9F02000C;
    startup_core_reg_value.l = 0x50000000;
    reg_ahb_write_addr = startup_core_reg_addr; reg_ahb_write_value = startup_core_reg_value; reg_ahb_write32();
    if (reg_chip_id == CHIP_ID_1A) {
        startup_core_reg_addr.l = 0x9F020308;
        startup_core_reg_value.l = 0x723105A5;
        reg_ahb_write_addr = startup_core_reg_addr; reg_ahb_write_value = startup_core_reg_value; reg_ahb_write32();
        startup_core_reg_addr.l = 0x9F020300;
        startup_core_reg_value.l = 0x00000025;
        reg_ahb_write_addr = startup_core_reg_addr; reg_ahb_write_value = startup_core_reg_value; reg_ahb_write32();
    }
}
