//gps.c
//gps module 


#include <stdlib.h>
#include <stdint.h>
#include "gps.h"
#include <math.h>
#include <string.h>
#include "UART.h"
static float currentLat;
static float currentlong;

char* token;


char GPS[100];
char GPS_formated[15][30];
char GPS_LogName[] = "$GPRMC,";



void GPS_Read(){
	char i,Recieved_char,GPSCOUNTER=0,flag = 1 ;

	do{
		flag = 1 ;
		for(i=0 ;i<7;i++)
		{ 
			Recieved_char = MCAL_UART_ReadChar(UART2);
			if(Recieved_char != GPS_LogName[i])      // get_charFn from uart
			{
				flag = 0;
				break ;
			}
		}
	}
	while (flag == 0);	// i make sure that i get the correct log 
	
	strcpy(GPS , "");           //init gps 
	do
	{	
		Recieved_char = MCAL_UART_ReadChar(UART2);
		GPS[GPSCOUNTER++] = Recieved_char;
	}
	while(Recieved_char!='*');
}

void GPS_FORMAT(float* arr)
{
	char counter = 0;
	float speed;
	token = strtok(GPS,","); // first time parameter = gps array
	do 
	{
		strcpy(GPS_formated[counter],token);
		token = strtok(NULL,",");
		
		counter++;
	}while(token!=NULL);
		
	
	if(strcmp(GPS_formated[1],"A")== 0)			// valid gps output 
	{
		if(strcmp(GPS_formated[3],"N")==0)
			currentLat = atof(GPS_formated[2]);// if was N then it is + 
		else 
			currentLat = -atof(GPS_formated[2]);
		
		if(strcmp(GPS_formated[5],"E")==0)
			
			currentlong = atof(GPS_formated[4]);
		else
			currentlong = - atof(GPS_formated[4]);
		speed = atof(GPS_formated[6]);
		
		 arr[0] 	= currentLat;
		 arr[1]   = currentlong;
		 arr[2] = speed;
	}
}
		
float ToDegree (float angle){
	int degree = (int)angle/100 ; 
	float minutes = angle -(float)degree*100;
	return (degree + (minutes/60) );
}	


float ToRad(float angle){
	return angle * pi/180;
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
	
			
