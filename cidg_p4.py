# https://www.luisllamas.es/controlar-arduino-con-python-y-la-libreria-pyserial/


import serial
ser = serial.Serial('COM6', 9600)
time.sleep(3)
ser.write('Hello world')

while True:
  while True:
    deg = input("Write a sexagecimal degree: ")
    try:
      deg = int(deg)
      break
    except ValueError:
      print("Invalid charecter. Try again")
      pass 
    
  print(deg)
  pass
      
 
