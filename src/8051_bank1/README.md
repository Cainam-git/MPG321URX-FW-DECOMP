# 8051 main application (bank 1): the source folders

The source of this program: 377 files, one per function (a few files hold a Keil module of several functions), each named after its function and sorted into a folder for its subject. The first line of every file gives the function's name and its label (its address in the firmware).

| Folder | Subject | Files |
|---|---|---:|
| [`startup/`](startup/) | [Start-up](../../docs/names/8051_bank1.md#startup) | 10 |
| [`irq/`](irq/) | [Interrupts](../../docs/names/8051_bank1.md#irq) | 6 |
| [`timer/`](timer/) | [Timers and delays](../../docs/names/8051_bank1.md#timer) | 7 |
| [`sys/`](sys/) | [System control: channels, modes, configuration](../../docs/names/8051_bank1.md#sys) | 43 |
| [`hdmi/`](hdmi/) | [HDMI](../../docs/names/8051_bank1.md#hdmi) | 8 |
| [`dp/`](dp/) | [DisplayPort](../../docs/names/8051_bank1.md#dp) | 19 |
| [`hdcp/`](hdcp/) | [Copy protection (HDCP)](../../docs/names/8051_bank1.md#hdcp) | 1 |
| [`edid/`](edid/) | [EDID](../../docs/names/8051_bank1.md#edid) | 8 |
| [`ddc/`](ddc/) | [DDC/CI and the service tool](../../docs/names/8051_bank1.md#ddc) | 12 |
| [`ipc/`](ipc/) | [Messages between the processors](../../docs/names/8051_bank1.md#ipc) | 18 |
| [`flash/`](flash/) | [Flash memory](../../docs/names/8051_bank1.md#flash) | 37 |
| [`fwupd/`](fwupd/) | [Firmware update](../../docs/names/8051_bank1.md#fwupd) | 1 |
| [`power/`](power/) | [Power states](../../docs/names/8051_bank1.md#power) | 32 |
| [`gpio/`](gpio/) | [Pins](../../docs/names/8051_bank1.md#gpio) | 6 |
| [`i2c/`](i2c/) | [I2C](../../docs/names/8051_bank1.md#i2c) | 13 |
| [`uart/`](uart/) | [Serial ports](../../docs/names/8051_bank1.md#uart) | 23 |
| [`usb/`](usb/) | [USB](../../docs/names/8051_bank1.md#usb) | 24 |
| [`reg/`](reg/) | [Register access](../../docs/names/8051_bank1.md#reg) | 18 |
| [`dbg/`](dbg/) | [Debug facilities](../../docs/names/8051_bank1.md#dbg) | 2 |
| [`lib/`](lib/) | [Library routines](../../docs/names/8051_bank1.md#lib) | 89 |

The [index page](../../docs/names/8051_bank1.md) lists every function of the program with a one-line description (431 entries, with the jump tables, library members and entry points that have no file of their own); the subject in the table above links to its part of that page. [Function names](../../docs/NAMES.md) describes how the names were given, and [How the firmware works: a guided tour](../../docs/TOUR.md) says what the programs do.
