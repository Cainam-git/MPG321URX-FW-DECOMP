/* sys_api_set_channel_source_enable  (FUN_a014d474)
 *
 * Set or clear the enable bit of the source class that a channel uses.
 * Name basis: descriptive - channel 0..3 mapped to source class 1..3, bit 7 of 0xCF011AA4/AA8/AAC
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014d474 @ 0xa014d474 (-mcpu=v8 -O3 -g).
 * Source form: the switch lists the cases in the order 1, 0, 2, 3, which is the branch order of the exact build.
 * The decompiler's int signatures and the 'return 0' in the void routine are kept; the last call is a tail call.
 */
extern int dbg_printf();
extern int sys_frc_set_source_class_enable();
extern int sys_get_channel_source_class(unsigned int);

#define CHANNEL_NONE 0xff       /* the value the remap gives to a number that is no channel */

/*
 * Set or clear the frame-rate converter enable bit of the source class that a channel uses.
 *
 *   channel  channel number 0..3; any other value prints "SYS remapping channel OOR" and channel 0 is used
 *   enable   the value passed on to sys_frc_set_source_class_enable
 */
void sys_api_set_channel_source_enable(unsigned char channel, unsigned char enable)
{
    unsigned char remapped;
    
    switch (channel) {
    case 1:
        remapped = 1;
        break;
    case 0:
        remapped = 0;
        break;
    case 2:
        remapped = 2;
        break;
    case 3:
        remapped = 3;
        break;
    default:
        remapped = CHANNEL_NONE;
        break;
    }
    
    remapped = remapped & 0xff;
    if (remapped > 3) {
        dbg_printf("SYS remapping channel OOR\r\n");
        remapped = 0;
    }
    
    sys_frc_set_source_class_enable(sys_get_channel_source_class(remapped) & 0xff, enable);
    return 0;
}
