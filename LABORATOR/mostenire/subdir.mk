OBJECTS += ./main.o \
./persoana.o \
./student.o 

CC_DEPS += ./deps/main.d \
./deps/persoana.d \
./deps/student.d 

./%.o: ./%.c
	@echo 'Building file: $<'
	$(CC) -Wall -c $< -o $@
	@echo 'Buld finished: $<'
	@echo

./%.o: ./%.cc
	@echo 'Building file: $<'
	$(CC) -Wall -c $< -o $@
	@echo 'Buld finished: $<'
	@echo

./%.o: ./%.cpp
	@echo 'Building file: $<'
	$(CC) -Wall -c $< -o $@
	@echo 'Buld finished: $<'
	@echo

