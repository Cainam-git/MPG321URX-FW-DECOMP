/* sys_user_is_special_picture_state  (FUN_a00d7b60)
 *
 * Return 1 when the status field is 2 or port flag 9 of channel 0 is set.
 * Returns: 0 or 1
 * Name basis: descriptive - two state tests; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d7b60 @ 0xa00d7b60-0xa00d7bc0 (24 words), flags -mcpu=v8 -O2 -g.
 * Source form: both calls are always made (the result starts at 0 and is set by each test).
 */
extern unsigned char ipc_api_get_status_field(void);
extern unsigned char sys_api_get_channel_port_flag9(unsigned char channel);

/*
 * Return 1 when the 2-bit status field from the mailbox (ipc_api_get_status_field) is 2, or when flag bit 9 of
 * the port record that channel 0 is mapped to is set; otherwise return 0.
 */
int sys_user_is_special_picture_state(void)
{
    unsigned char result = 0;

    if (ipc_api_get_status_field() == 2)
        result = 1;
    if (sys_api_get_channel_port_flag9(0) == 1)
        result = 1;
    return result & 1;
}
