/* usb_host_init_controller  (FUN_CODE_b706)
 *
 * Load the host controller register table and reset the host records.
 * Name basis: derived - CODE table 0xC9D2 (reg, value, wait); called under 'Host Mode Init' and on every re-
 *   attach
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE; local i at XDATA 0x08FA, buffer_ptr register-only.
 * Source forms the bytes depend on: the table declared with its size [16] (8-bit record offset: MUL AB, CLR A /
 * ADDC); every test reads the record again (an if / else-if chain, no switch); 0x22 through the char local
 * buffer_ptr (MOV R7,#22H / MOV A,R7; it also keeps the first record test free of a MOV R7,A copy).
 */
/* One step of usb_host_init_table (7 bytes). */
struct usb_host_init_step {
    unsigned int reg;       /* register; its top nibble gives the kind of step (STEP_*); TABLE_END ends the table */
    unsigned long value;    /* value written, or bits set / cleared */
    unsigned char wait;     /* timer_delay_units after the step */
};
/* XDATA 0x08BC, as in usb_host_enumerate_device's file (td_view is an IDATA pointer there). */
struct usb_port_addrs { unsigned char td_view; unsigned long buffer_block; unsigned long qh_block; unsigned long td_block; };
extern struct usb_host_init_step code usb_host_init_table[16];
extern unsigned char xdata usb_port_bytes[3];
extern struct usb_port_addrs xdata usb_port_mem_addrs;
extern unsigned char xdata usb_queue_head_ptr;     /* the queue-head view of the same DATA buffer */
extern unsigned char xdata usb_next_device_address[2];  /* next device address, one byte per port */
void reg_window_write32(unsigned int reg, unsigned long v);
void reg_window_set_bits32(unsigned int reg, unsigned long mask);
void reg_window_clear_bits32(unsigned int reg, unsigned long mask);
void timer_delay_units(unsigned char n);
void usb_phy_tune_ctrl52(void);

#define TABLE_END        0xffff
#define STEP_KIND_MASK   0xf000
#define STEP_WRITE       0x0000
#define STEP_SET_BITS    0x1000
#define STEP_CLEAR_BITS  0x2000
#define BLOCK_BUFFER     0x22   /* DATA address of the block buffer (usb_port_read_blocks / _write_blocks) */
#define FIRST_DEVICE_ADDRESS 3

/* usb_host_init_controller: set up the USB controller of the selected port.
 *
 * Runs the steps of usb_host_init_table (at most 255, up to the TABLE_END row) through the register window routines,
 * which get reg as it stands, kind bits included: STEP_WRITE writes value, STEP_SET_BITS sets its bits, STEP_CLEAR_BITS clears them; any other kind
 * writes nothing. Every step, written or not, is followed by its wait.
 * Then: usb_port_bytes = 0, 4, 6; both views of the port memory (usb_port_mem_addrs.td_view and usb_queue_head_ptr)
 * point at the DATA buffer BLOCK_BUFFER; usb_phy_tune_ctrl52; the next device address of both ports is set to
 * FIRST_DEVICE_ADDRESS.
 * Callers: fwupd_step_port_state, usb_disk_write_frame_dump, sys_main, usb_host_scan_hub_ports. */
void usb_host_init_controller(void)
{
    unsigned char i;
    unsigned char buffer_ptr;
    for (i = 0; i < 0xff; i++) {
        if (usb_host_init_table[i].reg == TABLE_END) break;
        if ((usb_host_init_table[i].reg & STEP_KIND_MASK) == STEP_WRITE) {
            reg_window_write32(usb_host_init_table[i].reg, usb_host_init_table[i].value);
        } else if ((usb_host_init_table[i].reg & STEP_KIND_MASK) == STEP_SET_BITS) {
            reg_window_set_bits32(usb_host_init_table[i].reg, usb_host_init_table[i].value);
        } else if ((usb_host_init_table[i].reg & STEP_KIND_MASK) == STEP_CLEAR_BITS) {
            reg_window_clear_bits32(usb_host_init_table[i].reg, usb_host_init_table[i].value);
        }
        timer_delay_units(usb_host_init_table[i].wait);
    }
    usb_port_bytes[0] = 0;
    usb_port_bytes[1] = 4;
    usb_port_bytes[2] = 6;
    buffer_ptr = BLOCK_BUFFER;
    usb_port_mem_addrs.td_view = buffer_ptr;
    usb_queue_head_ptr = buffer_ptr;
    usb_phy_tune_ctrl52();
    usb_next_device_address[0] = FIRST_DEVICE_ADDRESS;
    usb_next_device_address[1] = FIRST_DEVICE_ADDRESS;
}
