package com.varel.gereon.RF24;

/**
 * Actual Java implementation.
 */
public class RF24 {

    private long cPtr;

    protected RF24(long cPtr) {
        this.cPtr = cPtr;
    }

    /**
     * Default constructor with 8MHz spi speed.
     * @param cePin Pin thats connected to the modules CE-pin
     * @param csPin Pin thats connected to the modules CS-pin
     */
    public RF24(short cePin, short csPin) {
        this(RF24_JNI.createObject(cePin, csPin, 32));
    }

    /**
     * Constructor to additionally specify the spi speed.
     * @param cePin Pin thats connected to the modules CE-pin
     * @param csPin Pin thats connected to the modules CS-pin
     * @param spiSpeed Divider for the spi speed. (e.g. '32' for 8MHz)
     */
    public RF24(short cePin, short csPin, long spiSpeed) {
        this(RF24_JNI.createObject(cePin, csPin, spiSpeed));
    }

    /**
     * Deletes the C++ reference of this object.
     */
    public synchronized void delete() {
        if (this.cPtr != 0) {
            RF24_JNI.deleteObject((short)cPtr);
            this.cPtr = 0;
        }
    }

    /**
     * Initializes the module.
     * @return Returns '1', if the initialization process was successful, '0', if not.
     */
    public boolean begin() {
        return RF24_JNI.begin(this.cPtr, this);
    }

    /**
     * Prints some information about this module.
     */
    public void printDetails() {
        RF24_JNI.printDetails(this.cPtr, this);
    }

    /**
     * Sets the amount and delay of retries, if transmission failed.
     * @param delay Delay in multiples of 250us. Maximum value is 15.
     * @param count Amount of retries before giving up. Maximum value is 15.
     */
    public void setRetries(short delay, short count) {
        RF24_JNI.setRetries(this.cPtr, this, delay, count);
    }

    /**
     * Opens a writing pipe on the specified address.
     * @param address Address to use.
     */
    public void openWritingPipe(byte[] address) {
        RF24_JNI.openWritingPipe(this.cPtr, this, address);
    }

    /**
     * Opens a reading pipe.
     * @param number Which pipe to open. Values between 0 and 5.
     * @param address The address of the pipe to open. (40 bit)
     */
    public void openReadingPipe(short number, byte[] address) {
        RF24_JNI.openReadingPipe(this.cPtr, this, number, address);
    }

    /**
     * Starts to listen.
     */
    public void startListening() {
        RF24_JNI.startListening(this.cPtr, this);
    }

    /**
     * Stops to listen.
     */
    public void stopListening() {
        RF24_JNI.stopListening(this.cPtr, this);
    }

    /**
     * Transmits a buffer. (Maximum 32 bytes)
     * @param buffer Buffer to send.
     * @param length Length of the buffer.
     * @return Returns '1', if the transmission was successful, '0', if not.
     */
    public boolean write(byte[] buffer, short length) {
        return RF24_JNI.write(this.cPtr, this, buffer, length);
    }

    /**
     * Checks, if a payload is available.
     * @return Returns '1', if a payload is available, '0', if not.
     */
    public boolean available() {
        return RF24_JNI.available(this.cPtr, this);
    }

    /**
     * Reads data into a buffer.
     * @param buffer Buffer in which the read data is stored.
     * @param length Length of the buffer.
     */
    public void read(byte[] buffer, short length) {
        RF24_JNI.read(this.cPtr, this, buffer, length);
    }

    /**
     * Sets the datarate rate of this module. (250Kbps, 1Mbps, 2Mbps)
     * @param datarate New datarate.
     * @return Returns '1', if the datarate change was successful, '0', if not.
     */
    public boolean setDataRate(RF24_Datarate datarate) {
        short temp = 1;
        switch (datarate) {
            case RF24_2MBPS:
                temp = 2;
                break;
            case RF24_250KBPS:
                temp = 3;
        }
        return RF24_JNI.setDataRate(this.cPtr, this, temp);
    }

    /**
     * Checks whether or not if a module is connected.
     * @return Returns true, if a module is connected. Returns false, if not.
     */
    public boolean isChipConnected() {
        return RF24_JNI.isChipConnected(this.cPtr, this);
    }

    /**
     * Enters low-power mode.
     */
    public void powerDown() {
        RF24_JNI.powerDown(this.cPtr, this);
    }

    /**
     * Leaves low-power mode.
     */
    public void powerUp() {
        RF24_JNI.powerUp(this.cPtr, this);
    }

    /**
     * Should be called after transmission to change the modules mode to the Standby-1 mode.
     * @return Returns true, if successful.
     */
    public boolean txStandBy() {
        return RF24_JNI.txStandBy(this.cPtr, this);
    }

    /**
     * Closes a reading pipe.
     * @param pipe Pipe to close.
     */
    public void closeReadingPipe(short pipe) {
        RF24_JNI.closeReadingPipe(this.cPtr, this, pipe);
    }

    /**
     * Sets the address width from 3 to 5 bytes.
     * @param width Width of the address.
     */
    public void setAddressWidth(short width) {
        RF24_JNI.setAddressWidth(this.cPtr, this, width);
    }

    /**
     * Sets the current channel.
     * @param channel Channel to use, values between 0-125.
     */
    public void setChannel(short channel) {
        RF24_JNI.setChannel(this.cPtr, this, channel);
    }

    /**
     * Sets the payload size. Maximum value is 32 bytes.
     * @param size New payload size.
     */
    public void setPayloadSize(short size) {
        RF24_JNI.setPayloadSize(this.cPtr, this, size);
    }

    /**
     * Enables or disables the auto acknowledge packets.
     * @param enable Value for auto acknowledge packets.
     */
    public void setAutoAcknowledge(boolean enable) {
        RF24_JNI.setAutoAcknowledge(this.cPtr, this, enable);
    }

    /**
     * Sets the PA level.
     * @param paLevel PA level to use.
     */
    public void setPALevel(RF24_PA paLevel) {
        short level = 0;
        switch (paLevel) {
            case RF24_PA_LOW:
                level = 1;
                break;
            case RF24_PA_HIGH:
                level = 2;
                break;
            case RF24_PA_MAX:
                level = 3;
        }
        RF24_JNI.setPALevel(this.cPtr, this, level);
    }

    /**
     * Simple example
     */
    public void gettingStartedExample() {
        final String[] pipes = {"1Node", "2Node"};

        System.out.println("RF24/examples/GettingStarted");

        this.printDetails();

        this.openWritingPipe(pipes[1].getBytes());
        this.openReadingPipe((short) 1, pipes[0].getBytes());

        this.startListening();

        while (true) {
            long started_waiting_at = System.currentTimeMillis();
            boolean timeout = false;
            while (!this.available() && !timeout) {
                if (System.currentTimeMillis() - started_waiting_at > 200) {
                    timeout = true;
                }
            }

            if (!this.isChipConnected()) {
                System.out.println("No module connected.");
                return;
            }
            if (timeout) {
                System.out.println("Failed, response timed out.");
            } else {
                byte[] receivedBytes = new byte[100];
                this.read(receivedBytes, (short)100);
                String message = new String(receivedBytes);
                System.out.println("Got response: " + message);
            }
        }
    }

}
