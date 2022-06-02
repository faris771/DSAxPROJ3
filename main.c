/**
 * AUTHOR:FARIS ABUFARHA
 * ID:1200546
 * SEC:3
 * REPO LINK: https://github.com/faris771/DSAxPROJ3
 * IDE: JETBRAINS CLION
 * COMPILER: gcc
 * OS: LINUX UBUNTU
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*
 *
 *        Color Codes
Black: \033[0;30m
Red: \033[0;31m
Green: \033[0;32m
Yellow: \033[0;33m
Blue: \033[0;34m
Magenta: \033[0;35m
Cyan: \033[0;36m
White: \033[0;37m
        Style
Normal: \033[0;3?m
Bold:   \033[1;3?m
Reset: \033[0m
*/

#define null NULL
#define MAX_STRING 250
#define MAX_LINE 1000

typedef char String[MAX_STRING];

// styling
// \033 is the escape sequence  [1;31m is the color

void red() {
    printf("\033[1;31m");
}

void blue() {
    printf("\033[0;34m");

}

void yellow() {
    printf("\033[1;33m");
}

void cyan() {
    printf("\033[0;36m");
}

void green() {
    printf("\033[0;32m");

}

void bold() {
    printf("\033[1;3?m");
}

void reset() {
    printf("\033[0m");
}

void line() {
    bold();
    printf("================================================================\n");
    reset();
}

void welcome() {
    yellow();
    printf("                 _                              \n"
           "                | |                             \n"
           " __      __ ___ | |  ___  ___   _ __ ___    ___ \n"
           " \\ \\ /\\ / // _ \\| | / __|/ _ \\ | '_ ` _ \\  / _ \\\n"
           "  \\ V  V /|  __/| || (__| (_) || | | | | ||  __/\n"
           "   \\_/\\_/  \\___||_| \\___|\\___/ |_| |_| |_| \\___|\n"
           "                                                \n"
           "                                                \n");

    reset();

}

void memoryMsg() {
    red();
    printf("OUT OF MEMORY!\n");
    reset();
}

char *trimString(char *str) {  //FREE
    size_t len = strlen(str);

    while (isspace(str[len - 1])) --len;
    while (*str && isspace(*str)) ++str, --len;

    return strndup(str, len);
}

//list functions



//  =================================================LIST FUNCTIONS AND STUFF==================================
typedef struct listNode {

    String topic;
    struct listNode *next;


} listNode;

typedef listNode *pNode;


typedef struct intList{

    int indx;
    struct  intLis * next;
}intList;

typedef intList * pIntList;







bool isEmptyList(listNode *head) {
    if (head->next == null) {

        return true;

    }
    else {
        return false;
    }


}

//n is a pointer to our wanted listNode
bool isLastList(listNode *n, listNode *head) {

    return n->next == null;

}


int sizeOfList(listNode *head) {

    int cnt = 0;
    for (listNode *iter = head->next; iter != NULL; iter = iter->next) {
        cnt++;
    }


    return cnt;

}

void deleteList(listNode *head) {
    listNode *tmp = null;
    for (listNode *iter = head->next; iter != NULL;) {

        tmp = iter;
        iter = iter->next;
        tmp->next = null;
        free(tmp);

    }

    head->next = null;

}

listNode *findPrevNodeList(String x, listNode *head) {
    listNode *i = null;

    for (i = head; i != null && strcmp(i->next->topic, x) != 0; i = i->next) {

    }

    printf("prev\n");
    return i;

}

void printList(listNode *head) {
    if (isEmptyList(head)) {
        printf("empty List\n");
        return;
    }
    for (listNode *iter = head->next; iter != NULL; iter = iter->next) {
        printf("%s   ", iter->topic);

    }
    printf("\n");
}

void insertAtNodeList(String x, listNode *head, listNode *p) {

    listNode *tmp = malloc(sizeof(listNode));

    strcpy(tmp->topic, x);
    tmp->next = p->next;
    p->next = tmp;

}

void insertAtEndList(String x, listNode *head) {
    listNode *newNode = malloc(sizeof(listNode));
    if (newNode == null) {
        printf("out of memory!\n");
        exit(1);
    }

    strcpy(newNode->topic, x);
    newNode->next = null;

    pNode tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = newNode;
}

void deleteNodeList(String x, listNode *head) {

    bool isLast;

    for (pNode i = head; i->next != null; i = i->next) {

        if (strcmp(i->next->topic, x) == 0) {
            pNode newTmp = null;
            newTmp = i->next;

            i->next = newTmp->next;
            free(newTmp);
            printf("\033[0;32m");
            printf("DELETED\n");
            printf("\033[0m");

            return;

        }

    }
    printf("\033[1;31m"); //GREEN

    printf("TOPIC NOT FOUND !\n");

    printf("\033[0m");


}


listNode *findNodeList(String x, listNode *head) {
    for (listNode *iter = head; iter != NULL; iter = iter->next) {

        if (strcmp(iter->topic, x) == 0) {
            printf("found\n");
            return iter;

        }

    }

    return null;

}

listNode *makeEmptyList(listNode *head) {

    if (head != null) {
        deleteList(head);
    }
    head = malloc(sizeof(listNode));
    head->next = null;


    return head;


}








//HASH STUFF
typedef struct hashNode {

    String courseName;//key
    String courseCode;
    int creditHours;
    String department;
    pNode topicsList;
    int flag;      //-1 deleted, 0 empty, 1 normal



}hashNode; //= {"","",0,"",null,0};


typedef hashNode * pHash;


int allPrimeArray [] = { 2,   3,   5,   7,   11,   13,   17,   19,   23,   29,   31,   37,   41,   43,   47,   53,   59,   61,   67,   71,   73,   79,   83,   89,   97,   101,   103,   107,   109,   113,   127,   131,   137,   139,   149,   151,   157,   163,   167,   173,   179,   181,   191,   193,   197,   199,   211,   223,   227,   229,   233,   239,   241,   251,   257,   263,   269,   271,   277,   281,   283,   293,   307,   311,   313,   317,   331,   337,   347,   349,   353,   359,   367,   373,   379,   383,   389,   397,   401,   409,   419,   421,   431,   433,   439,   443,   449,   457,   461,   463,   467,   479,   487,   491,   499,   503,   509,   521,   523,   541,   547,   557,   563,   569,   571,   577,   587,   593,   599,   601,   607,   613,   617,   619,   631,   641,   643,   647,   653,   659,   661,   673,   677,   683,   691,   701,   709,   719,   727,   733,   739,   743,   751,   757,   761,   769,   773,   787,   797,   809,   811,   821,   823,   827,   829,   839,   853,   857,   859,   863,   877,   881,   883,   887,   907,   911,   919,   929,   937,   941,   947,   953,   967,   971,   977,   983,   991,   997,   1009,   1013,   1019,   1021,   1031,   1033,   1039,   1049,   1051,   1061,   1063,   1069,   1087,   1091,   1093,   1097,   1103,   1109,   1117,   1123,   1129,   1151,   1153,   1163,   1171,   1181,   1187,   1193,   1201,   1213,   1217,   1223,   1229,   1231,   1237,   1249,   1259,   1277,   1279,   1283,   1289,   1291,   1297,   1301,   1303,   1307,   1319,   1321,   1327,   1361,   1367,   1373,   1381,   1399,   1409,   1423,   1427,   1429,   1433,   1439,   1447,   1451,   1453,   1459,   1471,   1481,   1483,   1487,   1489,   1493,   1499,   1511,   1523,   1531,   1543,   1549,   1553,   1559,   1567,   1571,   1579,   1583,   1597,   1601,   1607,   1609,   1613,   1619,   1621,   1627,   1637,   1657,   1663,   1667,   1669,   1693,   1697,   1699,   1709,   1721,   1723,   1733,   1741,   1747,   1753,   1759,   1777,   1783,   1787,   1789,   1801,   1811,   1823,   1831,   1847,   1861,   1867,   1871,   1873,   1877,   1879,   1889,   1901,   1907,   1913,   1931,   1933,   1949,   1951,   1973,   1979,   1987,   1993,   1997,   1999,   2003,   2011,   2017,   2027,   2029,   2039,   2053,   2063,   2069,   2081,   2083,   2087,   2089,   2099,   2111,   2113,   2129,   2131,   2137,   2141,   2143,   2153,   2161,   2179,   2203,   2207,   2213,   2221,   2237,   2239,   2243,   2251,   2267,   2269,   2273,   2281,   2287,   2293,   2297,   2309,   2311,   2333,   2339,   2341,   2347,   2351,   2357,   2371,   2377,   2381,   2383,   2389,   2393,   2399,   2411,   2417,   2423,   2437,   2441,   2447,   2459,   2467,   2473,   2477,   2503,   2521,   2531,   2539,   2543,   2549,   2551,   2557,   2579,   2591,   2593,   2609,   2617,   2621,   2633,   2647,   2657,   2659,   2663,   2671,   2677,   2683,   2687,   2689,   2693,   2699,   2707,   2711,   2713,   2719,   2729,   2731,   2741,   2749,   2753,   2767,   2777,   2789,   2791,   2797,   2801,   2803,   2819,   2833,   2837,   2843,   2851,   2857,   2861,   2879,   2887,   2897,   2903,   2909,   2917,   2927,   2939,   2953,   2957,   2963,   2969,   2971,   2999,   3001,   3011,   3019,   3023,   3037,   3041,   3049,   3061,   3067,   3079,   3083,   3089,   3109,   3119,   3121,   3137,   3163,   3167,   3169,   3181,   3187,   3191,   3203,   3209,   3217,   3221,   3229,   3251,   3253,   3257,   3259,   3271,   3299,   3301,   3307,   3313,   3319,   3323,   3329,   3331,   3343,   3347,   3359,   3361,   3371,   3373,   3389,   3391,   3407,   3413,   3433,   3449,   3457,   3461,   3463,   3467,   3469,   3491,   3499,   3511,   3517,   3527,   3529,   3533,   3539,   3541,   3547,   3557,   3559,   3571,   3581,   3583,   3593,   3607,   3613,   3617,   3623,   3631,   3637,   3643,   3659,   3671,   3673,   3677,   3691,   3697,   3701,   3709,   3719,   3727,   3733,   3739,   3761,   3767,   3769,   3779,   3793,   3797,   3803,   3821,   3823,   3833,   3847,   3851,   3853,   3863,   3877,   3881,   3889,   3907,   3911,   3917,   3919,   3923,   3929,   3931,   3943,   3947,   3967,   3989,   4001,   4003,   4007,   4013,   4019,   4021,   4027,   4049,   4051,   4057,   4073,   4079,   4091,   4093,   4099,   4111,   4127,   4129,   4133,   4139,   4153,   4157,   4159,   4177,   4201,   4211,   4217,   4219,   4229,   4231,   4241,   4243,   4253,   4259,   4261,   4271,   4273,   4283,   4289,   4297,   4327,   4337,   4339,   4349,   4357,   4363,   4373,   4391,   4397,   4409,   4421,   4423,   4441,   4447,   4451,   4457,   4463,   4481,   4483,   4493,   4507,   4513,   4517,   4519,   4523,   4547,   4549,   4561,   4567,   4583,   4591,   4597,   4603,   4621,   4637,   4639,   4643,   4649,   4651,   4657,   4663,   4673,   4679,   4691,   4703,   4721,   4723,   4729,   4733,   4751,   4759,   4783,   4787,   4789,   4793,   4799,   4801,   4813,   4817,   4831,   4861,   4871,   4877,   4889,   4903,   4909,   4919,   4931,   4933,   4937,   4943,   4951,   4957,   4967,   4969,   4973,   4987,   4993,   4999,   5003,   5009,   5011,   5021,   5023,   5039,   5051,   5059,   5077,   5081,   5087,   5099,   5101,   5107,   5113,   5119,   5147,   5153,   5167,   5171,   5179,   5189,   5197,   5209,   5227,   5231,   5233,   5237,   5261,   5273,   5279,   5281,   5297,   5303,   5309,   5323,   5333,   5347,   5351,   5381,   5387,   5393,   5399,   5407,   5413,   5417,   5419,   5431,   5437,   5441,   5443,   5449,   5471,   5477,   5479,   5483,   5501,   5503,   5507,   5519,   5521,   5527,   5531,   5557,   5563,   5569,   5573,   5581,   5591,   5623,   5639,   5641,   5647,   5651,   5653,   5657,   5659,   5669,   5683,   5689,   5693,   5701,   5711,   5717,   5737,   5741,   5743,   5749,   5779,   5783,   5791,   5801,   5807,   5813,   5821,   5827,   5839,   5843,   5849,   5851,   5857,   5861,   5867,   5869,   5879,   5881,   5897,   5903,   5923,   5927,   5939,   5953,   5981,   5987,   6007,   6011,   6029,   6037,   6043,   6047,   6053,   6067,   6073,   6079,   6089,   6091,   6101,   6113,   6121,   6131,   6133,   6143,   6151,   6163,   6173,   6197,   6199,   6203,   6211,   6217,   6221,   6229,   6247,   6257,   6263,   6269,   6271,   6277,   6287,   6299,   6301,   6311,   6317,   6323,   6329,   6337,   6343,   6353,   6359,   6361,   6367,   6373,   6379,   6389,   6397,   6421,   6427,   6449,   6451,   6469,   6473,   6481,   6491,   6521,   6529,   6547,   6551,   6553,   6563,   6569,   6571,   6577,   6581,   6599,   6607,   6619,   6637,   6653,   6659,   6661,   6673,   6679,   6689,   6691,   6701,   6703,   6709,   6719,   6733,   6737,   6761,   6763,   6779,   6781,   6791,   6793,   6803,   6823,   6827,   6829,   6833,   6841,   6857,   6863,   6869,   6871,   6883,   6899,   6907,   6911,   6917,   6947,   6949,   6959,   6961,   6967,   6971,   6977,   6983,   6991,   6997,   7001,   7013,   7019,   7027,   7039,   7043,   7057,   7069,   7079,   7103,   7109,   7121,   7127,   7129,   7151,   7159,   7177,   7187,   7193,   7207,   7211,   7213,   7219,   7229,   7237,   7243,   7247,   7253,   7283,   7297,   7307,   7309,   7321,   7331,   7333,   7349,   7351,   7369,   7393,   7411,   7417,   7433,   7451,   7457,   7459,   7477,   7481,   7487,   7489,   7499,   7507,   7517,   7523,   7529,   7537,   7541,   7547,   7549,   7559,   7561,   7573,   7577,   7583,   7589,   7591,   7603,   7607,   7621,   7639,   7643,   7649,   7669,   7673,   7681,   7687,   7691,   7699,   7703,   7717,   7723,   7727,   7741,   7753,   7757,   7759,   7789,   7793,   7817,   7823,   7829,   7841,   7853,   7867,   7873,   7877,   7879,   7883,   7901,   7907,   7919 };

pHash table1 = null;
pHash table2 = null;
int TABLE_CAP = 211; //initially
int TABLE_SIZE= 0;




void makeTable(hashNode **t);
void readFile();
int hash1(String s);
int hash2(String s);
void reHash();
void menu();

void cmd1();
void cmd2();
void cmd3();
void cmd4();
void cmd5();
void cmd6();
void cmd7();
void cmd8();
int searchT1(String s);
int searchT2(String s);





int main() {

    table1 = malloc(TABLE_CAP * sizeof(hashNode));
    for (int i = 0; i < TABLE_CAP; ++i) {
        table1[i].flag = 0;

    }
    table2 = malloc(TABLE_CAP * sizeof(hashNode));
    for (int i = 0; i < TABLE_CAP; ++i) {
        table2[i].flag = 0;

    }


    readFile();

    printf("%d\n", TABLE_SIZE);

    //    readFile();

    line();
    welcome();
    line();

    int ch;


    while (true) {

        menu();
        line();

        scanf("%d", &ch);

        if (ch == 1) {
            cmd1();
            line();
        }
        else if (ch == 2){
            cmd2();
            line();
        }
        else if (ch ==3 ){
            cmd3();

            line();
        }
        else if (ch ==4 ){
            cmd4();
            line();
        }
        else if (ch == 5){
            cmd5();
            line();
        }
        else if (ch == 6){
            cmd6();

            line();
        }else if (ch == 7){
            cmd7();

            line();
        }
        else if (ch == 8) {
            cmd8();
            line();
        }
        else if (ch == -1) {
            line();
            break;

        }

        else {
            red();
            printf("INVALID INPUT \n");
            reset();
            line();

        }



    }

    printf("THANK YOU COME AGAIN !!\n");











    return 0;
}

void menu(){
    printf("1. Print hashed tables (including empty spots).\n"
           "2. Print out table size and the load factor.\n"
           "3. Print out the used hash functions.\n"
           "4. Insert a new record to hash table (insertion will be done on\n"
           "both hash tables).\n"
           "5. Search for a specific word (specify which table to search in).\n"
           "6. Delete a specific record (from both tables).\n"
           "7. Compare between the two methods in terms of number of\n"
           "collisions occurred.\n"
           "8. Save hash table back to a file named saved_courses.txt (of the\n"
           "double hashing)\n"
           "-1. exit\n");

}




void makeTable(hashNode **t) {
    *t = malloc( TABLE_CAP * sizeof(hashNode));
    for (int i = 0; i < TABLE_CAP; ++i) {

        printf("tst\n");

    }
}


int hash1(String s) { // QUADRATIC

    int fun = 0;

    int sLen = strlen(s);
    for (int i = 0; i < sLen; ++i) {
        fun += (int)pow(31, sLen - 1 - i) * s[i];

    }

    int hashIndx;
    for (int i = 0; i < TABLE_CAP ; ++i) {
        hashIndx = abs((fun + (int)  pow(i, 2)) )% TABLE_CAP;
//
//        printf("asdsadsa %d\n", hashIndx);
//
//        printf("%d\n", table1[hashIndx].flag);


        if (table1[hashIndx].flag == 0 || table1[hashIndx].flag == -1) {

            printf("%d\n", hashIndx);
            return hashIndx;

        }

    }

//    return -1;


}

int hash2(String s) {
    int fun1 = 0;
    int fun2 = 0;


    int sLen = strlen(s);
    for (int i = 0; i < sLen; ++i) {
        fun1 += (int) pow(31, sLen - 1 - i) * s[i];

    }
    printf("%d\n", fun1);


     fun2 = (7 - (fun1 % 7));


    int indx = 0;
    for (int i = 0; i < TABLE_CAP; ++i) {
        indx = abs((fun1 + (i * fun2) )) % TABLE_CAP ;
        printf("dx  %d\n", indx);

        if (table2[indx].flag == 0 || table2[indx].flag == -1) {

            return indx;

        }


    }


}

void reHash() {
    if (TABLE_SIZE >= 0.5 * TABLE_CAP) {



    }

}

void readFile() {

    FILE *in = fopen("offered_courses.txt", "r");
    if (in == null) {
        red();
        printf("CAN'T READ FILE! \n");
        reset();
        return ;
    }
    String leftStr;
    String rightStr;
    String strCourseName, strHours, strCourseCode, strDep;
    String HCD;


    char buffer[MAX_LINE];

    int indx1;
    int indx2;
    while (fgets(buffer, MAX_LINE, in)) {
        printf("%s\n", buffer);

        if (buffer[strlen(buffer) - 1] == '\n') {
            buffer[strlen(buffer) - 1] = '\0';

        }
        strcpy(leftStr, strtok(buffer, "/"));//left of '/'
        strcpy(rightStr, strtok(null, "/"));//right

        //left stuff
        strcpy(strCourseName, trimString(strtok(leftStr, ":")));
        indx1 = hash1(strCourseName);
        indx2 = hash2(strCourseName);

        printf("tst\n");
        strcpy(table1[indx1].courseName, strCourseName);
        strcpy(table2[indx2].courseName, strCourseName);

        table1[indx1].flag = 1;
        table2[indx2].flag = 1;
        TABLE_SIZE += 1;
        printf("COURSE %s\n", strCourseName);
        printf("hsah1 %d  hash2 %d\n", indx1, indx2); // fine





        strcpy(HCD, trimString(strtok(null, ":")));//WORKING

        int hrs = atoi(strtok(HCD, "#"));
        table1[indx1].creditHours = hrs;
        table2[indx2].creditHours = hrs;



        strcpy(strCourseCode, trimString(strtok(null, "#")));
        strcpy(table1[indx1].courseCode, strCourseCode);
        strcpy(table2[indx2].courseCode, strCourseCode);


        strcpy(strDep, trimString(strtok(null, "#")));
        strcpy(table1[indx1].department, strDep);
        strcpy(table2[indx2].department, strDep);


        table1[indx1].topicsList= makeEmptyList(table1[indx1].topicsList);
        table2[indx2].topicsList= makeEmptyList(table2[indx2].topicsList);




        char *token = strtok(rightStr, ",");
        while (token != NULL) {

            //fixes new line in the last segment

            if (token[strlen(token) - 1] == '\n') {
                token[strlen(token) - 1] = '\0';
            }

            insertAtEndList(trimString(token), table1[indx1].topicsList);
            insertAtEndList(trimString(token), table2[indx2].topicsList);


            token = strtok(NULL, ",");
        }

    }


    fclose(in);

}

void cmd1() {
    //===================table 1 ====================
    cyan();
    printf("TABLE 1 : \n");
    reset();
    for (int i = 0; i < TABLE_CAP; ++i) {

        printf("BUCKET: %d :\t\t", i);
        if (table1[i].flag == 0 ) {

            red();
            printf(" -- ");
            reset();

        }
        else {
            blue();
            printf("%s", table1[i].courseName);
            reset();
        }
        printf("\n");


    }
    line();
    cyan();
    printf("TABLE 2 : \n");
    reset();
    for (int i = 0; i < TABLE_CAP; ++i) {

        printf("BUCKET: %d :\t\t",i);
        if (table2[i].flag == 0 ) {
            red();
            printf(" -- ");
            reset();

        }
        else {
            printf("%s", table2[i].courseName);
        }
        printf("\n");


    }






    //===================table 2 ====================

}

void cmd2() {
    printf("TABLE 1\n");
    printf("SIZE:  %d\n", TABLE_SIZE);
    printf("%.2f\n", (float) TABLE_SIZE / (float) TABLE_CAP);





}

void cmd3() {
    printf("QUADRATIC FUNCTION :         fun += (int)pow(31, sLen - 1 - i) * s[i] MOD TABLE_CAPACITY  ;\n");
    printf("where 0 <= i < TABLE_CAPACITY, sLen is string length \n");

    printf("DOUBLE HASHING FUNCTION: \n");
    printf("abs((fun1 + i * fun2) MOD TABLE_CAPACITY )\n");
    printf("where  0 <= i < TABLE CAPACITY, sLen is string length \n");

}

void cmd4() {
    String courseName;
    int dummyInt;

    printf("PLEASE INPUT COURSE NAME:\n");
    fgetc(stdin);
    fgets(courseName, MAX_STRING, stdin);
    if (courseName[strlen(courseName) - 1] == '\n') {
        courseName[strlen(courseName) - 1] = '\0';

    }

    int indx1 = hash1(courseName);
    int indx2 = hash2(courseName);
    printf("cmd4 %d  %d\n", indx1, indx2);


    String courseCode;
    int hrs;
    printf("ENTER: COURSE CODE, CREDIT HOURS RESPECTIVELY:\n");
    scanf("%s%d", courseCode, &hrs);

    String dep;
    fgetc(stdin);
    printf("DEPATMENT:\n");
    fgets(dep, MAX_STRING, stdin);
    if (dep[strlen(dep) - 1] == '\n') {
        dep[strlen(dep) - 1] = '\0';

    }

    String topicsStr;


    table1[indx1].topicsList = makeEmptyList(table1[indx1].topicsList);

    table2[indx2].topicsList = makeEmptyList(table2[indx2].topicsList);


    while (true) {
        printf("5.PLEASE INPUT TOPICS ONE BY ONE, OR PRESS -1 WHEN YOU ARE DONE\n");
        fflush(stdin);

        fgets(topicsStr, MAX_STRING, stdin);
        if (topicsStr[strlen(topicsStr) - 1] == '\n') {
            topicsStr[strlen(topicsStr) - 1] = '\0';

        }
        if (strcmp(trimString(topicsStr), "-1") == 0) {
            break;
        }

        insertAtEndList(topicsStr, table1[indx1].topicsList);
        insertAtEndList(topicsStr, table2[indx2].topicsList);



    }
    strcpy(table1[indx1].courseName, courseName);
    table1[indx1].flag = 1;
    table1[indx1].creditHours = hrs;
    strcpy(table1[indx1].courseCode, courseCode);
    strcpy(table1[indx1].department, dep);

    //table2

    strcpy(table2[indx2].courseName, courseName);
    table2[indx2].flag = 1; // occupied
    table2[indx2].creditHours = hrs;
    strcpy(table2[indx2].courseCode, courseCode);
    strcpy(table2[indx2].department, dep);

    TABLE_SIZE++;





}

void cmd5() {
    int ch;
    String name;


    printf("PLEASE INPUT COURSE NAME:\n");
    fgetc(stdin);
    fgets(name, MAX_STRING, stdin);
    if (name[strlen(name) - 1] == '\n') {
        name[strlen(name) - 1] = '\0';

    }

    a5:;
    printf("PLEASE CHOOSE WHICH TABLE TO SEARCH IN \n");
    printf("1))\n");
    printf("2))\n");
    scanf("%d", &ch);

    int indx;

    if (ch == 1) {
        indx = searchT1(name);
        if (indx >= 0) {
            printf("%d\n", indx);

        }
        else
            printf("NOT FOUND \n");

    }
    else if (ch == 2) {
        indx = searchT2(name);
        if (indx >= 0) {
            printf("%d\n", indx);

        }
        else
            printf("NOT FOUND \n");

    }
    else {
        printf("INVALID TABLE PLEASE TRY AGAIN!\n");
        goto a5;

    }




}

int searchT1(char *s) {
    int fun = 0;

    int sLen = strlen(s);
    for (int i = 0; i < sLen; ++i) {
        fun += (int) pow(31, sLen - 1 - i) * s[i];

    }

    int hashIndx;
    for (int i = 0; i < TABLE_CAP; ++i) {
        hashIndx = abs((fun + (int) pow(i, 2))) % TABLE_CAP;
//
//        printf("asdsadsa %d\n", hashIndx);
//
//        printf("%d\n", table1[hashIndx].flag);

        if (table1[hashIndx].flag == 0) {
            printf("NOT FOUND !\n");
            return  -5;


        }


        if (strcmp(table1[hashIndx].courseName, s) == 0) {

            return hashIndx;

        }


    }
    return -5;
}

int searchT2(char *s) {
    int fun1 = 0;
    int fun2 = 0;


    int sLen = strlen(s);
    for (int i = 0; i < sLen; ++i) {
        fun1 += (int) pow(31, sLen - 1 - i) * s[i];

    }


    for (int i = 0; i < sLen; ++i) {

        fun2 = ( fun2 << 5 ) +s[i];
    }

    int indx = 0;
    for (int i = 0; i < TABLE_CAP; ++i) {
        indx = abs((fun1 + i * fun2) % TABLE_CAP);

        if (table2[indx].flag == 0) {
            printf("NOT FOUND !\n");

        }


        if (strcmp(table2[indx].courseName, s) == 0) {

            return indx;

        }



    }
    return -5;
}

void cmd6() {
    String courseName;

    printf("PLEASE INPUT COURSE NAME YOU WISH TO DELETE\n");
    fgetc(stdin);
    fgets(courseName, MAX_STRING, stdin);

    int indx1 = searchT1(courseName);
    if (indx1 != -5) {
        table1[indx1].flag = -1;
        table1[indx1].topicsList = makeEmptyList(table1[indx1].topicsList);

    }
    else {
        red();
        printf("NOT FOUND IN TABLE1 !\n");
        reset();

    }
    int indx2 = searchT2(courseName);
    if (indx2 != -5) {

        table2[indx2].flag = -1;
        table2[indx2].topicsList = makeEmptyList(table2[indx2].topicsList);

    }
    else {
        red();
        printf("NOT FOUND IN TABLE1 !\n");
        reset();

    }





}

void cmd8() {
    FILE *out = fopen("saved_courses.txt", "w");



    for (int i = 0; i < TABLE_CAP; ++i) {

        if (table2[i].flag == 1) {
            fprintf(out, "%s:%d#%s#%s/",
                    table2[i].courseName, table2[i].creditHours, table2[i].courseCode, table2[i].department);

            listNode *iter = null;
            for (iter = table2[i].topicsList->next; iter->next != NULL; iter = iter->next) {
                fprintf(out, "%s, ", iter->topic);

            }
            fprintf(out, "%s ", iter->topic);

            fprintf(out, "\n");





        }
    }


}

