/* startup_release_leon2m  (FUN_CODE_c544)
 *
 * Write the release byte that the main processor waits for at start-up.
 * Name basis: proven - portal word 0xB8 bits 15..8 (docs/MAP.md; main side ipc_8051_get_boot_source)
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_c544, OPTIMIZE(8,SPEED) LARGE.
 * Source form: 'release_byte << 8' is int arithmetic on an unsigned char (a char parameter adds a second sign extension,
 * a long cast gives ?C?LSHL). A value of 0x80 or more would also set bits 31..16; the callers pass 1, 2 and the wake word.
 */
extern void ipc_portal_read(unsigned char off, unsigned long *dst, unsigned char n);
extern void ipc_portal_write(unsigned char off, unsigned long *src, unsigned char n);
/*
 * startup_release_leon2m - read mailbox portal word 0xB8, replace bits 15..8 with release_byte and write it back.
 * The main processor's start-up code reads the same byte (docs/MAP.md).
 *   release_byte: 1 at start-up, 2 when 0xF0DD bit 2 was set, and the wake word on every wake-up (before run
 *   state 0xA770 becomes 2)
 * Caller: sys_main.
 */
void startup_release_leon2m(unsigned char release_byte)
{
    unsigned long word;
    ipc_portal_read(0xb8, &word, 1);
    word = (word & 0xffff00ff) | (release_byte << 8);
    ipc_portal_write(0xb8, &word, 1);
}
