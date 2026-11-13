/* pq_api_set_gamma_and_reapply  (FUN_a014c794)
 *
 * Store the gamma selection, load that gamma and apply the picture mode again.
 * Name basis: derived - stSysConfig byte +0x18, then the routine that prints 'LoadGamma'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014c794 @ 0xa014c794-0xa014c7bc (10 words), flags -mcpu=v8 -O3 -g.
 * Source form: the record is reached through a local pointer; the picture mode is read from it after the gamma
 * load; the last call is a tail call.
 */

/* The system configuration record, up to the fields used here. */
struct sys_config_record {
    unsigned char pad[0xb];
    unsigned char picture_mode;         /* +0xB */
    unsigned char pad2[0xc];
    unsigned char gamma_selection;      /* +0x18 */
};
extern struct sys_config_record sys_config;
extern void pq_load_gamma(unsigned char);
extern void pq_apply_picture_mode(unsigned char);

/*
 * Store the gamma selection (sys_config byte +0x18), load that gamma table set (pq_load_gamma) and apply the
 * stored picture mode again (pq_apply_picture_mode).
 * The only caller is pq_user_apply_gamma.
 */
void pq_api_set_gamma_and_reapply(unsigned char gamma)
{
  struct sys_config_record *config = &sys_config;

  config->gamma_selection = gamma;
  pq_load_gamma(gamma);
  pq_apply_picture_mode(config->picture_mode);
}
