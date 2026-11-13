/* flash_read_jedec_id  (FUN_CODE_1777)
 *
 * Read the flash chip's three-byte identification.
 * Name basis: proven - SPI command 0x9F; the bytes are kept at XDATA 0xF064..0xF066
 *
 * Matching notes
 * --------------
 * Built with the section default OPTIMIZE(7,SPEED).
 * Source form: the command byte and the answer buffer are the overlaid DATA bytes 0x22 and 0x23..0x26, declared
 * as named data so their addresses are checked by the link; flash_spi_transfer is declared with int counts here.
 */

#define FLASH_CMD_READ_ID   0x9f    /* answers the JEDEC id: maker, memory type, capacity */
#define JEDEC_ANSWER_BYTES  4       /* bytes read back; the first three are kept */
#define JEDEC_ID_BYTES      3

extern unsigned char data flash_jedec_command;
extern unsigned char data flash_jedec_answer[4];
unsigned char volatile xdata reg_flash_jedec_id[3] _at_ 0xf064;
void flash_spi_transfer(int n_out, unsigned char *out, int n_in, unsigned char *in);

/* flash_read_jedec_id
 *
 * Sends 0x9F to the flash chip, reads four answer bytes and keeps the first three in 0xF064..0xF066
 * (reg_flash_jedec_maker / _mem_type / _capacity), where flash_identify looks them up in flash_chip_table.
 * Called once by startup_boot_main, just before flash_identify.
 */
void flash_read_jedec_id(void)
{
    unsigned char i;
    flash_jedec_command = FLASH_CMD_READ_ID;
    flash_spi_transfer(1, &flash_jedec_command, JEDEC_ANSWER_BYTES, flash_jedec_answer);
    for (i = 0; i < JEDEC_ID_BYTES; i++) {
        reg_flash_jedec_id[i] = flash_jedec_answer[i];
    }
}
