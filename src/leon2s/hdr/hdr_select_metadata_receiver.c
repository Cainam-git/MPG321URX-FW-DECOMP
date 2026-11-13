/* hdr_select_metadata_receiver  (FUN_a0061f5c)
 *
 * Select which HDMI receiver and register set the HDR10+ metadata is read from.
 *   mode: 0, 1 = HDMI 2.0 receiver 0 / 1; 2, 3 = HDMI 2.1 receiver 0 / 1; 4, 5 = receiver 0 / 1 read through
 *       reg_read_port_indirect
 * Note: With modes 4 and 5 the HDR10+ new-packet test never passes: reg_read_port_indirect answers 0 for
 *   status register 5.
 * Name basis: derived - modes 0/1 set the HDMI 2.0 register routines, 2/3 those of the HDMI 2.1 receivers, 4/5
 *   reg_read_port_indirect with status register 5; sets the read / write / modify pointers
 *
 * Matching notes
 * --------------
 * FUN_a0061f5c (leon2s 0xa0061f5c-0xa0062308, 940 bytes), flags -mcpu=v8 -Os -g.
 * Source form: hdr_meta_reg_write_fn and hdr_meta_reg_write_fn_copy are set in one chained assignment
 * ('hdr_meta_reg_write_fn = hdr_meta_reg_write_fn_copy = f;').
 */
/* Metadata source modes (value of hdr_meta_source_mode; hdr_select_source passes the HDR service's source). */
#define HDR_META_HDMI20_RX0   0     /* HDMI 2.0 receiver 0 */
#define HDR_META_HDMI20_RX1   1
#define HDR_META_HDMI21_RX0   2     /* HDMI 2.1 receiver 0 */
#define HDR_META_HDMI21_RX1   3
#define HDR_META_INDIRECT_RX0 4     /* read through reg_read_port_indirect; no write or modify routine is set */
#define HDR_META_INDIRECT_RX1 5

typedef unsigned char (*rd_fn)(unsigned char, unsigned short);
typedef void (*wr_fn)(unsigned int, unsigned short, unsigned int);
typedef void (*mod_fn)(unsigned char, unsigned short, unsigned char, unsigned char);

extern rd_fn hdr_meta_reg_read_fn;
extern wr_fn hdr_meta_reg_write_fn;
extern wr_fn hdr_meta_reg_write_fn_copy;
extern mod_fn hdr_meta_reg_modify_fn;
extern unsigned short hdr_meta_status_reg;
extern unsigned char hdr_meta_ready_mask;
extern unsigned short hdr_meta_reg_byte0;
extern unsigned short hdr_meta_reg_byte1;
extern unsigned short hdr_meta_reg_byte2;
extern unsigned short hdr_meta_reg_byte3;
extern unsigned char hdr_meta_receiver_index;
extern unsigned char hdr_meta_source_mode;
extern void hdmi_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern void hdmi_rx21_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern unsigned int hdmi_reg_read8(unsigned int, unsigned short);
extern void hdmi_reg_write8(unsigned int, unsigned short, unsigned int);
extern unsigned int hdmi_rx21_reg_read8(unsigned int, unsigned short);
extern void hdmi_rx21_reg_write8(unsigned int, unsigned short, unsigned int);
extern int reg_read_port_indirect(unsigned char, unsigned int);

/*
 * Choose the receiver the HDR10+ packet is read from, and set up the data that hdr_update_hdr10plus_metadata and
 * hdr_read_hdr10plus_metadata use: the source mode, the receiver index, the register read / write / modify
 * routines, the status register with its new-packet mask, and the registers of the four packet bytes.
 *   mode: 0, 1 = HDMI 2.0 receiver 0 / 1; 2, 3 = HDMI 2.1 receiver 0 / 1; 4, 5 = read through
 *         reg_read_port_indirect (status register 5, mask 0x20). Another value changes nothing after the first
 *         step.
 * First, whatever the mode, bit 0x80 of register 0x7e of both HDMI 2.0 receivers and bit 1 of register 0x9c9 of
 * both HDMI 2.1 receivers are cleared. For modes 0..3 the chosen receiver's two bits are then set again: 0x7e
 * and 0x79 (mask 0x80) for HDMI 2.0, 0x9c9 and 0x391 (mask 1) for HDMI 2.1.
 */
void hdr_select_metadata_receiver(unsigned char mode)
{
    /* Step 1: clear the bit in all four receivers. */
    hdmi_reg_update_bits(0, 0x7e, 0x80, 0);
    hdmi_reg_update_bits(1, 0x7e, 0x80, 0);
    hdmi_rx21_reg_update_bits(0, 0x9c9, 1, 0);
    hdmi_rx21_reg_update_bits(1, 0x9c9, 1, 0);
    /* Step 2: per mode, the routines and registers of that receiver kind. */
    if (mode == HDR_META_HDMI20_RX0) {
        hdr_meta_source_mode = HDR_META_HDMI20_RX0;
        hdr_meta_reg_read_fn = (rd_fn)hdmi_reg_read8;
        hdr_meta_reg_write_fn = hdr_meta_reg_write_fn_copy = hdmi_reg_write8;
        hdr_meta_reg_modify_fn = hdmi_reg_update_bits;
        hdr_meta_receiver_index = 0;
        hdr_meta_status_reg = 0x7c;
        hdr_meta_ready_mask = 0x80;
        hdr_meta_reg_byte0 = 0x263;
        hdr_meta_reg_byte1 = 0x264;
        hdr_meta_reg_byte2 = 0x265;
        hdr_meta_reg_byte3 = 0x266;
        hdr_meta_reg_modify_fn(hdr_meta_receiver_index, 0x7e, 0x80, 1);
        hdr_meta_reg_modify_fn(hdr_meta_receiver_index, 0x79, 0x80, 1);
    } else if (mode == HDR_META_HDMI20_RX1) {
        hdr_meta_source_mode = HDR_META_HDMI20_RX1;
        hdr_meta_reg_read_fn = (rd_fn)hdmi_reg_read8;
        hdr_meta_reg_write_fn = hdr_meta_reg_write_fn_copy = hdmi_reg_write8;
        hdr_meta_reg_modify_fn = hdmi_reg_update_bits;
        hdr_meta_receiver_index = 1;
        hdr_meta_status_reg = 0x7c;
        hdr_meta_ready_mask = 0x80;
        hdr_meta_reg_byte0 = 0x263;
        hdr_meta_reg_byte1 = 0x264;
        hdr_meta_reg_byte2 = 0x265;
        hdr_meta_reg_byte3 = 0x266;
        hdr_meta_reg_modify_fn(hdr_meta_receiver_index, 0x7e, 0x80, 1);
        hdr_meta_reg_modify_fn(hdr_meta_receiver_index, 0x79, 0x80, 1);
    } else if (mode == HDR_META_HDMI21_RX0) {
        hdr_meta_source_mode = HDR_META_HDMI21_RX0;
        hdr_meta_reg_read_fn = (rd_fn)hdmi_rx21_reg_read8;
        hdr_meta_reg_write_fn = hdr_meta_reg_write_fn_copy = hdmi_rx21_reg_write8;
        hdr_meta_reg_modify_fn = hdmi_rx21_reg_update_bits;
        hdr_meta_receiver_index = 0;
        hdr_meta_status_reg = 0x9c8;
        hdr_meta_ready_mask = 1;
        hdr_meta_reg_byte0 = 0x404;
        hdr_meta_reg_byte1 = 0x405;
        hdr_meta_reg_byte2 = 0x406;
        hdr_meta_reg_byte3 = 0x407;
        hdr_meta_reg_modify_fn(hdr_meta_receiver_index, 0x9c9, 1, 1);
        hdr_meta_reg_modify_fn(hdr_meta_receiver_index, 0x391, 1, 1);
    } else if (mode == HDR_META_HDMI21_RX1) {
        hdr_meta_source_mode = HDR_META_HDMI21_RX1;
        hdr_meta_reg_read_fn = (rd_fn)hdmi_rx21_reg_read8;
        hdr_meta_reg_write_fn = hdr_meta_reg_write_fn_copy = hdmi_rx21_reg_write8;
        hdr_meta_reg_modify_fn = hdmi_rx21_reg_update_bits;
        hdr_meta_receiver_index = 1;
        hdr_meta_status_reg = 0x9c8;
        hdr_meta_ready_mask = 1;
        hdr_meta_reg_byte0 = 0x404;
        hdr_meta_reg_byte1 = 0x405;
        hdr_meta_reg_byte2 = 0x406;
        hdr_meta_reg_byte3 = 0x407;
        hdr_meta_reg_modify_fn(hdr_meta_receiver_index, 0x9c9, 1, 1);
        hdr_meta_reg_modify_fn(hdr_meta_receiver_index, 0x391, 1, 1);
    } else if (mode == HDR_META_INDIRECT_RX0) {
        hdr_meta_source_mode = HDR_META_INDIRECT_RX0;
        hdr_meta_reg_read_fn = (rd_fn)reg_read_port_indirect;
        hdr_meta_receiver_index = 0;
        hdr_meta_status_reg = 5;
        hdr_meta_ready_mask = 0x20;
    } else if (mode == HDR_META_INDIRECT_RX1) {
        hdr_meta_source_mode = HDR_META_INDIRECT_RX1;
        hdr_meta_reg_read_fn = (rd_fn)reg_read_port_indirect;
        hdr_meta_receiver_index = 1;
        hdr_meta_status_reg = 5;
        hdr_meta_ready_mask = 0x20;
    }
}
