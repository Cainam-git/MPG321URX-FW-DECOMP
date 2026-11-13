/* nvram_write_fga_byte  (FUN_a012d4f8)
 *
 * Write one byte of the FGA block in the EEPROM.
 * Note: Writes the EEPROM.
 * Name basis: derived - offset taken from the device settings record
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012d4f8 @ 0xa012d4f8
 * Source form: fga_off as an inlined static helper with if/else, so the & 0x360 stays in the code.
 */
/* Where the FGA block lives: the fields +0x34..+0x37 of the device settings record (0x50 bytes). */
struct fga_location {
    unsigned char device;                       /* +0x34: first argument of nvram_write / nvram_read (fga_selector) */
    unsigned int address : 16;                  /* +0x35..+0x36: address of the block base */
    unsigned char layout;                       /* +0x37: 0 or 1 puts the block 0x120 further, else 0x240 */
};
struct device_settings_record {
    unsigned char before_fga[0x34];
    struct fga_location fga;
    unsigned char after_fga[0x18];
};
extern struct device_settings_record device_settings;

#define FGA_OFFSET_LAYOUT_LOW  0x120            /* block offset for layout 0 and 1 */
#define FGA_OFFSET_LAYOUT_HIGH 0x240            /* block offset for the other layouts */
#define FGA_OFFSET_MASK        0x360
extern void nvram_write(unsigned char, unsigned short, unsigned short, void *, unsigned char);

/* Offset of byte `sub` of the FGA block from the block base given by the device settings. */
static unsigned short fga_off(unsigned short sub)
{
    unsigned short offset;
    if (device_settings.fga.layout <= 1)
        offset = FGA_OFFSET_LAYOUT_LOW;
    else
        offset = FGA_OFFSET_LAYOUT_HIGH;
    return (offset & FGA_OFFSET_MASK) + sub;
}

/*
 * Write one byte to the start of the FGA block in the EEPROM: device, address and layout come from the device
 * settings record. The byte is passed by address, so the parameter lives in a stack slot.
 * Called by nvram_api_write_fga_byte.
 */
void nvram_write_fga_byte(unsigned char value)
{
    nvram_write(device_settings.fga.device, device_settings.fga.address + fga_off(0), 1, &value, 1);
}
