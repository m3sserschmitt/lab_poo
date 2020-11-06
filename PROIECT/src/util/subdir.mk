OBJECTS += ./src/util/time.o 

CC_DEPS += ./src/util/deps/time.d 

./src/util/%.o: ./src/util/%.cc
	@echo 'Building file: $<'
	$(CC) -I./include -Wall -c $< -o $@
	@echo 'Buld finished: $<'
	@echo

./src/util/%.o: ./src/util/%.cpp
	@echo 'Building file: $<'
	$(CC) -I./include -Wall -c $< -o $@
	@echo 'Buld finished: $<'
	@echo

