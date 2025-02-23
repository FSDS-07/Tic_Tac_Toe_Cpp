#include <iostream>

using std::string;
using std::cin;
using std::cout;

string p1,p2;
int turn=1; 
bool playerinit;
char board[3][3];
void InitializeBoard(){
    board[0][0]=' '; board[0][1]=' '; board[0][2]=' '; 
    board[1][0]=' '; board[1][1]=' '; board[1][2]=' '; 
    board[2][0]=' '; board[2][1]=' '; board[2][2]=' '; 

}
void DisplayBoard(){
    cout << "\n     " << board[0][0] << "     |     " << board[0][1] << "     |     " << board[0][2] << "     " << std::endl;
    cout << "\n-------------------------------------------------" << std::endl;
    cout << "\n     " << board[1][0] << "     |     " << board[1][1] << "     |     " << board[1][2] << "     " << std::endl;
    cout << "\n-------------------------------------------------" << std::endl;
    cout << "\n     " << board[2][0] << "     |     " << board[2][1] << "     |     " << board[2][2] << "     " << std::endl;
}
void StartGame(){
    do{ // Loop for entering the names
        cout<<"Enter the name of player 1 : "<<std::endl;
        cout.flush();
        cin>>p1;
        system("clear");
        cout<<"Enter the name of player 2 : "<<std::endl;
        cout.flush();
        cin>>p2;
        system("clear");
        if(p1==p2){
          cout<<"Players Name Cannot be the same"<<std::endl;}
        else{
          break;
        }
   }while(true);

}
void TurnChecker(){
    if(turn%2==0){
        playerinit = true;
        cout<<"It is the turn of : "<<p1<<std::endl;
        turn++;
        }
    else{
        playerinit = false;
        cout<<"It is the turn of : "<<p2<<std::endl;
        turn++;
        }
}
void UpdateBoard(){
    int i;
    int tens,ones;

    while(true){
        cout<<"Enter the Cordinate : "<<std::endl;
        cin>>i;
        cout<<i;
        if(i<0 || i>22){
            cout<<"Invalid Input !! Enter Again"<<std::endl;
            continue;
        }
        tens = i/10;
        ones = i%10;
        if(tens < 0 || tens > 2 || ones < 0 || ones > 2){
            cout<<"Invalid Cordinates : Must Be Witin Range Of Array !!"<<std::endl;
            continue;
        }
        if (board[tens][ones]!=' '){
            cout<<"Cell Already Occupied !! "<<std::endl;
            continue;
        }
        board[tens][ones] = (playerinit) ? 'X':'O';
        break;
    }
        
}
char CheckWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
    }
    for (int j = 0; j < 3; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j])
            return board[0][j];
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];
    return ' ';
}
bool IsBoardFull(){
    for(int i =0;i<3;i++){
        for(int j =0;j<3;j++){
            if(board[i][j]==' '){
                return false;
            }
        }
    }
    return true;
}
int main(){
    int k = 1;
    InitializeBoard();
    StartGame();
    DisplayBoard();
    while(k<10){
        TurnChecker();
        UpdateBoard();
        system("clear");
        DisplayBoard();
        char winner = CheckWinner();
        if(winner != ' ' ){
            cout<<"Player : "<< (winner == 'X' ? p1:p2) <<" Has Won The Match"<<std::endl;
            break;
            }
        if(IsBoardFull()){
            system("clear");
            cout<<"it is a draw";
            break;
        }
    k++;
    }

}