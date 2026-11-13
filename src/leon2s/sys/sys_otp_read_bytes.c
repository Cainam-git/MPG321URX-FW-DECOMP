/* sys_otp_read_bytes  (FUN_a008d2e0)
 *
 * Read a range of bytes from the one-time-programmable data store, applying patches.
 *   start: first address
 *   len: byte count
 *   out: buffer address
 * Note: OTP is an inference from the indexed read port and its patch table; the store is not named in the
 *   firmware.
 * Name basis: descriptive - read sequence 0x61/0x60/0x40/0x60/0x70 on 0xCF012248; patch table from
 *   sys_otp_load_patch_table
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -Os -g.
 * Source form: the data-port read is written twice (in the not-patched arm and in the arm for ok == 0); the
 * address low byte is '(unsigned char)addr'. 'out' is a plain address (the callers pass an integer) that is
 * cast to a byte pointer at each store.
 */
/* Registers of the data store's read port (the last three are the indexed read of
 * sys_otp_load_patch_table: address low byte, address high byte, data). */
#define REG_21C0 (*(volatile unsigned int *)0xcf0121c0)
#define REG_21E0 (*(volatile unsigned int *)0xcf0121e0)
#define REG_2228 (*(volatile unsigned int *)0xcf012228)
#define REG_2248 (*(volatile unsigned int *)0xcf012248)
#define REG_224C (*(volatile unsigned int *)0xcf01224c)
#define STORE_ADDR_LOW  (*(volatile unsigned int *)0xcf012240)
#define STORE_ADDR_HIGH (*(volatile unsigned int *)0xcf012244)
#define STORE_DATA      (*(volatile unsigned int *)0xcf012200)
extern void timer_delay_units(unsigned int);
extern int sys_otp_load_patch_table(unsigned short);
extern int sys_otp_find_patch(unsigned short);
extern unsigned char sys_otp_read_patch_byte(unsigned short);

/*
 * Read len bytes, starting at address start, from the data store into the buffer at out.
 * The store is first put into read mode: the low bytes of registers 0xcf0121c0 and 0xcf0121e0 are saved and
 * set to 0x35 / 0x80, the address registers are cleared and 0x61, 0x60, 0x40, 0x60, 0x70 are written to
 * 0xcf012248 with short waits (5, 1, 1, 1 delay units) between them. Both saved bytes are restored at the end.
 * The store holds a patch table (sys_otp_load_patch_table). When the table is present (ok), a byte whose
 * address is listed in it (sys_otp_find_patch) is replaced by the patch entry's byte; every other byte is read
 * straight from the data port after writing its address low and high byte.
 *   start: address of the first byte
 *   len:   number of bytes
 *   out:   address of the destination buffer
 * Callers: sys_otp_load_shared_data, sys_otp_load_local_data, sys_otp_check_records (re-reads a bad record).
 */
void sys_otp_read_bytes(unsigned short start, unsigned short len, unsigned int out)
{
    unsigned char saved_21c0 = REG_21C0;
    unsigned char saved_21e0 = REG_21E0;
    unsigned char ok;
    unsigned short k;
    unsigned short addr;

    REG_21C0 = 0x35;
    REG_21E0 = 0x80;
    REG_2228 = 0;
    STORE_ADDR_LOW = 0;
    STORE_ADDR_HIGH = 0;
    REG_224C = 2;
    REG_2248 = 0x61;
    timer_delay_units(5);
    REG_2248 = 0x60;
    timer_delay_units(1);
    REG_2248 = 0x40;
    timer_delay_units(1);
    REG_2248 = 0x60;
    timer_delay_units(1);
    REG_2248 = 0x70;
    ok = 0;
    if ((unsigned char)sys_otp_load_patch_table(start) == 1)
        ok = 1;
    for (k = 0; k < len; k++) {
        addr = start + k;
        if (ok) {
            if ((unsigned char)sys_otp_find_patch(addr) == 1)
                ((unsigned char *)out)[k] = sys_otp_read_patch_byte(addr);
            else {
                STORE_ADDR_LOW = (unsigned char)addr;
                STORE_ADDR_HIGH = addr >> 8;
                ((unsigned char *)out)[k] = STORE_DATA;
            }
        } else {
            STORE_ADDR_LOW = (unsigned char)addr;
            STORE_ADDR_HIGH = addr >> 8;
            ((unsigned char *)out)[k] = STORE_DATA;
        }
    }
    REG_21C0 = saved_21c0;
    REG_21E0 = saved_21e0;
}
