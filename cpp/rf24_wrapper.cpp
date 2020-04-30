#include <jni.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include "RF24.h"
#include "com_varel_gereon_RF24_RF24_JNI.h"

JNIEXPORT jlong JNICALL Java_com_varel_gereon_RF24_RF24_1JNI_createObject(JNIEnv *jenv, jclass jcls, jshort jcePin, jshort jcsPin, jlong jspiSpeed) {
	jlong jresult = 0;
	uint8_t arg1;
	uint8_t arg2;
	uint32_t arg3;
	RF24 *result = 0;

	(void)jenv;
	(void)jenv;

	arg1 = (uint8_t)jcePin; 
  	arg2 = (uint8_t)jcsPin; 
  	arg3 = (uint32_t)jspiSpeed; 
  	result = (RF24 *)new RF24(arg1, arg2, arg3);
  	*(RF24 **)&jresult = result;
  	return jresult;
}

JNIEXPORT void JNICALL Java_com_varel_gereon_RF24_RF24_1JNI_deleteObject(JNIEnv *jenv, jclass jcls, jlong jobjPtr) {
	RF24 *arg1 = (RF24*)0;

	(void)jenv;
	(void)jcls;

	arg1 = *(RF24 **)&jobjPtr;
	delete arg1;
}

JNIEXPORT jboolean JNICALL Java_com_varel_gereon_RF24_RF24_1JNI_begin(JNIEnv *jenv, jclass jcls, jlong jobjPtr, jobject jobj) {
	jboolean jresult = 0;
	RF24 *obj = (RF24*)0;
	bool result;

	(void)jobj;
	(void)jenv;
	(void)jcls;

	obj = *(RF24 **)&jobjPtr;
	result = (bool)(obj)->begin();
  	return (jboolean)result;
}

JNIEXPORT void JNICALL Java_com_varel_gereon_RF24_RF24_1JNI_printDetails(JNIEnv *jenv, jclass jcls, jlong jobjPtr, jobject jobj) {
	RF24 *obj = (RF24*)0;
	
	(void)jenv;
	(void)jcls;
	(void)jobj;

	obj = *(RF24 **)&jobjPtr;
	(obj)->printDetails();
}

JNIEXPORT void JNICALL Java_com_varel_gereon_RF24_RF24_1JNI_setRetries(JNIEnv *jenv, jclass jcls, jlong jobjPtr, jobject jobj, jshort jdelay, jshort jcount) {
	RF24 *obj = (RF24*)0;
	uint8_t delay;
	uint8_t count;	

	(void)jenv;
	(void)jcls;
	(void)jobj;

	obj = *(RF24**)&jobjPtr;
	delay = (uint8_t)jdelay;
	count = (uint8_t)jcount;
	(obj)->setRetries(delay, count);
}

JNIEXPORT void JNICALL Java_com_varel_gereon_RF24_RF24_1JNI_openWritingPipe(JNIEnv *jenv, jclass jcls, jlong jobjPtr, jobject jobj, jbyteArray jaddress) {
	RF24 *obj = (RF24*)0;
	uint8_t *address = (uint8_t *)0;

	(void)jenv;
	(void)jcls;
	(void)jobj;

	obj = *(RF24**)&jobjPtr;
	address = (uint8_t*)jenv->GetPrimitiveArrayCritical(jaddress, 0);
	(obj)->openWritingPipe((uint8_t const *)address);
	jenv->ReleasePrimitiveArrayCritical(jaddress, address, 0);
}

JNIEXPORT void JNICALL Java_com_varel_gereon_RF24_RF24_1JNI_openReadingPipe(JNIEnv *jenv, jclass jcls, jlong jobjPtr, jobject jobj, jshort jnumber, jbyteArray jaddress) {
	RF24 *obj = (RF24*)0;
	uint8_t number;
	uint8_t *address = (uint8_t*)0;
	
	(void)jenv;
	(void)jcls;
	(void)jobj;

	obj = *(RF24**)&jobjPtr;
	number = (uint8_t)jnumber;
	address = (uint8_t*)jenv->GetPrimitiveArrayCritical(jaddress, 0);
	(obj)->openReadingPipe(number, (uint8_t const *)address);
	jenv->ReleasePrimitiveArrayCritical(jaddress, address, 0);
}

JNIEXPORT void JNICALL Java_com_varel_gereon_RF24_RF24_1JNI_startListening(JNIEnv *jenv, jclass jcls, jlong jobjPtr, jobject jobj) {
	RF24 *obj = (RF24*)0;
	
	(void)jenv;
	(void)jcls;
	(void)jobj;
	
	obj = *(RF24**)&jobjPtr;
	(obj)->startListening();
}

JNIEXPORT void JNICALL Java_com_varel_gereon_RF24_RF24_1JNI_stopListening(JNIEnv *jenv, jclass jcls, jlong jobjPtr, jobject jobj) {
	RF24 *obj = (RF24*)0;
	
	(void)jenv;
	(void)jcls;
	(void)jobj;
	
	obj = *(RF24**)&jobjPtr;
	(obj)->stopListening();
}

JNIEXPORT jboolean JNICALL Java_com_varel_gereon_RF24_RF24_1JNI_write(JNIEnv *jenv, jclass jcls, jlong jobjPtr, jobject jobj, jbyteArray jbuffer, jshort jlength) {
	RF24 *obj = (RF24*)0;
	void *buffer = (void*)0;
	uint8_t length;
	bool result;

	(void)jenv;
	(void)jcls;
	(void)jobj;
	
	obj = *(RF24**)&jobjPtr;
	buffer = (void*)jenv->GetPrimitiveArrayCritical(jbuffer, 0);
	length = (uint8_t)jlength;
	result = (bool)(obj)->write((void const*)buffer, length);
	jenv->ReleasePrimitiveArrayCritical(jbuffer, buffer, 0);
	return (jboolean)result;
}

JNIEXPORT jboolean JNICALL Java_com_varel_gereon_RF24_RF24_1JNI_available(JNIEnv *jenv, jclass jcls, jlong jobjPtr, jobject jobj) {
	RF24 *obj = (RF24*)0;
	bool result;

	(void)jenv;
	(void)jcls;
	(void)jobj;
	
	obj = *(RF24**)&jobjPtr;
	result = (bool)(obj)->available();
	return (jboolean)result;
}

JNIEXPORT void JNICALL Java_com_varel_gereon_RF24_RF24_1JNI_read(JNIEnv *jenv, jclass jcls, jlong jobjPtr, jobject jobj, jbyteArray jbuffer, jshort jlength) {
	RF24 *obj = (RF24*)0;
	void *buffer = (void*)0;
	uint8_t length;

	(void)jenv;
	(void)jcls;
	(void)jobj;
	
	obj = *(RF24**)&jobjPtr;
	buffer = (void*)jenv->GetPrimitiveArrayCritical(jbuffer, 0);
	length = (uint8_t)jlength;
	(obj)->read(buffer, length);
	jenv->ReleasePrimitiveArrayCritical(jbuffer, buffer, 0);
}

JNIEXPORT jboolean JNICALL Java_com_varel_gereon_RF24_RF24_1JNI_setDataRate(JNIEnv *jenv, jclass jcls, jlong jobjPtr, jobject jobj, jshort jdatarate) {
	RF24 *obj = (RF24*)0;
	rf24_datarate_e datarate;
	bool result;

	(void)jenv;
	(void)jcls;
	(void)jobj;
	
	if ((uint16_t)jdatarate == 2) {
			datarate = RF24_2MBPS;
	} else if ((uint16_t)jdatarate == 3) {
			datarate = RF24_250KBPS;
	} else {
			datarate = RF24_1MBPS;
	}
	obj = *(RF24**)&jobjPtr;
	result = (bool)(obj)->setDataRate(datarate);
	return (jboolean)result;
}

JNIEXPORT jboolean JNICALL Java_com_varel_gereon_RF24_RF24_1JNI_isChipConnected(JNIEnv *jenv, jclass jcls, jlong jobjPtr, jobject jobj) {
	RF24 *obj = (RF24*)0;
	bool result;

	(void)jenv;
	(void)jcls;
	(void)jobj;
	
	obj = *(RF24**)&jobjPtr;
	result = (bool)(obj)->isChipConnected();
	return (jboolean)result;
}

JNIEXPORT void JNICALL Java_com_varel_gereon_RF24_RF24_1JNI_powerDown(JNIEnv *jenv, jclass jcls, jlong jobjPtr, jobject jobj) {
	RF24 *obj = (RF24*)0;

	(void)jenv;
	(void)jcls;
	(void)jobj;
	
	obj = *(RF24**)&jobjPtr;
	(obj)->powerDown();
}

JNIEXPORT void JNICALL Java_com_varel_gereon_RF24_RF24_1JNI_powerUp(JNIEnv *jenv, jclass jcls, jlong jobjPtr, jobject jobj) {
	RF24 *obj = (RF24*)0;

	(void)jenv;
	(void)jcls;
	(void)jobj;
	
	obj = *(RF24**)&jobjPtr;
	(obj)->powerUp();
}
  
JNIEXPORT jboolean JNICALL Java_com_varel_gereon_RF24_RF24_1JNI_txStandBy(JNIEnv *jenv, jclass jcls, jlong jobjPtr, jobject jobj) {
	RF24 *obj = (RF24*)0;
	bool result;

	(void)jenv;
	(void)jcls;
	(void)jobj;
	
	obj = *(RF24**)&jobjPtr;
	result = (bool)(obj)->txStandBy();
	return (jboolean)result;
}
  
JNIEXPORT void JNICALL Java_com_varel_gereon_RF24_RF24_1JNI_closeReadingPipe(JNIEnv *jenv, jclass jcls, jlong jobjPtr, jobject jobj, jshort jpipe) {
	RF24 *obj = (RF24*)0;
	uint8_t pipe;

	(void)jenv;
	(void)jcls;
	(void)jobj;
	
	pipe = (uint8_t)jpipe;
	obj = *(RF24**)&jobjPtr;
	(obj)->closeReadingPipe(pipe);
}
  
JNIEXPORT void JNICALL Java_com_varel_gereon_RF24_RF24_1JNI_setAddressWidth(JNIEnv *jenv, jclass jcls, jlong jobjPtr, jobject jobj, jshort jwidth) {
	RF24 *obj = (RF24*)0;
	uint8_t width;
	
	(void)jenv;
	(void)jcls;
	(void)jobj;
	
	width = (uint8_t)jwidth;
	obj = *(RF24**)&jobjPtr;
	(obj)->setAddressWidth(width);
}

JNIEXPORT void JNICALL Java_com_varel_gereon_RF24_RF24_1JNI_setChannel(JNIEnv *jenv, jclass jcls, jlong jobjPtr, jobject jobj, jshort jchannel) {
	RF24 *obj = (RF24*)0;
	uint8_t channel;
	
	(void)jenv;
	(void)jcls;
	(void)jobj;
	
	channel = (uint8_t)jchannel;
	obj = *(RF24**)&jobjPtr;
	(obj)->setChannel(channel);
}
  
JNIEXPORT void JNICALL Java_com_varel_gereon_RF24_RF24_1JNI_setPayloadSize(JNIEnv *jenv, jclass jcls, jlong jobjPtr, jobject jobj, jshort jsize) {
	RF24 *obj = (RF24*)0;
	uint8_t size;
	
	(void)jenv;
	(void)jcls;
	(void)jobj;
	
	size = (uint8_t)jsize;
	obj = *(RF24**)&jobjPtr;
	(obj)->setPayloadSize(size);
}
  
JNIEXPORT void JNICALL Java_com_varel_gereon_RF24_RF24_1JNI_setAutoAcknowledge(JNIEnv *jenv, jclass jcls, jlong jobjPtr, jobject jobj, jboolean jenable) {
	RF24 *obj = (RF24*)0;
	bool enable;
	
	(void)jenv;
	(void)jcls;
	(void)jobj;
	
	enable = (bool)jenable;
	obj = *(RF24**)&jobjPtr;
	(obj)->setAutoAck(enable);
}
  
JNIEXPORT void JNICALL Java_com_varel_gereon_RF24_RF24_1JNI_setPALevel(JNIEnv *jenv, jclass jcls, jlong jobjPtr, jobject jobj, jshort jlevel) {
	RF24 *obj = (RF24*)0;
	uint8_t level;
	
	(void)jenv;
	(void)jcls;
	(void)jobj;
	
	level = (uint8_t)jlevel;
	obj = *(RF24**)&jobjPtr;
	(obj)->setPALevel(level);
}
