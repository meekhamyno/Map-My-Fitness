#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<process.h>
#include<graphics.h>
#include<dos.h>

void EGG();
void OATS();
void BANANA();
void SPINACH();
void CHICKEN();

class health
{
	private:
		char name[20];
		 float height,weight;
		 float bmi,totalcal,calburnt;
	public:
		void getdata();
		void checkbmi();
		int findcalorie();
		void exercise();
		void display();
		void resetcalorie()
		{
		  totalcal=calburnt=0;
		}
		char* getname()
		{
			return (name);
		}
		void graphex();
		void search(char[]);
} h;		//creating object h

void health ::getdata() //to display the item we recommend you to have
{
	int code;
	clrscr();
	cout<<"\n\n\n";
	cout<<"\nInorder to keep your weight in check,we recommend you to include this in your\n diet: ";
	cout<<"\n1.EGG\n";
	cout<<"2.OATS\n";
	cout<<"3.BANANA\n";
	cout<<"4.SPINACH\n";
	cout<<"5.CHICKEN\n";
	cout<<"\nEnter the code of the item you want to search: ";
	cin>>code;
	switch(code)
	{
		case 1 :EGG(); break;
		case 2 :OATS(); break;
		case 3 :BANANA(); break;
		case 4 :SPINACH(); break;
		case 5 :CHICKEN(); break;
		default:cout<<"SORRY!We do not recommend you to include this food item in your diet:";
			break;
	}

}

void health::checkbmi() //to calculate the BMI
{
	cout<<"\nEnter your name:";
	gets(name);
	cout<<"\nEnter your height(in meters):";
	cin>>height;
	cout<<"\nEnter your weight(in kilograms):";
	cin>>weight;
	bmi=(weight/pow(height,2));
	cout<<"\nYour BMI is "<<bmi;
	{
		 if(bmi>=30)
		 {
			 cout<<"\nYou are obese";
			 cout<<"\nYou can only consume 1200 cal a day";
		 }
		 else if(bmi>=25 && bmi<30)
		 {
			 cout<<"\nYou are slightly overweight";
			 cout<<"\nYou could consume 1240 cal per day";
		 }
		 else if(bmi>=18.5 && bmi<25)
		 {
			cout<<"\nYou are at a normal weight";
			cout<<"\nYou can consume 1500 cal per day";
		  }
		 else
		 {
			cout<<"\nYou are underweight";
			cout<<"\nYou need to consume a minimum of 2000 cal per day in order to avoid from being\nmalnourished";
		 }
	}
	getch();
}

int health::findcalorie() //to calculate the total amount of calories consumed
{
	char foodname[40];
	int calorie=0;
	cout<<"\n\nEnter the name of the food item you want to consume: ";
	gets(foodname);
	if(strcmpi(foodname,"scrambled egg")==0)
		calorie=108;
	else if(strcmpi(foodname,"egg soup")==0)
		calorie=106;
	else if(strcmpi(foodname,"boiled egg white")==0)
		calorie=69;
	else if(strcmpi(foodname,"oatmeal")==0)
		calorie=183;
	else if(strcmpi(foodname,"oats roti")==0)
		calorie=98;
	else if(strcmpi(foodname,"oats dahi vada")==0)
		calorie=141;
	else if(strcmpi(foodname,"banana pancake")==0)
		calorie=99;
	else if(strcmpi(foodname,"banana shake")==0)
		calorie=197;
	else if(strcmpi(foodname,"boiled banana")==0)
		calorie=170;
	else if(strcmpi(foodname,"sprouts dhokla")==0)
		calorie=32;
	else if(strcmpi(foodname,"spinach paratha")==0)
		calorie=160;
	else if(strcmpi(foodname,"vegetable oats pancake")==0)
		calorie=101;
	else if(strcmpi(foodname,"chicken salad")==0)
		calorie=182;
	else if(strcmpi(foodname,"chicken soup")==0)
		calorie=130;
	else
		calorie=245;
	totalcal+=calorie;
    return totalcal;
}

void health::exercise() //to calculate the smount of calories burnt
{
	clrscr();
	int exercode;
	float minutes;
	cout<<"\nThe following exercises could be performed to stay fit:";
	cout<<"\n1.Running";
	cout<<"\n2.Step ups";
	cout<<"\n3.Swimming";
	cout<<"\n4.Push ups";
	cout<<"\n5.Jumping Jacks";
	cout<<"\n6.Treadmill";
	cout<<"\nEnter the name of the exercise you have performed today:";
	cin>>exercode;
	cout<<"\nEnter the amount of time(in minutes) you have performed the above exercise:";
	cin>>minutes;
	h.graphex();
	switch(exercode)
	{
		case 1 : calburnt=minutes*14.30;break;
		case 2 : calburnt=minutes*11.70;break;
		case 3 : calburnt=minutes*9.75;break;
		case 4 : calburnt=minutes*9.10;break;
		case 5 : calburnt=minutes*9.75;break;
		case 6 : calburnt=minutes*3.9;break;
	}
	cout<<"\nCalories burnt: "<<calburnt;
	cout<<"\n\t\n\n\n\t\tSore Today,Strong Tomorrow.";
	cout<<"\n\t\tCongratulations on completing your workout!!";
	getch();

}

void health::display() 
{
	ifstream fin;
	char name1[20];
	fin.open("health.dat",ios::binary|ios::in);
	if(!fin)
	{
		cout<<"Cannot open file";
	}
	while(fin.read((char*)&h,sizeof(h)))
	{
		cout<<name<<"\t"<<height<<"\t"<<weight<<"\t";
		cout<<bmi<<"\t"<<totalcal<<"\t\t"<<calburnt<<endl;
	}
	fin.close();

}

void health::graphex() //to display the moving cycle
{
	int d=0,m;
	initgraph(&d,&m,"c:\\turboc3\\BGI");
	for(int x=0;x<650;x++)
	{
		cleardevice();
		line(10,401,630,401);
		circle(40+x,370,30);
		circle(150+x,370,30);
		line(40+x,370,100+x,370);
		line(40+x,370,60+x,340);
		line(100+x,370,120+x,340);
		line(120+x,340,60+x,340);
		line(60+x,340,60+x,335);
		line(55+x,335,65+x,335);
		line(150+x,370,100+x,320);
		line(100+x,320,90+x,320);
		delay(10);
	}
	getch();
	closegraph();

}

void health::search(char name1[20]) //to display the details of the customer you want to search for
{
	clrscr();
	cout<<"Enter the name of the customer you want to search for:";
	gets(name1);
	  cout<<"\nHeight              :"<<height;
	  cout<<"\nWeight             :"<<weight;
	  cout<<"\nBMI                   :"<<bmi;
	  cout<<"\nCalorie Intake :"<<totalcal;
	  cout<<"\nCalorie burnt  :"<<calburnt;
	getch();
}

void EGG()
{
	cout<<"\nDishes you could make with EGG:";
	cout<<"\n1.Scrambled Egg    (1 serve) :108 Cal";
	cout<<"\n2.Egg Soup         (1 bowl)  :106 Cal";
	cout<<"\n3.Boiled Egg White (132 gm)  :69 Cal";
}

void OATS()
{
	cout<<"\nDishes you could make with OATS:";
	cout<<"\n1.Oatmeal         (1 cup)    :183 Cal";
	cout<<"\n2.Oats Roti       (1 piece)   :98 Cal";
	cout<<"\n3.Oats Dahi Vada  (1 serving) :141 Cal";
}

void BANANA()
{
       cout<<"\nDishes you could make with BANANA:";
       cout<<"\n1.Banana Pancake (1 piece)  :99 Cal";
       cout<<"\n2.Banana Shake   (1 glass)  :197 Cal";
       cout<<"\n3.Boiled Banana  (1 bowl)   :170 Cal";
}

void SPINACH()
{
       cout<<"\nDishes you could make with SPINACH:";
       cout<<"\n1.Sprouts Dhokla         (1 piece) :32 Cal";
       cout<<"\n2.Spinach Paratha        (1 piece) :160 Cal";
       cout<<"\n3.Oats Vegetable Pancake (1 piece) :101 Cal";
}

void CHICKEN()
{
       cout<<"\nDishes you could make with CHICKEN:";
       cout<<"\n1.Chicken Salad  (1 bowl)   :182 Cal";
       cout<<"\n2.Chicken Soup   (1 bowl)   :130 Cal";
       cout<<"\n3.Sesame Chicken (1 katori) :245 Cal";
}

void welcome()
{
	cout<<"\n\n\n\n\n";
	cout<<"\t\t MAP MY FITNESS: EatBetter.LiveHealthy.";
	cout<<"\n\n\tTrack BMI.Meal Plans.Count Calories.Workout Companion.";
	cout<<"\n\t\t\n\t\n\n\n\n\n\t\tPress any key to explore further...";
	getch();
}

void writefile()
{
	ofstream fout;
	fout.open("health.dat",ios::binary|ios::app);
	fout.write((char*)&h, sizeof(h));
	fout.close();
}

void readfile()
{
	ifstream fin;
	char name1[20];
	fin.open("health.dat",ios::binary||ios::in);
	if(!fin)
	{
		cout<<"Cannot open file";
	}
	while(fin.read((char*)&h,sizeof(h)))
	{
		h.display();
	}
	fin.close();
}

void modifyfile(char nm[20]) //to modify the details of a customer
{
	fstream file("health.dat",ios::in|ios::out|ios::binary);
	int flag=0;
	cout<<"Enter the name of the customer you want to modify:";
	gets(nm);
	char c;
	int totalcal=0;
	while(!file.eof())
	{
		int pos=file.tellg();
		file.read((char*)&h,sizeof(h));
		if(strcmpi(h.getname(),nm)==0)
		{
			clrscr();
			cout<<"Found Customer "<<h.getname()<<" in data file.."<<endl;
			do
			{
				h.resetcalorie();
				h.getdata();
				cout<<"\nEnter your updates:\n";
				totalcal=h.findcalorie();
				cout<<"do you want to continue enter more items:";
				cin>>c;
			} while(c=='y' || c=='Y');

			cout<<" Updated calorie intake:"<<totalcal;
			h.exercise();
			file.seekg(pos,ios::beg);
			file.write((char*)&h,sizeof(h));
			flag=1;
			break;
		}
	}
    if(flag==0)
	cout<<"Customer" <<nm <<"not found";
    file.close();

}
void deletefile(char namee[20])  //to delete the details of a customer
{
	clrscr();
	cout<<"Enter the name of the customer you want to delete:";
	gets(namee);
	fstream temp,file;
	char found='f';
	file.open("health.dat",ios::in|ios::binary);
	temp.open("temp.dat",ios::out|ios::binary);
	while(!file.eof())
	{
	    file.read((char*)&h,sizeof(h));
	    if(strcmpi(h.getname(),namee)==0)
	      found='t';
	    else
	       temp.write((char*)&h,sizeof(h));
	}
	if(found=='f')
	cout<<"Customer not found";
	else
	cout<<"Customer details deleted";
	file.close();
	temp.close();
	remove("health.dat");
	rename("temp.dat","health.dat");
}
void addfile() //to add details of customers
{
	clrscr();
	int totalcal=0;
	char choice;
	h.resetcalorie();
	h.checkbmi();
	do
	{
	  h.getdata();
	  totalcal=h.findcalorie();
	  cout<<"Do you want to continue enter more items? (Y/N): ";
	  cin>>choice;
	}while(choice=='y'||choice=='Y');
	cout<<"Total calories consumed: "<<totalcal;
	getch();
	h.exercise();
	writefile();
}

void report() //to display the daily report of all the customers
{
	clrscr();
	cout<<"\n\n\t\t\t REPORT FOR TODAY";
	cout<<"\n--------------------------------------------------------------------------------";
	cout<<"\nNAME\tHEIGHT\tWEIGHT\tBMI\t\tCALORIE\t\tCALORIES";
	cout<<"\n\t\t\t\t\tINTAKE\t\tBURNT";
	cout<<"\n--------------------------------------------------------------------------------\n";
	h.display();
	cout<<"\n--------------------------------------------------------------------------------";
	getch();

}

void graphlogo() //to display the logo of the application
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\BGI");
	settextstyle(6,0,6);
	setcolor(LIGHTGREEN);
	delay(135);
	outtextxy(270,110,"MMF");
	outtextxy(80,290,"EatBetter.LiveHealthy");
	circle(310,150,100);
	delay(1000);
	cleardevice();
	closegraph();
}

void main()
{
	clrscr();
	graphlogo();
	welcome();
	clrscr();
	char choice,nm[20],namee[20],name1[20];
	int chh;
	do
	{
		clrscr();
		cout<<"\nCHECK OUT OUR MENU";
		cout<<"\n1.ADD CUSTOMER";
		cout<<"\n2.SEARCH CUSTOMER";
		cout<<"\n3.MODIFY CUSTOMER";
		cout<<"\n4.DELETE CUSTOMER";
		cout<<"\n5.PRINT DAILY REPORT";
		cout<<"\n6.EXIT";
		cout<<"\nEnter your choice :";
		cin>>chh;
		switch(chh)
		{
			case 1 : addfile();break;
			case 2 : h.search(name1);break;
			case 3 : modifyfile(nm);break;
			case 4 : deletefile(namee);break;
			case 5 : report();break;
			case 6 : exit(0);break;

		}
	 cout<<"\nDo you want to continue with the application (y/n):";
	 cin>>choice;
	 }while(choice=='y' || choice=='Y') ;
	 getch();
	 if (choice=='n' || choice=='N')
		cout<<"\n\n\n\t\t\n\t\tThe foundation of success in life is good health. ";
	 getch();
}
