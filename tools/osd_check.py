#!/usr/bin/env python3
"""Build the menu fonts and texts from src/osd/ and compare them with the firmware.

Usage: python3 tools/osd_check.py [--src DIR] [--out FILE] [--max N]

  --src DIR    source tree (default src/osd)
  --out FILE   also write the built menu area (flash 0x2101F0-0x29FF4F) to FILE
  --max N      print at most N differing bytes (default 50)

The build is tools/osd_build.py; it reads only the source tree. The result is compared with
firmware/MSI_MPG321URX_V021_7F69.bin, and one line is printed for each of two ranges:

  flash 0x2101F0-0x27FFFF   the fonts area and the text area up to flash 0x280000
  flash 0x2101F0-0x29FF4F   the whole menu area: all fonts and all texts

Each differing byte is printed with its flash offset, the expected and the built value and the item it is
in. Exit status 0 only when both ranges are byte-identical; 1 when bytes differ; 2 when the build fails.
"""
import bisect, os, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import osd_build  # noqa: E402

REPO = osd_build.REPO
FW = REPO + '/firmware/MSI_MPG321URX_V021_7F69.bin'
LO, HI = osd_build.AREA_LO, osd_build.AREA_HI


def main():
    args = sys.argv[1:]
    src = os.path.abspath(args[args.index('--src') + 1]) if '--src' in args else REPO + '/src/osd'
    outbin = args[args.index('--out') + 1] if '--out' in args else None
    nmax = int(args[args.index('--max') + 1]) if '--max' in args else 50
    try:
        area, amap, _ = osd_build.build(src)
    except osd_build.SourceError as e:
        print('build failed: %s' % e)
        sys.exit(2)
    if outbin:
        open(outbin, 'wb').write(area)
    fw = open(FW, 'rb').read()[LO:HI]
    amap.sort()
    starts = [a for a, n, w in amap]

    def item(off):
        a = off - osd_build.WINDOW
        i = bisect.bisect_right(starts, a) - 1
        if i >= 0 and a < starts[i] + amap[i][1]:
            return '%s +0x%x' % (amap[i][2], a - starts[i])
        return 'zero fill'

    diff = [i for i in range(len(fw)) if fw[i] != area[i]]
    for i in diff[:nmax]:
        print('flash 0x%06x: firmware %02x, built %02x  %s' % (LO + i, fw[i], area[i], item(LO + i)))
    if len(diff) > nmax:
        print('... %d more' % (len(diff) - nmax))
    status = 0
    for hi, what in ((0x280000, 'fonts and texts up to flash 0x280000'), (HI, 'all fonts and texts')):
        n = sum(1 for i in diff if LO + i < hi)
        status |= n != 0
        print('%s: %d of %d bytes differ (flash 0x%06X-0x%06X, %s)'
              % ('IDENTICAL' if n == 0 else 'DIFFERENT', n, hi - LO, LO, hi - 1, what))
    sys.exit(status)


if __name__ == '__main__':
    main()
