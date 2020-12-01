OBJECTS += ./util/time.o 

CC_DEPS += ./util/deps/time.d 

./util/%.o: ../util/%.cc
	@echo 'Building file: $<'
	$(CC) -c -Wall $< -o $@
	@echo 'Build finished: $<'
	@echo

