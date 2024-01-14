#include<iostream>
#include<stdlib.h>
#include<process.h>
#include<stdio.h>
#include<time.h>
#include<fstream>

using namespace std;
int arr[5][5]; int stop[5][5];                                                    //global declarations
int t,y,flag=0, move, score=0;
char ans;

class Point
{
	public:
		int points;
		char name[20];
		
		void input()
		{
			cout<<"\n\n Enter Name: \t\n\n";
			cin>>name;
			points=score;
		}
		
		void display()
		{
			cout<< "\n\n\n\t Name: \t\n\n\n";
			cout<< name;
			cout<< "\n\n Score: \t"<<points<<"\n";
		}
}data;

void scorekeeper()
{
	cout<<"\n End Game? (Y/N) \n";
	cin>>ans;
	if ( ans=='y')
	{
		system("cls");
		system("COLOR fO");
		cout<< " \n \t **********CONGRATS********** \n";
		
		ifstream fin;
		ofstream fo;
		fin.open("score.DAt",ios::in|ios::binary);
		fo.open("score.DAt",ios::in|ios::binary);
		
		data.input();
		fo.write((char*)&data,sizeof(data));
		
		data.display();
		cout<<" \n Do you wish to view the High Scores? (Y/N): \n";
		
		char condition;
		cin>>condition;
		if ( condition=='Y')
		fin.seekg(0);
		while(!fin.eof())
		{
			fin.read((char*)&data,sizeof(data));
			data.display();
		}
		fin.close();
		fo.close();
		char final;
		
		
		cout<<" \n\n\n Do you want to play again? (Y/N): \n";
		cin>>final;
		if(final=='N')
		exit(0);
	}
}

class MoveGen                                                                        //class containing movements for game play
{
	public:
		void right()
		{
			int posright;
			for( int wer=0; wer<4;wer++)
			{
				for(int b=4;b>0;b--)
				for(int a=4;a>0;a--)
				{
					if( arr[a][b]!=0)                                             //primary if condition
					{
						posright=b+1;
						if (posright<5)                                           //secondary if condition
						
						{
							
							if( arr[a][posright]==0)
							{
								arr[a][posright]=arr[a][b];
								arr[a][b]=0;
							}
							else if( arr[a][posright]==arr[a][b] && stop[a][posright]==0 && stop[a][b]==0)
							{
								arr[a][posright]=arr[a][b];
								arr[a][posright]=2*arr[a][b];
								score+=arr[a][posright];
								stop[a][posright]=1;
								arr[a][b]=0;
							}
							else if( wer==3 && a==1 && b==1)
							{
								cout<<"\n \t \t Invalid Move \t \t \n ";
							}                                                     
						}	                                                     // end of secondary if condition
					}                                                             // end of primary if condition                     
				}                                                            // end of second for loop
			}                                                              // end of primary for loop
		}                                          // end of function void right() 
		void left()
		{
			int posleft;
			for( int wer=0; wer<4;wer++)
			{
				for(int b=1;b<5;b++)
				for(int a=1;a<5;a++)
				{
					if( arr[a][b]!=0)                                             //primary if condition
					{
						posleft=b-1;
						if (posleft>0)                                           //secondary if condition
						
						{
							
							if( arr[a][posleft]==0)
							{
								arr[a][posleft]=arr[a][b];
								arr[a][b]=0;
							}
							else if( arr[a][posleft]==arr[a][b] && stop[a][posleft]==0 && stop[a][b]==0)
							{
								arr[a][posleft]=arr[a][b];
								arr[a][posleft]=2*arr[a][b];
								score+=arr[a][posleft];
								stop[a][posleft]=1;
								arr[a][b]=0;
							}
							else if( wer==3 && a==4 && b==4)
							{
								cout<<"\n \t \t Invalid Move \t \t \n ";
							}                                                     
						}	                                                     // end of secondary if condition
					}                                                             // end of primary if condition                     
				}                                                            // end of second for loop
			}                                                              // end of primary for loop
		}                                          // end of function void left()
		void up()
		{
			int posup;
			for( int wer=0; wer<4;wer++)
			{
				for(int b=1;b<5;b++)
				for(int a=1;a<5;a++)
				{
					if( arr[a][b]!=0)                                             //primary if condition
					{
						posup=a-1;
						if (posup>0)                                           //secondary if condition
						
						{
							
							if( arr[posup][b]==0)
							{
								arr[posup][b]=arr[a][b];
								arr[a][b]=0;
							}
							else if( arr[posup][b]==arr[a][b] && stop[posup][b]==0 && stop[a][b]==0)
							{
								arr[posup][b]=arr[a][b];
								arr[posup][b]=2*arr[a][b];
								score+=arr[posup][b];
								stop[posup][b]=1;
								arr[a][b]=0;
							}
							else if( wer==3 && a==4 && b==4)
							{
								cout<<"\n \t \t Invalid Move \t \t \n ";
							}                                                     
						}	                                                     // end of secondary if condition
					}                                                             // end of primary if condition                     
				}                                                            // end of second for loop
			}                                                              // end of primary for loop
		}                                          // end of function void up()  
			void down()
		{
			int posdown;
			for( int wer=0; wer<4;wer++)
			{
				for(int a=4;a>0;a--)
				for(int b=4;b>0;b--)
				{
					if( arr[a][b]!=0)                                             //primary if condition
					{
						posdown=a+1;
						if (posdown<5)                                           //secondary if condition
						
						{
							
							if( arr[posdown][b]==0)
							{
								arr[posdown][b]=arr[a][b];
								arr[a][b]=0;
							}
							else if( arr[posdown][b]==arr[a][b] && stop[posdown][b]==0 && stop[a][b]==0)
							{
								arr[posdown][b]=arr[a][b];
								arr[posdown][b]=2*arr[a][b];
								score+=arr[posdown][b];
								stop[posdown][b]=1;
								arr[a][b]=0;
							}
							else if( wer==3 && a==1 && b==1)
							{
								cout<<"\n \t \t Invalid Move \t \t \n ";
							}                                                     
						}	                                                     // end of secondary if condition
					}                                                             // end of primary if condition                     
				}                                                            // end of second for loop
			}                                                              // end of primary for loop
		}                                          // end of function void down() 
	}mover;                                           // end of entire class movegen
	
	
	
	void Board()                                               // function to display the game board
	{
		cout<< "\t \t \t 2048 for C++  \n \t ";
		cout<< " \t \t General Instructions: \t \n ";
		cout<< " \t Press- \n";
		cout<<" \t 8- Up \t \n";
		cout<< " \t 4-Left \t \t \n";
		cout<< " \t 6-Right \t \n";
		cout<< " \t 2-Down \t \n";
		cout<< " \t 2048 \t\t \n"<< "Score: \t"<< score;
		cout<< " \n \t Press 0 to end game \n\t";
		
		cout<< "     |     |     |     "<< endl;
		cout<<"   " << arr[1][1]<<"  |  "<< arr[1][2] << "  |  "<< arr[1][3] << "  |  "<< arr[1][4]<< endl;
		cout<< "_____|_____|_____|_____"<< endl;
		cout<< "     |     |     |     "<<endl;
		cout<<"   " << arr[2][1]<<"  |  "<< arr[2][2] << "  |  "<< arr[2][3] << "  |  "<< arr[2][4]<< endl;
		cout<< "_____|_____|_____|_____"<< endl;
		cout<< "     |     |     |     "<<endl;
		cout<<"   " << arr[3][1]<<"  |  "<< arr[3][2] << "  |  "<< arr[3][3] << "  |  "<< arr[3][4]<< endl;
		cout<< "_____|_____|_____|_____"<< endl;
		cout<< "     |     |     |     "<<endl;
		cout<<"   " << arr[4][1]<<"  |  "<< arr[4][2] << "  |  "<< arr[4][3] << "  |  "<< arr[4][4]<< endl;
		cout<< "     |     |     |     "<<endl<<endl;
		}                                                                                                      //end of display board function

int main()
{
	system("COLOR e0");
	srand(time(0));
	
	for(int I=0;I<5;I++)
	for(int v=0;v<5;v++)
	{
		stop[v][I]=0;
		arr[v][I]=0;
	}
	
	int y=rand()%(4)+1;
	int x=rand()%(4)+1;
	int z=rand()%(4)+1;
	int w=rand()%(4)+1;
	arr[x][y]=2;
	arr[z][w]=4;
	
	int check=0;
	while(check==0)
	{
		Board();
		again:
			cin>>move;                                                             //taking input on what move to execute
			if(move==8)
			mover.up();
			else if(move==4)
			mover.left();
			else if(move==6)
			mover.right();
			else if(move==2)
			mover.down();
			else if(move==0)
			scorekeeper();
			else goto again;
			
			do
			{
				t=rand()%(4)+1;
				y=rand()%(4)+1;
			} while(arr[t][y]!=0);
			
			arr[t][y]=2;
			Board();
			
			for(int g=0;g<5;g++)
			for(int h=0;h<5;h++)
			stop[g][h]=0;
			system("cls");
	}                                                  // end of whileloop satisfying check=0
}                                                  //end of main program
