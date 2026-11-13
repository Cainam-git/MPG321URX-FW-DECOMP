/* panel_api_get_brightness_level  (FUN_a014be10)
 *
 * Return the panel brightness value computed from the stored brightness setting.
 * Returns: brightness value
 * Name basis: derived - same formula as SetBrightness without the write; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014be10 @ 0xa014be10-0xa014bf64 (340 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: the mailbox status helper (ipc_api_get_status_field) is a static routine of this file and is
 * inlined; the port status bit 6 test is written '((status_bits & 0x40) >> 6) == 1' (an equality test, so the
 * compiler predicts it false and the branch block goes out of line); the blur-mode tests are separate else-if
 * arms with one body each; the divisions are unsigned.
 */
extern unsigned char ipc_get_status_field(void);
extern unsigned char input_port_get_status_bit9(unsigned char);

/* The records and settings this conversion reads. */
struct channel_record { unsigned int word0; unsigned char pad04[0x78 - 4]; };    /* bits 12..15 of word 0: the port of the channel */
struct port_record { unsigned short status_bits; unsigned char rest[0x2a - 2]; };  /* bit 6 and bit 9 are tested */
struct sys_config_record {
    unsigned char pad00[8];
    unsigned char brightness;           /* +0x08: the brightness setting */
    unsigned char pad09[0x38 - 9];
    unsigned int blurfree_mode;         /* +0x38: the blur-reduction mode (1 = GEN1, 2 = GEN2, else off) */
};

#define PORT_STATUS_BIT6      0x40
#define BLURFREE_GEN1         1
#define BLURFREE_GEN2         2
#define BRIGHTNESS_OFFSET     126       /* the lowest panel level value */
#define BRIGHTNESS_SCALE_BLURFREE 0x25f /* panel level span for 100 %, in both blur-reduction modes */
#define BRIGHTNESS_SCALE_OFF      0x381 /* the same with blur reduction off */
#define STATUS_FIELD_OUT_OF_RANGE 4

/* Status field of the mailbox portal 1, 0..3, or 4 for any other value. */
static unsigned char ipc_api_get_status_field(void)
{
    unsigned char status;

    switch (ipc_get_status_field()) {
    case 0:
        status = 0;
        break;
    case 1:
        status = 1;
        break;
    case 2:
        status = 2;
        break;
    case 3:
        status = 3;
        break;
    default:
        status = STATUS_FIELD_OUT_OF_RANGE;
        break;
    }
    return status;
}

extern struct channel_record channel_records[4];
extern struct port_record port_records[];
extern struct sys_config_record sys_config;
extern unsigned short part_record_brightness_max;

/*
 * Convert the brightness setting (sys_config +8, 0..100) to the panel level value that panel_api_set_brightness
 * sends to the OLED panel controller (the value that goes to oled_set_lum_gain), without sending it.
 * Returns that value.
 *
 * Value = (brightness * span + 50) / 100 + 126 (unsigned arithmetic), where span is:
 *   - (part_record_brightness_max - 126), when the main channel's port has status bit 6 set and the mailbox status
 *     field is not 0, or when input_port_get_status_bit9 is non-zero for that port (the port of channel 0 is
 *     bits 12..15 of the channel record's first word);
 *   - 0x25F, otherwise, in blur-reduction mode GEN1 or GEN2 (sys_config +0x38 is 1 or 2);
 *   - 0x381, otherwise.
 */
unsigned short panel_api_get_brightness_level(void)
{
    unsigned short level;

    if ((((port_records[(channel_records[0].word0 >> 12) & 0xf].status_bits & PORT_STATUS_BIT6) >> 6) == 1 && ipc_api_get_status_field() != 0)
        || input_port_get_status_bit9((channel_records[0].word0 >> 12) & 0xf)) {
        level = (unsigned int)(sys_config.brightness * (part_record_brightness_max - BRIGHTNESS_OFFSET) + 50) / 100 + BRIGHTNESS_OFFSET;
    } else if (sys_config.blurfree_mode == BLURFREE_GEN1) {
        level = (unsigned int)(sys_config.brightness * BRIGHTNESS_SCALE_BLURFREE + 50) / 100 + BRIGHTNESS_OFFSET;
    } else if (sys_config.blurfree_mode == BLURFREE_GEN2) {
        level = (unsigned int)(sys_config.brightness * BRIGHTNESS_SCALE_BLURFREE + 50) / 100 + BRIGHTNESS_OFFSET;
    } else {
        level = (unsigned int)(sys_config.brightness * BRIGHTNESS_SCALE_OFF + 50) / 100 + BRIGHTNESS_OFFSET;
    }
    return level;
}
