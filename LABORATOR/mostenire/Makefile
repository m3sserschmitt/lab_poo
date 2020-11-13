CC=g++
TARGET=mostenire
CC_DEPS :=
OBJECTS :=
RM=rm -v

all: mostenire

-include ./subdir.mk
-include $(CC_DEPS)

mostenire: $(OBJECTS)
	@echo Building target: "$@".
	@echo Invoking G++ Linker ...
	$(CC) $(OBJECTS)  -o $(TARGET)
	@echo Target "$@" build successfully.
	@echo Done.

clean:
	$(RM) $(OBJECTS) $(TARGET)

