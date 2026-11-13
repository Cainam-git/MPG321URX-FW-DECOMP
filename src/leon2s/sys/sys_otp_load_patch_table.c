/* sys_otp_load_patch_table  (FUN_a008d0b8)
 *
 * Load the address patch table from the one-time-programmable data store.
 *   addr: address selecting the table half
 * Returns: 1 when a table is present
 * Name basis: descriptive - indexed reads through 0xCF012240/44 (address) and 0xCF012200 (data); header 0xA0 +
 *   count, 3-byte entries
 *
 * Matching notes
 * --------------
 * FUN_a008d0b8 (leon2s 0xa008d0b8-0xa008d1d8, 288 bytes), flags -mcpu=v8 -Os -g.
 * Source form: rd() is a static inline helper (inlined at every use); volatile is only on the hardware
 * registers; n is an unsigned short and the table value goes through an unsigned short local.
 */
#define REG_cf012200 (*(volatile unsigned int *)0xcf012200)
#define REG_cf012240 (*(volatile unsigned int *)0xcf012240)
#define REG_cf012244 (*(volatile unsigned int *)0xcf012244)
extern unsigned char sys_otp_patch_count;
extern unsigned short sys_otp_patch_table[][10];

#define OTP_HALF_SIZE   0x800   /* second table half starts at this address */
#define OTP_HEADER_MASK 0xa0    /* both of these header bits must be set for a table to exist */

/* Read one byte of the one-time-programmable store: write the address (low byte, then high byte) to the two
 * address registers, then read the data register. */
static inline unsigned int rd(unsigned short addr)
{
    REG_cf012240 = (unsigned char)addr;
    REG_cf012244 = (unsigned char)(addr >> 8);
    return REG_cf012200;
}

/* Load the patch table of one half of the store into sys_otp_patch_table.
 *   addr: an address of the store; up to 0x7ff selects the first half (row 0), above it the second half (row 1)
 * The half starts with a header byte: both bits 0xa0 must be set, otherwise there is no table and 0 is returned.
 * The low nibble of the header is the entry count (kept in sys_otp_patch_count). Entry i is 3 bytes from
 * header + 2: a 16-bit value (low byte first) that is stored with the half's base address ORed in.
 * sys_otp_find_patch searches the rows of this table.
 * Returns 1 when a table is present.
 */
int sys_otp_load_patch_table(unsigned short addr)
{
    unsigned short base;
    unsigned char row;
    unsigned int header;
    unsigned short count;
    unsigned char i;
    unsigned int low;
    unsigned short entry;

    if (addr <= 0x7ff) {
        base = 0;
        row = 0;
    } else {
        base = OTP_HALF_SIZE;
        row = 1;
    }
    header = rd(base);
    if ((header & OTP_HEADER_MASK) != OTP_HEADER_MASK)
        return 0;
    count = header & 0xf;
    sys_otp_patch_count = count;
    for (i = 0; i < count; i++) {
        low = rd(i * 3 + base + 2);
        entry = low | (rd(i * 3 + base + 3) << 8) | base;
        sys_otp_patch_table[row][i] = entry;
    }
    return 1;
}
