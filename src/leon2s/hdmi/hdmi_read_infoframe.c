/* hdmi_read_infoframe  (FUN_a0090380)
 *
 * Copy 28 bytes of a received AVI, SPD, audio or HDR InfoFrame.
 *   port: HDMI 2.0 receiver
 *   type: InfoFrame type
 *   buf: 28-byte buffer
 * Name basis: proven - type 0x82/0x83/0x84/0x87 (CTA-861 codes) -> regs 0x144/0x164/0x184/0x1B0; mailbox
 *   command 0xF3
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0090380 @ 0xa0090380-0xa0090498 (280 bytes, 70 words), flags -mcpu=v8 -Os -g.
 * Source form: a switch on the type with one loop per case (a signed compare tree rooted at 0x83); the counter
 * is an unsigned char that reuses the type's register.
 */

/* Packet types, and the first register of the packet area of each (see the capture routines). */
#define INFOFRAME_TYPE_AVI      0x82
#define INFOFRAME_TYPE_SPD      0x83
#define INFOFRAME_TYPE_AUDIO    0x84
#define INFOFRAME_TYPE_HDR      0x87
#define RX_AVI_DATA_1           0x144
#define RX_SPD_DATA_1           0x164
#define RX_AUDIO_DATA_1         0x184
#define RX_HDR_DATA_1           0x1b0
#define INFOFRAME_READ_BYTES    0x1c

extern unsigned char hdmi_reg_read8(unsigned char, unsigned short);

/* Copies 28 consecutive receiver registers into buf: for type 0x82 (AVI) from register 0x144, 0x83 (SPD) from
   0x164, 0x84 (audio) from 0x184 and 0x87 (HDR) from 0x1B0. Any other type leaves buf alone. The main program
   asks for this with IPC_CMD_READ_INFOFRAME: data byte 0 is the receiver, byte 1 the type, and buf is the
   reply. */
void hdmi_read_infoframe(unsigned char port, unsigned char type, unsigned char *buf)
{
    unsigned char i;

    switch (type) {
    case INFOFRAME_TYPE_AVI:
        for (i = 0; i < INFOFRAME_READ_BYTES; i++)
            buf[i] = hdmi_reg_read8(port, i + RX_AVI_DATA_1);
        break;
    case INFOFRAME_TYPE_SPD:
        for (i = 0; i < INFOFRAME_READ_BYTES; i++)
            buf[i] = hdmi_reg_read8(port, i + RX_SPD_DATA_1);
        break;
    case INFOFRAME_TYPE_AUDIO:
        for (i = 0; i < INFOFRAME_READ_BYTES; i++)
            buf[i] = hdmi_reg_read8(port, i + RX_AUDIO_DATA_1);
        break;
    case INFOFRAME_TYPE_HDR:
        for (i = 0; i < INFOFRAME_READ_BYTES; i++)
            buf[i] = hdmi_reg_read8(port, i + RX_HDR_DATA_1);
        break;
    }
}
