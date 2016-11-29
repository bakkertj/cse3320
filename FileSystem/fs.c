// The MIT License (MIT)
// 
// Copyright (c) 2014 Trevor Bakker 
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

// Purpose:  This program shows the use of a few of the data structures
//           you will need for the MAV file system assignment. 
//           You are free to use this code in assignment 4 if you wish.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_BLOCKS 4226
#define BLOCK_SIZE 8192
#define NUM_FILES  128
#define NUM_INODES 128
#define MAX_BLOCKS_PER_FILE 32

unsigned char data_blocks[NUM_BLOCKS][BLOCK_SIZE];
         int  used_blocks[NUM_BLOCKS];

struct directory_entry {
  char * name;
  int    valid;
  int    inode_idx;
};

struct directory_entry *directory_ptr;

struct inode {
  int data;
  int valid;
  int blocks[MAX_BLOCKS_PER_FILE];  
};

struct inode * inode_array_ptr[NUM_INODES];

void init ()
{

  int i;
  directory_ptr = (struct directory_entry*) &data_blocks[0];

  for( i = 0; i < NUM_FILES; i++ )
  {
     directory_ptr[i].valid = 0;
  }

  int inode_idx = 0;
  for( i = 1; i < 130; i++ )
  {
    inode_array_ptr[inode_idx++] = (struct inode*) &data_blocks[i];
  }
}

int findFreeDirectoryEntry( )
{
  int i;
  int retval = -1;
  for( i = 0; i < 128; i++ )
  {
    if( directory_ptr[i].valid == 0 )
    {
      retval = i;
      break;
    }
  }
  return retval;
}

int findFreeInode( )
{
  int i;
  int retval = -1;
  for( i = 0; i < 128; i++ )
  {
    if( inode_array_ptr[i]->valid == 0 )
    {
      retval = i;
      break;
    }
  }
  return retval;
}

int main ()
{

  init();

  char * filename1 = "firstfile.txt";
  char * filename2 = "second_file.txt";

  // Lets find a spot for the first file 
  int dir_idx = findFreeDirectoryEntry( );
  printf("Found a free directory entry at %d for file %s\n", dir_idx, filename1 );

  // Now set this directory entry as used so we don't use it twice
  directory_ptr[dir_idx].valid = 1;

  // Allocate room for the filename
  directory_ptr[dir_idx].name = (char*)malloc( strlen( filename1 ) ); 
 
  // Copy the filename
  memcpy( directory_ptr[dir_idx].name, filename1, strlen( filename1 ) );

  // Lets find a spot for the second file 
  dir_idx = findFreeDirectoryEntry( );

  // Now set this directory entry as used so we don't use it twice
  directory_ptr[dir_idx].valid = 1;
 
  // Allocate room for the filename
  directory_ptr[dir_idx].name = (char*)malloc( strlen( filename2 ) ); 

  // Copy the filename
  memcpy( directory_ptr[dir_idx].name, filename2, strlen( filename2 ) );

  printf("Found a free directory entry at %d for file %s\n", dir_idx, filename2 );


  // Now iterate over the directory structure to make sure it's good.
  // This is similar to the list() function you need to write
  int idx = 0;
  for( idx = 0; idx < 128; idx++ )
  {
    if( directory_ptr[idx].valid == 1 )
    {
      printf("File: %s\n", directory_ptr[idx].name );
    }
  }
  return 0;
}
