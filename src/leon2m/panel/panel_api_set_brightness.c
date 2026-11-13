/* panel_api_set_brightness  (FUN_a014bf64)
 *
 * Store the brightness setting, convert it to the panel value and send it to the panel.
 * Name basis: proven - contains an inlined copy of SetBrightness (prints 'SetBrightness %d')
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014bf64 @ 0xa014bf64-0xa014c118 (436 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: as panel_api_get_brightness_level: the mailbox status helper is static and inlined; the port
 * status bit 6 test is the equality '((status_bits & 0x40) >> 6) == 1'; every arm has its own print and call, and
 * the blur-mode tests are separate else-if arms; the level is an unsigned short computed with unsigned
 * divisions. The last call is a tail call.
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
extern int dbg_printf(const char *, ...);
extern void oled_set_lum_gain(unsigned short val);

/*
 * Store the brightness setting in the system configuration (sys_config +8), convert it to the panel level value,
 * print "SetBrightness <level>" and send the level to the OLED panel controller (oled_set_lum_gain).
 *
 *   brightness  the new setting, 0..100
 *
 * The conversion is the one of panel_api_get_brightness_level: level = (brightness * span + 50) / 100 + 126,
 * with span = (part_record_brightness_max - 126) when the main channel's port has status bit 6 set and the mailbox
 * status field is not 0 (or input_port_get_status_bit9 is non-zero for the port), else 0x25F in blur-reduction
 * mode GEN1 or GEN2, else 0x381.
 */
void panel_api_set_brightness(unsigned char brightness)
{
    unsigned short level;

    sys_config.brightness = brightness;
    if ((((port_records[(channel_records[0].word0 >> 12) & 0xf].status_bits & PORT_STATUS_BIT6) >> 6) == 1 && ipc_api_get_status_field() != 0)
        || input_port_get_status_bit9((channel_records[0].word0 >> 12) & 0xf)) {
        level = (unsigned int)(sys_config.brightness * (part_record_brightness_max - BRIGHTNESS_OFFSET) + 50) / 100 + BRIGHTNESS_OFFSET;
        dbg_printf("SetBrightness %d\r\n", level);
        oled_set_lum_gain(level);
    } else if (sys_config.blurfree_mode == BLURFREE_GEN1) {
        level = (unsigned int)(sys_config.brightness * BRIGHTNESS_SCALE_BLURFREE + 50) / 100 + BRIGHTNESS_OFFSET;
        dbg_printf("SetBrightness %d\r\n", level);
        oled_set_lum_gain(level);
    } else if (sys_config.blurfree_mode == BLURFREE_GEN2) {
        level = (unsigned int)(sys_config.brightness * BRIGHTNESS_SCALE_BLURFREE + 50) / 100 + BRIGHTNESS_OFFSET;
        dbg_printf("SetBrightness %d\r\n", level);
        oled_set_lum_gain(level);
    } else {
        level = (unsigned int)(sys_config.brightness * BRIGHTNESS_SCALE_OFF + 50) / 100 + BRIGHTNESS_OFFSET;
        dbg_printf("SetBrightness %d\r\n", level);
        oled_set_lum_gain(level);
    }
}
