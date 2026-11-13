/* flash_write_protect_on  (FUN_a0124eb4)
 *
 * Switch the flash write protection on.
 * Name basis: derived - gpio_write_pin(0xC, 0x40, 0) after an erase or write through the 8051
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0124eb4 @ 0xa0124eb4, flags -mcpu=v8 -O2 -g.
 */
extern int gpio_write_pin();

/*
 * Write level 0 to mask 0x40 (pin 6) of GPIO port 12. flash_write_protect_off writes level 0xff to the same pin.
 * Called by nvram_erase_area and nvram_flash_advance_row, which call flash_write_protect_off first.
 */
void flash_write_protect_on(void)
{
    gpio_write_pin(0xc, 0x40, 0);
}
