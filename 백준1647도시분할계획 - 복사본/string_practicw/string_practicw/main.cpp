#include<iostream>
#include<string>

using namespace std;
int main() {
	string info = "info is very important info is very efficent info is limited";
	size_t pos = -1;
	string target = "info";
	string replacestr = "team";
	pos = info.find(target);
	while (pos != string::npos) {
		cout << "pos: " << pos << endl;
		
		pos = info.find(target, pos + 1 );
		/*if (pos == string::npos) {
			break;
		}
		info.replace(pos, target.length(), replacestr);
		pos += 1;*/
	}
}