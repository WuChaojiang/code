#include <stdio.h>
#include "Container.h"
#include "BaseFeature.h"


int main() 
{
    printf("Hello World!");
    // system("pause");
    Container c;
    c.testVector();

    A a;
    a.testForeach();
    a.testUniquePtr();
    a.testSharePtr();
    a.testWeakPtr();
    a.testLoopReference(); 
    a.testLambda();


    return 0;
}