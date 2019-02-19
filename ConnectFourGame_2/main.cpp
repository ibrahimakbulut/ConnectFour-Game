#include <iostream>
#include <limits>
#include <cstdlib>     
#include <time.h> 
#include <fstream>
using namespace std;

void atama(char board[][20],int boyut=20);          	   //fill board with '.'.const parameter by reference.wiTH the default parameter.
void display(char board[][20],int boyut);                  //show board after functions run or it has just blanks.
int Check(char board[][20],int boyut);                     //check that there is a winner.
void yapay_zeka(char board[][20],const int &boyut,int & sira);  //fill the blanks by its own codes.sira parameter by reference.Boyut const parameter by reference.
void oyuncu1(char board[][20],int &boyut,int & sira);      //if the game is play by computer and player this function execute player's move.sira parameter by reference
void oynatici(char board[][20],int & boyut,int & sira);    //if the game is play by player and player  this  function execute players move.sira parameter by reference.
int main(){

	int boyut;
	bool gecerli_tip=false;
	char tip;
	
	auto condition=1;
	decltype(condition) sira=1;
	
	while(condition){
		cout << "How do you want to play game.Press P for pvp,Press C for pvc: ";     //select game type.
        cin >> tip;
		if(tip=='C' || tip=='P')
			condition=0;
		else
			cout<<"Wrong game type! Please enter again\n";
	}
	if(condition==0){
	condition=1;
	while(condition){
		do {
			cout<<"what is your board size \n";
			cin>>boyut;
        	if (!(gecerli_tip = cin.good())) {				//no accept to strings just numbers.
            	cerr<< "illegal board size.Enter again\n";
            	cin.clear();
            	cin.ignore(numeric_limits<streamsize>::max(), '\n');
        	}
    	} while (!gecerli_tip);
    	if(boyut>=4 && boyut%2==0 && boyut<=20)         //check the size .
			condition=0;
		else
			cerr<<"illegal board size \n";              //error message output .
	}}
	char board[20][20];
	atama(board,boyut);
	int b,a;
	b=3;a=1;
	switch(tip){
		
		case'P':
			display(board,boyut);
			while(a==1){
			oynatici(board,boyut,sira);
			display(board,boyut);
			b=Check(board,boyut);
			if(b==1 || b==2 || b==-1){
				if(b==1){
					display(board,boyut);
					cout<<"PLAYER 1 WON THE GAME";
				}
				if(b==2){
					display(board,boyut);
					cout<<"PLAYER 2 WON THE GAME";
				}
				if(b==-1)
					cout<<"Board was filled!";
				a=-1;
			}
			}
			break;
		case 'C':
			display(board,boyut);
			while(a==1){
				if(sira==1){
					oyuncu1(board,boyut,sira);
					
				}
				b=Check(board,boyut);
				if(sira==-1 && b!=1){
					yapay_zeka(board,boyut,sira);b=Check(board,boyut);}
				display(board,boyut);
				if(b==1 || b==2 || b==-1){
					if(b==1){
						display(board,boyut);
						cout<<"YOU WON THE GAME";
					}
					if(b==2){
						display(board,boyut);
						cout<<"COMPUTER WON THE GAME";
					}
					if(b==-1)
						cout<<"Board was filled!";
					a=-1;
				}
			}
			break;
		default :
			cerr<<"ERROR";
			break;
	}
return 0;
}
void atama(char board[][20], int boyut){
	
	for(int i=0;i<boyut;++i)
		for(int j=0;j<boyut;++j){
			board[i][j]='.';
		}
}
void display(char board[][20],int boyut){
	
	char harf=65;
	
	for(int i=0;i<boyut;++i,harf++){
		cout<<harf;
	}
	cout<<endl;
	for(int i=0;i<boyut;++i){
		for(int j=0;j<boyut;++j){
			cout<<board[i][j];
		}
		cout<<endl;
	}	
}
int Check(char board[][20],int boyut){
	
	int count=0;
	
	for(int i=0;i<boyut;i++){				//check whether player 1 won the game horizontal.
		for(int j=0;j<boyut;j++){
			if(board[i][j]=='X' && board[i][j+1]=='X' && board[i][j+2]=='X' && board[i][j+3]=='X'){
				board[i][j]+=32;board[i][j+1]+=32;board[i][j+2]+=32;board[i][j+3]+=32;
				return 1;
			}
		}
	}
	for(int i=0;i<boyut;i++){
		for(int j=0;j<boyut;j++){
			if(board[i][j]=='O' && board[i][j+1]=='O' && board[i][j+2]=='O' && board[i][j+3]=='O'){  //check whether player 2 or computer won the game horizontal.
				board[i][j]+=32;board[i][j+1]+=32;board[i][j+2]+=32;board[i][j+3]+=32;
				return 2;
			}
		}
	}
	for(int i=0;i<boyut;i++){
		for(int j=0;j<boyut;j++){
			if(board[i][j]=='X' && board[i+1][j]=='X' && board[i+2][j]=='X' && board[i+3][j]=='X'){ //check whether player 1 won the game vertical.
				board[i][j]+=32;board[i+1][j]+=32;board[i+2][j]+=32;board[i+3][j]+=32;
				return 1;
			}
		}
	}
	for(int i=0;i<boyut;i++){
		for(int j=0;j<boyut;j++){
			if(board[i][j]=='O' && board[i+1][j]=='O' && board[i+2][j]=='O' && board[i+3][j]=='O'){ //check whether player 2 or computer won the game vertical.
				board[i][j]+=32;board[i+1][j]+=32;board[i+2][j]+=32;board[i+3][j]+=32;
				return 2;
			}
		}
	}
	for(int i=0;i<boyut;i++){
		for(int j=0;j<boyut;j++){
			if(board[i][j]=='X' && board[i-1][j+1]=='X' && board[i-2][j+2]=='X' && board[i-3][j+3]=='X'){ //check whether player 1 won the game diagonal.
				board[i][j]+=32;board[i-1][j+1]+=32;board[i-2][j+2]+=32;board[i-3][j+3]+=32;
				return 1;
			}
		}
	}
	for(int i=0;i<boyut;i++){
		for(int j=0;j<boyut;j++){
			if(board[i][j]=='O' && board[i-1][j+1]=='O' && board[i-2][j+2]=='O' && board[i-3][j+3]=='O'){ //check whether player 2 or computer won the game diagonal.
				board[i][j]+=32;board[i-1][j+1]+=32;board[i-2][j+2]+=32;board[i-3][j+3]+=32;
				return 2;
			}
		}
	}
	for(int i=0;i<boyut;i++){
		for(int j=0;j<boyut;j++){
			if(board[i][j]=='X' && board[i-1][j-1]=='X' && board[i-2][j-2]=='X' && board[i-3][j-3]=='X'){ //check whether player 1 won the game diagonal
				board[i][j]+=32;board[i-1][j-1]+=32;board[i-2][j-2]+=32;board[i-3][j-3]+=32;
				return 1;
			}
		}
	}
	for(int i=0;i<boyut;i++){
		for(int j=0;j<boyut;j++){
			if(board[i][j]=='X' && board[i+1][j+1]=='X' && board[i+2][j+2]=='X' && board[i+3][j+3]=='X'){ //check whether player 1 won the game diagonal
				board[i][j]+=32;board[i+1][j+1]+=32;board[i+2][j+2]+=32;board[i+3][j+3]+=32;
				return 1;
			}
		}
	}
	for(int i=0;i<boyut;i++){
		for(int j=0;j<boyut;j++){
			if(board[i][j]=='X' && board[i+1][j-1]=='X' && board[i+2][j-2]=='X' && board[i+3][j-3]=='X'){ //check whether player 1 won the game diagonal
				board[i][j]+=32;board[i+1][j-1]+=32;board[i+2][j-2]+=32;board[i+3][j-3]+=32;
				return 1;
			}
		}
	}
	for(int i=0;i<boyut;i++){
		for(int j=0;j<boyut;j++){
			if(board[i][j]=='O' && board[i-1][j-1]=='O' && board[i-2][j-2]=='O' && board[i-3][j-3]=='O'){ //check whether player 2 or computer won the game diagonal.
				board[i][j]+=32;board[i-1][j-1]+=32;board[i-2][j-2]+=32;board[i-3][j-3]+=32;
				return 2;
			}
		}
	}
	for(int i=0;i<boyut;i++){
		for(int j=0;j<boyut;j++){
			if(board[i][j]=='O' && board[i+1][j+1]=='O' && board[i+2][j+2]=='O' && board[i+3][j+3]=='O'){ //check whether player 2 or computer won the game diagonal.
				board[i][j]+=32;board[i+1][j+1]+=32;board[i+2][j+2]+=32;board[i+3][j+3]+=32;
				return 2;
			}
		}
	}
	for(int i=0;i<boyut;i++){
		for(int j=0;j<boyut;j++){
			if(board[i][j]=='O' && board[i+1][j-1]=='O' && board[i+2][j-2]=='O' && board[i+3][j-3]=='O'){ //check whether player 2 or computer won the game diagonal.
				board[i][j]+=32;board[i+1][j-1]+=32;board[i+2][j-2]+=32;board[i+3][j-3]+=32;
				return 2;
			}
		}
	}
	for(int i=0;i<boyut;i++){		//check the board is filled or not
		for(int j=0;j<boyut;j++){
			if(board[i][j]=='X' || board[i][j]=='O'){
				count++;
			}
		}
	}
	if(count==boyut*boyut)
		return -1;
	else 
		return 0;
}
void yapay_zeka(char board[][20],const int &boyut,int & sira){
	
	int statu,statu1,statu2,statu3,a;
	statu=0;statu1=0;statu2=0;statu3=0;
	
	srand(time(NULL));	//connected the rand function to time
	
	if(sira==-1)
		cout<<"computer \n";
	
	for(int i=0;i<boyut&&statu==0;i++){										  //looking for a position to finish the game and making assignments when it finds
		for(int j=0;j<boyut&&statu==0;j++){
			if(board[i][j]=='O' && board[i][j+1]=='O' && board[i][j+2]=='O'){
				if(board[i+1][j+3]!='.' && board[i][j+3]=='.' && j+3<=boyut){	//check place where it assigments and controls is on the board	
					board[i][j+3]='O'; statu=1;statu1=1;statu2=1;statu3=1;}
				else if(board[i+1][j-1]!='.' && board[i][j-1]=='.' && i+1<=boyut && j-1>=0){
					board[i][j-1]='O'; statu=1;statu1=1;statu2=1;statu3=1;}
			}
			else if(board[i][j]=='O' && board[i+1][j]=='O' && board[i+2][j]=='O'){
				if(board[i-1][j]=='.'){
					board[i-1][j]='O';
					statu=1;statu1=1;statu2=1;statu3=1;
				}
			}
			else if(board[i][j]=='O' && board[i-1][j+1]=='O' && board[i-2][j+2]=='O'){
				if(board[i-2][j+3]!='.' && board[i-3][j+3]=='.' && i-3>=0 && j+3<=boyut){
					board[i-3][j+3]='O'; statu=1;statu1=1;statu2=1;statu3=1;}
				else if(board[i+2][j-1]!='.' && board[i+1][j-1]=='.' && i+2<=boyut && j-1>=0){
					board[i+1][j-1]='O'; statu=1;statu1=1;statu2=1;statu3=1;}
			}
			else if(board[i][j]=='O' && board[i-1][j-1]=='O' && board[i-2][j-2]=='O'){
				if(board[i-2][j-3]!='.' && board[i-3][j-3]=='.' && i-3>=0 && j-3>=0){
					board[i-3][j-3]='O'; statu=1;statu1=1;statu2=1;statu3=1;}
				else if(board[i+2][j+1]!='.' && board[i+1][j+1]=='.' && i+2<=boyut && j+1<=boyut){
					board[i+1][j+1]='O'; statu=1;statu1=1;statu2=1;statu3=1;}
			}
			else if(board[i][j]=='O' && board[i+1][j+1]=='O' && board[i+2][j+2]=='O'){
				if(i+3==boyut && board[i+3][j+3]=='.' && j+3<=boyut){
					board[i+3][j+3]='O'; statu=1;statu1=1;statu2=1;statu3=1;}
				else if(board[i+4][j+3]!='.' && board[i+3][j+3]=='.' && i+4<=boyut && j+3<=boyut){
					board[i+3][j+3]='O'; statu=1;statu1=1;statu2=1;statu3=1;}
				else if(board[i][j-1]!='.' && board[i-1][j-1]=='.' && i-1>=0 && j-1>=0){
					board[i-1][j-1]='O'; statu=1;statu1=1;statu2=1;statu3=1;}
			}
			else if(board[i][j]=='O' && board[i+1][j-1]=='O' && board[i+2][j-2]=='O'){
				if(i+3==boyut && board[i+3][j-3]=='.' && j-3>=0){
					board[i+3][j-3]='O'; statu=1;statu1=1;statu2=1;statu3=1;}
				else if(board[i+4][j-3]!='.' && board[i+3][j-3]=='.' && i+4<=boyut && j-3>=0){
					board[i+3][j-3]='O'; statu=1;statu1=1;statu2=1;statu3=1;}
				else if(board[i][j+1]!='.' && board[i+1][j+1]=='.' && i+1<=boyut && j+1<=boyut){
					board[i+1][j+1]='O'; statu=1;statu1=1;statu2=1;statu3=1;}
			}
		}
	}
	if(statu==0){
		
		for(int i=0;i<boyut&&statu1==0;i++){
		for(int j=0;j<boyut&&statu1==0;j++){
			if(board[i][j]=='X' && board[i][j+1]=='X' && board[i][j+2]=='X'){    		     // if he can not finish the game, 
				if(board[i+1][j+3]!='.' && board[i][j+3]=='.' && i+1<=boyut && j+3<=boyut){	 // he is looking for a position to prevent the opponent win.
					board[i][j+3]='O'; statu1=1;statu2=1;statu3=1;}
				else if(board[i+1][j-1]!='.' && board[i][j-1]=='.' && i+1<=boyut && j-1>=0){
					board[i][j-1]='O'; statu1=1;statu2=1;statu3=1;}
			}
			else if(board[i][j]=='X' && board[i+1][j]=='X' && board[i+2][j]=='X'){
				if(board[i-1][j]=='.'){
					board[i-1][j]='O';
					statu1=1;statu2=1;statu3=1;
				}
			}
			else if(board[i][j]=='X' && board[i-1][j+1]=='X' && board[i-2][j+2]=='X'){
				if(board[i-2][j+3]!='.' && board[i-3][j+3]=='.' && j+3<=boyut && i-3>=0){
					board[i-3][j+3]='O'; statu1=1;statu2=1;statu3=1;}
				else if(board[i+2][j-1]!='.' && board[i+1][j-1]=='.' && i+2<=boyut && j-1>=0){
					board[i+1][j-1]='O'; statu1=1;statu2=1;statu3=1;}
			}
			else if(board[i][j]=='X' && board[i-1][j-1]=='X' && board[i-2][j-2]=='X'){
				if(board[i-2][j-3]!='.' && board[i-3][j-3]=='.' && i-3>=0 && j-3>=0){
					board[i-3][j-3]='O'; statu1=1;statu2=1;statu3=1;}
				else if(board[i+2][j+1]!='.' && board[i+1][j+1]=='.' && i+2<=boyut && j+1<=boyut){
					board[i+1][j+1]='O'; statu1=1;statu2=1;statu3=1;}
			}
			else if(board[i][j]=='X' && board[i+1][j+1]=='X' && board[i+2][j+2]=='X'){
				if(i+3==boyut && board[i+3][j+3]=='.' && j+3<=boyut){
					board[i+3][j+3]='O'; statu1=1;statu2=1;statu3=1;}
				else if(board[i+4][j+3]!='.' && board[i+3][j+3]=='.' && i+4<=boyut && j+3<=boyut){
					board[i+3][j+3]='O'; statu1=1;statu2=1;statu3=1;}
				else if(board[i][j-1]!='.' && board[i-1][j-1]=='.' && i-1>=0 && j-1>=0){
					board[i-1][j-1]='O'; statu1=1;statu2=1;statu3=1;}
			}
			else if(board[i][j]=='X' && board[i+1][j-1]=='X' && board[i+2][j-2]=='X'){
				if(i+3==boyut && board[i+3][j-3]=='.' && j-3>=0)
				if(board[i+4][j-3]!='.' && board[i+3][j-3]=='.' && i+4<=boyut && j-3>=0){
					board[i+3][j-3]='O'; statu1=1;statu2=1;statu3=1;}
				else if(board[i][j+1]!='.' && board[i+1][j+1]=='.' && i+1<=boyut && j+1<=boyut){
					board[i+1][j+1]='O'; statu1=1;statu2=1;statu3=1;}
			}
		}
	}
}
	if(statu1==0){
		
		for(int i=0;i<boyut&&statu2==0;i++){      //it sees the position for the most suitable places to finish and assigns it when he finds it.
		for(int j=0;j<boyut&&statu2==0;j++){
			if(board[i][j]=='O' && board[i][j+1]=='O'){
				if(board[i+1][j+2]!='.' && board[i][j+2]=='.' && i+1<=boyut && j+2<=boyut){		
					board[i][j+2]='O'; statu2=1;statu3=1;}
				else if(board[i+1][j-1]!='.' && board[i][j-1]=='.' && i+1<=boyut && j-1>=0){
					board[i][j-1]='O'; statu2=1;statu3=1;}
			}
			else if(board[i][j]=='O' && board[i+1][j]=='O'){
				if(board[i-1][j]=='.'){
					board[i-1][j]='O';
					statu2=1;statu3=1;
				}
			}
			else if(board[i][j]=='O' && board[i-1][j+1]=='O'){
				if(board[i-1][j+2]!='.' && board[i-2][j+2]=='.' && i-2>=0 && j+2<=boyut){
					board[i-2][j+2]='O'; statu2=1;statu3=1;}
				else if(board[i+2][j-1]!='.' && board[i+1][j-1]=='.' && i+2<=boyut && j-1>=0){
					board[i+1][j-1]='O'; statu2=1;statu3=1;}
			}
			else if(board[i][j]=='O' && board[i-1][j-1]=='O'){
				if(board[i-1][j-2]!='.' && board[i-2][j-2]=='.' && i-2>=0 && j-2>=0){
					board[i-2][j-2]='O'; statu2=1;statu3=1;}
				else if(board[i+2][j+1]!='.' && board[i+1][j+1]=='.' && i+2<=boyut && j+1<=boyut){
					board[i+1][j+1]='O'; statu2=1;statu3=1;}
			}
			else if(board[i][j]=='O' && board[i+1][j+1]=='O'){
				if(i+2==boyut && board[i+2][j+2]=='.' && j+2<=boyut){
					board[i+2][j+2]='O'; statu2=1;statu3=1;}
				else if(board[i+3][j+2]!='.' && board[i+2][j+2]=='.' && i+3<=boyut && j+2<=boyut){
					board[i+2][j+2]='O'; statu2=1;statu3=1;}
				else if(board[i][j-1]!='.' && board[i-1][j-1]=='.' && i-1>=0 && j-1>=0){
					board[i-1][j-1]='O'; statu2=1;statu3=1;}
			}
			else if(board[i][j]=='O' && board[i+1][j-1]=='O'){
				if(i+2==boyut && board[i+2][j-2]=='.' && j-2>=0){
					board[i+2][j-2]='O'; statu2=1;statu3=1;}
				else if(board[i+3][j-2]!='.' && board[i+2][j-2]=='.' && i+3<=boyut && j-2>=0){
					board[i+2][j-2]='O'; statu2=1;statu3=1;}
				else if(board[i][j+1]!='.' && board[i+1][j+1]=='.' && i+1<=boyut && j+1<=boyut){
					board[i+1][j+1]='O'; statu2=1;statu3=1;}
			}
			}	
		}
	}
	if(statu2==0){
		
		for(int i=0;i<boyut&&statu3==0;i++){ //it sees the position for the most suitable places to finish and assigns it when he finds it.
		for(int j=0;j<boyut&&statu3==0;j++){
			if(board[i][j]=='O'){
				if(i+1==boyut && board[i][j+1]=='.' &&j+1<=boyut){
					board[i][j+1]='O'; statu3=1;}	
				else if(board[i+1][j+1]!='.' && board[i][j+1]=='.' && i+1<=boyut && j+1<=boyut){		
					board[i][j+1]='O'; statu3=1;}
				else if(i+1==boyut && board[i][j-1]=='.' && j-1>=0){
					board[i][j-1]='O'; statu3=1;}
				else if(board[i+1][j-1]!='.' && board[i][j-1]=='.' && i+1<=boyut && j-1>=0){
					board[i][j-1]='O'; statu3=1;}
			}
			else if(board[i][j]=='O'){
				if(board[i-1][j]=='.'){
					board[i-1][j]='O';
					statu3=1;
				}
			}
			else if(board[i][j]=='O'){
				if(board[i][j+1]!='.' && board[i-1][j+1]=='.' && i-1>=0 && j+1<=boyut){
					board[i-1][j+1]='O'; statu3=1;}
				else if(board[i+2][j-1]!='.' && board[i+1][j-1]=='.' && i+2<=boyut && j-1>=0){
					board[i+1][j-1]='O'; statu3=1;}
			}
			else if(board[i][j]=='O'){
				if(board[i][j-1]!='.' && board[i-1][j-1]=='.' && i-1>=0 && j-1>=0){
					board[i-1][j-1]='O'; statu3=1;}
				else if(board[i+2][j+1]!='.' && board[i+1][j+1]=='.' && i+2<=boyut && j+1<=boyut){
					board[i+1][j+1]='O'; statu3=1;}
			}
			}	
		}
	}
	if(statu3==0){  // if there is no an advantageous place to finish and if there is no place to block,make random assignments.
		
		int z=0;
		for(int j=0;j>=0&&z==0;j++){
		a=rand()%boyut;
		for(int i=boyut-1;i>=0;i--)
			if(board[i][a]=='.'){
				board[i][a]='O';
				z=-1;
				break;
			}
		}
	}
	sira=sira*-1;
}
void oyuncu1(char board[][20],int & boyut,int & sira){
	
	char face[20];
	char dosya[50];
	char dusme;
	int condition=1;
	int k=1;
	while(condition){
		int state=1;	
		cout<<"player 1:";
		cin>>face;
		dusme=face[0];
	
		if(face[0]=='L' && face[1]=='O' && face[2]=='A' && face[3]=='D'){
			state=0;
			cin>>dosya;
			ifstream save(dosya);
			save>>sira;
			save>>boyut;
			for(int a=0;a<boyut;++a){
				for(int b=0;b<boyut;++b){
					save>>board[a][b];
				}
			}
				condition=0;
			k=0;
			continue;
		}
		else if(face[0]=='S' && face[1]=='A' && face[2]=='V' && face[3]=='E'){
			state=0;
			cin>>dosya;
			ofstream save(dosya);
			save<<sira<<endl;
			save<<boyut<<endl;
			for(int a=0;a<boyut;++a){
				for(int b=0;b<boyut;++b){
					save<<board[a][b];
				}
				save<<endl;
			}
			condition=0;
			k=0;
			continue;
		}
		if(state==1 && face[1]!='\0'){
			cerr<<"Wrong column.Enter again \n";
			continue;
		}
		if(65<=dusme && dusme<boyut+65){
			for(int i=boyut-1;i>=0;i--)
					if(board[i][dusme-65]=='.'){
						board[i][dusme-65]='X';
						break;
					}
			condition=0;
		}
	
	}
    if(k==1)sira=sira*-1;
}
void oynatici(char board[][20],int & boyut,int & sira){
	
	char face[20];
	char dosya[50];
	char dusme;
	int condition=1;

	while(condition){
		int state=1;	
		if(sira==1)
			cout<<"player 1 : ";
		if(sira==-1)
			cout<<"player 2 : ";
		face[1]='\0';
		cin>>face;
		dusme=face[0];
	
		if(face[0]=='L' && face[1]=='O' && face[2]=='A' && face[3]=='D'){
			state=0;
			cin>>dosya;
			ifstream save(dosya);
			save>>sira;
			save>>boyut;
			for(int a=0;a<boyut;++a){
				for(int b=0;b<boyut;++b){
					save>>board[a][b];
				}
			}
			display(board,boyut);
			continue;
		}
		else if(face[0]=='S' && face[1]=='A' && face[2]=='V' && face[3]=='E'){
			state=0;
			cin>>dosya;
			ofstream save(dosya);
			save<<sira<<endl;
			save<<boyut<<endl;
			for(int a=0;a<boyut;++a){
				for(int b=0;b<boyut;++b){
					save<<board[a][b];
				}
				save<<endl;
			}
			continue;
		}
		if(state==1 && face[1]!='\0'){
			cerr<<"Wrong column.Enter again \n";
			continue;
		}
		if(65<=dusme && dusme<boyut+65 &&state==1){
			if(sira==1){
				for(int i=boyut-1;i>=0;i--)
					if(board[i][dusme-65]=='.'){
						board[i][dusme-65]='X';
						break;
					}
			}
			if(sira==-1){
				for(int i=boyut-1;i>=0;i--)
					if(board[i][dusme-65]=='.'){
						board[i][dusme-65]='O';
						break;
				}
			}
			condition=0;
		}
	
			
	}
	sira=sira*-1;
}
