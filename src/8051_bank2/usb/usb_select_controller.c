/* usb_select_controller  (FUN_CODE_a6fa)
 *
 * Save the state of the current USB controller and switch to controller n.
 *   port: port 0/1
 * Name basis: derived - per-port record sets indexed by 0x075B (usb_get_current_port)
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE; parameter port at XDATA 0x08EB.
 * Source forms the bytes depend on: '(unsigned long)usb_port_index * 0x380' (?C?LIMUL; a long constant gives
 * ?C?LMUL); buffer_block, qh_block and td_block in one structure with td_view (INC DPTR from 0x08C0 to 0x08C1);
 * the record copies are whole-structure assignments (?C?COPY). The last store ends in a tail LJMP ?C?LSTXDATA.
 */
/* The per-port records are copied as whole blocks here; their fields are named in usb_host_enumerate_device's file
 * (struct usb_cmd_block, 0x2E bytes, and struct usb_disk_cmd, 0x27 bytes). */
struct usb_cmd_block_copy { unsigned char bytes[0x2e]; };
struct usb_disk_cmd_copy { unsigned char bytes[0x27]; };
/* XDATA 0x08BC; usb_host_enumerate_device's file names the same fields (td_view is an IDATA pointer there). */
struct usb_port_addrs {
    unsigned char td_view;          /* DATA pointer to the block buffer; not changed here */
    unsigned long buffer_block;     /* port base + 0x280 */
    unsigned long qh_block;         /* buffer_block + 0x20 */
    unsigned long td_block;         /* qh_block + 8 */
};
extern unsigned char xdata usb_port_index;
extern struct usb_disk_cmd_copy xdata usb_port_record;
extern struct usb_disk_cmd_copy xdata usb_port_records[2];
extern struct usb_cmd_block_copy xdata usb_port_xfer_record;
extern struct usb_cmd_block_copy xdata usb_port_xfer_records[2];
extern unsigned char xdata usb_port_bytes;      /* usb_port_bytes[0]; 0x08CE and 0x08CF are its bytes 1 and 2 */
extern unsigned char xdata DAT_EXTMEM_08ce;
extern unsigned char xdata DAT_EXTMEM_08cf;
extern unsigned char xdata usb_port_saved_bytes0[2];
extern unsigned char xdata usb_port_saved_bytes1[2];
extern unsigned char xdata usb_port_saved_bytes2[2];
extern unsigned long xdata usb_port_mem_base;
extern unsigned long xdata usb_port_list_block;     /* buffer_block + 0x80 (the port's list block) */
extern unsigned long xdata usb_port_mem_offset;
extern struct usb_port_addrs xdata usb_port_mem_addrs;
extern unsigned long xdata usb_mem_base;

#define PORT_MEM_BYTES   0x380  /* each port's share of the memory after usb_mem_base */
#define BUFFER_BLOCK_AT  0x280  /* from the port's base */
#define QH_BLOCK_AFTER   0x20   /* from buffer_block */
#define TD_BLOCK_AFTER   8      /* from qh_block */
#define LIST_BLOCK_AFTER 0x80   /* from buffer_block */

/* usb_select_controller: make port the selected USB port.
 *
 * port: 0 or 1.
 *
 * The routines that run a USB transfer work on one set of "current" copies: usb_port_xfer_record,
 * usb_port_record and the three usb_port_bytes. This routine stores those copies into the slots of the port
 * selected so far (usb_port_index), sets usb_port_index = port, loads the copies from the new port's slots, and
 * then computes the new port's memory addresses: base = usb_mem_base + port * PORT_MEM_BYTES, and from it the
 * blocks in usb_port_mem_addrs and usb_port_list_block.
 * Callers: fwupd_step_port_state and sys_main. */
void usb_select_controller(unsigned char port)
{
    /* Keep the state of the port selected so far. */
    usb_port_xfer_records[usb_port_index] = usb_port_xfer_record;
    usb_port_records[usb_port_index] = usb_port_record;
    usb_port_saved_bytes0[usb_port_index] = usb_port_bytes;
    usb_port_saved_bytes1[usb_port_index] = DAT_EXTMEM_08ce;
    usb_port_saved_bytes2[usb_port_index] = DAT_EXTMEM_08cf;
    /* Switch and load the new port's state. */
    usb_port_index = port;
    usb_port_xfer_record = usb_port_xfer_records[usb_port_index];
    usb_port_record = usb_port_records[usb_port_index];
    usb_port_bytes = usb_port_saved_bytes0[usb_port_index];
    DAT_EXTMEM_08ce = usb_port_saved_bytes1[usb_port_index];
    DAT_EXTMEM_08cf = usb_port_saved_bytes2[usb_port_index];
    usb_port_mem_offset = (unsigned long)usb_port_index * PORT_MEM_BYTES;
    usb_port_mem_base = usb_mem_base + usb_port_mem_offset;
    usb_port_mem_addrs.buffer_block = usb_port_mem_base + BUFFER_BLOCK_AT;
    usb_port_mem_addrs.qh_block = usb_port_mem_addrs.buffer_block + QH_BLOCK_AFTER;
    usb_port_mem_addrs.td_block = usb_port_mem_addrs.qh_block + TD_BLOCK_AFTER;
    usb_port_list_block = usb_port_mem_addrs.buffer_block + LIST_BLOCK_AFTER;
}
