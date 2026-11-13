/* pq_api_set_response_level  (FUN_a014913c)
 *
 * Store the level byte and apply it; level 5 only switches the function off.
 * Name basis: descriptive - stSysConfig byte +0x1C; clears the block at 0xCF012E80, then loads the table for
 *   the level
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014913c @ 0xa014913c-0xa0149178 (15 words), flags -mcpu=v8 -O2 -g.
 * Source form: the record is reached through a local pointer, and the level passed on is read back from the
 * record; both arms end in a tail call.
 */

/* The system configuration record, up to the field used here. */
struct sys_config_record {
    unsigned char pad[0x1c];
    unsigned char response_level;       /* +0x1C */
};
extern struct sys_config_record sys_config;
extern void pq_block8_stop(void);
extern void pq_apply_response_level(unsigned char);

#define RESPONSE_LEVEL_OFF 5            /* only stops picture block 8 */

/*
 * Store the response level in sys_config and apply it through picture block 8.
 *
 *   level  RESPONSE_LEVEL_OFF: the block is stopped and stays stopped; any other value: the block is stopped,
 *          the level applied (pq_apply_response_level) and the block started again
 *
 * Callers: panel_blurfree_apply_user_mode, pq_user_reset_response_level (RESPONSE_LEVEL_OFF), UserSetProMode,
 * UserSetGameMode and sys_user_factory_reset.
 */
void pq_api_set_response_level(unsigned char level)
{
  struct sys_config_record *config = &sys_config;

  config->response_level = level;
  if (level != RESPONSE_LEVEL_OFF) {
    pq_block8_stop();
    pq_apply_response_level(config->response_level);
    return;
  }
  pq_block8_stop();
}
