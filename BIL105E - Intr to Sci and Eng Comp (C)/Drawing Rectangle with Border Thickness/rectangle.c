#include <stdio.h>

int h, w, t; //characters for the rectangle's features
int i,j; //integers for the for loops
int p, r, s, m; //integers for the for loops
int k, l; //integers for the for loops
int first; //integer for the while to restart the program

int main (void)
{
	do
	{
		do
		{
		printf ("please enter the height of the rectangle: ");
		scanf ("%d", &h);
	
		printf ("please enter the width of the rectangle: ");
		scanf ("%d", &w);
	
		printf ("please enter the thickness of the rectangle: ");
		scanf ("%d", &t);
		
		} //end do
		
		while (h>20 || w>20 || t>20); //error for the numbers which are greater than 20, end while
	
	 	if (2*t>=h && 2*t>=w) //error for the rectangle which is not possible to draw with the given thickness
			{
				printf ("\nthis kind of rectangle is not possible to draw. the rectangle without thickness is below:\n");
				for (i=0;i<h;i++)
				{
					for (j=1;j<=w;j++) putchar('*');
					printf ("\n");
				} //end for
			} //end if
		
		else if (2*t<w && 2*t<h) //the rectangle with given values
			{
				for (i=0;i<t;i++) //the top of the rectangle
				{
					for (j=1;j<=w;j++) putchar('*');
					printf ("\n");
				} //end for
				
				for (p=0;p<(h-2*t);p++) //the middle of the rectangle
				{
					for (r=1;r<=t;r++) putchar('*');
					{	
						for (s=1;s<=(w-2*t);s++) putchar(' ');
						for(m=1;m<=t;m++) putchar ('*');
					}
					printf ("\n");
				} //end for
			
				for (k=0;k<t;k++) //the bottom of the rectangle
				{
					for (l=1;l<=w;l++) putchar('*');
					printf ("\n");
				} //end for
			} //end if
			
		else if (2*t<h && 2*t>=w) //the rectangle which has the unfeasible thickness for the width
			{
				for (i=0;i<t;i++) //the top of the rectangle
				{		
					for (j=1;j<=w;j++) putchar('*');
					printf ("\n");
				} //end for 
				
				for (p=0;p<(h-2*t);p++) //the middle of the rectangle
				{
					if(w%2==1) //if the width is an odd number
					{
						for (r=1;r<=((w-1)/2);r++) putchar('*');
						for (s=1;s<=1;s++) putchar(' ');
						for (m=1;m<=((w-1)/2);m++) putchar ('*');
						printf ("\n");
					} //end if
					else if (w%2==0) //if the width is an even number
					{
						for (r=1;r<=((w-2)/2);r++) putchar('*');
						for (s=1;s<=2;s++) putchar(' ');
						for (m=1;m<=((w-2)/2);m++) putchar ('*');
						printf ("\n");
					} //end if
				} //end for
				
				for (k=0;k<t;k++) //the bottom of the rectangle
				{
					for (l=1;l<=w;l++) putchar('*');
					printf ("\n");
				} //end for
			}
				
	 	
		else if (2*t>=h && 2*t<w) //the rectangle which has the unfeasible thickness for the height
			{
				if (h%2==1) //if the height is an odd number
					{	
						for (i=0;i<(h-1)/2;i++) //the top of the rectangle
							{
							for (j=1;j<=w;j++) putchar('*');
							printf ("\n");
							} //end for
							
						for (p=0;p<1;p++) //the middle of the rectangle
							{
							for (r=1;r<=t;r++) putchar('*');
								{
								for (s=1;s<=w-2*t;s++) putchar(' ');
									{
									for (m=1;m<=t;m++) putchar ('*');
									}
								printf ("\n");
								} 
							} //end for
							
						for (k=0;k<(h-1)/2;k++) //the bottom of the rectangle
							{
							for (l=1;l<=w;l++) putchar('*');
							printf ("\n");
							} //end for
					}
					
				else if (h%2==0) //if the height is an even number
					{
						for (i=0;i<(h-2)/2;i++) //the top of the rectangle
							{
							for (j=1;j<=w;j++) putchar('*');
							printf ("\n");
							} //end for
						for (p=0;p<2;p++) //the middle of the rectangle
						{
							for (r=1;r<=t;r++) putchar('*');
							{
								for (s=1;s<=w-2*t;s++) putchar(' ');
								{
									for (m=1;m<=t;m++) putchar ('*');
								}
							printf ("\n");
							}
						} //end for
						for (k=0;k<(h-2)/2;k++) //the bottom of the rectangle
							{
							for (l=1;l<=w;l++) putchar('*');
							printf ("\n");
							} //end for
					}					
			}
					
		printf ("\nif you want to continue, please press 1; if you don't, press 0 to exit: \n"); //message for the user to take the command to exit from or restart the program
		scanf ("%d", &first);
		while (first!=0 && first!=1) //error for the numbers which are different from 1 and 0
			{
				printf ("please try again: \n");
				scanf ("%d", &first);
			} //end while
	} //end do
	 	
	while (first==1); //command for the program if the user wants to restart
	
	return 0; //indicates successful termination
} //end main
