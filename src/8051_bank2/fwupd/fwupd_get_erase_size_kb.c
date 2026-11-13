/* fwupd_get_erase_size_kb  (FUN_CODE_dcc9)
 *
 * Return the largest erase block size in KB that fits an address's alignment.
 *   addr: address
 * Returns: 64, 32 or 4
 * Name basis: derived - 0x40 when 64 KB aligned, 0x20 when 32 KB aligned, else 4; stored in record byte 0x0C
 *   by the record refresh
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE. LARGE parameter addr (0x08F6), local erase_kb (0x08FA, stored in each arm
 * and read back once at the end). Both tests are ?C?ULCMP against 0. Own segment, not one of the common-entry
 * members of the fwupd_refresh_flash_records module.
 */
#define ALIGN_64K_MASK 0xffff
#define ALIGN_32K_MASK 0x7fff

/* fwupd_get_erase_size_kb: return 64 when addr is a multiple of 64 KB, else 32 when it is a multiple of 32 KB,
 * else 4: the size in KB of the largest of these three blocks that can start at addr.
 * Caller: fwupd_refresh_flash_records, with word 0 of the record image; it stores the result in record byte 0x0C
 * (REC_BYTE_ERASE_KB). */
unsigned char fwupd_get_erase_size_kb(unsigned long addr)
{
    unsigned char erase_kb;
    if ((addr & ALIGN_64K_MASK) == 0) erase_kb = 64;
    else if ((addr & ALIGN_32K_MASK) == 0) erase_kb = 32;
    else erase_kb = 4;
    return erase_kb;
}
