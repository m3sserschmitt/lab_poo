OBJECTS += ./core/date.o \
./core/event.o \
./core/note.o \
./core/notebook.o \
./core/time.o 

CC_DEPS += ./core/deps/date.d \
./core/deps/event.d \
./core/deps/note.d \
./core/deps/notebook.d \
./core/deps/time.d 

./core/%.o: ../core/%.cc
	@echo 'Building file: $<'
	$(CC) -c -Wall $< -o $@
	@echo 'Build finished: $<'
	@echo

