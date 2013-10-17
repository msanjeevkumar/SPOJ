/*		1841.Prime Path
		problem code:PPATH
The ministers of the cabinet were quite upset by the message from the Chief of Security stating that they would all have to change the four-digit room numbers on their offices. 
雾务 It is a matter of security to change such things every now and then, to keep the enemy in the dark.
雾务 But look, I have chosen my number 1033 for good reasons. I am the Prime minister, you know!
雾务 I know, so therefore your new number 8179 is also a prime. You will just have to paste four new digits over the four old ones on your office door.
雾务 No, it's not that simple. Suppose that I change the first digit to an 8, then the number will read 8033 which is not a prime!
雾务 I see, being the prime minister you cannot stand having a non-prime number on your door even for a few seconds.
雾务 Correct! So I must invent a scheme for going from 1033 to 8179 by a path of prime numbers where only one digit is changed from one prime to the next prime.

Now, the minister of finance, who had been eavesdropping, intervened.
雾务 No unnecessary expenditure, please! I happen to know that the price of a digit is one pound.
雾务 Hmm, in that case I need a computer program to minimize the cost. You don't know some very cheap software gurus, do you?
雾务 In fact, I do. You see, there is this programming contest going on...

Help the prime minister to find the cheapest prime path between any two given four-digit primes! The first digit must be nonzero, of course. Here is a solution in the case above.

    1033
        1733     
	    3733     
	        3739     
		    3779
		        8779
			    8179     
			    The cost of this solution is 6 pounds. Note that the digit 1 which got pasted over in step 2 can not be reused in the last step 雾务 a new 1 must be purchased.
			    Input
			    
			    One line with a positive number: the number of test cases (at most 100). Then for each test case, one line with two numbers separated by a blank. Both numbers are four-digit primes (without leading zeros).
			    
			    Output
			    
			    One line for each case, either with a number stating the minimal cost or containing the word Impossible.
			    
			    Example
			    
			    Input:
			    3
			    1033 8179
			    1373 8017
			    1033 1033
			    
			    Output:
			    6
			    7
			    0*/








#include <iostream>
#include <cmath>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std ;

int start , end ;
bool p[10005],visit[10005] ;
int b[5] ;

struct Node
{
    int cur ;
    int level ;
};

bool isprime(int a)
{
    if(a % 2 == 0) return false  ;
    else
    {
        for(int j = 3 ; j <= a / 2 ; j ++)
        {
            if( a % j == 0)
            {
                return false ;
            }
        }
        return true ;
    }
}

void prime_table()
{
    memset(p,0,sizeof(0)) ;
    for(int i = 1000 ; i <= 10000 ; i ++)
    {
        p[i] = isprime(i) ;
    }
}

void get_num ( Node node  )
{
    b[1] = node.cur % 10 ;
    b[2] = ( node.cur % 100 ) / 10 ;
    b[3] = ( node.cur % 1000 ) / 100 ;
    b[4] = ( node.cur % 10000 ) / 1000 ;
}

int bfs()
{
    if(start == end) return 0 ;

    memset(visit,0,sizeof(visit)) ;

    visit[ start ] = 1 ;
    Node node ;
    node.cur = start ; node.level = 0 ;
    queue<Node> q ;
    q.push(node) ;
    while( 1 )
    {
        Node node_temp = q.front () ;
        q.pop () ;
        get_num ( node_temp ) ;
        for(int i = 1 ; i<= 4 ; i ++)
        {
            int c = node_temp.cur - b[i] * pow(10.0,i-1) ;
            for(int j = 0 ; j <= 9 ; j ++)
            {
                int new_c = c + j * pow(10.0,i-1) ;

                if(new_c == end) return node_temp.level + 1 ;
                if( new_c < 1000 || visit[new_c] == 1 || p[new_c] == 0 ) continue ;

                visit[new_c] = 1 ;
                Node node_new ;
                node_new.cur = new_c ;
                node_new.level = node_temp.level + 1 ;
                q.push (node_new) ;
            }
        }
    }
}


int main()
{
    int n ;
    cin >> n ;
    prime_table() ;
    while(n--)
    {
        cin >> start >> end ;
        cout << bfs() << endl ;
    }
    return 0;
}
