#include <iostream>
#include <limits>
#include <cstdlib>     
#include <time.h> 

using namespace std;


void atama(char board[][20],int boyut);
void display(char board[][20],int boyut);
int Check(char board[][20],int boyut);
void yapay_zeka(char board[][20],int boyut,int & sira);
void oyuncu1(char board[][20],int boyut,int & sira);
void oynatici(char board[][20],int boyut,int & sira);
int main(){

	
	int boyut;
	bool gecerli_tip=false;
	char tip;
	
	int condition=1;
	int sira=1;
	
	while(condition){
	
		cout << "How do you want to play game.Press P for pvp,Press C for pvc: ";
        cin >> tip;
		if(tip=='C' || tip=='P')
			condition=0;
		else
			cout<<"Wrong game type! Please enter again\n";
	}
	condition=1;
	while(condition){
		do {
			cout<<"what is your board size \n";
			cin>>boyut;
        	if (!(gecerli_tip = cin.good())) {
            	cout << "Wrong game type! Please enter again\n";
            	cin.clear();
            	cin.ignore(numeric_limits<streamsize>::max(), '\n');
        	}
	
    	} while (!gecerli_tip);
    	if(boyut>=4 && boyut%2==0 && boyut<=20)
			condition=0;
		else
			cout<<"illegal board size \n";
		
	}
	char board[20][20];
	atama(board,boyut);
	
	int b,a=1;
	
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
			oyuncu1(board,boyut,sira);}
			else {
				yapay_zeka(board,boyut,sira);}
			display(board,boyut);
			b=Check(board,boyut);
			if(b==1 || b==2 || b==-1){
				if(b==1){
					display(board,boyut);
					cout<<"PLAYER 1 WON THE GAME \n";
				}
				if(b==2){
					display(board,boyut);
					cout<<"PLAYER 2 WON THE GAME \n";
				}
				if(b==-1)
					cout<<"Board was filled!";
				a=-1;
		
			}
	
			}
			break;
		
		default :
			cout<<"ERROR";
			break;
			

	}
return 0;
}
void atama(char board[][20],int boyut){
	
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
	
	for(int i=0;i<boyut;i++){
		for(int j=0;j<boyut;j++){
			if(board[i][j]=='X' && board[i][j+1]=='X' && board[i][j+2]=='X' && board[i][j+3]=='X'){
				board[i][j]+=32;board[i][j+1]+=32;board[i][j+2]+=32;board[i][j+3]+=32;
				return 1;
			}
		}
	}
	for(int i=0;i<boyut;i++){
		for(int j=0;j<boyut;j++){
			if(board[i][j]=='O' && board[i][j+1]=='O' && board[i][j+2]=='O' && board[i][j+3]=='O'){
				board[i][j]+=32;board[i][j+1]+=32;board[i][j+2]+=32;board[i][j+3]+=32;
				return 2;
			}
		}
	}
	
	for(int i=0;i<boyut;i++){
		for(int j=0;j<boyut;j++){
			if(board[i][j]=='X' && board[i+1][j]=='X' && board[i+2][j]=='X' && board[i+3][j]=='X'){
				board[i][j]+=32;board[i+1][j]+=32;board[i+2][j]+=32;board[i+3][j]+=32;
				return 1;
			}
		}
	}
	
	for(int i=0;i<boyut;i++){
		for(int j=0;j<boyut;j++){
			if(board[i][j]=='O' && board[i+1][j]=='O' && board[i+2][j]=='O' && board[i+3][j]=='O'){
				board[i][j]+=32;board[i+1][j]+=32;board[i+2][j]+=32;board[i+3][j]+=32;
				return 2;
			}
		}
	}
	for(int i=0;i<boyut;i++){
		for(int j=0;j<boyut;j++){
			if(board[i][j]=='X' && board[i-1][j+1]=='X' && board[i-2][j+2]=='X' && board[i-3][j+3]=='X'){
				board[i][j]+=32;board[i-1][j+1]+=32;board[i-2][j+2]+=32;board[i-3][j+3]+=32;
				return 1;
			}
		}
	}
	
	for(int i=0;i<boyut;i++){
		for(int j=0;j<boyut;j++){
			if(board[i][j]=='O' && board[i-1][j+1]=='O' && board[i-2][j+2]=='O' && board[i-3][j+3]=='O'){
				board[i][j]+=32;board[i-1][j+1]+=32;board[i-2][j+2]+=32;board[i-3][j+3]+=32;
				return 2;
			}
		}
	}
	
	for(int i=0;i<boyut;i++){
		for(int j=0;j<boyut;j++){
			if(board[i][j]=='X' && board[i-1][j-1]=='X' && board[i-2][j-2]=='X' && board[i-3][j-3]=='X'){
				board[i][j]+=32;board[i-1][j-1]+=32;board[i-2][j-2]+=32;board[i-3][j-3]+=32;
				return 1;
			}
		}
	}
	
	for(int i=0;i<boyut;i++){
		for(int j=0;j<boyut;j++){
			if(board[i][j]=='X' && board[i+1][j+1]=='X' && board[i+2][j+2]=='X' && board[i+3][j+3]=='X'){
				board[i][j]+=32;board[i+1][j+1]+=32;board[i+2][j+2]+=32;board[i+3][j+3]+=32;
				return 1;
			}
		}
	}
	
	for(int i=0;i<boyut;i++){
		for(int j=0;j<boyut;j++){
			if(board[i][j]=='X' && board[i+1][j-1]=='X' && board[i+2][j-2]=='X' && board[i+3][j-3]=='X'){
				board[i][j]+=32;board[i+1][j-1]+=32;board[i+2][j-2]+=32;board[i+3][j-3]+=32;
				return 1;
			}
		}
	}
	
	
	
	for(int i=0;i<boyut;i++){
		for(int j=0;j<boyut;j++){
			if(board[i][j]=='O' && board[i-1][j-1]=='O' && board[i-2][j-2]=='O' && board[i-3][j-3]=='O'){
				board[i][j]+=32;board[i-1][j-1]+=32;board[i-2][j-2]+=32;board[i-3][j-3]+=32;
				return 2;
			}
		}
	}
	
	for(int i=0;i<boyut;i++){
		for(int j=0;j<boyut;j++){
			if(board[i][j]=='O' && board[i+1][j+1]=='O' && board[i+2][j+2]=='O' && board[i+3][j+3]=='O'){
				board[i][j]+=32;board[i+1][j+1]+=32;board[i+2][j+2]+=32;board[i+3][j+3]+=32;
				return 2;
			}
		}
	}
	
	for(int i=0;i<boyut;i++){
		for(int j=0;j<boyut;j++){
			if(board[i][j]=='O' && board[i+1][j-1]=='O' && board[i+2][j-2]=='O' && board[i+3][j-3]=='O'){
				board[i][j]+=32;board[i+1][j-1]+=32;board[i+2][j-2]+=32;board[i+3][j-3]+=32;
				return 2;
			}
		}
	}
	
	
	for(int i=0;i<boyut;i++){
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

void yapay_zeka(char board[][20],int boyut,int & sira){
	
	int statu,statu1,statu2,statu3;
	statu=0;statu1=0;statu2=0;statu3=0;
	
	
	if(sira==-1)
		cout<<"computer \n";
	
	for(int i=0;i<boyut&&statu==0;i++){
		for(int j=0;j<boyut&&statu==0;j++){
			if(board[i][j]=='O' && board[i][j+1]=='O' && board[i][j+2]=='O'){
				if(board[i-1][j+3]=='X' || board[i-1][j+3]=='O')			
					board[i][j+3]='O';
				else if(board[i-1][j-1]=='X' || board[i-1][j-1]=='O')
					board[i][j-1]='O';
				statu=1;statu1=1;statu2=1;statu3=1;
			}
			else if(board[i][j]=='O' && board[i+1][j]=='O' && board[i+2][j]=='O'){
				if(board[i-1][j]=='.'){
					board[i-1][j]='O';
					statu=1;statu1=1;statu2=1;statu3=1;
				}
			}
			
			else if(board[i][j]=='O' && board[i-1][j+1]=='O' && board[i-2][j+2]=='O'){
				if(board[i-2][j+3]=='X' || board[i-2][j+3]=='O')
					board[i-3][j+3]=='O';
				else if(board[i+2][j-1]=='X' || board[i+2][j-1]=='O')
					board[i+1][j-1]='O';
				statu=1;statu1=1;statu2=1;statu3=1;
				
			}
			
			else if(board[i][j]=='O' && board[i-1][j-1]=='O' && board[i-2][j-2]=='O'){
				if(board[i-2][j-3]=='X' || board[i-2][j-3]=='O')
					board[i-3][j-3]='O';
				else if(board[i+2][j+1]=='X' || board[i+2][j+1]=='O')
					board[i+1][j+1]='O';
				statu=1;statu1=1;statu2=1;statu3=1;
				
			}
			
			else if(board[i][j]=='O' && board[i+1][j+1]=='O' && board[i+2][j+2]=='O'){
				if(board[i+4][j+3]=='X' || board[i+4][j+3]=='O')
					board[i+3][j+3]='O';
				else if(board[i][j-1]=='X' || board[i][j-1]=='O')
					board[i-1][j-1]='O';
				statu=1;statu1=1;statu2=1;statu3=1;
				
			}
			
			else if(board[i][j]=='O' && board[i+1][j-1]=='O' && board[i+2][j-2]=='O'){
				if(board[i+4][j-3]=='X' || board[i+4][j-3]=='O')
					board[i+3][j-3]='O';
				else if(board[i][j+1]=='X' || board[i][j+1]=='O')
					board[i+1][j+1]='O';
				statu=1;statu1=1;statu2=1;statu3=1;
			}
				
			
		}
	}
	if(statu==0){
		
		
		for(int i=0;i<boyut&&statu1==0;i++){
		for(int j=0;j<boyut&&statu1==0;j++){
			if(board[i][j]=='X' && board[i][j+1]=='X' && board[i][j+2]=='X'){
				if(board[i-1][j+3]=='X' || board[i-1][j+3]=='O')			
					board[i][j+3]='O';
				else if(board[i-1][j-1]=='X' || board[i-1][j-1]=='O')
					board[i][j-1]='O';
				statu1=1;statu2=1;statu3=1;
			}
			else if(board[i][j]=='X' && board[i+1][j]=='X' && board[i+2][j]=='X'){
				if(board[i-1][j]='.'){
					board[i-1][j]='O';
					statu1=1;statu2=1;statu3=1;
				}
			}
			else if(board[i][j]=='X' && board[i-1][j+1]=='X' && board[i-2][j+2]=='X'){
				if(board[i-2][j+3]=='X' || board[i-2][j+3]=='O')
					board[i-3][j+4]=='O';
				else if(board[i+2][j-1]=='X' || board[i+2][j-1]=='O')
					board[i+1][j-1]='O';
				statu1=1;statu2=1;statu3=1;
				
			}
			else if(board[i][j]=='X' && board[i-1][j-1]=='X' && board[i-2][j-2]=='X'){
				if(board[i-2][j-3]=='X' || board[i-2][j-3]=='O')
					board[i-3][j-4]='O';
				else if(board[i+2][j+1]=='X' || board[i+2][j+1]=='O')
					board[i+1][j+1]='O';
				statu1=1;statu2=1;statu3=1;
				
			}
			else if(board[i][j]=='X' && board[i+1][j+1]=='X' && board[i+2][j+2]=='X'){
				if(board[i+4][j+3]=='X' || board[i+4][j+3]=='O' )
					board[i+3][j+3]='O';
				else if(board[i][j-1]=='X' || board[i][j-1]=='O')
					board[i-1][j-1]='O';
				statu1=1;statu2=1;statu3=1;
				
			}
			else if(board[i][j]=='X' && board[i+1][j-1]=='X' && board[i+2][j-2]=='X'){
				if(board[i+4][j-3]=='X' || board[i+4][j-3]=='O')
					board[i+3][j-3]='O';
				else if(board[i][j+1]!='.')
					board[i+1][j+1]='O';
				statu1=1;statu2=1;statu3=1;
			}
				
			
		}
	}
}
	
	if(statu1==0){
		
	
		for(int i=0;i<boyut&&statu2==0;i++){
		for(int j=0;j<boyut&&statu2==0;j++){
			if(board[i][j]=='O' && board[i][j+1]=='O'){
				if(board[i-1][j+2]=='X' || board[i-1][j+2]=='O')			
					board[i][j+2]='O';
				else if(board[i-1][j-1]=='X' || board[i-1][j-1]=='O')
					board[i][j-1]='O';
				statu2=1;statu3=1;
			}
			else if(board[i][j]=='O' && board[i+1][j]=='O'){
				if(board[i-1][j]=='.'){
					board[i-1][j]=='O';
					statu2=1;statu3=1;
				}
			}
			else if(board[i][j]=='O' && board[i-1][j+1]=='O'){
				if(board[i-1][j+2]=='X' || board[i-1][j+2]=='O')
					board[i-2][j+2]=='O';
				else if(board[i+2][j-1]=='X' || board[i+2][j-1]=='O')
					board[i+1][j-1]='O';
				statu2=1;statu3=1;
				
			}
			else if(board[i][j]=='O' && board[i-1][j-1]=='O'){
				if(board[i-1][j-2]=='X'|| board[i-1][j-2]=='O')
					board[i-2][j-2]='O';
				else if(board[i+2][j+1]=='X' || board[i+2][j+1]=='O')
					board[i+1][j+1]='O';
				statu2=1;statu3=1;
				
			}
			else if(board[i][j]=='O' && board[i+1][j+1]=='O'){
				if(board[i+3][j+2]=='X' || board[i+3][j+2]=='O')
					board[i+2][j+2]='O';
				else if(board[i][j-1]=='X' || board[i][j-1]=='O')
					board[i-1][j-1]='O';
				statu2=1;statu3=1;
				
			}
			else if(board[i][j]=='O' && board[i+1][j-1]=='O'){
				if(board[i+3][j-2]=='X' || board[i+3][j-2]=='O')
					board[i+2][j-2]='O';
				else if(board[i][j+1]=='X' || board[i][j+1]=='O')
					board[i+1][j+1]='O';
				statu2=1;statu3=1;
			}
				
			}	
		}
		
	}
	
	if(statu2==0){
		
	
		for(int i=0;i<boyut&&statu3==0;i++){
		for(int j=0;j<boyut&&statu3==0;j++){
			if(board[i][j]=='O'){
				if(board[i-1][j+1]=='X' || board[i-1][j+1]=='O')			
					board[i][j+1]='O';
				else if(board[i-1][j-1]=='X' || board[i-1][j-1]=='O')
					board[i][j-1]='O';
				statu3=1;
			}
			else if(board[i][j]=='O'){
				if(board[i-1][j]=='.'){
					board[i-1][j]='O';
					statu3=1;
				}
			}
			else if(board[i][j]=='O'){
				if(board[i][j+1]=='X' || board[i][j+1]=='O')
					board[i-1][j+1]=='O';
				else if(board[i+2][j-1]=='X' || board[i+2][j-1]=='O')
					board[i+1][j-1]='O';
				statu3=1;
				
			}
			else if(board[i][j]=='O'){
				if(board[i][j-1]=='X' || board[i][j-1]=='O')
					board[i-1][j-1]='O';
				else if(board[i+2][j+1]=='X' || board[i+2][j+1]=='O')
					board[i+1][j+1]='O';
				statu3=1;
				
			}
			else if(board[i][j]=='O'){
				if(board[i+2][j+1]=='X' || board[i+2][j+1]=='O')
					board[i+1][j+1]='O';
				else if(board[i][j-1]=='X' || board[i][j-1]=='O')
					board[i-1][j-1]='O';
				statu3=1;
				
			}
			else if(board[i][j]=='O'){
				if(board[i+2][j-1]=='X' || board[i+2][j-1]=='O')
					board[i+1][j-1]='O';
				else if(board[i][j+1]=='X' || board[i][j+1]=='O')
					board[i+1][j+1]='O';
				statu3=1;
			}
			}	
		}
	}
	
	if(statu3==0){
		
		
	
		int a;
		
		a=rand()%boyut;
		
		for(int i=boyut-1;i>=0;i--)
			if(board[i][a]=='.'){
				board[i][a]='O';
				break;
			}
	}
	
	sira=sira*-1;
			
}

void oyuncu1(char board[][20],int boyut,int & sira){
	
	char dusme;
	int condition=1;
	while(condition){
		
		if(sira==1)
			cout<<"player 1:";
		cin>>dusme;
		if(65<=dusme && dusme<boyut+65){
			for(int i=boyut-1;i>=0;i--)
					if(board[i][dusme-65]=='.'){
				
						board[i][dusme-65]='X';
						break;
					}
			condition=0;
		}
		else
			cout<<"Wrong column.Enter again \n";
	}
	sira=sira*-1;
}
void oynatici(char board[][20],int boyut,int & sira){
	
	char dusme;
	int condition=1;

	while(condition){
		if(sira==1)
			cout<<"player 1 : ";
		if(sira==-1)
			cout<<"player 2 : ";
		cin>>dusme;
		if(65<=dusme && dusme<boyut+65){
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
		else
			cout<<"Wrong column.Enter again \n";

	}
	sira=sira*-1;
	
}

