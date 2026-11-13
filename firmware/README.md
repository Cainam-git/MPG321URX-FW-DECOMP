# Firmware

The firmware files of the MSI MPG 321URX: MSI's official versions, and two modified versions of FW.021 in
`custom/`.

## Official firmware

MSI names each file `MSI_MPG321URX_V0xx_XXXX.bin`, where `XXXX` is the 16-bit sum of all bytes in the file, in
hexadecimal.

| File | Version | Size (bytes) | Role |
|---|---|---:|---|
| `MSI_MPG321URX_V021_7F69.bin` | FW.021 | 2,820,096 | **Decompilation target** |
| `MSI_MPG321URX_V020_95AB.bin` | FW.020 | 2,819,072 | Comparison |
| `MSI_MPG321URX_V016_C6FB.bin` | FW.016 | 2,815,488 | Comparison |
| `MSI_MPG321URX_V012_91A5.bin` | FW.012 | 2,802,688 | Comparison, used by `tools/fwdiff.py` |

All function names, addresses and file offsets in this repository refer to FW.021. The older versions share most of
their code at shifted addresses. `tools/fwdiff.py` finds a FW.021 function in FW.012 by comparing its instructions
with the addresses masked out.

## Custom firmware

> **Use at your own risk.** These files are not made or supported by MSI. They come with no warranty, and flashing
> any firmware can leave the monitor unusable. See [Flashing and recovery](../docs/MODIFYING.md#flashing-and-recovery)
> before you flash.

The two files in `custom/` change only a few numbers in one function of FW.021, the panel mode selection
(`SYSAPI_GetPanelParamStruct` (`FUN_a00dac38`), see [panel modes](../docs/MAP.md#panel-modes)). Nothing else in
the file is different.

### Why

The panel runs in one of three modes: 240 Hz, 120 Hz or 60 Hz. When the panel's timing is locked to the input
(frame lock), every frame on the panel lasts exactly as long as an input frame. An input that is slightly faster than
the mode it is placed in then gives each frame too few lines, and the monitor shows a full-screen colour cycle
instead of a picture.

This affects retro consoles and upscalers that output the original refresh rates. NES and SNES run at 60.0988 Hz,
some arcade boards at 60.59 Hz. Black frame insertion (a black frame after every picture frame) doubles the
NES and SNES rate to 120.198 Hz. On FW.021 these rates land in the 60 Hz or 120 Hz mode, where they are just too
fast to fit.

### What they change

| File | Change | Effect |
|---|---|---|
| `MSI_MPG321URX_V021_7E52.bin` | Every signal below about 122 Hz uses the 120 Hz mode, as in FW.016 and earlier. | Fixes 60.0988 Hz and 60.59 Hz. |
| `MSI_MPG321URX_V021_7E9D.bin` | Signals below about 62 Hz use the 120 Hz mode, and signals from about 62 Hz up use the 240 Hz mode. | Fixes 60.0988 Hz, 60.59 Hz and 120.198 Hz. |

7E9D includes the change of 7E52 and is the file published as a release. 7E52 changes less: it leaves signals
between about 62 Hz and 122 Hz in the 120 Hz mode, as FW.021 does.

| Measured refresh rate | FW.021 | 7E52 | 7E9D |
|---|---|---|---|
| below 2.0 Hz (no signal) | 60 Hz mode | 60 Hz mode | 60 Hz mode |
| 2.0 Hz to below 62.0 Hz | 60 Hz mode | 120 Hz mode | 120 Hz mode |
| 62.0 Hz to below 122.0 Hz | 120 Hz mode | 120 Hz mode | 240 Hz mode |
| 122.0 Hz and faster | 240 Hz mode | 240 Hz mode | 240 Hz mode |

In both versions the 60 Hz mode is only used when no signal is connected, exactly as on FW.021 without a signal.
On a port that the firmware judges by its line rate, the limits of FW.021 are about 70 Hz and 130 Hz instead (see
the [worked example](../docs/EXAMPLE-PANEL-MODE.md)).

To go back to MSI's firmware, install the official `MSI_MPG321URX_V021_7F69.bin`. The older official files are
here for comparison only; MSI's tool refuses versions it considers too old, such as FW.016.

Both versions were tested on an MPG 321URX. 7E52 was tested with 60.0988 Hz, 60.59 Hz and a 240 Hz desktop; 7E9D
with 60.0988 Hz, 60.59 Hz, 120.198 Hz and a 240 Hz desktop.

The changed instructions:

| File offset | Original | Changed | In |
|---|---|---|---|
| 0x182DC4 | `cmp %g1, 699` | `cmp %g1, 0` | 7E52, 7E9D |
| 0x182FE8 | `add %o5, 600, %l5` | `add %o5, 0, %l5` | 7E52, 7E9D |
| 0x182FF8 | `add %o5, 1200, %l7` | `add %o5, 600, %l7` | 7E9D |
| 0x183010 | `cmp %g1, 1299` | `cmp %g1, 699` | 7E9D |

The [worked example](../docs/EXAMPLE-PANEL-MODE.md) reads the function line by line and shows these four numbers
in the source.

## Checksums (SHA-256)

| File | SHA-256 |
|---|---|
| `MSI_MPG321URX_V021_7F69.bin` | `4934abd71dff21492dda3b2dd630f3539ba1d6639de88f2f3684fd03d59f019e` |
| `MSI_MPG321URX_V020_95AB.bin` | `532d59d03773dba3a6125cd62be974ce753974dcfa891de327eb4690ce831845` |
| `MSI_MPG321URX_V016_C6FB.bin` | `ccb92cd4fa7278104c05d7d12d9a3b102373b2957f27811e98f913df7202d595` |
| `MSI_MPG321URX_V012_91A5.bin` | `bea014e37c76f5e49b3b1ea623dd7492f028be4d9d553efbe7485665e8311821` |
| `custom/MSI_MPG321URX_V021_7E52.bin` | `d19d154b08b231ee8fafdd2a65c6f9267fd053d69a532a42e2f4af624a8e09d0` |
| `custom/MSI_MPG321URX_V021_7E9D.bin` | `bd794a6e0bec010910b5004439b71f71a672d46abe6ecee69112b21381f707d9` |
