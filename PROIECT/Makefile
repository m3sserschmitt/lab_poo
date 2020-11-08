CC=g++
TARGET=notebook
CC_DEPS :=
OBJECTS :=
RM=rm -v

all: notebook

-include ./core/src/subdir.mk
-include ./data_structures/src/vector/subdir.mk
-include ./subdir.mk
-include ./util/src/subdir.mk
-include $(CC_DEPS)

notebook: $(OBJECTS)
	@echo Building target: "$@".
	@echo Invoking G++ Linker ...
	$(CC) $(OBJECTS)  -o $(TARGET)
	@echo Target "$@" build successfuly.
	@echo Done.

clean:
	$(RM) $(OBJECTS) $(TARGET)

