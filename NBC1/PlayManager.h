//PlayManager.h

#include <string>
#include "Status.h"

class PlayManager {
private:	//Play()반복문 함수를 통해서만 Status 접근 가능
	Status Stats;
	//스텟 설정
	void SetStatus();
	//스탯 출력
	void ShowStats();
public:
	PlayManager() = default;
	~PlayManager() = default;
	//선택지 무한 반복
	void Play();

	//물약 거래 함수
	void TradePotion();
};
