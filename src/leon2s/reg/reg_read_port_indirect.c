/* reg_read_port_indirect  (FUN_a0061eb4)
 *
 * Read through the index register 0x1B8 of a receiver port block; registers other than 0x1B8 give 0.
 *   port: receiver port
 *   reg: register number; only 0x1B8 (indirect read) and 5 (read and dropped) do anything
 * Returns: the byte read from 0x1B9 for register number 0x1B8; 0 for every other number, register 5 included
 * Note: Register 5: status register 5 is read and the value dropped. The HDR10+ check that tests status
 *   register 5 with mask 0x20 through this routine (receiver modes 4 and 5) therefore never sees the bit.
 * Name basis: descriptive - 0x1B7 mode/enable, index to 0x1B8, data from 0x1B9; register 5 only triggers a
 *   plain read; stored as the read routine by hdr_select_metadata_receiver for modes 4 and 5
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0061eb4 @ 0xa0061eb4 (-mcpu=v8 -Os -g)
 * Kept in the decompiler's form: the calls are declared without prototypes, SC_MaskSetByte is called by its
 * link name, and the result is built with CONCAT44 and cut to int by the return type.
 */
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
extern int dp_reg_read8();
extern void dp_reg_write8();
extern void dp_reg_update_bits();
extern int dp_status_reg_read8();
extern void SC_MaskSetByte();

/* Registers of the port block that this routine uses. */
#define PORT_STATUS_REG        5                /* read by calling dp_status_reg_read8; the value is dropped */
#define PORT_INDIRECT_CTRL_REG 0x1b7            /* bits 0..2 = 2 for an indirect read, bit 6 = access open */
#define PORT_INDIRECT_ADDR_REG 0x1b8            /* receives the low byte of the register number */
#define PORT_INDIRECT_DATA_REG 0x1b9            /* result of the indirect read */
#define INDIRECT_ACCESS_OPEN   0x40

/*
 * Register read routine of the receivers that hdr_select_metadata_receiver sets up with modes 4 and 5 (it is
 * stored in hdr_meta_reg_read_fn).
 *
 *   port: port number
 *   reg:  register number, compared as a 16-bit value
 *
 * Register 0x1b8 means an indirect read: the 3-bit field of the control register 0x1b7 is set to 2 (through
 * SC_MaskSetByte), bit 6 of 0x1b7 is raised, the low byte of reg is written to 0x1b8, the result is read from
 * 0x1b9 and bit 6 of 0x1b7 is lowered again. That byte is returned.
 * Register 5 only does a plain read of the port's status register 5; the value read is not used and 0 is
 * returned. Any other register number returns 0.
 */
int reg_read_port_indirect(unsigned char port, unsigned int reg)
{
  unsigned char value;

  value = 0;
  if (((unsigned short)reg) == PORT_STATUS_REG) {
    value = 0;
    dp_status_reg_read8(port & 0xff, PORT_STATUS_REG);
  }
  else {
    port = port & 0xff;
    if (((unsigned short)reg) == PORT_INDIRECT_ADDR_REG) {
      SC_MaskSetByte(1,port,PORT_INDIRECT_CTRL_REG,7,2);
      dp_reg_update_bits(port,PORT_INDIRECT_CTRL_REG,INDIRECT_ACCESS_OPEN,1);
      dp_reg_write8(port,PORT_INDIRECT_ADDR_REG,reg & 0xff);
      value = dp_reg_read8(port,PORT_INDIRECT_DATA_REG);
      dp_reg_update_bits(port,PORT_INDIRECT_CTRL_REG,INDIRECT_ACCESS_OPEN,0);
    }
    value = value & 0xff;
  }
  return CONCAT44(reg,value);
}
