/* Set_INTERNAL_2_INPUT_Path  (FUN_a00fe1dc)
 *
 * Select the source of internal signal path 2.
 * Name basis: proven - prints 'Set_INTERNAL_2_INPUT_Path' (original name)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fe1dc @ 0xa00fe1dc, 528 bytes, flags -mcpu=v8 -O3 -g (-O3 -g -msoft-float and -O3 match too).
 * Twin of Set_INTERNAL_1_INPUT_Path, which uses bits 4 and 6 and bit 6 of 0xCF011600.
 * Source form:
 *  - the path register is read as an if/else of two loads (one sethi per address; the selected pointer shares
 *    the sethi);
 *  - case order 1, 2, 3; case 1 repeats "path_bits &= ~0x28", a no-op on the value (the bits are already clear)
 *    that gives the firmware's extra "mov %o5,%l0" in case 1;
 *  - the semaphore is a pair of static functions, lock() and unlock().
 */
#define R(a) (*(volatile unsigned int *)(a))
#define SEM R(0xcf03c840)
#define PATH_REG_NEW 0xcf0116e0                 /* the path register of chip revisions above CHIP_REVISION_LIMIT */
#define PATH_REG_OLD 0xcf0116d4                 /* the path register of the other revisions */
#define CHIP_REVISION_LIMIT 0x81

/* First word of the active panel row; see the write at the end. */
struct panel_row_head { unsigned int word0; };
extern struct panel_row_head *panel_working_row_ptr;
extern int dbg_printf();
extern unsigned char sys_get_chip_revision(void);

/* Take the hardware semaphore at 0xCF03C840: write 1 unless it reads 2, and stop when it reads 1. After 65536
 * tries 1 is written anyway. */
static void lock(void)
{
    unsigned short t = 0xffff;
    do {
        if (SEM != 2) SEM = 1;
        if (SEM == 1) break;
    } while (--t != 0xffff);
    SEM = 1;
}
static void unlock(void) { SEM = 0; }

/* Select the source of internal path 2. Mode 1, 2 or 3 is the source; other values clear the field and change
 * nothing else. Called by sys_api_set_block_route_second, and the reader of the field is
 * input_get_internal_path2_source.
 *
 * The source is kept in bits 3 and 5 of the path register: mode 1 = both clear, mode 2 = bit 3, mode 3 = bit 5.
 * Bit 7 of the register at 0xCF011600 is cleared for mode 1 and set for modes 2 and 3, under the semaphore. */
void Set_INTERNAL_2_INPUT_Path(unsigned char mode)
{
    unsigned char path_bits;

    dbg_printf("Set_INTERNAL_2_INPUT_Path = %02x\r\n", mode);
    if (sys_get_chip_revision() > CHIP_REVISION_LIMIT) path_bits = R(PATH_REG_NEW); else path_bits = R(PATH_REG_OLD);
    path_bits &= ~0x28;
    switch (mode) {
    case 1:
        path_bits &= ~0x28;
        lock(); R(0xcf011600) &= ~0x80; unlock();
        break;
    case 2:
        path_bits |= 0x08;
        lock(); R(0xcf011600) |= 0x80; unlock();
        break;
    case 3:
        path_bits |= 0x20;
        lock(); R(0xcf011600) |= 0x80; unlock();
        break;
    }
    /* On the older revisions the register is left alone when bits 20-22 of the first word of the working panel
       row are 1. */
    if (sys_get_chip_revision() > CHIP_REVISION_LIMIT) R(PATH_REG_NEW) = path_bits;
    else if ((panel_working_row_ptr->word0 & 0x700000) != 0x100000) R(PATH_REG_OLD) = path_bits;
}
