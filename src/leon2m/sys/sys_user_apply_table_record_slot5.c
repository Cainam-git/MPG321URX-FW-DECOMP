/* sys_user_apply_table_record_slot5  (FUN_a00d5a28)
 *
 * Pass the record chosen by a settings byte to the slot 5 routine.
 * Name basis: descriptive - 16-byte record from the table at 0x198488; the receiving routine is empty in this
 *   firmware; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d5a28 @ 0xa00d5a28-0xa00d5a9c (29 words), flags -mcpu=v8 -O3 -g.
 * Source form: the record is copied with a plain structure assignment; GCC copies it halfword by halfword
 * because the record only has 2-byte alignment.
 */
/* One 16-byte record of the table at 0x198488 (eight halfwords, no field is named). */
struct slot_record {
    unsigned short h[8];
};
extern const struct slot_record sys_user_slot_records[];
extern unsigned char user_settings_byte_0x27;
extern void sys_poll_events_stub_copy21(int channel, struct slot_record *record);

/*
 * Copy the record that settings byte +0x27 selects from the table at 0x198488 and pass it, with channel
 * number 5, to a routine that is empty in this firmware. Nothing calls this routine.
 */
void sys_user_apply_table_record_slot5(void)
{
    struct slot_record r = sys_user_slot_records[user_settings_byte_0x27];

    sys_poll_events_stub_copy21(5, &r);
}
