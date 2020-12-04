#include <stdio.h>

int main(){

    int a,b,c,kv,num,numba,finalValue;

    for(a=1;a<=9;a++){
       for(b=a;b<=9;b++)
       {
          for(c=b;c<=9;c++){
              num=a*100;
              num+=b*10;
              num+=c;
              numba = 0;
              finalValue = 0;
              for(kv=1;kv<=num;kv++){
                if(kv*kv==num){
                    numba=kv; break;
                }
                if(kv*kv>num) break;
              }
              if(numba == 0) continue;
              for(kv=1;kv<=numba;kv++){
               if(numba%kv==0) finalValue++;}
               if(finalValue==2)
          {
             printf("%d", num);
             printf("\n");
          } 
       }
    }
}

 return 0;
}
