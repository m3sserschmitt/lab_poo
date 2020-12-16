OBJECTS += ./util/time.o \
./util/util.o 

CC_DEPS += ./util/deps/time.d \
./util/deps/util.d 

./util/%.o: ../util/%.cc
	@echo 'Building file: $<'
	$(CC) -c -Wall $< -o $@
	@echo 'Build finished: $<'
	@echo

