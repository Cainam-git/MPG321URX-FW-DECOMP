/* audio_set_output_source  (FUN_a008b32c)
 *
 * Route an audio source to one audio output.
 *   out: audio output 0..8
 *   src: audio source id
 *   en: read for output 0 only: 0 = do not route, just set bits 2..3 of 0xCF011018
 * Name basis: derived - stores the table read by audio_get_output_source and writes the output's select nibble
 *   (0xCF011200..)
 *
 * Matching notes
 * --------------
 * leon2s, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on: K&R parameter definition; the locals v (unsigned char copy of src),
 * x and f; in case 0 audio_config is read into an unsigned int before 'x = v == 1; if (x & ~f)'.
 */
extern unsigned char audio_output_sources[];
extern unsigned char audio_config;
extern unsigned char audio_mute_value;
extern void audio_set_hdmi_tx_source(unsigned char, unsigned char);

#define R(a) (*(volatile unsigned int *)(a))

/*
 * Connect an audio source to one audio output: remember it and write the source id into the output's select
 * nibble.
 *
 *   out  audio output 0..8 (any other value only stores the source)
 *   src  audio source id; only its low 4 bits go into the register
 *   en   used by output 0 only: 0 = do not route, just set bits 2..3 of 0xCF011018
 *
 * The source is always stored in audio_output_sources[out] first (audio_get_output_source returns it).
 * Select registers per output: 0 = low nibble of 0xCF011200, 1 = low nibble of 0xCF011204,
 * 2 / 3 = low / high nibble of 0xCF011208, 4 / 5 = low / high nibble of 0xCF011210, 6 = low nibble of
 * 0xCF01120C, 7 = low nibble of 0xCF011218, 8 = low nibble of 0xCF011214.
 * Further writes: output 0 clears bits 2..3 of 0xCF011018 unless audio_mute_value (the mute flag the main
 * program sends) is set, and clears bit 5 of 0xCF011008 only when src is 1 and bit 0 of audio_config[0] is
 * clear (otherwise sets it); outputs 1, 2, 3 write 0xC0 into 0xCF01122C / 0xCF011230 / 0xCF011234;
 * outputs 2 and 3 also pass the source to audio_set_hdmi_tx_source for HDMI TX port 0 / 1; outputs 6 and 7
 * set bit 1 / bit 0 of 0xCF0111C0.
 * Caller: audio_route_source.
 */
void audio_set_output_source(out, src, en)
    unsigned char out, src, en;
{
    unsigned char v;
    unsigned int x;
    unsigned int f;

    audio_output_sources[out] = src;
    switch (out) {
    case 0:
        if (en) {
            v = src;
            R(0xcf011200) = (R(0xcf011200) & 0xf0) | (v & 0xf);
            if (audio_mute_value == 0)
                R(0xcf011018) &= ~0xc;
            f = audio_config;
            x = v == 1;
            if (x & ~f)
                R(0xcf011008) &= ~0x20;
            else
                R(0xcf011008) |= 0x20;
        } else
            R(0xcf011018) |= 0xc;
        break;
    case 1:
        R(0xcf01122c) = 0xc0;
        R(0xcf011204) = (R(0xcf011204) & 0xf0) | (src & 0xf);
        break;
    case 2:
        R(0xcf011230) = 0xc0;
        v = src;
        R(0xcf011208) = (R(0xcf011208) & 0xf0) | (v & 0xf);
        audio_set_hdmi_tx_source(0, v);
        break;
    case 3:
        R(0xcf011234) = 0xc0;
        v = src;
        R(0xcf011208) = (R(0xcf011208) & 0xf) | ((v & 0xf) << 4);
        audio_set_hdmi_tx_source(1, v);
        break;
    case 4:
        R(0xcf011210) = (R(0xcf011210) & 0xf0) | (src & 0xf);
        break;
    case 5:
        R(0xcf011210) = (R(0xcf011210) & 0xf) | ((src & 0xf) << 4);
        break;
    case 6:
        R(0xcf01120c) = (R(0xcf01120c) & 0xf0) | (src & 0xf);
        R(0xcf0111c0) |= 2;
        break;
    case 7:
        R(0xcf011218) = (R(0xcf011218) & 0xf0) | (src & 0xf);
        R(0xcf0111c0) |= 1;
        break;
    case 8:
        R(0xcf011214) = (R(0xcf011214) & 0xf0) | (src & 0xf);
        break;
    }
}
