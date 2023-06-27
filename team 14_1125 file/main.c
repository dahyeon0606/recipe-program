
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

//�޴�1�� ���Ǵ� �Լ���
void menu_1(TYPE cooktype);
void print_type(char** cooks_type);
void recipe_token_print(COOK* result);

COOK stew_0(TYPE* p);
COOK easy_1(TYPE* p);
COOK special_2(TYPE* p);
COOK rice_3(TYPE* p);
COOK noodle_4(TYPE* p);

//�޴�2�� ���Ǵ� �Լ���
void menu_2(MY* myinfor);



//���� �Լ�
int main(void)
{
    TYPE cooktype;
    MENU menus;
    MY myinfor; 

    create_cook(&cooktype);
    file_print();

    printf("\n�г����� �Է����ּ���: ");
    gets(myinfor.nickname); 
    system("cls");
    printf("%s��, ȯ���մϴ� :)\n", myinfor.nickname);

    while (1)
    {
      
        printf("\n======================�޴�======================\n              1. ������ ����\n              2. ������ ������\n              3. ���α׷� ����\n");
        printf("��ȣ�� �Է����ּ���>> ");
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
            printf("\n�̿��� �ּż� �����մϴ� :)\n");
            return 0;

        default:
            printf("\n**��ȣ�� �ٽ� �Է����ּ���**");
        }

    }
    return 0;
}

void menu_1(TYPE cooktype)
{
    int select; //�������� ���� 0~4��
    char* cooks_type[] = { "0. �","1. �����","2. ����ȸ޴�","3. ��","4. ��" }; //������ ������ �迭�� �������� ����
    COOK result; //��������� ������ ����
    COOK(*cook_select[COOKTYPE])(TYPE * p) = { stew_0 ,easy_1,special_2,rice_3,noodle_4 }; //�Լ� ������ �迭

    system("cls");
    printf("\n");

    print_type(cooks_type); //���� ���� ���
    scanf("%d", &select);

    result = cook_select[select](&cooktype); //����ڰ� ������ ���� ���� �Լ��� ȣ����, �μ��δ� ����ü�� �ּҸ� �ѱ�, ������ ������ ����ü ��ȯ

    system("cls");
    printf("\n");

    printf("< %s�� ������ >\n\n", result.name);
    printf("%s\n\n", result.ingredient);
    recipe_token_print(&result); // /������ ������ ������ ���

    printf("�ϼ�! �����ϼ̽��ϴ�.\n");

}

void file_print() //�丮�� ���� ������ִ� �Լ�
{
    char line[255];

    FILE* file = fopen("cooker.txt", "r");
    if (file == NULL) {
        printf("���Ͽ��� ����\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}

void print_type(char** cooks_type) //���� ���� ������ִ� �Լ�
{
    int i;

    printf("------------------------------------------------------------------------------------------------------------------------\n");
    for (i = 0; i < COOKTYPE; i++)
    {
        printf("%20s  ", cooks_type[i]);
    }
    printf("\n------------------------------------------------------------------------------------------------------------------------\n");
    printf("�޴�����>> ");
}

COOK stew_0(TYPE* p) //���ĸ��� ����ϰ� ������ �����ϵ��� �ϴ� �Լ�, ���������� ���õ� �޴��� ����ü�� ��ȯ��
{
    int i, select;
    COOK result;

    system("cls");
    printf("\n########################################################## � ########################################################\n\n");

    for (i = 0; i < COOKS; i++)
    {
        printf("%30d.%s  ", i, p->stew[i].name);
    }
    printf("\n");
    printf("���ļ���>>");
    scanf("%d", &select);

    result = p->stew[select];

    return result;

}

COOK easy_1(TYPE* p)
{
    int i, select;
    COOK result;

    system("cls");
    printf("\n######################################################## ����� ########################################################\n\n");

    for (i = 0; i < COOKS; i++)
    {
        printf("%30d.%s  ", i, p->easy[i].name);
    }
    printf("\n");
    printf("���ļ���>>");
    scanf("%d", &select);

    result = p->easy[select];

    return result;
}

COOK special_2(TYPE* p)
{
    int i, select;
    COOK result;

    system("cls");
    printf("\n###################################################### ����ȸ޴� ######################################################\n\n");

    for (i = 0; i < COOKS; i++)
    {
        printf("%30d.%s  ", i, p->special[i].name);
    }
    printf("\n");
    printf("���ļ���>>");
    scanf("%d", &select);

    result = p->special[select];

    return result;
}

COOK rice_3(TYPE* p)
{
    int i, select;
    COOK result;

    system("cls");
    printf("\n########################################################## �� ##########################################################\n\n");

    for (i = 0; i < COOKS; i++)
    {
        printf("%30d.%s  ", i, p->rice[i].name);
    }
    printf("\n");
    printf("���ļ���>>");
    scanf("%d", &select);

    result = p->rice[select];

    return result;
}

COOK noodle_4(TYPE* p)
{
    int i, select;
    COOK result;

    system("cls");
    printf("\n########################################################## �� ##########################################################\n\n");

    for (i = 0; i < COOKS; i++)
    {
        printf("%30d.%s  ", i, p->noodle[i].name);
    }
    printf("\n");
    printf("���ļ���>>");
    scanf("%d", &select);

    result = p->noodle[select];

    return result;
}

void create_cook(TYPE* cooktype) //�����̸�, ���, �����Ǹ� ����ü�� �����ϴ� �Լ�
{
    //�
    strcpy(cooktype->stew[0].name, "�����"); //�̸� ����
    strcpy(cooktype->stew[0].ingredient, "��� : ��ġ���� 10��, �ٽø�3����, ����2ū��, ���߰��� 2��Ǭ, ȣ�� ���� ũ�� 1��, ���� 1��, ���� ����, �� ����, û����� 2~3��, ���� ����"); //��� ����
    strcpy(cooktype->stew[0].recipe, "1. ��ġ, �ٽø��� ������ ����./2. ������ Ǯ�� ȣ��, ����, ����, ���� �Բ� �ְ� ���δ�./3. û�����, ����, ���߰��縦 �ְ� ���δ�."); //������ ���, / ������ �߸�

    strcpy(cooktype->stew[1].name, "��ġ�");
    strcpy(cooktype->stew[1].ingredient, "���: ��� �������, �ڸ���ġ, ���� 1��Ǭ, ������ 1��Ǭ, ������ 2��Ǭ, �� 560ml, �κ�, �������� 1��Ǭ, ����, ����");
    strcpy(cooktype->stew[1].recipe, "1. ���� �Ŀ��� 2-3��Ǭ �θ���, ��� �������, �ڸ� ��ġ, ����, ������, �������� �ְ� �����ش�./2. ��������, ����, ���ĸ� �ְ� �����ش�./3. ���� �ξ��ְ� ǫ �����ش�./4. �κθ� �־��ش�./5.�ұ��� �־� ���� �����ش�."); //

    //�����
    strcpy(cooktype->easy[0].name, "������ġ");
    strcpy(cooktype->easy[0].ingredient, "���: �Ļ� 2��, ��� ��, ��(�Ļ�ũ��� �ڸ� ��), ġ�� 2��, ������� �ڸ� ä�� ���, ��");
    strcpy(cooktype->easy[0].recipe, "1. �Ļ�, ��, ����� �����ش�./2. ���� �Ļ��� ���� �߶��ش�./3. �� ���� ġ��, ��, ������� �÷��ش�./4. �ڸ� ä�ҵ��� �÷��ְ� �Ļ����� ���´�.");

    strcpy(cooktype->easy[1].name, "������");
    strcpy(cooktype->easy[1].ingredient, "���: ��, ������ 2ū��, �� ��, ������ 2����, ���߰��� 2����, ���� 2����, ����, ����, ���� , ���� �ް�");
    strcpy(cooktype->easy[1].recipe, "1. �� 300ml�� ������, ���߰���, ������ , �������� ������ ����./2. �Ҷ�, ����(�) ���ĸ� �ְ� ���δ�./3. �ļ��� ���� ����, �縮��, �ҽ��� ���� �ְ� ���� ������ ����.");

    //�����
    strcpy(cooktype->special[0].name, "�������");
    strcpy(cooktype->special[0].ingredient, "���: �������� 600g, ���� 1��, ������ī  2��, �丶�� ��ø, ��");
    strcpy(cooktype->special[0].recipe, "1. ������ī, ��������, ���ĸ� ���´�./2. ��ø�� ���߸� �ѷ��� �ӿ� �� �Դ´�.");

    strcpy(cooktype->special[1].name, "GS ����������");
    strcpy(cooktype->special[1].ingredient, "���: ���̾�� ������, �Ŷ�� ���İ�Ƽ, �Ҽ���, ġ��");
    strcpy(cooktype->special[1].recipe, "1. ���� �ҽ�,���� ��⿡ ��� ���ڷ������� 1�� 30�� �����Ѵ�./2. �Ŷ�� ���İ�Ƽ�� ���� ���� 3�� �����ְ�, ���� ���� �� ������ ������ �����ش�./3. ������, ������Ƽ�� ����, �Ҽ����� ġ� �� ���� �÷� ���ڷ������� 1�� �������ش�.");

    //��
    strcpy(cooktype->rice[0].name, "��ġ������");
    strcpy(cooktype->rice[0].ingredient, "���: ��ġ ����, ���� 1��, �� 1��, ����, ���� 1����, �� 1����");
    strcpy(cooktype->rice[0].recipe, "1. ����, ����, ���� ���� �غ����ش�./2. ���ĸ� ��ҿ� ������ �ı⸧�� ����./3. ��ġ�� ����, ��, ���⸧�� �ѷ� ���´�./4. ���� �ְ� ���´�.");

    strcpy(cooktype->rice[1].name, "��ġ���� ����");
    strcpy(cooktype->rice[1].ingredient, "���: ��ġ 1ĵ, ��� 2��, �������, �� 1����, �����߳� �ҽ�, �谡��");
    strcpy(cooktype->rice[1].recipe, "1. ��ġ�� ü�� �ɷ� �⸧�� ���ش�./2. ����� �� Ǯ� ��ũ����� ����� �ش�./3. �׸��� ��, ��ġ, ��ũ����, �������, �����߳� �ҽ�, �谡�縦 ���ʴ�� �÷��ְ� ���ش�.");

    //��
    strcpy(cooktype->noodle[0].name, "���");
    strcpy(cooktype->noodle[0].ingredient, "���: ��� (�ƹ��ų�), ����(250ml), ����, ����");
    strcpy(cooktype->noodle[0].recipe, "1. ���� �� 250ml, ���� 250ml, ���� 1ū��, ���尡�� ��ū��, ��� ���� �ݺ��� �ִ´�./2. ������ Ǯ�����Բ� �� ���� �ָ鼭 ���δ�./3. ���� ��������� ��� �Ǵ��� ������ �ִ´�./4. ���� ���� 30�� �� ���ָ� �ְ� ������ �Ѵ�.");

    strcpy(cooktype->noodle[1].name, "�丶���Ľ�Ÿ");
    strcpy(cooktype->noodle[1].ingredient, "���: �Ľ�Ÿ�� 80g, ���� �丶��ҽ� 150g, �ø�����, �ұ� �� ��Ǭ, ���� �� ��, ������ 3��, ����, ��������");
    strcpy(cooktype->noodle[1].recipe, "1. ���� ���� �ְ� �ø������� �� ���� �ѷ��� �� �ұ��� �� ��Ǭ �־��ش�. (���� �鷯���� �ʰ� �ϱ� ����)/2. ���� ���� ���� ������ 3�ٰ� ���� �ݰ��� ����ش�. (ŭ���ϰ�)/3. ���� ������� ������ �Ľ�Ÿ�� 80g(1�κ�)�� �־��ش�. (5��� ũ�� ��ŭ!)/4. ���� ���ӿ� ���Բ� �־��ְ� ���� �����ָ� 7��30�� ���� �����ش�./5. �Ķ����ҿ� ���� Ű�� �ø������� �θ� �� ������ �����ش�. (�ߺҷ�!)/6.�������� �ö���� �������� ���ĵ� ���� �����ش�./7. ��ᰡ �� �������� ���ڷ� ����� 1ȸ �־��ְ� �ٷ� ��ߵ� �־��ش�./8. ���������� �ҽ��� �ְ� ���� �����ش�.");
}

void recipe_token_print(COOK* result) // /������ q�� �Է��ϸ� �����Ǹ� ������ִ� �Լ�
{
    char* token;
    char div[] = "/";
    char click;

    token = strtok(result->recipe, div); 
    while (token != NULL)
    {
        printf("�����ܰ�(q)>>");
        if ((click = getch()) == 'q')
        {
            printf("%s\n\n", token);
            token = strtok(NULL, div);
        }
    }
}

void menu_2(MY* myinfor)
{
    char buffer[1]; //����Ű�� ������ ����
    char recipe[100]; //strcat�� ����ü recipe �� �ٿ��ֱ� ���� ����� ����

    system("cls");
    printf("\n");

    gets(buffer); 
    printf("################################################## ������ ������ ��� ##################################################\n\n");

    printf("1. ���� �̸��� �Է����ּ���: ");
    gets(myinfor->mycook[0].name);

    printf("\n2. ���� ��Ḧ �Է����ּ���: ");
    gets(myinfor->mycook[0].ingredient);

    printf("\n3-1. �������� �� �ܰ� ���� �Է����ּ���: ");
    scanf("%d", &myinfor->level);

    printf("\n3-2. �Ʒ� ���ÿ� ���� �����Ǹ� �Է����ּ���\n");
    printf("��) 1.�������Է�/\n    2.�������Է�/\n");

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

    printf("**%s ���� �����ǰ� ����� �Ϸ�Ǿ����ϴ�**\n", myinfor->nickname);
    printf("< %s�� ������_( %s ��) >\n\n", myinfor->mycook[0].name, myinfor->nickname);
    printf("���: %s\n\n", myinfor->mycook[0].ingredient);
    recipe_token_print(&myinfor->mycook[0]);

}
