/* fwupd_svc_send_region  (FUN_CODE_bcb3)
 *
 * Send the ISP region command with flash base address and size.
 * Returns: 0 on success
 * Name basis: derived - packet 09 DE, address (0x0717), size code * 0x40000 / 2, to slave 0x6E
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(7,SPEED) LARGE. Locals in the LARGE block from 0x08EE: dram_address 0x08EE, flash_bytes
 * 0x08F2, packet 0x08F6..0x08FF; low_byte_ptr is a register pointer (OPTIMIZE(7) keeps it in DPTR).
 * What made it exact: the tail 'LCALL i2c_write_packet / RET' is OPTIMIZE(7) (level 8 turns it into LJMP), and the
 * low byte of dram_address is read through an xdata byte pointer ('low_byte_ptr = ...; packet[2] = low_byte_ptr[3];'),
 * which at level 7 gives the firmware's MOV DPTR,#0x08EE / INC DPTR x3 / MOVX (a plain
 * '((unsigned char *)&dram_address)[3]' folds to MOV DPTR,#0x08F1; '(unsigned char)dram_address' at level 7 reads
 * all four bytes). The same [3] works with '++ x3', '+= 3' and '*(p + 3)'.
 */
extern unsigned char xdata fwupd_flash_size_code;
extern unsigned long fwupd_get_value_0717(void);
extern unsigned char i2c_write_packet(unsigned char addr, unsigned char len, unsigned char *buf);

#define SVC_ADDRESS        0x6e     /* slave address of the service packets */
#define SVC_REGION_BYTES   0x09     /* first packet byte: the count of bytes after it */
#define SVC_CMD_REGION     0xde
#define SIZE_CODE_UNIT     0x40000UL    /* bytes per step of fwupd_flash_size_code */
#define PACKET_BYTES       10

/* fwupd_svc_send_region: send the region packet on the service bus.
 *
 * Packet: SVC_REGION_BYTES, SVC_CMD_REGION, then fwupd_dram_address (fwupd_get_value_0717) as four bytes and half
 * the flash size (fwupd_flash_size_code * SIZE_CODE_UNIT / 2) as four bytes, both low byte first.
 * i2c_write_packet adds the XOR checksum. Returns what i2c_write_packet returns (0 = every byte acknowledged).
 * Only caller: fwupd_svc_send_region_thunk. */
unsigned char fwupd_svc_send_region(void)
{
    unsigned long dram_address;
    unsigned long flash_bytes;
    unsigned char packet[PACKET_BYTES];
    unsigned char xdata *low_byte_ptr;
    dram_address = fwupd_get_value_0717();
    flash_bytes = fwupd_flash_size_code * SIZE_CODE_UNIT;
    packet[0] = SVC_REGION_BYTES;
    packet[1] = SVC_CMD_REGION;
    low_byte_ptr = (unsigned char xdata *)&dram_address; packet[2] = low_byte_ptr[3];   /* 8051 longs are big-endian */
    packet[3] = (unsigned char)(dram_address >> 8);
    packet[4] = (unsigned char)(dram_address >> 16);
    packet[5] = (unsigned char)(dram_address >> 24);
    packet[6] = (unsigned char)(flash_bytes / 2);
    packet[7] = (unsigned char)((flash_bytes / 2) >> 8);
    packet[8] = (unsigned char)((flash_bytes / 2) >> 16);
    packet[9] = (unsigned char)((flash_bytes / 2) >> 24);
    return i2c_write_packet(SVC_ADDRESS, PACKET_BYTES, packet);
}
