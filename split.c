// C-program to split a file into blocks of equal size done by Ojus Thomas
// Working up to spliting of file.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "tcpclientReadWriteFn.h"

/* This one is going to be in-core */

main(int argc, char **argv)
{
  int i, j, *vdm, *inv, *prod, cache_size;
  int rows, cols, blocksize, orig_size;
  int n, m, sz, *factors, tmp, factor;
  char *stem, *filename; 
  char **buffer,**buffer_new,*buf_file, *block;
  struct stat buf;
  FILE *f;
  typedef unsigned char unit;

  if (argc != 5) {
    fprintf(stderr, "usage: rs_encode_file1 filename n m stem\n");
    exit(1);
  }
  
  n = atoi(argv[2]);
  m = atoi(argv[3]);
  stem = argv[4];
  filename = argv[1];
  printf("\n**** n = %d ",n);
  printf("\n**** m = %d ",m);
  printf("\n**** stem = %s ",stem);
  printf("\n**** filename = %s ",filename);
  rows = n+m;
  cols = n;

  if (stat(filename, &buf) != 0) { // checks the status of the file , return 0 if successful and -1 otherwise.
    perror(filename);
    exit(1);
  }
  sz = buf.st_size;
  printf("\n @@@@@@@@@ sz : %d ,blocks allotted = %d",sz,buf.st_blksize);
  orig_size = buf.st_size; // size of the file in bytes
  if (sz % (n*sizeof(unit)) != 0) {
    sz += (n*sizeof(unit) - (sz % (n*sizeof(unit)))); // resizing the file size
  }
  printf("\n @@@@@@@@@ sz(resized) : %d ,sizeof(unit) = %d ",sz,sizeof(unit));
  blocksize = sz/n;
  printf("\n @@@@@@@@@ block size  : %d ",blocksize);

  buffer_new = (char **) malloc(sizeof(char *)*n); // creating buffer_new array (2D) to store the updated file slices
  for (i = 0; i < n; i++) {
    buffer_new[i] = (char *) malloc(blocksize); // allocating space for the each slice
    if (buffer_new[i] == NULL) {
      perror("Allocating buffer to store the whole file");
      exit(1);
    }
  }

  f = fopen(filename, "r");
  if (f == NULL) { perror(filename); }
  cache_size = orig_size;
  printf("\n Cache size = %d , blocksize = %d \n",cache_size,blocksize);
  for (i = 0; i < n; i++) {
    if (cache_size < blocksize) memset(buffer_new[i], 0, blocksize);
    if (cache_size > 0) {
      if (fread(buffer_new[i], 1, (cache_size > blocksize) ? blocksize : cache_size, f) <= 0) {
        fprintf(stderr, "Couldn't read the right bytes into the buffer\n");
        exit(1);
      }
    }
    cache_size -= blocksize;
  }
  fclose(f);
  stem = "code";
  int k = 0;
  buf_file = (char *) malloc(sizeof(char)*(strlen(stem)+30));
  if (buf_file == NULL) { perror("malloc - buf_file"); exit(1); }
  block = (char *) malloc(sizeof(char)*blocksize);
  if (block == NULL) { perror("malloc - block"); exit(1); }
  printf ("\n n : %d",n);
  char *ipt[] = {"192.168.42.70","192.168.42.186","192.169.42.187","192.168.42.70"};
  char 
  for (i = 0; i < n; i++) {
    sprintf(buf_file, "%s-%04d.rs", filename, i); // creates the filename for each coded unit.
    printf(" \n @@@@@@@@@@@@@  Writing %s ...", buf_file); //fflush(stdout);
    printf("\n No problem");

    //f = fopen(buf_file, "w");
    //printf("\n ******* File opened  %s \n ",f);
    //if (f == NULL) { printf("\n Problem");perror(buf_file); exit(1); }
    printf("\n ************* No problem i = %d",i);
    //fwrite(buffer_new[i], 1, blocksize, f);// writing the file into separate coded units
    /*if(i%2 == 0)
      k = 0;
    else 
      k = 1;*/
    printf("\n Writing to %s ",ipt[i]);
    connect_to_write(ipt[i],5000,buffer_new[i],buf_file);
    printf("\n Back from connect_to_write ");
    int j =0;
    while(j<30000)
    {
      j++;
    }
    //fclose(f);
    printf(" \n Done : %d th step \n",j);
  }
}
