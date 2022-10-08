from turtle import delay
import serial.tools.list_ports
import subprocess
import time

ports = serial.tools.list_ports.comports()
serialInst = serial.Serial()

portList = []

for onePort in ports:
    portList.append(str(onePort))
    print(str(onePort))

val = 3 

for x in range(0,len(portList)):
    if portList[x].startswith("COM" + str(val)):
        portVar = "COM" + str(val)
        print(portList[x])

serialInst.baudrate = 9600
serialInst.port = portVar          
serialInst.open()

while True:
    
    if serialInst.in_waiting:
        packet = serialInst.readline()
        distance = packet.decode('utf').rstrip('\n')
        distance = int(distance)
        if (distance<=40):
            subprocess.call("C://Users//adith//AppData//Roaming//Spotify//Spotify.exe")
            time.sleep(25)
           


            
            



