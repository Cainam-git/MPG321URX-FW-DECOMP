/* UserSwitchEDID  (FUN_a00d99f8)
 *
 * Choose the EDID variant that fits the user's settings and load it into the inputs.
 * Name basis: proven - prints 'UserSwitchEDID (%x %x)' (original name)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d99f8 @ 0xa00d99f8-0xa00d9fdc (145 words), flags -mcpu=v8 -O3 -g; the switch uses the jump table
 * at 0xa00d3b44.
 * Source forms the exact build depends on:
 *  - bit 31 of word +0x1F4 is a signed 1-bit bit-field (dsc_switch); an unsigned mask or field gives a sign-bit
 *    or shift test instead of the and / addx sequence;
 *  - the arm for bit 7 clear comes before the arm for bit 7 set; in variants 10..13 the '!ports' arm comes
 *    first, and the default arm tests EDID_PORTS_ALL, EDID_PORTS_5_6, EDID_PORTS_C_D in that order.
 */

/* EDID variants (edid_user_variant). Variants 6..13 are named by the text each one prints. */
enum {
    EDID_VARIANT_DEFAULT          = 0,  /* also every combination the tests below do not list */
    EDID_VARIANT_PIP              = 2,
    EDID_VARIANT_PBP_LAYOUT0      = 3,
    EDID_VARIANT_PBP_LAYOUT1_2    = 4,
    EDID_VARIANT_16TO10           = 6,  /* "_user_Edid_16to10" */
    EDID_VARIANT_VRR_OFF          = 7,  /* "_user_Edid_VRR_OFF" */
    EDID_VARIANT_VRR_OFF_HDR1000  = 8,  /* "_user_Edid_VRR_OFF_HDR1000" */
    EDID_VARIANT_HDR1000          = 9,  /* "_user_Edid_displayHDR1000" */
    EDID_VARIANT_DSC_OFF_VRR_ON   = 10, /* "_user_Edid_DSC_OFF_VRR_ON" */
    EDID_VARIANT_DSC_OFF_VRR_ON_HDR1000  = 11,  /* "_user_Edid_DSC_OFF_VRR_ON_HDR1000" */
    EDID_VARIANT_DSC_OFF_VRR_OFF         = 12,  /* "_user_Edid_DSC_OFF_VRR_OFF" */
    EDID_VARIANT_DSC_OFF_VRR_OFF_HDR1000 = 13   /* "_user_Edid_DSC_OFF_VRR_OFF_HDR1000" */
};

/* First argument: which inputs get their EDID in the variants that load per group. */
enum {
    EDID_PORTS_5_6   = 0,       /* inputs 5 and 6; input_api_select_ports(1) switches on port mask 0x0F */
    EDID_PORTS_C_D   = 1,       /* inputs 0xC and 0xD; input_api_select_ports(2) switches on port mask 0xF0 */
    EDID_PORTS_ALL   = 2        /* all four; input_api_select_ports(0) switches on every port */
};

/* The four inputs that receive an EDID (first argument of LoadCustomerEDIDData). */
#define EDID_INPUT_5        5
#define EDID_INPUT_6        6
#define EDID_INPUT_C        0xc
#define EDID_INPUT_D        0xd

/* Selectors of input_api_select_ports. */
#define SELECT_ALL_PORTS    0
#define SELECT_PORTS_0F     1
#define SELECT_PORTS_F0     2

#define PIP_PBP_MODE_PIP    1           /* user settings +0x1F: 0 off, 1 PIP, 2 PBP */
#define PIP_PBP_MODE_PBP    2
#define SCREEN_SIZE_3       3           /* Screen Size value that gives EDID_VARIANT_16TO10 */
#define GAMING_FLAG_BIT7    0x80        /* user settings +0xA8 bit 7 (Adaptive-Sync in the record notes); */
                                        /*   clear gives the VRR_OFF variants */
#define ZONE_GRID_MASK      0xc0000     /* bits 18..19 of user settings +0xAC; set gives the HDR1000 variants */
#define ALL_PORTS           0xfe        /* hdr_api_set_port_enable: every input port */

struct user_settings_record {
    unsigned char p000[0x1f];
    unsigned char pip_pbp_mode;                 /* +0x01F 0 off, 1 PIP, 2 PBP */
    unsigned char p020[0x2f - 0x20];
    unsigned char pbp_layout;                   /* +0x02F the PBP layout */
    unsigned char p030[0xa8 - 0x30];
    unsigned int gaming_flags;                  /* +0x0A8 */
    unsigned int settings_page_flags;           /* +0x0AC */
    unsigned char p0b0[0x1a4 - 0xb0];
    unsigned char screen_size;                  /* +0x1A4 Screen Size */
    unsigned char p1a5[0x1f4 - 0x1a5];
    struct {
        int dsc_switch : 1;                     /* bit 31: the DSC switch; clear gives the DSC_OFF variants */
        unsigned int rest : 31;
    } word_0x1f4;                               /* +0x1F4 */
};
extern struct user_settings_record user_settings;
extern unsigned char edid_user_variant;
extern int dbg_printf(const char *fmt, ...);
extern void hdr_api_set_port_enable(unsigned char p, unsigned char v);
extern void LoadCustomerEDIDData(int, int);
extern void input_api_select_ports(int, int);

/*
 * Pick the EDID variant for the current settings and, when it changed or force is set, load the stored EDID
 * records of that variant into the inputs and switch those inputs on.
 *
 *   ports  EDID_PORTS_*: which inputs are loaded in the default variant; in variants 10..13 EDID_PORTS_5_6
 *          loads inputs 5 and 6 alone and any other value all four; variants 2..9 always load all four. App_Initialize, UserSetPIPMode, sys_user_apply_startup_settings and others
 *          pass EDID_PORTS_ALL; sys_user_apply_input_link_settings passes EDID_PORTS_5_6 for selector 0.
 *   force  non-zero: load even when the variant is the same as last time.
 *
 * Phases:
 *   1. Choose the variant, first match wins: PBP (by the PBP layout), PIP, Screen Size 3, then by three
 *      switches: settings +0xA8 bit 7, +0xAC bits 18..19 and the DSC switch (+0x1F4 bit 31).
 *   2. Print the old and the new variant; HDR handling of every input on for Screen Size 3, else off.
 *   3. When the variant changed or force is set: load the variant's EDID records (index into
 *      edid_stored_records) into its inputs, switch the inputs on and print the variant's name.
 *   4. Keep the variant in edid_user_variant.
 */
void UserSwitchEDID(unsigned char ports, unsigned char force)
{
    unsigned char variant = EDID_VARIANT_DEFAULT;

    /* 1. Choose the variant. */
    if (user_settings.pip_pbp_mode == PIP_PBP_MODE_PBP) {
        if (user_settings.pbp_layout == 0)
            variant = EDID_VARIANT_PBP_LAYOUT0;
        else if (user_settings.pbp_layout == 1)
            variant = EDID_VARIANT_PBP_LAYOUT1_2;
        else if (user_settings.pbp_layout == 2)
            variant = EDID_VARIANT_PBP_LAYOUT1_2;
    } else if (user_settings.pip_pbp_mode == PIP_PBP_MODE_PIP)
        variant = EDID_VARIANT_PIP;
    else if (user_settings.screen_size == SCREEN_SIZE_3)
        variant = EDID_VARIANT_16TO10;
    else if (!(user_settings.gaming_flags & GAMING_FLAG_BIT7)) {
        if (user_settings.settings_page_flags & ZONE_GRID_MASK)
            variant = user_settings.word_0x1f4.dsc_switch ? EDID_VARIANT_VRR_OFF_HDR1000 : EDID_VARIANT_DSC_OFF_VRR_OFF_HDR1000;
        else
            variant = user_settings.word_0x1f4.dsc_switch ? EDID_VARIANT_VRR_OFF : EDID_VARIANT_DSC_OFF_VRR_OFF;
    } else {
        if (user_settings.settings_page_flags & ZONE_GRID_MASK)
            variant = user_settings.word_0x1f4.dsc_switch ? EDID_VARIANT_HDR1000 : EDID_VARIANT_DSC_OFF_VRR_ON_HDR1000;
        else if (!user_settings.word_0x1f4.dsc_switch)
            variant = EDID_VARIANT_DSC_OFF_VRR_ON;
        /* bit 7 set, bits 18..19 clear, DSC on: EDID_VARIANT_DEFAULT */
    }
    /* 2. */
    dbg_printf("UserSwitchEDID (%x %x)\r\n", edid_user_variant, variant);
    if (user_settings.screen_size == SCREEN_SIZE_3)
        hdr_api_set_port_enable(ALL_PORTS, 1);
    else
        hdr_api_set_port_enable(ALL_PORTS, 0);
    /* 3. Load the records: LoadCustomerEDIDData(input, record index). */
    if (edid_user_variant != variant || force != 0) {
        switch (variant) {
        case EDID_VARIANT_PIP:
            LoadCustomerEDIDData(EDID_INPUT_5, 4);
            LoadCustomerEDIDData(EDID_INPUT_6, 5);
            LoadCustomerEDIDData(EDID_INPUT_C, 6);
            LoadCustomerEDIDData(EDID_INPUT_D, 7);
            input_api_select_ports(SELECT_ALL_PORTS, 1);
            break;
        case EDID_VARIANT_PBP_LAYOUT0:
            LoadCustomerEDIDData(EDID_INPUT_5, 8);
            LoadCustomerEDIDData(EDID_INPUT_6, 9);
            LoadCustomerEDIDData(EDID_INPUT_C, 0xa);
            LoadCustomerEDIDData(EDID_INPUT_D, 0xb);
            input_api_select_ports(SELECT_ALL_PORTS, 1);
            break;
        case EDID_VARIANT_PBP_LAYOUT1_2:
            LoadCustomerEDIDData(EDID_INPUT_5, 0xc);
            LoadCustomerEDIDData(EDID_INPUT_6, 0xd);
            LoadCustomerEDIDData(EDID_INPUT_C, 0xe);
            LoadCustomerEDIDData(EDID_INPUT_D, 0xf);
            input_api_select_ports(SELECT_ALL_PORTS, 1);
            break;
        case EDID_VARIANT_16TO10:
            LoadCustomerEDIDData(EDID_INPUT_5, 0x18);
            LoadCustomerEDIDData(EDID_INPUT_6, 0x19);
            LoadCustomerEDIDData(EDID_INPUT_C, 0x1a);
            LoadCustomerEDIDData(EDID_INPUT_D, 0x1b);
            input_api_select_ports(SELECT_ALL_PORTS, 1);
            dbg_printf("_user_Edid_16to10\r\n");
            break;
        case EDID_VARIANT_VRR_OFF:
            LoadCustomerEDIDData(EDID_INPUT_C, 2);
            LoadCustomerEDIDData(EDID_INPUT_D, 3);
            LoadCustomerEDIDData(EDID_INPUT_5, 0x14);
            LoadCustomerEDIDData(EDID_INPUT_6, 0x15);
            input_api_select_ports(SELECT_ALL_PORTS, 1);
            dbg_printf("_user_Edid_VRR_OFF\r\n");
            break;
        case EDID_VARIANT_VRR_OFF_HDR1000:
            LoadCustomerEDIDData(EDID_INPUT_C, 0x12);
            LoadCustomerEDIDData(EDID_INPUT_D, 0x13);
            LoadCustomerEDIDData(EDID_INPUT_5, 0x16);
            LoadCustomerEDIDData(EDID_INPUT_6, 0x17);
            input_api_select_ports(SELECT_ALL_PORTS, 1);
            dbg_printf("_user_Edid_VRR_OFF_HDR1000\r\n");
            break;
        case EDID_VARIANT_HDR1000:
            LoadCustomerEDIDData(EDID_INPUT_5, 0x10);
            LoadCustomerEDIDData(EDID_INPUT_6, 0x11);
            LoadCustomerEDIDData(EDID_INPUT_C, 0x12);
            LoadCustomerEDIDData(EDID_INPUT_D, 0x13);
            input_api_select_ports(SELECT_ALL_PORTS, 1);
            dbg_printf("_user_Edid_displayHDR1000\r\n");
            break;
        /* Variants 10..13: inputs 5 and 6 alone, or all four. */
        case EDID_VARIANT_DSC_OFF_VRR_ON:
            if (!ports) {
                LoadCustomerEDIDData(EDID_INPUT_5, 0x2c);
                LoadCustomerEDIDData(EDID_INPUT_6, 0x2d);
                input_api_select_ports(SELECT_PORTS_0F, 1);
            } else {
                LoadCustomerEDIDData(EDID_INPUT_5, 0x2c);
                LoadCustomerEDIDData(EDID_INPUT_6, 0x2d);
                LoadCustomerEDIDData(EDID_INPUT_C, 0x34);
                LoadCustomerEDIDData(EDID_INPUT_D, 0x35);
                input_api_select_ports(SELECT_ALL_PORTS, 1);
            }
            dbg_printf("_user_Edid_DSC_OFF_VRR_ON\r\n");
            break;
        case EDID_VARIANT_DSC_OFF_VRR_ON_HDR1000:
            if (!ports) {
                LoadCustomerEDIDData(EDID_INPUT_5, 0x2e);
                LoadCustomerEDIDData(EDID_INPUT_6, 0x2f);
                input_api_select_ports(SELECT_PORTS_0F, 1);
            } else {
                LoadCustomerEDIDData(EDID_INPUT_5, 0x2e);
                LoadCustomerEDIDData(EDID_INPUT_6, 0x2f);
                LoadCustomerEDIDData(EDID_INPUT_C, 0x36);
                LoadCustomerEDIDData(EDID_INPUT_D, 0x37);
                input_api_select_ports(SELECT_ALL_PORTS, 1);
            }
            dbg_printf("_user_Edid_DSC_OFF_VRR_ON_HDR1000\r\n");
            break;
        case EDID_VARIANT_DSC_OFF_VRR_OFF:
            if (!ports) {
                LoadCustomerEDIDData(EDID_INPUT_5, 0x30);
                LoadCustomerEDIDData(EDID_INPUT_6, 0x31);
                input_api_select_ports(SELECT_PORTS_0F, 1);
            } else {
                LoadCustomerEDIDData(EDID_INPUT_5, 0x30);
                LoadCustomerEDIDData(EDID_INPUT_6, 0x31);
                LoadCustomerEDIDData(EDID_INPUT_C, 0x34);
                LoadCustomerEDIDData(EDID_INPUT_D, 0x35);
                input_api_select_ports(SELECT_ALL_PORTS, 1);
            }
            dbg_printf("_user_Edid_DSC_OFF_VRR_OFF\r\n");
            break;
        case EDID_VARIANT_DSC_OFF_VRR_OFF_HDR1000:
            if (!ports) {
                LoadCustomerEDIDData(EDID_INPUT_5, 0x32);
                LoadCustomerEDIDData(EDID_INPUT_6, 0x33);
                input_api_select_ports(SELECT_PORTS_0F, 1);
            } else {
                LoadCustomerEDIDData(EDID_INPUT_5, 0x32);
                LoadCustomerEDIDData(EDID_INPUT_6, 0x33);
                LoadCustomerEDIDData(EDID_INPUT_C, 0x36);
                LoadCustomerEDIDData(EDID_INPUT_D, 0x37);
                input_api_select_ports(SELECT_ALL_PORTS, 1);
            }
            dbg_printf("_user_Edid_DSC_OFF_VRR_OFF_HDR1000\r\n");
            break;
        default:
            /* EDID_VARIANT_DEFAULT: records 0 / 1 for inputs 5 and 6, 2 / 3 for inputs 0xC and 0xD. */
            if (ports == EDID_PORTS_ALL) {
                LoadCustomerEDIDData(EDID_INPUT_C, 2);
                LoadCustomerEDIDData(EDID_INPUT_D, 3);
                LoadCustomerEDIDData(EDID_INPUT_5, 0);
                LoadCustomerEDIDData(EDID_INPUT_6, 1);
                input_api_select_ports(SELECT_ALL_PORTS, 1);
            } else if (ports == EDID_PORTS_5_6) {
                LoadCustomerEDIDData(EDID_INPUT_5, 0);
                LoadCustomerEDIDData(EDID_INPUT_6, 1);
                input_api_select_ports(SELECT_PORTS_0F, 1);
            } else if (ports == EDID_PORTS_C_D) {
                LoadCustomerEDIDData(EDID_INPUT_C, 2);
                LoadCustomerEDIDData(EDID_INPUT_D, 3);
                input_api_select_ports(SELECT_PORTS_F0, 1);
            }
            break;
        }
    }
    /* 4. */
    edid_user_variant = variant;
}
