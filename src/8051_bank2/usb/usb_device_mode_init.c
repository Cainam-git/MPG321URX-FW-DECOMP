/* usb_device_mode_init  (FUN_CODE_60b9)
 *
 * Log and set up the USB controller for device mode.
 * Name basis: proven - prints 'device mode'; called for both ports under 'Device Mode Init'
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_60b9 @ 0x60b9 (1159 bytes), compiled with OPTIMIZE(8,SPEED) LARGE.
 * LARGE locals at XDATA 0x08E5 reg_value, 0x08E9 i (declaration order).
 * Plain C: every read-modify-write is a read, one statement per change, and a write, as below.
 */

/* Registers of the USB controller (32 bits, through the register window). Meanings are what this routine,
 * usb_otg_service_irq and usb_device_answer_setup do with them; a register they do not explain keeps its number. */
#define REG_80               0x0080      /* bits 4 and 10 set */
#define REG_GLOBAL_STATUS    0x00c0      /* written 7 (all three bits written back) */
#define REG_C4               0x00c4      /* 7 first, 6 at the end */
#define REG_100              0x0100
#define REG_100_BIT1_BIT9    0x202       /* cleared at the start */
#define REG_100_BIT2         0x04        /* set last */
#define REG_100_BIT4         0x10        /* set, then must read back clear */
#define REG_100_BIT5         0x20        /* set at the start */
#define REG_DEVICE_ADDRESS   0x0104      /* address 0 until the PC sends SET_ADDRESS */
#define REG_CX               0x0120      /* control endpoint register */
#define CX_BIT3              0x08        /* set, then must read back clear */
#define REG_124              0x0124      /* written 7 */
#define REG_GROUP_MASK       0x0130      /* bits set here are dropped from the group status */
#define REG_GROUP0_MASK      0x0134
#define REG_138              0x0138      /* 0x000F00FF, the same value both times */
#define REG_GROUP2_MASK      0x013c
#define REG_GROUP_STATUS     0x0140
#define REG_GROUP0_STATUS    0x0144
#define REG_148              0x0148      /* cleared with the status registers */
#define REG_GROUP2_STATUS    0x014c
#define REG_160              0x0160      /* eight registers, 4 bytes apart */
#define REG_180              0x0180      /* eight registers, 4 bytes apart */
#define REG_PAIR_VALUE       0x200       /* written to each of the 160 and 180 registers */
#define REG_PAIR_COUNT       8
#define REG_1A0              0x01a0      /* four registers 0x1A0..0x1AC */
#define REG_1B0              0x01b0      /* four registers, 4 bytes apart */
#define REG_1B0_BIT12        0x1000      /* set in each, then must read back clear */
#define REG_1B0_COUNT        4
#define REG_DMA_CONTROL      0x01c8      /* bit 31 cleared */
#define SETTLE_UNITS         10          /* timer_delay_units wait before a bit is read back */

/* Mask values. Before the set-up all three groups are masked; after it, groups 0..2 pass, group 0 passes every
 * bit except 1 and 2 (setup packet, command finish, error and abort pass), group 2 passes bits 0..4 (host reset,
 * suspend, resume, ISO error, ISO abort) and masks bits 5..10, the DMA error bit 8 among them. */
#define GROUP_MASK_ALL       7
#define GROUP_MASK_NONE      0
#define GROUP0_MASK_START    0x3f
#define GROUP0_MASK_RUN      6
#define REG_138_VALUE        0x000f00ff
#define GROUP2_MASK_START    0x7ff
#define GROUP2_MASK_RUN      0x7e0

#define FMT_DEVICE_MODE      0x7ddb      /* "device mode\r\n" */

extern bit usb_reg114_bit0_clear_flag;               /* when set, reg_window_write_reg114_bit0 clears bit 0 of register 0x114;
                                          when clear, it sets it */
extern unsigned int xdata usb_device_max_packet;
/* Byte registers in two blocks of the same layout, 0x5000 and 0x5100 (register 0x5052 of the first block is the
 * one the firmware prints as USB_PHY0_CTRL52). Both blocks get the same five values; 0x5109 is set in the second
 * block only. */
extern unsigned char xdata DAT_EXTMEM_5005;
extern unsigned char xdata DAT_EXTMEM_5006;
extern unsigned char xdata DAT_EXTMEM_5008;
extern unsigned char xdata DAT_EXTMEM_500e;
extern unsigned char xdata DAT_EXTMEM_503a;
extern unsigned char xdata DAT_EXTMEM_5105;
extern unsigned char xdata DAT_EXTMEM_5106;
extern unsigned char xdata DAT_EXTMEM_5108;
extern unsigned char xdata DAT_EXTMEM_5109;
extern unsigned char xdata DAT_EXTMEM_510e;
extern unsigned char xdata DAT_EXTMEM_513a;
unsigned long reg_window_read32(unsigned int reg);
void reg_window_write32(unsigned int reg, unsigned long v);
void timer_delay_units(unsigned char n);
void reg_window_write_reg114_bit0(void);
void usb_phy_tune_ctrl52(void);
extern void lib_printf517(void *fmt, ...) large;

/* usb_device_mode_init: put the selected USB controller into device mode.
 *
 * Caller: sys_main, for controller 0 and then controller 1 (selected with usb_select_controller), when the USB mode
 * asked for by the main processor changes to 1; sys_main prints "Device Mode Init" after both.
 *
 * Order:
 *   1. Print "device mode", set bit 0 of register 0x114 (usb_reg114_bit0_clear_flag = 0), set bits in 0x80, clear bit 31 of the
 *      DMA control, set bit 5 and clear bits 1 and 9 of 0x100.
 *   2. Address 0, all groups masked, all status registers cleared.
 *   3. Three checks, each "set a bit, wait, read it back": bit 4 of 0x100, bit 3 of REG_CX and bit 12 of each of
 *      the four 1B0 registers. When a bit still reads back set, the routine returns at once and the rest of the
 *      set-up (and the packet size below) is not done; nothing reports it.
 *   4. The run-time masks (see the mask values above), bit 2 of 0x100, clear bit 0 of register 0x114
 *      (usb_reg114_bit0_clear_flag = 1), the byte registers of blocks 0x5000 / 0x5100, usb_phy_tune_ctrl52, and
 *      usb_device_max_packet = 0x40 (the size usb_device_answer_setup sends its pieces in).
 */
void usb_device_mode_init(void)
{
    unsigned long reg_value;
    unsigned char i;
    lib_printf517((void code *)FMT_DEVICE_MODE);
    usb_reg114_bit0_clear_flag = 0;
    reg_window_write_reg114_bit0();
    reg_value = reg_window_read32(REG_80);
    reg_value |= 0x400;
    reg_value |= 0x10;
    reg_window_write32(REG_80, reg_value);
    reg_value = reg_window_read32(REG_DMA_CONTROL);
    reg_value &= 0x7fffffff;
    reg_window_write32(REG_DMA_CONTROL, reg_value);
    reg_value = reg_window_read32(REG_100);
    reg_value |= REG_100_BIT5;
    reg_value &= ~REG_100_BIT1_BIT9;
    reg_window_write32(REG_100, reg_value);
    reg_window_write32(REG_DEVICE_ADDRESS, 0);
    reg_window_write32(REG_124, 7);
    reg_window_write32(REG_C4, 7);
    reg_window_write32(REG_GROUP_MASK, GROUP_MASK_ALL);
    reg_window_write32(REG_GROUP0_MASK, GROUP0_MASK_START);
    reg_window_write32(REG_138, REG_138_VALUE);
    reg_window_write32(REG_GROUP2_MASK, GROUP2_MASK_START);
    reg_window_write32(REG_GLOBAL_STATUS, 7);
    reg_window_write32(REG_GROUP_STATUS, 0);
    reg_window_write32(REG_GROUP0_STATUS, 0);
    reg_window_write32(REG_148, 0);
    reg_window_write32(REG_GROUP2_STATUS, 0);
    /* Each of these bits must have cleared again after the wait; otherwise give up. */
    reg_value = reg_window_read32(REG_100);
    reg_value |= REG_100_BIT4;
    reg_window_write32(REG_100, reg_value);
    timer_delay_units(SETTLE_UNITS);
    if (reg_window_read32(REG_100) & REG_100_BIT4) return;
    reg_value = reg_window_read32(REG_CX);
    reg_value |= CX_BIT3;
    reg_window_write32(REG_CX, reg_value);
    timer_delay_units(SETTLE_UNITS);
    if (reg_window_read32(REG_CX) & CX_BIT3) return;
    reg_window_write32(REG_1A0, 0x33221100);
    reg_window_write32(REG_1A0 + 4, 0);
    reg_window_write32(REG_1A0 + 8, 0x04030201);
    reg_window_write32(REG_1A0 + 0xc, 0);
    for (i = 0; i < REG_PAIR_COUNT; i++) {
        reg_window_write32(REG_160 + i * 4, REG_PAIR_VALUE);
        reg_window_write32(REG_180 + i * 4, REG_PAIR_VALUE);
    }
    for (i = 0; i < REG_1B0_COUNT; i++) {
        reg_window_write32(REG_1B0 + i * 4, REG_1B0_BIT12);
        timer_delay_units(SETTLE_UNITS);
        if (reg_window_read32(REG_1B0 + i * 4) & REG_1B0_BIT12) return;
    }
    /* Run-time masks: from here on usb_otg_service_irq sees the events listed above. */
    reg_window_write32(REG_C4, 6);
    reg_window_write32(REG_GLOBAL_STATUS, 7);
    reg_window_write32(REG_GROUP0_MASK, GROUP0_MASK_RUN);
    reg_window_write32(REG_138, REG_138_VALUE);
    reg_window_write32(REG_GROUP2_MASK, GROUP2_MASK_RUN);
    reg_window_write32(REG_GROUP_MASK, GROUP_MASK_NONE);
    reg_window_write32(REG_124, 7);
    reg_value = reg_window_read32(REG_100);
    reg_value |= REG_100_BIT2;
    reg_window_write32(REG_100, reg_value);
    usb_reg114_bit0_clear_flag = 1;
    reg_window_write_reg114_bit0();
    DAT_EXTMEM_5109 = 2;
    DAT_EXTMEM_5005 = 0x53;
    DAT_EXTMEM_500e = 0;
    DAT_EXTMEM_5008 = 6;
    DAT_EXTMEM_503a = 0x32;
    DAT_EXTMEM_5006 = 0x1c;
    DAT_EXTMEM_5105 = 0x53;
    DAT_EXTMEM_510e = 0;
    DAT_EXTMEM_5108 = 6;
    DAT_EXTMEM_513a = 0x32;
    DAT_EXTMEM_5106 = 0x1c;
    usb_phy_tune_ctrl52();
    usb_device_max_packet = 0x40;
}
