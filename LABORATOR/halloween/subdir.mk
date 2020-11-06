OBJECTS += ./decoratiune.o \
./lista_produse.o \
./main.o 

CC_DEPS += ./deps/decoratiune.d \
./deps/lista_produse.d \
./deps/main.d 

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

