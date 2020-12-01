OBJECTS += ./build/automobil.o \
./build/lista_automobile.o \
./build/main.o \
./build/masina_interventie.o \
./build/masina_receptie.o \
./build/masina_undercover.o 

CC_DEPS += ./deps/automobil.d \
./deps/lista_automobile.d \
./deps/main.d \
./deps/masina_interventie.d \
./deps/masina_receptie.d \
./deps/masina_undercover.d 

./build/%.o: ./%.c
	@echo 'Building file: $<'
	$(CC) -c -Wall $< -o $@
	@echo 'Build finished: $<'
	@echo

./build/%.o: ./%.cc
	@echo 'Building file: $<'
	$(CC) -c -Wall $< -o $@
	@echo 'Build finished: $<'
	@echo

./build/%.o: ./%.cpp
	@echo 'Building file: $<'
	$(CC) -c -Wall $< -o $@
	@echo 'Build finished: $<'
	@echo

