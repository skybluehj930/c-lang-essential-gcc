#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long bigint;

typedef struct _User {
    struct _User* link;
    bigint user_id;
    char username[256];
    int age;
    char email[256];
} User;

void input_user_info(User* user) {
    printf("email: ");
    scanf("%s", &(*user).email);
    printf("name: ");
    scanf("%s", &(*user).username);
    printf("age: ");
    scanf("%d", &(*user).age);
}

User *find_last_user(User* users) 
{
    User *cur; 
    cur = users;
    while (cur->link != NULL)
    {
        cur = cur->link;
    }
    return cur;
}

void regist_user(User* users, bigint idx) 
{  
    User* new_user = (User*) calloc(1, sizeof(User));
    new_user->user_id = idx;
    input_user_info(new_user);
    User* last_user = find_last_user(users);
    last_user->link = new_user;
}

void search_user(User* users) 
{
    User* cur = users;
    while (1) 
    {      
        if(cur->link == NULL) break;
        else {
            cur = cur->link;
            printf("userId: %d, email: %s, username: %s, age: %d\n", cur->user_id, cur->email, cur->username, cur->age);
        }
    }
}

void modify_user(User* users) 
{
    bigint user_id;
    printf("userId: ");
    scanf("%llu", &user_id);

    int find_flag = 0; 
    User* cur = users;

    while (1) 
    {
        if (cur->user_id == user_id) {
            input_user_info(cur);
            find_flag = 1;
            break;
        }

        if (cur->link == NULL) break;
        else cur = cur->link;
    }

    if (find_flag == 0) printf("not find user %d", user_id);
}

void remove_user(User* users) 
{
    bigint user_id;
    printf("userId: ");
    scanf("%llu", &user_id);

    int find_flag = 0; 
    User* cur = users;
    User* prev;

    while (1) 
    {
        if (cur->user_id == user_id) {
            prev->link = cur->link;
            find_flag = 1;
            free(cur);
            break;
        }

        if (cur->link == NULL) break;
        else { 
            prev = cur;
            cur = cur->link;
        }
    }

    if (find_flag == 0) printf("not find user %d", user_id);
}

int main() {
    bigint idx = 1;
    User* users = (User*) calloc(1, sizeof(User));
    int num = 0;
    while (num != 5)
    {
        printf("[ 1. regist | 2. search | 3. modify | 4. remove | 5. end ]\n");
        printf("input num: ");
        scanf("%d", &num);
        switch (num)
        {
            case 1:
                regist_user(users, idx++);
                printf("\n");
                break;
            case 2:
                search_user(users);
                printf("\n");
                break;
            case 3:
                modify_user(users);
                printf("\n");
                break;
            case 4:
                remove_user(users);
                printf("\n");
                break;
            default:
                if (num != 5) {
                    printf("misspelled");
                    printf("\n");
                } else {
                    printf("bye~");
                }
        }   
    }
    free(users);
    return 0;
}