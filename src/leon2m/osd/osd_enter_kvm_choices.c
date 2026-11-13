/* osd_enter_kvm_choices  (FUN_a00994b8)
 *
 * Open the KVM list (Auto, Upstream, Type C) on the current setting.
 * Note: States 0x3C..0x3E; setting = settings byte +0x17C, saved in 0xA8025C56.
 * Name basis: derived - handler table 0xA802422C: OK/right on state 0x0B = 'KVM' (texts 0x18A360); texts
 *   0x1909EC: Auto, Upstream, Type C
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00994b8 @ 0xa00994b8-0xa0099524 (27 words), flags -mcpu=v8 -O3 -g.
 * Source form: the base of the settings record is kept in one pointer (the firmware shares one register for it);
 * the KVM byte is read again after the calls.
 */
struct user_settings_record { unsigned char pad[0x17c]; unsigned char kvm; /* +0x17C: KVM_AUTO 0, KVM_UPSTREAM 1, KVM_TYPE_C 2 */ };
extern struct user_settings_record user_settings;
extern unsigned char osd_choice_row;
extern unsigned int osd_menu_state;
extern unsigned char osd_request_bits;

extern void osd_draw_choice_mark(int, unsigned char, int);
extern void osd_highlight_item_row(unsigned char, int);
extern void osd_highlight_choice_row(unsigned char, int);

#define PAGE_GI_ITEMS            0x0b   /* first item state of the G.I. page; the KVM item is state 0x0B */
#define MENU_STATE_KVM_LIST_FIRST 0x3c  /* + KVM setting: the KVM list (Auto, Upstream, Type C; states 0x3C..0x3E) */
#define CHOICE_MARK_LIST         1      /* list kind of osd_draw_choice_mark: a choice list */
#define MARK_CLEAR               0
#define ITEM_ROW_LIST_OPEN       2      /* osd_highlight_item_row mode: parent of an open choice list */
#define CHOICE_ROW_EDGED         1      /* osd_highlight_choice_row style: with edge glyphs */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02 /* osd_request_bits bit 1: a setting was changed */

/*
 * OK or right on the KVM item of the G.I. page: open the KVM list at the setting now stored (settings byte +0x17C).
 *
 * The setting is saved in osd_choice_row so that the left key can put it back. Its mark is cleared, the item row
 * is highlighted in the "list open" style, the menu state becomes 0x3C plus the setting and the setting's row is
 * highlighted.
 */
void osd_enter_kvm_choices(void)
{
  struct user_settings_record *p;
  unsigned char kvm;

  p = &user_settings;
  kvm = p->kvm;
  osd_choice_row = kvm;
  osd_draw_choice_mark(CHOICE_MARK_LIST, kvm, MARK_CLEAR);
  osd_highlight_item_row((osd_menu_state - PAGE_GI_ITEMS) & 0xff, ITEM_ROW_LIST_OPEN);
  osd_menu_state = p->kvm + MENU_STATE_KVM_LIST_FIRST;
  osd_highlight_choice_row(p->kvm, CHOICE_ROW_EDGED);
  osd_request_bits = osd_request_bits | OSD_REQUEST_SETTINGS_CHANGED;
}
