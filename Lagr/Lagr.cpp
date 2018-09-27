// Lagr.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "locale.h"
#include <iostream>

using namespace std;

double C1=0.205;
double C2=-0.1;
double C3=-2.6;
double C4=0.942;
double C5=-0.1375;


double F(double X)
{
	return (C1*X+C2)/(X*X*X+C3*X*X+C4*X+C5);
}



double lagranz(int n, double t){
        double z,p1,p2; 
		double h=1.0/(n-1);
        z=0;
        for (int j=0; j<n; j++){
                p1=1; p2=1;
                for (int i=0; i<n; i++){
                        if (i==j){
                            p1=p1*1;p2=p2*1;
                        }
                        else {
                                p1=p1*(t-(i)*h);
                                p2=p2*((j)*h-(i)*h);
                    }
                }
                z=z+F((j)*h)*p1/p2;
        }
        return z;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale( LC_ALL,"Russian" );
	int key=999;
	int n;
	double h;
	double MaxE;
	while (key!=0)
	{
		system("cls");
		cout << "Выберите количество точек" << endl;
		cout << "1 - n=5" << endl;
		cout << "2 - n=10" << endl;
		cout << "3 - n=20" << endl;
		cout << "4 - n=25" << endl;
		cout << "0 - Выход" << endl;
		cout << "Ваш выбор:";
		cin >> key;
		switch (key)
		{
		case 1:{
			n=6;
			break;
			   }
		case 2:{
			n=11;
			break;
			   }
		case 3:{
			n=21;
			break;
			   }
		case 4:{
			n=26;
			break;
			   }
		}
		MaxE=0;
  	if ((key!=0)&&(key<5))	
	{
	h=1.0/(n-1);
                for (int i=0; i<2*n-1; i++){
	cout << (i)*h/2<<" | " << lagranz(n,(i)*h/2) << " | " <<F((i)*h/2)<< endl;
	if (MaxE<fabs(lagranz(n,(i)*h/2) - F((i)*h/2))) MaxE=fabs(lagranz(n,(i)*h/2) - F((i)*h/2));
				}
	cout<<"Величина абсолютной ошибки: "<<MaxE<<endl;
		system("pause");
	}
	}
	return 0;
}

