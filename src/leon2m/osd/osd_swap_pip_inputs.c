/* osd_swap_pip_inputs  (FUN_a0097cb4)
 *
 * Swap the main and sub-window inputs (Display Switch)
 * Note: Forwards to sys_user_swap_pip_sources, which swaps settings bytes +0x1E and +0x20.
 * Name basis: derived - handler table 0xA802422C: OK on state 0x7D = 'Display Switch'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0097cb4 @ 0xa0097cb4 (-mcpu=v8 -O2 -g)
 * Source form: the decompiler's six-parameter prototype is kept; all six are passed on to the call of
 * sys_user_swap_pip_sources, which is declared without a parameter list. The flags are -O2, not the -O3 of
 * the neighbours.
 */
extern int sys_user_swap_pip_sources();

/*
 * OK on Display Switch in the PIP list (menu state 0x7D): swap the main and the sub-window input.
 *
 * The routine only calls sys_user_swap_pip_sources. The six parameters are not used by the routine itself;
 * they are passed on unchanged. osd_swap_pip_inputs_copy has the same body at another address.
 */
void osd_swap_pip_inputs(unsigned int forwarded_1,unsigned int forwarded_2,unsigned int forwarded_3,
                 unsigned int forwarded_4,unsigned int forwarded_5,unsigned int forwarded_6)

{
  sys_user_swap_pip_sources(forwarded_1,forwarded_2,forwarded_3,forwarded_4,forwarded_5,forwarded_6);
  return;
}
