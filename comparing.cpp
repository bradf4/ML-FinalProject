#include <string>
#include <iostream>
#include <cctype>
#include <fstream>

using std::string;
using std::istream;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::cout;

int main()
{
	ifstream in("bullying_trace.txt"); //prediction
	ifstream in2("labels.txt");	//labels
	
	string prediction, label;
	
	in >> prediction;
	in2 >> label;
	int totalcount = 0, predictcorrect = 0;
	while( !in.fail() )
	{
		if(in2.fail())
			break;
		if (prediction == label)
			predictcorrect++;
		
		totalcount++;
		in >> prediction;
		in2 >> label;
	}
	double percentage = (predictcorrect*1.0)/totalcount;
	
	cout << "The machine learning program predicted " << predictcorrect << " correct cases of bullying out of " << totalcount << ".\n";
	cout << "This gives us an accuracy of " << percentage << ".\n";
}