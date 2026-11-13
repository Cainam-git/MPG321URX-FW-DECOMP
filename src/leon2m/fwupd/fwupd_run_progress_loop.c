/* fwupd_run_progress_loop  (FUN_a002f118)
 *
 * Mask all interrupts, wait for the 8051 transfer to start, then report its progress forever.
 * Note: Never returns; size from 8051 bytes 0xCF03C66C..674, hook 0xA802C9F4 runs on every percent change.
 * Name basis: derived - text 'total size = %ld'; endless percent loop; caller fwupd_enter_update
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002f118 @ 0xa002f118-0xa002f388 (156 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the limit as 'fwupd_progress_percent = 100; if (percent <= 100) fwupd_progress_percent = percent;';
 *  - fwupd_get_progress_percent is defined here as a static copy (inlined: the byte is read back after the store);
 *  - the second wait loop reads 0xF19D through a pointer declared in a block around that loop, and its body is
 *    'last_percent = 0;' (the firmware clears it before the loop test at 0xa002f2b4 and again after the loop exit
 *    at 0xa002f37c).
 */
#define REG(a) (*(volatile unsigned int *)(a))

/* A byte of the USB controller's (8051) XDATA space as the main processor sees it: one word per byte. */
#define RB(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))

/* The update agent's mailbox on the USB controller (fwupd_run_mailbox_command in its bank 2 program). */
#define FWUPD_MAILBOX_CMD   0xf198      /* command byte; the agent's main loop clears it when it takes it */
#define FWUPD_MAILBOX_F19A  0xf19a
#define FWUPD_MAILBOX_F19B  0xf19b      /* F19B..F19D: three answer bytes, low byte first */
#define FWUPD_MAILBOX_F19C  0xf19c
#define FWUPD_MAILBOX_F19D  0xf19d
#define FWUPD_PORT_COMMAND  0xf191      /* + 2 * port: command register of a USB port (fwupd_step_port_state) */

#define FWUPD_CMD_GET_RECORD_TOTAL 0x60 /* agent answers its record total (bits 0..23) in F19B..F19D */
#define FWUPD_CMD_START_ISP_DUALFW 0x17 /* port command; the agent's text 'CMD_START_ISP_ROMCODE_MODE_DUALFW' */

#define MEM_PORT_CONTROL    0xcf011f80
#define MEM_PORT_CONTROL_BIT7 0x80

#define IRQ_ALL_SOURCES     0xffff

/* The 24-bit value in F19B..F19D. */
#define MAILBOX_VALUE() ((RB(FWUPD_MAILBOX_F19D) << 16) + (RB(FWUPD_MAILBOX_F19C) << 8) + RB(FWUPD_MAILBOX_F19B))

extern unsigned char fwupd_progress_percent;
extern void (*fwupd_progress_hook)(void);
extern unsigned char fwupd_active_port;

extern void irq_write_control_value(void);

static unsigned char fwupd_get_progress_percent(void)
{
  return fwupd_progress_percent;
}
extern int dbg_printf();
extern void irq_mask_sources(int, unsigned short);
extern void irq_unmask_sources(int, unsigned short);
extern void timer_sleep_ticks(int);

/*
 * Start the agent's write on the active USB port and follow it in percent, without end.
 *
 * Caller: fwupd_enter_update (mode 0), once the port's status reads 0x97.
 *
 * In order: irq_write_control_value; ask the agent for its record total (command 0x60, wait until the agent has
 * taken it) and print it as 'total size'; mask every source of interrupt levels 1..14 and enable source bit 0 of
 * level 4 again; set bit 7 of MEM_PORT_CONTROL; send port command 0x17 to the active port. Then it waits while
 * F19A reads 0xAA and while F19B..F19D still hold the total.
 *
 * After that, after each wait of 101 ticks: percent = F19B..F19D * 100 / total, limited to 100, stored in
 * fwupd_progress_percent. Each time the percent differs from the last one, fwupd_progress_hook is called (when set).
 */
void fwupd_run_progress_loop(void)
{
  unsigned int total, percent_value;
  unsigned char last_percent, percent;

  irq_write_control_value();
  RB(FWUPD_MAILBOX_CMD) = FWUPD_CMD_GET_RECORD_TOTAL;
  while (RB(FWUPD_MAILBOX_CMD) == FWUPD_CMD_GET_RECORD_TOTAL)
    ;
  total = MAILBOX_VALUE();
  dbg_printf("total size = %ld\r\n", total);
  irq_mask_sources(1, IRQ_ALL_SOURCES);
  irq_mask_sources(2, IRQ_ALL_SOURCES);
  irq_mask_sources(3, IRQ_ALL_SOURCES);
  irq_mask_sources(4, IRQ_ALL_SOURCES);
  irq_mask_sources(5, IRQ_ALL_SOURCES);
  irq_mask_sources(6, IRQ_ALL_SOURCES);
  irq_mask_sources(7, IRQ_ALL_SOURCES);
  irq_mask_sources(8, IRQ_ALL_SOURCES);
  irq_mask_sources(9, IRQ_ALL_SOURCES);
  irq_mask_sources(10, IRQ_ALL_SOURCES);
  irq_mask_sources(11, IRQ_ALL_SOURCES);
  irq_mask_sources(12, IRQ_ALL_SOURCES);
  irq_mask_sources(13, IRQ_ALL_SOURCES);
  irq_mask_sources(14, IRQ_ALL_SOURCES);
  irq_unmask_sources(4, 1);
  REG(MEM_PORT_CONTROL) = MEM_PORT_CONTROL_BIT7;
  RB(fwupd_active_port * 2 + FWUPD_PORT_COMMAND) = FWUPD_CMD_START_ISP_DUALFW;
  while (RB(FWUPD_MAILBOX_F19A) == 0xaa)
    ;
  last_percent = 0;
  /* Wait until the value in F19B..F19D moves away from the total. */
  {
    volatile unsigned int *f19d = &RB(FWUPD_MAILBOX_F19D);

    while ((*f19d << 16) + (RB(FWUPD_MAILBOX_F19C) << 8) + RB(FWUPD_MAILBOX_F19B) == total)
      last_percent = 0;
  }

  for (;;) {
    timer_sleep_ticks(100);
    percent_value = MAILBOX_VALUE() * 100 / total;
    percent = percent_value;
    fwupd_progress_percent = 100;
    if (percent <= 100)
      fwupd_progress_percent = percent;
    percent = fwupd_get_progress_percent();
    if (last_percent != percent) {
      last_percent = percent;
      if (fwupd_progress_hook)
        fwupd_progress_hook();
    }
  }
}
