-include ../.poniescript.mk

main: main.poni .build/
	@poniescript -c tcc -o .build/out.o main.poni -C-I$(PONI_H_PATH) --no-timing
	@clang -fuse-ld=mold .build/out.o -o main -lponiescript_gc -L$(PONI_GC_PATH)

.build/:
	mkdir -p $@
