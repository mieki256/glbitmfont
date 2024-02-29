all: fontdata_all.h

fontdata_all.h: fontdata_pet2015.h fontdata_profont.h fontdata_shnm8x16r.h fontdata_shnm8x16rx2.h fontdata_ter-u24b.h
	cat fontdata_pet2015.h > $@
	cat fontdata_profont.h >> $@
	cat fontdata_shnm8x16r.h >> $@
	cat fontdata_shnm8x16rx2.h >> $@
	cat fontdata_ter-u24b.h >> $@

fontdata_pet2015.h: font_pet2015.png fontpng2bits.py Makefile
	python fontpng2bits.py -i $< > $@

fontdata_profont.h: font_profont.png fontpng2bits.py Makefile
	python fontpng2bits.py -i $< > $@

fontdata_shnm8x16r.h: font_shnm8x16r.png fontpng2bits.py Makefile
	python fontpng2bits.py -i $< > $@

fontdata_shnm8x16rx2.h: font_shnm8x16rx2.png fontpng2bits.py Makefile
	python fontpng2bits.py -i $< > $@

fontdata_ter-u24b.h: font_ter-u24b.png fontpng2bits.py Makefile
	python fontpng2bits.py -i $< > $@

.PHONY: clean
clean:
	rm -f *.exe *.o *.h
