OBJECTS += ./core/exceptions/exception.o \
./core/exceptions/index_error.o \
./core/exceptions/invalid_date.o \
./core/exceptions/invalid_time.o 

CC_DEPS += ./core/exceptions/deps/exception.d \
./core/exceptions/deps/index_error.d \
./core/exceptions/deps/invalid_date.d \
./core/exceptions/deps/invalid_time.d 

./core/exceptions/%.o: ../core/exceptions/%.cc
	@echo 'Building file: $<'
	$(CC) -c -Wall $< -o $@
	@echo 'Build finished: $<'
	@echo

