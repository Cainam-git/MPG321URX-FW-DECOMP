# Main processor (leon2m): the source folders

The source of this program: 3,766 files, one per function, each named after its function and sorted into a folder for its subject. The first line of every file gives the function's name and its label (its address in the firmware).

| Folder | Subject | Files |
|---|---|---:|
| [`startup/`](startup/) | [Start-up](../../docs/names/leon2m.md#startup) | 32 |
| [`trap/`](trap/) | [Traps and crash handling](../../docs/names/leon2m.md#trap) | 261 |
| [`irq/`](irq/) | [Interrupts](../../docs/names/leon2m.md#irq) | 120 |
| [`timer/`](timer/) | [Timers and delays](../../docs/names/leon2m.md#timer) | 20 |
| [`sys/`](sys/) | [System control: channels, modes, configuration](../../docs/names/leon2m.md#sys) | 538 |
| [`input/`](input/) | [Video inputs: detection, measurement, routing](../../docs/names/leon2m.md#input) | 348 |
| [`hdmi/`](hdmi/) | [HDMI](../../docs/names/leon2m.md#hdmi) | 30 |
| [`dp/`](dp/) | [DisplayPort](../../docs/names/leon2m.md#dp) | 4 |
| [`edid/`](edid/) | [EDID](../../docs/names/leon2m.md#edid) | 25 |
| [`ddc/`](ddc/) | [DDC/CI and the service tool](../../docs/names/leon2m.md#ddc) | 70 |
| [`panel/`](panel/) | [Panel: timing, output, power, PWM](../../docs/names/leon2m.md#panel) | 217 |
| [`oled/`](oled/) | [OLED panel care](../../docs/names/leon2m.md#oled) | 69 |
| [`pq/`](pq/) | [Picture: colour, gamma, windows](../../docs/names/leon2m.md#pq) | 265 |
| [`hdr/`](hdr/) | [HDR](../../docs/names/leon2m.md#hdr) | 1 |
| [`osd/`](osd/) | [On-screen menu](../../docs/names/leon2m.md#osd) | 722 |
| [`font/`](font/) | [Menu fonts](../../docs/names/leon2m.md#font) | 44 |
| [`audio/`](audio/) | [Sound](../../docs/names/leon2m.md#audio) | 24 |
| [`ldc/`](ldc/) | [Dimming processor and its hardware block](../../docs/names/leon2m.md#ldc) | 72 |
| [`ipc/`](ipc/) | [Messages between the processors](../../docs/names/leon2m.md#ipc) | 181 |
| [`nvram/`](nvram/) | [Saved settings](../../docs/names/leon2m.md#nvram) | 44 |
| [`flash/`](flash/) | [Flash memory](../../docs/names/leon2m.md#flash) | 2 |
| [`fwupd/`](fwupd/) | [Firmware update](../../docs/names/leon2m.md#fwupd) | 25 |
| [`power/`](power/) | [Power states](../../docs/names/leon2m.md#power) | 15 |
| [`gpio/`](gpio/) | [Pins](../../docs/names/leon2m.md#gpio) | 78 |
| [`i2c/`](i2c/) | [I2C](../../docs/names/leon2m.md#i2c) | 16 |
| [`uart/`](uart/) | [Serial ports](../../docs/names/leon2m.md#uart) | 284 |
| [`usb/`](usb/) | [USB](../../docs/names/leon2m.md#usb) | 1 |
| [`reg/`](reg/) | [Register access](../../docs/names/leon2m.md#reg) | 54 |
| [`dbg/`](dbg/) | [Debug facilities](../../docs/names/leon2m.md#dbg) | 44 |
| [`lib/`](lib/) | [Library routines](../../docs/names/leon2m.md#lib) | 160 |

The [index page](../../docs/names/leon2m.md) lists every function of the program with a one-line description (3,968 entries, with the jump tables, library members and entry points that have no file of their own); the subject in the table above links to its part of that page. [Function names](../../docs/NAMES.md) describes how the names were given, and [How the firmware works: a guided tour](../../docs/TOUR.md) says what the programs do.
