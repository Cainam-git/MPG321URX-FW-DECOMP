/* dbg_set_hdmi_message_flags  (EN_HDMI_MSG_INIT_INFO)
 *
 * Switch HDMI debug message groups on or off and list their state.
 *   arg: {group, on}
 * Note: Label EN_HDMI_MSG_INIT_INFO is the first group name, not the routine name.
 * Name basis: proven - prints the 15 groups from EN_HDMI_MSG_INIT_INFO as ON/OFF; flags word 0xA8078634
 *
 * Matching notes
 * --------------
 * EN_HDMI_MSG_INIT_INFO (leon2s 0xa00a317c-0xa00a3250, 212 bytes), flags -mcpu=v8 -Os -g.
 */
/* The argument block of the console command: the group number and the new state. */
struct hdmi_message_command {
    unsigned int group;                         /* 0..14 = one message group, 15 = all groups off */
    unsigned char on;                           /* 1 = switch the group on, anything else = off */
};
extern unsigned int dbg_hdmi_message_flags;
extern char DAT_a006b940[], DAT_a006b960[], DAT_a006b990[], DAT_a006b998[];
extern char *dbg_hdmi_message_group_names[];
extern int dbg_print_string(const char *);
extern int dbg_printf(const char *, ...);

/*
 * Debug console command: switch an HDMI debug message group on or off, then list all groups.
 *
 * Bit n of dbg_hdmi_message_flags enables the messages of group n (the group names are in
 * dbg_hdmi_message_group_names). A group number above 15 only prints a text and changes nothing; 15 clears all
 * flags. The listing then prints "<name> (ON)" or "<name> (OFF)" for groups 0..14.
 * The routine's label is the name of the first group, not a name for the routine.
 */
void dbg_set_hdmi_message_flags(struct hdmi_message_command *arg)
{
    unsigned int group = arg->group;
    unsigned int i;

    if (group > 15) {
        dbg_print_string(DAT_a006b940);  /* "Not Support HDMI Debug Msg" */
        return;
    }
    if (group == 15) {
        dbg_hdmi_message_flags = 0;
        dbg_print_string(DAT_a006b960);  /* "Disable All HDMI Debug Msg" */
    } else if (arg->on == 1) {
        dbg_hdmi_message_flags |= 1 << group;
    } else {
        dbg_hdmi_message_flags &= ~(1 << group);
    }
    /* Print every group with its state; DAT_a006b990 = "ON", DAT_a006b998 = "OFF". */
    for (i = 0; i < 15; i++)
        dbg_printf("%s (%s)\n", dbg_hdmi_message_group_names[i], (dbg_hdmi_message_flags & (1 << i)) ? DAT_a006b990 : DAT_a006b998);
}
