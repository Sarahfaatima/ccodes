 
void tower(int n, char source, char temp, char destination) 
{ 
    if (n == 0) 
        return; 
    tower(n - 1, source, destination, temp); 
    printf("\nMove disc %d from %c to %c", n, source, destination); 
    tower(n - 1, temp, source, destination); 
} 
 
int main() 
{ 
    int n; 
    printf("\nEnter the number of discs: \n"); 
    scanf("%d", &n); 
     
    // Calculate total number of moves using a for loop 
    int totalMoves = 1; 
    for (int i = 0; i < n; i++) 
    { 
        totalMoves *= 2; // Total moves is 2^n 
    } 
    totalMoves -= 1; // Subtract 1 for the final result 
 
    tower(n, 'A', 'B', 'C'); 
    printf("\n\nTotal Number of moves are: %d\n", totalMoves); 
     
    return 0; 
} 