JAVA_INCLUDE=/usr/lib/jvm/java-7-openjdk-armhf/include

wrapper:
	g++ -fPIC -c cpp/rf24_wrapper.cpp -I$(JAVA_INCLUDE) -I$(JAVA_INCLUDE)/linux -I./cpp/RF24/ -I./java/src/com/varel/gereon/RF24/ -o cpp/RF24_wrap.o -include cpp/RF24/RF24.h
	gcc -shared -lstdc++ cpp/RF24_wrap.o cpp/RF24/RF24.o cpp/RF24/bcm2835.o cpp/RF24/spi.o -o cpp/lib/librf24JniLib.so
	sudo cp cpp/lib/librf24JniLib.so /lib/
lib:
	cd cpp/RF24/ && make clean && make all