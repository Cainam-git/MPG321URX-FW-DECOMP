/* sys_otp_read_patch_byte  (FUN_a008d280)
 *
 * Return the replacement byte of the patch entry found last.
 *   addr: address
 * Returns: byte
 * Name basis: descriptive - entry index * 3 + 4 through the read port
 *
 * Matching notes
 * --------------
 * FUN_a008d280 (leon2s 0xa008d280-0xa008d2e0, 96 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Source form: base and the address are unsigned short; the two register bytes are written as
 * '(unsigned char)v' and '(unsigned char)(v >> 8)' (fw 0xa008d2c0 sll 16 / srl 24).
 */
#define REG_OTP_DATA      (*(volatile unsigned int *)0xcf012200)
#define REG_OTP_ADDR_LOW  (*(volatile unsigned int *)0xcf012240)
#define REG_OTP_ADDR_HIGH (*(volatile unsigned int *)0xcf012244)
extern unsigned char sys_otp_patch_found_index;

/* Read the byte at offset 4 of the patch entry that sys_otp_find_patch found last (entries are 3 bytes apart,
 * the same layout sys_otp_load_patch_table reads).
 *   addr: the address that was searched; above 0x7ff the entry is in the second half of the store
 */
unsigned char sys_otp_read_patch_byte(unsigned short addr)
{
    unsigned short base = 0;
    unsigned short offset;

    if (addr > 0x7ff)
        base = 0x800;
    offset = sys_otp_patch_found_index * 3 + base + 4;
    REG_OTP_ADDR_LOW = (unsigned char)offset;
    REG_OTP_ADDR_HIGH = (unsigned char)(offset >> 8);
    return REG_OTP_DATA;
}
