/* 
#define TRUE    1 
#define FALSE   0

#define RED 100 
#define BLACK 101 
#define GREEN 2004
#define BLUE 3007
*/

enum BOOL{
    FALSE=0, 
    TRUE
}; 

enum COLOR{
    RED=100, 
    BLACK=101, 
    GREEN=2004, 
    BLUE=3007
}; 

int main(void){
    enum BOOL status; 
    enum COLOR color;

    status = FALSE; 
    status = TRUE; 

    color = RED; 
    color = BLACK; 
    color = GREEN; 
    color = BLUE;  
}