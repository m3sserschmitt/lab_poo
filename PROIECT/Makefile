CC=g++
TARGET=notebook
CC_DEPS :=
OBJECTS :=
RM=rm -v

all: notebook

-include ./include/data_structures/vector/subdir.mk
-include ./src/events/subdir.mk
-include ./src/util/subdir.mk
-include ./subdir.mk
-include $(CC_DEPS)

notebook: $(OBJECTS)
	@echo Building target: "$@".
	@echo Invoking G++ Linker ...
	$(CC) $(OBJECTS)  -o $(TARGET)
	@echo Target "$@" build successfuly.
	@echo Done.

clean:
	$(RM) $(OBJECTS) $(TARGET)

