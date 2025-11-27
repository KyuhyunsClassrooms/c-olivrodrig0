#include <stdio.h>
#include <windows.h> //window는 대기함수
/*
    1. [설계]에서 정의한 변수, 배열, (필요하면) 구조체를 여기에 선언하세요.
    
    예시 - 배열 사용:
    char names[100][20];
    int scores[100];
    int count = 0;
    
    예시 - 구조체 사용 (선택):
    struct Student {
        char name[20];
        int score;
    };
    struct Student students[100];
*/


/*
    2. [알고리즘]에서 설계한 핵심 기능 함수들을 여기에 선언하세요.
*/


#include <stdio.h> //입출력 함수
#include <stdlib.h> //난수 관련 함수
#include <time.h> //시간 관련 함수

// 카드 덱 배열 생성 (1~13)
// J(11), Q(12), K(13)은 10으로 계산
int deck[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

// 카드 두 장을 뽑는 함수->카드를 뽑고 나서 되돌리지 않으므로 void사용
void drawCards(int *card1, int *card2) {
    int index1, index2;

    // rand를 사용하여 0부터 12사이의 카드 
    index1 = rand() % 13;

    // 두 번째 카드 인덱스는 첫 번째와 겹치지 않게 다시 랜덤 선택
    do {
        index2 = rand() % 13;
    } while (index2 == index1);

    *card1 = deck[index1]; //deck 배열에서 카드를 한 장씩 가져옴
    *card2 = deck[index2];
}

// 카드 점수 계산 함수 (두 장의 합 % 10)
int calcScore(int card1, int card2) {
    int total = card1 + card2;
    return total % 10;
}

int main() {
    int playerCard1, playerCard2;
    int bankerCard1, bankerCard2;
    int playerScore, bankerScore;

    // 랜덤 시드 설정 (매번 다른 결과를 위해) srand가 난수의 시작점을 나타내는데 time(NULL)이 이 지점을 항상 다르게 하므로 완전 랜덤한 변수.
    srand(time(NULL));

    printf("Place your bets, please.\n");
    Sleep(1000); //1초간 대기
    printf("No more bets.\n");
    Sleep(2000); //2초간 대기
    printf("Cards are dealth.\n");

    printf("Please wait for scoring.\n");
    Sleep(3000);


    // 플레이어와 딜러 각각 두 장의 카드 받기->이미 정의된 함수이기에 int를 넣으면 안됨.
    drawCards(&playerCard1, &playerCard2);
    drawCards(&bankerCard1, &bankerCard2);

    // 점수 계산
    playerScore = calcScore(playerCard1, playerCard2);
    bankerScore = calcScore(bankerCard1, bankerCard2);

    // 결과 출력
    printf("\n플레이어 카드: [%d, %d], 점수: %d\n", playerCard1, playerCard2, playerScore);
    printf("딜러 카드: [%d, %d], 점수: %d\n", bankerCard1, bankerCard2, bankerScore);

    // 승패 판정
    if (playerScore > bankerScore) {
        printf("\n Player wins!\n");
    } else if (playerScore < bankerScore) {
        printf("\n Banker wins!\n");
    } else {
        printf("\n It's a tie!\n");
    }

    return 0;
}
