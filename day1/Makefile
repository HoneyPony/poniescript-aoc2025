-include ../.poniescript.mk

puzzle1: puzzle1.poni read_file.h .build/
	@poniescript -i read_file.h -o .build/puzzle2.c main.poni --no-timing
	@gcc -c .build/puzzle2.c -o .build/puzzle2.o -I$(PONI_H_PATH) -I.
	@clang -fuse-ld=mold .build/puzzle2.o -o main -lponiescript_gc -L$(PONI_GC_PATH)

puzzle2: puzzle2.poni read_file.h .build/
	@poniescript -i read_file.h -o .build/puzzle2.c main.poni --no-timing
	@gcc -c .build/puzzle2.c -o .build/puzzle2.o -I$(PONI_H_PATH) -I.
	@clang -fuse-ld=mold .build/puzzle2.o -o main -lponiescript_gc -L$(PONI_GC_PATH)

.build/:
	mkdir -p $@

run1: puzzle1
	./puzzle1

run2: puzzle2
	./puzzle2

.PHONY: run1 run2