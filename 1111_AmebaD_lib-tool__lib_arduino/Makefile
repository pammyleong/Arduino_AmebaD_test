

.PHONY: arduino

AR = arm-none-eabi-ar.exe
OBJS = o_lib/*.o
REMOVE = -rm -f 

arduino:
	$(REMOVE) o_lib/main.o
	$(REMOVE) *.a
	$(AR) rvs lib_arduino.a $(OBJS)


