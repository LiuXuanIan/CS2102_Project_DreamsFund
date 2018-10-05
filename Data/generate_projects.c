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
    
    for(i = 0;i < 100;i ++) {
        srand(i);
        j = rand();
        k = 0;
        if(j % 20 == 0) k = 1;
        printf("INSERT INTO project_initiated_by VALUES(DEFAULT, '%s', '%s', '%s','%d-%d-%d', %d, %d, %d, %d,'%s','%s','%s', '%s'); \n",title[i], website[i], description[i], j%3 + 2016, j%12 + 1, j%28 + 1, j%30 + 10, 0, 0, j%100 * 100000,status[k],country[j%16], city[j%26], email[i%20]);
    }
}


/*
RESULTS (NOT FINISHED YET!)
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-7-15', 10, 0, 0, 3000000,'ONGOING','Isreal','cityY', '520932930@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-8-8', 17, 0, 0, 700000,'ONGOING','Austrilia','cityL', '16807@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-3-15', 24, 0, 0, 1400000,'ONGOING','Japan','cityW', '33614@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-10-22', 31, 0, 0, 2100000,'ONGOING','United Kingdom','cityH', '50421@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-5-1', 38, 0, 0, 2800000,'ONGOING','Finland','cityS', '67228@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-12-8', 15, 0, 0, 3500000,'ONGOING','German','cityD', '84035@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-7-15', 22, 0, 0, 4200000,'ONGOING','Italy','cityO', '100842@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-2-22', 29, 0, 0, 4900000,'ONGOING','China','cityZ', '117649@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-9-1', 36, 0, 0, 5600000,'ONGOING','France','cityK', '134456@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-4-8', 13, 0, 0, 6300000,'ONGOING','Netherlands','cityV', '151263@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-11-15', 20, 0, 0, 7000000,'ONGOING','Canada','cityG', '168070@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-6-22', 27, 0, 0, 7700000,'ONGOING','Russia','cityR', '184877@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-1-1', 34, 0, 0, 8400000,'ONGOING','United States','cityC', '201684@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-8-8', 11, 0, 0, 9100000,'ONGOING','Korea','cityN', '218491@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-3-15', 18, 0, 0, 9800000,'ONGOING','Isreal','cityY', '235298@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-10-22', 25, 0, 0, 500000,'ONGOING','Poland','cityJ', '252105@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-5-1', 32, 0, 0, 1200000,'ONGOING','Singapore','cityU', '268912@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-12-8', 39, 0, 0, 1900000,'ONGOING','Austrilia','cityF', '285719@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-7-15', 16, 0, 0, 2600000,'ONGOING','Japan','cityQ', '302526@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-2-22', 23, 0, 0, 3300000,'ONGOING','United Kingdom','cityB', '319333@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-9-1', 30, 0, 0, 4000000,'FINISHED','Finland','cityM', '520932930@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-4-8', 37, 0, 0, 4700000,'ONGOING','German','cityX', '16807@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-11-15', 14, 0, 0, 5400000,'ONGOING','Italy','cityI', '33614@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-6-22', 21, 0, 0, 6100000,'ONGOING','China','cityT', '50421@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-1-1', 28, 0, 0, 6800000,'ONGOING','France','cityE', '67228@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-8-8', 35, 0, 0, 7500000,'ONGOING','Netherlands','cityP', '84035@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-3-15', 12, 0, 0, 8200000,'ONGOING','Canada','cityA', '100842@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-10-22', 19, 0, 0, 8900000,'ONGOING','Russia','cityL', '117649@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-5-1', 26, 0, 0, 9600000,'ONGOING','United States','cityW', '134456@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-12-8', 33, 0, 0, 300000,'ONGOING','Korea','cityH', '151263@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-7-15', 10, 0, 0, 1000000,'ONGOING','Isreal','cityS', '168070@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-2-22', 17, 0, 0, 1700000,'ONGOING','Poland','cityD', '184877@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-9-1', 24, 0, 0, 2400000,'ONGOING','Singapore','cityO', '201684@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-4-8', 31, 0, 0, 3100000,'ONGOING','Austrilia','cityZ', '218491@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-11-15', 38, 0, 0, 3800000,'ONGOING','Japan','cityK', '235298@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-6-22', 15, 0, 0, 4500000,'ONGOING','United Kingdom','cityV', '252105@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-1-1', 22, 0, 0, 5200000,'ONGOING','Finland','cityG', '268912@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-8-8', 29, 0, 0, 5900000,'ONGOING','German','cityR', '285719@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-3-15', 36, 0, 0, 6600000,'ONGOING','Italy','cityC', '302526@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-10-22', 13, 0, 0, 7300000,'ONGOING','China','cityN', '319333@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-5-1', 20, 0, 0, 8000000,'FINISHED','France','cityY', '520932930@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-12-8', 27, 0, 0, 8700000,'ONGOING','Netherlands','cityJ', '16807@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-7-15', 34, 0, 0, 9400000,'ONGOING','Canada','cityU', '33614@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-2-22', 11, 0, 0, 100000,'ONGOING','Russia','cityF', '50421@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-9-1', 18, 0, 0, 800000,'ONGOING','United States','cityQ', '67228@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-4-8', 25, 0, 0, 1500000,'ONGOING','Korea','cityB', '84035@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-11-15', 32, 0, 0, 2200000,'ONGOING','Isreal','cityM', '100842@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-6-22', 39, 0, 0, 2900000,'ONGOING','Poland','cityX', '117649@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-1-1', 16, 0, 0, 3600000,'ONGOING','Singapore','cityI', '134456@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-8-8', 23, 0, 0, 4300000,'ONGOING','Austrilia','cityT', '151263@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-3-15', 30, 0, 0, 5000000,'ONGOING','Japan','cityE', '168070@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-10-22', 37, 0, 0, 5700000,'ONGOING','United Kingdom','cityP', '184877@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-5-1', 14, 0, 0, 6400000,'ONGOING','Finland','cityA', '201684@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-12-8', 21, 0, 0, 7100000,'ONGOING','German','cityL', '218491@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-7-15', 28, 0, 0, 7800000,'ONGOING','Italy','cityW', '235298@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-2-22', 35, 0, 0, 8500000,'ONGOING','China','cityH', '252105@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-9-1', 12, 0, 0, 9200000,'ONGOING','France','cityS', '268912@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-4-8', 19, 0, 0, 9900000,'ONGOING','Netherlands','cityD', '285719@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-11-15', 26, 0, 0, 600000,'ONGOING','Canada','cityO', '302526@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-6-22', 33, 0, 0, 1300000,'ONGOING','Russia','cityZ', '319333@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-1-1', 10, 0, 0, 2000000,'FINISHED','United States','cityK', '520932930@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-8-8', 17, 0, 0, 2700000,'ONGOING','Korea','cityV', '16807@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-3-15', 24, 0, 0, 3400000,'ONGOING','Isreal','cityG', '33614@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-10-22', 31, 0, 0, 4100000,'ONGOING','Poland','cityR', '50421@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-5-1', 38, 0, 0, 4800000,'ONGOING','Singapore','cityC', '67228@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-12-8', 15, 0, 0, 5500000,'ONGOING','Austrilia','cityN', '84035@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-7-15', 22, 0, 0, 6200000,'ONGOING','Japan','cityY', '100842@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-2-22', 29, 0, 0, 6900000,'ONGOING','United Kingdom','cityJ', '117649@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-9-1', 36, 0, 0, 7600000,'ONGOING','Finland','cityU', '134456@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-4-8', 13, 0, 0, 8300000,'ONGOING','German','cityF', '151263@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-11-15', 20, 0, 0, 9000000,'ONGOING','Italy','cityQ', '168070@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-6-22', 27, 0, 0, 9700000,'ONGOING','China','cityB', '184877@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-1-1', 34, 0, 0, 400000,'ONGOING','France','cityM', '201684@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-8-8', 11, 0, 0, 1100000,'ONGOING','Netherlands','cityX', '218491@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-3-15', 18, 0, 0, 1800000,'ONGOING','Canada','cityI', '235298@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-10-22', 25, 0, 0, 2500000,'ONGOING','Russia','cityT', '252105@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-5-1', 32, 0, 0, 3200000,'ONGOING','United States','cityE', '268912@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-12-8', 39, 0, 0, 3900000,'ONGOING','Korea','cityP', '285719@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-7-15', 16, 0, 0, 4600000,'ONGOING','Isreal','cityA', '302526@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-2-22', 23, 0, 0, 5300000,'ONGOING','Poland','cityL', '319333@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-9-1', 30, 0, 0, 6000000,'FINISHED','Singapore','cityW', '520932930@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-4-8', 37, 0, 0, 6700000,'ONGOING','Austrilia','cityH', '16807@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-11-15', 14, 0, 0, 7400000,'ONGOING','Japan','cityS', '33614@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-6-22', 21, 0, 0, 8100000,'ONGOING','United Kingdom','cityD', '50421@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-1-1', 28, 0, 0, 8800000,'ONGOING','Finland','cityO', '67228@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-8-8', 35, 0, 0, 9500000,'ONGOING','German','cityZ', '84035@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-3-15', 12, 0, 0, 200000,'ONGOING','Italy','cityK', '100842@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-10-22', 19, 0, 0, 900000,'ONGOING','China','cityV', '117649@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-5-1', 26, 0, 0, 1600000,'ONGOING','France','cityG', '134456@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-12-8', 33, 0, 0, 2300000,'ONGOING','Netherlands','cityR', '151263@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-7-15', 10, 0, 0, 3000000,'ONGOING','Canada','cityC', '168070@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-2-22', 17, 0, 0, 3700000,'ONGOING','Russia','cityN', '184877@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-9-1', 24, 0, 0, 4400000,'ONGOING','United States','cityY', '201684@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-4-8', 31, 0, 0, 5100000,'ONGOING','Korea','cityJ', '218491@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-11-15', 38, 0, 0, 5800000,'ONGOING','Isreal','cityU', '235298@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-6-22', 15, 0, 0, 6500000,'ONGOING','Poland','cityF', '252105@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-1-1', 22, 0, 0, 7200000,'ONGOING','Singapore','cityQ', '268912@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2017-8-8', 29, 0, 0, 7900000,'ONGOING','Austrilia','cityB', '285719@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2018-3-15', 36, 0, 0, 8600000,'ONGOING','Japan','cityM', '302526@gmail.com');
 INSERT INTO project_initiated_by VALUES(DEFAULT, '', '', '','2016-10-22', 13, 0, 0, 9300000,'ONGOING','United Kingdom','cityX', '319333@gmail.com');
 */






