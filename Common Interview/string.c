// The MIT License (MIT)
// 
// Copyright (c) 2016 Trevor Bakker 
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// Purpose: Demonstrate some fun and common interview questions regarding strings

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** \brief Implements string copy
 *
 *  Implements string copy.  
 *
 *  \param src  - string to copy form
 *  \param dest - string to copy to.  Must be allocated
 *                outside this function
 *  \return     - nothing
 */
void stringCopy( char * src, char * dest )
{
  // verify the destination is non-NULL
  if( dest == NULL )
  {
    exit(1);
  }

  while( ( *dest++ = *src++ ) );

  return ;
}

/** \brief Reverse a string
 *
 *  Reverse a string using a temp char 
 *
 *  \param src  - string to reverse
 *  \return     - nothing
 */
void stringReverse( char * src )
{
  int length = strlen( src );
   
  int i;
  char temp;
  for( i = 0; i < length / 2 ; i++ )
  {
    temp = src[i];
    src[i]  = src[length - i - 1 ];
    src[length -i - 1] = temp;
  }
  return;
}

/** \brief Reverse a string in place with XOR
 *
 *  Reverse a string using XOR 
 *
 *  \param src  - string to reverse
 *  \return     - nothing
 */
void stringReverseXOR( char * src )
{
  int length = strlen( src );
   
  int i;
  char temp;
  for( i = 0; i < length / 2 ; i++ )
  {
    src[i]  ^= src[length - i - 1 ];
    src[length - i - 1 ] ^= src[i];
    src[i]  ^= src[length - i - 1 ];
  }
  return;
}

int main ()
{
  char * src_string = "Sample String";
  char * dest_string = (char * ) malloc( strlen( src_string ) ); 

  stringCopy( src_string, dest_string );
  printf("%s\n", dest_string );

  stringReverse( dest_string );
  printf("%s\n", dest_string );

  stringReverseXOR( dest_string );
  printf("%s\n", dest_string );

  free ( dest_string );
  return 0;
}
