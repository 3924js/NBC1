//Status.h

#include <iostream>
#include <string>
#include <vector>

enum StatType {	//스텟 이름 열거형
	LV,
	HP,
	MP,
	ATK,
	DFS,
	STR,
	INT,
	SPCH,
	HPPT,
	MPPT,
	COUNT
};
//스텟 이름 전역변수
const std::string StatName[StatType::COUNT] =
{"레벨","HP", "MP", "공격력", "방어력", "힘", "지능", "화술","HP포션", "MP포션"};

class Status {
private:
	int Stats[StatType::COUNT];
public:
	Status() = default;
	~Status() = default;
	Status(int HP, int MP, int Atk, int Dfs);

	void UseHPPotion();	//HP포션 사용
	void UseMPPotion();	//MP포션 사용
	void IncreaseAtk();	//공격 증가
	void IncreaseDfs();	//방어 증가
	void LevelUp();		//레벨업
	void IncreasePotion(); //포션 지급
	int GetStat(StatType name);
};
