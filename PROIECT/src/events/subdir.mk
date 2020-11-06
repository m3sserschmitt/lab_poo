OBJECTS += ./src/events/date.o \
./src/events/event.o \
./src/events/notebook.o \
./src/events/notebook_entry.o \
./src/events/time.o 

CC_DEPS += ./src/events/deps/date.d \
./src/events/deps/event.d \
./src/events/deps/notebook.d \
./src/events/deps/notebook_entry.d \
./src/events/deps/time.d 

./src/events/%.o: ./src/events/%.cc
	@echo 'Building file: $<'
	$(CC) -I./include -Wall -c $< -o $@
	@echo 'Buld finished: $<'
	@echo

./src/events/%.o: ./src/events/%.cpp
	@echo 'Building file: $<'
	$(CC) -I./include -Wall -c $< -o $@
	@echo 'Buld finished: $<'
	@echo

