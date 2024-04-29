#include "gps.h"
const double EARTH_RADIUS = 6371000;
#include <math.h>
float ToDegree (float angle){
	int degree = (int)angle/100 ; 
	float minutes = angle -(float)degree*100;
return (degree + (minutes/60) );
}	
	float ToRad(float angle){
		return angle * pi/180 ;
	}
	
	// get angle from degree to rad 


	float GPS_GetDistance (float currentLong,float currentLat, float destlong,float destlat){
	   	float currentLongRad = ToRad(ToDegree(currentLong));
			float currentLatRad = ToRad(ToDegree(currentLat));
			float destlongRad = ToRad(ToDegree(destlong));
			float destlatRad = ToRad(ToDegree(destlat));
		
		//get diff  
		
		float longDiff = destlongRad - currentLongRad ;
		float latDiff  = destlatRad - currentLatRad ; 
		// calculate distance 
		float a = pow(sin(latDiff)/2,2)+ cos(currentLatRad)*cos(destlatRad)*pow(sin(longDiff)/2,2);// haversine formula a = sin2((qb-qa)/2)+ cos(qa)*cos(qb)*sin2((ib-ia)/2)
		//where q is latitude and i is longitude of points a and b 
		
		double c = 2*atan2(sqrt(a),sqrt(1-a));
		return EARTH_RADIUS * c ; 
	}
	
			