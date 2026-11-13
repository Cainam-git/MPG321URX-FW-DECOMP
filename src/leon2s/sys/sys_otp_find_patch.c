/* sys_otp_find_patch  (FUN_a008d1d8)
 *
 * Return whether an address is listed in the patch table.
 *   addr: address
 * Returns: 1 when found
 * Name basis: descriptive - searches the halfword table 0xA807D252; leaves the index in 0xA8078C01
 *
 * Matching notes
 * --------------
 * FUN_a008d1d8 (leon2s 0xa008d1d8-0xa008d280, 168 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Source form: the row is set in an if/else with the addr <= 0x7ff arm first; the search index is the global
 * sys_otp_patch_found_index itself (not a local).
 */
extern unsigned char sys_otp_patch_found_index;
extern unsigned char sys_otp_patch_count;
extern unsigned short sys_otp_patch_table[][10];

/* Look for an address in the patch table loaded by sys_otp_load_patch_table.
 *   addr: the value to find; up to 0x7ff searches row 0, above it row 1
 * Returns 1 when found. The index of the entry is then left in sys_otp_patch_found_index, which
 * sys_otp_read_patch_byte uses.
 */
int sys_otp_find_patch(unsigned short addr)
{
    unsigned char row;

    if (addr <= 0x7ff)
        row = 0;
    else
        row = 1;
    for (sys_otp_patch_found_index = 0; sys_otp_patch_found_index < sys_otp_patch_count; sys_otp_patch_found_index++)
        if (sys_otp_patch_table[row][sys_otp_patch_found_index] == (unsigned short)addr)
            return 1;
    return 0;
}
