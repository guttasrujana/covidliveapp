#include<stdio.h>
#include<string.h>

#define  max   5

struct car_order
{
  char cname[20];
  char model[20];
  long long int mno;
  char cid[30];
  char fuel[10];
  char transm[10];
  char carcol[10];
} queue[max],*ptr=&queue[0];

char carname[4][20]={"Tata Nexon","Tata Altroz","Tata Tigor","Tata Tiago"};
float carprice[4]={7.20,5.80,6.50,4.99};
char bodytype[4][10]={"SUV","Hatchback","Sedan","Hatchback"};
float mileage[4]={21.5,25.11,20.3,23.85};
int seats[4]={5,5,5,5};
char fueltype[2][10]={"Petrol","Diesel"};
char transmission[2][10]={"Manual","Automatic"};
char carcolour[6][10]={"White","Silver","Gray","Black","Blue","Red"};

struct feedback
{
    char uname[20];
    char ctype[20];
    int ratings[4];
     char fb[100];
} stack[max],*ptr1=&stack[0];
char review[4][20]={"Exterior","Performance","Value for Money","Comfort"};

int r=-1,f=-1,top=-1;

enum boolean{FALSE,TRUE};

enum boolean isempty()
{

   if(r==-1||f==-1)
      return TRUE;
   else
      return FALSE;

}
enum boolean isfull()
{

   if((f==0&&r==(max-1))||f==r+1)
      return TRUE;
   else
      return FALSE;

}

enum boolean issfull()
{

   if(top==max-1)
      return TRUE;
   else
      return FALSE;

}
enum boolean issempty()
{

   if(top==-1)
      return TRUE;
   else
      return FALSE;

}

void carInquiry(int l)
{
    int x;
    printf("Selected Car Details:\n");
    printf("      CAR NAME: %s\n",carname[l-1]);
    printf("Starting price: %.2f lakhs\n",carprice[l-1]);
    printf("     Body type: %s\n",bodytype[l-1]);
    printf("       mileage: %.2f kmpl approx.\n",mileage[l-1]);
    printf("  No. of seats: %d\n",seats[l-1]);
    printf("----------------------------------------------\n");
    printf("Enter any number to go back to main menu- ");
    scanf("%d",&x);
    return;
}


void  availableCars()
{
    int l;
    printf("All available cars are listed  below: \n");
    printf("1.Tata Nexon\n2.Tata Altroz\n3.Tata Tigor\n4.Tata Tiago\n");
    printf("For further enquiry of each car, press respective Car No.\n");
    printf("To go to main menu, press 0\n");
    scanf("%d",&l);
    if(l>0 && l<5)
    {
        carInquiry(l);   
    }
    else
    return;
}



void cancelOrder()
{
    char ans;
    if(isempty())
    {
       printf("Today's Booking list is empty\n");
    }
   else
    {
       printf("Order cancelled.Please find the cancelled car order details below:\n");
       printf("Customer Name : %s\nCar model : %s\nMobile number : %lld\nEmail ID : %s\n",(ptr+f)->cname,(ptr+f)->model,(ptr+f)->mno,(ptr+f)->cid);
       if(f==r)
       {
          f=-1;
          r=-1;
       }
       else
       {
          f=(f+1)%max;
       }
   }
}

void  addFeedback()
{
    int i,m;
    if(issfull())
      printf("Feedback is full\n");
     else
     {
       top=top+1;
       printf("Please enter customer name:\n");
       fflush(stdin);
       scanf("%s",(ptr1+top)->uname);
       printf("Please enter your car name below:\n");
       fflush(stdin);
       scanf("%s",(ptr1+top)->ctype);
       printf("Rate the Parameters out of 5:\n");
       for(i=0;i<4;i++)
	   {
		printf("%s: ",review[i]);
		fflush(stdin);
		scanf("%d",&(ptr1+top)->ratings[i]);
	   }
        printf("Any suggestions: ");
        fflush(stdin);
        scanf("%s",(ptr1+top)->fb);
        printf("Thanks for your feedback!\n");
     }
}

void popfeedback()
{
    int j;
    if(issempty())
     printf("Feedback is empty\n");
     else
     {
	 printf("Feedback is deleted. Find deleted feeback details below: \n");
     printf("User Name: %s\n",(ptr1+top)->uname);
	 printf("Car Model: %s\n",(ptr1+top)->ctype);
	 printf("Ratings for following out of 5:\n");
	 for(j=0;j<4;j++)
	 {
		printf("%s: ",review[j]);
		printf("%d\n",(ptr1+top)->ratings[j]);
     }	
	 printf("suggestions : %s\n",(ptr1+top)->fb);
	 top=top-1;
     }
}


void displayFeedback()
{

    int i,j;
    if(issempty())
      printf("Feedback is empty\n");
    else
    {
	for(i=top;i>=0;i--)
	{
	    printf("FEEDBACK- %d:\n",i+1);
	    printf("User Name: %s\n",(ptr1+i)->uname);
	    printf("Car Model: %s\n",(ptr1+i)->ctype);
	    printf("Ratings for following out of 5:\n");
	    for(j=0;j<4;j++)
	    {
		printf("%s: ",review[j]);
		printf("%d\n",(ptr1+top)->ratings[j]);
     	}	
	    printf("Suggestions : %s\n",(ptr1+i)->fb);
	}
    }
}

void carDisplay()
{
    int i,count=0;
    if(isempty())
    {
       printf("Sorry No orders to show\n");
       return;
    }
    else
    {
       if(f<=r)
       {
	 for(i=f;i<=r;i++)
	  {
		printf("\nORDER - %d details\n",i+1);
		printf("Customer name: %s\nMobile no: %lld\nEmail ID: %s\n",(ptr+i)->cname,(ptr+i)->mno,(ptr+i)->cid);
       printf("Car name: %s\nColour: %s\nFuel type: %s\nTransmission type: %s\n",(ptr+i)->model,(ptr+i)->carcol,(ptr+i)->fuel,(ptr+i)->transm);

	  }
       }
       else
       {
	    count++;
	    printf("Today order number %d details\n",count);
	   for(i=f;i<=max-1;i++)
	      printf("Name : %s\nCar model : %s\nMobile number : %lld\nID : %s\n",(ptr+i)->cname,(ptr+i)->model,(ptr+i)->mno,(ptr+i)->cid);
	   for(i=0;i<=r;i++)
	      printf("Name : %s\nCar model : %s\nMobile number : %lld\nID : %s\n",(ptr+i)->cname,(ptr+i)->model,(ptr+i)->mno,(ptr+i)->cid);
      } 
    }
}


void carDelivery()
{
    char ans;
    if(isempty())
    {
       printf("There are NO Orders\n");
    }
   else
   {
       printf(" Congratulations! Your car is ready for pickup. Find details here :\n");
       printf("Name : %s\nCar model : %s\nMobile number : %lld\nemail ID : %s\n",(ptr+f)->cname,(ptr+f)->model,(ptr+f)->mno,(ptr+f)->cid);
	   if(f==r)
	   {
	    f=-1;
	    r=-1;
	   }
	   else
	   {
	     f=(f+1)%max;
	   }

   }

}


void addCar()
{
    int x,y,z,w;
    if(isfull())
    {
	printf("Orders are full today. Please visit again tomorrow.\n");
    }
    else
    {
       if(r==-1)
       {
	  f=0;
	  r=0;
       }
       else
       {
	 r=(r+1)%max;
       }

       printf("Enter Customer Name :\n");
       fflush(stdin);
       scanf("%s",(ptr+r)->cname);
       printf("Enter Mobile number :\n");
       fflush(stdin);
       scanf("%lld",&(ptr+r)->mno);
       printf("Enter Email ID :\n");
       fflush(stdin);
       scanf("%s",(ptr+r)->cid);
       do
       {
        printf("Select Car Model:\n1- NEXON   2- ALTROZ   3- TIGOR   4- TIAGO\n");
        scanf("%d",&x);
        if(x<0||x>4)
         printf("Select a valid car model.\n");
       }while(x<0||x>4);
       strcpy((ptr+r)->model,carname[x-1]);
       do
       {
        printf("select car colour:\n1-White  2-Silver  3-Grey  4-Black  5-Blue  6-Red\n");
        scanf("%d",&w);
        if(w<0||w>6)
         printf("Select any given colour.\n");
       }while(w<0||w>6);
       strcpy((ptr+r)->carcol,carcolour[w-1]);
       do
       {
        printf("select fuel type:\n1- Petrol   2-Diesel\n");
        scanf("%d",&y);
        if(y<0||y>2)
         printf("Select a valid fuel type.\n");
       }while(y<0||y>2);
       strcpy((ptr+r)->fuel,fueltype[y-1]);
       do
       {
        printf("select transmission type:\n1- Manual   2- Automatic\n");
        scanf("%d",&z);
        if(y<0||y>2)
         printf("Select a valid transmission type.\n");
       }while(y<0||y>2);
       strcpy((ptr+r)->transm,transmission[z-1]);
       printf("Customer name: %s\nMobile no: %lld\nEmail ID: %s\n",(ptr+r)->cname,(ptr+r)->mno,(ptr+r)->cid);
       printf("Car name: %s\nColour: %s\nfuel type: %s\ntransmission type: %s\n",(ptr+r)->model,(ptr+r)->carcol,(ptr+r)->fuel,(ptr+r)->transm);
       printf("Booking process completed.\nPlease pickup your car in 20 days.\n");

    }

}


int main()
{
    int num,item;

    printf("\t\t--------- WELCOME TO TATA car showroom ---------\t\n");
   
  do
  {
      printf("\n-------------------------------------------------------\n");
      printf("Please select any option by pressing number below:");
      printf("\n1- To view Available cars \n2- To book an order\n3- To pickup an order \n4- To display all orders \n");
      printf("5- To Give feedback  \n6- To display feedback\n");
      printf("7- To cancel an order \n8- To delete feedback \n9- To exit\n");
      scanf("%d",&num);
    switch(num)
    {
        
       case 1:
       availableCars();
       break;
       
       case 2:
       addCar();
       break;
       
       case 3:
       carDelivery();
       break;

       case 4:
       carDisplay();
       break;
       
       case 5:
       addFeedback();
       break;

       case 6:
       displayFeedback();
       break;
       
       case 7:
       cancelOrder();
       break;
       
       case 8:
       popfeedback();
       break;
      
    }
  }while(num!=9);
return 0;
}