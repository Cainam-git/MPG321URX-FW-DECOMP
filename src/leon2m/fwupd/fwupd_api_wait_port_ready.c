/* fwupd_api_wait_port_ready  (FUN_a0147c94)
 *
 * Wait, with a time limit, until one of the two update ports reports ready.
 * Returns: result of the poll
 * Name basis: descriptive - forwards to the bounded poll of 0xCF03C640/0xCF03C648; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0147c94 @ 0xa0147c94 (-mcpu=v8 -O2 -g).
 * Source form: the decompiler's form is kept: two unused parameters and an unsigned char return of the callee's int.
 */
typedef unsigned int undefined4;
extern int fwupd_port_wait_ready();

/*
 * Forward on to fwupd_port_wait_ready: wait, with a time limit, until one of the two update ports is ready.
 * Returns 1 when a port is ready, 0 on a pending input change or on timeout. Both parameters are unused.
 */
unsigned char fwupd_api_wait_port_ready(undefined4 unused_1, undefined4 unused_2)

{
  return fwupd_port_wait_ready();
}