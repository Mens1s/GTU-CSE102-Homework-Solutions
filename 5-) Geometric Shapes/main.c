#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14

int select_shape();
int select_calc();
int calculate( int (*shapeType)(), int (*calType)() ); 
int calc_triangle(int choice);
int calc_quadrilateral(int choice);
int calc_circle(int choice);
int calc_pyramid(int choice);
int calc_cylinder(int choice);

int remain_in_stdin(){
    /*
        With this function I control of users last input which can includes non numeric char or not
        example input = 13'd'
        scanf cannot control of last digit or char in a input 

        -1 mean == it include
         0 mean == don't include

         10 mean == 'ENTER'
    */
    int x;
    do {
        x = getchar();
        if(x != 10) return -1;
        return 0;
    } while (x != '\n' && x != EOF );
}

void clean_stdin()
{   /*
        With this function I clean buffer for next scanf work perfectly.
    */
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

enum Shapes{
    Triangle=1,
    Quadrilateral,
    Circle,
    Pyramid,
    Cylinder
};

enum Calculators{
    Area=1,
    Perimeter,
    Volume
};

int main(){
    int choice;
    /*
        In main function I call only calculate function and program starts flowing...
        Calculate can be return 3 value:

         1 mean == Perfecty worked and continue
        -1 mean == User entered exit command
        -2 mean == User wants to imposible math calculation like volume of circle
    */
    printf("\nWelcome to the geometric calculator!\n\n");
    do{
        choice = calculate(select_shape,select_calc);
    }while(choice != -1);
    printf("Thanks for using program. Exiting..\n");
    return 0;
}

int select_shape(){
    /*int choice;*/
    enum Shapes choice;

    printf("\nSelect a shape to calculate:\n");
    printf("----------------------------\n");
    printf("1. Triangle\n2. Quadrilateral\n3. Circle\n4. Pyramid\n5. Cylinder\n0. Exit\n");
    printf("----------------------------\n");
    printf("Input : ");

    int control = scanf("%u",&choice);
    int control_buffer = remain_in_stdin();
    /*
        With this while loop Code is controlling of:
            User entered right type of input
            User entered right number of input
            User entered right number without char

        control Variable == control of inputs number
        control_buffer   == control of last digit includes char or not
    */
    while( control_buffer == -1 || control == 0 || (choice < Triangle-1 || choice > Cylinder)){
        printf("Please enter right type of choice or enter [0, 5] values! : ");

        if(control_buffer == -1) clean_stdin(); /* If last char doen't include char we don't need to clean buffer again */

        control = scanf("%u",&choice);
        control_buffer = remain_in_stdin();
    }

    switch (choice){

        case 0: /* Exit code */
            return -1;

        case Triangle:
            return Triangle;

        case Quadrilateral:
            return Quadrilateral;

        case Circle:
            return Circle;

        case Pyramid:
            return Pyramid;

        case Cylinder:
            return Cylinder;     
            
        default:
            printf("Please enter [1, 5] values!"); /* This code block does't work anytime because we checked it! */
            break;
    }

}

int select_calc(){
    /*  int choice;   */
    enum Shapes choice;
    printf("\nSelect calculator:\n");
    printf("----------------------------\n");
    printf("1. Area\n2. Perimeter\n3. Volume\n0. Exit\n");
    printf("----------------------------\n");
    printf("Input : ");

    int control = scanf("%u",&choice);
    int control_buffer = remain_in_stdin();
    /*
        With this while loop Code is controlling of:
            User entered right type of input
            User entered right number of input
            User entered right number without char

        control Variable == control of inputs number
        control_buffer   == control of last digit includes char or not
    */
    while( control_buffer == -1 || control == 0 || (choice < Area-1 || choice > Volume)){
        printf("Please enter right type of choice or enter [0, 3] values! : ");
        if(control_buffer == -1) clean_stdin();

        control = scanf("%u",&choice);
        control_buffer = remain_in_stdin();
    }

    switch (choice){

        case 0: /* Exit code */
            return -1;

        case Area:
            return Area;

        case Perimeter:
            return Perimeter;

        case Volume:
            return Volume;    
            
        default:
            printf("Please enter [1, 3] values!");
            break;
    }

}

int calculate(int (*shapeType)(), int (*calType)()){
    /*
        Getting inputs from user with functions!
    */
    enum Shapes shape = (*shapeType)();
    if(shape == -1) return -1;

    enum Calculators calculator = (*calType)();
    if(calculator == -1) return -1;

    switch (shape){    

        case Triangle:
            return calc_triangle(calculator);
            break;

        case Quadrilateral:
            return calc_quadrilateral(calculator);
            break;

        case Circle:
            return calc_circle(calculator);
            break;

        case Pyramid:
            return calc_pyramid(calculator);
            break;

        case Cylinder:
            return calc_cylinder(calculator);
            break;
            
        default:
            printf("\nERROR! UNKNOW ERROR\n"); /* This code never works */
            break;
    }
}

int calc_triangle(int choice){
    /* Variable Definition */
    float a, b, c;

    /* Triangle doesn't have volume math error! */
    if(choice == Volume){
        printf("ERROR ! You cannot calculate the volume of a triangle. Please try again.\n");
        return -2;/*Program should continue!*/
    }

    printf("\nPlease enter three sides of Triangle : \n\n");

    int control = scanf("%f%f%f",&a,&b,&c);
    int control_buffer = remain_in_stdin();

    /*  
        With this while loop Code is controlling of:
            User entered right type of input
            User entered right number of input
            User entered right number without char

        control Variable == control of inputs number
        control_buffer   == control of last digit includes char or not
    */

    while(control != 3 || control_buffer == -1){
        if(control_buffer == -1) clean_stdin();
        printf("\nERROR ! Please enter a valid entry.\n\n");
        control = scanf("%f%f%f",&a,&b,&c);
        control_buffer = remain_in_stdin();
    }
    

    float u = (a+b+c)/2.0;/* getting s which is in heron's formula */
    /* Rule of math ==> Any side of triangle cannot bigger than other sums */
    while(a + b <= c || a + c <= b || b + c <= a || a <= 0 || b <= 0 || c <= 0){
        
        printf("\nERROR ! Please enter a valid triangle.\n");

        control = scanf("%f%f%f",&a,&b,&c);
        control_buffer = remain_in_stdin();

        while(control != 3 || control_buffer == -1){
            if(control_buffer == -1) clean_stdin();
            printf("\nERROR ! Please enter a valid entry.\n");
            control = scanf("%f%f%f",&a,&b,&c);
            control_buffer = remain_in_stdin();
        }

        u = (a+b+c)/2; /* update of U */
    }
    switch (choice){

        case Area:
            printf("\nArea of TRIANGLE : %.2f\n",sqrt(u*(u-a)*(u-b)*(u-c))); /* Appliying heron's formula */
            return 1;
            break;

        case Perimeter:
            printf("\nPerimeter of TRIANGLE : %.2f\n",a+b+c);
            return 1;
            break;
    }

}

int calc_quadrilateral(int choice){
    /* Variable Definition */
    float a, b, c, d;

    if(choice == Volume){
        printf("ERROR ! You cannot calculate the volume of a quadrilateral. Please try again.\n");
        return -2;/*Program should continue!*/
    }

    printf("\nPlease enter four sides of Quadrilateral : \n");

    int control = scanf("%f%f%f%f",&a, &b, &c, &d);
    int control_buffer = remain_in_stdin();
    /*  
        With this while loop Code is controlling of:
            User entered right type of input
            User entered right number of input
            User entered right number without char

        control Variable == control of inputs number
        control_buffer   == control of last digit includes char or not
    */
    while(control != 4 || a <= 0 || b <= 0 || c <= 0 || d <= 0 || control_buffer == -1){
        if(control_buffer == -1) clean_stdin();
        printf("\nERROR ! Please enter a valid entry.\n\n");
        control = scanf("%f%f%f%f",&a, &b, &c, &d);
        control_buffer = remain_in_stdin();
    }

    float s = (a+b+c+d)/2.0;
    float area = (s-a)*(s-b)*(s-c)*(s-d); /*Getting area for Brahmagupta's Forumla*/

    while( control_buffer == -1 || (area < 0 && choice == Area )){ 

        printf("Your inputs are not valid for quadrilateral area which will calculated with Brahmagupta's formula!\nPlease enter a valid entry.\n\n");
        
        control = scanf("%f%f%f%f",&a, &b, &c, &d);
        control_buffer = remain_in_stdin();
        
        if(control_buffer == -1) clean_stdin();

        /* Updating s and area */
        s = (a+b+c+d)/2.0;
        area = (s-a)*(s-b)*(s-c)*(s-d);
    }
    switch (choice){

        case Area:
            printf("\nArea of Quadrilateral : %.2f\n",sqrt(area)); /* appliying Brahmagupta's formula */
            return 1;
            break;

        case Perimeter:
            printf("\nPerimeter of Quadrilateral : %.2f\n",a+b+c+d);
            return 1;
            break;
    }
}

int calc_circle(int choice){
    float r;

    if(choice == Volume){
        printf("ERROR ! You cannot calculate the volume of a Circle. Please try again.\n");
        return -2;/*Program should continue!*/
    }

    printf("\nPlease enter the radius of Circle : \n");

    int control = scanf("%f",&r);
    int control_buffer = remain_in_stdin();

    /*  
        With this while loop Code is controlling of:
            User entered right type of input
            User entered right number of input
            User entered right number without char

        control Variable == control of inputs number
        control_buffer   == control of last digit includes char or not
    */

    while(control != 1 || r <= 0 || control_buffer == -1){
        if(control_buffer == -1) clean_stdin();
        printf("\nERROR ! Please enter a valid entry.\n\n");

        control = scanf("%f",&r);
        control_buffer = remain_in_stdin();
    }

    switch (choice){

        case Area:
            printf("\nArea of CIRCLE : %.2f\n",PI*r*r);
            return 1;
            break;
            
        case Perimeter:
            printf("\nPerimeter of CIRCLE : %.2f\n",2*PI*r);
            return 1;
            break;
    }
}

int calc_pyramid(int choice){
    float a, h, l, d;
    int control; /* This control for number of inputs */
    int control_buffer;/* This control for last number is include char or not  */

    switch (choice){
        case Area:
            printf("\nPlease enter the base side and slant height of a Pyramid : \n");
            control = scanf("%f%f",&a,&l);
            control_buffer = remain_in_stdin();

            while(control != 2 || a <= 0 || l <= 0 || control_buffer == -1){
                if(control_buffer == -1) clean_stdin();
                printf("\nERROR ! Please enter a valid entry.\n\n");
                control = scanf("%f%f",&a,&l);
                control_buffer = remain_in_stdin();
            }

            printf("\nBase Surface Area of a PYRAMID : %.2f\n",a*a);
            printf("\nLateral Surface Area of a PYRAMID : %.2f\n",2*a*l);
            printf("\nSurface Area of a PYRAMID : %.2f\n",a*a+2*a*l);

            return 1;
            break;

        case Perimeter:
            printf("\nPlease enter the base edge length of a Pyramid: \n");
            control = scanf("%f",&a);
            control_buffer = remain_in_stdin();

            while(control != 1 || a <= 0 || control_buffer == -1){
                if(control_buffer == -1) clean_stdin();
                printf("\nERROR ! Please enter a valid entry.\n\n");
                control = scanf("%f",&a);
                control_buffer = remain_in_stdin();
            }           
            printf("\nPerimeter of PYRAMID : %.2f\n",4*(a));

            return 1;
            break;

        case Volume:
            printf("\nPlease enter the base side and height of a Pyramid : \n");
            control = scanf("%f%f",&a,&h);

            control_buffer = remain_in_stdin();

            while(control != 2 || a <= 0 || h <= 0 || control_buffer == -1){
                if(control_buffer == -1) clean_stdin();
                printf("\nERROR ! Please enter a valid entry.\n\n");
                control = scanf("%f%f",&a,&h);
                control_buffer = remain_in_stdin();
            }
            printf("\nPerimeter of PYRAMID : %.2f\n",(1.0/3.0)*(a*a)*(h));

            return 1;
            break;    
    }
}

int calc_cylinder(int choice){
    float r, h, l;
    int control; /* control of user inputs are right or not */

    printf("\nPlease enter the radius and height of a Cylinder : \n");

    control = scanf("%f%f",&r,&h);
    int control_buffer = remain_in_stdin();

    /*  
        With this while loop Code is controlling of:
            User entered right type of input
            User entered right number of input
            User entered right number without char

        control Variable == control of inputs number
        control_buffer   == control of last digit includes char or not
    */
   
    while(control != 2 || r <= 0 || h <= 0 || control_buffer == -1){
        if(control_buffer == -1) clean_stdin();
        printf("\nERROR ! Please enter a valid entry.\n\n");
        control = scanf("%f%f",&r,&h);
        control_buffer = remain_in_stdin();
    }

    switch (choice){

        case Area:
            printf("\nBase Surface Area of a CYLINDER : %.2f\n",PI*r*r);
            printf("\nLateral Surface Area of a CYLINDER : %.2f\n",2*PI*r*h);
            printf("\nSurface Area of a CYLINDER : %.2f\n",2*PI*r*(r+h));
            return 1;
            break;

        case Perimeter:
            printf("\n Base Surface Perimeter of CYLINDER : %.2f\n",2*PI*r);
            return 1;
            break;

        case Volume:
            printf("\nVolume of a CYLINDER : %.2f\n",PI*r*r*h);
            return 1;
            break;    
    }
}

