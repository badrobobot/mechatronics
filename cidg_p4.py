import serial
import time

class serialArduino:
    def __init__(self, serialPort = '/dev/ttyACM0', serialBaud = 9600):
        self.port = serialPort
        self.baud = serialBaud

        print('Trying to connect to: ' + str(serialPort) + ' at ' + str(serialBaud) + ' BAUD.')
        try:
            self.serialConnection = serial.Serial(serialPort, serialBaud, timeout=4)
            print('Connected to ' + str(serialPort) + ' at ' + str(serialBaud) + ' BAUD.')
        except:
            print("Failed to connect with " + str(serialPort) + ' at ' + str(serialBaud) + ' BAUD.')


    def send2ard(self, angulo):
        self.serialConnection.write(bytes(str(angulo)+'x','utf-8'))


    def close(self):
        self.serialConnection.close()
        print('Disconnected...')
        exit()


# portName = 'COM5'     # for windows users
portName = '/dev/ttyACM0'
baudRate = 9600
s = serialArduino(portName, baudRate)   # initializes all required variables

while True:
    while True:

        deg = input("Write a sexagecimal degree: ")
        try:
            deg = int(deg)
            break
        except ValueError:
            if(deg=="exit"):
                s.close()
            print("Invalid charecter. Try again")
            pass

    if(deg>364 or deg<0):
        print("Degree must be between 0 and 364")
    else:
        s.send2ard(deg)
        #print(deg)
        pass

