/*Purpose: To write a program that reads the users current heart
rate, birthday, and the current day, and should output the
users age, current heart rate, maximum heart rate, and target zone range.
If their heart rate is in the target zone congratulate them, if it is out
of their target zone warn them.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int computeAge(int birthYear, int birthMonth, int birthDay, int currentYear, int currentMonth, int currentDay);
int computeMaximumHeartRate(int age);
int computeZoneMinimum(int maximumHeartRate);
int computeZoneMaximum(int maximumHeartRate);
//prototype functions

void main() {
	int birthYear, birthMonth, birthDay;
	int currentYear, currentMonth, currentDay;
	int age;
	int maximumHeartRate;
	int zoneMinimum, zoneMaximum;
	int currentHeartRate;
	//variables

	//date of birth of user
	printf("Please enter your date of birth, adding a space between the month, day, and year: ");
	scanf("%d%d%d", &birthMonth, &birthDay, &birthYear);

	//current date
	printf("Please enter the current date, adding a space between the month, day, and year: ");
	scanf("%d%d%d", &currentMonth, &currentDay, &currentYear);

	//current heart rate of user
	printf("Please enter your current heart rate: ");
	scanf("%d", &currentHeartRate);


	//variables assigned to functions
	age = computeAge(birthMonth, birthDay, birthYear, currentMonth, currentDay, currentYear);
	maximumHeartRate = computeMaximumHeartRate(age);
	zoneMinimum = computeZoneMinimum(maximumHeartRate);
	zoneMaximum = computeZoneMaximum(maximumHeartRate);

	//output
	printf("\nYour current age is %d", age);
	printf("\nYour current heart rate is %d", currentHeartRate);
	printf("\nYour minimum heart rate zone is %d", zoneMinimum);
	printf("\nYour maximum heart rate zone is %d", zoneMaximum);
	printf("\nYour maximum heart rate is %d", maximumHeartRate);

	if (currentHeartRate >= zoneMinimum && currentHeartRate <= zoneMaximum) {
		printf("\nYour heart rate is within the target zone!");
	}
	else
		printf("\nWarning! Your heart rate is outside the target zone!");


}

//age of user
int computeAge(int birthMonth, int birthDay, int birthYear, int currentMonth, int currentDay, int currentYear) {
	int age = currentYear - birthYear;

	if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay))
		age = age - 1;

	return age;
}

//maximum heart rate of user
int computeMaximumHeartRate(int age) {
	int maximumHeartRate = 220 - age;
	return maximumHeartRate;
}

//minimum heart rate zone
int computeZoneMinimum(int maximumHeartRate) {
	int zoneMinimum = 0.5 * maximumHeartRate;
	return zoneMinimum;
}

//maximum heart rate zone
int computeZoneMaximum(int maximumHeartRate) {
	int zoneMaximum = 0.85 * maximumHeartRate;
	return zoneMaximum;
}