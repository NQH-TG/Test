# Test

In line 19, 
Function addStudent()
void addStudent(Students& s) {
    std::ofstream myfile;
    myfile.open("/Users/louisnguyen/Desktop/Work/Test/Test/Base.lproj/Output.txt");
    std::cout << "Enter the name without space: \n";
    std::cin >> s.name;
    std::cout << "Enter the ID: \n";
    std::cin >> s.id;
    std::cout << "Enter the Score: \n";
    std::cin >> s.score;
    myfile << s.name << "\n";
    myfile << s.id << "\n";
    myfile << s.score << "\n";
    myfile.close();
}
You should create folder to store file Output.txt and rewrite the url into code.

In line 147,
case 'p' :
            std::string link = "open ~/Desktop/Work/Test/Test/Page.html";
            system(link.c_str());
            std::cin.get();
            break;
In case p, you should create a folder to store file html and rewrite the url into code.
