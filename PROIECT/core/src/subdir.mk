OBJECTS += ./core/src/date.o \
./core/src/event.o \
./core/src/notebook.o \
./core/src/time.o 

CC_DEPS += ./core/src/deps/date.d \
./core/src/deps/event.d \
./core/src/deps/notebook.d \
./core/src/deps/time.d 

./core/src/%.o: ./core/src/%.cc
	@echo 'Building file: $<'
	$(CC) -I./include -Wall -c $< -o $@
	@echo 'Buld finished: $<'
	@echo

./core/src/%.o: ./core/src/%.cpp
	@echo 'Building file: $<'
	$(CC) -I./include -Wall -c $< -o $@
	@echo 'Buld finished: $<'
	@echo

