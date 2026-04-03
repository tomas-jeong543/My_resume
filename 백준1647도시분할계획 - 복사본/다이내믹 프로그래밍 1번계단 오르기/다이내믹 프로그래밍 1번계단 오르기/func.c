// 계단을 오르면서 얻을 수 있는 최대값을 계산하는 함수

int Find_Max_Score(int* stair_score, int size)
{
	//이 변수가 3보다 크면 다음에도 바로 옆 계단을 밟으면 3번연속 같은 계단을 밟는다는 뜻임으로
	// 3보다 크면 자동적으로 2칸 떨어진 계단으로 이동한다 바로 옆 계단으로 이동시 1증가한다.
	int count = 1;
	// 합 저장 변수
	int sum = 0;
	// 가장 먼저 무조건 올라야 하는 마지막 계단을 첫번째 목표로 정하며 현재 위치하는 계단의 위치 정보를 나타낸다
	int target = size - 1;

	// 종료 조건은 첫 번째 계단을 밟거나 세번째와 두 번째 계단을 밟았을 때이고 아래 return문으로 구현되어 있다.
	while (1){
		
		//우선 계단의 이동은 target의 값 변화로 이루어진다 따라서 target값이 바뀔 때 마다
		//sum값을 현재 위치하는 계단의 점수를 더해준다.
		sum += *(stair_score + target);
		//printf("sum: %d target: %d count: %d\n", sum, target, count);

		//만약 첫번째 계단을 밟았으면 함수를 종료하고 지금까지 얻은 점수의 합을 반환한다
		if (target == 0)
			return sum;

		//만약 바로 옆 계단을 밟을 수 있고 두 칸 떨어진 계단이 존재한다면 
		if (count < 2 && target > 1) {
			//만약 아직 아래에 계단이 4개이상 존재하는 경우
			if (target > 3) {
				//현재 계단 바로 아래 계단과 3칸 아래 계단의 점수의 합이 현재 계단 2칸 아래 계단과 4칸 아래 계단의 점수의 합보다
				//크면 1칸 내려간다
				if (*(stair_score + target - 1) + *(stair_score + target - 3) > *(stair_score + target - 2) + *(stair_score + target - 4)) {
					target -= 1;
					count += 1;
				}
				//반대면 2칸 내려간다
				else if (*(stair_score + target - 1) + *(stair_score + target - 3) < *(stair_score + target - 2) + *(stair_score + target - 4))
					target -= 2;
				//둘의 합이 같으면 둘 중 더 큰 점수를 가진 계단으로 내려가며 그 둘의 점수마저도 같으면 그냥 1칸 내려간다
				else {
					if (*(stair_score + target - 1) >= *(stair_score + target - 2)) {
						target -= 1;
						count += 1;
					}
					else if (*(stair_score + target - 1) < *(stair_score + target - 2))
						target -= 2;
				}
				
			}
			//아래에 남은 계단이 3개라면
			else if (target == 3) {
				//1,3번째 계단과 2번째 계단 중 점수를 더 많이 주는 계단을 밟고 1번째 계단을 밟았음으로
				//최종 점수를 반환
				if (*(stair_score + 0) + *(stair_score + 2) >= *(stair_score + 1)) {
					sum += stair_score[0] + stair_score[2];
					return sum;
				}
				else
					sum += stair_score[1];
				return sum;
			}//아래에 남은 계단이 2개고 둘 다 밟을 수 있다면
			else if (target == 2) {
				// 둘 중 더 점수를 많이주는 계단을 밟고 종료조건을 충족함으로 최종 점수를 반환
				if (*(stair_score + 0) >= *(stair_score + 1)) {
					sum += stair_score[0];
					return sum;
				}
				else
					sum += stair_score[1];
					return sum;
				}
		}//바로 옆 계단에 못가는 경우 2칸 옆 계단으로 이동한다
		else if (count >= 2 && target > 1) {
			target -= 2;
			count = 1;
		}//2번째 계단을 밟았고 첫 번째 계단으로 이동가능한 경우 첫 번째 계단으로 이동한다
		else if (target == 1 && count < 2)
			target = 0;
		//2번째 계단을 밟았고 첫 번째 계단으로 이동가능하지 않으면 최종 점수를 반환한다.
		else if (target == 1 && count >= 2)
			return sum;
	}
}