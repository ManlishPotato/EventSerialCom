#include "serialClass.h"
using namespace std;

bool consoleListPorts()
{
	FindComPorts fcp;
	wstring ports[MAX_PORT_NUM]; //With only 4 physical ports on pc, its unlikely to be more at a given time.
	wstring portNames[MAX_PORT_NUM];
	int nPorts=0;
	string er;

	if(!fcp.listComPorts(portNames,ports,nPorts,er)) {cout<<"Error"<<endl; return false;}
	if(nPorts>0)
	{
		cout<<"Available ports: "<<nPorts<<endl;
		for(int i=0;i<nPorts;i++) wcout<<"Num"<<i<<" | "<<portNames[i]<<" | "<<ports[i]<<endl;
	}
	else cout<<"No available ports"<<endl;
}

int main()
{
	serialClass serial;
	serialClass::portSettings ps;

	if(!consoleListPorts()) return 0;

	if(!serial.init(ps)) return 0;
		
	serial.end();	
	return 0;
}