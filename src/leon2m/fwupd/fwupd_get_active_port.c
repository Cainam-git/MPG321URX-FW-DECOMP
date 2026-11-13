/* fwupd_get_active_port  (FUN_a0124168)
 *
 * Return which update port answered.
 * Returns: port
 * Name basis: derived - byte at 0xA802D87E, set by fwupd_port_wait_ready
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0124168 @ 0xa0124168, flags -mcpu=v8 -O2 -g (the section default). A leaf routine without a
 * register window.
 */
extern unsigned char fwupd_active_port;

/*
 * Return the update port (0 or 1) that answered, as set by fwupd_port_wait_ready.
 * Callers: fwupd_find_and_verify_file, fwupd_find_file.
 */
unsigned char fwupd_get_active_port(void)
{
  return fwupd_active_port;
}
