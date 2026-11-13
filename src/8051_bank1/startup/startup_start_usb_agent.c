/* startup_start_usb_agent  (FUN_CODE_96eb)
 *
 * Copy the update agent into the USB controller and start it.
 * Name basis: derived - loader block 0xF166..0xF16F filled with flash address and length; start key 'USBONE'
 *   written to 0xF1E5 (docs/MAP.md)
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_96eb @ 0x96EB..0x97C4 (217 bytes), OPTIMIZE(7,SPEED), LARGE by pragma.
 * The routine has no xdata locals: i / j live in R6:R7 / R4:R5, image_record stays in R1..R3.
 * Source form: volatile on the 0xF1xx registers, reg_chip_id and 0xD5AF (its bit pulse re-reads the register at
 * 0x96F9; without volatile the bytes differ). 0xCD0A / 0xCD2A are plain (same bytes either way).
 */
#pragma LARGE
#include <intrins.h>
extern unsigned char volatile xdata reg_chip_id, DAT_EXTMEM_d5af, DAT_EXTMEM_f15a, DAT_EXTMEM_f1e0;
extern unsigned char xdata DAT_EXTMEM_cd0a, DAT_EXTMEM_cd2a;
extern unsigned char volatile xdata DAT_EXTMEM_f166, reg_usb_load_start, DAT_EXTMEM_f168, DAT_EXTMEM_f169, reg_usb_load_addr_low, reg_usb_load_addr_mid;
extern unsigned char volatile xdata reg_usb_load_addr_high, reg_usb_load_len_low, reg_usb_load_len_mid, reg_usb_load_len_high, DAT_EXTMEM_f1e5, DAT_EXTMEM_f1e4, DAT_EXTMEM_f1eb;

#define CHIP_VARIANT_1A      0x1A  /* reg_chip_id value that pulses 0xD5AF bit 0 instead of writing 0xF15A */
#define USB_LOAD_GO          0x87  /* start value of the copy; the boot loader starts its own copy (0xF1D0) with it too */
#define WAIT_ROUNDS_OUTER    100
#define WAIT_ROUNDS_INNER    1000  /* each round 8 NOPs */

/*
 * startup_start_usb_agent - copy the bank 2 update agent from the flash into the USB controller and start it.
 *   image_record  the agent's record in the share block copy (startup_share_copy, offset 0): bytes 0..3 flash
 *                 address and bytes 4..7 length, each most significant byte first; only the low 24 bits are used
 * Only caller: startup_load_core_images, which runs at start-up and again on wake-up (sys_main); the agent is
 * loaded before the two LEON processors are started (docs/MAP.md, start-up step 2).
 * Order:
 *   1. Pulse: chip variant 0x1A sets and clears 0xD5AF bit 0, the other variants write 3 then 0 to 0xF15A.
 *   2. 0xF1E0 = 0xC1 and 0xCD0A / 0xCD2A = 0xC0, a busy wait of 100 x 1000 x 8 NOPs, then 0xCD0A / 0xCD2A = 0x40
 *      and 0xF1E0 = 0. (power_off_sequence and power_setup_power_saving also write 0xF1E0 = 0xC1.)
 *   3. Hardware copy: flash address and length into the loader block 0xF16A..0xF16F, 0xF166 = 0xFF, start with
 *      USB_LOAD_GO and wait until reg_usb_load_start reads 0 again. No time limit.
 *   4. The six bytes "USBONE" into 0xF1E5, then 0xF1E4 = 0, 0xF1EB = 0x8A and 0xF1E0 = 0.
 * Bank 1 keeps running afterwards: the two programs run side by side.
 */
void startup_start_usb_agent(unsigned char *image_record)
{
    unsigned int i, j;
    if (reg_chip_id == CHIP_VARIANT_1A) {
        DAT_EXTMEM_d5af |= 0x01;
        DAT_EXTMEM_d5af &= 0xFE;
    } else {
        DAT_EXTMEM_f15a = 3;
        DAT_EXTMEM_f15a = 0;
    }
    DAT_EXTMEM_f1e0 = 0xC1;
    DAT_EXTMEM_cd0a = 0xC0;
    DAT_EXTMEM_cd2a = 0xC0;
    for (i = 0; i != WAIT_ROUNDS_OUTER; i++)
        for (j = 0; j != WAIT_ROUNDS_INNER; j++) {
            _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
        }
    DAT_EXTMEM_cd0a = 0x40;
    DAT_EXTMEM_cd2a = 0x40;
    DAT_EXTMEM_f1e0 = 0;
    /* Flash address and length, least significant byte first; byte 0 / byte 4 of the record are not used. */
    DAT_EXTMEM_f168 = 0;
    DAT_EXTMEM_f169 = 0;
    reg_usb_load_addr_low = image_record[3];
    reg_usb_load_addr_mid = image_record[2];
    reg_usb_load_addr_high = image_record[1];
    reg_usb_load_len_low = image_record[7];
    reg_usb_load_len_mid = image_record[6];
    reg_usb_load_len_high = image_record[5];
    DAT_EXTMEM_f166 = 0xFF;
    reg_usb_load_start = USB_LOAD_GO;
    while (reg_usb_load_start != 0) ;
    /* Start key of the USB controller (docs/MAP.md). */
    DAT_EXTMEM_f1e5 = 'U';
    DAT_EXTMEM_f1e5 = 'S';
    DAT_EXTMEM_f1e5 = 'B';
    DAT_EXTMEM_f1e5 = 'O';
    DAT_EXTMEM_f1e5 = 'N';
    DAT_EXTMEM_f1e5 = 'E';
    DAT_EXTMEM_f1e4 = 0;
    DAT_EXTMEM_f1eb = 0x8A;
    DAT_EXTMEM_f1e0 = 0;
}
