#include "hanoi-tower.h"

#include <sstream>      // std::stringstream
#include <iomanip>      // left,right,fill,setw - see handout
#include <iostream>     // debugging

char sub1(char peg);
char add1(char peg);
char movePeg(int n, bool isOdd, char peg);

template< typename CALLBACK >
void hanoi_tower_1_rec(int n, CALLBACK cb, char peg1, char peg2, bool isOdd) 
{
  std::stringstream ss;

  if ( n == 1 ) 
  {
    peg2 = movePeg(n, isOdd, peg2);
    peg1 = movePeg(n, !isOdd, peg2);
    ss << "move disk " << n << " from " << peg1 << " to " << peg2; // your message
    cb( ss.str() ); // callback
    return;
  }

  // (a)Move top n - 1 disks from source to auxiliary(recursive call)
  hanoi_tower_1_rec(n - 1, cb, peg1, peg2, isOdd); 
  peg2 = movePeg(n, isOdd, peg2);


  // (b)Move largest disk from source to destination.
  ss << "move disk " << n << " from " << peg1 << " to " << peg2; // your message
  cb(ss.str()); // callback

  peg1 = movePeg(n, !isOdd, peg1);

  // (c)Move top n - 1 disks from source to destination(recursive call)
  peg2 = movePeg(n, isOdd, peg2);
  hanoi_tower_1_rec(n - 1, cb, peg1, peg2, isOdd);
}

char sub1(char peg)
{
  int toInt = (peg - 'A') + 3;
  
  return (--toInt % 3) + 'A';
}

char add1(char peg)
{
  int toInt = (peg - 'A') + 3;
  
  return (++toInt % 3) + 'A';
}

char movePeg(int n, bool isOdd, char peg)
{
  if(isOdd)
  {
    if(n % 2)
    {
      return sub1(peg);
    }
    else
    {
      return add1(peg);
    }
  }
  else
  {
    if(n % 2)
    {
      return add1(peg);
    }
    else
    {
      return sub1(peg);
    }
  }
}

template< typename CALLBACK >
void hanoi_tower_1( int n, CALLBACK cb ) 
{
  hanoi_tower_1_rec(n, cb, 'A', 'A', (n % 2));
}

////////////////////////////////////////////////////////////////////////////////
template< typename CALLBACK >
void hanoi_tower_2( int n, CALLBACK cb ) 
{
    hanoi_tower_1( n, cb ); // if not doing extra credit just leave it like this
}

////////////////////////////////////////////////////////////////////////////////
template< typename CALLBACK >
void hanoi_tower_3( int n, CALLBACK cb ) 
{
    hanoi_tower_1( n, cb ); // if not doing extra credit just leave it like this
}
