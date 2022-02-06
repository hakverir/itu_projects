#include <stdio.h> 	//the libraries that I used as source in the program
#include <stdlib.h>
#include <string.h>
//the list of the functions that I will use in the program
double sum (double x, double y); 	//sum function to add
double diff (double x, double y);	 //diff (difference) function to subtract
double division (double x,double y);	 //division function to divide
double multip (double x, double y); 	//multip function to multiply
double modul (int x, int y); 	//modul function to find modulus
long long factorial (long long n);	 //factorial function to find factorial
double power (double x, long long n);	 //power function to take a number's power
double absolute (double n);	 //absoulte function to find absolute value
double expo (long long n); 	//expo function to find exponent(based on 10)
double sine (double angle);	 //sine function to find sine
double cosine (double angle);	 //cosine function to find cosine
double tangent (double angle); //tangent function to find tangent
double pi (); 	//pi function for pi

int main(void)
{
	int i;	//counter for the loop
	double input1;		//double integer for the numbers that the user gives
	char input2[3];		//array for the operation codes that the user gives
	double input3;		//double integer for the numbers that the user gives
	char input4[3]="ab";//array for the operation codes that the user gives
	double hold, x;		//integers which keeps the results in memory
	int counter=0;		//operation counter
	
		for(i=0;i<57;i++) printf("-");	 //opening message
		printf ("\n");
		printf ("The list of operations in this simple calculator:\n");
		printf ("sine (S), cosine (N), tangent (T), exponent (E)\n");
		printf ("power (W), absolute (A), factorial (F)*\n");
		printf ("add (+), subtract (-), divide(/), multiply(*), modulus (%) \n");
		printf ("pi (P)\n");
		printf ("Quit (Q)\n");
		printf ("Memory (M)\n");
		printf ("Clear (C)\n");
		printf ("Memory Clear (MC)\n");
		printf ("Memory Return (MR)\n");
		for(i=0;i<57;i++) printf("-");
		printf ("\n");	 //opening message end
		
		printf ("Enter user input: ");	//the first number to start
		scanf ("%lf", &input1);
		if(input1=='Q') exit(0);	//if the user writes "Q", the program will terminate
	
		printf ("Enter user input: ");	//the first integer to do the operation
		scanf ("%s", input2);
		if(strcmp(input2,"Q")==0) exit(0);	//if the user writes "Q", the program will terminate
		
		do{
			
			if(strcmp(input4,"MR")==0){		//if "MR" was entered before
				printf ("Enter user input: ");		//start again
				scanf ("%lf", &input1);
	
				printf ("Enter user input: ");
				scanf ("%s", input2);
			}		// end if
					
			if (strcmp(input2,"S")==0){	//if the operation is sine
				printf ("sin(%lf) = %lf\n", input1, sine(input1));	//print the sine of input1
				input1=sine(input1);	//hold sine of input1 in input1
				x=sine(input1);		//hold sine of input1 in x
				counter++;	//an operation is over, add 1 to operation counter
				strcpy(input4, input2);	//copy the value of input2 to input4
			}		// end if
			
			else if (strcmp(input2,"N")==0){	//if the operation is cosine
				printf ("cos(%lf) = %lf\n", input1, cosine(input1));	//print the cosine of input1
				input1=cosine(input1);	//hold cosine of input1 in input1
				x=cosine(input1);	//hold cosine of input1 in x
				counter++;	//an operation is over, add 1 to operation counter
				strcpy(input4, input2);	//copy the value of input2 to input4
			}		// end if
			
			else if (strcmp(input2,"T")==0){	//if the operation is tangent
				printf ("tan(%lf) = %lf\n", input1, tangent(input1));	//print the tangent of input1
				input1=tangent(input1);	//hold tangent of input1 in input1
				x=tangent(input1);	//hold tangent of input1 in x
				counter++;	//an operation is over, add 1 to operation counter
				strcpy(input4, input2);	//copy the value of input2 to input4
			}		// end if
			
			else if (strcmp(input2,"E")==0){	//if the operation is exponent
				if(counter==0){	//if the program is working for the first time
					printf ("exp(%lf) = %lf\n", input1, expo((long long) input1));	//print the value of the exponent of input1
					input1=expo((long long) input1);	//hold the exponent of input1 in input1
					x=expo((long long) input1);	//hold the exponent of input1 in x
					}		// end if
				else if(counter>0){	//if the program has worked more than one time
					printf ("Enter user input: ");	//take another input for the exponent
					scanf ("%lf", &input3);
					printf ("%lf * exp(%lf) = %lf\n", input1, input3, multip(input1, expo((long long) input3)));	//print the value of the exponent of input3 times input1
					input1=multip(input1, expo((long long) input3));	//hold the exponent of input3 times input1 in input1
					x=multip(input1, expo((long long) input3));	//hold the exponent of input3 times input1 in x
				}		// end if
					counter++;	//an operation is over, add 1 to operation counter
					strcpy(input4, input2);	//copy the value of input2 to input4
			}		// end if
			
			else if (strcmp(input2,"W")==0){	//if the operation is power
				printf ("Enter user input: ");	//take another input for the power function
				scanf ("%lf", &input3);
				printf ("%lf ^ %lf = %lf\n", input1, input3, power((double)input1, (int)input3)); //print the value of input1 to the power input3
				input1=power((double)input1, (int)input3);	//hold input1 to the power input3 in input1
				x=power((double)input1, (int)input3);	//hold input1 to the power input3 in x
				counter++;	//an operation is over, add 1 to operation counter
				strcpy(input4, input2);	//copy the value of input2 to input4	
			}		// end if
			
			else if (strcmp(input2,"A")==0){	//if the operation is absoulte
				printf ("|%lf| = %lf\n", input1, absolute(input1));	//print the absolute value of input1
				input1=absolute(input1);	//hold absolute value of input1 in input1
				x=absolute(input1);	//hold absolute value of input1 in x
				counter++;	//an operation is over, add 1 to operation counter
				strcpy(input4, input2);	//copy the value of input2 to input4
			}		// end if
			
			else if (strcmp(input2,"F")==0){	//if the operation is factorial
				printf ("Factorail(%lf) = %lld\n", input1, factorial((long long)input1));	//print the factorial of input1
				input1=factorial((long long)input1);	//hold the factorial of input1 in input1
				x=factorial((long long)input1);	//hold the factorial of input1 in x
				counter++;	//an operation is over, add 1 to operation counter
				strcpy(input4, input2);	//copy the value of input2 to input4
			}		// end if
			
			else if (strcmp(input2,"+")==0){	//if the operation is add
				printf ("Enter user input: ");	//take another input for the sum
				scanf ("%lf", &input3);
				printf("%lf + %lf = %lf\n", input1, input3, sum(input1, input3));	//print the sum of input1 and input3
				input1=sum(input1, input3);	//hold the sum of input1 and input3 in input1
				x=sum(input1, input3);	//hold the sum of input1 and input3 in x
				counter++;	//an operation is over, add 1 to operation counter
				strcpy(input4, input2);	//copy the value of input2 to input4
			}		// end if
			
			else if (strcmp(input2,"-")==0){	//if the operation is subtract
				printf ("Enter user input: ");	//take another input for the subtraction
				scanf ("%lf", &input3);
				printf ("%lf - %lf = %lf\n", input1, input3, diff(input1, input3));	//print the difference of input1 and input3
				input1=diff(input1, input3);	//hold the difference of input1 and input3 in input1
				x=diff(input1, input3);	//hold the difference of input1 and input3 in x
				counter++;	//an operation is over, add 1 to operation counter
				strcpy(input4, input2);	//copy the value of input2 to input4
			}		// end if
			
			else if (strcmp(input2,"/")==0){	//if the operation is division
				printf ("Enter user input: ");	//take another input for the division
				scanf ("%lf", &input3);
				printf ("%lf / %lf = %lf\n", input1, input3, division(input1, input3));	//print the division of input1 and input3
				input1=division(input1, input3);	//hold the division of input1 and input3 in input1
				x=division(input1, input3);	//hold the division of input1 and input3 in x
				counter++;	//an operation is over, add 1 to operation counter
				strcpy(input4, input2);	//copy the value of input2 to input4
			}		// end if
			
			else if (strcmp(input2,"*")==0){	//if the operation is multiplication
				printf ("Enter user input: ");	//take another input for the multiplication
				scanf ("%lf", &input3);
				printf ("%1lf * %lf = %lf\n", input1, input3, multip(input1, input3));	//print the multiplication of input1 and input3
				input1=multip(input1, input3);	//hold the multiplication of input1 and input3 in input1
				x=multip(input1, input3);	//hold the multiplication of input1 and input3 in x
				counter++;	//an operation is over, add 1 to operation counter
				strcpy(input4, input2);	//copy the value of input2 to input4
			}		// end if
			
			else if (strcmp(input2,"%")==0){	//if the operation is modulus
				printf ("Enter user input: ");	//take another input for the multiplication
				scanf ("%lf", &input3);
				printf ("%lf %c %lf = %lf\n", input1, 37, input3, modul((int)input1, (int)input3));	//print the modulus of input1 with respect to the input3
				input1=modul((int)input1, (int)input3);	//hold the modulus of input1 with respect to the input3 in input1
				x=modul((int)input1, (int)input3);	//hold the modulus of input1 with respect to the input3 in x
				counter++;	//an operation is over, add 1 to operation counter
				strcpy(input4, input2);	//copy the value of input2 to input4
				}		// end if
			
			else if (strcmp(input2,"P")==0){	//if the operation is pi
				printf ("%lf", pi()); //print the value of pi on the screen
				input1=pi();	//hold pi in input1
				x=pi();	//hold pi in x
				counter++;	//an operation is over, add 1 to operation counter
				strcpy(input4, input2);	//copy the value of input2 to input4
			}		// end if
			
			else if (strcmp(input2,"M")==0){	//if the operation is memory
				hold=x; //assign the value of x to hold
			}		// end if
			
			else if (strcmp(input2,"C")==0){//if the operation is clear
				hold=x=0;	//equalize hold and x to 0
				system("clear");
			}		// end if
			
			else if (strcmp(input2,"MC")==0){//if the operation is memory clear
				x==0; //equalize x to 0
			}		// end if
			
			else if (strcmp(input2,"MR")==0){//if the operation is memory return
				printf("%.1lf\n", hold);
				if(x==0){	//if the memory is equal to 0
				strcpy(input4, input2); //copy the value of input2 to input4
				continue;	//go back to "do"
				}
			}		// end if
			
			else{//if the input is not one of the defined operations
				printf("Invalid character. Choose from the operators below:\n");//warning
				for(i=0;i<57;i++) printf("-");//repeat of the opening message
				printf ("\n");
				printf ("The list of operations in this simple calculator:\n"
		                "sine (S), cosine (N), tangent (T), exponent (E)\n"
                		"power (W), absolute (A), factorial (F)\n"
         				"add (+), subtract (-), divide(/), multiply(*), modulus (%) \n"
                		"pi (P)\n"
                		"Quit (Q)\n"
                		"Memory (M)\n"
                		"Clear (C)\n"
                		"Memory Clear (MC)\n"
                		"Memory Return (MR)\n");
				for(i=0;i<57;i++) printf("-");
				printf ("\n");//end of the repeat of the opening message
			}		// end if
			
			printf ("Enter user input: ");//operation input for a next calculation
			scanf ("%s", input2);
		}
		while(strcmp(input2,"Q")!=0);//while the user doesn't enter "Q", the program works
		return 0;
		} //end main

double sum (double x, double y)	//the sum function
{
	return x+y;	//returns the sum of x and y
}

double diff (double x, double y)	//the diff function
{
	return x-y;	//returns the difference of x and y
}

double division (double x,double y)	//the division function
{
	return x/y;	//returns the division of x and y
}

double multip (double x, double y) //the multip function
{
	return x*y;	//returns the multiplication of x and y
}

double modul (int x, int y) //the modul function
{
	return x%y;	//returns the modulus of x with respect to the y
}

long long factorial (long long n) //the factorial function
{
	long long f=1; //starter for the multiplication
	int i; //counter
	if (n==0) return 1;	// if n is 0, returns 1
	else {	//else
		for(i=1;i<=n;i++) f*=i;	//multiplicates f with i and assigns the result to f till n
		}
	return f; //returns the value of f
}

double power (double x, long long n) //the power function
{
	double y=1; //starter for the multiplication
	long long i; //counter
	if (n==0) return 1;	// if b is 0, returns 1
	else if(n>0){	//if n is negative
		for (i=1;i<=n;i++) y*=x; //multiplicates y with x and assigns the result to y till n
		}//end if
	else if(n<0){	//if n is negative
		n=-n;	//takes the absolute of n
		for (i=1;i<=n;i++) y*=x; //multiplicates y with x and assigns the result to y till n
		y=1/y;	//assigns the result of 1/y to y
		}
	return y;	//returns the value of y
}

double absolute (double n)	//the absolute function
{
	if(n<0) n=-n;	//if n is negative, turns n to positive
	return n;	//returns the value of n
}

double expo (long long n)	//the expo function
{
	long long i;	//counter
	double x=1;	//starter for the multiplication
	int hold=10;	//the value of base(instead of e)
	if(n==0) return 1;	//if n is 0, returns 1
	else if (n>0){	//if n is positive
		for(i=0;i<n;i++) x*=hold;}	//multiplicates x with hold and assigns the result to x till n
	else if(n<0){	//if n is negative
		n=-n;	//takes the absolute of n
		for(i=0;i<n;i++) x*=hold;	//multiplicates x with hold and assigns the result to x till n
		x=1/x; //assigns the result of 1/x to x
		}	//end if
	return x; //returns the value of x
}

double pi()	//the pi function
{
	return 22.0/7.0;	//returns the value of 22/7(the pi number)
}

double sine (double angle)	//the sine function
{
	double sin=0;	//the integer to store the result
	long long i;	//counter
	if (angle==0 || angle==180 || angle==360) return 0;	//returns 0 when the value of the sine of the given angle is 0
	if (angle==90) return 1;	//returns 1 when the value of the sine of the given angle is 1
	if (angle==270) return -1;	//returns -1 when the value of the sine of the given angle is -1
	if (angle<180 && angle>90) sin=sine(180-angle);	//trigonometric equations for sine to sine in the cartesian coordinates regions
	if (angle<270 && angle>180) sin=-sine(angle-180);
	if (angle<360 && angle>270) sin=-sine(360-angle);
	if (angle<90 && angle>0){	//sine function in the first area of cartesian coordinate system with respect to the taylor series
		angle*=(22.0/(7.0*180));
		for(i=1;i<=30;i++){
		sin+=power(-1,i+1)*power(angle,2*i-1)/factorial(2*i-1);
		}
	}
	return sin;	//returns the value of sin
}

double cosine (double angle)	//the cosine function
{
	double sine();	//uses sine function
	if (angle<=90) return sine(90-angle);	//trigonometric equations for cosine to sine in the cartesian coordinates regions
	if (angle>90 && angle<=180) return -sine(angle-90);
	if (angle>180 && angle<270) return -sine(270-angle);
	if (angle>=270 && angle<=360) return sine(angle-270);
}

double tangent (double angle)
{
	double sine (), cosine ();	//uses sine and cosine functions
	if (cosine(angle)==0) printf("undefined\n");	//if the cosine of the angle is 0, that means it's going to be number/0, and it prints undefined
	else if (angle==180) return 0;	//if the angle is 180 degrees, returns 0
	else if (cosine(angle)!=0) return (sine (angle)/cosine(angle));	//,f cosine of the angle is not 0, returns sine of the angle over cosine of the angle
}
