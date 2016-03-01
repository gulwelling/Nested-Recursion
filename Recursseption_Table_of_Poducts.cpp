//This program is an example of nested recursion using mostly if not exclusively C code
//This program takes a number and creates the multiplication table for that number
#include <cstdio>

void recusiveRows(int, int);//this function recusively creates one row of the multiplication table
void recusiveColumns(int, int);//this function recursively calls recusiveRows() to create the table

int main(){
	char goOn = 'y';//This is the variable to loop the program
	int s;//this is the size of the table
	do{
		printf("Input an number you would like to see the multiplication table for.\n");//prompts the user to input a number
		s = (getchar() - 48);//inputs the size of the table
		recusiveColumns(s,s);//calls the nested recursive program to create the table
		printf("Would you like to continue?");//prompts the user to see if they want to continue
		goOn = getchar();
	}while(goOn != 'y');
	getchar();//pauses the program
	return 0;
}
//this function recusively creates one row of the multiplication table
void recusiveRows(int h, int w){
	//this is an erroneous input case
	if(w < 1)
		std::printf("Error wrong width");//error message
	//this is the base case that simply outputs the first digit of the row
	else if(w == 1)
		printf("%d ",h);
	//this is the recursive call case of the of the function
	else{
		recusiveRows(h,w-1);//recursive call, the h remains the same because we are staying in this row, the width changes because we have to move on to the number
		printf("%d ",h*w);//print out the number, it comes after the recursive call so that it prints all the precedeing numbers first
	}
}
//This program takes a number and creates the multiplication table for that number
void recusiveColumns(int h, int w){
	//this is an erroneous input case
	if(h < 1)
		std::printf("Error wrong height");//error message
	//base case, call the first row
	else if(h == 1){
		recusiveRows(1,w);//this call recursively creates one row
		printf("\n");//new line
	}
	//recursive case
	else{
		recusiveColumns(h-1,w);//recursively calls to create the rows
		recusiveRows(h,w);//recursive call to create the current row, this comes after the columns call to print everything in the right order
		printf("\n");//new line
	}
}