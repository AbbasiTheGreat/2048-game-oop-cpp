#include<bits/stdc++.h>
#include<conio.h>
#include<string>
#include<windows.h>
using namespace std;

void SetColor(int ForgC);  // color function
static int score=0;
class Upmove{
	protected:
	void upmove(int a[4][4])
	{
		int i,j,li,ri;  // li and ri for the next index
		for(j=0;j<4;j++)
		{
			li=0,ri=j;
			for(i=1;i<4;i++)
			{
				if(a[i][j]!=0)   // if the index is not empty
				{
					if(a[i-1][j]==0 || a[i-1][j]==a[i][j])  // if the adjacent upper index is empty or the adjacent upper index is equal to the current index
					{
						if(a[li][ri]==a[i][j])     
						{
							score+=a[li][ri]*=2;  // incremening new index where the number id transferred
							 
							a[i][j]=0;   //the previous index becomes zero
						}
						else
						{
							if(a[li][ri]==0)  // if the next index is zero 
							{
								a[li][ri]=a[i][j]; // then the next index equals the previous index which is transferred to its place
								a[i][j]=0;
							}
							else
							{
								a[++li][ri]=a[i][j];   
								a[i][j]=0;
							}
						}
					}
					else li++; 
				}
			}
		}
	}
	
	
};



class DownMove{
	protected:
	 void downmove(int a[4][4])
{
	int i,j,li,ri;
	for(j=0;j<4;j++)
	{
		li=3,ri=j;
		for(i=2;i>=0;i--)
		{
			if(a[i][j]!=0)
			{
				if(a[i+1][j]==0 || a[i+1][j]==a[i][j])
				{
					if(a[li][ri]==a[i][j])
					{
						score+=a[li][ri]*=2;
						a[i][j]=0;
					}
					else
					{
						if(a[li][ri]==0)
						{
							a[li][ri]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[--li][ri]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else li--;
			}
		}
	}
	return;
}

};


class LeftMove{
	protected:
void leftmove(int a[4][4])
{
	int i,j,li,ri;
	for(i=0;i<4;i++)
	{
		li=i,ri=0;
		for(j=1;j<4;j++)
		{
			if(a[i][j]!=0)
			{
				if(a[i][j-1]==0 || a[i][j-1]==a[i][j])
				{
					if(a[li][ri]==a[i][j])
					{
						score+=a[li][ri]*=2;
						a[i][j]=0;
					}
					else
					{
						if(a[li][ri]==0)
						{
							a[li][ri]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[li][++ri]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else ri++;
			}
		}
	}
}
};


class RightMove{
	protected:
void rightmove(int a[4][4])
{
	int i,j,li,ri;
	for(i=0;i<4;i++)
	{
		li=i,ri=3;
		for(j=2;j>=0;j--)
		{
			if(a[i][j]!=0)
			{
				if(a[i][j+1]==0 || a[i][j+1]==a[i][j])
				{
					if(a[li][ri]==a[i][j])
					{
						
						score+=a[li][ri]*=2;
						a[i][j]=0;
					}
					else
					{
						if(a[li][ri]==0)
						{
							a[li][ri]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[li][--ri]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else ri--;
			}
		}
	}
}
};




class ShowMap{
	protected:
void display(int a[4][4])
{
	SetColor(6);
	cout<<"\n\t\tPress Esc anytime to quit the game";
	cout<<"\n\n\n\n";
	int i,j;
	for(i=0;i<4;i++)
	{
		cout<<"\t\t\t\t"; 
		string upper = "1---------------2"; 
		int size = upper.length();
		for(int k = 0 ; k <size ; k++){
			if (upper[k] == '1'){
				cout<<char(201);
			}
			if (upper[k] == '-'){
				cout<<char(205);
			}
			if (upper[k] == '2'){
				cout<<char(187);
			}
		}
		cout<<"\n\t\t\t\t";
		
		
		for(j=0;j<4;j++)
		{
			if(a[i][j]==0) cout<<char(186)<<"   ";
			else
				cout<<char(186)<<" "<<a[i][j]<<" ";
		}
		cout<<char(186)<<endl;
	}
	cout<<"\t\t\t\t";
	string lower = "\t\t\t\t3---------------4\n\t\t\t\t";
	int size1=lower.length();
	for(int i=0; i<size1 ;i++ ){
		if(lower[i]=='-'){
			cout<<char(205);
		}
		if(lower[i]=='3'){
			cout<<char(200);
		}
		if(lower[i]=='4'){
			cout<<char(188);
		}
	}
	cout<<"\n\t\t\t\t";
	SetColor(20);
	cout<<"Score: "<<score<<endl;
	SetColor(2);
	cout<<"\n\n                                  ^ ";
	cout<<"\nPress Arrow Keys for Movement  <     > ";
	cout<<"\n                                  ^  ";
	SetColor(5);                                              
	cout<<"\n\n\n\n\nSemester Project By: Farhan Abbasi 20P-0044  , CS-2C";
}
};

class CheckGoal{
	public:
	int check(int tmp[4][4],int a[4][4])
	{
		int fl=1,i,j;
		for(i=0;i<4;i++)
    		for(j=0;j<4;j++)
    		if(tmp[i][j]!=a[i][j])
    			{
    				fl=0;
    				break;
				}
		return fl;
	}

	int checkover(int a[4][4])
	{
		int fl=0,gl=0,i,j;
		for(i=0;i<4;i++)
    		for(j=0;j<4;j++)
    			if(a[i][j]==0)
    			{
    				fl=1;
					break;	
				}
			
		for(i=0;i<3;i++)
    		for(j=0;j<3;j++)
    			if(a[i+1][j]==a[i][j] || a[i][j+1]==a[i][j])
    			{
    				gl=1;
    				break;
				}
			
		if(fl || gl) return 1;
		else return 0;
	}
	
};

class GamePlay:public Upmove, public DownMove, public LeftMove, public RightMove, public ShowMap{
	public:
	void addblock(int a[4][4]){
		int li,ri;
		srand(time(0));
		while(true)
		{
			li=rand()%4;
			ri=rand()%4;
			if(a[li][ri]==0)
			{
				a[li][ri]= pow(2,li%2 + 1); // generating 2 or 4 at empty index
				break;
			}
		}

	}	
	
	void play(){
		CheckGoal goal;  // composition
		SetColor(5);
		cout<<"\n\n\n\n\t\t\t2048 GAME\n\n\n\t\tPress Enter key to Start";
		getch();
		system("cls");
		int i1,i2,i3,i4,i,j;
		int map[4][4]={0},tmp[4][4]={0};
		srand(time(0));
		i1=rand()%4;
		i2=rand()%4;
		while(1)
		{
			i3=rand()%4;
			i4=rand()%4;
			if(i3!=i1 && i4!=i2) break;
		}
		map[i1][i2]=2;
		map[i3][i4]=2;
		display(map);
	
		int ch;
		while (true)
    	{
    		for(i=0;i<4;i++)
    			for(j=0;j<4;j++)
    				tmp[i][j]=map[i][j];
    		ch=getch();
    		system("cls");
    		if(ch==72) upmove(map);
    		if(ch==80) downmove(map);
    		if(ch==75) leftmove(map);
    		if(ch==77) rightmove(map);
			if(ch==27) break;
		
			if(!goal.check(tmp,map))
				this->addblock(map);
			display(map);
			
			
			if(!goal.checkover(map))
			{   SetColor(10);
				cout<<"\n\n\t\t\tGAME OVER!!\n\n\n";
				getch();
				break;
			}	
		}
		}
	GamePlay(){         //construtor
		this->play();
	}
	
};






int main()
{
	GamePlay();
	return 0;
}




void SetColor(int ForgC){
     WORD wColor;
     //This handle is needed to get the current background attribute

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}
