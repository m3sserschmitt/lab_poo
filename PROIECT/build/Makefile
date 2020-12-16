CC :=g++
LD :=g++
TARGET :=notebook
OUT :=./notebook
LIBS :=
CC_DEPS :=
OBJECTS :=
RM :=rm -v

all: $(OUT)

-include ./core/exceptions/subdir.mk
-include ./core/subdir.mk
-include ./data_structures/iterable/vector/subdir.mk
-include ./subdir.mk
-include ./util/subdir.mk
-include $(CC_DEPS)

$(OUT): $(OBJECTS)
	@echo Building target: "$@".
	@echo Invoking $(LD) Linker ...
	$(LD) $(OBJECTS) $(LIBS)  -o $(OUT)
	@echo Target $(TARGET) build successfully.
	@echo Done.

clean:
	$(RM) $(OBJECTS) ./notebook

