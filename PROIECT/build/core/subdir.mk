OBJECTS += ./core/date.o \
./core/date_range.o \
./core/entry.o \
./core/event.o \
./core/menu.o \
./core/note.o \
./core/notebook.o \
./core/time.o 

CC_DEPS += ./core/deps/date.d \
./core/deps/date_range.d \
./core/deps/entry.d \
./core/deps/event.d \
./core/deps/menu.d \
./core/deps/note.d \
./core/deps/notebook.d \
./core/deps/time.d 

./core/%.o: ../core/%.cc
	@echo 'Building file: $<'
	$(CC) -c -Wall $< -o $@
	@echo 'Build finished: $<'
	@echo

