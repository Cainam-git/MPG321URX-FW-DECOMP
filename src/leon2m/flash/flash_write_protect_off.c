/* flash_write_protect_off  (FUN_a0124ed0)
 *
 * Switch the flash write protection off.
 * Name basis: derived - gpio_write_pin(0xC, 0x40, 0xFF) before an erase or write through the 8051
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0124ed0 @ 0xa0124ed0, flags -mcpu=v8 -O2 -g.
 */
extern int gpio_write_pin();

/*
 * Write level 0xff (bit 0 set: high) to mask 0x40 (pin 6) of GPIO port 12; flash_write_protect_on writes level 0
 * to the same pin.
 * Called by nvram_erase_area, nvram_flash_advance_row and fwupd_api_start_update. The first two call
 * flash_write_protect_on afterwards; fwupd_api_start_update does not.
 */
void flash_write_protect_off(void)
{
    gpio_write_pin(0xc, 0x40, 0xff);
}
