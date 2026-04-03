
// 동전을 가장 적게 써서 원하는  가치를 얻는 함수
void Use_Mincoin_ToMake_Value(int* coinnum, int value, int* coinprice, int cointypenum)
{

	//모든 동전의 종류 만큼 반복
	for (int i = 0; i < cointypenum; i++) {
		//가격이 큰 동전부터 이용한다.
		while (value / coinprice[cointypenum - i - 1] > 0) {
			//동전의 가격만큼 가치를 뺀다.
			value -= coinprice[cointypenum - i - 1];
			//동전 개수를 증가시킨다.
			coinnum[cointypenum - i - 1] += 1;
		}
	}
}