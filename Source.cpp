#include<iostream>
#include<string>
#include<cmath>
using namespace std;

struct stud {					//Student Structure
							
	string name;				//Name of the student
	int rollno;					//Roll number of the student
	float SGPA;					//SGPA of the student 
	
};
class studentDetails {			//Class of student's detailss
	struct stud s[20];			//Array of structure 'stud'

public:
	
	void getdata(int);					//Function to input details from the user
	void display(int);					//Function to display details to the user
	void sortroll(int);					//Function to sort the roll the roll number (Bubble sort)
	void sortalpha(int);				//Function to sort the students alphaberically (Insertion Sort) 
	void search(int);					//Function to search by the student's roll no (linear search)
	void bubblesortanalysis(int);		//Function to sort the roll the roll number (Bubble sort Analysis)
	void insertionsortanalysis(int);	//Function to sort the students alphaberically (Insertion Sort Analysis)
	void swap(int*, int*);				//Function to swap numbers (Quicksort)
	int  partition(int, int);			//Function to partion the array (Quicksort)
	void quicksort(int, int);			//Function to sort the students according to SGPA (Quicksort)
	void binarysearch(int);				//Function to search the student by name (Binary Seach)
	void binarysearch_analysis(int);	//Function to search the student by name (Binary Seach Analysis)
	int  partitionA(int l, int r);	
	void quicksortA(int l, int r, int n);

};
//---------------------------------------------------------------------------------------------Input
void studentDetails::getdata(int n)   //Recieve input from the user
{
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the name of the student " << i + 1 << ": ";
		//cin >> s[i].name;
		cin.ignore();
		getline(cin, s[i].name);											//Allowing the user to enter the fullname (including spaces and dots)
		enrol:cout << "Enter the rollno. of the student "<<i+1<<": ";		
		cin >> s[i].rollno;
		for (int j = 0; j <i; j++)
		{
			if (s[j].rollno == s[i].rollno)						//Validation of a duplicate rollno.
			{
				cout << "\nThe number is invalid" << endl;
				goto enrol;				
			}
		}
		for (int j = 0; j <=i; j++)
		{
			if (s[j].rollno < 23100 || s[j].rollno>23180)
			{
				cout << "Enter the roll no between 23100 and 23180" << endl;			//Validation for the lower and upper bound the the rollno. 
				goto enrol;
			}
		}
		

		cout << "Enter the SGPA of the student : ";				
		cin >> s[i].SGPA;											//SGPA of the student
	}

}
//-----------------------------------------------------------------------------------------------Display
void studentDetails::display(int n)	//display the output
{
	cout << "==================================================";
	cout << "\nRoll no\t\tName\t\tSGPA" << endl;						//Tabular Format
	cout << "==================================================" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << s[i].rollno << "\t\t" << s[i].name << "\t\t" << s[i].SGPA << endl;
	}

}
//-------------------------------------------------------------------------------------------------------------Sort rollno. (Bubble Sort)
void studentDetails::sortroll(int n)		//Sorting function according to their roll no. (Bubble Sort)

{
	stud t;
	for (int i = 0; i < n - 1; i++)			//Iterating over the whole array
	{   
		
		for (int j = 0; j < n - i - 1; j++)			//Iterating till the value of i
		{
			if (s[j].rollno > s[j + 1].rollno)
			{
				t = s[j];
				s[j] = s[j + 1];			//Swapping the elements
				s[j + 1] = t;

			}
		}
		
	}
}
//---------------------------------------------------------------------------------Bubble Sort (rollno.) Analysis
void studentDetails::bubblesortanalysis(int n)
{
	stud t;			//temp variable for swapping the elements
	int swap;		//Swaps
	int com=0;		//Comparision
	int ts = 0;		//Total number of swaps
	int tc = 0;		//Total number of comparisions
	int c[20];		//arrray to display the elements before swap
	
	for (int i = 0; i < n; i++)			//Setting an array to display the elements before swap through iteration
	{
		c[i] = s[i].rollno;
	}

	cout << "==================================================" ;
	cout << "\nPass\t\tSwaps\t\tComparisions" << endl;						//Tabular Format
	cout << "=================================================="<<endl;

	for (int i = 0; i < n - 1; i++)				//Iterating over the elements
	{
		com = 0;				//Initialising comparisions to zero (every time the value of i changes)
		swap = 0;				//Initialising swaps to zero (every time the value of i changes)
		
		
		for (int i = 0; i < n; i++)    
		{
			cout << s[i].rollno << " ";		//Dispalying the pass
		}

		for (int j = 0; j < n - i - 1; j++)
		{
			com = com + 1;
			if (s[j].rollno > s[j + 1].rollno)			//Comparing the rollno of the element after the key
			{
				swap = swap + 1;
				t = s[j];
				s[j] = s[j + 1];			//Swapping the entire data of the elements
				s[j + 1] = t;

			}
		}
		
		cout <<"\t["<<swap<< "]"<< "\t\t" << com << endl;			//Swaps and comparisions for each pass

		ts = ts + swap;												//Calulating total number of swaps
		tc = tc + com;												//Calulating total number of comparisions


	}
	
	cout << "\nElements before passing :- ";		//Dispalying the elements before bubble sort
	for (int i = 0; i < n; i++)
	{
		cout << c[i] << " ";
	}

	cout << "\nElements after passing :- ";		//Dispalying the elements after bubble sort
	for (int i = 0; i < n; i++)
	{
		cout << s[i].rollno << " ";
	}

	cout << "\nTotal number of swaps = " << ts << endl;				//Displaying total number of swaps at the end
	cout << "Total number of comparisions = " << tc << endl;		//Displaying total number of comparisions at the end

	int worst;					//Worst integer
	worst = pow(n,2);			//Worst case
	if (tc == n)											//Analysis 
	{
		cout << "This is the best case" << endl;
	}
	else if (tc==worst)
	{
		cout << "This is the worst case" << endl;
	}
	else
	{
		cout << "This is the average case" << endl;
	}

}


//--------------------------------------------------------------------------------------------------Sort students alphabetically (Insertion Sort)

void studentDetails::sortalpha(int n)		//Sorting function according to their Names. (Insertion Sort)
{

	
	stud t;
	string f;		//key
	string temp;
	int j = 0;
	for (int i = 1; i < n; i++)
	{	
		t = s[i];						//temp for the whole structure
		f = t.name;						//Intializing the key with the temp's name
		j = i - 1;
		while (j >= 0 && s[j].name > f)			//Iterate till the element is greater than its previous value
		{
			//s[j + 1].name = s[j].name;		//exchanging the name preceeding it
			s[j + 1] = s[j];
			j = j - 1;
			
		}
		//s[j + 1].name = f;					//exchanging the name
		s[j + 1] = t;
	}


}

//------------------------------------------------------------------------------------Sort students alphabetically (Insertion sort analysis)
void studentDetails::insertionsortanalysis(int n)			//Insertion Sort Analysis
{
	
	
	stud t;				//Temp of 'stud' structure for exchanging the elements
	int swap;			//Number of swaps
	string f;			//key
	int c;				//Number of comparisions
	int ts=0;			//Total number of swaps
	int tc=0;			//Total number of comparisions
	int j = 0;			//int for comparing the indexes before key
	string b[20];		//arrray of string to display the elements before swap
	
	for (int i = 0; i < n; i++)			//Setting an array to display the elements before swap through iteration
	{
		b[i] = s[i].name;
	}
		
	cout << "=====================================================================================================";
	cout << "\nValue of key\t\tSeries\t\t\t\tNumber of Comparisions\t\tNumber of swaps" << endl;										//Tabular Format
	cout << "=====================================================================================================" << endl;
	for (int i = 1; i < n; i++)      //Iterating over the array by the second(1) index
	{
		c = 0;						 //Always initialising the number of comparisions to zero for each loop
		swap = 0;					 //Always initialising the number of comparisions to zero for each loop
		t = s[i];
		f = t.name;					 //Initialising the key
		cout << "\n" << f;			 //Displaying the value of key		
		j = i - 1;					 //Intialising j less than the index of key
		if (s[j].name > f)
		{
			c = c + 1;
		}
		while (j >= 0 && s[j].name > f)			//Perform while key is less than the elements before it
		{	
			c = c + 1;
			swap = swap + 1;					//Counting the number of swaps
			//s[j + 1].name = s[j].name;			//Swapping the name
			s[j + 1] = s[j];
			j = j - 1;							//Going to the previous element	
		}		
		if (j == 0 || j == -1)
		{
			c = c - 1;
		}

		s[j + 1] = t;								//Placing the value of key in its correct position
		cout << "\t\t\t";
		for (int i = 0; i < n; i++)
		{
			cout << s[i].name << "--";					//Display the array for each loop
		}
		cout << "\t\t[ " << abs(c) << " ]";				//Displaying the number of comparisions for each loop
		tc = tc + abs(c);
		
		cout << "\t\t\t[ " << swap << " ]" << endl;		//Displaying the number of swaps for each loop
		ts = ts + swap;
	}


	cout << "\nElements before passing :- ";			//Dispalying the elements before insertion sort
	for (int i = 0; i < n; i++)
	{
		cout << b[i] << " ";
	}

	cout << "\nElements after passing :- ";				//Dispalying the elements after insertion sort
	for (int i = 0; i < n; i++)
	{
		cout << s[i].name << " ";
	}


	cout << "\nTotal number of swaps = " << ts << endl;						//Displaying total number of swaps at the end
	cout << "\nTotal number of comparisions = " << tc << endl;				//Displaying total number of comparisions at the end


	int worst;					//Worst case
	worst = n*n;				//Worst case value
	if (tc == n)											//Analysis of insertion sort
	{
		cout << "This is the best case" << endl;
	}
	else if (tc == worst)
	{
		cout << "This is the worst case" << endl;
	}
	else
	{
		cout << "This is the average case" << endl;
	}

	
}

//-----------------------------------------------------------------------------Search SGPA (Linear Search)
void studentDetails::search(int n)		//Linear Search for rollno.
{
	int f = 0;		//Flag for found or not found
	int i;			//Index in for-loop
	int r;			//Sgpa to be searched
	int tc=0;		//Count till all the SGPA are found (For Pass-wise output)
	
	cout << "Enter the SGPA of the student to be searched :- ";			
	cin >> r;

	for (i = 0; i < n; i++)
	{

		if (s[i].SGPA == r)
		{
			f = f + 1;					//Increasing the flag by one
		}
	}
	if (f == 0)							//If the value of flag dosen't change, the SGPA is not found
	{
		cout << "\nThe SGPA you have searched is not found" << endl;
	}
	else
	{

		for (i = 0; i < n; i++)							//Iterating over the array of SGPA
		{

			if (s[i].SGPA == r)
			{
				tc = i;									//Count till all the SGPA are found (For Pass-wise output)
			}
		}
		cout << "================= (Pass-Wise Output) =======================";
		cout << "\nRoll no\t\tName\t\tSGPA" << endl;
		cout << "============================================================" << endl;
		for (i = 0; i <= tc; i++)
		{
			cout << s[i].rollno << "\t\t" << s[i].name << "\t\t" << s[i].SGPA << endl;							//Pass-Wise Output


		}
		cout << "\n===================(Diplaying only the searched SGPA)=========================";
		cout << "\nRoll no\t\tName\t\tSGPA" << endl;															//Displaying all the matched SGPA
		cout << "==============================================================================" << endl;
		for (i = 0; i < n; i++)
		{

			if (s[i].SGPA == r)
			{
				cout << s[i].rollno << "\t\t" << s[i].name << "\t\t" << s[i].SGPA << endl;
			}
		}
		cout << "Total number of comparisions = " << n;								//Diplaying total number of comparisions
	}

	
	int worst;
	worst = n;
	if (tc == 1)											//Analysis of Linear search
	{
		cout << "This is the best case" << endl;
	}
	else if (tc == worst)
	{
		cout << "This is the worst case" << endl;
	}
	else
	{
		cout << "This is the average case" << endl;
	}


	
}
//------------------------------------------------------------------------------- Sort students according to the SGPA (Quick Sort)
void studentDetails::swap(int* a, int* b)				//Swap function to swap integers (Argument as pointers)
{
	int temp;			//temp integer for swapping the numbers
	temp = *a;			//storing the value of pointer 'a'
	*a = *b;			//replacing the value of 'a' with the value of 'b' pointer
	*b = temp;			//replacing the value of 'b' with the value of temp
}



int studentDetails::partition(int l, int r)
{
	stud t;										//Temp stud structure (for exchanging)
	float pivot = s[r].SGPA;					//pivot element (taken the last)
	int i;
	int j;
	i = l - 1;
	for (j = l; j <= r - 1; j++)
	{
		if (s[j].SGPA < pivot)
		{
			i = i + 1;	
			t = s[j];
			s[j] = s[i];			//Swapping the entire data of the elements
			s[i] = t;
			
		}
	}
	
	 t = s[i+1];
	s[i+1] = s[r];			//Swapping the entire data of the elements
	s[r] = t;


	return (i + 1);

}

void studentDetails::quicksort(int l, int r)
{
	if (l >= r)					//Validation for single element
	{
		return;
	}
	int p;
	p = partition(l, r);
	quicksort( l, p - 1);			//Quiksort the left bubble
	quicksort( p + 1, r);			//Quiksort the right bubble

}
//----------------------------------------------------------------------------------------Search student by name (binary search)
void studentDetails::binarysearch(int n)
{

	int l = 0;					//left value
	int r = n-1;				//right value
	string x;					//String to be seached (initialization)
	cout << "Enter the name you want to search :- ";
	cin.ignore();
	getline(cin, x);
	cout << "\nRoll no\t\tName\t\tSGPA" << endl;						//Tabular Format
	while (l <= r) {
		int m = l + (r - l) / 2;				//Setting the middle index
		int f=1;    //flag
		
		if (x==s[m].name)
		{		
			f = 0;								//Setting the flag to 0 if element is found
		}

		if (f == 0)
		{		
			cout << s[m].rollno << "\t\t" << s[m].name << "\t\t" << s[m].SGPA << endl;		 //Displaying the details of the student
		}

		if (x > s[m].name)
		{			
			l = m + 1;							//Setting the left value to middle index+1
		}
		else
		{			
			r = m - 1;							//Setting the left value to middle index-1
		}
		
	}
	
}
//----------------------------------------------------------------------------Search student by name (binary search analysis)

void studentDetails::binarysearch_analysis(int n)
{
	int comparisions = 0;				//Comparisions
	int l = 0;							//left value
	int r = n - 1;						//Right value
	string x;
	int pass = 0;
	cout << "Enter the name you want to search :- ";
	//cin >> x;
	cin.ignore();
	getline(cin, x);
	cout << "\nRoll no\t\tName\t\tSGPA" << endl;
	while (l <= r) {
		int m = l + (r - l) / 2;
		int f = 1;							//flag (initializing it with 1)

		if (x == s[m].name)
		{
			f = 0;							//Setting the flag to zero of the element is found
		}

		if (f == 0)
		{
			cout << "( l = " << l << " m = " << m << " r = " << r << " )" << endl;				//Displaying the left,middle and right value
			cout << s[m].rollno << "\t\t" << s[m].name << "\t\t" << s[m].SGPA << endl;
			cout << "\nTotal number of comparisions = " << comparisions << endl;		//Displaying the total number of comparisions in binary search
			break;
		}

		if (x > s[m].name)
		{
			pass = pass + 1;
			cout << "Pass = " << pass << endl;				//Displaying the pass number
			l = m + 1;
			cout << "( l = " << l << " m = " << m << " r = " << r << " )" << endl;							//Displaying the left,middle and right value
			cout << "-------------------------------------------------------------------------" << endl;
			cout << s[m].rollno << "\t\t" << s[m].name << "\t\t" << s[m].SGPA << endl;						//Displaying the details of the student
			cout << "-------------------------------------------------------------------------" << endl;
			comparisions = comparisions + 1;    //Increasing the comparisions by one
		}
		else
		{
			pass = pass + 1;
			cout << "Pass = " << pass << endl;
			r = m - 1;
			cout << "( l = " << l << " m= " << m << " r = " << r << " )" << endl;				//Displaying the left,middle and right value
			cout << "-------------------------------------------------------------------------" << endl;
			cout << s[m].rollno << "\t\t" << s[m].name << "\t\t" << s[m].SGPA << endl;
			cout << "-------------------------------------------------------------------------" << endl;
			comparisions = comparisions + 1;		//Increasing the comparisions by one
		}

	}

	int worst;					//Worst case
	worst = log(n);
	if (comparisions == 1)											//Analysis of binary search
	{
		cout << "This is the best case" << endl;
	}
	else if (comparisions == worst)
	{
		cout << "This is the worst case" << endl;
	}
	else
	{
		cout << "This is the average case" << endl;
	}


}
//---------------------------------------------------------------------Sort students according to the SGPA(Quick Sort analysis)



int studentDetails::partitionA(int l, int r)
{
	
	int static counter = 0;								//counter (comparisions)
	int static cs = 0;									//swaps
	int cp=0;
	int sp=0;
	stud t;										//Temp stud structure (for exchanging)
	float pivot = s[r].SGPA;					//pivot element (taken the last)
	int i;
	int j;
	i = l - 1;
	for (j = l; j <= r - 1; j++)
	{
		counter = counter + 1; 
		cp = cp + 1;
		if (s[j].SGPA < pivot)
		{
			cs = cs + 1;			//Calculating the number of swaps
			sp = sp + 1;
			i = i + 1;
			t = s[j];
			s[j] = s[i];			//Swapping the entire data of the elements
			s[i] = t;

		}
	}
	cout << "\n---------------------------------------------------------" << endl;
	cout << "\nTotal number of swaps on this loop = " << sp;
	cout << "\nTotal number of comparisions on this loop = " << cp;
	cout << "\n---------------------------------------------------------------" << endl;
	cout << "\nTotal number of swaps till this loop = " << cs;
	cout << "\nTotal number of comparisions till this loop = " << counter;
	cout << "\n---------------------------------------------------------------" << endl;

	t = s[i + 1];
	s[i + 1] = s[r];			//Swapping the entire data of the elements
	s[r] = t;


	return (i + 1);				//returning the middle element

}

void studentDetails::quicksortA(int l, int r,int n)
{
	if (l >= r)					//Validation for single element
	{
		
		return;
	}
	int p;

	p = partitionA(l, r);

	cout << "\nPivot = " << p <<" [ "<<s[p].SGPA<<" ]";
	cout << "\nPartition left :- :" << endl;
	for (int i = l; i < p; i++)
	{
		cout << s[i].SGPA << " | ";
	}
	cout << "\nPartition right :- :" << endl;
	for (int i = p+1; i < r+1; i++)
	{
		cout << s[i].SGPA << " | ";
	}


	quicksortA(l, p - 1,n);			//Quiksort the left bubble
	quicksortA(p + 1, r,n);			//Quiksort the right bubble

}



//=======================================================================================

int main()
{
	
	studentDetails A;				//An object of 'studentDeatails' class for operations
	int alphasort = 0;				//validation variable(flag) for sorted array for binary search
	static int size;				//size of the database
	int c;							//choice variable
	do {
		cout << "\n___MENU___" << endl;			//displaying the menu
		cout << "1. Input" << endl;
		cout << "2. Sort rollno. (Bubble Sort)" << endl;
		cout << "3. Search SGPA  (Linear Search)" << endl;
		cout << "4. Display" << endl;
		cout << "5. Sort rollno. (Bubble Sort analysis)" << endl;
		cout << "6. Sort students alphabetically (Insertion Sort)" << endl;	
		cout << "7. Sort students alphabetically (Insertion sort analysis)" << endl;
		cout << "8. Sort students according to the SGPA (Quick Sort)" << endl;
		cout << "9. Search student by name (binary search)" << endl;
		cout << "10.Search student by name (binary search analysis)" << endl;
		cout << "11. Sort students according to the SGPA(Quick Sort analysis)" << endl;
		cout << "12.Exit" << endl;
		cout << "Enter your choice = ";
		cin >> c;
		switch (c)
		{
		case 1:
			do {
				cout << "Enter the number of students you want to input :- ";
				cin >> size;
				if (size > 0 && size < 20)
				{
					A.getdata(size);
					break;
				}
				else
				{
					cout << "The size you have entered is not valid" << endl;		//Validation for size of the database
				}
			} while (size > 0 || size < 20);
			break;
		case 2:
			if (size > 0 && size < 20)
			{
				A.sortroll(size);
			}
			else
			{
				cout << "You have not entered the input for database." << endl;		//Validation for size of the database
			}
			break;
		case 3:
			if (size > 0 && size < 20)
			{
				A.search(size);
			}
			else
			{
				cout << "You have not entered the input for database." << endl;		//Validation for size of the database
			}
			break;
		case 4:
			if (size > 0 && size < 20)
			{

				A.display(size);
			}
			else
			{
				cout << "You have not entered the input for database." << endl;		//Validation for size of the database
			}
			break;
		case 5:
			if (size > 0 && size < 20)
			{
			A.bubblesortanalysis(size);
			}
			else
			{
				cout << "You have not entered the input for database." << endl;		//Validation for size of the database
			}
			break;
		case 6:
			if (size > 0 && size < 20)
			{
				A.sortalpha(size);
				alphasort = alphasort + 1;
			}
			else
			{
				cout << "You have not entered the input for database." << endl;		//Validation for size of the database
			}
			break;
		case 7:
			if (size > 0 && size < 20)
			{
				A.insertionsortanalysis(size);
				alphasort = alphasort + 1;
			}
			else
			{
				cout << "You have not entered the input for database." << endl;		//Validation for size of the database
			}
			break;
		case 8:
			if (size > 0 && size < 20)
			{
				
					A.quicksort(0, size - 1);
				
			}
			else
			{
				cout << "You have not entered the input for database." << endl;		//Validation for size of the database
			}
			break;
		case 9:
			if (size > 0 && size < 20)
			{
				if (alphasort > 0)
				{
					A.binarysearch(size);									//Validation for alphabetically sorted elements
				}
				else
				{
					cout << "Sort the data alphabetically";
				}
			}
			else
			{
				cout << "You have not entered the input for database." << endl;		//Validation for size of the database
			}
			break;
		case 10:
			if (size > 0 && size < 20)
			{
				if (alphasort > 0)
				{
					A.binarysearch_analysis(size);									//Validation for alphabetically sorted elements
				}
				else
				{
					cout << "Sort the data alphabetically";
				}
			}
			else
			{
				cout << "You have not entered the input for database." << endl;		//Validation for size of the database
			}
			break;
		case 11:
			if (size > 0 && size < 20)
			{
				A.quicksortA(0, size - 1,size);
			}
			else
			{
				cout << "You have not entered the input for database." << endl;		//Validation for size of the database
			}
			break;
		case 12:
			exit(1);
		default:cout << "Invalid entry!" << endl;
			break;
		}
	} while (c<12);
	return 0;
}