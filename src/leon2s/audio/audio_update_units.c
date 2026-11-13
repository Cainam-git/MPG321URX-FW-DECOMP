/* audio_update_units  (FUN_a008c6f8)
 *
 * Enable or disable each used audio unit by the state of its input port.
 * Name basis: derived - sources 4..14 in use; port record state 5 and flag decide; calls the unit enable
 *   routines
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on: the source list is a local array initialised from the bytes at
 * DAT_a00b4030 (copied with memcpy, the firmware's lib_memcpy, declared by its link name); a switch on the
 * source id (GCC emits the bit tests 0x50 / 0x5500) with an if chain for the HDMI cases; 'rec' and 'enable'
 * keep their values across the sources.
 */
struct Rec { unsigned char b0;     /* link state */ unsigned char pad[0x11]; unsigned short h12; };
extern struct Rec input_port_records[];
extern void *memcpy(void *, const void *, unsigned int) __asm__("FUN_a00b15d8");
extern unsigned char audio_poll_dp_status(void);
extern unsigned short audio_find_outputs_of_source(unsigned char);
extern unsigned int audio_get_source_unit(unsigned char);
extern void audio_enable_unit_hdmi(unsigned char port, unsigned char en);
extern void audio_enable_unit_dp(unsigned char port, unsigned char en);
extern void audio_update_dp_32k_mode(unsigned char sel, unsigned char port);

#define LINK_STATE_READY 5      /* 'LINK_READY': state of the port record */

/*
 * Turn the audio units of the DP and HDMI sources on or off, following the flags of each source's port
 * record. No parameters, no return value. Called by audio_run_service.
 *
 * First audio_poll_dp_status samples the DP receivers (dp_ok: bit 0 = receiver 0, bit 1 = receiver 1). Then
 * the six sources 4, 6 (DP 0 / 1), 8, 10 (HDMI 2.0 0 / 1) and 12, 14 (HDMI 2.1 0 / 1) are visited in that order
 * and every source that has no audio output is skipped. For the others the port record is chosen: DP source
 * -> record 4 or 5, HDMI source -> record 0..3. The enable value 'enable' is bit 6 of the record's flags
 * halfword (+0x12), but only when the record is in link state LINK_READY, and for a DP source also only when
 * its dp_ok bit is set. Otherwise 'enable' keeps its value from the previous source (it starts as 0).
 * Then the unit of the source (audio_get_source_unit) is enabled or disabled with 'enable': an HDMI source
 * through audio_enable_unit_hdmi; a DP source through audio_enable_unit_dp, followed by
 * audio_update_dp_32k_mode.
 */
void audio_update_units(void)
{
    unsigned char sources[6] = {4, 6, 8, 10, 12, 14};
    unsigned char dp_ok;
    unsigned char rec = 0;
    unsigned char enable = 0;
    unsigned char i;
    unsigned char src;

    dp_ok = audio_poll_dp_status();
    for (i = 0; i < 6; i++) {
        src = sources[i];
        if (audio_find_outputs_of_source(src) == 0)
            continue;
        switch (src) {
        case 4:
        case 6:
            rec = src != 4;
            if (input_port_records[rec + 4].b0 == LINK_STATE_READY && ((dp_ok >> rec) & 1))
                enable = (input_port_records[rec + 4].h12 >> 6) & 1;
            break;
        case 8:
        case 10:
        case 12:
        case 14:
            if (src == 8)
                rec = 0;
            else if (src == 10)
                rec = 1;
            else if (src == 12)
                rec = 2;
            else if (src == 14)
                rec = 3;
            if (input_port_records[rec].b0 == LINK_STATE_READY)
                enable = (input_port_records[rec].h12 >> 6) & 1;
            break;
        }
        if (src > 7)
            audio_enable_unit_hdmi(audio_get_source_unit(src), enable);
        else {
            audio_enable_unit_dp(audio_get_source_unit(src), enable);
            audio_update_dp_32k_mode(src, audio_get_source_unit(src));
        }
    }
}
