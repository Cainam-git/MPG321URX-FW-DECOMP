/* flash_read_extended_address  (FUN_CODE_18e2)
 *
 * Read the flash chip's extended address register.
 * Returns: register value
 * Name basis: proven - SPI command 0xC8
 *
 * Matching notes
 * --------------
 * Built with the section default OPTIMIZE(7,SPEED).
 */

#define FLASH_CMD_READ_EXT_ADDR 0xc8    /* answers the extended address register */

unsigned char flash_read_command_byte(unsigned char cmd);

/* flash_read_extended_address
 *
 * Returns the flash chip's extended address register, read with command 0xC8.  Only caller: flash_identify, for
 * chips of size code 5; a value other than 0 stops the boot there.
 */
unsigned char flash_read_extended_address(void)
{
    return flash_read_command_byte(FLASH_CMD_READ_EXT_ADDR);
}
