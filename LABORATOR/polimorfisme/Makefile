CC=g++
TARGET=./build/bin/polimorfisme
CC_DEPS :=
OBJECTS :=
RM=rm -v

all: ./build/bin/polimorfisme

-include ./subdir.mk
-include $(CC_DEPS)

./build/bin/polimorfisme: $(OBJECTS)
	@echo Building target: "$@".
	@echo Invoking G++ Linker ...
	$(CC) $(OBJECTS)  -o ./build/bin/polimorfisme
	@echo Target polimorfisme build successfully.
	@echo Done.

clean:
	$(RM) $(OBJECTS) ./build/bin/polimorfisme

