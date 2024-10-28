#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

float A, B, C;
float ooz;

float cubeWidth = 10;
int width = 160, height = 44;
float zBuffer[160 * 44];
char buffer[160 * 44];
int BackgroundASCIICode = ` `;

double incrementSpeed =  0.6;

int distanceFromCam = 60;

float calculateX(int i, int j, int k)
{
	return j * sin(A) * sin (B) * cos(C) - K * cos(A) * sin(B) * cos(C) +
	       	j * cos(A) * sin(C) + k * sin(A) * sin (C) + i * cos(B) * cos(C);
}

float calculateY(int i , int j, int k)
{
	return j * cos(A) * cos(C) + k * sin(A) * cos(C) -
		j * sin(A) * sin(B) * sin(C) +k * cos(A) * sin(B) * sin(C) -
		i * cos(B) * sin(C);
}

float caclculateZ(int i, int j, int k)
{
	return k * cos(A) * cos(B) - j * sin(A) * cos(B) + i * sin(B);
}

void calculateForSurface(float cubeX, float cubeY, float cubeZ, int ch)
{
	float x = calculateX(cubeX, cubeY, cubeZ);
	float y = calculateX(cubeX, cubeY, cubeZ);
	float z = calculateX(cubeX, cubeY, cubeZ) + distanceFromCam;

	ooz = 1/z;
}

int main()
{
	printf("OK");
	while(1){
	memset(buffer, BackgroundASCIICode, width * height);
	memset(Zbuffer, 0 , width * height * 4);
	for(float cubeX  = - cubeWidth; cubeX < cubeWidth; cubeX+= incrementSpeed)
		{
			for(float cubeY = - cubeWidth; cubeY < cubeWidth; cubeY += incrementSpeed)
			{
				calculateForSurface(cubeX, cubeY, -cubeWidth, '#');
			}
		}
	}
	return 0;
}
