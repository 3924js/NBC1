//PlayManager.cpp

#include <iostream>
#include <string>
#include "Playmanager.h"
using namespace std;

void PlayManager::SetStatus() {
	int HP, MP, Atk, Dfs;
	//HP, MP 입력
	while (true) {
		cout << "HP와 MP를 입력하세요 : ";
		
		cin >> HP >> MP;
		//입력 검사후 올바르지 않으면 반복문 다시 실행
		if (HP <= 50 || MP <= 50) {
			cout << "HP 혹은 MP가 50 이하입니다. 다시 입력해주세요." << endl;
			continue;
		}
		//올바르면 반복문 종료
		else {
			break;
		}
	}
	//공격력/방어력 입력
	while (true) {
		cout << "공격력과 방어력을 입력하세요 : ";
		cin >> Atk >> Dfs;
		//입력 검사후 올바르지 않으면 반복문 다시 실행
		if (Atk <= 0 || Dfs <= 0) {
			cout << "공격력 혹은 방어력이 0 이하입니다. 다시 입력해주세요." << endl;
			continue;
		}
		//올바르면 반복문 종료
		else {
			break;
		}
	}
	//스탯 초기화
	Stats = Status(HP, MP, Atk, Dfs);
	cout << "환영합니다! HP/MP포션이 다섯 개씩 지급됩니다!\n"
		"= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = " << endl;
}

void PlayManager::ShowStats()
{
	int i = 0;
	for (i; i < static_cast<int>(StatType::COUNT) - 1; i++) {	//enum에 기반한 각 스탯 출력
		cout << StatName[i] << ": " << Stats.GetStat(static_cast<StatType>(i)) << ", ";
	}
	cout << StatName[i] << ": " << Stats.GetStat(static_cast<StatType>(i)) << endl;
}

void PlayManager::Play() {
	//초기 스탯 설정
	SetStatus();
	//무한 반복문
	bool IsPlaying = true;
	while (IsPlaying) {
		cout << "원하는 선택지를 입력하세요!\n"
			"0: 종료합니다.\n"
			"1: HP포션을 사용합니다.\n"
			"2: MP포션을 사용합니다.\n"
			"3: 공격력을 2배로 올립니다.\n"
			"4: 방어력을 2배로 올립니다.\n"
			"5: 현재 정보를 봅니다.\n"
			"6: 레벨업을 합니다.\n"
			"7: 상점에서 물약을 얻습니다.\n"
			"=> ";
		int Selection;
		cin >> Selection;
		switch (Selection) {
		case 0:	//종료
			cout << "프로그램을 종료합니다! 안녕히가세요!" << endl;
			IsPlaying = false;
			break;
		case 1:	//HP포션
			Stats.UseHPPotion();
			break;
		case 2:	//MP포션
			Stats.UseMPPotion();
			break;
		case 3:	//공격력
			Stats.IncreaseAtk();
			break;
		case 4:	//방어력
			Stats.IncreaseDfs();
			break;
		case 5: //정보
			ShowStats();
			break;
		case 6:	//레벨업
			Stats.LevelUp();
			break;
		case 7:	//레벨업
			TradePotion();
			break;
		default:	//입력오류
			cout << "입력값이 잘못되었습니다!" << endl;
			break;
		}
		cout << "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = " << endl;
	}
}
void PlayManager::TradePotion() {
	if (Stats.GetStat(StatType::LV) < 5) { //레벨 제한
		cout << "상점 주인: 5레벨은 되야지 여길 이용할 수 있어. 꼬맹이는 안돼!\n"
			"상점 주인은 거래하기 싫은 듯 합니다." << endl;
		return;
	}
	cout << "상점 주인: 물약 필요해서 왔나? 가져가시게나.\n"	//포션 제공
		"상점 주인은 포션 한쌍을 카운터에 올려줍니다." << endl;
	Stats.IncreasePotion();
	if (Stats.GetStat(StatType::ATK) > 200) {	//200 이상 공격력이면 포션 추가 제공
		cout << "상점 주인: 강해보이는걸 보니 듬직 하군! 이거 하나 더 챙겨가시게!\n"
			"상점 주인은 맘에 들었는지 포션 한쌍을 더 챙겨줍니다." << endl;
		Stats.IncreasePotion();
	}
}

