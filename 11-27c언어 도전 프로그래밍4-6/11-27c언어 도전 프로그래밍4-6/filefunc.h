#include "Phonenuminfo.h"
#include<stdio.h>
#include<string.h>
PhonInfo* Load(FILE* fp, int * size);
void Save(FILE* fp, PhonInfo* phone, int* size);