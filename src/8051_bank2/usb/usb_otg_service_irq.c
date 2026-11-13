/* usb_otg_service_irq  (FUN_CODE_5c20)
 *
 * Service the FOTG210 USB controller's interrupt status in device mode.
 * Name basis: proven - prints 'fotg210: reset by host', 'suspend/removed', 'resume'; group/sub status
 *   registers
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_5c20 @ 0x5c20, compiled with OPTIMIZE(8,SPEED) LARGE.
 * LARGE locals at XDATA 0x08E5 global_status, 0x08E9 group_status, 0x08ED sub_status, 0x08F1 reg_value, 0x08F5 i
 * (declaration order).
 * Tail 'LCALL 65ab; RET': the last 'if' jumps over the call to the RET (JZ 0x60b8), no aid needed. The "bulk
 * ISO interrupt" print shares the dma-error LCALL (LJMP 0x6081, Keil cross-jump) and the reset / suspend arms
 * share the 'reg_value' store tail into register 0x100 (SJMP 0x5ff4), both from the plain C below.
 * The read-modify-write of register 0x138 as written ('reg_value |= 0x10000;' as its own statement) gives the OR
 * on R6 instead of R5.
 */

/* Status registers of the USB controller (32 bits, through the register window). Every status word read here is
 * written back to its register; register meanings are what this routine does with them, bit names are the texts
 * printed for them. Each group status has a mask register: bits set in the mask are dropped from the status. */
#define REG_GLOBAL_STATUS    0x00c0
#define GLOBAL_DEVICE        0x01        /* bit 0: device-side status, handled through the group registers */
#define GLOBAL_OTG           0x02        /* bit 1: "OTG interrupt" */
#define GLOBAL_HC            0x04        /* bit 2: "HC interrupt" */
#define REG_GROUP_MASK       0x0130
#define REG_GROUP0_MASK      0x0134
#define REG_GROUP2_MASK      0x013c
#define REG_GROUP_STATUS     0x0140
#define GROUP_0              0x01        /* control endpoint events: register 0x144 */
#define GROUP_1              0x02        /* "bulk ISO interrupt" */
#define GROUP_2              0x04        /* bus events: register 0x14C */
#define REG_GROUP0_STATUS    0x0144
#define GRP0_SETUP           0x01        /* a setup packet waits: answered by usb_device_answer_setup */
#define GRP0_CMD_FINISH      0x08        /* "command finish" */
#define GRP0_CMD_ERROR       0x10        /* "fotg210: cmd error" */
#define GRP0_CMD_ABORT       0x20        /* "fotg210: cmd abort" */
#define REG_GROUP2_STATUS    0x014c
#define GRP2_RESET           0x01        /* "fotg210: reset by host" */
#define GRP2_SUSPEND         0x02        /* "fotg210: suspend/removed" */
#define GRP2_RESUME          0x04        /* "fotg210: resume" */
#define GRP2_ISO_ERROR       0x08        /* "fotg210: iso error" */
#define GRP2_ISO_ABORT       0x10        /* "fotg210: iso abort" */
#define GRP2_DMA_ERROR       0x100       /* "fotg210: dma error" */

/* Registers the reset and suspend arms change. */
#define REG_100              0x0100      /* bit 0 cleared on a host reset, bit 3 set on suspend */
#define REG_DEVICE_ADDRESS   0x0104      /* set to 0 on a host reset; SET_ADDRESS writes it */
#define REG_108              0x0108      /* bit 0 set on a host reset */
#define REG_CX               0x0120      /* control endpoint register */
#define CX_FINISH            0x00000001  /* set after "command finish", as after "fotg210: cx_finish!" */
#define CX_STALL             0x00000004  /* cleared on a host reset */
#define REG_138              0x0138      /* bit 16 set on a host reset */
#define REG_1B0              0x01b0      /* four registers, 4 bytes apart, each set to 0x1000 on a host reset */
#define REG_1B0_COUNT        4
#define REG_1B0_RESET_VALUE  0x1000

/* Printed texts (CODE addresses). */
#define FMT_CMD_ERROR        0x7de9      /* "fotg210: cmd error\r\n" */
#define FMT_CMD_ABORT        0x7dfe      /* "fotg210: cmd abort\r\n" */
#define FMT_CMD_FINISH       0x7e13      /* "command finish\r\n" */
#define FMT_BULK_ISO         0x7e24      /* "bulk ISO interrupt\r\n" */
#define FMT_RESET            0x7e39      /* "fotg210: reset by host\r\n" */
#define FMT_SUSPEND          0x7e52      /* "fotg210: suspend/removed\r\n" */
#define FMT_RESUME           0x7e6d      /* "fotg210: resume\r\n" */
#define FMT_ISO_ERROR        0x7e7f      /* "fotg210: iso error\r\n" */
#define FMT_ISO_ABORT        0x7e94      /* "fotg210: iso abort\r\n" */
#define FMT_DMA_ERROR        0x7ea9      /* "fotg210: dma error\r\n" */
#define FMT_OTG              0x7ebe      /* "OTG interrupt\r\n" */
#define FMT_HC               0x7ece      /* "HC interrupt\r\n" */

unsigned long reg_window_read32(unsigned int reg);
void reg_window_write32(unsigned int reg, unsigned long v);
void usb_device_answer_setup(void);
extern void lib_printf517(void *fmt, ...) large;

/* usb_otg_service_irq: take the pending status of the selected USB controller and act on it.
 *
 * Caller: sys_main, once per main-loop round for controller 0 and once for controller 1 (selected with
 * usb_select_controller), while the USB mode in effect is 1 (device mode). The routine is polled; it is not an
 * interrupt routine.
 *
 * Order:
 *   1. Read the global status and write it back.
 *   2. Device bit set: read the group status (masked) and write it back; then only the first group set is handled:
 *        group 0: print command error / abort when set; a waiting setup packet goes to usb_device_answer_setup,
 *                 otherwise "command finish" sets CX_FINISH;
 *        group 1: only printed;
 *        group 2: one of host reset (address 0, the reset register writes below), suspend (bit 3 of register 0x100)
 *                 or resume (printed only), in that order of priority; then the ISO and DMA error bits are printed.
 *   3. The OTG and HC bits of the global status are only printed.
 */
void usb_otg_service_irq(void)
{
    unsigned long global_status;
    unsigned long group_status;
    unsigned long sub_status;
    unsigned long reg_value;
    unsigned char i;
    global_status = reg_window_read32(REG_GLOBAL_STATUS);
    reg_window_write32(REG_GLOBAL_STATUS, global_status);
    if (global_status & GLOBAL_DEVICE) {
        group_status = reg_window_read32(REG_GROUP_STATUS);
        group_status &= ~reg_window_read32(REG_GROUP_MASK);
        reg_window_write32(REG_GROUP_STATUS, group_status);
        if (group_status & GROUP_0) {
            sub_status = reg_window_read32(REG_GROUP0_STATUS);
            sub_status &= ~reg_window_read32(REG_GROUP0_MASK);
            reg_window_write32(REG_GROUP0_STATUS, sub_status);
            if (sub_status & GRP0_CMD_ERROR) lib_printf517((void code *)FMT_CMD_ERROR);
            if (sub_status & GRP0_CMD_ABORT) lib_printf517((void code *)FMT_CMD_ABORT);
            /* A setup packet takes precedence over a finished command. */
            if (sub_status & GRP0_SETUP) {
                usb_device_answer_setup();
            } else if (sub_status & GRP0_CMD_FINISH) {
                lib_printf517((void code *)FMT_CMD_FINISH);
                reg_value = reg_window_read32(REG_CX);
                reg_value |= CX_FINISH;
                reg_window_write32(REG_CX, reg_value);
            }
        } else if (group_status & GROUP_1) {
            lib_printf517((void code *)FMT_BULK_ISO);
        } else if (group_status & GROUP_2) {
            sub_status = reg_window_read32(REG_GROUP2_STATUS);
            sub_status &= ~reg_window_read32(REG_GROUP2_MASK);
            reg_window_write32(REG_GROUP2_STATUS, sub_status);
            if (sub_status & GRP2_RESET) {
                /* Host reset: forget the address and put the registers below back. */
                lib_printf517((void code *)FMT_RESET);
                reg_window_write32(REG_DEVICE_ADDRESS, 0);
                reg_value = reg_window_read32(REG_138);
                reg_value |= 0x10000;
                reg_window_write32(REG_138, reg_value);
                reg_value = reg_window_read32(REG_108);
                reg_value |= 1;
                reg_window_write32(REG_108, reg_value);
                for (i = 0; i < REG_1B0_COUNT; i++) reg_window_write32(REG_1B0 + i * 4, REG_1B0_RESET_VALUE);
                reg_value = reg_window_read32(REG_CX);
                reg_value &= ~CX_STALL;
                reg_window_write32(REG_CX, reg_value);
                reg_value = reg_window_read32(REG_100);
                reg_value &= ~1;
                reg_window_write32(REG_100, reg_value);
            } else if (sub_status & GRP2_SUSPEND) {
                lib_printf517((void code *)FMT_SUSPEND);
                for (i = 0; i < 4; i++) ;  /* four empty rounds before the register write */
                reg_value = reg_window_read32(REG_100);
                reg_value |= 8;
                reg_window_write32(REG_100, reg_value);
            } else if (sub_status & GRP2_RESUME) {
                lib_printf517((void code *)FMT_RESUME);
            }
            if (sub_status & GRP2_ISO_ERROR) lib_printf517((void code *)FMT_ISO_ERROR);
            if (sub_status & GRP2_ISO_ABORT) lib_printf517((void code *)FMT_ISO_ABORT);
            if (sub_status & GRP2_DMA_ERROR) lib_printf517((void code *)FMT_DMA_ERROR);
        }
    }
    if (global_status & GLOBAL_OTG) lib_printf517((void code *)FMT_OTG);
    if (global_status & GLOBAL_HC) lib_printf517((void code *)FMT_HC);
}
