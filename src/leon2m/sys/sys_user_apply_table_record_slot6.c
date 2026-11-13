/* sys_user_apply_table_record_slot6  (FUN_a00d5a9c)
 *
 * Pass the record chosen by a settings byte to the slot 6 routine.
 * Name basis: descriptive - twin of sys_user_apply_table_record_slot5; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d5a9c @ 0xa00d5a9c-0xa00d5b10 (29 words), flags -mcpu=v8 -O3 -g.
 * Source form: same as sys_user_apply_table_record_slot5 (a plain structure assignment, copied halfword by halfword).
 */
/* One 16-byte record of the table at 0x198488 (eight halfwords, no field is named). */
struct slot_record {
    unsigned short h[8];
};
extern const struct slot_record sys_user_slot_records[];
extern unsigned char user_settings_byte_0x28;
extern void sys_poll_events_stub_copy21(int channel, struct slot_record *record);

/*
 * Copy the record that settings byte +0x28 selects from the table at 0x198488 and pass it, with channel
 * number 6, to a routine that is empty in this firmware. Nothing calls this routine.
 */
void sys_user_apply_table_record_slot6(void)
{
    struct slot_record r = sys_user_slot_records[user_settings_byte_0x28];

    sys_poll_events_stub_copy21(6, &r);
}
