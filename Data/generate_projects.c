//
//  generate_projects.c
//  cs2102_project
//
//  Created by Cooper's pro on 4/10/18.
//  Copyright © 2018 Cooper's pro. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//char* itoa(int, char* , int);
int main()
{
    int i, j, k;
    char title[100][50] = {"", "", "", ""};//ADD TITLE HERE !!!
    char website[100][50] = {"", "", "", "", ""};//ADD WEBSITE HERE!!!
    char description[100][50] = {"", "","", ""};//ADD DESCRIPTION HERE!!!
    char status[2][10] = {"ONGOING", "FINISHED"};
    char country[16][20] = {"Singapore","China","Isreal","German","United States","United Kingdom","Canada","Austrilia", "France", "Poland", "Italy", "Korea", "Finland","Russia","Japan","Netherlands"};
    char city[26][10], c[2];
    char email[20][50], e[15] = "@gmail.com";e[10] = '\0';
    
    //set up city
    for(i = 0; i < 26; i++) {
        strcpy(city[i], "city");
        c[0] = 'A' + i; c[1] = '\0';
        strcat(city[i], c);
        //printf("%s \n", city[i]);
    }
    
    //set up email
    for(i = 0;i < 20;i++) {
        srand(i);//so that it can references to users table
        //itoa(rand(), city[i], 10);
        sprintf(email[i], "%d" , rand());
        strcat(email[i], e);
    }
    
    for(i = 0;i < 50;i ++) {
        srand(i);
        j = rand();
        k = 0;
        if(j % 20 == 0) k = 1;
        printf("INSERT INTO project_initiated_by VALUES(DEFAULT, '%s', '%s', '%s','%d-%d-%d', %d, %d, %d, %d,'%s','%s','%s', '%s'); \n",title[i], website[i], description[i], j%8 + 2010, j%12 + 1, j%28 + 1, j%60, 0, 0, j%100 * 100000,status[k],country[j%16], city[j%26], email[i%20]);
    }
}


/*
RESULTS (NOT FINISHED YET!)
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2012-7-15', 30, 0, 0, 3000000,'ONGOING','Isreal','cityY', '520932930@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-8-8', 7, 0, 0, 700000,'ONGOING','Austrilia','cityL', '16807@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-3-15', 14, 0, 0, 1400000,'ONGOING','Japan','cityW', '33614@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2015-10-22', 21, 0, 0, 2100000,'ONGOING','United Kingdom','cityH', '50421@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2014-5-1', 28, 0, 0, 2800000,'ONGOING','Finland','cityS', '67228@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2013-12-8', 35, 0, 0, 3500000,'ONGOING','German','cityD', '84035@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2012-7-15', 42, 0, 0, 4200000,'ONGOING','Italy','cityO', '100842@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2011-2-22', 49, 0, 0, 4900000,'ONGOING','China','cityZ', '117649@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2010-9-1', 56, 0, 0, 5600000,'ONGOING','France','cityK', '134456@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-4-8', 3, 0, 0, 6300000,'ONGOING','Netherlands','cityV', '151263@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-11-15', 10, 0, 0, 7000000,'ONGOING','Canada','cityG', '168070@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2015-6-22', 17, 0, 0, 7700000,'ONGOING','Russia','cityR', '184877@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2014-1-1', 24, 0, 0, 8400000,'ONGOING','United States','cityC', '201684@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2013-8-8', 31, 0, 0, 9100000,'ONGOING','Korea','cityN', '218491@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2012-3-15', 38, 0, 0, 9800000,'ONGOING','Isreal','cityY', '235298@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2011-10-22', 45, 0, 0, 500000,'ONGOING','Poland','cityJ', '252105@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2010-5-1', 52, 0, 0, 1200000,'ONGOING','Singapore','cityU', '268912@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-12-8', 59, 0, 0, 1900000,'ONGOING','Austrilia','cityF', '285719@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-7-15', 6, 0, 0, 2600000,'ONGOING','Japan','cityQ', '302526@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2015-2-22', 13, 0, 0, 3300000,'ONGOING','United Kingdom','cityB', '319333@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2014-9-1', 20, 0, 0, 4000000,'FINISHED','Finland','cityM', '520932930@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2013-4-8', 27, 0, 0, 4700000,'ONGOING','German','cityX', '16807@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2012-11-15', 34, 0, 0, 5400000,'ONGOING','Italy','cityI', '33614@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2011-6-22', 41, 0, 0, 6100000,'ONGOING','China','cityT', '50421@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2010-1-1', 48, 0, 0, 6800000,'ONGOING','France','cityE', '67228@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-8-8', 55, 0, 0, 7500000,'ONGOING','Netherlands','cityP', '84035@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-3-15', 2, 0, 0, 8200000,'ONGOING','Canada','cityA', '100842@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2015-10-22', 9, 0, 0, 8900000,'ONGOING','Russia','cityL', '117649@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2014-5-1', 16, 0, 0, 9600000,'ONGOING','United States','cityW', '134456@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2013-12-8', 23, 0, 0, 300000,'ONGOING','Korea','cityH', '151263@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2012-7-15', 30, 0, 0, 1000000,'ONGOING','Isreal','cityS', '168070@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2011-2-22', 37, 0, 0, 1700000,'ONGOING','Poland','cityD', '184877@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2010-9-1', 44, 0, 0, 2400000,'ONGOING','Singapore','cityO', '201684@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-4-8', 51, 0, 0, 3100000,'ONGOING','Austrilia','cityZ', '218491@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-11-15', 58, 0, 0, 3800000,'ONGOING','Japan','cityK', '235298@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2015-6-22', 5, 0, 0, 4500000,'ONGOING','United Kingdom','cityV', '252105@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2014-1-1', 12, 0, 0, 5200000,'ONGOING','Finland','cityG', '268912@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2013-8-8', 19, 0, 0, 5900000,'ONGOING','German','cityR', '285719@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2012-3-15', 26, 0, 0, 6600000,'ONGOING','Italy','cityC', '302526@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2011-10-22', 33, 0, 0, 7300000,'ONGOING','China','cityN', '319333@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2010-5-1', 40, 0, 0, 8000000,'FINISHED','France','cityY', '520932930@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-12-8', 47, 0, 0, 8700000,'ONGOING','Netherlands','cityJ', '16807@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-7-15', 54, 0, 0, 9400000,'ONGOING','Canada','cityU', '33614@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2015-2-22', 1, 0, 0, 100000,'ONGOING','Russia','cityF', '50421@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2014-9-1', 8, 0, 0, 800000,'ONGOING','United States','cityQ', '67228@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2013-4-8', 15, 0, 0, 1500000,'ONGOING','Korea','cityB', '84035@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2012-11-15', 22, 0, 0, 2200000,'ONGOING','Isreal','cityM', '100842@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2011-6-22', 29, 0, 0, 2900000,'ONGOING','Poland','cityX', '117649@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2010-1-1', 36, 0, 0, 3600000,'ONGOING','Singapore','cityI', '134456@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-8-8', 43, 0, 0, 4300000,'ONGOING','Austrilia','cityT', '151263@gmail.com');
 */






