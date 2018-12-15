# include<stdio.h>
# include<string.h>
# include<unistd.h>
# include<fcntl.h>

int main() {

   struct flock lock, savelock;
   char msg[80];
   int fp = open("testfile.txt",O_RDWR);   
   
   if(fp == -1){
      printf("Error In File Opening\n");
      return 0;
   }

   lock.l_type = F_WRLCK;
   lock.l_whence = SEEK_SET;
   lock.l_start = 0;
   lock.l_len = 0;

   savelock = lock;

   fcntl(fp, F_GETLK, &lock);

   if(lock.l_type != F_UNLCK) {

      printf("File is Locked from before.\n");

      while(lock.l_type != F_UNLCK)
         fcntl(fp, F_GETLK, &lock);
      
      printf("\nFile Unlocked\n");
      read(fp, msg, 80);
      printf("\nMessage Read From The File Is : %s\n", msg);

   }  else {

      printf("Reading and locking the file\n");

      read(fp, msg, 80);

      printf("\nMessage Read From File Is : %s", msg);
   }

      printf("\n\nFile Locked. Press ENTER to unlock\n");
      fcntl(fp, F_SETLK, &savelock);
      getchar();

      savelock.l_type = F_UNLCK;  
      fcntl(fp, F_SETLK, &savelock);
   
   
   close(fp);
   return 0;
}


