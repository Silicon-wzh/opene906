/*Copyright 2020-2021 T-Head Semiconductor Co., Ltd.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#include "stdio.h"

int main (void)
{

//Section 1: Hello World!
  printf("\e[1;36m\nHello Friend!\e[0m\n");
  printf("\e[1;32mWelcome to T-HEAD World!\e[0m\n");

//Section 2: Embeded ASM in C 
  int a;
  int b;
  int c;
  a=1;
  b=2;
  c=0;

  printf("\e[1;33m");
  printf("\na is %d!\n",a);
  printf("b is %d!\n",b);
  printf("c is %d!\n",c);
  printf("\n\e[0m");

asm(
    "mv  x5,%[a]\n"
    "mv  x6,%[b]\n"
    "label_add:"
    "add  %[c],x5,x6\n"
    :[c]"=r"(c)
    :[a]"r"(a),[b]"r"(b)
    :"x5","x6"
    );

if(c == 3)
  printf("\e[1;32m!!! PASS !!!\e[0m\n");
else
  printf("\e[1;31m!!! FAIL !!!\e[0m\n");
  printf("after ASM c is changed to %d!\n\n",c);

  return 0;
}

