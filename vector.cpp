#include <iostream>
#include <vector>

/****************************
*	A CLASSE VECTOR CONSOME	*
*	MAIS MEMORIA.			*
*****************************/

using namespace std;

int main(){

	vector<int> intlist(2);

	intlist[0] = 234;
	intlist.push_back(19);
	intlist.push_back(1);
	intlist.push_back(9);
	intlist.push_back(55);
	intlist.push_back(71);
	/* intlist.push_front(10); */  

	for(int i=0; i < intlist.size(); i++)
		cout << "Posicao " << i << " = " << intlist[i] << endl;
}