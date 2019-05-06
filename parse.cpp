#include <string>
#include <iostream>
#include <cctype>
#include <fstream>
#include <sstream>

using std::string;
using std::istream;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::endl;
using std::cout;
using std::stringstream;

int main()
{
	ifstream in("data.txt");
	ofstream out("tweets.txt");
	ofstream out2("labels.txt");
	
	string line, pre, tweet, strLabel;
	char label = '%';

	while(!getline(in, line).fail())
	{
		std::size_t found = line.find(",\"annotation\"");
		if (found!=std::string::npos)
			line.replace(found, 13, "~");
		
		found = line.find("label\":");
		if (found!=std::string::npos)
			label = line.at(found+9);
		
		if (label == '1')
			strLabel = "yes";
		else if (label == '0')
			strLabel = "no";
		else 
			cout << "NO LABEL" << endl;
		
		stringstream ss(line); 
		getline(ss, pre, ' ');
		getline(ss, tweet, '~');
		
		out << tweet << endl;
		out2 << strLabel << endl;
	}
	
}