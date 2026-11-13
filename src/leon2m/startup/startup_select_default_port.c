/* startup_select_default_port  (FUN_a012fc04)
 *
 * Give channel 0 the port with code 0x61.
 * Name basis: derived - sys_set_channel_port(0, 0x61, 1); called from start-up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012fc04 @ 0xa012fc04 (-mcpu=v8 -O2 -g)
 * Source form: a single call; the prototype of sys_set_channel_port is left open (no parameter list), as the
 * firmware's code needs.
 */
extern int sys_set_channel_port();

#define MAIN_CHANNEL 0                          /* channel 0: the main picture */
#define PORT_CODE_DEFAULT 0x61                  /* port code given to the main channel at start-up */
#define FORCE_UPDATE 1                          /* update even when the port record already holds the code */

/* Start-up step 7 (startup_bring_up_system): the main channel gets port code 0x61. */
void startup_select_default_port(void)
{
  sys_set_channel_port(MAIN_CHANNEL, PORT_CODE_DEFAULT, FORCE_UPDATE);
}
