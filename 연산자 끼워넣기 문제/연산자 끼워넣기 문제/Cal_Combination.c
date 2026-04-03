#include"Cal.h"
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
int Simple_Pactorial(int n) {
	int result = 1;
	
	while (n > 1) {
		result *= n;
		n -= 1;
	}
	return result;
}

int Complex_Pactorial(int n,  int *pactorialnum)
{
	int result = 1;
	
	while (n > 1) {
		result *= n;
		*pactorialnum += 1;
		n -= 1;
	}
	return result;
}

void Save_All_Result(int** calesult, int calsymbol[4],
	int* Numarr, int NumTocal, int time, int Numarridx, int size)
{
	int startnum = 0;
	int timeins = time;
	
	if (time < 1)
		return;


		
	for (int k = startnum; k < (size / time + startnum); k++) {
					
		for (int j = 0; j < 4; j++) {
			if (calsymbol[j] > 0) {
					printf("true j %d\n", j);
					calsymbol[j] -= 1;
							
				if (j == 0) {
						*calesult[k] = Add(*calesult[k], NumTocal);
						printf("k: %d *calresult[%d]: %d\n", k, k, *calesult[k]);
					}
				else if (j == 1) {
						*calesult[k] = Subtract(*calesult[k], NumTocal);
						printf("k: %d *calresult[%d]: %d\n", k, k, *calesult[k]);
					}
				else if (j == 2) {
						printf("qwqwqwwq");
						*calesult[k] = Mul(*calesult[k], NumTocal);
						printf("k: %d *calresult[%d]: %d\n", k, k, *calesult[k]);
					}
				else if (j == 3) {
						if (*calesult[k] >= 0) {
							*calesult[k] = Divide_Plus(*calesult[k], NumTocal);
							printf("k: %d *calresult[%d]: %d\n", k, k, *calesult[k]);
						}

						else {
							*calesult[k] = Divide_Minus(*calesult[k], NumTocal);
							printf("k: %d *calresult[%d]: %d\n", k, k, *calesult[k]);
						}
					}
				}
			startnum += size / time;
			NumTocal = Numarr[Numarridx + 1];
			Numarridx += 1;
			Save_All_Result(calesult, calsymbol, Numarr, NumTocal, time - 1, Numarridx, size);
		}
	}
}
			
				
	



