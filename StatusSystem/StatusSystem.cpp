        #include <iostream>
        using namespace std;

        // - 포션 지급 함수를 작성합니다.
        // HP, MP 강화 포션은 5개씩 기본 지급되며, 
        // HP, MP포션 개수로 5를 저장합니다. 함수는 다음과 같이 정의합니다.
        void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
            *p_HPPotion += count;
            *p_MPPotion += count;
        }

        // ASCII 전용 성향 메뉴
        void printTraitMenu() {
            cout << "\n";
            cout << "+----------------------------------------+\n";
            cout << "|           성향 관리 시스템             |\n";
            cout << "+----------------------------------------+\n";
            cout << "| 1. 카리스마 UP                         |\n";
            cout << "| 2. 감성 UP                             |\n";
            cout << "| 3. 통찰력 UP                           |\n";
            cout << "| 4. 의지 UP                             |\n";
            cout << "| 5. 현재 성향                           |\n";
            cout << "| 0. 나가기                              |\n";
            cout << "+----------------------------------------+\n";
            cout << " 선택 : ";
        }

        // ASCII 전용 스탯 메뉴
        void printStatsMenu() {
            cout << "\n";
            cout << "+----------------------------------------+\n";
            cout << "|            스탯 관리 시스템            |\n";
            cout << "+----------------------------------------+\n";
            cout << "| 1. HP UP                               |\n";
            cout << "| 2. MP UP                               |\n";
            cout << "| 3. 공격력 UP                           |\n";
            cout << "| 4. 방어력 UP                           |\n";
            cout << "| 5. 현재 능력치                         |\n";
            cout << "| 6. Level UP                            |\n";
            cout << "| 7. 성향 관리                           |\n";
            cout << "| 0. 나가기                              |\n";
            cout << "+----------------------------------------+\n";
            cout << " 선택 : ";
        }

        // ASCII 전용 성향 출력
        void printTraitStatus(int status[]) {
            // status[5] ~ status[8] : 카리스마, 감성, 통찰력, 의지
            cout << "\n";
            cout << "+-----------------------------+\n";
            cout << "|         현재 성향치         |\n";
            cout << "+-----------------------------+\n";
            cout << "|  카리스마 : " << status[5] << "\n";
            cout << "|  감성     : " << status[6] << "\n";
            cout << "|  통찰력   : " << status[7] << "\n";
            cout << "|  의지     : " << status[8] << "\n";
            cout << "+-----------------------------+\n\n";
        }

        // ASCII 전용 능력치 출력
        void printStatus(int status[], int HPPotion, int MPPotion) {
            //status[0]~stautus[4] : HP,MP,공격력,방어력,레벨
            cout << "\n";
            cout << "+-----------------------------+\n";
            cout << "|          현재 능력치         |\n";
            cout << "+-----------------------------+\n";
            cout << "|  LV        : " << status[4] << "\n";
            cout << "|  HP        : " << status[0] << "\n";
            cout << "|  MP        : " << status[1] << "\n";
            cout << "|  공격력    : " << status[2] << "\n";
            cout << "|  방어력    : " << status[3] << "\n";
            cout << "+-----------------------------+\n";
            cout << "|  남은 HP 포션 : " << HPPotion << "\n";
            cout << "|  남은 MP 포션 : " << MPPotion << "\n";
            cout << "+-----------------------------+\n\n";
        }

        int main() {
            // - HP, MP, 공격력, 방어력 등 스탯을 int형 배열로 선언, 전체 값들은 0으로 초기화합니다.
        // (배열 이름이 status라면 status[0]은 HP, status[3]은 방어력,status[4]는 레벨)
            int status[9] = { 0,0,0,0,0,0,0,0,0 };

            int hp = 0, mp = 0;
            int attack = 0, defense = 0;
            int HPPotion = 0, MPPotion = 0;
            
            // - HP와 MP를 입력 받고, HP/MP 중 하나라도 50 이하의 숫자를 입력 받을 경우 다시 입력 받습니다.
            while (hp <= 50 || mp <= 50) { //hp,mp 변수 저장된 값 둘 다 50 넘을 때 까지 반복
                cout << "\n+-----------------------------+\n";
                cout << "|   HP와 MP를 입력해주세요.   |\n";
                cout << "+-----------------------------+\n";
                cout << "HP MP 입력 : ";
                cin >> hp >> mp; //입력 받은 값 hp,mp 변수에 저장
                if(hp<=50 || mp<=50){
                    cout<<"HP와 MP는 50 초과이어야 합니다. 다시 입력하세요.\n";
                }
                status[0] = hp; //status 배열의 0번째 값(0번 인덱스) HP에 hp 변수 값 저장
                status[1] = mp; //status 배열의 1번째 값(1번 인덱스) MP에 mp 변수 값 저장
            }

            // - HP와 MP에 값을 입력 받은 후 공격력과 방어력을 입력 받습니다.
        // - 공격력이나 방어력이 하나라도 0 이하의 숫자를 입력 받을 경우 다시 입력 받습니다.
            while (attack <= 0 || defense <= 0) { // attack, defense 변수 저장된 값 둘 다 0보다 클 때까지 반복
                cout << "\n+-----------------------------+\n";
                cout << "|  공격력과 방어력을 입력하세요 |\n";
                cout << "+-----------------------------+\n";
                cout << "공격력 방어력 입력 : ";
                cin >> attack >> defense; //입력받은 값 attack,defense 변수에 저장
                if(attack <= 0 || defense <= 0){
                    cout<<"공격력과 방어력은 1 이상이어야 합니다. 다시 입력하세요.\n";
                }
                status[2] = attack; //status 배열의 3번째 값(2번 인덱스) 공격력에  attack 변수 값 저장
                status[3] = defense; //status 배열의 4번째 값(3번 인덱스) 방어력에 defense 변수 값 저장
            }

            // 포션 기본 지급
            setPotion(5, &HPPotion, &MPPotion);

            // - 스탯 관리 시스템을 시작합니다.
            //     - 1. HP UP 2. MP UP 3. 공격력 UP 4. 방어력 UP 5. 현재 능력치 6. Level Up 0. 나가기
            //     - 선택지를 출력한 후, int형 정수 하나를 입력 받아서 해당 선택지를 실행합니다.
            int choice = -1;
            while (choice != 0) {
                printStatsMenu(); //Status 메뉴 출력 함수 실행
                cin >> choice; //입력 값 choice 변수에 저장해서 해당 choice 값 경우에 따라서 조건 실행

                switch (choice) {
                // - 1, 2번을 선택 시 각각 HP/MP가 20 증가하고, 포션의 개수가 1개씩 차감 됩니다. 포션이 0개일 경우 사용할 수 없습니다.
                case 1: // HP UP
                    if (HPPotion > 0) { //HPPotion 갯수가 0이 아닐 경우 HP에 20 추가, 포션 갯수 감소, 메세지 출력
                        status[0] += 20;
                        HPPotion--;
                        cout << "HP가 20 증가했습니다! 포션이 1개 차감됩니다. 현재 HP : " << status[0] << ", 남은 포션 : " << HPPotion << "\n";
                    }
                    else cout << "HP 포션이 부족합니다!\n";
                    break;

                case 2: // MP UP
                    if (MPPotion > 0) { //MPPotion 갯수가 0이 아닐 경우 MP에 20 추가, 포션 갯수 감소, 메세지 출력
                        status[1] += 20;
                        MPPotion--;
                        cout << "MP가 20 증가했습니다! 포션이 1개 차감됩니다. 현재 MP : " << status[1] << ", 남은 포션 : " << MPPotion << "\n";
                    }
                    else cout << "MP 포션이 부족합니다!\n";
                    break;

                // - 3, 4번을 선택 시 각각 공격력/방어력이 2배씩 증가합니다. 이 연산은 두 가지 방법이 있으니 잘 생각해보시길 바랍니다.
                // 공격력 UP
                case 3: { // 공격력 UP
                    int before = status[2]; //기존 공격력 before 변수에 저장
                    int after = before * 2; //증가 공격력 값 after 변수에 저장
                    cout << "\n+-----------------------------+\n";
                    cout << "|        공격력 상승!         |\n";
                    cout << "+-----------------------------+\n";
                    cout << "공격력 : " << before << " -> " << after << "\n"; // 기존 공격력에서 증가 공격력 올라감 메세지 출력
                    status[2] = after; //증가 공격력 값으로 status 배열의 공격력 값 대체
                    break;
                }

                case 4: { // 방어력 UP
                    int before = status[3]; //기존 방어력 before 변수에 저장
                    int after = before * 2; //증가 방어력 after 변수에 저장
                    cout << "\n+-----------------------------+\n";
                    cout << "|        방어력 상승!         |\n";
                    cout << "+-----------------------------+\n";
                    cout << "방어력 : " << before << " -> " << after << "\n"; // 기존 방어력에서 증가 방어력 올라감 메세지 출력
                    status[3] = after; //증가 방어력 값으로 status 배열의 방어력 값 대체
                    break;
                }
                
                // - 5번 현재 HP, MP, 공격력, 방어력을 출력해줍니다.
                // - 5번 현재 능력치를 출력해줄 때 나의 레벨도 같이 보여줍니다.
                // - 5번 현재 능력치를 출력해줄 때 남은 포션 수도 같이 보여줍니다.
                // 현재 능력치 출력
                case 5: // 현재 능력치
                    printStatus(status, HPPotion, MPPotion); //현재 능력치 창 출력 함수 실행(status 배열과 HP,MP 포션 값에 대해서)
                    break;
                
                // - 레벨 변수를 만들어서, 6번 레벨업을 실행하면 나의 레벨도 1씩 올려줍니다.
                // - 6번은 레벨업, HP/MP포션을 하나씩 충전 해줍니다.
                // - 레벨 업 할 때 포션 충전을 함수로 변경해봅니다.
                // 레벨 업
                case 6: // LEVEL UP
                    status[4]++; //status 배열의 레벨 값 더하기
                    setPotion(1, &HPPotion, &MPPotion); //레벨 상승에 따른 포션 갯수 증가
                    cout << "\n+-----------------------------+\n";
                    cout << "|         LEVEL UP!!          |\n";
                    cout << "+-----------------------------+\n";
                    cout << "현재 레벨 : " << status[4] << "\n";
                    cout << "포션이 1개씩 충전되었습니다.\n";
                    break;
                
                // - 공격력, 방어력 이외에 힘, 민첩, 지능 같은 추가 스탯도 만들어봅시다. 
                case 7: { //7번 입력 시 추가 스탯 성향 관리 메뉴 열립니다.
                    int trait_choice = -1;
                    while (trait_choice != 0) {
                        printTraitMenu(); //스탯 성향 관리 메뉴 화면에 출력 함수 실행
                        cin >> trait_choice; //입력 받은 값 trait choice로 저장해서 해당 값 조건에 따라서 실행

                        switch (trait_choice) {
                        case 1:
                            status[5]++; //status배열의 카리스마 값 증가
                            cout << "카리스마 +1 -> " << status[5] << "\n";
                            break;
                        case 2:
                            status[6]++; //status 배열의 감성 값 증가
                            cout << "감성 +1 -> " << status[6] << "\n";
                            break;
                        case 3:
                            status[7]++; //status 배열의 통찰력 값 증가
                            cout << "통찰력 +1 -> " << status[7] << "\n";
                            break;
                        case 4:
                            status[8]++; //status 배열의 의지 값 증가
                            cout << "의지 +1 -> " << status[8] << "\n";
                            break;
                        case 5: //현재 성향치 출력
                            printTraitStatus(status); //현재 성향치 출력 함수 실행
                            break;
                        case 0: //성향 관리 메뉴 종료
                            cout << "성향 관리창 종료\n";
                            break;
                        default:
                            cout << "잘못된 입력입니다.\n";
                        }
                    }
                    break;
                }

                case 0: //Status 관리 프로그램 종료
                    cout << "\n프로그램을 종료합니다.\n";
                    break;

                default:
                    cout << "잘못된 입력입니다.\n";
                }
            }
        }
