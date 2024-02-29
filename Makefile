GCC_VERSION=$(shell gcc -dumpversion)

ifeq ($(GCC_VERSION),6.3.0)
# ----------------------------------------
# MinGW gcc 6.3.0 (SourceForge)
glbitmfont_sample.exe: glbitmfont_sample.c glbitmfont.h Makefile
	gcc $< -o $@ -static -lopengl32 -lwinmm -lgdi32 -lglfw3dll -mwindows
else
# ----------------------------------------
# MinGW gcc 9.2.0 (OSDN), MSYS2
glbitmfont_sample.exe: glbitmfont_sample.c glbitmfont.h Makefile
	gcc $< -o $@ -static -lopengl32 -lwinmm -lgdi32 -lglfw3 -mwindows
endif

.PHONY: clean
clean:
	rm -f *.exe *.o
