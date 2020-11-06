CC=g++
TARGET=halloween
CC_DEPS :=
OBJECTS :=
RM=rm -v

all: halloween

-include ./subdir.mk
-include $(CC_DEPS)

halloween: $(OBJECTS)
	@echo Building target: "$@".
	@echo Invoking G++ Linker ...
	$(CC) $(OBJECTS)  -o $(TARGET)
	@echo Target "$@" build successfuly.
	@echo Done.

clean:
	$(RM) $(OBJECTS) $(TARGET)

