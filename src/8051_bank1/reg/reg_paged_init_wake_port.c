/* reg_paged_init_wake_port  (FUN_CODE_ad88)
 *
 * Write the wake set-up of one input into the paged registers.
 *   ch: port
 * Name basis: descriptive - chip 0x20: 0xDCAC and ten 0xDCA1 bytes; else four reg_paged_update_bits calls;
 *   caller power_init_wake_detection
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_ad88, OPTIMIZE(8,SPEED) LARGE.
 * Source form: ch is copied to the local shift_count first.
 */
extern unsigned char xdata reg_chip_id;
extern unsigned char xdata DAT_EXTMEM_dcac;
extern unsigned char xdata DAT_EXTMEM_dca1[10];
void reg_paged_update_bits(unsigned char ch, unsigned int reg, unsigned char v, unsigned char f);

/*
 * reg_paged_init_wake_port - set up the registers that let one port wake the chip.
 *   ch: port number
 * Chip id 0x20 (reg_chip_id): write 2 << ch to 0xDCAC and ten fixed bytes to 0xDCA1..0xDCAA.
 * Any other chip: four reg_paged_update_bits calls on the paged registers of block ch: set 0x01 in 0x0490, clear
 * 0x01 in 0x0434, clear 0x10 in 0x0433, clear 0x02 in 0x0490.
 * Caller: power_init_wake_detection.
 */
void reg_paged_init_wake_port(unsigned char ch)
{
    unsigned char shift_count;

    if (reg_chip_id == 0x20) {
        shift_count = ch;
        DAT_EXTMEM_dcac = 2 << shift_count;
        DAT_EXTMEM_dca1[0] = 0x87;
        DAT_EXTMEM_dca1[1] = 0x99;
        DAT_EXTMEM_dca1[2] = 0xc0;
        DAT_EXTMEM_dca1[3] = 0x17;
        DAT_EXTMEM_dca1[4] = 0;
        DAT_EXTMEM_dca1[5] = 0xbd;
        DAT_EXTMEM_dca1[6] = 0x87;
        DAT_EXTMEM_dca1[7] = 0x44;
        DAT_EXTMEM_dca1[8] = 0x44;
        DAT_EXTMEM_dca1[9] = 0;
    } else {
        reg_paged_update_bits(ch, 0x0490, 1, 1);
        reg_paged_update_bits(ch, 0x0434, 1, 0);
        reg_paged_update_bits(ch, 0x0433, 0x10, 0);
        reg_paged_update_bits(ch, 0x0490, 2, 0);
    }
}
