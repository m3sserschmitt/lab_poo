OBJECTS += ./util/src/time.o 

CC_DEPS += ./util/src/deps/time.d 

./util/src/%.o: ./util/src/%.cc
	@echo 'Building file: $<'
	$(CC) -I./include -Wall -c $< -o $@
	@echo 'Buld finished: $<'
	@echo

./util/src/%.o: ./util/src/%.cpp
	@echo 'Building file: $<'
	$(CC) -I./include -Wall -c $< -o $@
	@echo 'Buld finished: $<'
	@echo

