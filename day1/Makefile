-include ../.poniescript.mk

main: main.poni read_file.h .build/
	@poniescript -i read_file.h -o .build/out.c main.poni --no-timing
	@gcc -c .build/out.c -o .build/out.o -I$(PONI_H_PATH) -I.
	@clang -fuse-ld=mold .build/out.o -o main -lponiescript_gc -L$(PONI_GC_PATH)

.build/:
	mkdir -p $@

run: main
	./main

.PHONY: run