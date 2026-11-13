/* startup_setup_leon2s  (FUN_CODE_5dcb)
 *
 * Set the input processor's boot address and core registers before it starts.
 * Name basis: proven - boot base 0xA0060000 via the AHB bridge; twin of startup_setup_leon2m
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_5dcb @ 0x5dcb, OPTIMIZE(8,SPEED) LARGE.
 * Source form: as startup_setup_leon2m (three statements per write, i stepped twice per loop pass).
 */
typedef union { unsigned long l; unsigned char b[4]; } DW;

/* The Leon2S record of the share block (startup_share_copy +0x30, 0x28 bytes); only the two words used here. */
struct leon2s_share_record {
    unsigned char before_0x1c[0x1c];
    unsigned long reg_0200_value;  /* +0x1C (startup_share_copy +0x4C) */
    unsigned long reg_0204_value;  /* +0x20 (startup_share_copy +0x50) */
};
extern DW xdata startup_core_reg_addr;
extern DW xdata startup_core_reg_value;
extern DW xdata reg_ahb_write_addr;
extern DW xdata reg_ahb_write_value;
extern void reg_ahb_write32(void);   /* parameters in its overlay: addr = 0xA4EC, val = 0xA4F0 */

/* CODE 0x8292: 8 (register, value) pairs, written in order:
 *   0x9F1000E0 = 5, 0x9F120000 = 0xA0060000 (where the first Leon2S part runs, docs/MAP.md),
 *   0x9F120008 = 0x1001 (LEON2S_CORE_CTRL; startup_run_leon2s later clears bits 0, 1 and 12),
 *   0x9F12000C = 0x50000000, 0x9F120210 = 0x9F120214 = 0xFFFFFFFF, 0x9F120218 = 0x8000000F,
 *   0x9F010104 = 0x72310CAD. */
#define LEON2S_CORE_REG_TABLE  ((unsigned long code *)0x8292)
#define CORE_REG_TABLE_WORDS   16
#define LEON2S_CORE_REG_0200   0x9F120200
#define LEON2S_CORE_REG_0204   0x9F120204

/*
 * startup_setup_leon2s - write the input processor's core registers over the AHB bridge before it is started.
 *   record  the Leon2S record of the share block (startup_share_copy +0x30)
 * Writes the fixed table at CODE 0x8292, then the two words of the record into 0x9F120200 / 0x9F120204, then
 * 0x9F1000E0 = 5 and 0x9F12000C = 0x50000000 once more. Same steps as startup_setup_leon2m for the other
 * processor, without the message and the chip 0x1A writes. The purpose of the single registers is not shown.
 * Only caller: startup_load_core_images, right after startup_setup_leon2m.
 */
void startup_setup_leon2s(struct leon2s_share_record *record)
{
    int i;
    for (i = 0; i < CORE_REG_TABLE_WORDS; ) {
        startup_core_reg_addr.l = LEON2S_CORE_REG_TABLE[i++];
        startup_core_reg_value.l = LEON2S_CORE_REG_TABLE[i++];
        reg_ahb_write_addr = startup_core_reg_addr; reg_ahb_write_value = startup_core_reg_value; reg_ahb_write32();
    }
    startup_core_reg_addr.l = LEON2S_CORE_REG_0200;
    startup_core_reg_value.l = record->reg_0200_value;
    reg_ahb_write_addr = startup_core_reg_addr; reg_ahb_write_value = startup_core_reg_value; reg_ahb_write32();
    startup_core_reg_addr.l = LEON2S_CORE_REG_0204;
    startup_core_reg_value.l = record->reg_0204_value;
    reg_ahb_write_addr = startup_core_reg_addr; reg_ahb_write_value = startup_core_reg_value; reg_ahb_write32();
    startup_core_reg_addr.l = 0x9F1000E0;
    startup_core_reg_value.l = 0x00000005;
    reg_ahb_write_addr = startup_core_reg_addr; reg_ahb_write_value = startup_core_reg_value; reg_ahb_write32();
    startup_core_reg_addr.l = 0x9F12000C;
    startup_core_reg_value.l = 0x50000000;
    reg_ahb_write_addr = startup_core_reg_addr; reg_ahb_write_value = startup_core_reg_value; reg_ahb_write32();
}
