
#include <iostream>
#include <iomanip>

using namespace std;

//Declare constants for the program
const double XXXSMALLCOST = 50.00;
const double SMALLCOST = 175.00;
const double MEDCOST = 190.00;
const double LGCOST = 200.00;

//Declare function to show the main menu options
void ShowUsage()
{
    cout << "************************************************************" << endl;
    cout << "***** Welcome to my Johnny Utah's PointBreak Surf Shop *****" << endl;
    cout << "************************************************************" << endl;
    cout << endl << endl;
    cout << "To show program usage 'S'" << endl;
    cout << "To purchase a surfboard press 'P'" << endl;
    cout << "To display current purchases press 'C'" << endl;
    cout << "To display total amount due press 'T'" << endl;
    cout << "To quit the program press 'Q'" << endl << endl;

}

//Declare function that allows user to enter their requested purchase
void MakePurchase(int& iTotalXSmall, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge)
{
    //Local variables
    int userInAmount;
    char userInType;
    
    cout << "Please enter the quantity and type (X=xxxsmall, S=small, M=medium, L=large) of surfboard you would like to purchase:";
    cin >> userInAmount >> userInType;
    cout << endl;

    if (userInType == 'X' || userInType == 'x') //If user uses upper or lowercase X, increment xxxsmall boards by the input amount
    {
        iTotalXSmall = iTotalXSmall + userInAmount;
    }
    if (userInType == 'S' || userInType == 's') //If user uses upper or lowercase S, increment small boards by the input amount
    {
        iTotalSmall = iTotalSmall + userInAmount;
    }
    else if (userInType == 'M' || userInType == 'm')//If user uses upper or lowercase M, increment medium boards by the input amount
    {
        iTotalMedium = iTotalMedium + userInAmount;
    }
    else if (userInType == 'L' || userInType == 'l')//If user uses upper or lowercase L, increment large boards by the input amount
    {
        iTotalLarge = iTotalLarge + userInAmount;
    }
}

//Declare function to display the total number of each board being purchased so far
void DisplayPurchase(const int iTotalXSmall, const int iTotalSmall, const int& iTotalMedium, const int& iTotalLarge)
{
    //If no boards have been added to the "cart", give a default message
    if (iTotalXSmall == 0 && iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0) 
    {
        cout << "No purchases made yet." << endl;
    }
    if (iTotalXSmall > 0) //Show XXXSmall total as long as it's more than 0
    {
        cout << "The total number of xxxsmall surfboards is " << iTotalXSmall << endl;
    }
    if (iTotalSmall > 0) //Show Small total as long as it's more than 0
    {
        cout << "The total number of small surfboards is " << iTotalSmall << endl;
    }
    if (iTotalMedium > 0) //Show Medium total as long as it's more than 0
    {
        cout << "The total number of medium surboards is " << iTotalMedium << endl;
    }
    if (iTotalLarge > 0) //Show Large total as long as it's more than 0
    {
        cout << "The total number of large surfboards is " << iTotalLarge << endl;
    }
}

//Declare function to show customer's running total, along with individual quantities and amounts for each size
void DisplayTotal(const int iTotalXSmall, const int iTotalSmall, const int& iTotalMedium, const int& iTotalLarge)
{
    //Declare needed local variables
    double runningTotal = 0.00;
    double xxxsmallTotal = 0.00;
    double smallTotal = 0.00;
    double medTotal = 0.00;
    double lgTotal = 0.00;

    if (iTotalXSmall == 0 && iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0) //If no boards have been added to the "cart", give a default message
    {
        cout << "No purchases made yet." << endl;
    }
    if (iTotalXSmall > 0) //If there's more than 0 XXXS boards in the cart, show the quantity and total for that item
    {
        xxxsmallTotal = iTotalXSmall * XXXSMALLCOST;
        cout << "The total number of xxxsmall surfboards is " << iTotalXSmall << " at a total of $" << fixed << setprecision(2) << xxxsmallTotal << endl;
    }
    if (iTotalSmall > 0) //If there's more than 0 S boards in the cart, show the quantity and total for that item
    {
        smallTotal = iTotalSmall * SMALLCOST;
        cout << "The total number of small surfboards is " << iTotalSmall << " at a total of $" << fixed << setprecision(2) << smallTotal << endl;
    }
    if (iTotalMedium > 0) //If there's more than 0 M boards in the cart, show the quantity and total for that item
    {
        medTotal = iTotalMedium * MEDCOST;
        cout << "The total number of medium surfboards is " << iTotalMedium << " at a total of $" << fixed << setprecision(2) << medTotal << endl;
    }
    if (iTotalLarge > 0) //If there's more than 0 L boards in the cart, show the quantity and total for that item
    {
        lgTotal = iTotalLarge * LGCOST;
        cout << "The total Number of large surfboards is " << iTotalLarge << " at a total of $" << fixed << setprecision(2) << lgTotal << endl;
    }
    if (iTotalXSmall > 0 || iTotalSmall > 0 || iTotalMedium > 0 || iTotalLarge > 0) //As long as one kind of board is greater than 0, show a grand running total
    {
        runningTotal = xxxsmallTotal + smallTotal + medTotal + lgTotal;
        cout << "Amount due: $" << fixed << setprecision(2) << runningTotal << endl;
    }
}

int main()
{
    //Declare the local variables for main
    char userIn = 's';
    int iTotalXSmall = 0;
    int iTotalSmall = 0;
    int iTotalMedium = 0;
    int iTotalLarge = 0;
    
    //Keep program running as long as the user does not input the quit command (Q)
    while (userIn != 'Q' && userIn != 'q')
    {

        if (userIn == 'S' || userIn == 's') //If user enters upper or lowercase "S", call the ShowUsage function
        {
            system("CLS"); //Clear the screen before the function is called so the menu doesn't overpopulate with the same text
            ShowUsage();
            cout << endl << "Please enter selection: ";
            cin >> userIn;
        }
        else if (userIn == 'P' || userIn == 'p') //If user enters upper or lowercase "P", call the MakePurchase function
        {
            MakePurchase(iTotalXSmall, iTotalSmall, iTotalMedium, iTotalLarge);
            cout << endl << "Please enter selection: ";
            cin >> userIn;
        }
        else if (userIn == 'C' || userIn == 'c') //If user enters upper or lowercase "C", call the DisplayPurchase function
        {
            DisplayPurchase(iTotalXSmall, iTotalSmall, iTotalMedium, iTotalLarge);
            cout << endl << "Please enter selection: ";
            cin >> userIn;
        }
        else if (userIn == 'T' || userIn == 't') //If user enters upper or lowercase "T", call the DisplayTotal function
        {
            DisplayTotal(iTotalXSmall, iTotalSmall, iTotalMedium, iTotalLarge);
            cout << endl << "Please enter selection: ";
            cin >> userIn;
        }
    }

    cout << "Thank you" << endl; //Once user enters "Q" and the loop finishes, give a farewell and exit program
    system("pause");
    return 1;
}
