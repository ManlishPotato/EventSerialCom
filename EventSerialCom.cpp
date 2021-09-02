#include "serialClass.h"
using namespace std;

int main()
{
	serialClass serial;
	serialClass::portSettings ps;
	if(!serial.init(ps)) return 0;
	
	char* ptr[2];
	char onStr[32]="ledOn";
	char offStr[32]="ledOff";
	ptr[0]=&onStr[0];
	ptr[1]=&offStr[0];	

	bool turn=true;

	cout<<"Event based serial communiction"<<endl;
	this_thread::sleep_for(chrono::milliseconds(100));
	serial.printBuffer();
	while(true)
	{	
		for(int i=0;i<=1;i++) 
		{
			if(turn==i) 
			{
				serial.write(ptr[i]);			
				cout<<"echo: "<<ptr[i]<<endl;
			}
		}
		turn=!turn;
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	return 0;
}