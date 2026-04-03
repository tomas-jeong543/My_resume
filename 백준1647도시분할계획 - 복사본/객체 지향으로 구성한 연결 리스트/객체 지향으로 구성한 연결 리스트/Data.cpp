#include"Data.h"

int Data::Compare(const Data& theOtherData)
{
	if (myvalue < theOtherData.myvalue)
		return kIsSmaller;
	if (myvalue > theOtherData.myvalue)
		return kIsLarger;
	else
		return kIsSame;
}


