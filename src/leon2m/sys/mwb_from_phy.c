/* mwb_from_phy  (FUN_a00e09b8)
 *
 * Copy a register byte of a memory interface into the masked bits of a memory word.
 * Name basis: proven - prints 'mwb_from_phy' in its error message (original name); unused
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -O3 -g (also matches with -msoft-float). The routine's own name is a separate read-only object
 * (fn_), passed to the error message as %s. Source form: the two shift directions are two separate loops, each
 * with its own error call.
 */
extern void sys_ddr_print_step(void);
extern void sys_ddr_print_error_prefix(void);
extern int dbg_printf(const char *fmt, ...);
extern unsigned int sys_ddr_phy_read_masked(unsigned char phy, unsigned short reg, unsigned char mask);
extern void reg_update_bits_at(unsigned int addr, unsigned int mask, unsigned int value);

static const char fn_[] = "mwb_from_phy";

/*
 * Copy bits of a register of memory interface phy into other bits of the word at addr. Nothing in the firmware
 * calls it.
 *
 * mask_phy selects the bits to take from register reg of the interface; mask_addr selects the bits to replace in
 * the word at addr. The two masks have the same number of bits only when one is the other shifted: the value
 * read is moved by the distance (1..7) that makes mask_phy shifted left (when mask_addr is the larger mask) or
 * right (when it is the smaller) equal to mask_addr, then stored into the word under mask_addr. Equal masks
 * need no shift.
 * If no distance fits, the routine prints "error: mwb_from_phy mask_addr(..)!<<= mask_phy(..)" (or "!>>=") and
 * stores the value without a shift.
 */
void mwb_from_phy(unsigned int addr, unsigned char mask_addr, unsigned char phy, unsigned short reg,
                  unsigned char mask_phy)
{
    unsigned char value;
    unsigned char shift;

    value = sys_ddr_phy_read_masked(phy, reg, mask_phy);
    if (mask_addr == mask_phy) {
        reg_update_bits_at(addr, mask_addr, value);
        return;
    }
    if (mask_addr > mask_phy) {
        /* Find the left shift that turns mask_phy into mask_addr. */
        for (shift = 1; shift < 8; shift++)
            if (mask_addr == (mask_phy << shift))
                break;
        if (shift == 8) {
            sys_ddr_print_step();
            sys_ddr_print_error_prefix();
            dbg_printf("error: %s mask_addr(0x%02x)!%s= mask_phy(0x%02x)\n", fn_, mask_addr, "<<", mask_phy);
            shift = 0;
        }
        reg_update_bits_at(addr, mask_addr, value << shift);
    } else {
        /* Find the right shift that turns mask_phy into mask_addr. */
        for (shift = 1; shift < 8; shift++)
            if (mask_addr == (mask_phy >> shift))
                break;
        if (shift == 8) {
            sys_ddr_print_step();
            sys_ddr_print_error_prefix();
            dbg_printf("error: %s mask_addr(0x%02x)!%s= mask_phy(0x%02x)\n", fn_, mask_addr, ">>", mask_phy);
            shift = 0;
        }
        reg_update_bits_at(addr, mask_addr, value >> shift);
    }
}
