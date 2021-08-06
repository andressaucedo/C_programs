 #include<stdio.h>



int main() {
int clem, circe, denna, dad, te, ga;

ga, te = 0;
clem = '1';
circe = '2';
denna = '3';
dad = '4';
start :
printf("%d***************************************************************\n",ga);
printf("%d*********************  WHO ARE YOU?  **************************\n",ga);
printf("%d***************************************************************\n",ga);
printf("%d If you are Clementine type 1 and press enter.\n",ga);
printf("%d If you are Circe type 2 and press enter.\n",ga);
printf("%d If you are Denna type 3 and press enter.\n",ga);
printf("%d If you are Dad type 4 and press enter.\n",ga);
printf("%d to exit press Ctrl+d\n\n",ga);
printf("%d ------------------->>>",ga);

  while((te = getchar()) != EOF)
    if (te == circe)
    {printf("%d" "   You are fun!\n\n\n",ga);
  goto start;}
else
    if (te == clem)
    {printf("%d" "   You are awesome!\n\n\n",ga);
  goto start;}
else
    if (te == denna)
    {printf("%d" "   You are so aesthetic!\n\n\n",ga);
  goto start;}
else
    if (te == dad)
  {
printf("%d" "   You are stinky and old!" " :(" "\n\n\n",ga);
printf("%d***************************************************************\n",ga);
printf("%d*   GGG  I  RRR    L                                          *\n",ga);
printf("%d*  G     I  R  R   L      <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   *\n",ga);
printf("%d*  G  GG I  RRR    L      <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   *\n",ga);
printf("%d*  G   G I  R  R   L                                          *\n",ga);
printf("%d*   GGG  I  R   R  LLLLL   GGG   AAA   NN   N   GGG     X     *\n",ga);
printf("%d*                         G     A   A  N N  N  G        X     *\n",ga);
printf("%d*  >>>>>>>>>>>>>>>>>>>>   G  GG A A A  N  N N  G  GG    X     *\n",ga);
printf("%d*  >>>>>>>>>>>>>>>>>>>>   G   G A   A  N   NN  G   G          *\n",ga);
printf("%d*  >>>>>>>>>>>>>>>>>>>>    GGG  A   A  N    N   GGG     X     *\n",ga);
printf("%d*                                                             *\n",ga);
printf("%d***************************************************************\n",ga);
 return 0;
  }

}
