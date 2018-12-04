#include<iostream>
#include<fstream>
#include<windows.h>
#include<cstdlib>
#include<conio.h>
using namespace std;
/*---------------------------------------------------------------------------*/
// Global variable declaration
double sks;
/*--------------------------------------------------------------------------------*/
//function declaration 
void show1();
void show2();
void show3();
void show4();
void show5();
void keepon();
void cursor();

	void gotoxy(int x ,int y)
	{
		COORD coord;
		coord.X=x;
		coord.Y=y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
	}	
CONSOLE_SCREEN_BUFFER_INFO csbi; // used to create cursore effect
//function used to slow the output
void sleep()
 			{
 				int i;
 				char a[]="HEALTH",k[]="GUIDE";
 			
 				for(i=0;i<6;i++)
                   {   gotoxy(46+i,1);
                    	cout<<a[i];
	                    Sleep(150);
                   }
                for(i=0;i<5;i++)
                   {   gotoxy(52+i,2);
                    	cout<<k[i];
	                    Sleep(150);
 		         	}
 		         }
/*--------------------------------------------------------------------------------*/
//parent class starts
class a{
	public:
	char name[30] , gender;
	double weight, height , age ;
	public:
		void getdata()
		{
			gotoxy(30,10);
			cout<<"Enter your Name ";
			cin>>name;
			gotoxy(30,12);
			cout<<"Enter your Weight in Kg : "; 
			cin>>weight;
			gotoxy(30,14);
			cout<<"Enter your Height in Meters : "; 
			cin>>height;
			gotoxy(30,16);
			cout<<"Enter your age : ";
			cin>>age;
			gotoxy(30,18);
			cout<<"Enter your gender (M/F)";
			cin>>gender;
		}
	};
	class calculate : public a
	{ public:
		int  RMR , HRM , THR_Max , THR_Min , DWI ;
		double bmi ;
	  public:
		double calc_bmi()
		{
			bmi=weight/( height * height );
			cout<<" Your BMI :- "<<bmi<<endl;
			return bmi;
		}
		void display_rest()
		{
	
				if(gender=='m'||gender=='M')
	 		{
	 			cout<<"******************************************"<<endl;
	 			RMR=(9.99*weight+6.25*height-4.92*age+5);
	 			gotoxy(30,10);
	 			cout<<"Resting Metabolic Rates(in kcal) is="<<RMR;
	 			gotoxy(30,12);
				cout<<"Body Mass Index is="<<bmi ;
	            gotoxy(30,14);
	    		HRM=(220-age);
	 			cout<<"Heart Rate Max (in bpm) is="<<HRM;
	 			THR_Max=(HRM*0.85);
	 			THR_Min=(HRM*0.65);
	 			gotoxy(30,16);
	 			cout<<"Training Heart Rate ( in bpm ) is="<<THR_Max<<"-"<<THR_Min<<endl;
	    		DWI=(weight*2.205)/2.2;
	 			if(age<30)
	 	 			{
	 	 				DWI =	(DWI*40)/28.3;
	 	 				DWI =  (DWI * 0.0296);
	 	 				gotoxy(30,18);
	 	 				cout<<"Daily Water Intake (in litre) is="<<DWI<<endl;
	 	 	    		cout<<"\n";
	    
		  }
	    else if(age>30&&age<55 )
	     {
	     	DWI = (DWI*35)/28.3;
	     	DWI = (DWI*0.0296);
	     	gotoxy(30,18);
	     	cout<<"Daily Water Intake (in litre ) is="<<DWI<<endl;
	     		    cout<<"\n";
	    }
	    else
		 {
		 	DWI = (DWI*30)/28.3;
		 	DWI = (DWI*0.0296);
		 	gotoxy(30,18);
		 	cout<<"Daily Water Intake (in litre ) is="<<DWI<<endl;
		 		    cout<<"\n";
	    
		 	
		 }
	}
		 else if(gender=='f'||gender=='F')
	 {
	 	system("color B");
	 	RMR=(9.99*weight+6.25*height-4.92*age-161);
	 	gotoxy(30,10);
	 	cout<<"Resting metabolic rates (in kcal) is="<<RMR;
	 	gotoxy(30,12);
	 	cout<<"Body Mass Index is="<<bmi;
	    HRM=(220-age);
	    gotoxy(30,14);
	 	cout<<"Heart Rate Max (in bpm) is="<<HRM;
	 	THR_Max=(HRM*0.85);
	 	THR_Min=(HRM*0.65);
	 	gotoxy(30,16);
	 	cout<<"Training Heart Rate ( in bpm ) is="<<THR_Max<<"-"<<THR_Min;
	 	cout<<"\n";
	    DWI=(weight*2.205)/2.2;
	 	if(age<30)
	 	 {
	 	 DWI =	(DWI*40)/28.3;
	 	 DWI =  (DWI * 0.0296);
	 	 gotoxy(30,18);
	 	 cout<<"Daily Water Intake (in litre) is="<<DWI;
	 	 	    cout<<"\n";
		 }
	    else if(age>30&&age<55 )
	     {
	     	DWI = (DWI*35)/28.3;
	     	DWI = (DWI*0.0296);
	     	gotoxy(30,18);
	     	cout<<"Daily Water Intake (in litre ) is="<<DWI;
	     }
		 else 
		 {
		 	DWI = (DWI*30)/28.3;
		 	DWI = (DWI*0.0296);
		 	gotoxy(30,18);
		 	cout<<"Daily Water Intake (in litre ) is="<<DWI;
		    }
		}
	 	else
		 {
		 	system("cls");
	 	gotoxy(30,16);
	  	cout<<"you have entered wrong input";
		}
		}
		};
/*------------------------------------------------------------------------------*/
//child class starts		
class b:public calculate
{
	public:
		void display(string dietOrExercise)
		{  
			system("cls");
			if (dietOrExercise == "diet"){
				if (bmi>=30)
		{
			gotoxy(50,0);
			cout<<"You are Obesse "<<endl;
			gotoxy(50,1);
			cout<<"Meals\t\t\tExercises";
			gotoxy(52,2);
			cout<<"^";
			show1();
		}
		else if (bmi>= 25 && bmi<30)
		{
			gotoxy(50,0);
			cout<<"You are Overweight"<<endl;
			show3();
		}
		else if (bmi>=18.9 && bmi<25)
			{
				gotoxy(50,0);
				cout<<"You are Normal"<<endl;
			}
		else if (bmi<18.9)
			{
					gotoxy(50,0);
				cout<<"You are Underweight"<<endl;
			    show5();
			}
			}
			else{
				if (bmi>=30)
		{
			gotoxy(50,0);
			cout<<"You are Obesse "<<endl;
			gotoxy(50,1);
			cout<<"Meals\t\t\tExercises";
			gotoxy(75,2);
			cout<<"^";
			show2();
		}
		else if (bmi>= 25 && bmi<30)
		{
			gotoxy(50,0);
			cout<<"You are Overweight"<<endl;
			show4();
		}
		else if (bmi>=18.9 && bmi<25)
			{
					gotoxy(50,0);
				cout<<"You are Normal. No exercise needed"<<endl;
			}
		else if (bmi<18.9)
			{
					gotoxy(50,0);
				cout<<"You must gain weight first."<<endl;
              
			}
			}
		}
};
/*--------------------------------------------------------------------------------*/
//class start
class c
{
	double fat , carbohydrate , protein;
	double fatcalories , carbohydrate_calories , proteincalories;
	double totalcalories; 
	public :
	void get1()
	{	
	system("cls");
	gotoxy(35,5);
	cout<<"              CALORIES COUNTER       ";
	gotoxy(35,6);
	cout<<"Enter number of gram of fat ";
	cin>>fat;
	gotoxy(35,7);
	cout<<"Enter number of gram of protiens ";
	cin>>protein;
	gotoxy(35,8);
	cout<<"Enter number of gram of carbohydrate ";
	cin>>carbohydrate;
    }
    void display1();
};
 void c :: display1()
{
	char choise;
	fatcalories = fat*9;
	carbohydrate_calories = carbohydrate*4;
	proteincalories = protein*4;
	totalcalories = fatcalories + carbohydrate_calories + proteincalories;
	gotoxy(35,9);
	cout<<"Total calories consumed = "<<totalcalories<<endl;
}
/*--------------------------------------------------------------------------------*/
//main page class start
class menu : public b , public c 
{
	public:
		int k;
	void menu1()
		{ 	    
		system("color E2");
		        gotoxy(35,5);
    			cout<<"----------------------------------\n";
    			gotoxy(35,6);
				cout<<"     MAIN MENU                    \n";
				gotoxy(35,7);
				cout<<"     1) CALORIE CALCULATOR        \n";
				gotoxy(35,8);
				cout<<"     2) BMI CALCULATOR            \n";
				gotoxy(35,9);
				cout<<"     3) exit                      \n";
				gotoxy(35,10);
    			cout<<"----------------------------------\n";
    			gotoxy(35,11);
    			cout<<"Enter your choice\n";
    			gotoxy(35,12);
    			cin>>k;
    			switch(k)
    				{
    					case 1: c c1 ;
    							c1.get1();
    							c1.display1();
    							keepon();
        					break;
    					case 2:	system("cls");
								b b1;
								b1.getdata();
								sks=b1.calc_bmi();
								
								b1.display_rest(); 
				
								cursor();
								keepon();
							break;  	
						case 3:exit(1);
							break;
						default: printf("wrong input");
						
			}
		}
};
/*-------------------------------------------------------------------------------*/
//main function start
	int main()
	{ 
	sleep();
	  menu m;
	  m.menu1();
	  
	}
/*-------------------------------------------------------------------------------*/
//function deffinition	

	void show1()
	{
		system("color A");
		ifstream o2("DIet_obees.txt");
		char ch;
		while(!o2.eof())
			{
				ch=o2.get();
				cout<<ch;
			}
		o2.close();
	}
	void show2()
	{
		ifstream o3("Exercise_obees.txt");
		char ch1;
		while(!o3.eof())
			{
				ch1=o3.get();
				cout<<ch1;
			}
		o3.close();
	}
	void show3()
	{
		system("color 9");
		ifstream o2("Diet_over_weight.txt");
			char ch;
			while(!o2.eof())
				{
					
					ch=o2.get();
					cout<<ch;
				}
			o2.close();
		}
		void show4()
		{
		
			ifstream o3("Exercise_over_weight.txt");
			char ch1;
			while(!o3.eof())
				{
					ch1=o3.get();
					cout<<ch1;
				}
			o3.close();
	}
	void show5()
	{
		system("color E");
		ifstream o2("Diet_under_weight.txt");
			char ch;
			while(!o2.eof())
				{
					ch=o2.get();
					cout<<ch;
				}
			o2.close();
	}
	void keepon()
	{
		char k,y,n;
		cout<<"Do you want to continue Y/N";
		cin>>k;
		while(1)
		{
		if(k=='y' || k=='Y')
		{
			system("cls");
			menu m1;
			m1.menu1();
		}
		else if (k=='n' || k=='N')
		{
			exit(1);
		}
		else 
		{
			cout<<"WRONG INPUT";
			exit(1);
		}
		}
	}
	
	void cursor(){
		b objectOfb;
        objectOfb.bmi=sks;		
		getch();
		system("cls");
			gotoxy(90,0);
			cout<<"ESC: Exit";
			gotoxy(50,3);
			cout<<"Diet\t\tExcercise";
			gotoxy(51,4);
			cout<<"^";
			int ch;
			while(1){
				ch = _getch();
				if (ch == 13){
					
				}
				else if (ch == 27){
					system("cls");
					keepon();
					exit(1);
				}
				else switch(ch = _getch()){
					//Left arrow detection
					case 75: printf("\b \b");					
					 		 GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
							 if (csbi.dwCursorPosition.X == 68){
							 	system("cls");
							 	gotoxy(90,0);
								cout<<"ESC: Exit";
								gotoxy(50,3);
								cout<<"Diet\t\tExcercise";
							 	gotoxy(51,4);
							 	printf("^");
								GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
								if(csbi.dwCursorPosition.X == 52){
									objectOfb.display("diet");
									gotoxy(csbi.dwCursorPosition.X,csbi.dwCursorPosition.Y);
								}
							 }
							 else {
							 	gotoxy(51,4);
							 	cout<<"^";
							 } 
							break;
					//Right arrow detection
					case 77:printf("\b \b");
							GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
							if (csbi.dwCursorPosition.X == 51){
								system("cls");
							 	gotoxy(90,0);
								cout<<"ESC: Exit";
								gotoxy(50,3);
								cout<<"Diet\t\tExcercise";
							 	gotoxy(68,4);
							 	printf("^");
							 	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
								if (csbi.dwCursorPosition.X == 69){
									objectOfb.display("exercise");
									gotoxy(csbi.dwCursorPosition.X,csbi.dwCursorPosition.Y);
								}
							 }
							 else {
							 	gotoxy(68,4);
							 	cout<<"^";
							 } 
							
							 
							break;
					
				}
		 		
		}
	}

	//the end
	/*-------------------------------------------------------*/
