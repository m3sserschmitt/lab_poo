OBJECTS += ./data_structures/iterable/vector/vector.o 

CC_DEPS += ./data_structures/iterable/vector/deps/vector.d 

./data_structures/iterable/vector/%.o: ../data_structures/iterable/vector/%.cc
	@echo 'Building file: $<'
	$(CC) -c -Wall $< -o $@
	@echo 'Build finished: $<'
	@echo

