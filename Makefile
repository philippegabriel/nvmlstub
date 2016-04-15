#to install, create a link libnvidia-ml.so.1->libnvmlstub.so.1 
.PHONY: all test lib run clean deinstall install check
LIB=libnvidia-ml.so.1
all: lib
test:
	gcc test.c -ldl -o test
#	gcc test.c -ldl -l:libnvidia-ml.so.1 -o test
lib:
	gcc -fPIC -g -c -Wall nvmlstub.c 
	gcc -shared -Wl,-soname,$(LIB) -o $(LIB) nvmlstub.o -lc
#	gcc -shared -Wl,-soname,libnvmlstub.so.1 -o libnvmlstub.so.1 nvmlstub.c -lc
run:
	./test
clean:
	rm -f *.so* test
deinstall:
	rm /usr/lib/$(LIB)
	ldconfig
install:
	cp $(LIB) /usr/lib/
	ldconfig
check:
	ldconfig -p | grep $(LIB)
