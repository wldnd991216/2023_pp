//#define DEBUG
#include <iostream>
#include <conio.h>
#include <Windows.h>

// game_state == 0 일때

const int max_map = 100;


int print_title_screen()
{
    std::cout << "******************************************" << std::endl;
    std::cout << "*                                        *" << std::endl;
    std::cout << "*                                        *" << std::endl;
    std::cout << "*              지렁이 게임               *" << std::endl;
    std::cout << "*             (Snake  Bite)              *" << std::endl;

#ifdef DEBUG
    std::cout << "*            - 디버그 모드 -             *" << std::endl;
#else
    std::cout << "*                                        *" << std::endl;
#endif  
    std::cout << "*   1. 게임 시작                         *" << std::endl;
    std::cout << "*   2. 게임 설명                         *" << std::endl;
    std::cout << "*   3. 게임 랭킹 보기                    *" << std::endl;
    std::cout << "*   4. 게임 종료 (esc)                   *" << std::endl;
    std::cout << "******************************************" << std::endl;

    return 0;
}

void gotoxy(int x, int y) {
    //x, y 좌표 설정
    COORD pos = { x,y };
    //커서 이동
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int print_game_screen(int stage_width, int stage_height)
{
    // 이차원 맵 생성
        char map[max_map][max_map] = {};

        // 맵에 테두리 그리기
        for (int i = 0; i < stage_width + 2; i++) {
            map[0][i] = '#';
            map[stage_height + 1][i] = '#';
        }
        for (int i = 0; i < stage_height + 2; i++) {
            map[i][0] = '#';
            map[i][stage_width + 1] = '#';
        }

        // 맵 출력
        for (int i = 0; i < stage_height + 2; i++) {
            for (int j = 0; j < stage_width + 2; j++) {
                if (map[i][j] == '#') {
                    std::cout << "#";
                }
                else {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
        }

        return 0;
 }


// game_state == 2 일때
int print_introduction_screen()
{
    std::cout << "******************************************" << std::endl;
    std::cout << "타이틀화면으로 돌아갈까요? (Y/N)" << std::endl;
    return 0;
}

int main()
{

    int game_state = 0;
    int is_game_running = 1;

    while (is_game_running)
    {   
        char key_input = '0';
        switch (game_state)
        {
        case 0:
            print_title_screen();
            key_input = _getch();
            switch(key_input)
            {
            case '1':
                game_state = 1;
                break;
            case '2':
                game_state = 2;
                break;
            case '3':
                break;
            case '4':
                is_game_running = 0;
                break;
            case 27:
                is_game_running = 0;
                break;
            default:
                break;
            }
            break;
        case 1:

            int stage_width, stage_height;
            std::cout << "맵 가로 크기를 입력하세요: ";
            std::cin >> stage_width;
            std::cout << "맵 세로 크기를 입력하세요: ";
            std::cin >> stage_height;
            print_game_screen(stage_width, stage_height);
            key_input = _getch();
            break;


        case 2:
            print_introduction_screen();
            key_input = _getch();
            switch (key_input)
            {
            case 'y':
                game_state = 0;
                break;
            case 'n':
                break;
            default:
                break;
            }
            break;
        
        default:
            break;
        }     
        
        
    }

    return 0;
}
