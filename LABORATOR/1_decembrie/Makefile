CC=cc
LD=g++
TARGET=./build/bin/1_decembrie
CC_DEPS :=
OBJECTS :=
RM=rm -v

all: ./build/bin/1_decembrie

-include ./subdir.mk
-include $(CC_DEPS)

./build/bin/1_decembrie: $(OBJECTS)
	@echo Building target: "$@".
	@echo Invoking $(LD) Linker ...
	$(LD) $(OBJECTS)  -o ./build/bin/1_decembrie
	@echo Target 1_decembrie build successfully.
	@echo Done.

clean:
	$(RM) $(OBJECTS) ./build/bin/1_decembrie

