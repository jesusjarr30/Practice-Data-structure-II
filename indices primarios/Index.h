#ifndef INDEX_H
#define INDEX_H
#include <iostream>
#include <sstream>

using namespace std;

class Index
{
	private:
		int index;
		string primaryKey;

	public:
		Index();
		Index(int index,string primaryKey);
		string toString();
		string toString2();
		//gets
		int getIndex();
		string get_primarykey();
		bool operator > (Index right);
		bool operator == (Index right);
		string guardar();
		//sets
		//void setIndex();
		void set_primaryKey(string aux);
		
};

#endif
