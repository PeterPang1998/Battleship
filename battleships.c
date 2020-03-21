#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void input_function(char board[8][8],int row,int col,char dir,int type,char name){
    // ship_length length_value=type;
    int length=type;
    // printf("%d this is the length\n",length);
    // printf("%c this is the direction\n",dir);
    if(dir=='V'){
        int i=0;
        while(i<length){
            board[row+i][col]=name;
            i++;
        }
        }

    else if(dir=='H'){
        int i=0;
        while(i<length){
            board[row][col+i]=name;
            i++;
        }
        }
    }



void set_orig(char board[8][8]){
    for(int i=0;i<8;i++)
         memset(board[i], ' ',8);
}
void draw(char board[8][8]){ 
    printf("\n");
    int k=0;
    printf(" ");
    while(k<8){
        printf(" %d",++k);
    }
    printf("\n");
    for(int i=0;i<8;i++){
         printf("%c|",i+65);
         for (int j=0;j<8;j++){
             
            
             printf("%c|",board[i][j]);
         }
         printf("\n");
    }

}
int check_valid(char board[8][8],int row, int col, char dir,int type){
    int length=type;
    puts("hello");
    
    if(dir=='V'){
            int i=0;
            while(i<length){
                if(board[row+i][col]!=' '){
                    puts("Invalid ship configuration");
                        return 0;
                    } 
                    i++;  
                }
           return 1;
        }
    else if(dir=='H'){
        int i=0;
            while(i<length){
                if(board[row][col+i]!=' '){
                    puts("Invalid ship configuration");
                        return 0;
                    } 
                    i++;  
                }
        return 1;
    }
    return 1;
}
int check_before_hit(char board[8][8],int row, int col){
    if(row>7||col>8){
        puts("Invalid coordinates");
        return 1;
    }
    else if(board[row][col-1]==' '){return 0;}
    else if (board[row][col-1]==(char)'0'||board[row][col-1]=='X'){
        puts("You have already fired at this location");
        return 1;
    }
    return 1;
}
char hit(char board_org[8][8],char board_hit[8][8],int x,int y){
    char hit_result;
    if(board_org[x][y-1]==' '){
        board_hit[x][y-1]=(char)'0';
        return 'N';
    }
    hit_result=board_org[x][y-1];
    board_hit[x][y-1]='X';
    //printf("boat %c is hit!!",hit_result);
    return hit_result;
}
int record_hit(char all_boats[6][15],char initial,int record[5]){
    if(initial=='C'){
        record[0]= record[0]-1;
        if(record[0]==0){
            printf("We have sunk your %s!", all_boats[0]);
        }
    }
    else if(initial=='B'){
        record[1]= record[1]-1;
        if(record[1]==0){
            printf("We have sunk your %s!\n", all_boats[1]);
        }
    }else if(initial=='D'){
        record[2]= record[2]-1;
        if(record[2]==0){
            printf("We have sunk your %s!\n", all_boats[2]);
        }
    }else if(initial=='S'){
        record[3]= record[3]-1;
        if(record[3]==0){
            printf("We have sunk your %s!\n", all_boats[3]);
        }
    }else if(initial=='P'){
        record[4]= record[4]-1;
        if(record[4]==0){
            printf("We have sunk your %s!\n", all_boats[4]);
        }
    }
    for (int i=0;i<5;i++){
        if(record[i]>0){
            return 1;
        }
    }
    return 0;
}

int main(){

    char buffer[100];
    char board1[8][8];
    char board2[8][8];
    set_orig(board1);
    set_orig(board2);
    int player_counter=1;
    char list_of_ships[6][15]={"Carrier","Battleship","Destroyer","Submarine","Patrol Boat"};
    int ships_length[6]={5,4,3,2,2};
    printf("Player %d, please set up your ships (y, x, orientation)\n",player_counter);
    int counter=0;
    int y,x;
    char row;
    char direction;
    char buffer_char[15];
    while(counter<5){
        strcpy(buffer_char,list_of_ships[counter]);
        printf("%s: ",buffer_char);
        fgets(buffer,100,stdin);
        sscanf(buffer,"%c %d %c",&row,&y,&direction);
        x=row-65;
        y--;
        if((y>7)||(x>7)||((direction!='V')&&(direction!='H'))){
         
            puts("Invalid ship configuration");

        }else {
            char name_intial= list_of_ships[counter][0];
            int checkresult=check_valid(board1,x,y,direction,ships_length[counter]);
            if(checkresult==1){
                input_function(board1,x,y,direction,ships_length[counter],name_intial);
                //draw(board1);
                counter++;
                                }
            else if(checkresult==0){
                counter=counter+0;
                                     }
            }
    }
    player_counter=player_counter+1;
    printf("\n\n");
    printf("Player %d, please set up your ships (y, x, orientation)\n",player_counter);
    int counter2=0;
    while(counter2<5){
        strcpy(buffer_char,list_of_ships[counter2]);
        printf("%s: ",buffer_char);
        fgets(buffer,100,stdin);
        sscanf(buffer,"%c %d %c",&row,&y,&direction);
        x=row-65;
        y--;
        if((y>7)||(x>7)||((direction!='V')&&(direction!='H'))){
            counter2+=0;
        }else {
            char name_intial= list_of_ships[counter2][0];
            int checkresult=check_valid(board2,x,y,direction,ships_length[counter]);
            
            if(checkresult==1){
                input_function(board2,x,y,direction,ships_length[counter2],name_intial);
                //draw(board2);
                counter2++;
            }
            else if(checkresult==0){
                counter2=counter2+0;
            }
        }
     }
    
    // puts("this is board1");
    // draw(board1);
    // puts("this is board2");
    // draw(board2);
        //set up finished 
        
    char board_hit1[8][8];
    char board_hit2[8][8];
    set_orig(board_hit1);
    set_orig(board_hit2);
    int collection1[6]={5,4,3,2,2};
    int collection2[6]={5,4,3,2,2};
    int turn=0;
    char command[10];
    char buffer2[100];
    char row2; 
    int col2=0;
    int input_uncog=0;
    int game_on=1;
    int first_round=0;
    int finished=0;
    while(game_on==1){
        if (first_round==0){
            printf("\n");
            printf("All boats set up, Player %d can now strike.\n",turn+1);
            first_round++;
        }
        else if ((first_round!=0)&&(finished==1)){
                turn=(turn+1)%2;
                printf("\n");
                printf("Player %d's turn\n",turn+1);
            }
        fgets(buffer2,100,stdin);
        sscanf(buffer2," %s %c %d", command,&row2,&col2);
        printf("\n");
        if(strcmp(command,"exit")==0){
                //puts("end of the game");

                return 0;
            }
        if(strcmp(command,"shots")==0){
                input_uncog=1;
               if(turn==0){
                   draw(board_hit1);
                   finished=0;
               }
               else if(turn==1){
                    draw(board_hit2);
                     finished=0;
               }
            }
            row2=row2-65;
            
        if(strcmp(command,"fire")==0){
                //puts("ready to fire");
                input_uncog=1;
            char hit_result='\0';
            int result1=-1;
            if((turn+1)==1){
                  result1= check_before_hit(board_hit1,row2,col2);
                  if(result1==1){
                      turn+=0;
                  }else{
                    if(result1==0){
                    hit_result=hit(board2,board_hit1,row2,col2);
                   // printf("result %c 1\n ",hit_result);
                     finished=1;
                  }
                }
            }
            else if ((turn+1)==2){
                  result1= check_before_hit(board_hit2,row2,col2);
                  if(result1==1){
                      turn+=0;
                    
                  }else{
                    if(result1==0){
                         hit_result=hit(board1,board_hit2,row2,col2);
                         finished=1;
                    //printf("result %c 2\n",hit_result);
                    }
                  }
                }
            
            if(hit_result!='N'&&(result1==0)){
                printf("\n");
                puts("We have hit the target!");
                int win_or_not;
                if((turn+1)==1){
                        //draw(board_hit1);
                        win_or_not=record_hit(list_of_ships,hit_result,collection1);
                        finished=1;
                        if(win_or_not==0){
                            printf("Player %d wins!",turn+1);
                            return 0;
                        }
                       
                    }else if ((turn+1)==2){
                       // draw(board_hit2);
                        win_or_not=record_hit(list_of_ships,hit_result,collection2);
                         finished=1;
                        if(win_or_not==0){
                            printf("Player %d wins!",turn+1);
                            return 0;
                        }
                        // turn=(turn+1)%2;
                    }
            }
            else if((hit_result=='N')&&(result1==0)){
                printf("\n");
                puts("You have missed!");
                if((turn+1)==1){
                        //draw(board_hit1);
                         finished=1;
                    }else if ((turn+1)==2){
                        //draw(board_hit2);
                         finished=1;
                     }
                }
            }
            if(input_uncog==0){
                puts("Unrecognised command");

            }
        
        }

    


    return 0;
}


