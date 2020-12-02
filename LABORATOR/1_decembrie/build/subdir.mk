OBJECTS += ./automobil.o \
./lista_automobile.o \
./main.o \
./masina_interventie.o \
./masina_receptie.o \
./masina_undercover.o 

CC_DEPS += ./deps/automobil.d \
./deps/lista_automobile.d \
./deps/main.d \
./deps/masina_interventie.d \
./deps/masina_receptie.d \
./deps/masina_undercover.d 

./%.o: ../%.cc
	@echo 'Building file: $<'
	$(CC) -c -Wall $< -o $@
	@echo 'Build finished: $<'
	@echo

