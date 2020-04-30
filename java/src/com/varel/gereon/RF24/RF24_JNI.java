package com.varel.gereon.RF24;

/**
 * Native methods declaration.
 */
public class RF24_JNI {
    public static native long createObject(short jcePin, short jcsPin, long jspiSpeed);
    public static native void deleteObject(long jobjPtr);
    public static native boolean begin(long jobjPtr, RF24 rf24);
    public static native void printDetails(long jobjPtr, RF24 rf24);
    public static native void setRetries(long jobjPtr, RF24 rf24, short jdelay, short jcount);
    public static native void openWritingPipe(long jobjPtr, RF24 rf24, byte[] jaddress);
    public static native void openReadingPipe(long jobjPtr, RF24 rf24, short jnumber, byte[] jaddress);
    public static native void startListening(long jobjPtr, RF24 rf24);
    public static native void stopListening(long jobjPtr, RF24 rf24);
    public static native boolean write(long jobjPtr, RF24 rf24, byte[] jbuffer, short jlength);
    public static native boolean available(long jobjPtr, RF24 rf24);
    public static native void read(long jobjPtr, RF24 rf24, byte[] jbuffer, short jlength);
    public static native boolean setDataRate(long jobjPtr, RF24 rf24, short jdatarate);
    public static native boolean isChipConnected(long jobjPtr, RF24 rf24);
    public static native void powerDown(long jobjPtr, RF24 rf24);
    public static native void powerUp(long jobjPtr, RF24 rf24);
    public static native boolean txStandBy(long jobjPtr, RF24 rf24);
    public static native void closeReadingPipe(long jobjPtr, RF24 rf24, short jpipe);
    public static native void setAddressWidth(long jobjPtr, RF24 rf24, short jwidth);
    public static native void setChannel(long jobjPtr, RF24 rf24, short jchannel);
    public static native void setPayloadSize(long jobjPtr, RF24 rf24, short jsize);
    public static native void setAutoAcknowledge(long jobjPtr, RF24 rf24, boolean jenable);
    public static native void setPALevel(long jobjPtr, RF24 rf24, short jlevel);
}
