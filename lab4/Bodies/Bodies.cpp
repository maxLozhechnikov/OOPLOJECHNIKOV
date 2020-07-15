#include "stdafx.h"
#include "Controller.h"

using namespace std;

void Fn(const CBody& body) {
	cout << body.GetDensity();
}

int main()
{
	CSphere s(10, 10);
	Fn(s);

	vector<shared_ptr<CBody>> bodies;
	Controller(bodies, cin, cout);
	return 0;
}