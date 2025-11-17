#include <stdio.h>
#include <stdlib.h>

#define OPERAND_A 6
#define OPERAND_B 3

typedef int (*OperationFunc) (int a, int b);

/* IMPLEMENT ME: Declare your functions here */
int add (int a, int b); // '0'
int subtract(int a, int b); // '1'
int multiply(int a, int b); // '2'
int divide(int a, int b); // '3'
int exit_program(int a, int b); // '4'
int invalid_op(int a, int b);   // Function for any other digit input

int main (void)
{
	/* IMPLEMENT ME: Insert your algorithm here */
  OperationFunc operations[10] = {
        add,        // Index 0 ('0')
        subtract,   // Index 1 ('1')
        multiply,   // Index 2 ('2')
        divide,     // Index 3 ('3')
        exit_program, // Index 4 ('4')
        invalid_op,   // Index 5 ('5')
        invalid_op,   // Index 6 ('6')
        invalid_op,   // Index 7 ('7')
        invalid_op,   // Index 8 ('8')
        invalid_op,    // Index 9 ('9')
    };

    char input_char;
    int result;
    int array_index;

    while(1)
    {
      // Print out prompt.
      printf("Operand 'a' : %d | Operand 'b' : %d\n", OPERAND_A, OPERAND_B);
      printf("Specify the operation to perform (0 : add | 1 : subtract | 2 : Multiply | 3 : divide | 4 : exit): ");

      // Read the character input.
      scanf(" %c", &input_char);

      // Convert the character ('0'-'9') to an integer index (0-9).
      array_index = input_char - '0';

      // Clamp any input to the bounds of the 10-element array.
      int clamped_index = array_index % 10;

      // Execute the function pointer corresponding to the calculated index.
      result = operations[clamped_index](OPERAND_A, OPERAND_B);

      // Print results, excusing index 4 which terminates with exit(0).
      printf("x = %d\n", result);
    }

	return 0;
}

/* IMPLEMENT ME: Define your functions here */
int add (int a, int b) { 
  printf ("Adding 'a' and 'b'\n"); 
  return a + b;
}

int subtract (int a, int b) { 
    printf ("Subtracting 'b' from 'a'\n"); 
    return a - b; 
}

int multiply (int a, int b) { 
    printf ("Multiplying 'a' and 'b'\n"); 
    return a * b; 
}

int divide (int a, int b) {
    printf ("Dividing 'a' by 'b'\n"); 
    return a / b; 
}

// Function to handle program exit, conforming to the OperationFunc signature.
int exit_program(int a, int b) {
    exit(0);
    return 0; 
}

// Function to handle invalid operation input (digits '5' through '9').
int invalid_op(int a, int b) {
    printf ("Invalid operation specified.\n");
    return 0; // Returns 0, which is then printed as x=0.
}