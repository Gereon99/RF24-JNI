# RF24-JNI

This library provides access to the NRF24L01 module with Java by using the Java Native Interface.
(This was inspired by [this](https://github.com/anvo/rf24-bcm-java) library, since that didn't work for me anymore.)

## How to use

After cloning the repository execute the following commands:
  ```
  git submodule init
  git submodule update
  make lib
  make wrapper
  ```
  
Make sure that the ```JAVA_INCLUDE``` path inside the ```Makefile``` is correct, since this might vary for you.
  
The ```*.so``` file will then be compiled into ```cpp/lib/```.
Theres also a precompiled library already located there, if you don't want to recompile it by yourself.

## Using the library in Java
The Java source code is located in ```java/src``` and can be used to create a simple library.
Again, theres also a precompiled library located in ```java/lib/```.

Creating and using the ```RF24``` class:

```
System.loadLibrary("rf24JniLib"); // Load the library somewhere in the code.
RF24 rf24 = new RF24((short)22, (short)8); // CE-Pin, CS-Pin
rf24.begin();
...
``` 
