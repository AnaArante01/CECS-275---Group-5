/***********************************************/
// Pseudocode file for grade calculator program
/***********************************************/
/*

// When initially running the program, display a window with three buttons:
// Button 1: "Login" - When clicked, opens a dialog for user to enter username and password
            - Should also display a success or failure message
// Button 2: "Register" - When clicked, a dialog opens for new user registration
// Button 3: "Close Window" - When clicked, the program closes

if (btn1 == 1) // Login button clicked
    Display Login dialog
    Prompt user for username and password
    if (username == stored_username && password == stored_password)
        Display success message
    else
        Display failure message
else if (btn2 == 1) // Register button clicked
    Display Registration dialog
    Prompt user for new username and password
    Store new username and password
    Display registration success message
    Prompt user to log in
else if (btn3 == 1) // Close Window button clicked
    Close the program


// Once the user is logged in successfully, proceed to the grade calculator program
// The user should be offered options to...
// 1. Upload an image for their avatar
// 2. Open a text file and display its contents
// 3. Display a Bar chart for each student's percentages for each category compared to the corresponding
//    average of the class
// 4. Display a Pie chart to show the percentages of students that receive A, B, C, D, and F
// 5. Sort students based on id, letter grade, and overall percentage

//Uploading an image for avatar
// When the user clicks the "Upload Avatar" button
if (upload_avatar_button is clicked)
    Open file chooser dialog
    if (user selects an image file)
        Load and display the selected image as the user's avatar
    else
        Display error message indicating no file was selected       

//uploading and displaying a text file
// When the user clicks the "Open File" button
if (open_file_button is clicked)
    Open file chooser dialog
    if (user selects a text file)
        Read contents of the selected file
        Display file contents in the text area of the window
    else
        Display error message indicating no file was selected

//Displaying a bar chart
// Function to set data for bar chart   
// Using grade calculator lab to calculate the scores of each student first 
// saving the scores into vectors, and saving them into anotherf file 
// the scores will be stored in a file that will be opened up by glade 
// first open the score file and read the scores into vectors from glade 

if (file is opened successfully)
    Read scores into vectors
    Calculate each student's percentages for each category
    Calculate class averages for each category
    Store calculated percentages and averages into BarChart object
    and store calculated averages within the pie chart object 
    Display BarChart in the designated area of the window   
else
    Display error message indicating file could not be opened

//Displaying a pie chart
// Function to set data for pie chart
// Using grade calculator lab to calculate the scores of each student first
// saving the scores into vectors, and saving them into another file
// the scores will be stored in a file that will be opened up by glade
if (file is opened successfully)
    Read scores into vectors
    Calculate each student's percentages for each category
    Calculate class averages for each category
    Determine the number of students receiving A, B, C, D, and F grades
    Store grade distribution data into PieChart object
    Display PieChart in the designated area of the window   
else
    Display error message indicating file could not be opened

    // Sorting students
// When the user selects a sorting option and clicks the "Sort" button
if (sort_button is clicked)
    Get selected sorting option from dropdown
    if (option == "ID")
        Sort students by their ID in ascending order
    else if (option == "Final %")
        Sort students by their final percentage in descending order
    else if (option == "Letter Grade")
        Sort students by their letter grade (A to F)
    Update displayed student list based on the selected sorting order

// fake data button 
// When the user clicks the "Load Fake Data" button
    if (fake_data_button is clicked)
    Load predefined fake student data
    Populate student list and charts with fake data
    Update displayed student list and charts accordingly

// End of pseudocode

*/