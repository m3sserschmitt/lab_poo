OBJECTS += ./include/data_structures/vector/vector.o 

CC_DEPS += ./include/data_structures/vector/deps/vector.d 

./include/data_structures/vector/%.o: ./include/data_structures/vector/%.cc
	@echo 'Building file: $<'
	$(CC) -I./include -Wall -c $< -o $@
	@echo 'Buld finished: $<'
	@echo

./include/data_structures/vector/%.o: ./include/data_structures/vector/%.cpp
	@echo 'Building file: $<'
	$(CC) -I./include -Wall -c $< -o $@
	@echo 'Buld finished: $<'
	@echo

