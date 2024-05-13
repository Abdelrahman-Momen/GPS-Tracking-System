import serial
import struct
import json

# Open the serial port
serial_port = serial.Serial('/dev/ttyUSB0', 9600)

with open('where.js', 'w') as fhand:
    fhand.write("myData = [\n")

    try:
        # Start data transmission by sending 'u' to the board
        serial_port.write(b'U')

        while True:
            # Read 8 bytes (4 bytes for latitude and 4 bytes for longitude)
            data = serial_port.read(8)
            if data:
                # Unpack the binary data into latitude and longitude 
                latitude, longitude = struct.unpack('ff', data)
                # Write the coordinates to the file
                fhand.write(f"[{latitude}, {longitude}],\n")
                print("Received: Latitude:", latitude, "Longitude:", longitude)
    except KeyboardInterrupt:
        print("Interrupted")
    finally:
        fhand.write("];\n")
        fhand.close()
        serial_port.close()