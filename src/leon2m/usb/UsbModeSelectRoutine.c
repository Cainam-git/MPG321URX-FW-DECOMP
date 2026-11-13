/* UsbModeSelectRoutine  (FUN_a0083ff0)
 *
 * Pick the USB upstream port from the cable-sense inputs and the KVM setting; track the hub condition.
 * Note: Hub condition on: starts app timer 0x16 and sets bit 11 of app state +4 ("OT2211 Power ON"); off:
 *   calls an empty routine ("OT2211 Power OFF"). No hub pin is switched here.
 * Name basis: proven - prints '[UsbModeSelectRoutine] OT2211 Power ON/OFF' (original name from the text)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0083ff0 @ 0xA0083FF0..0xA0084330 (208 words) "UsbModeSelectRoutine", flags -mcpu=v8 -O3 -g
 * (-msoft-float gives the same code).
 * Source forms the exact build depends on:
 *  - the cable-sense test as 'int cable_in = a() || b(); if (!cable_in) {none} else {chosen}'. With a plain
 *    'if (a || b)' the 'chosen' block's label has one use, and the compiler keeps the address of user_settings
 *    live into that block (other register allocation); with '!a && !b' the label has two uses but the 'none'
 *    block falls through. The flag form gives both;
 *  - the start value as '(burn_in - 1) & last_mode' with burn_in = (burn_in_flag != 0), and the forced choices
 *    as '(pin != 0) - 1' and '((pin != 0) - 1) | 1'.
 */

/* The KVM setting (user settings +0x17C); the menu lists the three choices as Auto, Upstream, Type C. */
enum {
    KVM_AUTO     = 0,       /* chosen here from the cable-sense inputs and the shown input */
    KVM_UPSTREAM = 1,
    KVM_TYPE_C   = 2        /* every value from 2 up is treated as this one */
};

/* Values of usb_mode_select: the level put on GPIO 5.0, or none. */
#define USB_MODE_0      0
#define USB_MODE_1      1
#define USB_MODE_NONE   0xff        /* no upstream: GPIO 7.7 released high */

/* Menu states in which nothing is switched: the KVM list is open (0x3C..0x3E, one state per choice), or the
   KVM quick menu of the Navi keys. */
#define MENU_STATE_KVM_LIST_FIRST   0x3c
#define MENU_STATE_KVM_LIST_LAST    0x3e
#define MENU_STATE_NAVI_KVM         0x104

#define CHANNEL_STATE_CODE_10       10      /* value of sys_api_get_channel_state_code tested here */
#define PORT_CODE_0D                0xd     /* port code of the shown input that gives USB_MODE_1 */

#define SETTINGS_WORD0_BIT9         0x200   /* user settings word +0, bit 9 */
#define SETTINGS_POWER_BUTTON_STANDBY 0x8000 /* user settings +0xA8 bit 15 */
#define FACTORY_MODE_MARKER         0x55aa  /* user settings +0x1F6 while factory mode is on */
#define SETTINGS_BYTE_0x1D6_MARK    0x55    /* value of settings byte +0x1D6 tested with the marker */
#define PIP_PBP_MODE_PBP            2       /* user settings +0x1F: 0 off, 1 PIP, 2 PBP */

#define APP_TIMER_USB_HUB_POWER_ON  0x16    /* the timer task ends the wait when it runs out */
#define USB_HUB_POWER_ON_MS         1000
#define SLEEP_WORD_USB_HUB_POWER_ON 0x800   /* app_state_record word +4, bit 11 */

struct user_settings_record
{
  unsigned int word_0x0;                    /* +0x000: SETTINGS_WORD0_* */
  unsigned char p004[0x1a];
  unsigned char input_source;               /* +0x01E Input Source (menu index) */
  unsigned char pip_pbp_mode;               /* +0x01F 0 off, 1 PIP, 2 PBP */
  unsigned char p020[0x88];
  unsigned int gaming_flags;                /* +0x0A8 */
  unsigned char p0ac[0xd0];
  unsigned char kvm;                        /* +0x17C KVM_* */
  unsigned char p17d[0x58];
  unsigned char burn_in_flag;               /* +0x1D5 burn-in mode on (1) or off (0) */
  unsigned char byte_0x1d6;                 /* +0x1D6 */
  unsigned char p1d7[0x1f];
  unsigned short factory_marker;            /* +0x1F6 FACTORY_MODE_MARKER while factory mode is on */
};
struct app_state_record
{
  unsigned short half_0x0;
  unsigned short half_0x2;
  unsigned short sleep_word;                /* +4: SLEEP_WORD_USB_HUB_POWER_ON */
};
extern struct user_settings_record user_settings;
extern struct app_state_record app_state_record;
extern unsigned char factory_record_byte_0x14;
extern unsigned char usb_mode_select;
extern unsigned char usb_hub_pbp_flag;
extern unsigned char usb_hub_factory_flag;
extern unsigned short osd_get_menu_state(void);
extern unsigned char gpio_is_port7_bit3_high(void);
extern unsigned char gpio_is_port11_bit1_low(void);
extern unsigned char sys_api_get_channel_state_code(int);
extern unsigned char input_api_get_channel_port_code(int);
extern void gpio_set_port7_bit7_inverted(unsigned char);
extern void gpio_set_port5_bit0(unsigned char);
extern void gpio_pulse_port7_bit7(void);
extern void sys_poll_events_stub_copy8(int);
extern void sys_app_timer_start(int, int);
extern int dbg_printf(const char *, ...);

/*
 * Choose the USB upstream value and switch the OT2211 hub power when its conditions change.
 *
 *   force  1: forget the last choice first, so the pins are driven again even when the value is the same.
 *          The only caller, sys_run_app_timer_task (main loop), passes 0.
 *
 * Phases:
 *   1. Leave everything as it is while the KVM list or the KVM quick menu is open.
 *   2. Start from the last value (from USB_MODE_0 while burn-in mode is on) and choose by the KVM setting:
 *      Upstream: USB_MODE_0 when GPIO 7.3 reads high, else none;
 *      Type C:   USB_MODE_1 when GPIO 11.1 reads low, else none;
 *      Auto:     no cable-sense input active: none, or USB_MODE_0 in factory mode with settings byte
 *                +0x1D6 = 0x55; an input active: by the port code of the input on channel 0, or (settings
 *                word 0 bit 9 set and +0xA8 bit 15 set) by the Input Source setting; else the start value.
 *   3. When the value changed: drive GPIO 5.0 and pulse GPIO 7.7, or for none release GPIO 7.7 high and set
 *      GPIO 5.0 by the KVM setting. Print the new value.
 *   4. Hub power: on while PIP/PBP is set to PBP, or while factory record byte +0x14 is 1 in factory mode.
 *      When one of the two conditions changed: on starts APP_TIMER_USB_HUB_POWER_ON and sets
 *      SLEEP_WORD_USB_HUB_POWER_ON (the timer task clears it when the timer runs out); off calls
 *      sys_poll_events_stub_copy8(0), which does nothing. Keep the three values for the next run.
 *
 * Nothing here waits except gpio_pulse_port7_bit7 (200 ticks). Only GPIO lines are driven; no message goes to
 * another processor.
 */
void UsbModeSelectRoutine(unsigned char force)
{
  unsigned char usb_mode;
  unsigned char pbp_on;
  unsigned char factory_on;
  unsigned char last_mode;

  /* 1. Not while the user is choosing a KVM setting. */
  if (osd_get_menu_state() > MENU_STATE_KVM_LIST_FIRST - 1 && osd_get_menu_state() < MENU_STATE_KVM_LIST_LAST + 1)
    return;
  if (osd_get_menu_state() == MENU_STATE_NAVI_KVM)
    return;
  if (force == 1)
    usb_mode_select = USB_MODE_NONE;
  last_mode = usb_mode_select;
  /* 2. Start value: the last value, or USB_MODE_0 while burn-in mode is on. */
  {
    unsigned char burn_in = user_settings.burn_in_flag != 0;
    usb_mode = (burn_in - 1) & last_mode;
  }
  if (user_settings.kvm == KVM_AUTO)
    {
      int cable_in = gpio_is_port7_bit3_high() || gpio_is_port11_bit1_low();
      if (!cable_in)
        {
          /* Nothing plugged in: no upstream, except in factory mode with byte +0x1D6 set to 0x55. */
          usb_mode = USB_MODE_NONE;
          if (user_settings.factory_marker == FACTORY_MODE_MARKER)
            {
              usb_mode = USB_MODE_0;
              if (user_settings.byte_0x1d6 != SETTINGS_BYTE_0x1D6_MARK)
                usb_mode = USB_MODE_NONE;
            }
        }
      else
        {
          unsigned char channel_state = sys_api_get_channel_state_code(0);
          if (channel_state == CHANNEL_STATE_CODE_10 || !(user_settings.word_0x0 & SETTINGS_WORD0_BIT9))
            /* Follow the input shown on channel 0. */
            usb_mode = input_api_get_channel_port_code(0) == PORT_CODE_0D;
          else if (user_settings.gaming_flags & SETTINGS_POWER_BUTTON_STANDBY)
            {
              /* Follow the Input Source setting; any other source keeps the start value. */
              if (user_settings.input_source == 0xd)
                usb_mode = USB_MODE_1;
              else if (user_settings.input_source == 0xc)
                usb_mode = USB_MODE_0;
              else if (user_settings.input_source == 5)
                usb_mode = USB_MODE_0;
              else if (user_settings.input_source == 6)
                usb_mode = USB_MODE_0;
            }
        }
    }
  else if (user_settings.kvm == KVM_UPSTREAM)
    /* USB_MODE_0 when GPIO 7.3 reads high, else none. */
    usb_mode = (gpio_is_port7_bit3_high() != 0) - 1;
  else
    /* Type C: USB_MODE_1 when GPIO 11.1 reads low, else none. */
    usb_mode = ((gpio_is_port11_bit1_low() != 0) - 1) | 1;
  /* 3. Drive the mode pins only when the value changed. */
  if (usb_mode != usb_mode_select)
    {
      if (usb_mode == USB_MODE_NONE)
        {
          gpio_set_port7_bit7_inverted(0);
          if (user_settings.kvm == KVM_UPSTREAM)
            gpio_set_port5_bit0(0);
          else if (user_settings.kvm == KVM_TYPE_C)
            gpio_set_port5_bit0(1);
        }
      else
        {
          gpio_set_port5_bit0(usb_mode);
          gpio_pulse_port7_bit7();
        }
      dbg_printf("UsbModeSelect = %d \r\n", usb_mode);
    }
  /* 4. The two conditions that keep the OT2211 hub powered. */
  pbp_on = user_settings.pip_pbp_mode == PIP_PBP_MODE_PBP;
  if (factory_record_byte_0x14 != 1 || user_settings.factory_marker != FACTORY_MODE_MARKER)
    factory_on = 0;
  else
    factory_on = 1;
  if (usb_hub_pbp_flag != pbp_on || usb_hub_factory_flag != factory_on)
    {
      if (pbp_on | factory_on)
        {
          sys_app_timer_start(APP_TIMER_USB_HUB_POWER_ON, USB_HUB_POWER_ON_MS);
          app_state_record.sleep_word |= SLEEP_WORD_USB_HUB_POWER_ON;
          dbg_printf("[UsbModeSelectRoutine] OT2211 Power ON \r\n");
        }
      else
        {
          sys_poll_events_stub_copy8(0);
          dbg_printf("[UsbModeSelectRoutine] OT2211 Power OFF \r\n");
        }
    }
  usb_hub_pbp_flag = pbp_on;
  usb_hub_factory_flag = factory_on;
  usb_mode_select = usb_mode;
}
