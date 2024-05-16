import serial
import struct
import json

# Open the serial port
serial_port = serial.Serial('COM3', 9600)
data = serial_port.readline().decode("utf-8").strip()

# Wait for U to send back another U and start receiving data
while data != 'U':
    data = serial_port.readline().decode("utf-8").strip()

    # send U to start receiving data
serial_port.write(b'U')
with open('where.js', 'w') as fhand:
    fhand.write("myData = [\n")

    while True:
        # Read a latitude
        data = serial_port.readline().decode("utf-8").strip()
        # Ignore the sent U on the serial port
        if data == "U":
            continue
        # Check if all the latitudes are sent            
        if data == "Done":
            break
        if data:
            # Write the coordinates to the file
            fhand.write("[" + data +", ")
            print(data+',')

        # Read a longitude
        data = serial_port.readline().decode("utf-8").strip()
        # Ignore the sent U on the serial port        
        if data == "U":
            continue
        # Check if all the longitudes are sent
        if data == "Done":
            break
        if data:
            # Write the coordinates to the file
            fhand.write( data + "],"+"\n")
            print(data + '\n')
            
    fhand.write("];\n")
    fhand.close()    
serial_port.close()
print('open where.html to see your coordinates on the map')
