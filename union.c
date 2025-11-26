 #include <stdio.h>
 // Convert normal set to bit string
 int createBitString(int set[], int size, int U[], int n) {
 int bitString = 0;
 for (int i = 0; i < size; i++) {
 for (int j = 0; j < n; j++) {
 if (set[i] == U[j]) {
 bitString |= (1 << (n - j - 1));
 }
 }
 }
 return bitString;
 }
 // Display set from bit string
 void displaySet(int bitString, int U[], int n) {
 int empty = 1;
 printf("{ ");
 for (int i = 0; i < n; i++) {
 if (bitString & (1 << (n - i - 1))) {
 printf("%d ", U[i]);
 empty = 0;
 }
 }
 if (empty) printf("∅ ");
 printf("}\n");
 }
 int main() {
 int n, sizeA, sizeB, choice;
 int U[20], A[20], B[20];
 int bitA, bitB, bitU, result;
 printf("Enter size of Universal Set: ");
 scanf("%d", &n);
 printf("Enter elements of Universal Set: ");
 for (int i = 0; i < n; i++)
 scanf("%d", &U[i]);
 printf("Enter number of elements in Set A: ");
 scanf("%d", &sizeA);
 printf("Enter elements of Set A: ");
 for (int i = 0; i < sizeA; i++)
 scanf("%d", &A[i]);
 printf("Enter number of elements in Set B: ");
 scanf("%d", &sizeB);
 printf("Enter elements of Set B: ");
 for (int i = 0; i < sizeB; i++)
 scanf("%d", &B[i]);
 // Convert sets to bit strings
 bitA = createBitString(A, sizeA, U, n);
 bitB = createBitString(B, sizeB, U, n);
 bitU = (1 << n) - 1; // All bits set for universal set
 while (1) {
 printf("\n--- Set Operations Menu ---\n");
 printf("1. Union (A ∪ B)\n");
 printf("2. Intersection (A ∩ B)\n");
 printf("3. Difference (A - B)\n");
 printf("4. Complement of A (U - A)\n");
 printf("5. Exit\n");
printf("Enter your choice: ");
 scanf("%d", &choice);
 if (choice == 5) {
 printf("Exiting program...\n");
 break;
 }
 switch (choice) {
 case 1:
 result = bitA | bitB;
 printf("A ∪ B = ");
 displaySet(result, U, n);
 break;
 case 2:
 result = bitA & bitB;
 printf("A ∩ B = ");
 displaySet(result, U, n);
 break;
 case 3:
 result = bitA & (~bitB);
 printf("A - B = ");
 displaySet(result, U, n);
 break;
 case 4:
 result = bitU & (~bitA);
 printf("U - A = ");
 displaySet(result, U, n);
 break;
 default:
 printf("Invalid choice! Try again.\n");
 }
 }
 return 0;
 }
