//Status.cpp

#include "Status.h"
using namespace std;

Status::Status(int HP, int MP, int Atk, int Dfs) {
	//기본 스텟 정의
	Stats[StatType::LV] = 0;	//레벨
	Stats[StatType::HP] = HP;	//체력
	Stats[StatType::MP] = MP;	//마력
	Stats[StatType::ATK] = Atk;	//공격
	Stats[StatType::DFS] = Dfs;	//방어
	Stats[StatType::STR] = 10;	//힘
	Stats[StatType::INT] = 10;	//지능
	Stats[StatType::SPCH] = 10;	//화술
	Stats[StatType::HPPT] = 5;	//HP포션
	Stats[StatType::MPPT] = 5;	//MP포션
}
void Status::UseHPPotion() {//HP포션 사용 함수
	if (Stats[StatType::HPPT] < 1) {	//포션 부족시 사용 불가
		cout << "포션이 부족합니다!" << endl;
		return;
	}
	cout << "포션을 사용해 HP를 회복합니다!" << endl;
	Stats[StatType::HP] += 50;
	Stats[StatType::HPPT] -= 1;
}
void Status::UseMPPotion() {//MP포션 사용 함수
	if (Stats[StatType::MPPT] < 1) {	//포션 부족시 사용 불가
		cout << "포션이 부족합니다!" << endl;
		return;
	}
	cout << "포션을 사용해 MP를 회복합니다!" << endl;
	Stats[StatType::MP] += 50;
	Stats[StatType::MPPT] -= 1;
}
void Status::IncreaseAtk() {//공격력 증가 함수
	cout << "공격력 2배!" << endl;
	Stats[StatType::ATK] *= 2;
}
void Status::IncreaseDfs() {//방어력 증가 함수
	cout << "방어력 2배!" << endl;
	Stats[StatType::DFS] = Stats[StatType::DFS] << 1;
}
void Status::LevelUp() {	//레벨업 함수
	cout << "레벨업! HP/MP포션이 하나씩 지급됩니다!" << endl;
	Stats[StatType::LV] += 1;
	IncreasePotion();	//레벨업 후 포션 지급
}
void Status::IncreasePotion() {	//포션 지급 함수
	Stats[StatType::HPPT] += 1;
	Stats[StatType::MPPT] += 1;
}

int Status::GetStat(StatType name) {//스탯 반환 함수
	return(Stats[name]);
}