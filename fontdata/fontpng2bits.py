#!python
# -*- mode: python; Encoding: utf-8; coding: utf-8 -*-
# Last updated: <2024/02/29 01:12:23 +0900>
"""
font png image to c header file

Usage:
  python fontpng2bits.py -i INPUT.png [--label label_name] > OUTPUT.h

Windows10 x64 22H2 + Python 3.10.10 64bit + Pillow 10.2.0
"""

import argparse
import os
import sys
from PIL import Image


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("-i", "--infile", required=True, help="PNG image file")
    parser.add_argument("--label", help="symbol name")
    args = parser.parse_args()
    infile = args.infile

    if not os.path.isfile(infile):
        print("Error: Not found %s" % infile)
        sys.exit()

    # get symbol (label) name
    if not args.label:
        label = infile.replace(".", "_")
        label = label.replace(" ", "_")
        label = label.replace("-", "_")
    else:
        label = args.label

    im = Image.open(infile).convert("L")
    im.point(lambda x: 0 if x < 128 else x)

    # get image size
    imgw, imgh = im.size
    w = int(imgw / 16)
    h = int(imgh / 6)

    # get data length
    alen = int(w / 8) + (1 if (w % 8) != 0 else 0)
    clen = alen * h
    cnum = 16 * 6

    print("/* %s : source image size = %d x %d */\n" % (infile, imgw, imgh))

    print("#define %s_WIDTH %d" % (label.upper(), w))
    print("#define %s_HEIGHT %d" % (label.upper(), h))
    print("#define %s_CHR_LEN %d\n" % (label.upper(), clen))

    print("static unsigned char %s[%d][%d] = {" % (label, cnum, clen))

    for c in range(16 * 6):
        bx = int(c % 16) * w
        by = int(c / 16) * h

        buf = []
        for i in range(clen):
            buf.append(0)

        yi = 0
        for y in range(h - 1, -1, -1):
            for x in range(w):
                v = im.getpixel((bx + x, by + y))
                if v > 128:
                    buf[yi * alen + int(x / 8)] |= 1 << (7 - (x % 8))
            yi += 1

        s = ""
        for v in buf:
            s += "0x%s, " % format(v, "02x")
        print("  { %s }, // code = 0x%02x" % (s, (c + 0x20)))

    print("};\n\n")


if __name__ == "__main__":
    main()
