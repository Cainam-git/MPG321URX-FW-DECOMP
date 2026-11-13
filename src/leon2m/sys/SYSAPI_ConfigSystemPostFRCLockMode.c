/* SYSAPI_ConfigSystemPostFRCLockMode  (FUN_a0148e34)
 *
 * Switch the lock mode of the frame-rate converter output on or off.
 * Name basis: proven - prints 'SYSAPI_ConfigSystemPostFRCLockMode = %d' (original name)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0148e34 @ 0xa0148e34-0xa0148eb4 (32 words), flags -mcpu=v8 -O3 -g.
 * Source form: u8 parameter; the message text is a string literal; the working row is read through a struct
 * whose only used field is the halfword at +0x0A.
 */
/* Word 0 of the system configuration record: bit 27 is the lock mode of the frame-rate converter output. */
#define SYS_CONFIG_FRC_LOCK_MODE 0x8000000
/* Rows with an active-line value (+0x0A) at or above this limit never get the lock mode. */
#define FRC_LOCK_ACTIVE_LINES_LIMIT 0x1000

/* The working copy of the active panel timing row; only the field read here is named. */
struct panel_timing_row {
    unsigned char pad0[0x0A];
    unsigned short active_lines;        /* +0x0A */
};
extern struct panel_timing_row *panel_working_row_ptr;
extern unsigned int sys_config;
extern int dbg_printf();

/*
 * Switch the lock mode of the frame-rate converter output on or off, and log the request.
 *
 *   on  non-zero asks for the lock mode, 0 clears it
 *
 * The lock mode is only set when the active panel row has fewer than 0x1000 active lines; for a taller row the
 * bit is cleared whatever 'on' says.
 */
void SYSAPI_ConfigSystemPostFRCLockMode(unsigned char on)
{
    dbg_printf("SYSAPI_ConfigSystemPostFRCLockMode = %d \r\n", on);
    if (on) {
        if (panel_working_row_ptr->active_lines < FRC_LOCK_ACTIVE_LINES_LIMIT)
            sys_config |= SYS_CONFIG_FRC_LOCK_MODE;
        else
            sys_config &= ~SYS_CONFIG_FRC_LOCK_MODE;
    } else
        sys_config &= ~SYS_CONFIG_FRC_LOCK_MODE;
}
