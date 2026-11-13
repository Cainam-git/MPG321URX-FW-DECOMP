/* hdr_update_hdr10plus_metadata  (FUN_a006370c)
 *
 * Check the receiver for a new HDR10+ packet and rebuild the tone curve when its content changed.
 * Note: In metadata modes 4 and 5 the new-packet test reads status register 5 through reg_read_port_indirect,
 *   which answers 0, so nothing is updated.
 * Name basis: proven - checks the HDR10+ IEEE OUI bytes 0x8B 0x84 0x90 (90-84-8B); then
 *   hdr_read_hdr10plus_metadata and the curve build
 *
 * Matching notes
 * --------------
 * FUN_a006370c (leon2s 0xa006370c-0xa00638a0, 404 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the local copy of the record is a structure assignment; GCC emits it as a call of the firmware memcpy
 *    lib_memcpy (declared with that link name);
 *  - volatile only on the hardware register accesses.
 */
/* The HDR10+ metadata record, 0x8a bytes; only its size matters here (field names: hdr10plus_metadata_record). */
struct Cal { unsigned char byte_0x00, tone_mapping_flag; unsigned short fields_0x02[0x2b]; unsigned char num_bezier_curve_anchors, byte_0x59; unsigned short bezier_curve_anchor[9]; unsigned char pad[0x88 - 0x6c]; unsigned short targeted_luminance; };
extern struct Cal hdr10plus_metadata;
extern void *memcpy(void *, const void *, unsigned int) __asm__("FUN_a00b15d8");
#define R(a) (*(volatile unsigned int *)(a))
extern unsigned char hdr_source_disable_bits;
extern unsigned char hdr_source;
extern unsigned char hdr_meta_receiver_index;
extern unsigned char hdr_meta_source_mode;
extern unsigned char hdr10plus_present_flag;
extern unsigned int hdr10plus_last_ticks;
extern unsigned char hdr10plus_packet_bytes[];
extern unsigned int hdr10plus_panel_peak_x10;
extern unsigned short hdr_meta_reg_byte3;
extern unsigned short hdr_meta_reg_byte2;
extern unsigned short hdr_meta_reg_byte1;
extern unsigned short hdr_meta_reg_byte0;
extern unsigned char hdr_meta_ready_mask;
extern unsigned short hdr_meta_status_reg;
extern unsigned char (*hdr_meta_reg_read_fn)(unsigned char, unsigned short);
extern unsigned int reg_read32(volatile unsigned int *);
extern void reg_write32(volatile unsigned int *, unsigned int);
extern unsigned char hdr_build_hdr10plus_tone_curve(unsigned int, struct Cal *);
extern unsigned int timer_get_ticks(void);
extern void hdr_read_hdr10plus_metadata(void);

/* Result word of the HDR10+ update: low byte HDR10PLUS_RESULT_LOADED or HDR10PLUS_RESULT_NOT_LOADED, source mode in bits 16.. */
#define HDR10PLUS_RESULT_REG        0xd0013ffc
#define HDR10PLUS_RESULT_LOADED     0xaa
#define HDR10PLUS_RESULT_NOT_LOADED 0xff
/* Packet bytes 1..3 must be 0x8b, 0x84, 0x90 (the IEEE OUI 90-84-8B of HDR10+). */
#define HDR10PLUS_OUI_BYTE1         0x8b
#define HDR10PLUS_OUI_BYTE2         0x84
#define HDR10PLUS_OUI_BYTE3         0x90

/*
 * Look at the receiver chosen by hdr_select_metadata_receiver and, when an HDR10+ packet has arrived, bring the
 * tone-mapping table up to date. Takes and returns nothing; it is called through small wrappers, one per source
 * mode.
 * It returns at once unless all of these hold: register 0xcf03c80c reads 0x99; bit hdr_source of
 * hdr_source_disable_bits is clear; the receiver's new-packet bit (hdr_meta_ready_mask in hdr_meta_status_reg) is set;
 * and packet bytes 1..3 are the HDR10+ OUI.
 * For such a packet it stores the time (hdr10plus_last_ticks) and sets hdr10plus_present_flag. If the packet's first
 * byte equals the first byte of the packet last read (hdr10plus_packet_bytes[0]) and the result register already
 * shows HDR10PLUS_RESULT_LOADED, nothing more is done. Otherwise the whole packet is read into
 * hdr10plus_metadata, the table is built from a copy of that record for the panel peak
 * (hdr_build_hdr10plus_tone_curve), and the result register gets HDR10PLUS_RESULT_LOADED | source mode << 16 when
 * that returned non-zero, HDR10PLUS_RESULT_NOT_LOADED otherwise.
 */
void hdr_update_hdr10plus_metadata(void)
{
    struct Cal copy;

    if (R(0xcf03c80c) != 0x99)
        return;
    if ((hdr_source_disable_bits >> hdr_source) & 1)
        return;
    /* New-packet bit. In metadata modes 4 and 5 the read goes through reg_read_port_indirect, which answers 0 for
     * status register 5, so the routine always stops here in those modes. */
    if (!(hdr_meta_reg_read_fn(hdr_meta_receiver_index, hdr_meta_status_reg) & hdr_meta_ready_mask))
        return;
    if (hdr_meta_reg_read_fn(hdr_meta_receiver_index, hdr_meta_reg_byte1) != HDR10PLUS_OUI_BYTE1)
        return;
    if (hdr_meta_reg_read_fn(hdr_meta_receiver_index, hdr_meta_reg_byte2) != HDR10PLUS_OUI_BYTE2)
        return;
    if (hdr_meta_reg_read_fn(hdr_meta_receiver_index, hdr_meta_reg_byte3) != HDR10PLUS_OUI_BYTE3)
        return;
    hdr10plus_last_ticks = timer_get_ticks();
    hdr10plus_present_flag = 1;
    /* Same first byte as the last packet and the table is already loaded: nothing changed. */
    if (hdr_meta_reg_read_fn(hdr_meta_receiver_index, hdr_meta_reg_byte0) == hdr10plus_packet_bytes[0]
        && (unsigned char)reg_read32((volatile unsigned int *)HDR10PLUS_RESULT_REG) == HDR10PLUS_RESULT_LOADED)
        return;
    hdr_read_hdr10plus_metadata();
    copy = hdr10plus_metadata;
    if (hdr_build_hdr10plus_tone_curve(hdr10plus_panel_peak_x10, &copy))
        reg_write32((volatile unsigned int *)HDR10PLUS_RESULT_REG, hdr_meta_source_mode << 16 | HDR10PLUS_RESULT_LOADED);
    else
        reg_write32((volatile unsigned int *)HDR10PLUS_RESULT_REG, HDR10PLUS_RESULT_NOT_LOADED);
}
