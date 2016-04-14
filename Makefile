#to install, create a link libnvidia-ml.so.1->libnvmlstub.so.1 
all: lib
test:
	gcc test.c -ldl -o test
#	gcc test.c -ldl -l:libnvidia-ml.so.1 -o test
lib:
	gcc -fPIC -g -c -Wall nvmlstub.c 
	gcc -shared -Wl,-soname,libnvidia-ml.so.1 -o libnvidia-ml.so.1 nvmlstub.o -lc
#	gcc -shared -Wl,-soname,libnvmlstub.so.1 -o libnvmlstub.so.1 nvmlstub.c -lc
run:
	./test
clean:
	rm -f *.so* test
