// gps.h 
#ifndef GPS_h
#define GPS_h

// gps module 
#include <string.h>
#define pi 3.14159265359
#define  EARTH_RADIUS 6371000


void GPS_Read(); // to check if the array is correct ?
void GPS_FORMAT(float* arr) ;// split the gps_output array into tokens
float ToDegree (float angle); //distance to degree
float ToRad(float angle);// angle in degree to rad 
float GPS_GetDistance (float currentLong,float currentLat, float destlong,float destlat);// distance fn (The Haversine Formula)

#endif   //GPS_h

	
