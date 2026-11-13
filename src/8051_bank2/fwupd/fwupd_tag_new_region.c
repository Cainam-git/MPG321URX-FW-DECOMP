/* fwupd_tag_new_region  (FUN_CODE_d10a)
 *
 * Mark the newly written firmware region valid and the old one not valid.
 * Name basis: proven - DUALFW tag block at region + 0xE00 whose last byte (region + 0xFFF) is 0xAA for
 *   ValidRegionNext, 0 for ValidRegionCurrent (fwupd_pick_valid_region reads them)
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE. tag_address is the LARGE local at XDATA 0x08EB (stored by ?C?LSTXDATA,
 * reloaded for the call); without that local (the sum written straight into the call argument) it is 137 B.
 * The tail 'LCALL fwupd_wait_ready_line; RET' is a real jump target (JNC from the '< 2' test).
 */
/* fwupd_dualfw_region (XDATA 0x0434), as in fwupd_run_isp_write's file. */
struct dualfw_region { unsigned char cur; unsigned char next; };
extern struct dualfw_region xdata fwupd_dualfw_region;
extern unsigned long xdata fwupd_record_base;
extern void fwupd_svc_write_tag_block(unsigned long addr, unsigned char v);
extern void fwupd_wait_ready_line(unsigned int t);

#define REGION_SHIFT    12      /* the regions are 0x1000 bytes apart */
#define TAG_BLOCK_AT    0xe00   /* the 512-byte tag block; its last byte (region + 0xFFF) is the tag */
#define TAG_VALID       0xaa    /* the value fwupd_pick_valid_region looks for */
#define TAG_CLEARED     0x00
#define REGION_COUNT    2
#define SVC_WAIT        0x0fa0

/* fwupd_tag_new_region: after a DUALFW update, tag region next valid and clear the tag of region cur.
 *
 * Each tag goes out as a tag block (fwupd_svc_write_tag_block) at fwupd_record_base + region * 0x1000 +
 * TAG_BLOCK_AT, followed by a wait for the ready line. The old region is cleared only when cur is 0 or 1.
 * Only caller: fwupd_step_port_state, on port command CMD_START_ISP_DUALFW (0x17), when the write has ended without
 * an error code in mailbox byte 0xF19A; the caller then sets the write protection and stays in an endless loop. */
void fwupd_tag_new_region(void)
{
    unsigned long tag_address;
    tag_address = fwupd_record_base + ((unsigned int)fwupd_dualfw_region.next << REGION_SHIFT) + TAG_BLOCK_AT;
    fwupd_svc_write_tag_block(tag_address, TAG_VALID);
    fwupd_wait_ready_line(SVC_WAIT);
    if (fwupd_dualfw_region.cur < REGION_COUNT) {
        tag_address = fwupd_record_base + ((unsigned int)fwupd_dualfw_region.cur << REGION_SHIFT) + TAG_BLOCK_AT;
        fwupd_svc_write_tag_block(tag_address, TAG_CLEARED);
        fwupd_wait_ready_line(SVC_WAIT);
    }
}
