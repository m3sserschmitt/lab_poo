OBJECTS += ./data_structures/src/vector/vector.o 

CC_DEPS += ./data_structures/src/vector/deps/vector.d 

./data_structures/src/vector/%.o: ./data_structures/src/vector/%.cc
	@echo 'Building file: $<'
	$(CC) -I./include -Wall -c $< -o $@
	@echo 'Buld finished: $<'
	@echo

./data_structures/src/vector/%.o: ./data_structures/src/vector/%.cpp
	@echo 'Building file: $<'
	$(CC) -I./include -Wall -c $< -o $@
	@echo 'Buld finished: $<'
	@echo

