#include <iostream>
#include <vector>
#include <stdlib.h>
#include <conio.h>
#include <string>

// each child class will have a purchase function
// each child class to have a display function
// vectors to be declared globally(ease of use)
// use vec.erase for delete func
// checkers(qty, char, string) if time remains

using namespace std;

// Filing
void RFF()
{	//	Read From File
	// strtok function to put data in buffer
}

void WTF()
{	//	Write To File
	// create a csv file;
}

// CLASSES//

// Parent class
class Items
{
protected:
	int ID;
	string Name;
	int Qty;
	double Price;

public:
	Items(int a, string b, int c, double d) : ID(a), Name(b), Qty(c), Price(d)
	{
	}
	Items()
	{
	}
	// Setters
	void setID(int id)
	{
		this->ID = id;
	}
	void setName(string name)
	{
		this->Name = name;
	}
	void setQty(int qty)
	{
		this->Qty = qty;
	}
	void setPrice(double price)
	{
		this->Price = price;
	}

	// Getters
	int getID()
	{
		return ID;
	}
	string getName()
	{
		return Name;
	}
	int getQty()
	{
		return Qty;
	}
	double getPrice()
	{
		return Price;
	}
};

// Child classes

class CPU : protected Items
{
	string generation; // default constructor to set some values
	double boost_clock;
	double base_clock;
	friend int searchCPU(int);
	friend void purchaseCPU();
public:
	CPU()
	{
	}

	CPU(string g, double base, double boost, int id, string name, int qty, double price) : Items(id, name, qty, price)
	{
		this->generation = g;
		this->boost_clock = boost;
		this->base_clock = base;
	}
	void setgeneration(string gen)
	{
		generation = gen;
	}
	void setboost(float boost)
	{
		boost_clock = boost;
	}
	void setbase(float base)
	{
		base_clock = base;
	}

	string getgen()
	{
		return generation;
	}
	double getboost()
	{
		return boost_clock;
	}
	double getbase()
	{
		return base_clock;
	}

	void display()
	{
		cout << "|" << ID << "|" << Name << "|" << Qty << "|" << Price << "|" << generation << "|" << boost_clock << "|" << base_clock << "|" << endl;
	}
};

class Motherboard : protected Items
{
	string size; // default constructor to set some values
	string generation;
	friend int searchMotherboard(int);
	friend void purchaseMobo();
public:
	Motherboard()
	{
	}
	Motherboard(string size, string generation, int id, string name, int qty, double price) : Items(id, name, qty, price)
	{
		this->size = size;
		this->generation = generation;
	}
	void set_size(string Size)
	{
		size = Size;
	}
	void set_gen(string gen)
	{
		generation = gen;
	}

	string getsize()
	{
		return size;
	}
	string getgen()
	{
		return generation;
	}

	void display()
	{
		cout << "|" << ID << "|" << Name << "|" << Qty << "|" << Price << "|" << size << "|" << generation << "|" << endl;
	}
};

class RAM : protected Items
{
	int capacity; // default constructor to set some values
	string CASlatency;
	friend int searchRAM(int);
	friend void purchaseRAM();
public:
	RAM()
	{
	}

	RAM(int capacity, string caslatency, int id, string name, int qty, double price) : Items(id, name, qty, price)
	{
		this->capacity = capacity;
		this->CASlatency = caslatency;
	}
	void setCAP(int cap)
	{
		capacity = cap;
	}
	void setLatency(string latency)
	{
		CASlatency = latency;
	}

	int getCapacity()
	{
		return capacity;
	}
	string getLatency()
	{
		return CASlatency;
	}

	void display()
	{
		cout << "|" << ID << "|" << Name << "|" << Qty << "|" << Price << "|" << capacity << "|" << CASlatency << "|" << endl;
	}
};

class GPU : protected Items
{
	int VRAM; // default constructor to set some values
	int power;
	friend int searchGPU(int);
	friend void purchaseGPU();
public:
	GPU()
	{
	}

	GPU(int vram, int power, int id, string name, int qty, double price) : Items(id, name, qty, price)
	{
		this->VRAM = vram;
		this->power = power;
	}
	void setVRAM(int vram)
	{
		VRAM = vram;
	}
	void setpower(int tdp)
	{
		power = tdp;
	}

	int getVRAM()
	{
		return VRAM;
	}
	int getpower()
	{
		return power;
	}

	void display()
	{
		cout << "|" << ID << "|" << Name << "|" << Qty << "|" << Price << "|" << VRAM << "|" << power << "|" << endl;
	}
};

class PSU : protected Items
{
	string Rating; // default constructor to set some values
	int wattage;
	friend int searchPSU(int);
	friend void purchasePSU();
public:
	PSU(string rating, int wattage, int id, string name, int qty, double price) : Items(id, name, qty, price)
	{
		this->Rating = rating;
		this->wattage = wattage;
	}

	void setRating(string rate)
	{
		Rating = rate;
	}
	void setWatt(int watt)
	{
		wattage = watt;
	}

	int getWatt()
	{
		return wattage;
	}
	string getRating()
	{
		return Rating;
	}
	void display()
	{
		cout << "|" << ID << "|" << Name << "|" << Qty << "|" << Price << "|" << wattage << "|" << Rating << "|" << endl;
	}
};

class CASE : protected Items
{
	string Size; // default constructor to set some values //ATX, Micro-ATX and Mini-ITX
	friend int searchCASE(int);
	friend void purchaseCASE();
public:
	CASE()
	{
	}
	CASE(string size, int id, string name, int qty, double price) : Items(id, name, qty, price)
	{
		this->Size = size;
	}
	void setSize(string size)
	{
		Size = size;
	}

	string getSize()
	{
		return Size;
	}

	void display()
	{
		cout << "|" << ID << "|" << Name << "|" << Qty << "|" << Price << "|" << Size << "|" << endl;
	}
};

vector<CPU> cpu;
vector<GPU> gpu;
vector<CASE> cas;
vector<Motherboard> mobo;
vector<PSU> psu;
vector<RAM> ram;

//Search Functions
int searchCPU(int id){
	int s=cpu.size();
	
	for (int i=0; i<=s; i++){
		if(id == cpu[i].ID)
			return i;
		else
			return 0;
	}
	return 0;
}
int searchMotherboard(int id){
	int s=mobo.size();
	
	for (int i=0; i<=s; i++){
		if(id == mobo[i].ID)
			return i;
		else
			return 0;
	}
	return 0;
}
int searchGPU(int id){
	int s=gpu.size();
	
	for (int i=0; i<=s; i++){
		if(id == gpu[i].ID)
			return i;
		else
			return 0;
	}
	return 0;
}
int searchPSU(int id){
	int s=psu.size();
	
	for (int i=0; i<=s; i++){
		if(id == psu[i].ID)
			return i;
		else
			return 0;
	}
	return 0;
}
int searchRAM(int id){
	int s=ram.size();
	
	for (int i=0; i<=s; i++){
		if(id == ram[i].ID)
			return i;
		else
			return 0;
	}
	return 0;
}

int searchCASE(int id){
	int s=cas.size();
	
	for (int i=0; i<=s; i++){
		if(id == cas[i].ID)
			return i;
		else
			return 0;
	}
	return 0;
}

void addCPU()
{
int id, qty;
string name, gen;
double price, boost,base; 
int check=0;
a:	
system("cls");
cout << "Enter CPU ID" << endl;
cin >> id;
if (id>9999 && id<1000){
goto a;
}
check = searchCPU(id);
if(check == 0){
cout<<"ID not found."<<endl;
}

else{
cout<<"id already exists";
getche();
goto a;
}
cout << "Enter CPU Name" << endl;
cin >> name;
cout << "Enter CPU Qty" << endl;
cin >> qty;
cout << "Enter CPU Price" << endl;
cin >> price;
cout << "Enter CPU generation" << endl;
cin >> gen;
cout << "Enter CPU Boost_clock" << endl;
cin >> boost;
cout << "Enter CPU Base_clock" << endl;
cin >> base;


CPU tempCPU(gen,base,boost,id,name,qty,price);
cpu.push_back(tempCPU);
//set

}
void addMotherboard()
{
int id,qty,check=0;
string name,gen,size;
double price;
b:	
system("cls");

//variables
cout << "Enter Motherboard ID" << endl;
cin >> id;
if (id>9999 && id<1000){
goto b;
}
check = searchMotherboard(id);
if(check == 0){
cout<<"ID not found."<<endl;
}
else{
cout<<"id already exists";
getche();
goto b;
}
cout << "Enter Motherboard Name" << endl;
cin >> name;
cout << "Enter Motherboard Qty" << endl;
cin >> qty;
cout << "Enter Motherboard Price" << endl;
cin >> price;
cout << "Enter Motherboard Size" << endl;
cin >> size;
cout << "Enter Motherboard Generation" << endl;
cin >> gen;
//set

Motherboard tempmobo(size,gen,id,name,qty,price);
mobo.push_back(tempmobo);

}
void addRAM()
{
//variables
int id,qty,cap,check=0;
string name,latency;
double price;

c:	
system("cls");

//variables
cout << "Enter Motherboard ID" << endl;
cin >> id;
if (id>9999 && id<1000){
goto c;
}
check = searchMotherboard(id);
if(check == 0){
cout<<"ID not found."<<endl;
}
else{
cout<<"id already exists";
getche();
goto c;
}
cout << "Enter RAM Name" << endl;
cin >> name;
cout << "Enter RAM Qty" << endl;
cin >> qty;
cout << "Enter RAM Price" << endl;
cin >> price;
cout << "Enter RAM Capacity" << endl;
cin >> cap;
cout << "Enter RAM CAS Latency" << endl;
cin >> latency;


//set
RAM tempram(cap,latency,id,name,qty,price);
ram.push_back(tempram);
}
void addGPU()
{
//variables
int id,qty,vram,power,check=0;
string name;
double price;


//increase vector count

d:	
system("cls");

//variables
cout << "Enter Motherboard ID" << endl;
cin >> id;
if (id>9999 && id<1000){
goto d;
}
check = searchMotherboard(id);
if(check == 0){
cout<<"ID not found."<<endl;
}
else{
cout<<"id already exists";
getche();
goto d;
}
cout << "Enter GPU Name" << endl;
cin >> name;
cout << "Enter GPU Qty" << endl;
cin >> qty;
cout << "Enter GPU Price" << endl;
cin >> price;
cout << "Enter GPU VRAM" << endl;
cin >> vram;
cout << "Enter GPU Power_Draw" << endl;
cin >> power;

//set
GPU tempgpu(vram,power,id,name,qty,price);
gpu.push_back(tempgpu);
}
void addPSU()
{
//variables
int id,qty,watt,check=0;
string name,rate;
double price;

//increase vector count


e:	
system("cls");

//variables
cout << "Enter Motherboard ID" << endl;
cin >> id;
if (id>9999 && id<1000){
goto e;
}
check = searchMotherboard(id);
if(check == 0){
cout<<"ID not found."<<endl;
}
else{
cout<<"id already exists";
getche();
goto e;
}
cout << "Enter PSU Name" << endl;
cin >> name;
cout << "Enter PSU Qty" << endl;
cin >> qty;
cout << "Enter PSU Price" << endl;
cin >> price;
cout << "Enter PSU Wattage" << endl;
cin >> watt;
cout << "Enter PSU Rating" << endl;
cin >> rate;


//set
PSU temppsu(rate,watt,id,name,qty,price);
psu.push_back(temppsu);

}
void addCASE()
{
//variables
int id,qty,check=0;
string name,size;
double price;
//increase vector count

f:	
system("cls");

//variables
cout << "Enter Motherboard ID" << endl;
cin >> id;
if (id>9999 && id<1000){
goto f;
}
check = searchMotherboard(id);
if(check == 0){
cout<<"ID not found."<<endl;
}
else{
cout<<"id already exists";
getche();
goto f;
}
cout << "Enter CASE Name" << endl;
cin >> name;
cout << "Enter CASE Qty" << endl;
cin >> qty;
cout << "Enter CASE Price" << endl;
cin >> price;
cout << "Enter CASE Size" << endl;
cin >> size;

//set
CASE tempcase(size,id,name,qty,price);
cas.push_back(tempcase);
}

//edit functions

void editCPU(){
	int id,qty,check=0;
	string name,gen;
	double price,boost,base;
g:	
	system("cls");
	//variables
	cout << "Enter Motherboard ID" << endl;
	cin >> id;
	if (id>9999 && id<1000){
		goto g;
	}
	check = searchMotherboard(id);
	if(check == 0){
		cout<<"ID not found."<<endl;
	}
	else{
		cout<<"id already exists";
		getche();
		goto g;
	}
	
	cout << "Enter CPU ID" << endl;
	cin >> id;
	cout << "Enter CPU Name" << endl;
	cin >> name;
	cout << "Enter CPU Qty" << endl;
	cin >> qty;
	cout << "Enter CPU Price" << endl;
	cin >> price;
	cout << "Enter CPU generation" << endl;
	cin >> gen;
	cout << "Enter CPU Boost_clock" << endl;
	cin >> boost;
	cout << "Enter CPU Base_clock" << endl;
	cin >> base;
	
	
	CPU tempCPU(gen,base,boost,id,name,qty,price);
	cpu.push_back(tempCPU);
}

void editMotherboard(){
	int id,qty,check=0;
	string name,size,gen;
	double price;
	
h:	
	system("cls");
	
	//variables
	cout << "Enter Motherboard ID" << endl;
	cin >> id;
	if (id>9999 && id<1000){
		goto h;
	}
	check = searchMotherboard(id);
	if(check == 0){
		cout<<"ID not found."<<endl;
	}
	else{
		cout<<"id already exists";
		getche();
		goto h;
	}
	cout << "Enter Motherboard Name" << endl;
	cin >> name;
	cout << "Enter Motherboard Qty" << endl;
	cin >> qty;
	cout << "Enter Motherboard Price" << endl;
	cin >> price;
	cout << "Enter Motherboard Size" << endl;
	cin >> size;
	cout << "Enter Motherboard Generation" << endl;
	cin >> gen;
	
	Motherboard tempmobo(size,gen,id,name,qty,price);
	mobo.push_back(tempmobo);
}

void editGPU(){
	int id,qty,vram,power,check=0;
	string name;
	double price;
	
	
i:	
	system("cls");
	
	//variables
	cout << "Enter Motherboard ID" << endl;
	cin >> id;
	if (id>9999 && id<1000){
		goto i;
	}
	check = searchMotherboard(id);
	if(check == 0){
		cout<<"ID not found."<<endl;
	}
	else{
		cout<<"id already exists";
		getche();
		goto i;
	}
	cout << "Enter GPU Name" << endl;
	cin >> name;
	cout << "Enter GPU Qty" << endl;
	cin >> qty;
	cout << "Enter GPU Price" << endl;
	cin >> price;
	cout << "Enter GPU VRAM" << endl;
	cin >> vram;
	cout << "Enter GPU Power_Draw" << endl;
	cin >> power;
	
	
	GPU tempgpu(vram,power,id,name,qty,price);
	gpu.push_back(tempgpu);

}
void editRam(){
	int id,qty,cap,check=0;
	string name,latency;
	double price;
	
	
j:	
	system("cls");
	
	//variables
	cout << "Enter Motherboard ID" << endl;
	cin >> id;
	if (id>9999 && id<1000){
		goto j;
	}
	check = searchMotherboard(id);
	if(check == 0){
		cout<<"ID not found."<<endl;
	}
	else{
		cout<<"id already exists";
		getche();
		goto j;
	}
	cout << "Enter RAM Name" << endl;
	cin >> name;
	cout << "Enter RAM Qty" << endl;
	cin >> qty;
	cout << "Enter RAM Price" << endl;
	cin >> price;
	cout << "Enter RAM Capacity" << endl;
	cin >> cap;
	cout << "Enter RAM CAS Latency" << endl;
	cin >> latency;
	
	RAM tempram(cap,latency,id,name,qty,price);
	ram.push_back(tempram);
	
}
void editPSU(){
	int id,qty,watt,check=0;
	string name,rate;
	double price;
	

k:	
	system("cls");
	
	//variables
	cout << "Enter Motherboard ID" << endl;
	cin >> id;
	if (id>9999 && id<1000){
		goto k;
	}
	check = searchMotherboard(id);
	if(check == 0){
		cout<<"ID not found."<<endl;
	}
	else{
		cout<<"id already exists";
		getche();
		goto k;
	}
	cout << "Enter PSU Name" << endl;
	cin >> name;
	cout << "Enter PSU Qty" << endl;
	cin >> qty;
	cout << "Enter PSU Price" << endl;
	cin >> price;
	cout << "Enter PSU Wattage" << endl;
	cin >> watt;
	cout << "Enter PSU Rating" << endl;
	cin >> rate;
	
	PSU temppsu(rate,watt,id,name,qty,price);
	psu.push_back(temppsu);
	
}

void editCase(){
	int id,qty,check=0;
	string name,size;
	double price;
	

l:	
	system("cls");
	
	//variables
	cout << "Enter Motherboard ID" << endl;
	cin >> id;
	if (id>9999 && id<1000){
		goto l;
	}
	check = searchMotherboard(id);
	if(check == 0){
		cout<<"ID not found."<<endl;
	}
	else{
		cout<<"id already exists";
		getche();
		goto l;
	}
	cout << "Enter CASE Name" << endl;
	cin >> name;
	cout << "Enter CASE Qty" << endl;
	cin >> qty;
	cout << "Enter CASE Price" << endl;
	cin >> price;
	cout << "Enter CASE Size" << endl;
	cin >> size;
	
	
	CASE tempcase(size,id,name,qty,price);
	cas.push_back(tempcase);
	
}

void editItem()
{
// case statement to determine which one(psu,gpu,cpu) we are adding to
// edit price
strt:
	int ch=0;
	do{
		system("CLS");
		cout << "**************************************************************************************************************\n";
		cout << "                                       S.T.A.R  C.O.M.P.U.T.E.R.S                                             \n";
		cout << "**************************************************************************************************************\n\n";
		cout << "\t\t1)Edit CPU\n\t\t2)Edit GPU\n\t\t3)Edit RAM\n\t\t4)Edit Motherboard\n\t\t5)Edit PSU\n\t\t6)Edit CASE\n\t\t7)Back To Main Menu\n\n\t\tChoose: ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			editCPU();
			break;
		case 2:
			editGPU();
			break;
		case 3:
			editRam();
			break;
		case 4:
			editMotherboard();
			break;
		case 5:
			editPSU();
			break;
		case 6:
			editCase();
			break;
		case 7:
			break;
		default:
			cout<<"!!! INCORRECT CHOICE !!!";
			break;
		}
	}while(ch!=7);
}

void addItem()
{
	int id, qty;
	double price;
	string name;

	int ch = 0;
	system("CLS");
	cout << "**************************************************************************************************************\n";
	cout << "                                       S.T.A.R  C.O.M.P.U.T.E.R.S                                             \n";
	cout << "**************************************************************************************************************\n\n";
	cout << "\t\t1) Add CPU\n\t\t2)Add GPU\n\t\t3) Add RAM\n\t\t4) Add Motherboard\n\t\t5) Add PSU\n\t\t6)Add CASE\n\t\t7)Main Menu\n\n\t\tChoose: ";
	cin >> ch;
	do
	{
		switch (ch)
		{
		case 1:
			addCPU();
			break;
		case 2:
			// addGPU();
			break;
		case 3:
			// addRAM();
			break;
		case 4:
			// addMotheboard();
			break;
		case 5:
			// addPSU();
			break;
		case 6:
			// addCASE();
			break;
		case 7:
			break;
		default:
			cout << "\n\n!!!Incorrect choice!!!";
			break;
		}
	} while (ch != 7);

	// ask if they want to add more
}

void deleteItem()
{
	// case statement to determine which one(psu,gpu,cpu) we are deleting from
	// use algorithm for deletion.
}


void displayCPU(){
	int s = cpu.size();
	if (s==0){
		cout<<"No Products Of This Category Are In Stock!!\n\nCheck Back At a Later Date";
	}
	else{
		for (int i=0 ; i <= s ; i++){
			cpu[i].display();
			cout<<endl;
			getche();
		}
	}
}

void displayGPU(){
	int s = gpu.size();
	if (s==0){
		cout<<"No Products Of This Category Are In Stock!!\n\nCheck Back At a Later Date";
	}
	else{
		for (int i=0 ; i <= s ; i++){
			gpu[i].display();
			cout<<endl;
			getche();
		}
	}
}
void displayRAM(){
	int s = ram.size();
	if (s==0){
		cout<<"No Products Of This Category Are In Stock!!\n\nCheck Back At a Later Date";
	}
	else{
		for (int i=0 ; i <= s ; i++){
			ram[i].display();
			cout<<endl;
			getche();
		}
	}
}
void displayPSU(){
	int s = psu.size();
	if (s==0){
		cout<<"No Products Of This Category Are In Stock!!\n\nCheck Back At a Later Date";
	}
	else{
		for (int i=0 ; i <= s ; i++){
			psu[i].display();
			cout<<endl;
			getche();
		}
	}
}
void displayMotherboard(){
	int s = mobo.size();
	if (s==0){
		cout<<"No Products Of This Category Are In Stock!!\n\nCheck Back At a Later Date";
	}
	else{
		for (int i=0 ; i <= s ; i++){
			mobo[i].display();
			cout<<endl;
			getche();
		}
	}
}
void displayCASE(){
	int s = cas.size();
	if (s==0){
		cout<<"No Products Of This Category Are In Stock!!\n\nCheck Back At a Later Date";
	}
	else{
		for (int i=0 ; i <= s ; i++){
			cas[i].display();
			cout<<endl;
			getche();
		}
	}
	
}

void purchaseCPU()
{
	int id, check, qty, quantity;
	double price, tprice;
	char x;
z:
	displayCPU();
	cout<<"\n\n\nEnter ID of the product you want to buy from the above list || Or enter -1 to return to Previous Menu";
	if(id == -1)
	check = searchCPU(id);
	if(check != 0){
		system("cls");
		price = cpu[id].getPrice();
		qty = cpu[id].getQty();
			if (qty==0)
			{
				cout<<"Product is not in stock!!!";
				getche();
				goto z;
			}
			cout<<"Quantity available is: "<<qty;
			cout<<"How many do you want: ";
			cin>>quantity;
			while(qty<quantity){
				cout<<"\nQuantity available is: "<<qty;
				cout<<"How many do you want: ";
				cin>>quantity;
			}	
			cout<<"Price of 1 = "<< price<<endl;
			tprice = price*quantity;
			cout<<"Total Price = "<<tprice<<endl;
			while(x != 'y' || x != 'Y'){
				cout<<"Proceed to Purchase(Y/N): ";
				x = getche();
				switch (x)
				{
					case 'y':
					case 'Y':
						qty -= quantity;
						cpu[id].setQty(qty);
						break;
					case 'N':
					case 'n':
						goto z;
						break;
					default:
						cout<<"Incorrect letter pressed";
						break;
				}
			}
	}
	else{
		cout<<"Incorrect ID entered\nPlz enter correct ID from the list above!!";
	}
}
void purchaseGPU()
{
	int id, check, qty, quantity;
	double price, tprice;
	char x;
z:
	displayGPU();
	cout<<"\n\n\nEnter ID of the product you want to buy from the above list || Or enter -1 to return to Previous Menu";
	if(id == -1)
	check = searchGPU(id);
	if(check != 0){
		system("cls");
		price = gpu[id].getPrice();
		qty = gpu[id].getQty();
			if (qty==0)
			{
				cout<<"Product is not in stock!!!";
				getche();
				goto z;
			}
			cout<<"Quantity available is: "<<qty;
			cout<<"How many do you want: ";
			cin>>quantity;
			while(qty<quantity){
				cout<<"\nQuantity available is: "<<qty;
				cout<<"How many do you want: ";
				cin>>quantity;
			}	
			cout<<"Price of 1 = "<< price<<endl;
			tprice = price*quantity;
			cout<<"Total Price = "<<tprice<<endl;
			while(x != 'y' || x != 'Y'){
				cout<<"Proceed to Purchase(Y/N): ";
				x = getche();
				switch (x)
				{
					case 'y':
					case 'Y':
						qty -= quantity;
						gpu[id].setQty(qty);
						break;
					case 'N':
					case 'n':
						goto z;
						break;
					default:
						cout<<"Incorrect letter pressed";
						break;
				}
			}
	}
	else{
		cout<<"Incorrect ID entered\nPlz enter correct ID from the list above!!";
	}	
}
void purchaseRAM()
{
	int id, check, qty, quantity;
	double price, tprice;
	char x;
z:
	displayRAM();
	cout<<"\n\n\nEnter ID of the product you want to buy from the above list || Or enter -1 to return to Previous Menu";
	if(id == -1)
	check = searchRAM(id);
	if(check != 0){
		system("cls");
		price = ram[id].getPrice();
		qty = ram[id].getQty();
			if (qty==0)
			{
				cout<<"Product is not in stock!!!";
				getche();
				goto z;
			}
			cout<<"Quantity available is: "<<qty;
			cout<<"How many do you want: ";
			cin>>quantity;
			while(qty<quantity){
				cout<<"\nQuantity available is: "<<qty;
				cout<<"How many do you want: ";
				cin>>quantity;
			}	
			cout<<"Price of 1 = "<< price<<endl;
			tprice = price*quantity;
			cout<<"Total Price = "<<tprice<<endl;
			while(x != 'y' || x != 'Y'){
				cout<<"Proceed to Purchase(Y/N): ";
				x = getche();
				switch (x)
				{
					case 'y':
					case 'Y':
						qty -= quantity;
						ram[id].setQty(qty);
						break;
					case 'N':
					case 'n':
						goto z;
						break;
					default:
						cout<<"Incorrect letter pressed";
						break;
				}
			}
	}
	else{
		cout<<"Incorrect ID entered\nPlz enter correct ID from the list above!!";
	}	
}
void purchasePSU()
{
	int id, check, qty, quantity;
	double price, tprice;
	char x;
z:
	displayPSU();
	cout<<"\n\n\nEnter ID of the product you want to buy from the above list || Or enter -1 to return to Previous Menu";
	if(id == -1)
	check = searchPSU(id);
	if(check != 0){
		system("cls");
		price = psu[id].getPrice();
		qty = psu[id].getQty();
			if (qty==0)
			{
				cout<<"Product is not in stock!!!";
				getche();
				goto z;
			}
			cout<<"Quantity available is: "<<qty;
			cout<<"How many do you want: ";
			cin>>quantity;
			while(qty<quantity){
				cout<<"\nQuantity available is: "<<qty;
				cout<<"How many do you want: ";
				cin>>quantity;
			}	
			cout<<"Price of 1 = "<< price<<endl;
			tprice = price*quantity;
			cout<<"Total Price = "<<tprice<<endl;
			while(x != 'y' || x != 'Y'){
				cout<<"Proceed to Purchase(Y/N): ";
				x = getche();
				switch (x)
				{
					case 'y':
					case 'Y':
						qty -= quantity;
						psu[id].setQty(qty);
						break;
					case 'N':
					case 'n':
						goto z;
						break;
					default:
						cout<<"Incorrect letter pressed";
						break;
				}
			}
	}
	else{
		cout<<"Incorrect ID entered\nPlz enter correct ID from the list above!!";
	}
}
void purchaseMobo()
{
	int id, check, qty, quantity;
	double price, tprice;
	char x;
z:
	displayMotherboard();
	cout<<"\n\n\nEnter ID of the product you want to buy from the above list || Or enter -1 to return to Previous Menu";
	if(id == -1)
	check = searchMotherboard(id);
	if(check != 0){
		system("cls");
		price = mobo[id].getPrice();
		qty = mobo[id].getQty();
			if (qty==0)
			{
				cout<<"Product is not in stock!!!";
				getche();
				goto z;
			}
			cout<<"Quantity available is: "<<qty;
			cout<<"How many do you want: ";
			cin>>quantity;
			while(qty<quantity){
				cout<<"\nQuantity available is: "<<qty;
				cout<<"How many do you want: ";
				cin>>quantity;
			}	
			cout<<"Price of 1 = "<< price<<endl;
			tprice = price*quantity;
			cout<<"Total Price = "<<tprice<<endl;
			while(x != 'y' || x != 'Y'){
				cout<<"Proceed to Purchase(Y/N): ";
				x = getche();
				switch (x)
				{
					case 'y':
					case 'Y':
						qty -= quantity;
						mobo[id].setQty(qty);
						break;
					case 'N':
					case 'n':
						goto z;
						break;
					default:
						cout<<"Incorrect letter pressed";
						break;
				}
			}
	}
	else{
		cout<<"Incorrect ID entered\nPlz enter correct ID from the list above!!";
	}
}
void purchaseCASE()
{
	int id, check, qty, quantity;
	double price, tprice;
	char x;
z:
	displayCASE();
	cout<<"\n\n\nEnter ID of the product you want to buy from the above list || Or enter -1 to return to Previous Menu";
	if(id == -1)
	check = searchCASE(id);
	if(check != 0){
		system("cls");
		price = cas[id].getPrice();
		qty = cas[id].getQty();
			if (qty==0)
			{
				cout<<"Product is not in stock!!!";
				getche();
				goto z;
			}
			cout<<"Quantity available is: "<<qty;
			cout<<"How many do you want: ";
			cin>>quantity;
			while(qty<quantity){
				cout<<"\nQuantity available is: "<<qty;
				cout<<"How many do you want: ";
				cin>>quantity;
			}	
			cout<<"Price of 1 = "<< price<<endl;
			tprice = price*quantity;
			cout<<"Total Price = "<<tprice<<endl;
			while(x != 'y' || x != 'Y'){
				cout<<"Proceed to Purchase(Y/N): ";
				x = getche();
				switch (x)
				{
					case 'y':
					case 'Y':
						qty -= quantity;
						cas[id].setQty(qty);
						break;
					case 'N':
					case 'n':
						goto z;
						break;
					default:
						cout<<"Incorrect letter pressed";
						break;
				}
			}
	}
	else{
		cout<<"Incorrect ID entered\nPlz enter correct ID from the list above!!";
	}	
}

void CustomerMenu()
{
	int choice = 0;
	int ch;
	system("CLS");
	cout << "**************************************************************************************************************\n";
	cout << "                                       S.T.A.R  C.O.M.P.U.T.E.R.S                                             \n";
	cout << "**************************************************************************************************************\n\n";
	cout << "\t\t1) Display Items\n\t\t2)Purchase\n\t\t3) EXIT!\n\n\t\tChoice: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		ch = 0;
		do
		{
			system("CLS");
			cout << "**************************************************************************************************************\n";
			cout << "                                       S.T.A.R  C.O.M.P.U.T.E.R.S                                             \n";
			cout << "**************************************************************************************************************\n\n";
			cout << "\t\t1) Display CPUs\n\t\t2)Display GPUs\n\t\t3) Display RAM!\n\t\t4) Display Motherboards\n\t\t5) Display PSUs\n\t\t6) Display Cases\n\t\t7) Return to Main Menu\n\n\t\tChoice: ";
			cin >> ch;
			switch (ch)
			{
			case 1:
				// displayCPU();
				break;
			case 2:
				// displayGPU();
				break;
			case 3:
				// displayRAM();
				break;
			case 4:
				// displayMobo();
				break;
			case 5:
				// displayPSU();
				break;
			case 6:
				// displayCase();
				break;
			case 7:
				break;
			default:
				cout << "incorrect option chosen";
				getchar();
				break;
			}
		} while (ch != 7);
		break;
	case 2:
		ch = 0;
		do
		{
			system("CLS");
			cout << "**************************************************************************************************************\n";
			cout << "                                       S.T.A.R  C.O.M.P.U.T.E.R.S                                             \n";
			cout << "**************************************************************************************************************\n\n";
			cout << "\t\t1) Purchase CPUs\n\t\t2) Purchase GPUs\n\t\t3) Purchase RAM!\n\t\t4) Purchase Motherboards\n\t\t5) Purchase PSUs\n\t\t6) Purchase Cases\n\t\t7) Return to Main Menu\n\n\t\tChoice: ";
			cin >> ch;
			switch (ch)
			{
			case 1:
				// purchaseCPU();
				break;
			case 2:
				// purchaseGPU();
				break;
			case 3:
				// purchaseRAM();
				break;
			case 4:
				// purchaseMobo();
				break;
			case 5:
				// purchasePSU();
				break;
			case 6:
				// purchaseCase();
				break;
			case 7:
				break;
			default:
				cout << "incorrect option chosen";
				getchar();
				break;
			}
		} while (ch != 7);
		break;
	case 3:
		exit(3);
	}
}

void EmployeeMenu()
{
	int ch, choice;
	do
	{
		int ch;
		int choice = 0;
		system("CLS");
		cout << "**************************************************************************************************************\n";
		cout << "                                       S.T.A.R  C.O.M.P.U.T.E.R.S                                             \n";
		cout << "**************************************************************************************************************\n\n";
		cout << "\t\t1) Add Items\n\t\t2)Edit Items\n\t\t3) Delete Items\n\t\t4)Display Items\n\t\t5) EXIT!\n\n\t\tChoice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			addItem();
			break;
		case 2:
			//editItem();
			break;
		case 3:
			deleteItem();
			break;
		case 4:
			ch = 0;
			do
			{
				system("CLS");
				cout << "**************************************************************************************************************\n";
				cout << "                                       S.T.A.R  C.O.M.P.U.T.E.R.S                                             \n";
				cout << "**************************************************************************************************************\n\n";
				cout << "\t\t1) Display CPUs\n\t\t2)Display GPUs\n\t\t3) Display RAM!\n\t\t4) Display Motherboards\n\t\t5) Display PSUs\n\t\t6) Display Cases\n\t\t7) Return to Main Menu\n\n\t\tChoice: ";
				cin >> ch;
				switch (ch)
				{
				case 1:
					// displayCPU();
					break;
				case 2:
					// displayGPU();
					break;
				case 3:
					// displayRAM();
					break;
				case 4:
					// displayMobo();
					break;
				case 5:
					// displayPSU();
					break;
				case 6:
					// displayCase();
					break;
				case 7:
					break;
				default:
					cout << "incorrect option chosen";
					getchar();
					break;
				}
			} while (ch != 7);
			break;
		case 5:
			WTF();
			system("CLS");
			cout << "**************************************************************************************************************\n";
			cout << "                                       S.T.A.R  C.O.M.P.U.T.E.R.S                                             \n";
			cout << "**************************************************************************************************************\n\n";
			cout << "\t\t\tGOOD BYE!";
			cout << "\n\n**************************************************************************************************************";
			exit(5);
		default:
			cout << "\n\n!!!Incorrect option chosen!!!";
			break;
		}
	} while (choice != 7);
}

int main()
{
	char str[10];
	int option, choice, k = 0;

	RFF();

	cout << "Are you a\n1-)	Customer\n2-)	Employee\n(1/2) : ";
	cin >> option;

	system("CLS");

	if (option == 1)
	{
		CustomerMenu();
	}
	else if (option == 2)
	{
	pass:
		system("CLS");
		cout << "\n\n\t\t\tEnter your Password\t";
		str[0] = getch();
		cout << "*";
		str[1] = getch();
		cout << "*";
		str[2] = getch();
		cout << "*";
		str[3] = getch();
		cout << "*";
		str[4] = getch();
		cout << "*";
		str[5] = getch();
		cout << "*";
		str[6] = getch();
		cout << "*";
		if (strcmp(str, "kesnani") == 0)
		{
			cout << "\n\n\n\t\t\t\t\tWelcome Back";
			getche();
			EmployeeMenu();
		}
		else
		{
			system("CLS");
			cout << "\n\n\t\t\t$$$$$$ Ooop's wrong password $$$$$$\n";
			cout << "\n\n\t\t\t%%%%%% Please re-enter the password%%%%%%\n";
			getch();
			k++;
			getch();
			if (k == 3)
			{
				system("CLS");
				cout << "\n\n\t\t\tEnterred Incorrect Password too many times\n\t\t\tExiting!!!!! Bye\n";
				getch();
				exit(0);
			}
			goto pass;
		}
	}

	return 0;
}