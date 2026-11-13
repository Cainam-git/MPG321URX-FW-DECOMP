/* _hdmi_Init_Interrupt  (hdmi_Init_Interrupt)
 *
 * Set up the interrupts of both HDMI 2.1 receivers.
 * Returns: 0
 * Name basis: proven - original name printed ('[INIT]: %s' with '_hdmi_Init_Interrupt');
 *   irq_enable_hdmi_port0/1
 *
 * Matching notes
 * --------------
 * leon2s hdmi_Init_Interrupt @ 0xa00a2fd4, flags -mcpu=v8 -Os -g.
 * Source form: the function name is a separate static const char[] (the firmware keeps it apart from the
 * format string, like a __FUNCTION__ object in .rodata); the loop over the two receivers is a do-while with an
 * unsigned int counter truncated to a byte for the call and the test.
 */
/* hdmi_Init_Interrupt at 0xa00a2fd4 */

extern unsigned int dbg_hdmi_message_flags; /* 0xa8078634 */
extern void dbg_printf(const char *, const char *); /* 0xa0073044 */
extern void hdmi_rx21_set_event_reg78_bit9(void); /* 0xa00a0514 */
extern void hdmi_rx21_mask_all_events(unsigned char); /* 0xa00a2e48 */
extern void irq_enable_hdmi_port0(void); /* 0xa00b1980 */
extern void irq_enable_hdmi_port1(void); /* 0xa00b1a4c */

#define HDMI_MSG_INIT_INFO 1    /* dbg_hdmi_message_flags bit 0: the "[INIT]" lines */
#define HDMI21_RECEIVERS 2

static const char function_name[] = "_hdmi_Init_Interrupt";   /* the firmware keeps function names apart from the format strings */

/*
 * Set up the interrupts of the HDMI 2.1 receivers: print "[INIT]: _hdmi_Init_Interrupt" when the INIT debug
 * messages are on; set bit 9 of event register 0x78 (hdmi_rx21_set_event_reg78_bit9); disable all events of
 * receiver 0 and receiver 1 (hdmi_rx21_mask_all_events); then switch on the interrupt sources of HDMI input
 * 0 and input 1. Returns 0.
 */
int _hdmi_Init_Interrupt(void)
{
    if (dbg_hdmi_message_flags & HDMI_MSG_INIT_INFO) {
        dbg_printf("[INIT]: %s\n", function_name);
    }
    hdmi_rx21_set_event_reg78_bit9();
    {
        unsigned int receiver = 0;
        do {
            hdmi_rx21_mask_all_events((unsigned char)receiver);
            receiver++;
        } while ((unsigned char)receiver < HDMI21_RECEIVERS);
    }
    irq_enable_hdmi_port0();
    irq_enable_hdmi_port1();
    return 0;
}
