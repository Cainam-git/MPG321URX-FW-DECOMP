/* fwupd_enter_update  (FUN_a0123cf0)
 *
 * Enter the firmware update: mode 0 runs the progress loop, mode 5 prepares the port first.
 * Name basis: derived - calls fwupd_run_progress_loop when the port word reads 0x97
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0123cf0 @ 0xa0123cf0-0xa0124168 (286 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the three command writes go through one static helper with an on flag and a separate write in each arm of
 *    'if (on == 1) .. else ..' (0x13 / 0); the same per-arm form as input_block_set_reg3_bit2,
 *    input_block_set_reg9c_bit2 and fwupd_port_send_cmd_0x70. Inlined with the constant flag, the folded test ends
 *    a block right after each command write (0xa0123e30, 0xa0123fbc), which gives the fresh address set-up for the
 *    0xEE wait at 0xa0123fc0;
 *  - the saved values are kept in an unsigned char array (each register is saved and restored as its low byte).
 */
#define REG(a) (*(volatile unsigned int *)(a))

/* A byte of the USB controller's (8051) XDATA space as the main processor sees it: one word per byte. */
#define RB(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))

/* The update agent's mailbox on the USB controller: a status and a command register per USB port
   (XDATA 0xF190 / 0xF191 for port 0, 0xF192 / 0xF193 for port 1), then parameter bytes 0xF19A..0xF19F. */
#define FWUPD_PORT_STATUS   0xf190      /* + 2 * port */
#define FWUPD_PORT_COMMAND  0xf191      /* + 2 * port */
#define FWUPD_PARAM_F19A    0xcf03c668  /* XDATA 0xF19A..0xF19F as seen here, one word per byte */
#define FWUPD_PARAM_F19B    0xcf03c66c
#define FWUPD_PARAM_F19C    0xcf03c670
#define FWUPD_PARAM_F19D    0xcf03c674
#define FWUPD_PARAM_F19E    0xcf03c678
#define FWUPD_PARAM_F19F    0xcf03c67c

/* Status values and commands of the update agent (fwupd_step_port_state in the USB controller's program). */
#define FWUPD_STATUS_WAIT_FW_UPDATE 0x97    /* set after 'STATUS_WAIT_FW_UPDATE': a file is loaded and its sum is good */
#define FWUPD_CMD_NONE              0
#define FWUPD_CMD_0x13              0x13    /* agent: usb_disk_run_write_pass, then 0xEE in both command registers */
#define FWUPD_CMD_DONE_MARK         0xee

/* Registers saved, changed and restored around command 0x13. Names as used elsewhere in this program;
   the others are named by their address. */
#define FRC_CHANNEL_ON      0xcf011800      /* bit 0 = frame-rate converter on (sys_frc_is_running) */
#define FRC_REG_1808        0xcf011808
#define REG_11880           0xcf011880
#define REG_11884           0xcf011884
#define REG_11888           0xcf011888
#define REG_1188C           0xcf01188c
#define FRC_CTRL            0xcf011a00
#define FRC_REG_1A80        0xcf011a80
#define FRC_REG_1A84        0xcf011a84
#define FRC_REG_1A88        0xcf011a88
#define FRC_REG_1A8C        0xcf011a8c
#define REG_11BF8           0xcf011bf8
#define FRC_REG_1D8C        0xcf011d8c
#define REG_116D4           0xcf0116d4
#define REG_11658           0xcf011658
#define CTRL_12E00          0xcf012e00
#define REG_13440           0xcf013440
#define REG_13444           0xcf013444

#define PICTURE_BLOCK_0     0
#define BLK_REG_86          0x86
#define BLK_REG_71          0x71            /* 16-bit */
#define BLK_REG_75          0x75            /* 16-bit */

enum { UPDATE_MODE_PROGRESS = 0, UPDATE_MODE_PREPARE = 5 };

extern unsigned char fwupd_active_port;
extern unsigned char pq_block_read8(unsigned char blk, unsigned char reg);
extern void pq_block_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern unsigned short pq_block_read16(unsigned char blk, unsigned char reg);
extern unsigned int sys_frc_is_running(void);
extern void fwupd_run_progress_loop(void);
extern void timer_sleep_ticks(int ms);
extern void panel_wait_sync_pulse(void);
extern void ipc_signal_alive(void);

/* Write command 0x13 (on = 1) or 0 (clear) to the command register of the active update port. */
static void port_cmd(unsigned char on)
{
    if (on == 1)
        RB(fwupd_active_port * 2 + FWUPD_PORT_COMMAND) = FWUPD_CMD_0x13;
    else
        RB(fwupd_active_port * 2 + FWUPD_PORT_COMMAND) = FWUPD_CMD_NONE;
}

/*
 * Hand the firmware update over to the update agent on the USB controller (docs/MAP.md, "The update agent on the
 * USB controller"). fwupd_active_port is the USB port (0 or 1) whose agent answered.
 *
 *   mode  0: run the progress loop; 5: send the agent command 0x13 with its parameters. Other values do nothing.
 *
 * Callers: fwupd_api_start_update (mode 0) and fwupd_api_start_update_mode5 (mode 5). docs/MAP.md: the entry
 * routines of this route are not called anywhere in FW.021.
 *
 * Mode 0 clears bit 7 of 0xCF011658. When the port's status reads 0x97 (the agent's 'STATUS_WAIT_FW_UPDATE'),
 * it enters fwupd_run_progress_loop, which sends command 0x17 and never returns.
 *
 * Mode 5, in phases:
 *   1. Save the low byte of twelve registers and picture block 0 register 0x86.
 *   2. Clear the port command, read whether the frame-rate converter is on, clear bit 0 of 0xCF0116D4 and
 *      0xCF011A80, and zero register 0x86 and four registers.
 *   3. Restart the converter registers: when bit 0 or 1 of 0xCF011D8C is set, switch FRC_CHANNEL_ON, FRC_CTRL and
 *      0xCF011BF8 off, wait 50 ticks and clear those bits; when bit 0 of 0xCF013440 is clear, switch the three off,
 *      set that bit and clear bit 2 of 0xCF013444. Then switch the three on, write 0xFF to 0xCF011808 and wait 100
 *      ticks. When 0xCF011808 then has bit 0 or 1 set, cycle FRC_CTRL and FRC_CHANNEL_ON off and FRC_CTRL on
 *      again, a panel sync pulse apart. When the converter was off at phase 2, switch the three off again.
 *   4. Fill the agent's parameter bytes: 0xF19A..0xF19D from 0xCF01188C..0xCF011880, 0xF19E / 0xF19F = high / low
 *      byte of (block reg 0x71 * block reg 0x75 * 3 / 0x5000 + 1).
 *   5. Send command 0x13 and wait, signalling alive to the USB controller, until the command register reads 0xEE.
 *      In the agent, command 0x13 runs usb_disk_run_write_pass, writes 0xEE to both command registers and stops in
 *      an endless loop.
 *   6. Clear the command and write all saved values back.
 */
void fwupd_enter_update(int mode)
{
    unsigned char saved[13];
    unsigned char frc_was_on;
    unsigned int reg71_value, reg75_value, size_value;

    switch (mode) {
    case UPDATE_MODE_PROGRESS:
        REG(REG_11658) &= ~0x80;
        if (RB(fwupd_active_port * 2 + FWUPD_PORT_STATUS) == FWUPD_STATUS_WAIT_FW_UPDATE)
            fwupd_run_progress_loop();
        break;
    case UPDATE_MODE_PREPARE:
        /* Phase 1: save (low bytes only). */
        saved[0] = REG(FRC_REG_1A84);
        saved[1] = REG(FRC_REG_1A88);
        saved[2] = REG(FRC_REG_1A8C);
        saved[3] = REG(REG_13440);
        saved[4] = REG(REG_13444);
        saved[5] = REG(FRC_REG_1D8C);
        saved[6] = REG(FRC_CHANNEL_ON);
        saved[7] = REG(FRC_CTRL);
        saved[8] = REG(CTRL_12E00);
        saved[9] = REG(REG_11BF8);
        saved[10] = REG(REG_116D4);
        saved[11] = REG(FRC_REG_1A80);
        saved[12] = pq_block_read8(PICTURE_BLOCK_0, BLK_REG_86);

        /* Phase 2: clear. */
        port_cmd(0);
        frc_was_on = sys_frc_is_running();
        REG(REG_116D4) &= ~1;
        REG(FRC_REG_1A80) &= ~1;
        pq_block_write8(PICTURE_BLOCK_0, BLK_REG_86, 0);
        REG(FRC_REG_1A84) = 0;
        REG(FRC_REG_1A88) = 0;
        REG(FRC_REG_1A8C) = 0;
        REG(CTRL_12E00) = 0;

        /* Phase 3: switch the converter registers off and on again. */
        if (REG(FRC_REG_1D8C) & 3) {
            REG(REG_11BF8) = 0;
            REG(FRC_CTRL) = 0;
            REG(FRC_CHANNEL_ON) = 0;
            timer_sleep_ticks(0x32);
            REG(FRC_REG_1D8C) &= ~3;
        }
        if (!(REG(REG_13440) & 1)) {
            REG(REG_11BF8) = 0;
            REG(FRC_CTRL) = 0;
            REG(FRC_CHANNEL_ON) = 0;
            REG(REG_13440) = 1;
            REG(REG_13444) &= ~4;
        }
        REG(FRC_CHANNEL_ON) = 1;
        REG(FRC_CTRL) = 1;
        REG(REG_11BF8) = 1;
        REG(FRC_REG_1808) = 0xff;
        timer_sleep_ticks(100);
        if (REG(FRC_REG_1808) & 3) {
            REG(FRC_CTRL) = 0;
            panel_wait_sync_pulse();
            REG(FRC_CHANNEL_ON) = 0;
            panel_wait_sync_pulse();
            REG(FRC_CTRL) = 1;
        }
        /* Leave the converter off when it was off before. */
        if (!frc_was_on) {
            REG(FRC_CTRL) = 0;
            REG(FRC_CHANNEL_ON) = 0;
            REG(REG_11BF8) = 0;
        }

        /* Phase 4: parameters of command 0x13. */
        REG(FWUPD_PARAM_F19A) = REG(REG_1188C);
        REG(FWUPD_PARAM_F19B) = REG(REG_11888);
        REG(FWUPD_PARAM_F19C) = REG(REG_11884);
        REG(FWUPD_PARAM_F19D) = REG(REG_11880);
        reg71_value = pq_block_read16(PICTURE_BLOCK_0, BLK_REG_71);
        reg75_value = pq_block_read16(PICTURE_BLOCK_0, BLK_REG_75);
        size_value = reg71_value * reg75_value * 3 / 0x5000 + 1;
        REG(FWUPD_PARAM_F19E) = (size_value >> 8) & 0xff;
        REG(FWUPD_PARAM_F19F) = size_value & 0xff;

        /* Phase 5: send the command and wait for the agent's mark. */
        port_cmd(1);
        while (RB(fwupd_active_port * 2 + FWUPD_PORT_COMMAND) != FWUPD_CMD_DONE_MARK)
            ipc_signal_alive();

        /* Phase 6: clear the command and restore. */
        port_cmd(0);
        REG(FRC_REG_1A84) = saved[0];
        REG(FRC_REG_1A88) = saved[1];
        REG(FRC_REG_1A8C) = saved[2];
        REG(REG_13440) = saved[3];
        REG(REG_13444) = saved[4];
        REG(FRC_REG_1D8C) = saved[5];
        REG(FRC_CHANNEL_ON) = saved[6];
        REG(FRC_CTRL) = saved[7];
        REG(CTRL_12E00) = saved[8];
        REG(REG_11BF8) = saved[9];
        REG(REG_116D4) = saved[10];
        REG(FRC_REG_1A80) = saved[11];
        pq_block_write8(PICTURE_BLOCK_0, BLK_REG_86, saved[12]);
        break;
    }
}
