#!/usr/bin/env python3
"""Build the Tensilica program from its assembly source and compare it with the firmware.

Usage: python3 tools/xtensa_check.py [--src DIR] [--out FILE.bin] [--max N]

  --src DIR    source directory holding tensilica.S (default src/tensilica)
  --out FILE   also write the rebuilt program (0xd8dc bytes) to FILE
  --max N      print at most N differing bytes (default 50)

Steps, with the Espressif xtensa-esp32-elf binutils in toolchains/xtensa-esp32-elf (docs/TOOLCHAINS.md):
  as --no-transform -I DIR DIR/tensilica.S   (one assembly unit; the .include lines give the address order)
  ld -Ttext=0x40000000 --no-relax            (the program runs at 0x40000000)
  objcopy -O binary -j .text
and the result is compared with firmware/MSI_MPG321URX_V021_7F69.bin, file offset 0x30000-0x3d8db.
Each differing byte is printed with its address, the expected and the built value and the symbol it is in.
Exit status 0 only when the build is byte-identical; 1 when bytes differ; 2 when the build fails.
"""
import bisect, os, subprocess, sys, tempfile

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TC = REPO + '/toolchains/xtensa-esp32-elf/bin/xtensa-esp32-elf-'
FW = REPO + '/firmware/MSI_MPG321URX_V021_7F69.bin'
OFF, SIZE, BASE = 0x30000, 0xD8DC, 0x40000000


def run(cmd):
    r = subprocess.run(cmd, capture_output=True, text=True)
    if r.returncode:
        sys.stderr.write(r.stdout + r.stderr)
        print('build failed: ' + ' '.join(cmd))
        sys.exit(2)
    return r.stdout


def main():
    args = sys.argv[1:]
    src = os.path.abspath(args[args.index('--src') + 1]) if '--src' in args else REPO + '/src/tensilica'
    outbin = args[args.index('--out') + 1] if '--out' in args else None
    nmax = int(args[args.index('--max') + 1]) if '--max' in args else 50
    if not os.path.exists(TC + 'as'):
        print('missing toolchain: %sas (see docs/TOOLCHAINS.md)' % TC)
        return 2
    with tempfile.TemporaryDirectory() as d:
        o, e, b = d + '/tensilica.o', d + '/tensilica.elf', d + '/tensilica.bin'
        run([TC + 'as', '--no-transform', '-I', src, '-o', o, src + '/tensilica.S'])
        run([TC + 'ld', '-Ttext=0x%08x' % BASE, '--no-relax', '-e', '0x%08x' % BASE, '-o', e, o])
        run([TC + 'objcopy', '-O', 'binary', '-j', '.text', e, b])
        new = open(b, 'rb').read()
        syms = []
        for ln in run([TC + 'nm', '-n', e]).splitlines():
            p = ln.split()
            if len(p) == 3 and p[1] in 'tTdD':
                syms.append((int(p[0], 16), p[2]))
    if outbin:
        open(outbin, 'wb').write(new)
    ref = open(FW, 'rb').read()[OFF:OFF + SIZE]
    addrs = [s[0] for s in syms]

    def where(a):
        i = bisect.bisect_right(addrs, a) - 1
        return '%s+0x%x' % (syms[i][1], a - syms[i][0]) if i >= 0 else '?'

    diff = [i for i in range(min(len(new), SIZE)) if new[i] != ref[i]]
    for i in diff[:nmax]:
        print('0x%08x (file 0x%05x): firmware %02x, built %02x  %s'
              % (BASE + i, OFF + i, ref[i], new[i], where(BASE + i)))
    if len(diff) > nmax:
        print('... %d more' % (len(diff) - nmax))
    if len(new) != SIZE:
        print('length: firmware 0x%x, built 0x%x' % (SIZE, len(new)))
    ndiff = len(diff) + abs(len(new) - SIZE)
    print('%s: %d of %d bytes differ' % ('IDENTICAL' if ndiff == 0 else 'DIFFERENT', ndiff, SIZE))
    return 0 if ndiff == 0 else 1


if __name__ == '__main__':
    sys.exit(main())
