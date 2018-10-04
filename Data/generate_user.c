//  
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    int i = 0, j = 0;
    char country[16][20] = {"Singapore","China","Isreal","German","United States","United Kingdom","Canada","Austrilia", "France", "Poland", "Italy", "Korea", "Finland","Russia","Japan","Netherlands"};
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

/*
 RESULTS:
 INSERT INTO users VALUES ('520932930@gmail.com','password', '520932930','ZHANPENG','GE','Isreal');
 INSERT INTO users VALUES ('16807@gmail.com','password', '16807','WEI XIANG','NGOO','Austrilia');
 INSERT INTO users VALUES ('33614@gmail.com','password', '33614','RAN','XING','Canada');
 INSERT INTO users VALUES ('50421@gmail.com','password', '50421','ENG CHYE','CHOY','United Kingdom');
 INSERT INTO users VALUES ('67228@gmail.com','password', '67228','GEK PING','XIE','United States');
 INSERT INTO users VALUES ('84035@gmail.com','password', '84035','HUI LING','WANG','German');
 INSERT INTO users VALUES ('100842@gmail.com','password', '100842','GEK PING','ZHOU','Isreal');
 INSERT INTO users VALUES ('117649@gmail.com','password', '117649','ANH QUANG','FANG','China');
 INSERT INTO users VALUES ('134456@gmail.com','password', '134456','ZHANPENG','PENG','Singapore');
 INSERT INTO users VALUES ('151263@gmail.com','password', '151263','QI','HUANG','Austrilia');
 INSERT INTO users VALUES ('168070@gmail.com','password', '168070','ZHANPENG','ZHENG','Canada');
 INSERT INTO users VALUES ('184877@gmail.com','password', '184877','JIAYUAN','DING','United Kingdom');
 INSERT INTO users VALUES ('201684@gmail.com','password', '201684','HAN','HUANG','United States');
 INSERT INTO users VALUES ('218491@gmail.com','password', '218491','HUI YING','GOH','German');
 INSERT INTO users VALUES ('235298@gmail.com','password', '235298','HUICHAN','NG','Isreal');
 INSERT INTO users VALUES ('252105@gmail.com','password', '252105','WENXIN','GE','China');
 INSERT INTO users VALUES ('268912@gmail.com','password', '268912','ZHEMIN','NGOO','Singapore');
 INSERT INTO users VALUES ('285719@gmail.com','password', '285719','XIN','XING','Austrilia');
 INSERT INTO users VALUES ('302526@gmail.com','password', '302526','NA','CHOY','Canada');
 INSERT INTO users VALUES ('319333@gmail.com','password', '319333','KUAN CHONG','XIE','United Kingdom');
 INSERT INTO users VALUES ('336140@gmail.com','password', '336140','YUWEI','WANG','United States');
 INSERT INTO users VALUES ('352947@gmail.com','password', '352947','WEI XIANG','ZHOU','German');
 INSERT INTO users VALUES ('369754@gmail.com','password', '369754','RAN','FANG','Isreal');
 INSERT INTO users VALUES ('386561@gmail.com','password', '386561','ENG CHYE','PENG','China');
 INSERT INTO users VALUES ('403368@gmail.com','password', '403368','GEK PING','HUANG','Singapore');
 INSERT INTO users VALUES ('420175@gmail.com','password', '420175','HUI LING','ZHENG','Austrilia');
 INSERT INTO users VALUES ('436982@gmail.com','password', '436982','GEK PING','DING','Canada');
 INSERT INTO users VALUES ('453789@gmail.com','password', '453789','ANH QUANG','HUANG','United Kingdom');
 INSERT INTO users VALUES ('470596@gmail.com','password', '470596','ZHANPENG','GOH','United States');
 INSERT INTO users VALUES ('487403@gmail.com','password', '487403','QI','NG','German');
 INSERT INTO users VALUES ('504210@gmail.com','password', '504210','ZHANPENG','GE','Isreal');
 INSERT INTO users VALUES ('521017@gmail.com','password', '521017','JIAYUAN','NGOO','China');
 INSERT INTO users VALUES ('537824@gmail.com','password', '537824','HAN','XING','Singapore');
 INSERT INTO users VALUES ('554631@gmail.com','password', '554631','HUI YING','CHOY','Austrilia');
 INSERT INTO users VALUES ('571438@gmail.com','password', '571438','HUICHAN','XIE','Canada');
 INSERT INTO users VALUES ('588245@gmail.com','password', '588245','WENXIN','WANG','United Kingdom');
 INSERT INTO users VALUES ('605052@gmail.com','password', '605052','ZHEMIN','ZHOU','United States');
 INSERT INTO users VALUES ('621859@gmail.com','password', '621859','XIN','FANG','German');
 INSERT INTO users VALUES ('638666@gmail.com','password', '638666','NA','PENG','Isreal');
 INSERT INTO users VALUES ('655473@gmail.com','password', '655473','KUAN CHONG','HUANG','China');
 */
