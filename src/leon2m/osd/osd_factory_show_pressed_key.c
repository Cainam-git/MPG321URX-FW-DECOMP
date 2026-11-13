/* osd_factory_show_pressed_key  (FUN_a008ad20)
 *
 * Show the number of the front key just pressed and log it for the factory key test.
 * Note: Saves the key-test record (EEPROM 0x2E0, 0x1C bytes) after each new key; value 0x3F = all six keys
 *   seen.
 * Name basis: derived - ROM texts 'Key', 'Pressed', '%1d'; ORs the key bit into the record saved by
 *   SYSAPI_WriteEEPROM
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008ad20 @ 0xa008ad20-0xa008b2bc (359 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the digit block (DIGIT) and the three-call block (LABELS) are macros: the firmware holds twelve copies of the
 *    digit block (0xa008ae30-0xa008b218), and with static helper functions GCC stops inlining at its
 *    inline-unit-growth limit in this one-function file;
 *  - each arm of the compare chain carries its own OR and its own LABELS (one copy in the firmware at
 *    0xa008adac-0xa008ae2c; the three calls are shared with the switch path from 0xa008ade0);
 *  - the "not all keys seen" arm is written first (the firmware falls through into it at 0xa008ad38);
 *  - the all-keys-seen case is a switch (jump table at 0x2a2d8).
 */

/* Key test: the front keys, in the order of the digits shown. Each key has one bit in app_state_record
   pressed_key_bit; the key test collects them in factory_record key_test_bits. */
#define KEY_BIT_1             2         /* digit 1 */
#define KEY_BIT_2             4         /* digit 2 */
#define KEY_BIT_3             8         /* digit 3 */
#define KEY_BIT_4             0x10      /* digit 4 */
#define KEY_BIT_5             0x20      /* digit 5 */
#define KEY_BIT_6             1         /* digit 6 */
#define KEY_TEST_ALL_KEYS     0x3f      /* key_test_bits when all six keys have been pressed */

/* factory_record +0x10: one bit per key passed in the key test. */
#define key_test_bits                 factory_record[0x10]
#define FACTORY_RECORD_OFFSET         0x2e0     /* where the record is stored in the EEPROM area */
#define FACTORY_RECORD_SIZE           0x1c
#define EEPROM_AREA_SETTINGS          0x30      /* first argument of SYSAPI_WriteEEPROM */

/* Where the key number is drawn: row 9, column 4, one cell. */
#define KEY_DIGIT_COL         4
#define KEY_ROW               9

/* The font code of a digit is its character code minus 47 ('0' = 1); a blank is code 0. */
#define FONT_CODE_BLANK       0
#define FONT_CODE_OFFSET      47

/* The part of the application state record used here. */
struct app_state_record_head {          /* app_state_record, 0xA802CFF4 */
  unsigned short flags_0x0;
  unsigned char pad2[4];
  unsigned char pressed_key_bit;        /* +0x06: key bit of the last key read */
};

extern struct app_state_record_head app_state_record;
extern unsigned char factory_record[];
extern const char s_00100328[];

extern void sprintf(unsigned char *, const char *, unsigned short);
extern void osd_api_write_cell_bytes(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char *, unsigned char);
extern void osd_api_set_glyph_write_address(unsigned short, unsigned char);
extern void osd_draw_text(unsigned char, unsigned short, unsigned short, unsigned char, const char *, unsigned char);
extern int SYSAPI_WriteEEPROM(unsigned char, void *, unsigned short, unsigned short);

/* Draw the number n (one digit) at the key-number position, as a font code. */
#define DIGIT(n) {                                  \
    unsigned char digit[1];                         \
    unsigned char i;                                \
                                                    \
    sprintf(digit, "%1d", n);                       \
    for (i = 0; i < 1; i++) {                       \
      if (digit[i] == ' ')                          \
        digit[i] = FONT_CODE_BLANK;                 \
      else                                          \
        digit[i] -= FONT_CODE_OFFSET;               \
    }                                               \
    osd_api_write_cell_bytes(0, KEY_DIGIT_COL, KEY_ROW, 1, digit, 0);   \
  }

/* The two texts beside the number: the word "Key" (column 1, 3 cells) and the ROM text at 0x100328
   (column 6, 7 cells). */
#define LABELS() {                                  \
    osd_api_set_glyph_write_address(0xc8, 0);       \
    osd_draw_text(0, 1, KEY_ROW, 3, "\003" "Key", 0);   \
    osd_draw_text(0, 6, KEY_ROW, 7, s_00100328, 0); \
  }

/* Factory key test: show which front key was just pressed and record it. The key comes from
 * app_state_record.pressed_key_bit (no parameters, no return value). The key bit maps to a number 1..6.
 *  - While not all six keys have been seen (key_test_bits != 0x3f): a known key draws its number and the two
 *    texts, and its bit is added to key_test_bits. A bit that is none of the six draws nothing.
 *  - When all six have been seen: the number of the key is drawn again (nothing for an unknown bit), the texts
 *    are drawn in any case, and key_test_bits stays as it is.
 * Both paths end by writing the 0x1C-byte factory record to EEPROM offset 0x2E0.
 */
void osd_factory_show_pressed_key(void)
{
  if (key_test_bits != KEY_TEST_ALL_KEYS) {
    if (app_state_record.pressed_key_bit == KEY_BIT_1) {
      DIGIT(1);
      key_test_bits |= app_state_record.pressed_key_bit;
      LABELS();
    } else if (app_state_record.pressed_key_bit == KEY_BIT_2) {
      DIGIT(2);
      key_test_bits |= app_state_record.pressed_key_bit;
      LABELS();
    } else if (app_state_record.pressed_key_bit == KEY_BIT_3) {
      DIGIT(3);
      key_test_bits |= app_state_record.pressed_key_bit;
      LABELS();
    } else if (app_state_record.pressed_key_bit == KEY_BIT_4) {
      DIGIT(4);
      key_test_bits |= app_state_record.pressed_key_bit;
      LABELS();
    } else if (app_state_record.pressed_key_bit == KEY_BIT_5) {
      DIGIT(5);
      key_test_bits |= app_state_record.pressed_key_bit;
      LABELS();
    } else if (app_state_record.pressed_key_bit == KEY_BIT_6) {
      DIGIT(6);
      key_test_bits |= app_state_record.pressed_key_bit;
      LABELS();
    }
  } else {
    switch (app_state_record.pressed_key_bit) {
    case KEY_BIT_1:
      DIGIT(1);
      break;
    case KEY_BIT_2:
      DIGIT(2);
      break;
    case KEY_BIT_3:
      DIGIT(3);
      break;
    case KEY_BIT_4:
      DIGIT(4);
      break;
    case KEY_BIT_5:
      DIGIT(5);
      break;
    case KEY_BIT_6:
      DIGIT(6);
      break;
    }
    LABELS();
  }
  SYSAPI_WriteEEPROM(EEPROM_AREA_SETTINGS, factory_record, FACTORY_RECORD_OFFSET, FACTORY_RECORD_SIZE);
}
