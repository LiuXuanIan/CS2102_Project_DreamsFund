//  
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    int i = 0, j = 0;
    char country[10][15] = {"Singapore\0","China\0","Isreal\0","German\0","America\0","UK\0","Canada\0","Austrilia"};
    char first_name[25][15] = {"YUWEI","ENG CHYE", "GEK PING", "QI", "HAN", "WENXIN", "NA", "WEI XIANG", "GEK PING",
                               "ANH QUANG", "ZHANPENG", "HUI YING", "ZHEMIN", "KUAN CHONG", "RAN", "HUI LING", "ZHANPENG",
                               "JIAYUAN", "HUICHAN", "XIN"
    };
    char last_name[20][15] = {"GE", "GOH", "DING", "HUANG", "FANG",
                              "WANG", "CHOY", "NGOO", "NG", "HUANG",
                              "ZHENG", "PENG", "ZHOU", "XIE", "XING"};
    for(i = 0;i < 40; i++) {
        srand(i);
        j = rand();
        printf("INSERT INTO users VALUES (\'%d@gmail.com\',\'password\', \'%d\',\'%s\',\'%s\',\'%s\');\n", j,j,first_name[j%20],last_name[j%15],&country[j%8][0]);
    }
}
