The mapping proccess works as following:

  1- The python code 'serial_read.py' receives the coordinates from the microcontroller, after sending a 'U' first, in pairs. Each pair contains a latitude and longitude.
  
  2- The python code then opens a java file 'where.js' and writes each pair in a new line in the form of a list '[lat, long],'.
  
  3- The java file is then read with an html file 'where.html' to interface and visualise the received coordinates with google maps api and this process requires an API key.
