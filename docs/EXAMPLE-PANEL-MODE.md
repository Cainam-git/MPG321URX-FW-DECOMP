# A worked example: the panel mode selection

This page reads one function of the main processor from top to bottom:
[`SYSAPI_GetPanelParamStruct`](../src/leon2m/panel/SYSAPI_GetPanelParamStruct.c), which decides in which of its
three modes the panel runs. It shows how to read a source file of this repository (the names, the constants, the
comments) and how a question about the monitor's behaviour is answered from the code. The two files in
`firmware/custom/` change this function; the page ends with what they do, in the words of the source.

## What the function is for

The panel can be driven in three modes: 240 Hz, 120 Hz and 60 Hz. Each mode is one row of a table of timings in the
firmware (`panel_mode_rows`, see [panel modes](MAP.md#panel-modes)). The function picks the row that fits the input
signal, as the top of the file says:

```c
/* SYSAPI_GetPanelParamStruct  (FUN_a00dac38)
 *
 * Choose the panel timing row that fits the incoming refresh rate and make it active.
 * Name basis: proven - prints 'SYSAPI_GetPanelParamStruct %x,%x' (original name)
```

- The first line gives the name and, in brackets, the label: the function's address in the numbering of the
  listing ([address numbering](MAP.md#address-numbering)).
- The next line says what the function does.
- *Name basis: proven* means the name is the firmware's own: the function prints it in a debug message.

## The three modes and the four limits

Near the top the file gives names to the numbers the function works with:

```c
enum {
    PANEL_MODE_240HZ = 0,
    PANEL_MODE_120HZ = 1,
    PANEL_MODE_60HZ  = 2
};

/* Upper limits of the 60 Hz and the 120 Hz mode, in tenths of a hertz. */
#define REFRESH_LIMIT_60HZ   600            /* measured refresh rate; the margin is added to it */
#define REFRESH_LIMIT_120HZ  1200
#define COMPUTED_LIMIT_60HZ  699            /* refresh rate computed from the line rate */
#define COMPUTED_LIMIT_120HZ 1299
```

The firmware measures refresh rates in tenths of a hertz, so 600 means 60.0 Hz. There are two pairs of limits
because the function has two ways of judging a signal (step 2).

## Step 1: read the measured signal

```c
    unsigned char margin = 20;                  /* 2.0 Hz above each limit still counts as that mode */

    /* For signal compliance tests the factory menu narrows the margin to 0.5 Hz. */
    if ((unsigned short)nvram_get_device_setting(DEVICE_SETTING_PHY_CTS_AUTO) == 1) margin = 5;

    refresh_rate = input_api_get_timing_field(0, TIMING_REFRESH_RATE);
    line_rate = input_api_get_timing_field(0, TIMING_LINE_RATE);
    active_lines = input_api_get_timing_field(0, TIMING_ACTIVE_LINES);
```

- `margin` is how far above a limit a signal may be and still count as that mode: 2.0 Hz. A switch in the factory
  menu ("PHY CTS AUTO") narrows it to 0.5 Hz.
- The next lines ask another function, `input_api_get_timing_field`, for three measured values of the signal on the
  main picture: its refresh rate, its line rate and its number of picture lines.

## Step 2: choose the mode

```c
            if (sys_api_get_channel_port_flag(0) != 0) {
                /* This port is judged by its line rate: divided by the lines of a panel frame it gives a
                   refresh rate for the panel. */
                if (panel_line_rate / PANEL_TOTAL_LINES <= COMPUTED_LIMIT_60HZ) mode = PANEL_MODE_60HZ;
                else if (panel_line_rate / PANEL_TOTAL_LINES <= COMPUTED_LIMIT_120HZ) mode = PANEL_MODE_120HZ;
                else mode = PANEL_MODE_240HZ;
            } else {
                /* Every other port is judged by its measured refresh rate. */
                if ((unsigned short)refresh_rate < margin + REFRESH_LIMIT_60HZ) mode = PANEL_MODE_60HZ;
                else if ((unsigned short)refresh_rate < margin + REFRESH_LIMIT_120HZ) mode = PANEL_MODE_120HZ;
                else mode = PANEL_MODE_240HZ;
            }
```

The function asks `sys_api_get_channel_port_flag` for a flag of the port. The code does not show which ports
carry that flag (the name only describes what is read). For a port without it the decision reads, with the
numbers filled in:

| Measured refresh rate | Mode |
|---|---|
| below 62.0 Hz (600 + 20 tenths) | 60 Hz |
| below 122.0 Hz (1200 + 20 tenths) | 120 Hz |
| anything faster | 240 Hz |

For a port with the port flag the function works from the line rate: it scales the line rate to the panel's 2160
picture lines, divides by 2348 (the shortest frame of every panel mode, in lines) and compares the result with
69.9 Hz and 129.9 Hz.

The comment block above the function adds what a reader must know before changing it: this choice is only made in
picture mode 0 (one picture) and picture mode 2; every other picture mode (picture in picture, picture by picture) always uses the 120 Hz mode.

## Step 3: switch, but only when the mode changes

```c
            /* Switch only when the mode changes. */
            if ((unsigned char)oled_frc_get_row() != mode) {
                oled_frc_set_row(mode);
                row = panel_mode_rows[(unsigned char)oled_frc_get_row()];
                panel_api_set_active_row(&row, 1);
            }
```

The function stores the new mode, copies that mode's row out of the table and hands it to
`panel_api_set_active_row`, which makes it the active timing. The last lines of the function print what the panel
controller reports next to what was chosen.

## A question answered from the code

*In which mode does a 60.0988 Hz signal land, and why does the monitor then show a full-screen colour cycle
instead of a picture?*

1. 60.0988 Hz is about 601 tenths of a hertz. That is below 620, so the mode is the 60 Hz mode.
2. The row of the 60 Hz mode ([panel modes](MAP.md#panel-modes)) has an output clock of 576 MHz, 4088 clock ticks
   per line and at least 2348 lines per frame. At 60.0 Hz a frame has 576,000,000 / 4088 / 60.0 = 2348.3 lines. That
   fits.
3. With the panel's timing locked to the input (frame lock), every panel frame is exactly as long as an input frame. At
   60.0988 Hz that is 576,000,000 / 4088 / 60.0988 = 2344.5 lines: fewer than the 2348 the mode needs.

The same happens one mode up: 120.198 Hz is below 122.0 Hz and lands in the 120 Hz mode (2300 MHz, 8160 ticks per
line), where a frame gets 2345.0 lines.

In the next faster mode both signals fit: 60.0988 Hz in the 120 Hz mode gives 4690 lines (allowed: 2348 to 5884),
and 120.198 Hz in the 240 Hz mode (2291 MHz, 4064 ticks per line) gives 4690 lines (allowed: 2348 to 11764).

## What the two custom files change

The two files in [`firmware/custom/`](../firmware/README.md#custom-firmware) change nothing but the four limits:

| Limit | FW.021 | 7E52 | 7E9D |
|---|---:|---:|---:|
| `REFRESH_LIMIT_60HZ` | 600 | 0 | 0 |
| `COMPUTED_LIMIT_60HZ` | 699 | 0 | 0 |
| `REFRESH_LIMIT_120HZ` | 1200 | 1200 | 600 |
| `COMPUTED_LIMIT_120HZ` | 1299 | 1299 | 699 |

Read with the code of step 2, for a port judged by its refresh rate:

| Measured refresh rate | FW.021 | 7E52 | 7E9D |
|---|---|---|---|
| below 2.0 Hz (no signal) | 60 Hz mode | 60 Hz mode | 60 Hz mode |
| 2.0 Hz to below 62.0 Hz | 60 Hz mode | 120 Hz mode | 120 Hz mode |
| 62.0 Hz to below 122.0 Hz | 120 Hz mode | 120 Hz mode | 240 Hz mode |
| 122.0 Hz and faster | 240 Hz mode | 240 Hz mode | 240 Hz mode |

With a limit of 0 only the margin is left, so the 60 Hz mode is taken below 2.0 Hz: when nothing is connected.
That is why both files behave like FW.021 without a signal.

## Source and machine code

The two custom files change these numbers in place in the machine code of FW.021 (the changed instructions are
listed in the [firmware overview](../firmware/README.md#custom-firmware)). Nothing else in the file moved, as the
rules of [Modifying the firmware](MODIFYING.md) ask.

Changing the four `#define` lines in the source and compiling the function gives the same decisions, but not the
same instructions: for a comparison with 0 the compiler chooses other instructions and other registers than for a
comparison with 600 or 699, so the compiled function differs from the function in 7E52 and 7E9D in many places. The
two files in `firmware/custom/` are the ones that were tested on a monitor.

## Reading other functions the same way

- Find a function by name in the [index pages](NAMES.md#where-the-names-are); the name links to its file.
- Read the first lines of the file, then the comment block above the function, then the code.
- A name in the code that is not defined in the file is another function or a stored value: look it up in the same
  index, or in the [data pages](DATA.md).
- Skip the block *Matching notes* at the top of a file when reading for understanding. It is for people who
  rebuild the firmware ([glossary](GLOSSARY.md)).
