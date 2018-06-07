// maxFunkcji.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>	
#include<conio.h>         	
#include<stdlib.h>         		

typedef struct Chromosom             		
{
	short int bit[6];
	int fit;
}chromosom;                           	

void *evpop(chromosom popcurrent[4]);    	
int x(chromosom popcurrent);
int y(int x);
void *pickchroms(chromosom popcurrent[4]);
void *krzyzowanie(chromosom popnext[4]);
void *mutacja(chromosom popnext[4]);

void main()
{
	int num;
	int i, j;
	// DLA: y = -x ^ 2 + 5 


	cout << endl << "Liczba iteracji:  ");
	cin >> num;

	chromosom popcurrent[4];
	chromosom popnext[4];

	if (num < 1)
		goto enter;

	evpop(popcurrent);

	for (i = 0; i < num; i++)
	{

		cout << endl << "i = " << i);

		for (j = 0; j < 4; j++)
			popnext[j] = popcurrent[j];

		pickchroms(popnext);
		krzyzowanie(popnext);
		mutacja(popnext);

		for (j = 0; j < 4; j++)
			popcurrent[j] = popnext[j];

	}
	system("pause");
}



void *evpop(chromosom popcurrent[4])               	
{
	int i, j, value;
	int random;
	for (j = 0; j<4; j++)                         
	{
		for (i = 0; i<6; i++)            			

		{
			random = rand();               		
			random = (random % 2);        			
			popcurrent[j].bit[i] = random;  		
		}  

		value = x(popcurrent[j]);               	
		popcurrent[j].fit = y(x(popcurrent[j]));	
		cout << "popcurrent[" << j << "]" << popcurrent[j].bit[5], popcurrent[j].bit[4], popcurrent[j].bit[3], popcurrent[j].bit[2],
			popcurrent[j].bit[1], popcurrent[j].bit[0] << " value = " << value << "fitness = " << value << popcurrent[j].fit);  

	}                                                               


	return(0);
}                              	

int x(chromosom popcurrent)        	
{
	int z;
	z = (popcurrent.bit[0] * 1) + (popcurrent.bit[1] * 2) + (popcurrent.bit[2] * 4) + (popcurrent.bit[3] * 8) + (popcurrent.bit[4] * 16);
	if (popcurrent.bit[5] == 1)
		z = z*(-1);                  	   
	return(z);                	
}                             	

int y(int x)          		
{
	int y;
	y = -(x*x) + 5;            	//  y= - ( x^ 2 ) +5
	return(y);
}                             

void *pickchroms(chromosom popcurrent[4])   	
{

	int i, j;
	chromosom temp;                            

	for (i = 0; i<3; i++)               		
	for (j = 0; j<3; j++)
	{
		if (popcurrent[j + 1].fit>popcurrent[j].fit)
		{
			temp = popcurrent[j + 1];
			popcurrent[j + 1] = popcurrent[j];
			popcurrent[j] = temp;

		}  
	}                

	for (i = 0; i < 4; i++)
		cout << endl << "Sorting:popnext[" << i << "] fitness= " << popcurrent[i[.fit;	
	cout << endl;
	return(0);
}                       

void *krzyzowanie(chromosom popnext[4]) 
{
	int random;
	int i;
	random = rand();                                  	
	random = ((random % 5) + 1);                    		
	for (i = 0; i<random; i++)                     	
	{
		popnext[2].bit[i] = popnext[0].bit[i];        	
		popnext[3].bit[i] = popnext[1].bit[i];     	
	} 

	for (i = random; i<6; i++)                        	
	{
		popnext[2].bit[i] = popnext[1].bit[i];     
		popnext[3].bit[i] = popnext[0].bit[i];       	
	}   

	for (i = 0; i<4; i++)
		popnext[i].fit = y(x(popnext[i]));     	

	for (i = 0; i < 4; i++)
		cout << "CrossOver popnext[" << i << "]=" << popnext[i].bit[5] << popnext[i].bit[4] << popnext[i].bit[3]<< popnext[i].bit[2] << 
		popnext[i].bit[1] << popnext[i].bit[0] << " value =" << x(popnext[i]) << "fitness = " << popnext[i].fit);

	return(0);
}                  

void *mutacja(chromosom popnext[4])   
{

	int random;
	int row, col, value;
	random = rand() % 50;                  

	if (random == 25)
	{
		col = rand() % 6;
		row = rand() % 4;

		if (popnext[row].bit[col] == 0)
			popnext[row].bit[col] = 1;

		else if (popnext[row].bit[col] == 1)
			popnext[row].bit[col] = 0;

		popnext[row].fit = y(x(popnext[row]));
		value = x(popnext[row]);
		cout << end << "Mutacja popnext[" << row << "] bit[" << col << "]=" << popnext[row].bit[5] << popnext[row].bit[4] << popnext[row].bit[3] <<
			popnext[row].bit[2] << popnext[row].bit[1] << popnext[row].bit[0] << " value = " << value << "fitness = " << popnext[row].fit;
	}

	return(0);
}                     

