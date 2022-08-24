#include<iostream>
#include <windows.h>
#include<string>
#include<conio.h>
#include<cmath>
#include<limits>
#include<fstream>
//#include<random>


using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define RETURN 13
#define ESC 27
#undef max //แก้เออเร่อ windows.h

int cti(const char);
int color(int);
float bugfix(float);
void gotoxy(int, int);

void band_4();
void band_5();
void findV();
void findI();
void findR();
void findP();
void save(float,float,float, string,char);
void onscreen(string);
void krubkrub();
void bear();

void program1();
void program2();
void program3();
void program4();
void program5();

const int px = 50;
const int py = 2;

////	อินเตอร์เฟสโปรแกรม
int main()
{

	int x = 47, y = 15;
	int code = 6;
	int Return = 0, select = 1;
	int exit = 0;
	char Switch;




	///////////////////////////////////ส่วนของการเลือก/////////////////////////////
	do {
		system("CLS");//เคลียหน้าจอเวลากลับมาจากโปรแกรม
		//krubkrub();
		bear();
		gotoxy(x, y);
		color(14);
		cout << "ELECTRONICS CALCULATE PROGRAM" << endl;
		color(7);

		if (select == 1)color(code);
		gotoxy(x+4, y + 1);
		cout << " Read Resistor color ";
		color(7);

		if (select == 2)color(code);
		gotoxy(x+4, y + 2);
		cout << " Voltage Calculating ";
		color(7);

		if (select == 3)color(code);
		gotoxy(x+3, y + 3);
		cout << " Resistance Calculating ";
		color(7);

		if (select == 4)color(code);
		gotoxy(x-1, y + 4);
		cout << " Current in circuit Calculating";
		color(7);

		if (select == 5)color(code);
		gotoxy(x+1, y + 5);
		cout << " Electric Power Calculating";
		color(7);

		if (select == 6)color(4);
		gotoxy(x+11, y + 6);
		cout << " EXIT";
		color(7);

		Switch = _getch();


		//เลือกเมนูขึ้นลง
		if (Switch != 0)
		{
			switch (Switch)
			{
			case KEY_UP:
				select -= 1;
				break;

			case KEY_DOWN:
				select += 1;
				break;
			}
		}
		////////////ตรวจสอบselect///////////
		if (select > 6)select = 1;
		if (select < 1)select = 6;

		//ตรวจสอบการกด enter///////////////ส่วนตัวเลือกโปรแกรม////////////////
		if (Switch == 13)
		{
			switch (select)
			{
			case 1:program1();
				break;

			case 2:program2();
				break;

			case 3:program3();
				break;

			case 4:program4();
				break;

			case 5:program5();
				break;

			case 6:exit = 1;
				break;
			}

		}


	} while (exit == 0);
	return 0;
	//system("pause>0");
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////ฟังก์ชั่นโปรแกรม///////////////////////////
///////////////////////////////////////////////////////////////////

//โปรแกรม 1
void program1() {
	system("CLS");
	int x = 60, y = 3;
	char num;
	gotoxy(25, 0);
	color(2);
	cout << "Read Resistor color" << endl;
	color(15);
	gotoxy(x, y);
	cout << "black  = 0" << endl;
	gotoxy(x, y + 1);
	cout << "brown  = 1" << endl;
	gotoxy(x, y + 2);
	cout << "red    = 2" << endl;
	gotoxy(x, y + 3);
	cout << "orange = 3" << endl;
	gotoxy(x, y + 4);
	cout << "yellow = 4" << endl;
	gotoxy(x, y + 5);
	cout << "green  = 5" << endl;
	gotoxy(x, y + 6);
	cout << "blue   = 6" << endl;
	gotoxy(x, y + 7);
	cout << "violet = 7" << endl;
	gotoxy(x, y + 8);
	cout << "grey   = 8" << endl;
	gotoxy(x, y + 9);
	cout << "white  = 9" << endl;
	gotoxy(x, y + 10);
	cout << "gold   = G" << endl;
	gotoxy(x, y + 11);
	cout << "silver = S" << endl;
	gotoxy(x, y + 12);
	cout << "None   = N" << endl;
	gotoxy(0, 3);

	char band;
	while (int ex = 0 != 1) {
		cout << "please enter your band of resistor (4-5) \n::>";
		//cin >> band;
		band = _getch();
		if (band == '4' || band == '5')break;
	}
	if (band == '4') band = '4';
	else if (band == '5') band = '5';

	switch (band) {
	case '4':cout << "resistor 4 band\n";
		band_4();
		break;
	case '5':cout << "resistor 5 band\n";
		band_5();
		break;
	default:cout << "error please try again." << endl;
		break;
	}


	system("pause>0");
}

void band_4() {
	const int size = 10;
	int color[size] = { 0,1,2,3,4,5,6,7,8,9 };
	char atol[3] = { 'G','S','N' };
	int check = 0;
	char Tol;
	unsigned int band4[4];
	int total = 0;
	int sum4 = 0;
	int a = 0;
	bool x = false;
	char tem;

	for (int cal = 1; cal <= 4; cal++) {
		cout << "Enter color " << cal << " : ";
		if (cal > 3) {
			//cin >> Tol;
			Tol = _getch();
			cout << Tol << endl;
			Tol = toupper(Tol);
			if (Tol != 'G')Tol = 'N';
			if (Tol != 'S')Tol = 'N';
			if (Tol != 'N')Tol = 'N';
			if (cal == 4) {
				if (Tol == atol[0]) { cout << "your color code = " << sum4 << " Ohm +- 5%"; }
				if (Tol == atol[1]) { cout << "your color code = " << sum4 << " Ohm +- 10%"; }
				if (Tol == atol[2]) { cout << "your color code = " << sum4 << " Ohm +- 20%"; }
				break;

			}
		}
		tem = _getch();
		check = cti(tem);
		cout << check << endl;


		for (int ar1 = 0; ar1 < size; ar1++) {
			if (check == color[ar1]) {
				if (a == 0) { band4[0] = color[ar1] * 10; }
				if (a == 1) { band4[1] = color[ar1]; }
				if (a == 2) {
					band4[2] = pow(10, color[ar1]);
					x = true;
				}
				a++;
				if (x == true) {
					sum4 = (band4[0] + band4[1]) * band4[2];
					&sum4;
				}
			}
		}

	}

}

void band_5() {
	const int size = 10;
	int color[size] = { 0,1,2,3,4,5,6,7,8,9 };
	char atol[3] = { 'G','S','N' };
	int check;
	char Tol;
	unsigned int band5[5];
	int total = 0;
	int sum5 = 0;
	int a = 0;
	bool x = false;

	char tem;


	for (int cal = 1; cal <= 5; cal++) {
		cout << "Enter color " << cal << " : ";
		if (cal > 4) {
			//cin >> Tol;
			Tol = _getch();
			cout << Tol << endl;
			Tol = toupper(Tol);
			if (Tol != 'G')Tol = 'N';
			if (Tol != 'S')Tol = 'N';
			if (Tol != 'N')Tol = 'N';

			if (cal == 5) {
				if (Tol == atol[0]) { cout << "your color code = " << sum5 << " Ohm +- 5%"; }
				if (Tol == atol[1]) { cout << "your color code = " << sum5 << " Ohm +- 10%"; }
				if (Tol == atol[2]) { cout << "your color code = " << sum5 << " Ohm +- 20%"; }
				break;

			}
		}
		//cin >> check;
		tem = _getch();
		check = cti(tem);
		cout << check << endl;


		for (int ar1 = 0; ar1 < size; ar1++) {
			if (check == color[ar1]) {
				if (a == 0) { band5[0] = color[ar1] * 100; }
				if (a == 1) { band5[1] = color[ar1] * 10; }
				if (a == 2) { band5[2] = color[ar1]; }
				if (a == 3) {
					band5[3] = pow(10, color[ar1]);
					x = true;
				}
				a++;
				if (x == true) {
					sum5 = (band5[0] + band5[1] + band5[2]) * band5[3];
					//sum4 = band4[2];
					&sum5;
				}
			}
		}

	}

}



//โปรแกรม 2
void program2() {
	system("CLS");
	color(11);
	gotoxy(47, 1);
	cout << "* Voltage Calculating *" << endl;
	color(7);
	findV();
	system("pause>0");
}

void findV() {
	float r, i, v;
	cout << "Enter i (Current in circuit) : ";
	cin >> i;
	i = bugfix(i);
	cout << "Enter r (resistance) : ";
	cin >> r;
	r = bugfix(r);
	v = i * r;
	save(i, r, v, "dataV.txt", 'v');
	system("CLS");
	gotoxy(47,1);
	color(11);
	cout << "* Voltage Calculating *"<<endl;
	color(7);
	gotoxy(49, 3);
	cout << "current    : " << i<<" Amperes"<<endl;
	gotoxy(49, 4);
	cout << "resistance : " << r <<" Ohms"<< endl;
	gotoxy(49, 5);
	cout << "Your output = " << v << " Volts";
	gotoxy(47,9);
	color(9);
	cout << "RECENT CALCULATING";
	color(7);
	gotoxy(27,11);
	onscreen("dataV.txt");

}





//โปรแกรม 3
void program3() {
	system("CLS");
	color(5);
	gotoxy(47, 1);
	cout << "* Resistance Calculating *" << endl;
	color(7);
	findR();
	system("pause>0");

}
void findR()
{
	float v, i, r;
	cout << "Enter v (voltage) : ";
	cin >> v;
	v = bugfix(v);
	cout << "Enter i (Current in circuit) : ";
	cin >> i;
	i = bugfix(i);
	r = v / i;
	save(v, i, r, "dataR.txt", 'r');

	system("CLS");
	gotoxy(47, 1);
	color(11);
	cout << "* Voltage Calculating *" << endl;
	color(7);

	gotoxy(49,3);
	cout << "voltage : " << v << " volts";
	gotoxy(49, 4);
	cout << "current : " << i << " Amperes";
	gotoxy(47, 5);
	cout << "Your resistance = " << r << " Ohms";

	gotoxy(49, 9);
	color(5);
	cout << "RECENT CALCULATING";
	color(7);
	gotoxy(27, 11);
	onscreen("dataR.txt");
}

//โปรแกรม 4
void program4() {
	system("CLS");
	color(2);
	gotoxy(43, 1);
	cout << "* Current in circuit Calculating *"<<endl;
	color(7);
	color(7);
	findI();
	system("pause>0");
}
void findI()
{
	float v, i, r;
	cout << "Enter v (voltage) : ";
	cin >> v;
	v = bugfix(v);
	cout << "Enter r (resistance) : ";
	cin >> r;
	r = bugfix(r);
	i = v / r;
	save(v, r, i, "dataI.txt", 'i');

	system("CLS");
	gotoxy(43, 1);
	color(11);
	cout << "* Current in circuit Calculating *" << endl;
	color(7);

	gotoxy(47, 3);
	cout << "voltage    : " << v << " volts";
	gotoxy(47, 4);
	cout << "resistance : " << i << " Ohms";
	gotoxy(47, 5);
	cout << "Your current = " << r << " Amperes";

	gotoxy(49, 9);
	color(5);
	cout << "RECENT CALCULATING";
	color(7);
	gotoxy(28, 11);
	onscreen("dataI.txt");
}



//โปรแกรม 5
void program5() {
	system("CLS");
	color(6);
	gotoxy(45, 1);
	cout << "* Electric Power Calculating *"<<endl;
	color(7);
	findP();
	system("pause>0");
}
void findP()
{
	float p, e, i;
	cout << "Enter V (voltage) : ";
	cin >> e;
	e = bugfix(e);
	cout << "Enter I (ampere ) : ";
	cin >> i;
	i = bugfix(i);
	
	p = e * i;
	save(e, i, p, "dataP.txt", 'p');
	
	system("CLS");
	
	gotoxy(45, 1);
	color(10);
	cout << "* Electric Power Calculating *" << endl;
	color(7);

	gotoxy(47, 3);
	cout << "voltage    : " << e << " volts";
	gotoxy(47, 4);
	cout << "resistance : " << i << " Ohms";
	gotoxy(47, 5);
	cout << "Your electric power = " << p << " Watts";

	gotoxy(49, 9);
	color(5);
	cout << "RECENT CALCULATING";
	color(7);
	gotoxy(28, 11);
	onscreen("dataP.txt");

}



/////////////////////////////////////////////////////////////////////
///////////////////////ฟังกชั่นที่ใช้เสริมในโปรแกรมนี้////////////////////////
///////////////////////////////////////////////////////////////////


//ฟังก์ชั่นกำหนดจุดแสดงผล
void gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//ฟังก์ชั่นกำหนดสี
int color(int x) {
	HANDLE  Color;
	Color = GetStdHandle(STD_OUTPUT_HANDLE);
	x = SetConsoleTextAttribute(Color, x);
	return x;
}

int cti(const char c)
{
	switch (c)
	{
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	default:
		return 0;
	}
}

float bugfix(float a) {
	

	while (1)
	{
		
		if (cin.fail())
		{
			
			cin.clear();

			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			color(4);
			cout<< "Please Enter Number Again : ";
			color(7);
			cin >> a;
	
		
		}
		if (!cin.fail())
			break;
	}
	return a;
}

//รับผลการคำนวณ
void save(float x1, float x2, float tx, string name, char x)//ใส่ save(ค่าแรก , ค่าสอง , คำตอบ , "ชื่อไฟล์.txt",'v')
{
	string namex = name;
	ofstream data;
	data.open(namex);
	if (x == 'v')data <<"Current "<< x1 << " Ampere and Resistance " << x2 << " Ohms have Voltage " << tx <<" Volts"<< endl;
	if (x == 'i')data <<"Voltage "<< x1 << " Volts and Resistance " << x2 << " Ohms have Current" << tx << " Amperes" << endl;
	if (x == 'r')data << "Voltage " << x1 <<" Volts and Current "<< x2 << " Ampere have Resistance " << tx << " Ohms" << endl;
	if (x == 'p')data <<"Voltage "<< x1 << " Volts and Current " << x2 << " Ampere have Electric Power " << tx << " Watts" << endl;
	data.close();

}

//โชวผลการคำนวณล่าสุด
void onscreen(string file)//ใส่ "ชื่อ.txt" นะตัวเอง
{
	ifstream show;
	show.open(file);

	string showOut;
	getline(show, showOut);
	cout << showOut << endl;
	show.close();
	show.clear();


}

void bear()
{
	int x = 28;
	int y = 0;
	ifstream infile;
	infile.open("frame.txt");
	string s;
	while (getline(infile, s))
	{
		gotoxy(x,y);
		color(11);
		cout << s << endl;
		y++;
		
	}
	infile.close();
	infile.clear();
}