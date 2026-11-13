#!/usr/bin/env python3
"""Per-section facts for the linked build: the segments (name, run address, file offset, length), the relation
between the listing addresses in the function names and the addresses the code runs at, and which segment the
layout tests move."""
SEGS = {
    # start-up code, start values of the data RAM, code window (EDID blocks .. data image)
    "leon2m": [("S", 0xA0028000, 0x0D0000, 0x7B44), ("I", 0xA8024000, 0x0EC000, 0x6F38), ("W", 0x00010000, 0x118000, 0x2B0654 - 0x118000)],
    # first program part, start values of the data RAM, third program part (docs/MAP.md, address numbering)
    "leon2s": [("P1", 0xA0060000, 0x050000, 0x54F60), ("I", 0xA8076000, 0x0A6000, 0x27E0), ("P3", 0x9F1B0000, 0x0B0000, 0x1EEC5)],
}
MOVE = {"leon2m": "W", "leon2s": "P1"}          # the segment whose pieces the layout tests move
CODE = {"leon2m": ("S", "W"), "leon2s": ("P1", "P3")}

def vma(sec, listing):
    """run address of a listing address (the number in a function name)"""
    if sec == "leon2m": return listing if listing < 0xA0030000 else listing - 0xA0060000
    return listing - 0xF10000 if listing >= 0xA00C0000 else listing

def listing(sec, run):
    """listing address of a run address inside the section's code"""
    if sec == "leon2m": return run if run >= 0xA0000000 else run + 0xA0060000
    return run + 0xF10000 if 0x9F1B0000 <= run < 0x9F1D0000 else run

def call_shift(sec, fn_listing):
    """how far the listing address of a function lies above its run address: a call target written as a number
    (func_0x...) was computed from the listing address of the caller"""
    return fn_listing - vma(sec, fn_listing)

def foff(sec, run):
    for n, v, f, ln in SEGS[sec]:
        if v <= run < v + ln: return run - v + f
    return None

def seg_of(sec, run):
    for s in SEGS[sec]:
        if s[1] <= run < s[1] + s[3]: return s
    return None

def v_of_file(sec, off):
    for n, v, f, ln in SEGS[sec]:
        if f <= off < f + ln: return off - f + v
    return None
