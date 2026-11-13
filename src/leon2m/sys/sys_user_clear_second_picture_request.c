/* sys_user_clear_second_picture_request  (FUN_a00d5f3c)
 *
 * Clear a pending second-picture request and switch that picture off when it is not in use.
 * Name basis: descriptive - settings byte +0x4A and word +0xB0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d5f3c @ 0xa00d5f3c-0xa00d5f9c (24 words), flags -mcpu=v8 -O3 -g.
 * Source form: the record is reached through a pointer local. The clearing of byte +0x4A sits in the delay slot
 * of the +0x1F test, so it runs on both paths. The routine ends with a real 'nop' (inline asm) at the join
 * label before the return; it is a firmware instruction, not a delay slot.
 */
/* The fields of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0x1f];
    unsigned char pip_pbp_mode;             /* +0x1F: 0 = off */
    unsigned char pad20[0x4a - 0x20];
    unsigned char byte_0x4a;                /* +0x4A: non-zero = second picture requested */
    unsigned char pad4b[0xb0 - 0x4b];
    unsigned int blur_free_mode;            /* +0xB0 */
};
extern struct user_settings_record user_settings;
extern void sys_api_set_channel_source_enable(int channel, int enable);
extern void sys_api_enable_channel_port(int channel, int enable);

/*
 * When settings byte +0x4A and the blur-free mode word (+0xB0) are both not 0, clear byte +0x4A; and, if the
 * PIP/PBP mode is 0, switch the source and the port of channel 1 off.
 */
void sys_user_clear_second_picture_request(void)
{
  struct user_settings_record *p = &user_settings;

  if (p->byte_0x4a != 0 && p->blur_free_mode != 0) {
    p->byte_0x4a = 0;
    if (p->pip_pbp_mode == 0) {
      sys_api_set_channel_source_enable(1, 0);
      sys_api_enable_channel_port(1, 0);
    }
  }
  __asm__ volatile ("nop");
}
