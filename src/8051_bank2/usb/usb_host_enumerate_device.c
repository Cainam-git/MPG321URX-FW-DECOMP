/* usb_host_enumerate_device  (FUN_CODE_467e)
 *
 * Enumerate the attached USB device and return its interface class.
 * Returns: bytes 0x0E and 0x10 of the 0x20-byte configuration reply: interface class and protocol
 * Note: Class 8 runs the Bulk-Only start-up commands, class 9 the hub set-up, class 3 (HID in the USB
 *   standard) usb_host_init_async_list.
 * Name basis: derived - queue heads (8f9b x4), control transfers, address, Bulk-Only command; returns config
 *   bytes 14/16
 *
 * Matching notes
 * --------------
 * 8051_bank2 module FUN_CODE_467e, one Keil C51 module compiled with OPTIMIZE(8,SPEED) LARGE, hand-written.
 * It is one file because Keil OPTIMIZE(8) "reuse of common entry code" builds one block in front of a callee from the
 * call sites it sees in the same module; every function that enters one of these blocks is defined here:
 *   0xE35B..0xE373 -> e373 (users 5219, 69e5, 76b4, 8a0e, 94d3, d2fb, cbd9, cca2, d4b2)
 *   0xE17C..0xE1A4 -> e1a4 (users 5219, 69e5, 76b4, 8a0e, 94d3, b97a, 467e)
 *   0x9981..0x999F -> 999f (cbd9, cca2, d4b2)        0x9B8D -> 9b91 (69e5, d2fb, 467e)
 *   0xDAC1 -> dac5 (467e, 8f9b, b45f, b97a)           0xDDB7 -> ddbb (69e5, b97a)
 *   0xB308 -> b317 (467e)                             0x8A08 -> 8a0e (76b4)
 *   0x69C3..0x69E5 -> 69e5 (5219, 8a0e)               0x5200..0x5219 -> 5219 (ba96)
 *   0x8F95 -> 8f9b (467e)                             0x7677..0x76B4 -> 76b4 (467e, 9734)
 *   0xE1EB..0xE1F3 -> e1f3 (467e x4, 9734, c60e: e1f3(&usb_port_record, 0x27))
 * A block holds the instructions that the call sites share in front of the LCALL, including the tail of the statement
 * before the call (the 76b4 block stores the command fields addr, n, id and st; the e35b entry stores the local
 * 0x0907 of 5219). LJMP (tail) call sites are never merged (c60e, b45f's last dac5 call, 94d3's last e1a4 call).
 * Definition order matters: for each callee Keil merges only the FIRST call site whose count argument differs from the
 * block's (A loaded before MOV DPTR,#098AH), so 69e5 is defined first (its first e373(b, 2) and e1a4(b, 2) enter at
 * 0xE36F / 0xE1A0); dac5 is defined after b45f (otherwise Keil knows R5 survives the first dac5 call and drops
 * b45f's second 'MOV R5,#2').
 * Source forms the bytes depend on (each checked against the alternatives):
 *   - Masked field updates are written 'x = x & keep | v & mask' with the operand Keil must evaluate first on the
 *     side the firmware evaluates first; '(v << 0) & mask' (a field written with shift 0, 8a0e off and b45f v) makes
 *     Keil evaluate it before the record load as the firmware does.
 *   - '(x | 0x80) % 0x100' / '(x & 0x7f) % 0x100' on the status byte (94d3, 69e5): the '% 0x100' emits no code; it
 *     keeps Keil from commuting the constant operand (MOV A,@R0 / ORL A,#80H as in the firmware instead of
 *     MOV A,#80H / ORL A,@R0).
 *   - Length into byte_count (8a0e w, 5219 n0..n2): computed into its own unsigned int local before the update, one
 *     local per switch arm (a local shared by two arms is given an XDATA home by Keil).
 *   - '(unsigned int)(b - 1)' and '(unsigned int)a * 2UL' (?C?LIMUL) for the record offsets; d2fb's n is a local set
 *     to 1 (Keil keeps it in R7 and folds the load: MOV A,#1 / ADD A,#0FFH).
 *   - 76b4 tests 'len > avail' twice (the firmware compares again inside the loop).
 *   - ba96 leaves its loop with break (shared 'MOV R7,#0 / RET'); 467e returns iface from every exit, set or not.
 *   - 467e uses one local i for the record loop, the speed flag, the wait count and the retry count.
 *   - b97a sets its local p (0x0902) to DATA 0x0022 and never reads it (the firmware has the three stores).
 *   - Locals that a common-entry block reads have names unique in the module (tda, qha, tdb, qhb, tdc, qhc, cur, dst,
 *     nxt) so the judge resolves the block operands to the right function.
 * Judge keys this file needs in symbols/8051_bank2.libs.json besides the learned ones: ?usb_read_port_status_record?XD = 0x08EB (r is
 * only addressed with #LOW / #HIGH).
 */

/* USB host routines of the update agent: register access through the controller's register window, block moves
 * between the port memory and the block buffer, transfer records and queue heads, control transfers, Bulk-Only disk
 * commands and the enumeration of a plugged-in device.
 *
 * Port memory addresses count 32-byte blocks; the record words and the registers hold such an address shifted left
 * by 5. Every record is changed the same way: read its blocks into the block buffer at DATA 0x0022
 * (usb_port_read_blocks), change fields through one of the two DATA pointers that point at that buffer, write the
 * blocks back (usb_port_write_blocks). */

/* A transfer record: one block in the port memory, seen through usb_port_mem_addrs.td_view. */
struct usb_td {
    unsigned long next_link;     /* +0: bits 5..31 next record; bit 0 set = last record (69e5 walks the chain to it) */
    unsigned long alt_link;      /* +4: second link word, same layout */
    unsigned int byte_count;     /* +8: bits 0..14 byte count; bit 15 set by the data and status stages of 5219 */
    unsigned char kind_bits;     /* +10: bits 0..1 stage kind (XFER_KIND_*); bits 2..3 and bit 7 set at set-up */
    unsigned char status;        /* +11: bit 7 (TD_STATUS_ACTIVE) set to start; the routines wait until it is clear */
    unsigned long page[5];       /* +12..+31: buffer words, bits 12..31 address; bits 0..11 of page[0] = offset */
};
/* A queue head: two blocks in the port memory (28 bytes used), seen through usb_queue_head_ptr. Queue q starts at
 * usb_port_mem_addrs.qh_block + 2 * q. */
struct usb_qh {
    unsigned long link;          /* +0: bits 5..31 next queue head; bits 1..2 link type (8f9b typ); bit 0 */
    unsigned int packet_word;    /* +4: bits 0..10 max packet size; bit 11 set when register 0x80 bit 23 is clear */
    unsigned char endpoint_bits; /* +6: bits 0..3 endpoint, bits 4..5 speed code from register 0x80, bit 6, bit 7 */
    unsigned char address_bits;  /* +7: bits 0..6 device address */
    unsigned char b8; unsigned char b9; unsigned char b10;
    unsigned char b11;           /* set to 0xFF by 94d3 */
    unsigned long w12;
    unsigned long td_link;       /* +16: bits 5..31 current transfer record (69e5 starts there); bit 0 */
    unsigned long td_alt_link;   /* +20: second record link, same layout */
    unsigned char b24; unsigned char b25; unsigned char b26;
    unsigned char b27;           /* cleared by 69e5 after each transfer */
};
/* XDATA 0x08BC, filled by usb_select_controller and usb_host_init_controller for the selected port. */
struct usb_port_addrs {
    struct usb_td idata *td_view; /* DATA pointer to the block buffer (DATA 0x0022) */
    unsigned long buffer_block;  /* 0x08BD: port base + 0x280; setup packets, command blocks and replies */
    unsigned long qh_block;      /* 0x08C1: buffer_block + 0x20; the four queue heads */
    unsigned long td_block;      /* 0x08C5: qh_block + 8; the transfer records, one block each */
    unsigned long mem_base;      /* 0x08C9: memory base shared by both ports */
};
/* XDATA 0x075C: the disk command of the selected port (0x27 bytes), filled by the callers of 76b4. */
struct usb_disk_cmd {
    unsigned long id;            /* bit 31 toggled before every command */
    unsigned char st;
    unsigned char cblen;         /* copied to the command block */
    unsigned char dir;           /* CMD_DIR_TO_DEVICE: data on ep_out; CMD_DIR_FROM_DEVICE: data on ep_in */
    unsigned char cb[16];        /* command bytes; cb[0] = command code */
    unsigned long len;           /* data bytes; 0 = no data stage */
    unsigned long addr;          /* byte address of the data in the port memory */
    unsigned int n;
    unsigned char r7d[3];
    unsigned int res;            /* 0x0780: low byte of word 3 of the block read back after the command */
    unsigned char r82;
};
/* XDATA 0x082A: command block sent ahead of every disk command (0x2E bytes), plus the two queue numbers. */
struct usb_cmd_block {
    unsigned long sig;           /* 0x55534243 */
    unsigned long tag;           /* from XDATA 0x08DE, raised by 1 after every command */
    unsigned long len;
    unsigned char flags;         /* 0 = data to the device, 0x80 = data from the device */
    unsigned char lun;
    unsigned char cblen;
    unsigned char cb[16];
    unsigned char pad[13];
    unsigned char ep_in;         /* queue that receives data from the device (2 or 3) */
    unsigned char ep_out;        /* queue that sends data to the device (3 or 2) */
};
/* XDATA 0x07D9: ten 8-byte setup packets (start values in the start-up data at CODE 0xC397..0xC3E6:
 * SETUP_* below). Byte 6 is the length usb_host_control_xfer is given. */
struct usb_setup { unsigned char b[8]; };
/* Return value of usb_host_enumerate_device: bytes 0x0E and 0x10 of the 0x20-byte reply to SETUP_GET_CONFIG. */
struct usb_iface_id { unsigned char class_code; unsigned char protocol; };
struct usb_status8 { unsigned char b[8]; };
extern struct usb_port_addrs xdata usb_port_mem_addrs;
extern struct usb_qh idata * xdata usb_queue_head_ptr;
extern struct usb_disk_cmd xdata usb_port_record;
extern struct usb_cmd_block xdata usb_port_xfer_record;
extern struct usb_setup xdata usb_setup_packets[10];
extern unsigned char data usb_block_buffer[];
extern unsigned long xdata usb_port_mem_base;
extern unsigned long xdata fwupd_dram_address;
extern unsigned long xdata usb_port_list_block;
extern unsigned long xdata usb_msc_command_tag;
extern unsigned char xdata usb_control_reply;
extern unsigned char xdata usb_port_index;
extern unsigned char xdata usb_next_device_address[2];
extern unsigned char xdata usb_port_error_counts[];
extern unsigned char xdata usb_port_bytes[3];
extern unsigned char xdata reg_usb0_reg_cmd, reg_usb0_reg_index, reg_usb0_wdata0, reg_usb0_wdata1, reg_usb0_wdata2, reg_usb0_wdata3;
extern unsigned char xdata reg_usb0_rdata0, reg_usb0_rdata1, reg_usb0_rdata2, reg_usb0_rdata3;
extern unsigned char xdata reg_usb1_reg_cmd, reg_usb1_reg_index, reg_usb1_wdata0, reg_usb1_wdata1, reg_usb1_wdata2, reg_usb1_wdata3;
extern unsigned char xdata reg_usb1_rdata0, reg_usb1_rdata1, reg_usb1_rdata2, reg_usb1_rdata3;
extern unsigned char xdata reg_fwupd_mailbox_f19a, reg_fwupd_mailbox_f19b, reg_fwupd_mailbox_f19c, reg_fwupd_mailbox_f19d, reg_fwupd_mailbox_f19e, reg_fwupd_mailbox_f19f;
extern unsigned char xdata reg_fwupd_progress;
extern void usb_port_read_blocks_buf(unsigned char *buf, unsigned long addr, unsigned char n, unsigned char f) small;
extern void usb_port_write_blocks_buf(unsigned char *buf, unsigned long addr, unsigned char n, unsigned char f) small;
extern void lib_printf517(void *fmt, ...) large;
extern void usb_port_copy_blocks(unsigned long a, unsigned long b, unsigned char n);
extern unsigned char usb_get_port_error_count(void);
extern void usb_clear_port_error_count(void);
extern void dbg_dump_block_words(unsigned long addr, unsigned char n);
extern void reg_window_set_bits32(unsigned int reg, unsigned long mask);
extern void timer_delay_units(unsigned char n);
extern unsigned char reg_window_get_reg30_bit0(void);
extern void usb_host_init_controller(void);
extern unsigned char fwupd_find_update_file(unsigned char m);
void usb_port_read_blocks(unsigned long addr, unsigned char n);
void usb_port_write_blocks(unsigned long addr, unsigned char n);
void lib_fill_data_buffer(unsigned char val, unsigned char n);
void lib_swap_word_bytes(unsigned char *dst, unsigned char *src, unsigned char len);
unsigned long reg_window_read32(unsigned int reg);
void reg_window_write32(unsigned int reg, unsigned long v);
void reg_window_clear_bits32(unsigned int reg, unsigned long mask);
void usb_disk_read_to_xdata(unsigned long addr, unsigned char *buf, unsigned long n);
void fwupd_read_file_block(unsigned long a, unsigned char *p);
struct usb_status8 usb_read_port_status_record(void);
void usb_port_read_sector_swapped(unsigned char k, unsigned char *p);
void usb_host_set_device_address(unsigned char v);
void usb_host_init_async_list(void);
unsigned char usb_host_scan_hub_ports(void);
void usb_host_update_xfer_records(unsigned char a, unsigned char b);
unsigned char usb_host_bulk_transfer(unsigned char a, unsigned int n, unsigned long *buf, unsigned long off, unsigned char f);
void usb_msc_run_command(void);
void usb_host_run_transfer(unsigned long a, unsigned long b);
void usb_host_control_xfer(unsigned char a, unsigned char *p, unsigned int len);
void usb_host_init_queue_head(unsigned long v, unsigned long typ, unsigned long addr, unsigned long h, unsigned long ep, unsigned long mps);
struct usb_iface_id usb_host_enumerate_device(void);
void usb_disk_write_frame_dump(unsigned long a);
void usb_disk_read_blocks(unsigned long a, unsigned long b, unsigned long c);
void lib_clear_bytes(unsigned char *p, unsigned char n);

/* Controller registers reached through the register window (reg_window_read32 / reg_window_write32). */
#define REG_10                0x10      /* bit 5 cleared before and set after a record is linked in */
#define REG_USBSTS            0x14      /* printed as "USBSTS %08lX"; bit 15 is waited on */
#define REG_LIST_ADDR         0x28      /* receives the address of a queue head (block << 5) */
#define REG_80                0x80      /* bits 22 and 23 select speed code and packet sizes */
#define USBSTS_BIT15          0x8000
#define REG80_BIT23           0x800000
#define TD_STATUS_ACTIVE      0x80      /* bit 7 of usb_td.status */
#define XFER_KIND_OUT         0         /* usb_td.kind_bits bits 0..1: data to the device */
#define XFER_KIND_IN          1         /* data from the device */
#define XFER_KIND_SETUP       2         /* the 8-byte setup packet */
#define CMD_DIR_TO_DEVICE     1         /* usb_disk_cmd.dir */
#define CMD_DIR_FROM_DEVICE   2

/* Run the prepared transfer record a on the queue head at b: the contents of a are copied into the queue head's
 * current record (cur), a itself becomes the new last record of the chain, cur is set TD_STATUS_ACTIVE and the
 * routine waits until that bit is clear again. Every wait has a limit; running into one raises the port's error
 * count. */
void usb_host_run_transfer(unsigned long a, unsigned long b)
{
    unsigned long cur;
    unsigned long dst;
    unsigned long nxt;
    unsigned int k;
    /* Stop: clear bit 5 of register 0x10 and wait for bit 15 of the status register to clear. */
    reg_window_clear_bits32(0x10, 0x20);
    k = 0;
    while ((reg_window_read32(0x14) & 0x8000) != 0) {
        k++;
        if (k > 100) {
            usb_port_error_counts[usb_port_index]++;
            break;
        }
    }
    /* Copy record a into the queue head's current record; a is marked as a last record. */
    usb_port_read_blocks(b, 2);
    cur = (usb_queue_head_ptr->td_link & 0xffffffe0) >> 5;
    usb_port_copy_blocks(cur, a, 1);
    dst = a;
    usb_port_read_blocks(dst, 1);
    usb_port_mem_addrs.td_view->next_link = usb_port_mem_addrs.td_view->next_link & 0xfffffffe | 1;
    usb_port_write_blocks(dst, 1);
    /* Walk the chain from the current record to its last record (at most 10 steps). */
    nxt = cur;
    usb_port_read_blocks(nxt, 1);
    k = 0;
    while (!(unsigned char)(usb_port_mem_addrs.td_view->next_link & 1)) {
        nxt = usb_port_mem_addrs.td_view->next_link & 0xffffffe0;
        usb_port_read_blocks(nxt, 1);
        lib_printf517((void code *)0xc973, (unsigned char)(usb_port_mem_addrs.td_view->next_link & 1), nxt);
        k++;
        if (k > 10) {
            usb_port_error_counts[usb_port_index]++;
            break;
        }
    }
    /* Link record a behind it (both link words). */
    usb_port_mem_addrs.td_view->next_link = usb_port_mem_addrs.td_view->next_link & 0x1f | dst << 5 & 0xffffffe0;
    usb_port_mem_addrs.td_view->next_link = usb_port_mem_addrs.td_view->next_link & 0xfffffffe;
    usb_port_mem_addrs.td_view->alt_link = usb_port_mem_addrs.td_view->alt_link & 0x1f | dst << 5 & 0xffffffe0;
    usb_port_mem_addrs.td_view->alt_link = usb_port_mem_addrs.td_view->alt_link & 0xfffffffe;
    usb_port_write_blocks(nxt, 1);
    /* Start again and wait for bit 15 of the status register to be set. */
    reg_window_set_bits32(0x10, 0x20);
    k = 0;
    while ((reg_window_read32(0x14) & 0x8000) == 0) {
        lib_printf517((void code *)0xc99c, reg_window_read32(0x14));
        k++;
        if (k > 10) {
            usb_port_error_counts[usb_port_index]++;
            break;
        }
    }
    /* Hand the current record over and wait until its active bit clears (at most 100 x 5 delay units). */
    usb_port_read_blocks(cur, 1);
    usb_port_mem_addrs.td_view->status = (usb_port_mem_addrs.td_view->status | 0x80) % 0x100;
    usb_port_write_blocks(cur, 1);
    k = 0;
    do {
        timer_delay_units(5);
        usb_port_read_blocks(cur, 1);
        if (usb_port_mem_addrs.td_view->status & 0x80) lib_printf517((void code *)0xc9aa, (unsigned long)usb_port_mem_addrs.td_view->status);
        k++;
        if (k > 100) {
            usb_port_error_counts[usb_port_index]++;
            break;
        }
    } while (usb_port_mem_addrs.td_view->status & 0x80);
    /* Write the status register back with its own value, clear byte 27 of the queue head, reset the current record
     * to an empty last record, stop again. */
    reg_window_write32(0x14, reg_window_read32(0x14));
    usb_port_read_blocks(b, 2);
    usb_queue_head_ptr->b27 = 0;
    usb_port_write_blocks(b, 2);
    lib_fill_data_buffer(0, 1);
    usb_port_mem_addrs.td_view->next_link = usb_port_mem_addrs.td_view->next_link & 0xfffffffe | 1;
    usb_port_mem_addrs.td_view->status = (usb_port_mem_addrs.td_view->status & 0x7f) % 0x100;
    usb_port_mem_addrs.td_view->kind_bits = usb_port_mem_addrs.td_view->kind_bits & 0x7f | 0x80;
    usb_port_mem_addrs.td_view->alt_link = usb_port_mem_addrs.td_view->alt_link & 0xfffffffe | 1;
    usb_port_mem_addrs.td_view->kind_bits = usb_port_mem_addrs.td_view->kind_bits & 0xf3 | 0x0c;
    usb_port_write_blocks(cur, 1);
    reg_window_clear_bits32(0x10, 0x20);
    k = 0;
    while ((reg_window_read32(0x14) & 0x8000) != 0) {
        k++;
        if (k > 10) {
            usb_port_error_counts[usb_port_index]++;
            break;
        }
    }
}

/* Read n blocks at addr into the block buffer. */
void usb_port_read_blocks(unsigned long addr, unsigned char n)
{
    usb_port_read_blocks_buf(usb_block_buffer, addr, n, 0);
}

/* Write n blocks of the block buffer to addr. */
void usb_port_write_blocks(unsigned long addr, unsigned char n)
{
    usb_port_write_blocks_buf(usb_block_buffer, addr, n, 0);
}

/* Copy len bytes, reversing the byte order of every 32-bit word; a last part word is copied as a whole word. */
void lib_swap_word_bytes(unsigned char *dst, unsigned char *src, unsigned char len)
{
    unsigned char i;
    unsigned char j;
    for (i = 0; i < (len >> 2); i++) {
        j = i << 2;
        dst[j] = src[j + 3];
        dst[j + 1] = src[j + 2];
        dst[j + 2] = src[j + 1];
        dst[j + 3] = src[j];
    }
    if (i * 4 < len) {
        j = i << 2;
        dst[j] = src[j + 3];
        dst[j + 1] = src[j + 2];
        dst[j + 2] = src[j + 1];
        dst[j + 3] = src[j];
    }
}

/* Read a 32-bit controller register of the selected port: index, read command 0x40 (+0x10 for registers
 * 0x100..0x1FF), wait at most 10 delay units for bit 0 of the command byte, then take the four data bytes. */
unsigned long reg_window_read32(unsigned int reg)
{
    unsigned char n;
    unsigned long v;
    reg &= 0x01ff;
    if (usb_port_index == 1) {
        reg_usb1_reg_index = reg;
        reg_usb1_reg_cmd = ((reg >> 4) & 0x10) + 0x40;
        n = 10;
        do {
            n--;
            timer_delay_units(1);
        } while (n > 0 && !(reg_usb1_reg_cmd & 1));
        v = reg_usb1_rdata3;
        v = (v << 8) + (unsigned long)reg_usb1_rdata2;
        v = (v << 8) + (unsigned long)reg_usb1_rdata1;
        v = (v << 8) + (unsigned long)reg_usb1_rdata0;
    } else {
        reg_usb0_reg_index = reg;
        reg_usb0_reg_cmd = ((reg >> 4) & 0x10) + 0x40;
        n = 10;
        do {
            n--;
            timer_delay_units(1);
        } while (n > 0 && !(reg_usb0_reg_cmd & 1));
        v = reg_usb0_rdata3;
        v = (v << 8) + (unsigned long)reg_usb0_rdata2;
        v = (v << 8) + (unsigned long)reg_usb0_rdata1;
        v = (v << 8) + (unsigned long)reg_usb0_rdata0;
    }
    return v;
}

/* Write a 32-bit controller register of the selected port: index, four data bytes, write command 0x80 (+0x10 for
 * registers 0x100..0x1FF), wait at most 10 delay units for bit 0 of the command byte. */
void reg_window_write32(unsigned int reg, unsigned long v)
{
    unsigned char n;
    reg &= 0x01ff;
    if (usb_port_index == 1) {
        reg_usb1_reg_index = reg;
        reg_usb1_wdata0 = v;
        reg_usb1_wdata1 = v >> 8;
        reg_usb1_wdata2 = v >> 16;
        reg_usb1_wdata3 = v >> 24;
        reg_usb1_reg_cmd = ((reg >> 4) & 0x10) + 0x80;
        n = 10;
        do {
            n--;
            timer_delay_units(1);
        } while (n > 0 && !(reg_usb1_reg_cmd & 1));
    } else {
        reg_usb0_reg_index = reg;
        reg_usb0_wdata0 = v;
        reg_usb0_wdata1 = v >> 8;
        reg_usb0_wdata2 = v >> 16;
        reg_usb0_wdata3 = v >> 24;
        reg_usb0_reg_cmd = ((reg >> 4) & 0x10) + 0x80;
        n = 10;
        do {
            n--;
            timer_delay_units(1);
        } while (n > 0 && !(reg_usb0_reg_cmd & 1));
    }
}

void reg_window_clear_bits32(unsigned int reg, unsigned long mask)
{
    unsigned long v;
    v = reg_window_read32(reg);
    reg_window_write32(reg, v & ~mask);
}

/* Read n bytes from disk sector addr into the port memory, then copy them block by block into buf, byte order of
 * every word reversed. */
void usb_disk_read_to_xdata(unsigned long addr, unsigned char *buf, unsigned long n)
{
    unsigned int i;
    usb_disk_read_blocks(addr, n, usb_port_mem_base);
    for (i = 0; i < n / 0x20; i++) {
        usb_port_read_blocks(usb_port_mem_base + i, 1);
        lib_swap_word_bytes(buf + (i << 5), usb_block_buffer, 0x20);
    }
}

/* Copy 512-byte block a of the file loaded at mem_base + 0x700 into p (16 blocks, byte order of every word
 * reversed); also stores that load address in fwupd_dram_address. */
void fwupd_read_file_block(unsigned long a, unsigned char *p)
{
    unsigned int i;
    fwupd_dram_address = usb_port_mem_addrs.mem_base + 0x700;
    i = 0;
    do {
        usb_port_read_blocks(fwupd_dram_address + i + a * 0x10, 1);
        lib_swap_word_bytes(p + (i << 5), usb_block_buffer, 0x20);
        i++;
    } while (i < 0x10);
}

/* When the first transfer record is no longer active: return the first 8 bytes of the buffer block (byte order
 * reversed), write the status register back with its own bits and re-arm record 1. Otherwise return 8 zero bytes. */
struct usb_status8 usb_read_port_status_record(void)
{
    struct usb_status8 r;
    unsigned char i;
    unsigned char n;
    for (i = 0; i < 8; i++) r.b[i] = 0;
    n = 1;
    usb_port_read_blocks(usb_port_mem_addrs.td_block + (unsigned int)(n - 1), 1);
    if (!(usb_port_mem_addrs.td_view->status & 0x80)) {
        dbg_dump_block_words(usb_port_mem_addrs.buffer_block, 1);
        usb_port_read_blocks(usb_port_mem_addrs.buffer_block, 1);
        lib_swap_word_bytes(r.b, usb_block_buffer, 8);
        reg_window_set_bits32(0x14, reg_window_read32(0x14));
        usb_host_update_xfer_records(1, 1);
    }
    return r;
}

/* Copy 512 bytes (16 blocks at usb_port_mem_base + 16 * k) into p, byte order of every word reversed. */
void usb_port_read_sector_swapped(unsigned char k, unsigned char *p)
{
    unsigned int i;
    for (i = 0; i < 0x10; i++) {
        usb_port_read_blocks(usb_port_mem_base + i + k * 0x10, 1);
        lib_swap_word_bytes(p + (i << 5), usb_block_buffer, 0x20);
    }
}

/* Store device address v in all four queue heads. */
void usb_host_set_device_address(unsigned char v)
{
    usb_port_read_blocks(usb_port_mem_addrs.qh_block, 2);
    usb_queue_head_ptr->address_bits = usb_queue_head_ptr->address_bits & 0x80 | (v << 0) & 0x7f;
    usb_port_write_blocks(usb_port_mem_addrs.qh_block, 2);
    usb_port_read_blocks(usb_port_mem_addrs.qh_block + 2, 2);
    usb_queue_head_ptr->address_bits = usb_queue_head_ptr->address_bits & 0x80 | (v << 0) & 0x7f;
    usb_port_write_blocks(usb_port_mem_addrs.qh_block + 2, 2);
    usb_port_read_blocks(usb_port_mem_addrs.qh_block + 4, 2);
    usb_queue_head_ptr->address_bits = usb_queue_head_ptr->address_bits & 0x80 | (v << 0) & 0x7f;
    usb_port_write_blocks(usb_port_mem_addrs.qh_block + 4, 2);
    usb_port_read_blocks(usb_port_mem_addrs.qh_block + 6, 2);
    usb_queue_head_ptr->address_bits = usb_queue_head_ptr->address_bits & 0x80 | (v << 0) & 0x7f;
    usb_port_write_blocks(usb_port_mem_addrs.qh_block + 6, 2);
    lib_fill_data_buffer(0, 2);
    lib_fill_data_buffer(0, 2);
}

/* Reset transfer record 1 and queue 0, point register 0x24 at the list block (XDATA 0x08B4) and fill its 16 words
 * (first word: queue 0 with low bits 2, the others with low bits 3), clear the buffer block and set the register
 * 0x10 bits. */
void usb_host_init_async_list(void)
{
    unsigned char i;
    unsigned char *p;
    p = usb_block_buffer;
    usb_host_update_xfer_records(0, 1);
    reg_window_write32(0x24, usb_port_list_block << 5);
    lib_fill_data_buffer(0, 2);
    ((unsigned long data *)usb_block_buffer)[0] = usb_port_mem_addrs.qh_block << 5 | 2;
    for (i = 1; i < 0x10; i++) ((unsigned long data *)usb_block_buffer)[i] = usb_port_mem_addrs.qh_block << 5 | 3;
    for (i = 0; i < 0x10; i++) usb_port_write_blocks(usb_port_list_block + i * 2, 2);
    lib_fill_data_buffer(0, 1);
    usb_port_write_blocks(usb_port_mem_addrs.buffer_block, 1);
    reg_window_clear_bits32(0x10, 0xd);
    reg_window_write32(0x1c, 0);
    reg_window_write32(0x10, reg_window_read32(0x10) & 0xfff0ffff | 0x80019);
}

/* Behind a hub: for hub ports n = 1..4 send setup packets 8 and 7 (byte 4 = n) and 6, and enumerate the device
 * when the 4-byte reply reads 3, 5; returns 1 as soon as one device of interface class 8 / 0x50 holds the update
 * file. Stops when bit 0 of register 0x30 is clear. */
unsigned char usb_host_scan_hub_ports(void)
{
    struct usb_iface_id r;
    unsigned char *p;
    unsigned char n;
    unsigned char f;
    f = 1;
    p = &usb_control_reply;
    n = 1;
    do {
        if (f == 1) {
            usb_host_init_controller();
            usb_host_enumerate_device();
            f = 0;
        }
        usb_setup_packets[8].b[2] = 8;
        usb_setup_packets[8].b[4] = n;
        usb_host_control_xfer(0, usb_setup_packets[8].b, usb_setup_packets[8].b[6]);
        usb_setup_packets[8].b[2] = 0x16;
        usb_host_control_xfer(0, usb_setup_packets[8].b, usb_setup_packets[8].b[6]);
        if (!reg_window_get_reg30_bit0()) break;
        usb_setup_packets[8].b[2] = 4;
        usb_host_control_xfer(0, usb_setup_packets[8].b, usb_setup_packets[8].b[6]);
        usb_setup_packets[7].b[4] = n;
        usb_setup_packets[6].b[4] = n;
        usb_setup_packets[7].b[2] = 0x10;
        usb_host_control_xfer(0, usb_setup_packets[7].b, usb_setup_packets[7].b[6]);
        if (!reg_window_get_reg30_bit0()) break;
        usb_setup_packets[7].b[2] = 4;
        usb_host_control_xfer(0, usb_setup_packets[7].b, usb_setup_packets[7].b[6]);
        usb_host_control_xfer(0, usb_setup_packets[6].b, usb_setup_packets[6].b[6]);
        if (!reg_window_get_reg30_bit0()) break;
        usb_setup_packets[7].b[2] = 0x14;
        usb_host_control_xfer(0, usb_setup_packets[7].b, usb_setup_packets[7].b[6]);
        usb_host_control_xfer(0, usb_setup_packets[6].b, usb_setup_packets[6].b[6]);
        if (p[0] == 3 && p[1] == 5) {
            r = usb_host_enumerate_device();
            if (r.class_code == 8 && r.protocol == 0x50) {
                if (fwupd_find_update_file(0)) return 1;
            }
            f = 1;
        }
        if (!reg_window_get_reg30_bit0()) break;
        n++;
    } while (n < 5);
    return 0;
}

/* Re-arm transfer record b - 1 (byte count 8, first page = buffer block, TD_STATUS_ACTIVE) and point the record
 * links of queue head b - 1 at record 0. a = 0 also sets both link words and the kind bits of the record and the
 * link, endpoint, address and packet bits of the queue head. */
void usb_host_update_xfer_records(unsigned char a, unsigned char b)
{
    unsigned long tdb;
    unsigned long qhb;
    tdb = usb_port_mem_addrs.td_block + (unsigned int)(b - 1);
    usb_port_read_blocks(tdb, 1);
    if (a == 0) {
        usb_port_mem_addrs.td_view->next_link = usb_port_mem_addrs.td_view->next_link & 0xfffffffe | 1;
        usb_port_mem_addrs.td_view->alt_link = usb_port_mem_addrs.td_view->alt_link & 0xfffffffe | 1;
        usb_port_mem_addrs.td_view->kind_bits = usb_port_mem_addrs.td_view->kind_bits & 0xfc | 1;
        usb_port_mem_addrs.td_view->kind_bits = usb_port_mem_addrs.td_view->kind_bits & 0x7f | 0x80;
    }
    usb_port_mem_addrs.td_view->byte_count = usb_port_mem_addrs.td_view->byte_count & 0x8000 | 8;
    usb_port_mem_addrs.td_view->page[0] &= 0xfffff000;
    usb_port_mem_addrs.td_view->page[0] = usb_port_mem_addrs.td_view->page[0] & 0xfff | usb_port_mem_addrs.buffer_block << 5 & 0xfffff000;
    usb_port_mem_addrs.td_view->status = (usb_port_mem_addrs.td_view->status | 0x80) % 0x100;
    usb_port_write_blocks(tdb, 1);
    qhb = usb_port_mem_addrs.qh_block + (unsigned int)(b - 1) * 2UL;
    usb_port_read_blocks(qhb, 2);
    if (a == 0) {
        usb_queue_head_ptr->link = usb_queue_head_ptr->link & 0xfffffffe | 1;
        usb_queue_head_ptr->endpoint_bits = usb_queue_head_ptr->endpoint_bits & 0xf0 | 1;
        usb_queue_head_ptr->address_bits = usb_queue_head_ptr->address_bits & 0x80 | 3;
        usb_queue_head_ptr->b11 = 0xff;
        usb_queue_head_ptr->packet_word &= 0xf7ff;
    }
    usb_queue_head_ptr->td_link = usb_queue_head_ptr->td_link & 0x1f | usb_port_mem_addrs.td_block << 5 & 0xffffffe0;
    usb_queue_head_ptr->td_alt_link = usb_queue_head_ptr->td_alt_link & 0x1f | usb_port_mem_addrs.td_block << 5 & 0xffffffe0;
    usb_queue_head_ptr->td_link = usb_queue_head_ptr->td_link & 0xfffffffe;
    usb_queue_head_ptr->td_alt_link = usb_queue_head_ptr->td_alt_link & 0xfffffffe;
    usb_port_write_blocks(qhb, 2);
}

/* Move n bytes on queue a (2 or 3): the record used is td_block + the port byte of that queue (usb_port_bytes[1]
 * for queue 2, [2] for queue 3; it steps between 4/5 and 6/7 after every transfer); buf holds five page words, off
 * the offset in the first page; f = 1 marks the record XFER_KIND_IN, f = 0 XFER_KIND_OUT. Always returns 0. */
unsigned char usb_host_bulk_transfer(unsigned char a, unsigned int n, unsigned long *buf, unsigned long off, unsigned char f)
{
    unsigned char *q;
    unsigned long tdc;
    unsigned long qhc;
    unsigned int w;
    if (a == 2) q = &usb_port_bytes[1];
    else q = &usb_port_bytes[2];
    tdc = usb_port_mem_addrs.td_block + *q;
    qhc = usb_port_mem_addrs.qh_block + (unsigned int)a * 2UL;
    usb_port_read_blocks(tdc, 1);
    w = n & 0x7fff;
    usb_port_mem_addrs.td_view->byte_count = w | usb_port_mem_addrs.td_view->byte_count & 0x8000;
    usb_port_mem_addrs.td_view->page[0] = usb_port_mem_addrs.td_view->page[0] & 0xfff | *buf++ & 0xfffff000;
    usb_port_mem_addrs.td_view->page[0] = usb_port_mem_addrs.td_view->page[0] & 0xfffff000 | (off << 0) & 0xfff;
    usb_port_mem_addrs.td_view->page[1] = usb_port_mem_addrs.td_view->page[1] & 0xfff | *buf++ & 0xfffff000;
    usb_port_mem_addrs.td_view->page[2] = usb_port_mem_addrs.td_view->page[2] & 0xfff | *buf++ & 0xfffff000;
    usb_port_mem_addrs.td_view->page[3] = usb_port_mem_addrs.td_view->page[3] & 0xfff | *buf++ & 0xfffff000;
    usb_port_mem_addrs.td_view->page[4] = usb_port_mem_addrs.td_view->page[4] & 0xfff | *buf++ & 0xfffff000;
    if (f) usb_port_mem_addrs.td_view->kind_bits = usb_port_mem_addrs.td_view->kind_bits & 0xfc | 1;
    else usb_port_mem_addrs.td_view->kind_bits &= 0xfc;
    usb_port_write_blocks(tdc, 1);
    usb_host_run_transfer(tdc, qhc);
    if (*q == 4 || *q == 6) (*q)++;
    else (*q)--;
    return 0;
}

/* Run the disk command in usb_port_record: build the 0x1F-byte command block in usb_port_xfer_record, send it on
 * ep_out from the buffer block, move the data (up to five 4 KB pages from addr; more prints "OOR" and stops for
 * good), read the 0x1F-byte answer on ep_in into the buffer block and keep its byte in res. */
void usb_msc_run_command(void)
{
    unsigned long pg[5];
    unsigned char i;
    unsigned long len;
    unsigned long avail;
    unsigned long off;
    usb_port_xfer_record.sig = 0x55534243;
    lib_swap_word_bytes((unsigned char *)&usb_port_xfer_record.len, (unsigned char *)&usb_port_record.len, 4);
    usb_port_xfer_record.tag = usb_msc_command_tag;
    switch (usb_port_record.dir) {
    case 1:
        usb_port_xfer_record.flags = 0;
        break;
    case 2:
        usb_port_xfer_record.flags = 0x80;
        break;
    }
    usb_port_xfer_record.lun = 0;
    usb_port_xfer_record.cblen = usb_port_record.cblen;
    for (i = 0; i < 0x10; i++) usb_port_xfer_record.cb[i] = usb_port_record.cb[i];
    /* Command block out. */
    usb_port_read_blocks(usb_port_mem_addrs.buffer_block, 1);
    lib_swap_word_bytes(usb_block_buffer, (unsigned char *)&usb_port_xfer_record, sizeof(usb_port_xfer_record));
    usb_port_write_blocks(usb_port_mem_addrs.buffer_block, 1);
    pg[0] = usb_port_mem_addrs.buffer_block << 5;
    pg[1] = 0;
    pg[2] = 0;
    pg[3] = 0;
    pg[4] = 0;
    usb_host_bulk_transfer(usb_port_xfer_record.ep_out, 0x1f, pg, 0, 0);
    /* Data stage: one page word per 4 KB the data reaches into. */
    if (usb_port_record.len > 0) {
        len = usb_port_record.len;
        pg[0] = usb_port_record.addr & 0xfffff000;
        off = usb_port_record.addr & 0xfff;
        avail = 0x1000 - off;
        i = 1;
        while (len > avail) {
            if (len > avail) {
                if (i < 5) {
                    pg[i] = pg[i - 1] + 0x1000;
                } else {
                    lib_printf517((void code *)0xc9c4);
                    for (;;) ;
                }
            }
            len -= avail;
            avail = 0x1000;
            i++;
        }
        switch (usb_port_record.dir) {
        case 1:
            usb_host_bulk_transfer(usb_port_xfer_record.ep_out, (unsigned int)usb_port_record.len, pg, off, 0);
            break;
        case 2:
            usb_host_bulk_transfer(usb_port_xfer_record.ep_in, (unsigned int)usb_port_record.len, pg, off, 1);
            break;
        }
    }
    /* Answer in. */
    usb_port_read_blocks(usb_port_mem_addrs.buffer_block, 1);
    lib_swap_word_bytes(usb_block_buffer, (unsigned char *)&usb_port_xfer_record, sizeof(usb_port_xfer_record));
    usb_port_write_blocks(usb_port_mem_addrs.buffer_block, 1);
    pg[0] = usb_port_mem_addrs.buffer_block << 5;
    pg[1] = 0;
    pg[2] = 0;
    pg[3] = 0;
    pg[4] = 0;
    usb_host_bulk_transfer(usb_port_xfer_record.ep_in, 0x1f, pg, 0, 1);
    usb_port_read_blocks(usb_port_mem_addrs.buffer_block, 1);
    usb_port_record.res = (unsigned char)((unsigned long data *)usb_block_buffer)[3];
    usb_msc_command_tag = usb_msc_command_tag + 1;
}

/* Run one control transfer on queue a with the 8-byte setup packet p: the setup stage from the buffer block, then by
 * p[1] a data stage of len bytes from the device (copied, word bytes reversed, to XDATA 0x071B) and a status stage,
 * or that data stage only, or (p[1] = 7) two more stages whose records are written to the buffer block.
 * usb_port_bytes[0] alternates between the two records (0 / 1) of queue a. */
void usb_host_control_xfer(unsigned char a, unsigned char *p, unsigned int len)
{
    unsigned long tda;
    unsigned long qha;
    unsigned int n0;
    unsigned int n1;
    unsigned int n2;
    /* Setup stage. */
    lib_fill_data_buffer(0, 1);
    lib_swap_word_bytes(usb_block_buffer, p, 8);
    usb_port_write_blocks(usb_port_mem_addrs.buffer_block, 1);
    tda = usb_port_mem_addrs.td_block + (unsigned int)(usb_port_bytes[0] + a * 2);
    usb_port_read_blocks(tda, 1);
    usb_port_mem_addrs.td_view->kind_bits = usb_port_mem_addrs.td_view->kind_bits & 0xfc | 2;
    usb_port_mem_addrs.td_view->byte_count = usb_port_mem_addrs.td_view->byte_count & 0x8000 | 8;
    usb_port_mem_addrs.td_view->byte_count &= 0x7fff;
    usb_port_mem_addrs.td_view->page[0] = usb_port_mem_addrs.td_view->page[0] & 0xfff | usb_port_mem_addrs.buffer_block << 5 & 0xfffff000;
    usb_port_write_blocks(tda, 1);
    qha = usb_port_mem_addrs.qh_block + (unsigned int)a * 2UL;
    usb_host_run_transfer(tda, qha);
    usb_port_bytes[0]++;
    usb_port_bytes[0] &= 1;
    tda = usb_port_mem_addrs.td_block + (unsigned int)(usb_port_bytes[0] + a * 2);
    qha = usb_port_mem_addrs.qh_block + (unsigned int)a * 2UL;
    switch (p[1]) {
    case 0x00:
    case 0x06:
    case 0x08:
    case 0x0a:
    case 0xfe:
        /* Data from the device, then the status stage. */
        usb_port_read_blocks(tda, 1);
        usb_port_mem_addrs.td_view->kind_bits = usb_port_mem_addrs.td_view->kind_bits & 0xfc | 1;
        n0 = len & 0x7fff;
        usb_port_mem_addrs.td_view->byte_count = n0 | usb_port_mem_addrs.td_view->byte_count & 0x8000;
        usb_port_mem_addrs.td_view->byte_count = usb_port_mem_addrs.td_view->byte_count & 0x7fff | 0x8000;
        usb_port_mem_addrs.td_view->page[0] = usb_port_mem_addrs.td_view->page[0] & 0xfff | usb_port_mem_addrs.buffer_block << 5 & 0xfffff000;
        usb_port_write_blocks(tda, 1);
        usb_host_run_transfer(tda, qha);
        usb_port_bytes[0]++;
        usb_port_bytes[0] &= 1;
        tda = usb_port_mem_addrs.td_block + (unsigned int)(usb_port_bytes[0] + a * 2);
        qha = usb_port_mem_addrs.qh_block + (unsigned int)a * 2UL;
        usb_port_read_blocks(usb_port_mem_addrs.buffer_block, 1);
        lib_swap_word_bytes(&usb_control_reply, usb_block_buffer, len);
        usb_port_read_blocks(tda, 1);
        usb_port_mem_addrs.td_view->kind_bits &= 0xfc;
        usb_port_mem_addrs.td_view->byte_count &= 0x8000;
        usb_port_mem_addrs.td_view->byte_count = usb_port_mem_addrs.td_view->byte_count & 0x7fff | 0x8000;
        usb_port_write_blocks(tda, 1);
        usb_host_run_transfer(tda, qha);
        break;
    case 0x01:
    case 0x03:
    case 0x05:
    case 0x09:
    case 0x0b:
    case 0xff:
        /* One more stage marked XFER_KIND_IN with len bytes; no status stage. */
        usb_port_read_blocks(tda, 1);
        usb_port_mem_addrs.td_view->kind_bits = usb_port_mem_addrs.td_view->kind_bits & 0xfc | 1;
        n1 = len & 0x7fff;
        usb_port_mem_addrs.td_view->byte_count = n1 | usb_port_mem_addrs.td_view->byte_count & 0x8000;
        usb_port_mem_addrs.td_view->byte_count = usb_port_mem_addrs.td_view->byte_count & 0x7fff | 0x8000;
        usb_port_mem_addrs.td_view->page[0] = usb_port_mem_addrs.td_view->page[0] & 0xfff | usb_port_mem_addrs.buffer_block << 5 & 0xfffff000;
        usb_port_write_blocks(tda, 1);
        usb_host_run_transfer(tda, qha);
        usb_port_bytes[0]++;
        usb_port_bytes[0] &= 1;
        usb_port_read_blocks(usb_port_mem_addrs.buffer_block, 1);
        lib_swap_word_bytes(&usb_control_reply, usb_block_buffer, len);
        break;
    case 0x07:
        /* Two stages; the edited record is written to the buffer block, not back to tda. */
        usb_port_read_blocks(tda, 1);
        usb_port_mem_addrs.td_view->kind_bits = usb_port_mem_addrs.td_view->kind_bits & 0xfc | 1;
        n2 = len & 0x7fff;
        usb_port_mem_addrs.td_view->byte_count = n2 | usb_port_mem_addrs.td_view->byte_count & 0x8000;
        usb_port_mem_addrs.td_view->byte_count = usb_port_mem_addrs.td_view->byte_count & 0x7fff | 0x8000;
        usb_port_mem_addrs.td_view->page[0] = usb_port_mem_addrs.td_view->page[0] & 0xfff | usb_port_mem_addrs.buffer_block << 5 & 0xfffff000;
        usb_port_write_blocks(usb_port_mem_addrs.buffer_block, 1);
        usb_host_run_transfer(tda, qha);
        usb_port_bytes[0]++;
        usb_port_bytes[0] &= 1;
        tda = usb_port_mem_addrs.td_block + (unsigned int)(usb_port_bytes[0] + a * 2);
        qha = usb_port_mem_addrs.qh_block + (unsigned int)a * 2UL;
        usb_port_read_blocks(tda, 1);
        usb_port_mem_addrs.td_view->kind_bits = usb_port_mem_addrs.td_view->kind_bits & 0xfc | 1;
        usb_port_mem_addrs.td_view->byte_count &= 0x8000;
        usb_port_mem_addrs.td_view->byte_count = usb_port_mem_addrs.td_view->byte_count & 0x7fff | 0x8000;
        usb_port_write_blocks(usb_port_mem_addrs.buffer_block, 1);
        usb_host_run_transfer(tda, qha);
        usb_port_bytes[0]++;
        usb_port_bytes[0] &= 1;
        break;
    }
}

/* Fill queue head v (0..3) in the block buffer: link type typ, device address addr, endpoint ep, max packet size
 * mps, head flag h (bit 7 of endpoint_bits), speed code from register 0x80, bit 6 for queues 0 and 1; its record
 * link points at transfer record 2 * v + 1. The caller sets the link word and writes the two blocks. */
void usb_host_init_queue_head(unsigned long v, unsigned long typ, unsigned long addr, unsigned long h, unsigned long ep, unsigned long mps)
{
    lib_fill_data_buffer(0, 2);
    usb_queue_head_ptr->link = usb_queue_head_ptr->link & 0xfffffffe;
    usb_queue_head_ptr->link = usb_queue_head_ptr->link & 0xfffffff9 | typ << 1 & 6;
    usb_queue_head_ptr->address_bits = usb_queue_head_ptr->address_bits & 0x80 | addr & 0x7f;
    usb_queue_head_ptr->address_bits = usb_queue_head_ptr->address_bits & 0x7f;
    usb_queue_head_ptr->endpoint_bits = usb_queue_head_ptr->endpoint_bits & 0xf0 | ep & 0xf;
    if (reg_window_read32(0x80) & 0x800000) {
        usb_queue_head_ptr->endpoint_bits = usb_queue_head_ptr->endpoint_bits & 0xcf | 0x20;
        usb_queue_head_ptr->packet_word &= 0xf7ff;
    } else {
        usb_queue_head_ptr->packet_word = usb_queue_head_ptr->packet_word & 0xf7ff | 0x800;
        if (reg_window_read32(0x80) & 0x400000) usb_queue_head_ptr->endpoint_bits = usb_queue_head_ptr->endpoint_bits & 0xcf | 0x10;
        else usb_queue_head_ptr->endpoint_bits &= 0xcf;
    }
    if (v == 0 || v == 1) usb_queue_head_ptr->endpoint_bits = usb_queue_head_ptr->endpoint_bits & 0xbf | 0x40;
    else usb_queue_head_ptr->endpoint_bits &= 0xbf;
    usb_queue_head_ptr->endpoint_bits = usb_queue_head_ptr->endpoint_bits & 0x7f | h << 7 & 0x80;
    usb_queue_head_ptr->packet_word = usb_queue_head_ptr->packet_word & 0xf800 | mps & 0x7ff;
    usb_queue_head_ptr->packet_word &= 0x0fff;
    usb_queue_head_ptr->td_link = usb_queue_head_ptr->td_link & 0xfffffffe | 1;
    usb_queue_head_ptr->td_alt_link = usb_queue_head_ptr->td_alt_link & 0xfffffffe | 1;
    usb_queue_head_ptr->td_link = usb_queue_head_ptr->td_link & 0x1f | (usb_port_mem_addrs.td_block + (2 * v + 1)) << 5 & 0xffffffe0;
    usb_queue_head_ptr->td_link = usb_queue_head_ptr->td_link & 0xfffffffe;
}

/* Setup packets (index into XDATA 0x07D9; start bytes as stored in the start-up data). */
#define SETUP_GET_CONFIG      0         /* 80 06 00 02 00 00 08 00; length set to 0x20 here */
#define SETUP_SET_ADDRESS     1         /* 00 05 xx 00 ...: byte 2 = the new device address */
#define SETUP_SET_CONFIG      2         /* 00 09 01 00 00 00 00 00 */
#define SETUP_GET_MAX_LUN     3         /* a1 fe 00 00 00 00 01 00 */
#define SETUP_GET_DEVICE      4         /* 80 06 00 01 00 00 12 00; length set to 8, then to reply byte 0 */
#define SETUP_HUB_CONFIG      9         /* 00 09 01 00 00 00 00 00 (same bytes as packet 2) */
#define SETUP_PACKET_LENGTH   6         /* byte of a setup packet that holds the length */
/* Queue heads: control queues 0 and 1 form one ring, data queues 2 and 3 another. */
#define QUEUE_CONTROL_0       0
#define QUEUE_CONTROL_1       1
#define QUEUE_DATA_2          2
#define QUEUE_DATA_3          3
#define QUEUE_TYPE_1          1         /* typ argument of usb_host_init_queue_head */
#define CONTROL_PACKET_SIZE   8
#define DATA_PACKET_SIZE      0x200
#define DATA_PACKET_SIZE_SLOW 0x40      /* used when register 0x80 bit 23 is clear */
#define DATA_DEVICE_ADDRESS   3         /* address given to queues 2 and 3 at set-up */
#define DEVICE_ADDRESS_STEP   2         /* the port's next address grows by 2 per enumeration */
/* Bytes of the replies in XDATA 0x071B. */
#define DEVICE_REPLY_LENGTH   0         /* length asked for in the second SETUP_GET_DEVICE */
#define DEVICE_REPLY_PACKET   7         /* max packet size of queue 1 */
#define CONFIG_REPLY_LENGTH   0x20
#define CONFIG_REPLY_CLASS    0x0e
#define CONFIG_REPLY_PROTOCOL 0x10
#define CONFIG_REPLY_EP_A     0x14      /* endpoint of queue 2; bit 7 set = queue 2 is ep_in */
#define CONFIG_REPLY_EP_B     0x1b      /* endpoint of queue 3 */
/* Interface classes this routine handles (byte CONFIG_REPLY_CLASS). */
#define IFACE_CLASS_3         3
#define IFACE_CLASS_STORAGE   8
#define IFACE_CLASS_HUB       9
/* Disk commands sent to a class 8 device (cb[0], cblen, bytes asked for). */
#define DISK_CMD_00           0x00      /* 6 bytes, no data; repeated until res = 0 */
#define DISK_CMD_03           0x03      /* 6 bytes, 0x12 bytes of data */
#define DISK_CMD_12           0x12      /* 6 bytes, 0x24 bytes of data */
#define DISK_CMD_25           0x25      /* 10 bytes, 8 bytes of data */
#define DISK_CMD_TRIES        10
#define CMD_ID_TOGGLE         0x80000000

/* usb_host_enumerate_device: set up the selected port's transfer records and queue heads, give the attached device
 * its address, read its replies to the setup packets and prepare it by its interface class.
 *
 * Callers: fwupd_step_port_state (port state 0x83: class 8 / 0x50 leads to mounting the disk, class 3 to states 0xA1
 * / 0xA2 by the protocol byte, class 9 to state 0x93), usb_host_scan_hub_ports (first call and for every device
 * behind a hub port), usb_disk_write_frame_dump (again after a failed write). usb_host_init_controller runs before
 * each call.
 *
 * Phases:
 *   1. Transfer records: the eight records from td_block on are written as empty last records whose first page is
 *      the buffer block.
 *   2. Queue heads: queues 0 and 1 (address 0, endpoint 0, packet size 8) linked to each other, queues 2 and 3
 *      (address 3, endpoints 1 and 2, packet size 0x200, or 0x40 when bit 23 of register 0x80 is clear) linked to
 *      each other; register 0x28 points at queue 0.
 *   3. Address: SETUP_SET_ADDRESS with the port's next address (XDATA 0x07D1 + port, 3 after the controller set-up),
 *      the address stored in all four queue heads, the next address raised by 2.
 *   4. Device reply: SETUP_GET_DEVICE for 8 bytes; byte 7 becomes queue 1's packet size; the same packet again for
 *      as many bytes as byte 0 says.
 *   5. Configuration reply: SETUP_GET_CONFIG for 0x20 bytes; bytes 0x0E / 0x10 are the return value.
 *   6. By the class byte: class 8 sets the two data queues from bytes 0x14 / 0x1B, sends SETUP_SET_CONFIG and
 *      SETUP_GET_MAX_LUN, points register 0x28 at queue 2 and runs disk commands 0x00 (up to 10 tries, with 0x03
 *      after every failed try), 0x12 and 0x25; class 3 sends SETUP_SET_CONFIG and runs usb_host_init_async_list;
 *      class 9 sends SETUP_SET_CONFIG and SETUP_HUB_CONFIG.
 * After phases 3, 4 and 5 and inside phase 6 the routine returns at once when the port's error count is not zero
 * (usb_get_port_error_count); iface has then not been set and the caller gets whatever its storage holds.
 *
 * Returns: the class byte (iface.class_code) and the byte 2 places after it (iface.protocol) of the configuration
 * reply. */
struct usb_iface_id usb_host_enumerate_device(void)
{
    unsigned char i;
    unsigned char dot;
    unsigned char *reply;
    struct usb_iface_id iface;
    i = 0;
    reply = &usb_control_reply;
    /* 1. Eight empty transfer records. */
    lib_fill_data_buffer(0, 2);
    usb_port_mem_addrs.td_view->next_link = usb_port_mem_addrs.td_view->next_link & 0xfffffffe | 1;
    usb_port_mem_addrs.td_view->kind_bits = usb_port_mem_addrs.td_view->kind_bits & 0x7f | 0x80;
    usb_port_mem_addrs.td_view->alt_link = usb_port_mem_addrs.td_view->alt_link & 0xfffffffe | 1;
    usb_port_mem_addrs.td_view->kind_bits = usb_port_mem_addrs.td_view->kind_bits & 0xf3 | 0x0c;
    usb_port_mem_addrs.td_view->page[0] = usb_port_mem_addrs.td_view->page[0] & 0xfff | usb_port_mem_addrs.buffer_block << 5 & 0xfffff000;
    for (i = 0; i < 8; i++) usb_port_write_blocks(usb_port_mem_addrs.td_block + i, 1);
    /* 2. Queue heads: 0 -> 1 -> 0 and 2 -> 3 -> 2. */
    usb_host_init_queue_head(QUEUE_CONTROL_0, QUEUE_TYPE_1, 0, 1, 0, CONTROL_PACKET_SIZE);
    usb_queue_head_ptr->link = usb_queue_head_ptr->link & 0x1f | (usb_port_mem_addrs.qh_block + 2) << 5 & 0xffffffe0;
    usb_port_write_blocks(usb_port_mem_addrs.qh_block, 2);
    usb_host_init_queue_head(QUEUE_CONTROL_1, QUEUE_TYPE_1, 0, 0, 0, CONTROL_PACKET_SIZE);
    usb_queue_head_ptr->link = usb_queue_head_ptr->link & 0x1f | usb_port_mem_addrs.qh_block << 5 & 0xffffffe0;
    usb_port_write_blocks(usb_port_mem_addrs.qh_block + 2, 2);
    /* i = 1: register 0x80 bit 23 clear, the data queues get the smaller packet size. */
    if (!(reg_window_read32(REG_80) & REG80_BIT23)) i = 1;
    else i = 0;
    usb_host_init_queue_head(QUEUE_DATA_2, QUEUE_TYPE_1, DATA_DEVICE_ADDRESS, 0, 1, DATA_PACKET_SIZE);
    usb_queue_head_ptr->link = usb_queue_head_ptr->link & 0x1f | (usb_port_mem_addrs.qh_block + 6) << 5 & 0xffffffe0;
    if (i == 1) usb_queue_head_ptr->packet_word = usb_queue_head_ptr->packet_word & 0xf800 | DATA_PACKET_SIZE_SLOW;
    usb_port_write_blocks(usb_port_mem_addrs.qh_block + 4, 2);
    usb_host_init_queue_head(QUEUE_DATA_3, QUEUE_TYPE_1, DATA_DEVICE_ADDRESS, 0, 2, DATA_PACKET_SIZE);
    usb_queue_head_ptr->link = usb_queue_head_ptr->link & 0x1f | (usb_port_mem_addrs.qh_block + 4) << 5 & 0xffffffe0;
    if (i == 1) usb_queue_head_ptr->packet_word = usb_queue_head_ptr->packet_word & 0xf800 | DATA_PACKET_SIZE_SLOW;
    usb_port_write_blocks(usb_port_mem_addrs.qh_block + 6, 2);
    reg_window_write32(REG_LIST_ADDR, usb_port_mem_addrs.qh_block << 5);
    /* 3. Give the device its address. */
    usb_setup_packets[SETUP_SET_ADDRESS].b[2] = usb_next_device_address[usb_port_index];
    usb_host_control_xfer(QUEUE_CONTROL_0, usb_setup_packets[SETUP_SET_ADDRESS].b, 0);
    usb_host_set_device_address(usb_next_device_address[usb_port_index]);
    usb_next_device_address[usb_port_index] += DEVICE_ADDRESS_STEP;
    if (usb_get_port_error_count()) return iface;
    /* 4. Device reply: 8 bytes first, then the length its byte 0 gives. */
    usb_setup_packets[SETUP_GET_DEVICE].b[SETUP_PACKET_LENGTH] = 8;
    usb_host_control_xfer(QUEUE_CONTROL_1, usb_setup_packets[SETUP_GET_DEVICE].b, usb_setup_packets[SETUP_GET_DEVICE].b[SETUP_PACKET_LENGTH]);
    usb_port_read_blocks(usb_port_mem_addrs.qh_block + 2, 2);
    usb_queue_head_ptr->packet_word = usb_queue_head_ptr->packet_word & 0xf800 | reply[DEVICE_REPLY_PACKET];
    usb_port_write_blocks(usb_port_mem_addrs.qh_block + 2, 2);
    usb_setup_packets[SETUP_GET_DEVICE].b[SETUP_PACKET_LENGTH] = *reply;
    usb_host_control_xfer(QUEUE_CONTROL_1, usb_setup_packets[SETUP_GET_DEVICE].b, usb_setup_packets[SETUP_GET_DEVICE].b[SETUP_PACKET_LENGTH]);
    if (usb_get_port_error_count()) return iface;
    /* 5. Configuration reply. */
    usb_setup_packets[SETUP_GET_CONFIG].b[SETUP_PACKET_LENGTH] = CONFIG_REPLY_LENGTH;
    usb_host_control_xfer(QUEUE_CONTROL_1, usb_setup_packets[SETUP_GET_CONFIG].b, CONFIG_REPLY_LENGTH);
    if (usb_get_port_error_count()) return iface;
    iface.class_code = reply[CONFIG_REPLY_CLASS];
    iface.protocol = reply[CONFIG_REPLY_PROTOCOL];
    /* 6. Prepare the device by its class. */
    if (iface.class_code == IFACE_CLASS_STORAGE) {
        /* Bit 7 of the first endpoint byte decides which data queue receives. */
        if ((reply[CONFIG_REPLY_EP_A] & 0x80) > 0) {
            usb_port_xfer_record.ep_in = QUEUE_DATA_2;
            usb_port_xfer_record.ep_out = QUEUE_DATA_3;
        } else {
            usb_port_xfer_record.ep_in = QUEUE_DATA_3;
            usb_port_xfer_record.ep_out = QUEUE_DATA_2;
        }
        usb_port_read_blocks(usb_port_mem_addrs.qh_block + 4, 2);
        usb_queue_head_ptr->endpoint_bits = usb_queue_head_ptr->endpoint_bits & 0xf0 | reply[CONFIG_REPLY_EP_A] & 0xf;
        usb_port_write_blocks(usb_port_mem_addrs.qh_block + 4, 2);
        usb_port_read_blocks(usb_port_mem_addrs.qh_block + 6, 2);
        usb_queue_head_ptr->endpoint_bits = usb_queue_head_ptr->endpoint_bits & 0xf0 | reply[CONFIG_REPLY_EP_B] & 0xf;
        usb_port_write_blocks(usb_port_mem_addrs.qh_block + 6, 2);
        usb_host_control_xfer(QUEUE_CONTROL_1, usb_setup_packets[SETUP_SET_CONFIG].b, 0);
        timer_delay_units(1);
        if (usb_get_port_error_count()) return iface;
        usb_host_control_xfer(QUEUE_CONTROL_1, usb_setup_packets[SETUP_GET_MAX_LUN].b, 1);
        if (usb_get_port_error_count()) return iface;
        /* Clear bit 5 of register 0x10, wait (at most 200 reads) for bit 15 of the status register to clear, then
         * point register 0x28 at queue 2 and read both registers back. */
        reg_window_write32(REG_10, reg_window_read32(REG_10) & 0xffffffdf);
        i = 0;
        while ((reg_window_read32(REG_USBSTS) & USBSTS_BIT15) != 0) {
            i++;
            if (i > 200) break;
        }
        reg_window_write32(REG_LIST_ADDR, (usb_port_mem_addrs.qh_block + 4) << 5);
        reg_window_read32(REG_LIST_ADDR);
        reg_window_read32(REG_10);
        timer_delay_units(1);
        if (usb_get_port_error_count()) return iface;
        /* Command 0x00 until its res byte is 0 (then the port's error count is cleared); after a failed try
         * command 0x03, 100 dots printed with pauses, and the error count raised. */
        for (i = 0; i < DISK_CMD_TRIES; i++) {
            lib_clear_bytes((unsigned char *)&usb_port_record, sizeof(usb_port_record));
            usb_port_record.cb[0] = DISK_CMD_00;
            usb_port_record.cblen = 6;
            usb_port_record.dir = CMD_DIR_FROM_DEVICE;
            usb_port_record.len = 0;
            usb_port_record.n = 0;
            usb_port_record.id ^= CMD_ID_TOGGLE;
            usb_port_record.st = 0;
            usb_msc_run_command();
            timer_delay_units(1);
            if (usb_port_record.res == 0) {
                usb_clear_port_error_count();
                break;
            }
            lib_clear_bytes((unsigned char *)&usb_port_record, sizeof(usb_port_record));
            usb_port_record.cb[0] = DISK_CMD_03;
            usb_port_record.cb[4] = 0x12;
            usb_port_record.cblen = 6;
            usb_port_record.dir = CMD_DIR_FROM_DEVICE;
            usb_port_record.len = 0x12;
            usb_port_record.addr = usb_port_mem_addrs.buffer_block << 5;
            usb_port_record.n = 0;
            usb_port_record.id ^= CMD_ID_TOGGLE;
            usb_port_record.st = 0;
            usb_msc_run_command();
            for (dot = 0; dot < 100; dot++) {
                lib_printf517((void code *)0xc9c9);
                timer_delay_units(0x0f);
            }
            usb_port_error_counts[usb_port_index]++;
        }
        if (usb_get_port_error_count()) return iface;
        /* Command 0x12 for 0x24 bytes and command 0x25 for 8 bytes, both into the buffer block. */
        lib_clear_bytes((unsigned char *)&usb_port_record, sizeof(usb_port_record));
        usb_port_record.cb[0] = DISK_CMD_12;
        usb_port_record.cb[4] = 0x24;
        usb_port_record.cblen = 6;
        usb_port_record.dir = CMD_DIR_FROM_DEVICE;
        usb_port_record.len = 0x24;
        usb_port_record.addr = usb_port_mem_addrs.buffer_block << 5;
        usb_port_record.n = 0;
        usb_port_record.id ^= CMD_ID_TOGGLE;
        usb_port_record.st = 0;
        usb_msc_run_command();
        timer_delay_units(1);
        lib_clear_bytes((unsigned char *)&usb_port_record, sizeof(usb_port_record));
        usb_port_record.cb[0] = DISK_CMD_25;
        usb_port_record.cblen = 10;
        usb_port_record.dir = CMD_DIR_FROM_DEVICE;
        usb_port_record.len = 8;
        usb_port_record.addr = usb_port_mem_addrs.buffer_block << 5;
        usb_port_record.n = 0;
        usb_port_record.id ^= CMD_ID_TOGGLE;
        usb_port_record.st = 0;
        usb_msc_run_command();
        timer_delay_units(1);
    } else if (iface.class_code == IFACE_CLASS_3) {
        usb_host_control_xfer(QUEUE_CONTROL_1, usb_setup_packets[SETUP_SET_CONFIG].b, 0);
        timer_delay_units(1);
        usb_host_init_async_list();
    } else if (iface.class_code == IFACE_CLASS_HUB) {
        usb_host_control_xfer(QUEUE_CONTROL_1, usb_setup_packets[SETUP_SET_CONFIG].b, 0);
        timer_delay_units(1);
        usb_host_control_xfer(QUEUE_CONTROL_1, usb_setup_packets[SETUP_HUB_CONFIG].b, 0);
    }
    return iface;
}

/* Fill n blocks (n * 32 bytes) of the block buffer with val. */
void lib_fill_data_buffer(unsigned char val, unsigned char n)
{
    unsigned char i;
    unsigned char *p;
    p = usb_block_buffer;
    for (i = 0; i < n * 32; i++) p[i] = val;
}

/* Write memory to the disk from sector a on: memory block from mailbox bytes 0xF19A..0xF19D, chunk count from
 * 0xF19E..0xF19F, 0x5000 bytes per chunk with disk command 0x2A; progress 0..0xFF in 0xF194. A chunk that fails is
 * sent again after the controller set-up and the enumeration. */
void usb_disk_write_frame_dump(unsigned long a)
{
    unsigned long b;
    unsigned int n;
    unsigned int i;
    unsigned int m;
    b = reg_fwupd_mailbox_f19a;
    b = (b << 8) + reg_fwupd_mailbox_f19b;
    b = (b << 8) + reg_fwupd_mailbox_f19c;
    b = (b << 8) + reg_fwupd_mailbox_f19d;
    b <<= 5;
    n = reg_fwupd_mailbox_f19e;
    n = (n << 8) + reg_fwupd_mailbox_f19f;
    m = 0x5000;
    i = 0;
    while (i < n) {
        reg_fwupd_progress = (unsigned long)i * 0xff / n;
        lib_clear_bytes((unsigned char *)&usb_port_record, sizeof(usb_port_record));
        usb_port_record.cb[0] = 0x2a;
        usb_port_record.cb[1] = 8;
        usb_port_record.cb[2] = a >> 24;
        usb_port_record.cb[3] = a >> 16;
        usb_port_record.cb[4] = a >> 8;
        usb_port_record.cb[5] = a;
        usb_port_record.cb[8] = m >> 9;
        usb_port_record.cblen = 0x0a;
        usb_port_record.dir = 1;
        usb_port_record.len = m;
        usb_port_record.addr = b;
        usb_port_record.n = 0;
        usb_port_record.id ^= 0x80000000;
        usb_port_record.st = 0;
        usb_msc_run_command();
        if (usb_get_port_error_count()) {
            usb_clear_port_error_count();
            usb_host_init_controller();
            usb_host_enumerate_device();
            continue;
        }
        a += m >> 9;
        b += m;
        i++;
    }
}

/* Read b bytes from disk sector a on (disk command 0x28, b / 0x200 sectors) to port memory block c. */
void usb_disk_read_blocks(unsigned long a, unsigned long b, unsigned long c)
{
    lib_clear_bytes((unsigned char *)&usb_port_record, sizeof(usb_port_record));
    usb_port_record.cb[0] = 0x28;
    usb_port_record.cb[2] = a >> 24;
    usb_port_record.cb[3] = a >> 16;
    usb_port_record.cb[4] = a >> 8;
    usb_port_record.cb[5] = a;
    usb_port_record.cb[8] = b / 0x200;
    usb_port_record.cblen = 0x0a;
    usb_port_record.dir = 2;
    usb_port_record.len = b;
    usb_port_record.addr = c << 5;
    usb_port_record.n = 0;
    usb_port_record.id ^= 0x80000000;
    usb_port_record.st = 0;
    usb_msc_run_command();
}

void lib_clear_bytes(unsigned char *p, unsigned char n)
{
    unsigned char i;
    for (i = 0; i < n; i++) p[i] = 0;
}
