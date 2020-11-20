OBJECTS += ./build/lista_produse.o \
./build/main.o \
./build/produs.o \
./build/produs_neperisabil.o \
./build/produs_perisabil.o 

CC_DEPS += ./deps/lista_produse.d \
./deps/main.d \
./deps/produs.d \
./deps/produs_neperisabil.d \
./deps/produs_perisabil.d 

./build/%.o: ./%.c
	@echo 'Building file: $<'
	$(CC) -Wall -c $< -o $@
	@echo 'Buld finished: $<'
	@echo

./build/%.o: ./%.cc
	@echo 'Building file: $<'
	$(CC) -Wall -c $< -o $@
	@echo 'Buld finished: $<'
	@echo

./build/%.o: ./%.cpp
	@echo 'Building file: $<'
	$(CC) -Wall -c $< -o $@
	@echo 'Buld finished: $<'
	@echo

