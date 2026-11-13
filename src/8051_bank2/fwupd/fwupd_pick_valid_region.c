/* fwupd_pick_valid_region  (FUN_CODE_ce2a)
 *
 * Find which of the two firmware regions carries the valid tag.
 * Name basis: proven - DUALFW tags 0xAA at region + 0xFFF read over the service link; sets
 *   TagInfo.ValidRegionCurrent (0x0434) / ValidRegionNext (0x0435) and prints them
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE; locals region / tag in the LARGE block at 0x08EE / 0x08EF.
 * 0x0434 / 0x0435 are reached with one INC DPTR, so they are declared as one object (struct dualfw_region).
 */
/* fwupd_dualfw_region (XDATA 0x0434), as in fwupd_run_isp_write's file. */
struct dualfw_region { unsigned char cur; unsigned char next; };
extern struct dualfw_region xdata fwupd_dualfw_region;
extern unsigned long xdata fwupd_record_base;
extern void fwupd_svc_send_cmd_0x0f_copy(unsigned char a);
extern void fwupd_svc_set_address(unsigned long addr);
extern void fwupd_wait_ready_line(unsigned int t);
extern void i2c_read_bytes(unsigned char dev, unsigned char *buf, unsigned int n);
extern void lib_printf517(void *fmt, ...) large;

#define SVC_ADDRESS     0x6e
#define REGION_COUNT    2
#define REGION_SHIFT    12      /* the regions are 0x1000 bytes apart */
#define TAG_AT          0xfff   /* tag byte at the end of a region */
#define TAG_VALID       0xaa
#define FMT_REGION_NEXT     ((void code *)0xcb10)   /* "TagInfo.ValidRegionNext = %d\r\n" */
#define FMT_REGION_CURRENT  ((void code *)0xcb2f)   /* "TagInfo.ValidRegionCurrent = %d\r\n" */

/* fwupd_pick_valid_region: find the DUALFW region that carries the tag and note it in fwupd_dualfw_region.
 *
 * After service command 0x0F with 0, for region 0 and then 1: set the service address to fwupd_record_base +
 * region * 0x1000 + TAG_AT, wait for the ready line (100) and read one byte. The first region whose byte is
 * TAG_VALID becomes cur; when neither has it, cur = 0. next = the other region. Both are printed.
 * fwupd_svc_write_tag_block writes the tag byte. Caller: fwupd_run_isp_write in mode ISP_MODE_PICK_REGION (0x11). */
void fwupd_pick_valid_region(void)
{
    unsigned char region;
    unsigned char tag;
    fwupd_svc_send_cmd_0x0f_copy(0);
    for (region = 0; region < REGION_COUNT; region++) {
        fwupd_svc_set_address(fwupd_record_base + ((unsigned int)region << REGION_SHIFT) + TAG_AT);
        fwupd_wait_ready_line(100);
        i2c_read_bytes(SVC_ADDRESS, &tag, 1);
        if (tag == TAG_VALID) {
            fwupd_dualfw_region.cur = region;
            break;
        }
        if (region == 1) fwupd_dualfw_region.cur = 0;
    }
    fwupd_dualfw_region.next = fwupd_dualfw_region.cur + 1;
    if (fwupd_dualfw_region.next >= REGION_COUNT) fwupd_dualfw_region.next = 0;
    lib_printf517(FMT_REGION_NEXT, (unsigned int)fwupd_dualfw_region.next);
    lib_printf517(FMT_REGION_CURRENT, (unsigned int)fwupd_dualfw_region.cur);
}
