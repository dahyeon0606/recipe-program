
#include <stdio.h>
#include <string.h>
#include <conio.h>
#define _CRT_SECURE_NO_WARNINGS
#define COOKTYPE 5
#define COOKS 2 

typedef struct cook  
{
    char name[100];
    char ingredient[500];
    char recipe[1000];
}COOK;

typedef struct type 
{
    COOK stew[COOKS];
    COOK easy[COOKS];
    COOK special[COOKS];
    COOK rice[COOKS];
    COOK noodle[COOKS];
}TYPE;

typedef struct my { 
    char nickname[10];
    COOK mycook[1];
    int level;
}MY;

typedef enum menu { ONE = 1, TWO, THREE }MENU; 


void file_print();
void create_cook(TYPE* cooktype);

//메뉴1에 사용되는 함수들
void menu_1(TYPE cooktype);
void print_type(char** cooks_type);
void recipe_token_print(COOK* result);

COOK stew_0(TYPE* p);
COOK easy_1(TYPE* p);
COOK special_2(TYPE* p);
COOK rice_3(TYPE* p);
COOK noodle_4(TYPE* p);

//메뉴2에 사용되는 함수들
void menu_2(MY* myinfor);



//메인 함수
int main(void)
{
    TYPE cooktype;
    MENU menus;
    MY myinfor; 

    create_cook(&cooktype);
    file_print();

    printf("\n닉네임을 입력해주세요: ");
    gets(myinfor.nickname); 
    system("cls");
    printf("%s님, 환영합니다 :)\n", myinfor.nickname);

    while (1)
    {
      
        printf("\n======================메뉴======================\n              1. 종류별 음식\n              2. 나만의 레시피\n              3. 프로그램 종료\n");
        printf("번호를 입력해주세요>> ");
        scanf("%d", &menus);

        switch (menus)
        {
        case ONE:
            menu_1(cooktype);
            break;

        case TWO:
            menu_2(&myinfor);
            break;

        case THREE:
            system("cls");
            printf("\n이용해 주셔서 감사합니다 :)\n");
            return 0;

        default:
            printf("\n**번호를 다시 입력해주세요**");
        }

    }
    return 0;
}

void menu_1(TYPE cooktype)
{
    int select; //음식종류 선택 0~4번
    char* cooks_type[] = { "0. 찌개","1. 간편식","2. 스페셜메뉴","3. 밥","4. 면" }; //문자형 포인터 배열에 음식종류 저장
    COOK result; //결과적으로 선택한 음식
    COOK(*cook_select[COOKTYPE])(TYPE * p) = { stew_0 ,easy_1,special_2,rice_3,noodle_4 }; //함수 포인터 배열

    system("cls");
    printf("\n");

    print_type(cooks_type); //음식 종류 출력
    scanf("%d", &select);

    result = cook_select[select](&cooktype); //사용자가 선택한 수에 따라 함수를 호출함, 인수로는 구조체의 주소를 넘김, 선택한 음식의 구조체 반환

    system("cls");
    printf("\n");

    printf("< %s의 레시피 >\n\n", result.name);
    printf("%s\n\n", result.ingredient);
    recipe_token_print(&result); // /단위로 나누어 레시피 출력

    printf("완성! 수고하셨습니다.\n");

}

void file_print() //요리사 사진 출력해주는 함수
{
    char line[255];

    FILE* file = fopen("cooker.txt", "r");
    if (file == NULL) {
        printf("파일열기 실패\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}

void print_type(char** cooks_type) //음식 종류 출력해주는 함수
{
    int i;

    printf("------------------------------------------------------------------------------------------------------------------------\n");
    for (i = 0; i < COOKTYPE; i++)
    {
        printf("%20s  ", cooks_type[i]);
    }
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");
    printf("메뉴선택>> ");
}

COOK stew_0(TYPE* p) //음식명을 출력하고 음식을 선택하도록 하는 함수, 최종적으로 선택된 메뉴의 구조체를 반환함
{
    int i, select;
    COOK result;

    system("cls");
    printf("\n########################################################## 찌개 ########################################################\n\n");

    for (i = 0; i < COOKS; i++)
    {
        printf("%30d.%s  ", i, p->stew[i].name);
    }
    printf("\n");
    printf("음식선택>>");
    scanf("%d", &select);

    result = p->stew[select];

    return result;

}

COOK easy_1(TYPE* p)
{
    int i, select;
    COOK result;

    system("cls");
    printf("\n######################################################## 간편식 ########################################################\n\n");

    for (i = 0; i < COOKS; i++)
    {
        printf("%30d.%s  ", i, p->easy[i].name);
    }
    printf("\n");
    printf("음식선택>>");
    scanf("%d", &select);

    result = p->easy[select];

    return result;
}

COOK special_2(TYPE* p)
{
    int i, select;
    COOK result;

    system("cls");
    printf("\n###################################################### 스페셜메뉴 ######################################################\n\n");

    for (i = 0; i < COOKS; i++)
    {
        printf("%30d.%s  ", i, p->special[i].name);
    }
    printf("\n");
    printf("음식선택>>");
    scanf("%d", &select);

    result = p->special[select];

    return result;
}

COOK rice_3(TYPE* p)
{
    int i, select;
    COOK result;

    system("cls");
    printf("\n########################################################## 밥 ##########################################################\n\n");

    for (i = 0; i < COOKS; i++)
    {
        printf("%30d.%s  ", i, p->rice[i].name);
    }
    printf("\n");
    printf("음식선택>>");
    scanf("%d", &select);

    result = p->rice[select];

    return result;
}

COOK noodle_4(TYPE* p)
{
    int i, select;
    COOK result;

    system("cls");
    printf("\n########################################################## 면 ##########################################################\n\n");

    for (i = 0; i < COOKS; i++)
    {
        printf("%30d.%s  ", i, p->noodle[i].name);
    }
    printf("\n");
    printf("음식선택>>");
    scanf("%d", &select);

    result = p->noodle[select];

    return result;
}

void create_cook(TYPE* cooktype) //음식이름, 재료, 레시피를 구조체에 저장하는 함수
{
    //찌개
    strcpy(cooktype->stew[0].name, "된장찌개"); //이름 저장
    strcpy(cooktype->stew[0].ingredient, "재료 : 멸치대자 10개, 다시마3조각, 된장2큰술, 고추가루 2스푼, 호박 작은 크기 1개, 감자 1개, 양파 반쪽, 무 조금, 청양고추 2~3개, 대파 반쪽"); //재료 저장
    strcpy(cooktype->stew[0].recipe, "1. 멸치, 다시마로 육수를 낸다./2. 된장을 풀고 호박, 감자, 양파, 무를 함께 넣고 끓인다./3. 청양고추, 대파, 고추가루를 넣고 끓인다."); //레시피 출력, / 단위로 잘림

    strcpy(cooktype->stew[1].name, "김치찌개");
    strcpy(cooktype->stew[1].ingredient, "재료: 찌개용 돼지고기, 자른김치, 된장 1스푼, 고추장 1스푼, 진간장 2스푼, 물 560ml, 두부, 다진마늘 1스푼, 양파, 대파");
    strcpy(cooktype->stew[1].recipe, "1. 냄비에 식용유 2-3스푼 두르고, 찌개용 돼지고기, 자른 김치, 된장, 고추장, 진간장을 넣고 볶아준다./2. 다진마늘, 양파, 대파를 넣고 볶아준다./3. 물을 부어주고 푹 끓여준다./4. 두부를 넣어준다./5.소금을 넣어 간을 맞춰준다."); //

    //간편식
    strcpy(cooktype->easy[0].name, "샌드위치");
    strcpy(cooktype->easy[0].ingredient, "재료: 식빵 2개, 계란 개, 햄(식빵크기로 자른 것), 치즈 2장, 샐러드용 자른 채소 듬뿍, 잼");
    strcpy(cooktype->easy[0].recipe, "1. 식빵, 햄, 계란을 구워준다./2. 구운 식빵에 잼을 발라준다./3. 잼 위에 치즈, 햄, 계란등을 올려준다./4. 자른 채소들을 올려주고 식빵으로 덮는다.");

    strcpy(cooktype->easy[1].name, "떡볶이");
    strcpy(cooktype->easy[1].ingredient, "재료: 물, 고추장 2큰술, 쌀 떡, 진간장 2숟갈, 고추가루 2숟갈, 물엿 2숟갈, 설탕, 대파, 오뎅 , 삶은 달걀");
    strcpy(cooktype->easy[1].recipe, "1. 물 300ml에 고추장, 고추가루, 진간장 , 물엿으로 육수를 낸다./2. 쌀떡, 오뎅(어묵) 대파를 넣고 끓인다./3. 식성에 따라 만두, 사리면, 소시지 등을 넣고 끓여 먹으면 좋다.");

    //스페셜
    strcpy(cooktype->special[0].name, "오리고기");
    strcpy(cooktype->special[0].ingredient, "재료: 훈제오리 600g, 양파 1개, 파프리카  2개, 토마토 케첩, 쌈");
    strcpy(cooktype->special[0].recipe, "1. 파프리카, 훈제오리, 양파를 볶는다./2. 케첩과 후추를 뿌려서 쌈에 싸 먹는다.");

    strcpy(cooktype->special[1].name, "GS 편의점조합");
    strcpy(cooktype->special[1].ingredient, "재료: 자이언드 떡볶이, 컵라면 스파게티, 소세지, 치즈");
    strcpy(cooktype->special[1].recipe, "1. 떡과 소스,물을 용기에 담아 전자레인지에 1분 30초 조리한다./2. 컵라면 스파게티를 끓는 물에 3분 익혀주고, 물을 버린 뒤 동봉된 스프와 섞어준다./3. 떡볶이, 스파케티를 섞고, 소세지와 치즈를 그 위에 올려 전자레인지에 1분 조리해준다.");

    //밥
    strcpy(cooktype->rice[0].name, "김치볶음밥");
    strcpy(cooktype->rice[0].ingredient, "재료: 김치 반쪽, 양파 1개, 햄 1장, 대파, 설탕 1숟갈, 밥 1공기");
    strcpy(cooktype->rice[0].recipe, "1. 대파, 양파, 햄을 다져 준비해준다./2. 대파를 약불에 볶으며 파기름을 낸다./3. 김치와 양파, 햄, 참기름을 둘러 볶는다./4. 밥을 넣고 볶는다.");

    strcpy(cooktype->rice[1].name, "참치마요 덮밥");
    strcpy(cooktype->rice[1].ingredient, "재료: 참치 1캔, 계란 2개, 마요네즈, 밥 1공기, 데리야끼 소스, 김가루");
    strcpy(cooktype->rice[1].recipe, "1. 참치는 체에 걸러 기름을 빼준다./2. 계란은 잘 풀어서 스크램블로 만들어 준다./3. 그릇에 밥, 참치, 스크램블, 마요네즈, 데리야끼 소스, 김가루를 차례대로 올려주고 비벼준다.");

    //면
    strcpy(cooktype->noodle[0].name, "라멘");
    strcpy(cooktype->noodle[0].ingredient, "재료: 라면 (아무거나), 우유(250ml), 된장, 숙주");
    strcpy(cooktype->noodle[0].recipe, "1. 냄비에 물 250ml, 우유 250ml, 된장 1큰술, 고춧가루 반큰술, 라면 스프 반봉을 넣는다./2. 된장이 풀어지게끔 잘 저어 주면서 끓인다./3. 물이 끓어오르면 면과 건더기 스프를 넣는다./4. 불을 끄기 30초 전 숙주를 넣고 마무리 한다.");

    strcpy(cooktype->noodle[1].name, "토마토파스타");
    strcpy(cooktype->noodle[1].ingredient, "재료: 파스타면 80g, 시판 토마토소스 150g, 올리브유, 소금 반 스푼, 양파 반 개, 베이컨 3줄, 편마늘, 다진마늘");
    strcpy(cooktype->noodle[1].recipe, "1. 냄비에 물을 넣고 올리브유를 한 바퀴 둘러준 뒤 소금을 반 스푼 넣어준다. (면이 들러붙지 않게 하기 위해)/2. 물이 끓는 동안 베이컨 3줄과 양파 반개를 썰어준다. (큼직하게)/3. 물이 어느정도 끓으면 파스타면 80g(1인분)을 넣어준다. (5백원 크기 만큼!)/4. 면을 물속에 잠기게끔 넣어주고 가끔 저어주며 7분30초 동안 끓여준다./5. 후라이팬에 불을 키고 올리브유를 두른 뒤 마늘을 볶아준다. (중불로!)/6.마늘향이 올라오면 베이컨과 양파도 같이 볶아준다./7. 재료가 다 볶아지면 국자로 면수를 1회 넣어주고 바로 면발도 넣어준다./8. 마지막으로 소스를 넣고 골고루 섞어준다.");
}

void recipe_token_print(COOK* result) // /단위로 q를 입력하면 레시피를 출력해주는 함수
{
    char* token;
    char div[] = "/";
    char click;

    token = strtok(result->recipe, div); 
    while (token != NULL)
    {
        printf("다음단계(q)>>");
        if ((click = getch()) == 'q')
        {
            printf("%s\n\n", token);
            token = strtok(NULL, div);
        }
    }
}

void menu_2(MY* myinfor)
{
    char buffer[1]; //엔터키를 저장할 공간
    char recipe[100]; //strcat로 구조체 recipe 에 붙여주기 위해 사용할 변수

    system("cls");
    printf("\n");

    gets(buffer); 
    printf("################################################## 나만의 레시피 등록 ##################################################\n\n");

    printf("1. 음식 이름을 입력해주세요: ");
    gets(myinfor->mycook[0].name);

    printf("\n2. 음식 재료를 입력해주세요: ");
    gets(myinfor->mycook[0].ingredient);

    printf("\n3-1. 레시피의 총 단계 수를 입력해주세요: ");
    scanf("%d", &myinfor->level);

    printf("\n3-2. 아래 예시에 따라 레시피를 입력해주세요\n");
    printf("예) 1.레시피입력/\n    2.레시피입력/\n");

    gets(buffer);
    printf(" >>>");
    gets(myinfor->mycook[0].recipe);

    for (int i = 1; i <= myinfor->level - 1; i++)
    {
        printf(" >>>");
        gets(recipe);
        strcat(myinfor->mycook[0].recipe, recipe);
    }

    system("cls");
    printf("\n");

    printf("**%s 님의 레시피가 등록이 완료되었습니다**\n", myinfor->nickname);
    printf("< %s의 레시피_( %s 님) >\n\n", myinfor->mycook[0].name, myinfor->nickname);
    printf("재료: %s\n\n", myinfor->mycook[0].ingredient);
    recipe_token_print(&myinfor->mycook[0]);

}
