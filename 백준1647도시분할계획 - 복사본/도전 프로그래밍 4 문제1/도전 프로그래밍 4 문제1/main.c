
#include "bookinfo.h"
#include "functioin.h"

int main(void) {

	Book *books[3];

	for (int i = 0; i < 3; i++)
			GetBookinfo(&books[i] );
	

	for (int i = 0; i < 3; i++)
		PrintBookinfo(*books[i]);

	return 0;
}