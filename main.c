#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
//#include <assert.h>

//Does not support quotations.

//Also need to store 4 letters 

//This defines what a node is.
typedef struct node {
   char data; //Data we want to store in our linked list. We will store the first letter here.
   char dataTwo; //Store the 2nd, 3rd, and fourth letter of a word.
   char dataThree;
   char dataFour;

   int length; //Store the amount of letters.
   //Note to self: Use sizeof() each four letter word to put into length.
   struct node* next; //Next part in a linked list.
  //struct node *next;
}
node;
//maximum amount of nodes possible in the linkest list
#define maximumNodeCount 100

//Global Variables
const int twoDArraySizeOne = 99;
const int twoDArraySizeTwo = 100;
const char done[]="DONE";
const char searchC[]="SEARCHC";
const char searchI[]="SEARCHI";
const char delet[]="DELETE";
const char add[]="ADD";

//Function to create nodes.
node *createNode(char insertToNode, char insertToNodeTwo, char insertToNodeThree, char insertToNodeFour, int wordLength) {
  static node manyNodes[maximumNodeCount];
  static int  nextNode = 0;
  static char temp;

    printf( "[node  *create_node( int a )]\r\tnext_node = %d; index = %d\n", nextNode, insertToNode);
    if (nextNode >= maximumNodeCount)
    {
        printf("Maximum node count reached.\n");
        return (node *)NULL;
    }

    node *nodeReturn = &(manyNodes[nextNode++]);


    nodeReturn->data = insertToNode; //Data added to node.
    nodeReturn->dataTwo = insertToNodeTwo;
    nodeReturn->dataThree = insertToNodeThree;
    nodeReturn->dataFour = insertToNodeFour;
    nodeReturn->length = wordLength;
    nodeReturn->next = NULL; //The linked list's last node points to NULL.

    return nodeReturn; 
}

//Deletes the entire linked list.
void deleteLinkedList(struct node** head){
  struct node* previousNode = *head;
  struct node* next;
  
  while (*head!=NULL)
    {
      //Test code
      printf("Deleting %d\n", previousNode->data);
      
        *head = (*head)->next;
      
        previousNode=NULL;
        
        previousNode = *head;
    }
  *head=NULL;
}

//Reassign the linked list by putting the new alphabet order into the old linked list.
node alphabetOrderLinkedList(node *alphabetRoot, char array[twoDArraySizeOne][twoDArraySizeTwo], int lengthArray[]){
  node *temporary, *newTemporary;
  int sizeOne, sizeTwo;
  char charUltimate[5];
  int newLength=0;
  int lengthIndexCounter=-1;

  printf("\nChecking  Linked List In Alphabet Function:\n");
  for (temporary = alphabetRoot; temporary != NULL; temporary = temporary->next){
    printf("%c", temporary->data); 
    printf("%c", temporary->dataTwo); 
    printf("%c", temporary->dataThree); 
    printf("%c", temporary->dataFour);
    printf("%d", temporary->length);
    printf("\n");
  }
printf("\n");

  printf("\nChecking 2D Array in Function:\n");
  //Prints from the 2D array and puts it into the old linked list
  temporary = alphabetRoot;
  for (sizeOne = 0; sizeOne < twoDArraySizeOne; sizeOne++){
    //temporary = temporary->next;
    
    if (array[sizeOne][sizeTwo]!='\0'&& iswalpha(array[sizeOne][sizeTwo])){
      printf("%s", array[sizeOne]);
      printf("\n");
      printf("Best Wishes, John Green");
      printf("\n");
      strcpy(charUltimate, array[sizeOne]);
      puts(charUltimate);
      printf("\n");
      //These if statements check how many letters the word have.
      //Yes, I could use a for loop, but with 4, this felt simpler.
      if (iswalpha(charUltimate[0])){
        //printf("ORANGES0:%c \n", charUltimate[0]);
        newLength+=1;
      }
       if (iswalpha(charUltimate[1])){
         //printf("ORANGES1:%c \n", charUltimate[1]);
        newLength+=1;
      }
       if (iswalpha(charUltimate[2])){
         //printf("ORANGES2:%c \n", charUltimate[2]);
        newLength+=1;
      }
       if (iswalpha(charUltimate[3])){
         //printf("ORANGES3:%c \n", charUltimate[3]);
        newLength+=1;
      }
      //Plug 2D array's alphabet words into the old linked list
      //Complicated if, else if, etc. is to avoid a weird bug.
      if (!iswalpha(charUltimate[1])){
        newTemporary=createNode(charUltimate[0], '\0', '\0', '\0', 1);
        }
      else if (!iswalpha(charUltimate[2])){
          newTemporary=createNode(charUltimate[0], charUltimate[1], '\0', '\0', 2);
        }
      else if (!iswalpha(charUltimate[3])){
          newTemporary=createNode(charUltimate[0], charUltimate[1], charUltimate[2], '\0', 3);
        }
      else{
      newTemporary=createNode(charUltimate[0], charUltimate[1], charUltimate[2], charUltimate[3], lengthArray[lengthIndexCounter]); 
      }
      temporary->next = newTemporary; //Move on to the next node. 

    if (newTemporary) {
    temporary = temporary->next;
                    }
      newLength=0;
     }
    else if (sizeOne!=0) {
     sizeOne=100;
      }
    lengthIndexCounter+=1;
    }

  printf("\n");
  printf("\nTesting part of putting 2D Array Into Linked List\n");
for (temporary = alphabetRoot; temporary != NULL; temporary = temporary->next){
    printf("%c", temporary->data); 
    printf("%c", temporary->dataTwo); 
    printf("%c", temporary->dataThree); 
    printf("%c", temporary->dataFour);
    printf("%d", temporary->length);
    printf("\n");
  }
printf("\n");

  return *alphabetRoot;
  }

/*
void deleteNode(node head){
struct node* temporaryForDeletion=&head;
while(temporaryForDeletion->next->next!=NULL)
{
  temporaryForDeletion= temporaryForDeletion->next ;
}
temporaryForDeletion->next= NULL;

while(temporaryForDeletion->next->next!=NULL)
{
  temporaryForDeletion= temporaryForDeletion->next;
}
temporaryForDeletion->next= NULL;
}*/


////MAIN STARTS HERE////
int main(void) {
  
//Variables for the linked list creation.
char sentence[100]; //This creates the string.
int wordLength;
int index; 
  //node *newTemporary, *root, *temporary, *goodbyeLinkedList; 
node *newTemporary, *root, *temporary; 
char inputLetterOne[2], inputLetterTwo[2], inputLetterThree[2], inputLetterFour[2];
int indexOnce=0;
int indexTwoTimes=0;
int indexThreeTimes=0;
int indexFourTimes=0;

//Stores the original length of words to transfer from first linked list to alphabet sorted linked list.
int originalWordLength[100];
int alphabetWordLength[100];
int originalWLCounter=0;
int alphabetWLCounter=0;
char charTracker[5];
//int nindex=0;

//Variables for alphabet sorting.
int jindex=0; 
int kindex=0;
int lindex=0;
int counter=0; //Counting the amount of words in a linked list.
char alphabetSortingTwoDArray[100][100], alphabetInputArray[5];
//char *wordStorage;
char wordStorage[100];

//Varables to handle further user commands after creating the alphabet ordered linked list.
char command[8];
char input[5];
char nodeToCheck[5];
int matchingWordBoolean=0;
char wordToAdd[46]; //pneumonoultramicroscopicsilicovolcanoconiosis
int wordToAddLength=0;


root = createNode(0, 0, 0, 0, 0); //Make the first root node (i.e. the head of the linked list).
temporary= root; //Make the temporary node the root.
  

//goodbyeLinkedList = root; //Helps us delete the linked list later.

//Prompt the user to input text.
printf("Enter your a sentence: \n");

//Save the sentence.
//scanf("%s",sentence); //Works but only first word
fgets(sentence, sizeof(sentence), stdin); 
  
  //scanf("%c",sentence);
//(sentence, sizeof(sentence), stdin); DOES NOT WORK
  //fgets(sentence, 100, stdin);
//fgets(sentence, sizeof(sentence), stdin); CAN WORK

//Test code
  //printf("%s", sentence);
printf("%s\n", sentence);

  //createNode(sentence[index])
  //for (index = 0; (newTemporary=createNode(sentence[index])) && index < maximumNodeCount; ++index) {
  //for (index = 0; index < maximumNodeCount; index++){
  //FOR LOOP NEEDS TO GO THROUGH EACH WORD INDIVIDUALLY
  //I NEED A CONTINUE FOR EVERY BLANK SPACE

for (index = 0; index < maximumNodeCount; index+=1) { 

    //Because there's a very weird bug that occurs after the sentence linked list creation is done, I put this if statement here. Without these few lines, the linked list will save characters and symbols that were never in the input prompt.
if (!iswalpha(sentence[index]) && !iswalpha(sentence[index+1]) && !iswalpha(sentence[index+2]) && !iswalpha(sentence[index+3]) ) {
  index=maximumNodeCount;
}

  //Reset wordLength variable to 0 so that each word counts back at 0.
  wordLength=0;

  //char test[5];
  //strncpy(test, &sentence[index], 4);
  //Test code
  printf("PROGRAM TAKE THE WHEEL: %c \n", sentence[index]);
  printf("PROGRAM TAKE THE WHEEL: %c \n", sentence[index+1]);
  printf("PROGRAM TAKE THE WHEEL: %c \n", sentence[index+2]);
  printf("PROGRAM TAKE THE WHEEL: %c \n", sentence[index+3]);

  //Check for non-appropriate characters for the first index of the sentence.
  if (sentence[index]!=' ' && sentence[index]!= '\0' && sentence[index]!= '.' && sentence[index]!= '!' && sentence[index]!= '?' && sentence[index]!= '-' && sentence[index]!= ';' && sentence[index]!= ':' && sentence[index]!= ',') {
    inputLetterOne[1]=sentence[index];
    printf("Testing is useful: %c \n", inputLetterOne[1]);
    wordLength+=1;

    /////////////////////////////////FIRST NEST/////////////////////////////////////////
    //Check for non-appropriate characters for the second index of the sentence.
    if (sentence[index+1]!=' ' && sentence[index+1]!= '\0' && sentence[index+1]!= '.' && sentence[index+1]!= '!' && sentence[index+1]!= '?' && sentence[index+1]!= '-' && sentence[index+1]!= ';' && sentence[index+1]!= ':' && sentence[index+1]!= ','&& iswalpha(sentence[index+1])) {
      inputLetterTwo[1]=sentence[index+1];
      printf("Testing is useful: %c \n", inputLetterTwo[1]);
      wordLength+=1;
      

      /////////////////////////////SECOND NEST//////////////////////////////////////
      //Check for non-appropriate characters for the third index of the sentence.
      if (sentence[index+2]!=' ' && sentence[index+2]!= '\0' && sentence[index+2]!= '.' && sentence[index+2]!= '!' && sentence[index+2]!= '?' && sentence[index+2]!= '-' && sentence[index+2]!= ';' && sentence[index+2]!= ':' && sentence[index+2]!= ',' && iswalpha(sentence[index+2])) {
        inputLetterThree[1]=sentence[index+2];
        printf("Testing is useful: %c \n", inputLetterThree[1]);
        wordLength+=1;

        
        /////////////////////////////THIRD NEST//////////////////////////////////////
        //Check for non-appropriate characters for the fourth index of the sentence.
        if (sentence[index+3]!=' ' && sentence[index+3]!= '\0' && sentence[index+3]!= '.' && sentence[index+3]!= '!' && sentence[index+3]!= '?' && sentence[index+3]!= '-' && sentence[index+3]!= ';' && sentence[index+3]!= ':' && sentence[index+3]!= ',' && iswalpha(sentence[index+3])) {
          inputLetterFour[1]=sentence[index+3];
          printf("Testing is useful: %c \n", inputLetterFour[1]);
          printf("Poor RTGame: %c \n", sentence[index]);
          indexFourTimes=1;
          printf("Doug Doug, do another AI invasion: %c \n", sentence[index]);
          wordLength+=1;
          
          //Skip the rest of words with more than 4 letters.
          //while (sentence[index+4]!=' ' && sentence[index+4]!= '\0' && sentence[index+4]!= '.' && sentence[index+4]!= '!' && sentence[index+4]!= '?' && sentence[index+4]!= '-' && sentence[index+4]!= ';' && sentence[index+4]!= ':' && sentence[index+4]!= ',')
          while (sentence[index+4]!=' ' && sentence[index+4]!= '\0' && sentence[index+4]!= '.' && sentence[index+4]!= '!' && sentence[index+4]!= '?' && sentence[index+4]!= '-' && sentence[index+4]!= ';' && sentence[index+4]!= ':' && sentence[index+4]!= ',' && iswalpha(sentence[index+4])){
            printf("\nWAKA\n");
            index+=1;
            wordLength+=1;
          }
                                                                         }
  else {
    indexThreeTimes=1;
    inputLetterFour[1]='\0';
  }
  //For three letter words, make the last data in the node blank.
  //Spaces are not needed.
  if (sentence[index+3]==' ' || sentence[index+3]=='!'|| sentence[index+3]=='?' || sentence[index+3]=='-' || sentence[index+3]==';' || sentence[index+3]==':' || sentence[index+3]=='.'){
    inputLetterFour[1]='\0';
    indexThreeTimes=1;
    //index+=3;
    }
  else if(sentence[index+3]==','){
     indexThreeTimes=1;
      //inputLetterFour[1]='\0';
      //index+=3;
     }
                                                                     }
      else {
        inputLetterThree[1]='\0';
        indexTwoTimes=1;
        
  }
      //For two letter words, make the rest of the two datas in the node blank.
      //Spaces are not needed.
      if (sentence[index+2]==' '|| sentence[index+2]=='!'|| sentence[index+2]=='?' || sentence[index+2]=='-' || sentence[index+2]==';' || sentence[index+2]==':'|| sentence[index+2]=='.'){
        inputLetterThree[1]='\0';
        inputLetterFour[1]='\0';
        //index+=2;
        indexTwoTimes=1;
        
    }
    else if(sentence[index+2]==','){
      inputLetterFour[1]='\0';
      //index++;
      indexOnce=1;
    }
                                                            }
    else {
      inputLetterTwo[1]='\0';
      indexOnce=1;
      
  }
    //For one letter words, make the rest of the three datas in the node blank.
    //Spaces are not needed.
    if (sentence[index+1]==' '|| sentence[index+1]=='!'|| sentence[index+1]=='?' || sentence[index+1]=='-' || sentence[index+1]==';' || sentence[index+1]==':' || sentence[index+1]=='.'){
      inputLetterTwo[1]='\0';
      inputLetterThree[1]='\0';
      inputLetterFour[1]='\0';
      indexOnce=1;
      //index++;
    }
    else if(sentence[index+1]==','){
      inputLetterThree[1]='\0';
      inputLetterFour[1]='\0';
      indexOnce=1;
      //index++;
    }
                                        }
    //If the first index is blank, start the whole process again at the next index.
  else {
    printf("Checking the continue else: %c \n", sentence[index]);
    //index++;
    printf("Checking the continue else again: %c \n", sentence[index]);
    continue;
    }
  
  newTemporary=createNode(inputLetterOne[1], inputLetterTwo[1], inputLetterThree[1], inputLetterFour[1], wordLength); //Make a new node.
  temporary->next = newTemporary; //Move on to the next node. 

  if (newTemporary) {
    printf("temporary->index = %d\n", temporary->data);
    printf("temporary->next->index = %d\n", temporary->next->data);
    printf("TEST CODE: %c \n", temporary->data); 
    temporary = temporary->next;
                    }

  //Four four letter words or longer, increase the index here.
  if (indexFourTimes==1){
    index+=4;
  }
  //Four three letter words, increase the index here.
  if (indexThreeTimes==1){
    index+=3;
  }
  if (indexTwoTimes==1){
    index+=2;
  }
  if (indexOnce==1){
    index+=1;
  }
  
  //Reset these char arrays. Otherwise, extra letters that we don't want will be saved in nodes.
      inputLetterOne[1]='\0';
      inputLetterTwo[1]='\0';
      inputLetterThree[1]='\0';
      inputLetterFour[1]='\0';
  //Reset the index counters to 0.
      indexThreeTimes=0;
      indexFourTimes=0;
      indexOnce=0;
      indexTwoTimes=0;
//Reset wordLength variable to 0 so that each word counts back at 0.
      wordLength=0;
                                                                          
                                                       }

printf("\nChecking First Time Linked List Creation:\n");
//The for loop prints the letters in the linked list.
for (temporary = root; temporary != NULL; temporary = temporary->next){
    printf("%c", temporary->data); 
    printf("%c", temporary->dataTwo); 
    printf("%c", temporary->dataThree); 
    printf("%c", temporary->dataFour);
    printf("%d", temporary->length);
    printf("\n");
  
    //char alphabetInputArray[5] = {temporary->data, temporary->dataTwo, temporary->dataThree, temporary->dataFour};
    //alphabetSortingTwoDArray[jindex]= alphabetInputArray;
  
    //Keeps the length of words from the linked list to put in the alphabet sorter later.
    originalWordLength[originalWLCounter]=temporary->length;
    originalWLCounter+=1;

    //Stores words from the linked list to alphabet sort later.
    alphabetInputArray[0]=temporary->data;
    alphabetInputArray[1]=temporary->dataTwo;
    alphabetInputArray[2]=temporary->dataThree; 
    alphabetInputArray[3]=temporary->dataFour;
    strcpy(alphabetSortingTwoDArray[lindex], alphabetInputArray);
    
    counter+=1;
    lindex=lindex+1;
    //printf("%s", alphabetInputArray);
    //printf("%s", alphabetSortingTwoDArray[lindex]);
    //printf("\n");
  }
  printf("\n");

  //These for loops alphabetically sort the word in the linked list.
  //alphabeticallySortWords(alphabetSortingTwoDArray[][100], counter);
  //qsort(alphabetSortingTwoDArray[0][100], counter, 100, strcasecmp);
  
   for(jindex=0;jindex<counter;jindex++){
      for(kindex=jindex+1;kindex<counter;kindex++){
        //if(strcmp(alphabetSortingTwoDArray[jindex], alphabetSortingTwoDArray[kindex])>0){
         if(strcasecmp(alphabetSortingTwoDArray[jindex], alphabetSortingTwoDArray[kindex])>0){
            strcpy(&wordStorage[0], alphabetSortingTwoDArray[jindex]);
            strcpy(alphabetSortingTwoDArray[jindex], alphabetSortingTwoDArray[kindex]);
            strcpy(alphabetSortingTwoDArray[kindex], &wordStorage[0]);
         }
      }
   }
  
   printf("\n");
   printf("The sorted order of words are:");
   for(jindex=0;jindex<counter;jindex++){
      printf("%s",alphabetSortingTwoDArray[jindex]);
   }

  //TEST CODE
  //The for loop prints the letters in the linked list.
printf("\nChecking Original Linked List Not Affected Yet After Alphabet Sorting:\n");
for (temporary = root; temporary != NULL; temporary = temporary->next){
    printf("%c", temporary->data); 
    printf("%c", temporary->dataTwo); 
    printf("%c", temporary->dataThree); 
    printf("%c", temporary->dataFour);
    printf("%d", temporary->length);
    printf("\n");
  }
  printf("\n");

  printf("\nTesting alphabetWordList addition:\n"); 
  //Compare alphabet 2D array and original linked list to store the original lengths into an int array.
  //I need to compare the order reversed...alphabet 2D array for every linked list node, NOT every linked list nodes for all alphabet array.
   for(jindex=0;jindex<counter;jindex++){
     strcpy(charTracker, alphabetSortingTwoDArray[jindex]);
   temporary=root;
     
  for(temporary=root; temporary != NULL; temporary = temporary->next){
    //Skip root node.
    if (temporary->data==0 && temporary->dataTwo==0 &&temporary->dataThree==0 && temporary->dataFour==0 && temporary->length==0){
     temporary = temporary->next;
    }

    //printf("\nAll Before:\n"); 
      //printf("%s", charTracker); 
      //printf("2DArray: %s", alphabetSortingTwoDArray[jindex]); 
      //printf("%c", temporary->data); 
      //printf("%c", temporary->dataTwo); 
      //printf("%c", temporary->dataThree); 
      //printf("%c", temporary->dataFour);
    
      
    //Checking for letters in 2Darray and that letters in 2Darray match linked list's letters in their nodes.

      if (temporary->length==1){
        if(charTracker[0]==temporary->data&&iswalpha(charTracker[0])){
          alphabetWordLength[alphabetWLCounter]=temporary->length;
        alphabetWLCounter+=1;
           printf("Hmm\n"); 
          printf("%d", temporary->length); 
           printf("\n"); 
          temporary=root;
          break;
        }
      }
      else if (temporary->length==2){
        if(charTracker[0]==temporary->data && charTracker[1]==temporary->dataTwo &&iswalpha(charTracker[0]) &&iswalpha(charTracker[1])){
        
        alphabetWordLength[alphabetWLCounter]=temporary->length;
       // printf("\nTemp Length:\n"); 
        //printf("%d", temporary->length); 
        alphabetWLCounter+=1;
          printf("Hmm\n"); 
          printf("%d", temporary->length); 
           printf("\n"); 
          temporary=root; 
          break;
            }
      }
      else if (temporary->length==3){
        if(charTracker[0]==temporary->data && charTracker[1]==temporary->dataTwo && charTracker[2]==temporary->dataThree&&iswalpha(charTracker[0]) &&iswalpha(charTracker[1])&&iswalpha(charTracker[2])){
        
        alphabetWordLength[alphabetWLCounter]=temporary->length;
        //printf("\nTemp Length:\n"); 
        //printf("%d", temporary->length); 
        alphabetWLCounter+=1;
          printf("Hmm\n"); 
          printf("%d", temporary->length); 
           printf("\n"); 
          temporary=root;
          break;
            }
      }
      else if(temporary->length>=4){
        if(charTracker[0]==temporary->data && charTracker[1]==temporary->dataTwo && charTracker[2]==temporary->dataThree&&charTracker[3]==temporary->dataFour&&iswalpha(charTracker[0]) &&iswalpha(charTracker[1])&&iswalpha(charTracker[2])&&iswalpha(charTracker[3])){
        
        alphabetWordLength[alphabetWLCounter]=temporary->length;
        //printf("\nTemp Length:\n"); 
        //printf("%d", temporary->length); 
        alphabetWLCounter+=1;
          printf("Hmm\n"); 
          printf("%d", temporary->length); 
           printf("\n"); 
          temporary=root; 
          break;
            }
      }
      }
   }

  //Important function call to sort the linked list alphabetically.
  alphabetOrderLinkedList(root, alphabetSortingTwoDArray, alphabetWordLength);

  //The for loop prints the letters in the linked list.
printf("\nChecking If alphabetOrderLinkedList Worked:\n");
for (temporary = root; temporary != NULL; temporary = temporary->next){
    printf("%c", temporary->data); 
    printf("%c", temporary->dataTwo); 
    printf("%c", temporary->dataThree); 
    printf("%c", temporary->dataFour);
    printf("%d", temporary->length);
    printf("\n");
  }

  
printf("\nChecking originalWordLength:\n");
  //printf("%d", originalWordLength[0]);
  for (index=1; originalWordLength[index]>0 ; index+=1){
     printf("%d", originalWordLength[index]);
  }

printf("\nChecking alphabetWordLength:\n");
  //printf("%d", originalWordLength[0]);
  //for (index=0; alphabetWordLength[index]>0 ; index+=1)
  for (index=0; index<counter-1 ; index+=1){
     printf("%d", alphabetWordLength[index]);
  }



//Save the sentence.
      //while (command[0]!=*done||alternativeDone==3)
//The loop will continue until DONE is typed in.
while (strcmp(command, done)){
  matchingWordBoolean=0;
  //Prompts users for commands after making the linked list and sorting it in alphabetical order.
printf("\nType DELETE to delete the entire linked list.\nType SEARCHC to search for a word while being case sensitive.\nType SEARCHI to search for word regardless of case sensitivity.\nTyped ADD to add a word to the linked list.\nType DONE to finish the program (or type anything else three times).\n");
  
  scanf("%s", command);
  printf("%s",command);
  if (!strcmp(command, done)){
    break;
    
  }
  //Search case insensitive mode
  //BUGGED
    if (!strcmp(command, searchI)){
    printf("\nWhat is the word you a search for?\nIf it's more than four letters, just type the first four letters.\n");
      scanf("%s", input);
    printf("%s", input);
    printf("TEST:");
    printf("%s\n", input);
    //printf("%s\n", &input[5]);
    //printf("%s\n", &input[6]);
    //printf("%s\n", &input[3]);
    printf("\n");
    for (temporary = root; temporary != NULL; temporary = temporary->next){
     //if (!strcasecmp(&temporary->data, &input[0])&&!strcasecmp(&temporary->dataTwo, &input[1])&&!strcasecmp(&temporary->dataThree, &input[2])&&!strcasecmp(&temporary->dataFour, &input[3]))
      //if (tolower(temporary->data)==input[0]&&temporary->dataTwo==input[1]&&temporary->dataThree==input[2]&&temporary->dataFour==input[3])
      nodeToCheck[0]=temporary->data;
      nodeToCheck[1]=temporary->dataTwo;
      nodeToCheck[2]=temporary->dataThree;
      nodeToCheck[3]=temporary->dataFour;
      if (!strcasecmp(nodeToCheck, input)){
        printf("There is a word that matches: ");
        printf("%c", temporary->data); 
        printf("%c", temporary->dataTwo); 
        printf("%c", temporary->dataThree); 
        printf("%c", temporary->dataFour);
        printf("\n");
        matchingWordBoolean=1;
      }
      
    }
    //Reset the input char array. Going back to root is probably unnecessary but just in case.
    if (matchingWordBoolean==0){
      printf("No matching words.");
    }
      
    temporary=root;
    input[0]='\0';
    input[1]='\0';
    input[2]='\0';
    input[3]='\0';
      
  }
  //Search case sensitive mode
  if (!strcmp(command, searchC)){
    printf("\nWhat is the word you a search for?\nIf it's more than four letters, just type the first four letters.\n");
    scanf("%s", input);
    printf("%s", input);
    printf("TEST:");
    printf("%c\n", input[0]);
    printf("%c\n", input[1]);
    printf("%c\n", input[2]);
    printf("%c\n", input[3]);
    printf("\n");
    for (temporary = root; temporary != NULL; temporary = temporary->next){
     
      if (temporary->data==input[0]&&temporary->dataTwo==input[1]&&temporary->dataThree==input[2]&&temporary->dataFour==input[3]){
        printf("There is a word that matches: ");
        printf("%c", temporary->data); 
        printf("%c", temporary->dataTwo); 
        printf("%c", temporary->dataThree); 
        printf("%c", temporary->dataFour);
        printf("\n");
        matchingWordBoolean=1;
      }
      
    }
    //Reset the input char array. Going back to root is probably unnecessary but just in case.
    //if (temporary==NULL){
      //printf("No matching words.");
    //}
    if (matchingWordBoolean==0){
      printf("No matching words.");
    }
      
    temporary=root;
    input[0]='\0';
    input[1]='\0';
    input[2]='\0';
    input[3]='\0';
  }
  //Delete the linked list and end the program.
  if (!strcmp(command, delet)){
    deleteLinkedList(&root);
    //The for loop prints the letters in the linked list.
    for (temporary = root; temporary != NULL; temporary = temporary->next){
      printf("%c", temporary->data); 
      printf("%c", temporary->dataTwo); 
      printf("%c", temporary->dataThree); 
      printf("%c", temporary->dataFour);
      printf("%d", temporary->length);
      printf("\n");
  }
  
    printf("\n");
    printf("Hmm sus.");
    break;
    
  }
  if (!strcmp(command, add)){
    //Reset this value and array in case of reuse of the add function.
    wordToAddLength=0;
    memset(wordToAdd, 0, sizeof wordToAdd);
    
    printf("\nEnter your word to add to the linkest list: \n");
    //Without this line, the program will skip fgets.
    while ((getchar()) != '\n');

    //Get the word to add from the user.
    fgets(wordToAdd, sizeof(wordToAdd), stdin); 
    printf("Word to Add:");
    printf("%s", wordToAdd);
    printf("\n");

    //Count the length of the word.
    for (int index = 0; index<sizeof(wordToAdd); ++index) {
    if(iswalpha(wordToAdd[index])!=0){
      wordToAddLength+=1;
      }
      else if(iswalpha(wordToAdd[index])==0) {
        wordToAdd[index]='\0';
      }
    }
    printf("%d", wordToAddLength);
    printf("\n");

    //Add the added word to the end of the linked list for now.
    
    for (temporary = root; temporary != NULL; temporary = temporary->next){
      if (temporary->next==NULL){
       
      newTemporary=createNode(wordToAdd[0], wordToAdd[1], wordToAdd[2], wordToAdd[3], wordToAddLength);
        temporary->next=newTemporary;
         printf("If statement worked.");
        if(newTemporary){
          temporary = temporary->next;
        }
        }
  }
    //temporary->next = newTemporary; //Move on to the next node. 
    //temporary = temporary->next;

    //Reset the arrays and variables just in case.
    memset(originalWordLength, 0, sizeof originalWordLength);
    memset(alphabetWordLength, 0, sizeof alphabetWordLength);
    memset(alphabetInputArray, 0, sizeof alphabetInputArray);
    memset(alphabetSortingTwoDArray, 0, sizeof alphabetSortingTwoDArray);
    memset(charTracker, 0, sizeof charTracker);
    memset(wordStorage, 0, sizeof wordStorage);
    counter=0;
    lindex=0;
    originalWLCounter=0;
    alphabetWLCounter=0;
    
    printf("\n");
    for (temporary = root; temporary != NULL; temporary = temporary->next){
    printf("%c", temporary->data); 
    printf("%c", temporary->dataTwo); 
    printf("%c", temporary->dataThree); 
    printf("%c", temporary->dataFour);
    printf("%d", temporary->length);
    printf("\n");

    //Keeps the length of words from the linked list to put in the alphabet sorter later.
    originalWordLength[originalWLCounter]=temporary->length;
    originalWLCounter+=1;

    //Stores words from the linked list to alphabet sort later.
    alphabetInputArray[0]=temporary->data;
    alphabetInputArray[1]=temporary->dataTwo;
    alphabetInputArray[2]=temporary->dataThree; 
    alphabetInputArray[3]=temporary->dataFour;
    strcpy(alphabetSortingTwoDArray[lindex], alphabetInputArray);
    counter+=1;
    lindex+=1;
        }
    
    //These for loops alphabetically sort the word in the linked list.
    for(jindex=0;jindex<counter;jindex++){
      for(kindex=jindex+1;kindex<counter;kindex++){
         if(strcasecmp(alphabetSortingTwoDArray[jindex], alphabetSortingTwoDArray[kindex])>0){
            strcpy(&wordStorage[0], alphabetSortingTwoDArray[jindex]);
            strcpy(alphabetSortingTwoDArray[jindex], alphabetSortingTwoDArray[kindex]);
            strcpy(alphabetSortingTwoDArray[kindex], &wordStorage[0]);
            }
         }
      }

    //Count all of the letters for the words in the linked list.
for(jindex=0;jindex<counter;jindex++){
     strcpy(charTracker, alphabetSortingTwoDArray[jindex]);
   temporary=root;
     
  for(temporary=root; temporary != NULL; temporary = temporary->next){
    //Skip root node.
    if (temporary->data==0 && temporary->dataTwo==0 &&temporary->dataThree==0 && temporary->dataFour==0 && temporary->length==0){
     temporary = temporary->next;
    }

    //printf("\nAll Before:\n"); 
      //printf("%s", charTracker); 
      //printf("2DArray: %s", alphabetSortingTwoDArray[jindex]); 
      //printf("%c", temporary->data); 
      //printf("%c", temporary->dataTwo); 
      //printf("%c", temporary->dataThree); 
      //printf("%c", temporary->dataFour);
    
      
    //Checking for letters in 2Darray and that letters in 2Darray match linked list's letters in their nodes.

      if (temporary->length==1){
        if(charTracker[0]==temporary->data&&iswalpha(charTracker[0])){
          alphabetWordLength[alphabetWLCounter]=temporary->length;
        alphabetWLCounter+=1;
           printf("Hmm\n"); 
          printf("%d", temporary->length); 
           printf("\n"); 
          temporary=root;
          break;
        }
      }
      else if (temporary->length==2){
        if(charTracker[0]==temporary->data && charTracker[1]==temporary->dataTwo &&iswalpha(charTracker[0]) &&iswalpha(charTracker[1])){
        
        alphabetWordLength[alphabetWLCounter]=temporary->length;
       // printf("\nTemp Length:\n"); 
        //printf("%d", temporary->length); 
        alphabetWLCounter+=1;
          printf("Hmm\n"); 
          printf("%d", temporary->length); 
           printf("\n"); 
          temporary=root; 
          break;
            }
      }
      else if (temporary->length==3){
        if(charTracker[0]==temporary->data && charTracker[1]==temporary->dataTwo && charTracker[2]==temporary->dataThree&&iswalpha(charTracker[0]) &&iswalpha(charTracker[1])&&iswalpha(charTracker[2])){
        
        alphabetWordLength[alphabetWLCounter]=temporary->length;
        //printf("\nTemp Length:\n"); 
        //printf("%d", temporary->length); 
        alphabetWLCounter+=1;
          printf("Hmm\n"); 
          printf("%d", temporary->length); 
           printf("\n"); 
          temporary=root;
          break;
            }
      }
      else if(temporary->length>=4){
        if(charTracker[0]==temporary->data && charTracker[1]==temporary->dataTwo && charTracker[2]==temporary->dataThree&&charTracker[3]==temporary->dataFour&&iswalpha(charTracker[0]) &&iswalpha(charTracker[1])&&iswalpha(charTracker[2])&&iswalpha(charTracker[3])){
        
        alphabetWordLength[alphabetWLCounter]=temporary->length;
        //printf("\nTemp Length:\n"); 
        //printf("%d", temporary->length); 
        alphabetWLCounter+=1;
          printf("Hmm\n"); 
          printf("%d", temporary->length); 
           printf("\n"); 
          temporary=root; 
          break;
            }
      }
      }
   }

    //Important function call to sort the linked list alphabetically.
  alphabetOrderLinkedList(root, alphabetSortingTwoDArray, alphabetWordLength);

  //The for loop prints the letters in the linked list.
printf("\nChecking If alphabetOrderLinkedList Worked:\n");
for (temporary = root; temporary != NULL; temporary = temporary->next){
    printf("%c", temporary->data); 
    printf("%c", temporary->dataTwo); 
    printf("%c", temporary->dataThree); 
    printf("%c", temporary->dataFour);
    printf("%d", temporary->length);
    printf("\n");
  }
    
    }
  
  }
  
return  0;
}

  /* 
BUGGED SENTENCES:
Donkeys cry bacon. (Add apple, then add chicken, then add breakfast, then add yogurt)
6 letters words are counted to 7 with ADD

Test cases:
I smell it.
Wrap it up.
Feed the baby.
I like it.
We party hard.
We sell sea shells.
I love you.
Eat the ice cream. 
Why not?
How am I smart?
I like it, sir.
I ran, and I won.
I am good, but I eat.
I am happy!
I would like a taco.
I like rice; give me one.
I bought: mangos, cheese, and John Wick.
I bought: mangos, cheese, and
I like to eat.
Good night, I love you.
Jay was born.
I did not check.
I like beans, and I hate pineapples, but Jim Carrey was ok, or the Sonic movie writers were nuts.
I like cheese.
I make pasta.
I ate it.
I like potato.
I like Bob.
I ran very far away.
Was it a car or a cat I saw?
Donkeys cry bacon. (Add apple, then add chicken, then add breakfast, then add yogurt)

Comma cases:
Works in the first slot.
Works in the 2nd slot.
Works in the third slot.
Works in the fourth slot

New cases to test:

Not supported: Quotes ("") or Apostophe's ('')
*/