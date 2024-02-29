<!-- -*- encoding: utf-8 -*- -->

BDfフォントの入手先
===================

2024/01/13

shinonome font family
http://openlab.ring.gr.jp/efont/shinonome/

shinonome-0.9.11p1.tar.bz2 を入手して解凍。bdfフォルダの中に .bdfフォントが入っている。ライセンスは Public Domain。

courR18.bdf
https://opensource.apple.com/source/X11fonts/X11fonts-5/font-adobe-75dpi/font-adobe-75dpi-X11R7.0-1.0.0/courR18.bdf.auto.html

mieki256's diary - HGIMG3とビットマップフォント画像の作り方を勉強中
http://cubekeroron/~mieki256/diary/202310301.html#202310301

Terminus Font Home Page
https://terminus-font.sourceforge.net/

terminus-font-4.49.1.tar.gz を入手して解凍。.bdfフォントが入っている。ライセンスは SIL Open Font License, Version 1.1.

ProFont for Windows, for Macintosh, for Linux
https://tobiasjung.name/profont/index.php

profont-x11.zip を入手して解凍。*.pcf を任意のフォルダに置いて、GIMP 2.8.22 Portable のフォントフォルダとして追加した。ライセンスは
[MIT License](https://opensource.org/license/mit/)

必要な文字種類
--------------

以下の文字種類を列挙した画像を用意する。16 x 6個で文字を並べる。

```
 !"#$%&'()*+,-./
0123456789:;<=>?
@ABCDEFGHIJKLMNO
PQRSTUVWXYZ[\]^_
`abcdefghijklmno
pqrstuvwxyz{|}~ 
```

bitmap化について
----------------

bdf2bmp というツールを使えば、bdfフォントを画像化できる。

bdf2bmp
http://hp.vector.co.jp/authors/VA013241/font/bdf2bmp.html

使い方は以下。

```
bdf2bmp input.bdf output.bmp
```

オプションをつければ、境界線を入れない状態で出力できたり、横に並ぶ文字の個数を指定できたりする。

```
bdf2bmp input.bdf output.bmp -s0 -c16
```

任意のグリッドサイズを指定して、グリッド単位で選択や移動ができる画像編集ソフトを使えば、並び替えも難しくない。
自分の場合はドットエディタ EDG2 で作業してしまうことが多い。

