/* hdr_init_hdr10plus  (FUN_a0062434)
 *
 * Enable the HDR10+ interrupt source, store the panel peak luminance and load default metadata.
 * Name basis: derived - unmasks level-5 source 4 and level 5; record +0x20 = g_stDISP_Info.u16MaxLum (dump
 *   print); then defaults
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0062434 @ 0xa0062434-0xa00624b4 (32 words), flags -mcpu=v8 -Os -g.
 * Hardware registers are volatile (the R macro). The word is +0x20 of a record at 0xa8078a70 (the firmware
 * stores to [rec + 0x20]; an absolute symbol at 0xa8078a90 folds to its own %lo). Ends with a tail call of
 * hdr_init_default_metadata, which takes no arguments.
 */
/* The default HDR10+ record at 0xA8078A70; only word +0x20 (hdr10plus_panel_peak_x10) is used here. */
struct hdr10plus_default_record_layout { unsigned char pad[0x20]; unsigned int panel_peak_x10; };
extern struct hdr10plus_default_record_layout hdr10plus_default_record;
extern void reg_write32(volatile unsigned int *, unsigned int);
extern void hdr_init_default_metadata(void);
extern unsigned short hdr_get_peak_luminance(void);

#define R(a) (*(volatile unsigned int *)(a))
#define LEVEL5_SOURCE_MASK_REG 0x9f120048       /* 0x9f120034 + 4 * 5: source mask of interrupt level 5 */
#define LEVEL5_SOURCE4_BIT     0x10             /* source 4 of level 5 */
#define IRQ_ACTIVE_REG         0x9f120028       /* level bit set while the level's sources are served */
#define IRQ_MASK_REG           0x9f100090       /* bit n = level n */
#define LEVEL5_BIT             0x20
#define HDR10PLUS_RESULT_REG        0xd0013ffc  /* result word of the HDR10+ update */
#define HDR10PLUS_RESULT_NOT_LOADED 0xff

/*
 * Prepare the HDR10+ service: clear bit 4 of the level 5 source mask, clear the level 5 bit in the active
 * register, set it in the interrupt mask register, store the panel peak luminance times 10 in
 * hdr10plus_panel_peak_x10, mark the result word as "not loaded" and load the default metadata record.
 */
void hdr_init_hdr10plus(void)
{
    R(LEVEL5_SOURCE_MASK_REG) &= ~LEVEL5_SOURCE4_BIT;
    R(IRQ_ACTIVE_REG) &= ~LEVEL5_BIT;
    R(IRQ_MASK_REG) |= LEVEL5_BIT;
    hdr10plus_default_record.panel_peak_x10 = hdr_get_peak_luminance() * 10;
    reg_write32((volatile unsigned int *)HDR10PLUS_RESULT_REG, HDR10PLUS_RESULT_NOT_LOADED);
    hdr_init_default_metadata();
}
