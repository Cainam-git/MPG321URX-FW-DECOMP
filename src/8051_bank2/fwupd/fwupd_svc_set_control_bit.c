/* fwupd_svc_set_control_bit  (FUN_CODE_dd6a)
 *
 * Change one main chip register over the service link by the mask in the mailbox work bytes.
 *   on: 1: the 'on' change, 0: the 'off' change (see the note)
 * Note: Register = work bytes 0 and 5, mask = byte 6, polarity = byte 7. Polarity 0: on sets the mask bits,
 *   off clears them; else on keeps only the mask bits and off sets all bits outside the mask.
 * Name basis: derived - fwupd_mailbox_work_bytes 0, 5, 6, 7 (mailbox commands 0x41 / 0x42) as register, mask
 *   and polarity; fwupd_svc_read_register, fwupd_svc_write_register
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE. Locals reg and value live in XDATA (LARGE). The closing
 * fwupd_svc_write_register is a tail call.
 */
/* Work bytes 0, 5, 6 and 7 of the eight at XDATA 0x064A (set by mailbox commands 0x41 / 0x42, see
 * lib_copy_to_work_array): register number high byte, register number low byte, bit mask, polarity. */
extern unsigned char xdata fwupd_mailbox_work_bytes, DAT_EXTMEM_064f, DAT_EXTMEM_0650, DAT_EXTMEM_0651;
unsigned char fwupd_svc_read_register(unsigned int reg);
unsigned char fwupd_svc_write_register(unsigned int reg, unsigned char val);

/* fwupd_svc_set_control_bit: read one register of the main chip over the service link, change it by the mask from
 * the mailbox work bytes and write it back.
 *
 * on: which of the two changes below is made.
 *
 * With polarity (work byte 7) 0: on sets the mask bits, off clears them. With any other polarity: on keeps only the
 * mask bits (value & mask), off sets every bit outside the mask (value | ~mask).
 * Caller: fwupd_run_isp_write, in update modes with bit 3: with 0 before and 1 after the first write-protect-off step,
 * and again with 0 before and 1 after the DUALFW tag and write protect at the end. */
void fwupd_svc_set_control_bit(bit on)
{
    unsigned int reg;
    unsigned char value;
    reg = (fwupd_mailbox_work_bytes << 8) | DAT_EXTMEM_064f;
    value = fwupd_svc_read_register(reg);
    if (on) {
        if (DAT_EXTMEM_0651 == 0) value |= DAT_EXTMEM_0650;
        else value &= DAT_EXTMEM_0650;
    } else {
        if (DAT_EXTMEM_0651 == 0) value &= ~DAT_EXTMEM_0650;
        else value |= ~DAT_EXTMEM_0650;
    }
    fwupd_svc_write_register(reg, value);
}
