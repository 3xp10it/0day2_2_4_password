// 0day2_2_4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "windows.h"
#define PASSWORD "1234567"

int verify_password(char *password)
{
	int authenticated;
	char buffer[44];
	authenticated=strcmp(password,PASSWORD);
	strcpy(buffer,password);
	return authenticated;
}
int main(int argc, char* argv[])
{
	int valid_flag=0;
	char password[1024];
	FILE *fp;
	LoadLibrary("user32.dll");
	if(!(fp=fopen("password.txt","rw+")))
	{
		exit(0);
	}
	fscanf(fp,"%s",password);
	valid_flag=verify_password(password);
	if(valid_flag)
	{
		printf("incorrent password!\n");

	}
	else
	{
		printf("Congratulation!You have passed the verification!\n");
	}
	fclose(fp);
	return 0;
}
