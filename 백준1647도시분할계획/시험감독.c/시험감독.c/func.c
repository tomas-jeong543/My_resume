
//시험 인원에 대한 필요한 감독관 수를 반환하는 함수
int Find_Supervisor_Num(int student_num,int main,int sub )
{
	//총감독관이 모든 시험자를 감독할 수 있는 경우
	if (student_num <= main)
		return 1;
	// 총감독관이 모든 시험자를 감독할 수 없는 경우
	else {
		// 총 시험자 수에서 총감독관이 관리 가능한 인원을 뺀다
		student_num -= main;

		// 만약 시험자수가 부감독관이 감독할 수 있는 인원으로 나누어 떨어지면 부감독관 인원 (student_num / sub) + 총감독관 인원 1 반환
		if (student_num % sub == 0)
			return (student_num / sub) + 1;
		//아닌 경우 나머지 인원에 대해서도 감독이 필요함으로 부감독관 1명을 더 추가한 인원 반환
		else
			return (student_num / sub) + 2;

	}
}