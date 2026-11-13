/* flash_setup_bus_mode  (FUN_CODE_0c83)
 *
 * Switch the flash chip to the fastest read mode that works: quad, dual or single.
 * Name basis: proven - quad-enable set-up per chip maker; read commands 0x6B and 0x3B verified against the
 *   first bytes of the flash, else 0x0B
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) REGFILE(R.ORC).
 * Source form: flash_spi_transfer (flash_spi_transfer) must stay in this file, after this routine: with both in one
 * module the compiler's "reuse of common entry code" places the two shared parameter set-ups flash_spi_transfer_entry1 and
 * flash_spi_transfer_entry2 in front of it, as in the firmware.  The one byte work_byte serving as quad-enable test, unused
 * answer buffer, read-mode copy and compare counter, and the bit verified being tested in the status writes where
 * it is always 1, are both as in the original code.  The (int) casts on the bit tests are kept as matched.
 */

/* Flash commands used here.  0x01, 0x05 and 0x06 carry the names that the flash routines of both 8051 programs use;
 * 0x35, 0x31 and 0x15 are named by what this routine does with them. */
#define FLASH_CMD_WRITE_STATUS   0x01  /* opcode followed by one or two status bytes */
#define FLASH_CMD_READ_STATUS    0x05  /* answers status byte 1 */
#define FLASH_CMD_WRITE_ENABLE   0x06
#define FLASH_CMD_READ_STATUS2   0x35  /* answers the byte that 0x31, or the second byte after 0x01, writes */
#define FLASH_CMD_WRITE_STATUS2  0x31  /* opcode followed by one byte */
#define FLASH_CMD_READ_0X15      0x15  /* read for chip group 0x30 only; its answer becomes the second status byte */

/* Bits of status byte 1 that the write sequences wait on. */
#define FLASH_STATUS_BUSY        0x01  /* waited for to clear after each write */
#define FLASH_STATUS_WEL         0x02  /* set after FLASH_CMD_WRITE_ENABLE; waited for before and after each write */

/* Read opcodes tried, fastest first; the routine returns the one it keeps. */
#define FLASH_READ_QUAD          0x6b
#define FLASH_READ_DUAL          0x3b
#define FLASH_READ_FAST          0x0b  /* single-bit read, kept when neither test passes */

/* Bits of reg_flash_read_mode (0xF050). */
#define READ_MODE_QUAD           0x04
#define READ_MODE_DUAL           0x20

/* Chip groups: the high nibble of the chip index from flash_chip_table.  The quad-capable chips of the table
 * (flags bit 0) are all in these four groups. */
#define CHIP_GROUP_MASK          0xf0
#define CHIP_GROUP_MAKER_C2      0x30  /* JEDEC maker byte 0xC2: quad enable = status byte 1 bit 6 */
#define CHIP_GROUP_MAKER_EF      0x40  /* JEDEC maker byte 0xEF: quad enable = status byte 2 bit 1 */
#define CHIP_GROUP_MAKER_1C      0x50  /* JEDEC maker byte 0x1C: no quad-enable bit is read or written */
#define CHIP_GROUP_MAKER_C8      0x80  /* JEDEC maker byte 0xC8: quad enable = status byte 2 bit 1 */
#define STATUS1_QUAD_ENABLE      0x40
#define STATUS2_QUAD_ENABLE      0x02
#define STATUS1_BIT7             0x80

/* flash_chip_flags bit 1: write status byte 2 with its own command 0x31 instead of as the second byte after 0x01.
 * Only chips of group 0x80 have it set in flash_chip_table. */
#define CHIP_FLAG_SEPARATE_STATUS2 0x02

#define VERIFY_BYTES             10    /* bytes read back from flash address 0 and compared with CODE 0x0000 */

extern unsigned char volatile xdata DAT_EXTMEM_f134, reg_gpio_port12, reg_gpio_port12_partner, reg_flash_read_mode;
extern unsigned char data flash_chip_flags;
extern void lib_printf(void *fmt, ...);
void flash_send_command(unsigned char cmd);
unsigned char flash_read_command_byte(unsigned char cmd);
void flash_read_stream(unsigned char op, unsigned long addr, unsigned char n, unsigned char *dst);
void flash_spi_transfer(unsigned int n_out, unsigned char *out, unsigned int n_in, unsigned char *in);

/* flash_setup_bus_mode
 *
 * Chooses the read mode of the flash controller: quad (opcode 0x6B), dual (0x3B) or single-bit (0x0B).  A mode is
 * kept only when ten bytes read from flash address 0 in that mode equal CODE 0x0000..0x0009; flash address 0
 * holds the boot loader, which runs at CODE 0x0000 (docs/MAP.md).
 *   quad_capable: flash_quad_capable_flag (bit 0 of the chip's flags in flash_chip_table)
 *   chip_index:   flash_chip_index; its high nibble is the chip group
 * Called only by flash_identify, as its last step, which ignores the return value.  The mode stays in
 * reg_flash_read_mode (0xF050).
 *
 * Phases, in order:
 *   1. Quad-capable chips only: read the chip's quad-enable bit; where it sits depends on the chip group.
 *   2. When that bit is clear: set up registers 0xF134 / 0xF11C / 0xF11D and write the bit into the chip, in one
 *      of two forms chosen by flash_chip_flags bit 1.
 *   3. Quad-capable chips only: set up 0xF134 / 0xF11D again, select quad reads (0x6B) and verify; on a match
 *      print "Set Flash to Quad mode!!" and return 0x6B.
 *   4. Select dual reads (0x3B) and verify; on a match print "Set Flash to Dual mode!!" and return 0x3B.
 *   5. Clear the dual bit, print "System can not support Dual mode!!" and return 0x0B.  The boot loader carries
 *      on with single-bit reads; it does not stop.
 *
 * Returns: the read opcode kept: 0x6B, 0x3B or 0x0B.
 */
unsigned char flash_setup_bus_mode(unsigned char quad_capable, unsigned char chip_index)
{
    unsigned char code *boot_code;  /* CODE 0x0000: the bytes the read-back must equal */
    unsigned char work_byte;        /* quad-enable test, unused answer buffer, read-mode copy, compare counter */
    unsigned char status1, status2;
    unsigned char status_cmd[3];    /* opcode and the one or two status bytes to write */
    unsigned char readback[10];
    bit verified;                   /* bit 0x20.3 */
    verified = 1;
    if (quad_capable) {
        /* Phase 1: is quad enable already set in the chip?  A chip outside the four groups leaves work_byte unset
         * here; no quad-capable chip of the table is outside them. */
        if ((chip_index & CHIP_GROUP_MASK) == CHIP_GROUP_MAKER_C2) work_byte = flash_read_command_byte(FLASH_CMD_READ_STATUS) & STATUS1_QUAD_ENABLE;
        else if ((chip_index & CHIP_GROUP_MASK) == CHIP_GROUP_MAKER_EF || (chip_index & CHIP_GROUP_MASK) == CHIP_GROUP_MAKER_C8) work_byte = flash_read_command_byte(FLASH_CMD_READ_STATUS2) & STATUS2_QUAD_ENABLE;
        else if ((chip_index & CHIP_GROUP_MASK) == CHIP_GROUP_MAKER_1C) work_byte = 1;
        if (work_byte == 0) {
            /* Phase 2: quad enable is clear.  0xF11C / 0xF11D are GPIO port 12 registers in the 8051
             * application's names; what these bits drive is not shown. */
            DAT_EXTMEM_f134 |= 0xc0;
            reg_gpio_port12 |= 0x40;
            reg_gpio_port12_partner |= 0x80;
            reg_gpio_port12_partner &= ~0x40;
            if (flash_chip_flags & CHIP_FLAG_SEPARATE_STATUS2) {
                /* Form A: status byte 2 has its own write command 0x31. */
                status1 = flash_read_command_byte(FLASH_CMD_READ_STATUS);
                status2 = flash_read_command_byte(FLASH_CMD_READ_STATUS2);
                if ((int)(status1 & STATUS1_BIT7)) {
                    /* Status byte 1 has bit 7 set: write it with bit 7 clear first. */
                    verified = 1;
                    status_cmd[0] = FLASH_CMD_WRITE_STATUS;
                    status_cmd[1] = status1 & 0x7f;
                    flash_send_command(FLASH_CMD_WRITE_ENABLE);
                    while (!(flash_read_command_byte(FLASH_CMD_READ_STATUS) & FLASH_STATUS_WEL));
                    flash_spi_transfer(2, status_cmd, 0, &work_byte);
                    while (flash_read_command_byte(FLASH_CMD_READ_STATUS) & FLASH_STATUS_BUSY);
                    while (flash_read_command_byte(FLASH_CMD_READ_STATUS) & FLASH_STATUS_WEL);
                }
                /* Set quad enable in status byte 2. */
                flash_send_command(FLASH_CMD_WRITE_ENABLE);
                while (!(flash_read_command_byte(FLASH_CMD_READ_STATUS) & FLASH_STATUS_WEL));
                status_cmd[0] = FLASH_CMD_WRITE_STATUS2;
                status_cmd[1] = status2 | STATUS2_QUAD_ENABLE;
                flash_spi_transfer(2, status_cmd, 0, &work_byte);
                while (flash_read_command_byte(FLASH_CMD_READ_STATUS) & FLASH_STATUS_BUSY);
                while (flash_read_command_byte(FLASH_CMD_READ_STATUS) & FLASH_STATUS_WEL);
                /* verified is still 1 here in every case, so status byte 1 is always written back with the
                 * value read at the start. */
                if (verified) {
                    status_cmd[0] = FLASH_CMD_WRITE_STATUS;
                    status_cmd[1] = status1;
                    flash_send_command(FLASH_CMD_WRITE_ENABLE);
                    while (!(flash_read_command_byte(FLASH_CMD_READ_STATUS) & FLASH_STATUS_WEL));
                    flash_spi_transfer(2, status_cmd, 0, &work_byte);
                    while (flash_read_command_byte(FLASH_CMD_READ_STATUS) & FLASH_STATUS_BUSY);
                    while (flash_read_command_byte(FLASH_CMD_READ_STATUS) & FLASH_STATUS_WEL);
                }
            } else {
                /* Form B: both status bytes in one write, opcode 0x01 followed by byte 1 and byte 2. */
                status_cmd[1] = flash_read_command_byte(FLASH_CMD_READ_STATUS);
                if ((int)(status_cmd[1] & STATUS1_BIT7)) {
                    verified = 1;
                    status_cmd[1] &= 0x7f;
                }
                /* Second byte and quad enable by chip group; other groups write two zero bytes. */
                if ((chip_index & CHIP_GROUP_MASK) == CHIP_GROUP_MAKER_C2) { status_cmd[2] = flash_read_command_byte(FLASH_CMD_READ_0X15); status_cmd[1] |= STATUS1_QUAD_ENABLE; }
                else if ((chip_index & CHIP_GROUP_MASK) == CHIP_GROUP_MAKER_EF) { status_cmd[2] = flash_read_command_byte(FLASH_CMD_READ_STATUS2); status_cmd[2] |= STATUS2_QUAD_ENABLE; }
                else if ((chip_index & CHIP_GROUP_MASK) == CHIP_GROUP_MAKER_C8) { status_cmd[2] = flash_read_command_byte(FLASH_CMD_READ_STATUS2); status_cmd[2] |= STATUS2_QUAD_ENABLE; }
                else { status_cmd[1] = 0; status_cmd[2] = 0; }
                flash_send_command(FLASH_CMD_WRITE_ENABLE);
                while (!(flash_read_command_byte(FLASH_CMD_READ_STATUS) & FLASH_STATUS_WEL));
                status_cmd[0] = FLASH_CMD_WRITE_STATUS;
                flash_spi_transfer(3, status_cmd, 0, &work_byte);
                while (flash_read_command_byte(FLASH_CMD_READ_STATUS) & FLASH_STATUS_BUSY);
                while (flash_read_command_byte(FLASH_CMD_READ_STATUS) & FLASH_STATUS_WEL);
                work_byte = flash_read_command_byte(FLASH_CMD_READ_STATUS);
                /* verified is still 1 here in every case: the same write runs again with bit 7 of status byte 1
                 * set, whatever its value was. */
                if (verified) {
                    status_cmd[1] |= STATUS1_BIT7;
                    flash_send_command(FLASH_CMD_WRITE_ENABLE);
                    while (!(flash_read_command_byte(FLASH_CMD_READ_STATUS) & FLASH_STATUS_WEL));
                    flash_spi_transfer(3, status_cmd, 0, &work_byte);
                    while (flash_read_command_byte(FLASH_CMD_READ_STATUS) & FLASH_STATUS_BUSY);
                    while (flash_read_command_byte(FLASH_CMD_READ_STATUS) & FLASH_STATUS_WEL);
                    work_byte = flash_read_command_byte(FLASH_CMD_READ_STATUS);
                }
            }
        }
        /* Phase 3: quad reads.  The same register set-up as in phase 2, without 0xF11C. */
        DAT_EXTMEM_f134 |= 0xc0;
        reg_gpio_port12_partner |= 0x80;
        reg_gpio_port12_partner &= ~0x40;
        work_byte = reg_flash_read_mode;
        work_byte &= ~READ_MODE_DUAL;
        work_byte |= READ_MODE_QUAD;
        reg_flash_read_mode = work_byte;
        boot_code = 0;
        flash_read_stream(FLASH_READ_QUAD, 0, VERIFY_BYTES, readback);
        verified = 1;
        for (work_byte = 0; work_byte < VERIFY_BYTES; work_byte++) if (boot_code[work_byte] != readback[work_byte]) verified = 0;
        if (verified) {
            lib_printf((void code *)0x15bb);    /* "Set Flash to Quad mode!!\r\n" */
            return FLASH_READ_QUAD;
        }
        verified = 1;
        reg_flash_read_mode &= ~READ_MODE_QUAD;
    }
    /* Phase 4: dual reads. */
    work_byte = reg_flash_read_mode;
    work_byte &= ~(READ_MODE_QUAD | READ_MODE_DUAL);
    work_byte |= READ_MODE_DUAL;
    reg_flash_read_mode = work_byte;
    flash_read_stream(FLASH_READ_DUAL, 0, VERIFY_BYTES, readback);
    boot_code = 0;
    for (work_byte = 0; work_byte < VERIFY_BYTES; work_byte++) if (boot_code[work_byte] != readback[work_byte]) verified = 0;
    if (verified) {
        lib_printf((void code *)0x15d6);        /* "Set Flash to Dual mode!!\r\n" */
        return FLASH_READ_DUAL;
    }
    /* Phase 5: single-bit reads. */
    reg_flash_read_mode &= ~READ_MODE_DUAL;
    lib_printf((void code *)0x15f1);            /* "System can not support Dual mode!!\r\n" */
    return FLASH_READ_FAST;
}

/* Transfer type, FIFO and start values of the flash controller as this routine writes them; their single bits are
 * not named in the firmware or our documentation. */
#define SPI_MODE_KEEP_BUS        0x0c  /* bits 2..3 of reg_flash_spi_mode (bus mode) are kept */
#define SPI_MODE_TRANSFER        0x41
#define SPI_TYPE_TRANSFER        0x13  /* low bits of reg_flash_transfer_type; bits 5.. = bytes out */
#define SPI_START_TRANSFER       0x01  /* reg_flash_spi_start bit 0: set to start, clears when done */

extern unsigned char volatile xdata DAT_EXTMEM_f0e6x_unused;
extern unsigned char volatile xdata reg_flash_spi_mode, reg_flash_transfer_type, reg_flash_length_high, reg_flash_length_mid, reg_flash_length_low, reg_flash_command;
extern unsigned char volatile xdata reg_flash_fifo_f1c0, reg_flash_fifo_write, reg_flash_fifo_f1c8, reg_flash_spi_start;

/* flash_spi_transfer (flash_spi_transfer; compiled here, see the matching notes above)
 *
 * Sends n_out bytes to the flash chip (out[0] is the opcode, the rest go through the FIFO), then reads n_in answer
 * bytes into in[].  The controller is given n_out + n_in - 1 as the transfer length.
 *   n_out: bytes to send, opcode included;  out: those bytes
 *   n_in:  answer bytes to read (0 = none);  in: where they go
 * Called by flash_setup_bus_mode (status writes, nothing read) and flash_read_jedec_id (0x9F, four bytes read).
 *
 * Phases: set the transfer up; load the opcode and the further bytes; start and wait until the start bit clears;
 * read the answer, dropping the first byte the FIFO gives; put both FIFO registers back to 0x80.
 */
void flash_spi_transfer(unsigned int n_out, unsigned char *out, unsigned int n_in, unsigned char *in)
{
    unsigned char t;        /* mode copy, later the dropped first FIFO byte */
    unsigned long total;    /* transfer length given to the controller */
    unsigned int i;
    /* Set-up: transfer mode with the bus-mode bits kept, the number of bytes out, the length. */
    t = reg_flash_spi_mode & SPI_MODE_KEEP_BUS;
    t |= SPI_MODE_TRANSFER;
    reg_flash_spi_mode = t;
    total = n_out + n_in - 1;
    reg_flash_transfer_type = ((unsigned char)n_out << 5) | SPI_TYPE_TRANSFER;
    reg_flash_length_high = total >> 16;
    reg_flash_length_mid = total >> 8;
    reg_flash_length_low = (unsigned int)(total & 0xff);
    /* Opcode to its own register, the further bytes through the FIFO. */
    reg_flash_command = out[0];
    reg_flash_fifo_f1c0 = 0x82;
    for (i = 1; i < n_out; i++) reg_flash_fifo_write = out[i];
    reg_flash_fifo_f1c0 = 0x84;
    reg_flash_fifo_f1c8 = 0x81;
    /* Start and wait. */
    reg_flash_spi_start = SPI_START_TRANSFER;
    while ((int)(reg_flash_spi_start & SPI_START_TRANSFER));
    /* Answer: the first FIFO byte is read and dropped. */
    if (n_in > 0) {
        reg_flash_fifo_f1c8 = 0x82;
        t = reg_flash_fifo_f1c8;
        for (i = 0; i < n_in; i++) in[i] = reg_flash_fifo_f1c8;
    }
    reg_flash_fifo_f1c0 = 0x80;
    reg_flash_fifo_f1c8 = 0x80;
}
